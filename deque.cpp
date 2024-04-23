/**
 * @file deque.cpp
 * @author Kimble Culley
 * @date 2024-04-23
 * @brief deque.cpp
 * 
 * ceque.cpp
 */


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
  if(frontIndex == 0){
    if(frontBlock == 0){
      int** newBlockmap = new int*[numBlocks * 2];
      for(int i = 0; i < numBlocks; i++)
	newBlockmap[i + 1] = blockmap[i];
      delete[] blockmap;
      blockmap = newBlockmap;
      numBlocks ++;
    }
    frontBlock--;
    frontIndex = blockSize - 1;
    blockmap[frontBlock] = new int[blockSize];
  }else{
    frontIndex--;
  }
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
    backIndex;
  }
}

