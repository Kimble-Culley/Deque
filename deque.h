/**
 * @file deque.h
 * @author Kimble Culley and Sydney Marshall
 * @date 2024-04-29
 * @brief declares deque class 
 * 
 * declares deque class and member variables and methods 
 */


#ifndef DEQUE_H
#define DEQUE_H

class Deque{
 private:
  // pointer to a pointer 
  int** blockmap;
  int frontBlock;
  int backBlock;
  int frontIndex;
  int backIndex;
  int numBlocks;
  int blockSize;
  int numElements;


  void expandFront();//expands deque towards front 
  void expandBack();//expands deque towards back
  void shrinkFront();//shrinks deque towards front
  void shrinkBack();//shrinks deque towards back 

 public:

/**
 * constructor to initialize deque 
 * @post deque is initialized 
 */
  Deque();

/**
 * destructor
 * @post memory is deallocated
 */
  ~Deque();


/**
 * adds element to front of deque
 * @param int item 
 * @return void 
 * @post element is added to the front
 */
  void push_front(int item);

/**
 * adds element to the back of deque
 * @param int item 
 * @return int 
 * @post element is added to the back
 */
  int push_back(int item);

/**
 * removes and returns element from front of deque
 * @return int 
 * @post element is removed from front  
 */
  int pop_front();

/**
 * removes and returns element from back
 * @return int 
 * @post element is removed from back 
 */
  int pop_back();

/**
 * returns element at front of deque
 * @return int  
 */
  int front();

/**
 * returns element at back of deque
 * @return int  
 */
  int back();

/**
 * checks if deque is empty
 * @return bool  
 */
  bool empty();

/**
 * returns number of elements in deque
 * @return int  
 */
  int size();

/**
 * overloaded subscript op. to access elements by index
 * @param int index 
 * @pre index is within range
 * @return int  
 */
  int operator[](int index);

};


  
#endif //DEQUE_H
