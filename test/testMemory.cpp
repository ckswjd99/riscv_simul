#include "../src/modules/memory.hpp"

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

using WORD = uint32_t;
using MEMORY_ADDR = uint32_t;

unsigned long long bigRand() {
  unsigned long long r = 0;
  for (int i = 0; i < 5; ++i) {
      r = (r << 15) | (rand() & 0x7FFF);
  }
  return r & 0xFFFFFFFFFFFFFFFFULL;
}

int main () {
  srand(time(0));
  
  MEMORY_ADDR minAddress = 0;
  MEMORY_ADDR maxAddress = (MEMORY_ADDR)0 - 1;
  WORD minWord = 0;
  WORD maxWord = (WORD)0 - 1;
  
  int pageBit = 4;
  int testNum = 10000000;

  Memory<int32_t, int32_t>* mem = new Memory<int32_t, int32_t>(pageBit);

  for(int i = 0; i < testNum; i++) {
    MEMORY_ADDR randAddress = bigRand() % maxAddress + minAddress;
    WORD randWord = bigRand() % maxWord + minWord;
    // printf("%d %llu %llu\n", i, randAddress, randWord);

    mem->store(randAddress, randWord);
    WORD loadedWord = mem->load(randAddress);
    if(randWord != loadedWord) {
      printf("testMemory: Error! stored %X, loaded %X.\n", randWord, loadedWord);
      return 0;
    }
  }

  unsigned long long usedMemorySize = mem->usedMemorySize();
  unsigned long long totalMemorySize = mem->totalMemorySize();
  printf(
    "testMemory: PASS! tested %d load & stores, %llu / %llu bits (%.10f %%) used.\n",
    testNum, 
    usedMemorySize, 
    totalMemorySize, 
    (usedMemorySize / 1e10) / (totalMemorySize / 1e10) * 100
  );

}