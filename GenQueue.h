/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 4

This is my GenQueue template class.
*/

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template <class T>



class GenQueue{

public:
  GenQueue(); //default
  GenQueue(int maxSize); //overloaded
  ~GenQueue(); //destructor

  //core functions
  bool insert(T d); //enqueue
  T remove(); //dequeue

  //aux functions
  T peek();
  bool isFull();
  bool isEmpty();
  unsigned int getSize();
  //void print();

private:
  int front;
  int rear;
  int mSize;
  unsigned int numElements;

  DoublyLinkedList<T> *myList;
};




//default
template <class T>
GenQueue<T>::GenQueue(){
  myList = new DoublyLinkedList<T>();
  mSize = 128;
  front = 0;
  rear = -1;
  numElements = 0;
}


//overloaded
template <class T>
GenQueue<T>::GenQueue(int maxSize){
  myList = new DoublyLinkedList<T>();
  mSize = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
}

//destructor
template <class T>
GenQueue<T>::~GenQueue(){
  delete myList;
}


//core functions
template <class T>
bool GenQueue<T>::insert(T d){ //enqueue
  if (isFull()){
    return false;
  }else{
    myList->insertBack(d);
    numElements++;
    return true;
  }
}


template <class T>
T GenQueue<T>::remove(){ //dequeue
  T c;
  // if (isEmpty()){
  //   return c;
  // }else{
    c = myList->removeFront();
    front++;
    --numElements;
    return c;
  //}

}



//aux functions
template <class T>
T GenQueue<T>::peek(){
  return (myList->front->data);
}

template <class T>
bool GenQueue<T>::isFull(){
  return (numElements == mSize);
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return (numElements == 0);
}

template <class T>
unsigned int GenQueue<T>::getSize(){
  return  numElements;
}


// template <class T>
// void GenQueue<T>::print(){
//   cout << "Q SIZE: " << getSize() << endl;
//   cout << "FRONT: " << front << endl;
//   cout << "REAR: " << rear << endl;
//
//   for (int i = 0; i < mSize; ++i){
//     cout << "Q["<<i<<"]: " << myList->removeFront();
//     if (i != mSize - 1){
//       cout << " | ";
//     }
//   }
//   cout << endl;
// }
