/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 4

This is my DoublyLinkedList template class.
*/

#include <iostream>
#include <stddef.h>
#include <algorithm>
#include <iterator>
#include "ListNode.h"
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


using namespace std;

template <class T>


class DoublyLinkedList{
public:
  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int size;

//public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  void insertFront(T d);
  void insertBack(T d);
  T removeFront();
  T removeBack();
  int find(int value);
  T deletePos(int pos);
  T removeNode(int key);

  void printList();
  bool isEmpty();
  unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  //
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if (size == 0){
    back = node;
  }else{
    front->prev = node;
    node->next = front;
  }
  front = node;
  ++size;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);
   if (front == NULL){ //same as size == 0
     front = node;
     node->next = NULL;
     node->prev = NULL;
   }else{
    back->next = node;
    node->next = NULL;
    node->prev = back;
  }
  back = node;
  ++size;
}


template <class T>
T DoublyLinkedList<T>::removeFront(){
  ListNode<T> *node = front;
    // if (size == 0){
    //   cout << "Error! Empty!" << endl;
    //   return -1;
    // }

  if (front->next == NULL){
    back = NULL;
  }else{
    //more than one node in the List
    front->next->prev = NULL;
  }
  front = front->next;
  node->next = NULL;
  T temp = node->data;

  size--;

  delete node;

  return temp;
}

template <class T>
T DoublyLinkedList<T>::removeBack(){

}

//print front to back
template <class T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;
  while (curr != NULL){
    cout<<curr->data<<endl;
    curr = curr->next;
  }
}

//print back to front
// void DoublyLinkedList::printList(){
//   ListNode *curr = bacl;
//   while (curr != NULL){
//     cout<<curr->data<<endl;
//     curr = curr->prev;
//   }
// }

template <class T>
int DoublyLinkedList<T>::find(int value){
  int pos = -1;
  ListNode<T> *curr = front;
  while (curr != NULL){
    ++pos;
    if (curr->data == value){
      break;
    }
    curr = curr->next;
  }
  if (curr == NULL){
    pos = -1;
  }
  return pos;
}

template <class T>
T DoublyLinkedList<T>::deletePos(int pos){
  int p = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  while (p != pos){
    prev = curr;
    curr = curr->next;
    p++;
  }
  prev->next = curr->next;
  curr->next = NULL;

  T temp = curr->data;
  size--;

  delete curr;

  return temp;
}

template <class T>
T DoublyLinkedList<T>::removeNode(int key){
  ListNode<T> *curr = front;

  //check if empty before proceeding

  //if not empty, you can leverage find() to determine if value even exists

  while (curr->data != key){
    curr = curr->next;

    if (curr == NULL){
      //i reached the end of my linked list and did not find the key/value
      return -1;
    }
  }

  //if i make it here, I found the node that needs to be deleted
  if (curr == front){
    front = curr->next;
    front->prev = NULL;
  }else if (curr == back){
    back = curr->prev;
    back->next = NULL;
  }else{
    //its between front and back
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;

  T temp = curr->data;
  size--;

  delete curr;

  return temp;
}


#endif
