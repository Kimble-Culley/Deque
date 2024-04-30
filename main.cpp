/**
   @file main.cpp
 * @author Kimble Culley and Sydney Marshall
 * @date 2024-04-23
 * @brief driver program
 * 
 * driver program for the implementation of the deque. it shows how the data in the deque
can be added, removed, and accessed. 
 */

#include "deque.h"
#include <iostream>

using namespace std;

int main() {

  Deque deque; // deque class
  int counter = 0; // keeps track of data added to the deque 

  cout << "push_back test of 1000: " << endl;
  // adds data to the back of deque and prints them 
  for(int i = 0; i < 1000; i++){
    deque.push_back(i);
    cout << " " << deque[i]; // this prints new data 
    counter++; 
  }

  cout << endl;
  cout << "pop_front test of 100: " << endl; 
  // removes data from the front of the deque 
  for(int i = 0; i < 100; i++){
    deque.pop_front();
    counter--;  
  }

  // prints data that remains in the deque 
  for(int i = 0; i < counter; i++){
    cout << " " << deque[i];
  }
  cout << endl;
  cout <<"pop_back test of 100: " << endl;

  // removes data from the back of the deque 
  for(int i = 0; i < 100; i++){
    deque.pop_back();
    counter--; 
  }

  // prints data that remains in deque 
  for(int i = 0; i < counter; i++){
    cout << " " << deque[i];
  }

  cout << endl;  
  return 0;
}
