#ifndef DEQUE_H
#define DEQUE_H

class Deque{
 private:
  int** blockmap;
  int frontBlock;
  int backBlock;
  int frontIndex;
  int backIndex;
  int numBlocks;
  int blockSize;
  int numElements;

  void expandFront();
  void expandBack();
  void shrinkFront();
  void shrinkBack();

 public:
  Deque();
  ~Deque();

  int push_front(int item);
  int push_back(int item);
  int pop_front();
  int pop_back();
  int front();
  int back();
  bool empty();
  int size();
  int operator[](int index);

};


  
#endif //DEQUE_H
