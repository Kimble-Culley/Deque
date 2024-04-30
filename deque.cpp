/**
 * @file deque.cpp
 * @author Kimble Culley
 * @date 2024-04-23
 * @brief deque.cpp
 * 
 * ceque.cpp
 */

#include <iostream>
#include "deque.h"

Deque::Deque(){
  blockmap = new int*[1];
  blockmap[0] = new int[1];
  frontBlock = backBlock = 0;
  frontIndex = backIndex = 0;
  numBlocks = 1;
  blockSize = 1;
  numElements = 0;
}

Deque::~Deque(){
  for(int i = 0; i < numBlocks; i++)
    delete[] blockmap[i];
  delete[] blockmap;
}

void Deque::expandFront(){
  if(frontBlock == 0){
    int** newBlockmap = new int*[numBlocks * 2];
    for(int i = 0; i < numBlocks; i++){
      newBlockmap[i + 1] = blockmap[i];
    }
    delete[] blockmap;
    blockmap = newBlockmap;
    numBlocks *= 2;
  }
  frontBlock--;
  frontIndex = blockSize -1;
  blockmap[frontBlock] = new int[blockSize];
}

void Deque::expandBack(){
  if(backIndex == blockSize - 1){
    if(backBlock == numBlocks - 1){
      int** newBlockmap = new int*[numBlocks * 2];
      for(int i = 0; i < numBlocks; i++)
	newBlockmap[i] = blockmap[i];
      delete[] blockmap;
      blockmap = newBlockmap;
      numBlocks++;
    }
    backBlock++;
    backIndex = 0;
    blockmap[backBlock] = new int[blockSize];
  }else{
    backIndex++;
  }
}

void Deque::shrinkFront(){
  if(numElements == 0)
    return;
  if(frontBlock == backBlock && frontIndex == backIndex)
    return;

  if(blockmap[frontBlock] != NULL){
    delete[] blockmap[frontBlock];
    blockmap[frontBlock] = NULL;
  }
  frontBlock++;
  frontIndex = 0;
}

void Deque::shrinkBack(){
  if(numElements == 0)
    return;
  if(frontBlock == backBlock && frontIndex == backIndex)
    return;

  if(blockmap[backBlock] != NULL){
    delete[] blockmap[backBlock];
    blockmap[backBlock] = NULL;
  }
  backBlock--;
  backIndex = blockSize -1;
}
  

void Deque::push_front(int item){
  if(frontIndex == 0){
    expandFront();
  }
  frontIndex--;
  blockmap[frontBlock][frontIndex] = item;
}

int Deque::push_back(int item){
  if(empty()){
    blockmap[backBlock][backIndex] = item;
  }else{
    expandBack();
    blockmap[backBlock][backIndex] = item;
  }
  numElements++;
  return 0;
}

int Deque::pop_front(){
  if(empty()){
    return -1;
  }
  if(frontIndex == blockSize - 1){
    shrinkFront();
  }else{
    frontIndex++;
  }
  numElements--;
  return 0;
}

int Deque::pop_back(){
  if(empty()){
    return -1;
  }
  if(backIndex == 0){
    shrinkBack();
  }else{
    backIndex--;
  }
  numElements--;
  return 0;
}

int Deque::front(){
  return blockmap[frontBlock][frontIndex];
}

int Deque::back(){
  return blockmap[backBlock][backIndex];
}

bool Deque::empty(){
  return numElements == 0;
}

int Deque::size(){
  return numElements;
}

int Deque::operator[](int index){
  int blockIndex = (frontBlock + (index + frontIndex) / blockSize) % numBlocks;
  int elementIndex = (index + frontIndex) % blockSize;
  return blockmap[blockIndex][elementIndex];
}
