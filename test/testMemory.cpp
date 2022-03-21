#include "../src/modules/memory.hpp"

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define WORD unsigned __int32
#define MEMORY_ADDR unsigned __int32

int bigRand() {
  int x = rand() & 0xff;
  x |= (rand() & 0xff) << 8;
  x |= (rand() & 0xff) << 16;
  x |= (rand() & 0xff) << 24;
  return x;
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
    int randAddress = bigRand() % maxAddress + minAddress;
    int randWord = bigRand() % maxWord + minWord;
    mem->store(randAddress, randWord);
    int loadedWord = mem->load(randAddress);
    if(randWord != loadedWord) {
      printf("testMemory: Error! stored %X, loaded %X.\n", randWord, loadedWord);
      return 0;
    }
  }

  printf("testMemory: PASS! tested %d cases.\n", testNum);

}