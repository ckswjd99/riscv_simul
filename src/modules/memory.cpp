#include "./memory.hpp"

#include "stdio.h"

template <typename WordType, typename MemoryAddrType>
PageTree<WordType, MemoryAddrType>::PageTree(int pageBit, int depth) {
  this->children = new PageTree*[1 << pageBit];
  for(int i=0; i<(1 << pageBit); i++) {
    this->children[i] = nullptr;
  }
  this->data = nullptr;
  this->pageBit = pageBit;
  this->depth = depth;
}

template <typename WordType, typename MemoryAddrType>
PageTree<WordType, MemoryAddrType>::~PageTree() {
  delete[] this->data;
  delete[] this->children;
}

template <typename WordType, typename MemoryAddrType>
WordType* PageTree<WordType, MemoryAddrType>::find(MemoryAddrType address) {
  int pageDepth = sizeof(MemoryAddrType) * 8 / this->pageBit;
  int parsedIndex = (address >> (this->pageBit * (pageDepth - this->depth - 1))) & ((1 << this->pageBit) - 1);
  // printf("depth %d/%d, now index %X\n", this->depth, pageDepth, parsedIndex);
  
  if(this->depth == pageDepth - 1) {  // last pageTree depth
    if(this->data == nullptr) { // first touch
      this->data = new WordType[1 << this->pageBit];
      return this->data + parsedIndex % (1 << this->pageBit);
    }
    else {  // not first touch
      return this->data + parsedIndex % (1 << this->pageBit);
    }
  }
  else {  // traverse more pageTree
    if(this->children[parsedIndex] == nullptr) {  // first touch
      this->children[parsedIndex] = new PageTree<WordType, MemoryAddrType>(this->pageBit, this->depth + 1);
      return this->children[parsedIndex]->find(address);
    }
    else {  // not first touch
      return this->children[parsedIndex]->find(address);
    }
  }
}

template <typename WordType, typename MemoryAddrType>
Memory<WordType, MemoryAddrType>::Memory(int pageBit) {
  this->pageBit = pageBit;
  this->root = new PageTree<WordType, MemoryAddrType>(this->pageBit, 0);
}

template <typename WordType, typename MemoryAddrType>
WordType Memory<WordType, MemoryAddrType>::load(MemoryAddrType address) {
  return *(this->root->find(address));
}

template <typename WordType, typename MemoryAddrType>
void Memory<WordType, MemoryAddrType>::store(MemoryAddrType address, WordType data) {
  *(this->root->find(address)) = data;
}

// benchmark functions
template <typename WordType, typename MemoryAddrType>
MemoryAddrType PageTree<WordType, MemoryAddrType>::countLeaf() {
  if(this->data != nullptr) return 1;
  else {
    MemoryAddrType counter = 0;
    for(int i=0; i < (1 << this->pageBit); i++) {
      if(this->children[i] != nullptr) counter += this->children[i]->countLeaf();
    }
    return counter;
  }
}

template <typename WordType, typename MemoryAddrType>
unsigned long long Memory<WordType, MemoryAddrType>::totalMemorySize() {
  return (1ULL << (sizeof(MemoryAddrType) * 8)) * sizeof(WordType) * 8;
}

template <typename WordType, typename MemoryAddrType>
unsigned long long Memory<WordType, MemoryAddrType>::usedMemorySize() {
  int leafNum = this->root->countLeaf();
  return leafNum * sizeof(WordType) * 8;
}


// avoid linker errors
template class Memory<int, int>;