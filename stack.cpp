#include <iostream>
#include "stack.h"
using namespace std;

Stack:: Stack() {
  sptr = nullptr;
  ssize = 0;
}
Stack:: Stack(const Stack& s) {
    ssize = s.ssize;
    sptr = new int[ssize];
    for(int i = 0; i < ssize; ++i) {
      sptr[i] = s.sptr[i];
    }
}
void Stack:: push(int elem) {
  int* tempS = new int[ssize];
  for(int i = 0; i < ssize; ++i) {
    tempS[i] = sptr[i];
  }
  delete[] sptr;
  ++ssize;
  sptr = new int [ssize];
  for(int i = 0; i < ssize - 1; ++i) {
    sptr[i]  = tempS[i];
  }
  delete[] tempS;
  sptr[ssize -1] = elem;
}
int Stack:: pop() {
  if(!isEmpty()) {
    int elem = sptr[ssize-1];
    --ssize;
    int* tempS = new int [ssize];
    for(int i = 0; i < ssize; ++i) {
      tempS[i] = sptr[i];
    }
    delete sptr;
    sptr = new int [ssize];
    for(int i = 0; i < ssize; ++i) {
      sptr[i] = tempS[i];
    }
    delete[] tempS;
    return elem;
  }
}
void Stack:: multiPop(int N) {
  if(!isEmpty()) {
    ssize -= N;
    int* tempS = new int [ssize];
    for(int i = 0; i < ssize; ++i) {
      tempS[i] = sptr[i];
    }
    delete[] sptr;
    sptr = new int [ssize];
    for(int i = 0; i < ssize; ++i) {
      sptr[i] = tempS[i];
    }
    delete[] tempS;
  }
}
bool Stack:: isEmpty() {
  if(sptr == nullptr) {
    return true;
  } else {
    return false;
  }
}
void Stack:: show() {
  for(int i = 0; i < ssize; ++i) {
    cout << sptr[i];
    if(i < ssize -1) {
        cout << " ";
    }
  }
  cout << endl;
}
Stack:: ~Stack() {
  delete[] sptr;
}
Stack& Stack:: operator = (const Stack& s) {
  if(this  == &s) {
    return *this;
  }
  ssize = s.ssize;
  sptr = new int[ssize];
  for(int i = 0; i < ssize; ++i) {
    sptr[i] = s.sptr[i];
  }
  return *this;
}
