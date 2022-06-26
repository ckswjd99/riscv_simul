#ifndef MEMORY_H
#define MEMORY_H

#include "../specs/const.h"
#include "stdint.h"

template <typename WordType, typename MemoryAddrType>
class PageTree {
public:
  PageTree(int pageBit, int depth);
  ~PageTree();

  WordType* find(MemoryAddrType address);

  // benchmark
  MemoryAddrType countLeaf();

private:
  int pageBit;
  int depth;
  PageTree** children;
  WordType* data;
};

template <typename WordType, typename MemoryAddrType>
class Memory {
public:
  Memory(int pageBit);
  ~Memory();

  WordType load(MemoryAddrType address);
  void store(MemoryAddrType address, WordType data);
  
  // benchmark
  unsigned long long totalMemorySize();
  unsigned long long usedMemorySize();

private:
  int pageBit;
  PageTree<WordType, MemoryAddrType>* root;
};

#endif