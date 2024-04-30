/**
 * @file deque.cpp
 * @author Kimble Culley and Sydney Marshall
 * @date 2024-04-23
 * @brief implementation of deque class 
 * 
 * 
 */

#include <iostream>
#include "deque.h"

Deque::Deque(){
  blockmap = new int*[1];//allocate memory for one block 
  blockmap[0] = new int[1];//allocate for one element 
  frontBlock = backBlock = 0;
  frontIndex = backIndex = 0;
  numBlocks = 1;
  blockSize = 1;
  numElements = 0;
}

Deque::~Deque(){
  for(int i = 0; i < numBlocks; i++)
    delete[] blockmap[i];//deletes each block
  delete[] blockmap;// deletes the blockmap
}

void Deque::expandFront(){
  if(frontBlock == 0){
    int** newBlockmap = new int*[numBlocks * 2];//checks if new block needs to be made
    for(int i = 0; i < numBlocks; i++){
      newBlockmap[i + 1] = blockmap[i];//copy existing blocks to new blockmap 
    }
    delete[] blockmap;
    blockmap = newBlockmap;
    numBlocks *= 2;
  }
  frontBlock--;//updates front block, index, and allocate memory for a new block
  frontIndex = blockSize -1;
  blockmap[frontBlock] = new int[blockSize];
}

void Deque::expandBack(){
  if(backIndex == blockSize - 1){
    if(backBlock == numBlocks - 1){
      int** newBlockmap = new int*[numBlocks * 2];//checks if new block needs to be made
      for(int i = 0; i < numBlocks; i++)
	newBlockmap[i] = blockmap[i];//copy existing blocks to new blockmap
      delete[] blockmap;
      blockmap = newBlockmap;
      numBlocks++;
    }
    backBlock++;// updates back block, index, and allocates mem for new block
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
    delete[] blockmap[frontBlock];// deletes the front block if it is not empty 
    blockmap[frontBlock] = NULL;
  }
  frontBlock++;//move the front block index and rest the front index
  frontIndex = 0;
}

void Deque::shrinkBack(){
  if(numElements == 0)
    return;
  if(frontBlock == backBlock && frontIndex == backIndex)
    return;

  if(blockmap[backBlock] != NULL){
    delete[] blockmap[backBlock];// deletes the back block if it is not empty
    blockmap[backBlock] = NULL;
  }
  backBlock--;// move back block index and reset the back index
  backIndex = blockSize -1;
}
  

void Deque::push_front(int item){
  if(frontIndex == 0){// checks if new block needs to be created at the front 
    expandFront();
  }
  frontIndex--;// moves front index and assigns to certain position
  blockmap[frontBlock][frontIndex] = item;
}

int Deque::push_back(int item){
  if(empty()){
    blockmap[backBlock][backIndex] = item;//if deque is empty, assign to back
  }else{
    expandBack();//if deque is not empty, expand it towards back and assign item
    blockmap[backBlock][backIndex] = item;
  }
  numElements++;
  return 0;
}

int Deque::pop_front(){
  if(empty()){
    return -1;//failure 
  }
  if(frontIndex == blockSize - 1){
    shrinkFront();
  }else{
    frontIndex++;//moves front index
  }
  numElements--;
  return 0;//success
}

int Deque::pop_back(){
  if(empty()){
    return -1;//failure 
  }
  if(backIndex == 0){
    shrinkBack();
  }else{
    backIndex--;//move back index
  }
  numElements--;
  return 0;//success
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
  // overloaded subscript op 
  int blockIndex = (frontBlock + (index + frontIndex) / blockSize) % numBlocks;
  int elementIndex = (index + frontIndex) % blockSize;
  return blockmap[blockIndex][elementIndex];
}
