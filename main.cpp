/**
0;10;1c * @file main.cpp
 * @author Kimble Culley
 * @date 2024-04-23
 * @brief idk
 * 
 * idk
 */

#include "deque.h"
#include <iostream>

using namespace std;

int main() {

  Deque deque;
  int counter = 0;
  
  for(int i = 0; i < 1000; i++){
    deque.push_back(i);
    cout << " " << deque[i];
    counter++;
  }

  for(int i = 0; i < 100; i++){
    deque.pop_front();
    counter--;
  }

  for(int i = 0; i < counter; i++){
    cout << " " << deque[i];
  }

  for(int i = 0; i < 100; i++){
    deque.pop_back();
    counter--;
  }

  for(int i = 0; i < counter; i++){
    cout << " " << deque[i];
  }
  
  return 0;
}
