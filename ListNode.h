/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 4

This is my ListNode template class.
*/

#include <iostream>
#include <stddef.h>
#ifndef LISTNODE_H
#define LISTNODE_H


using namespace std;

template <class T>

class ListNode{


public:
  ListNode();
  ListNode(T d);
  ~ListNode();

  T data;
  ListNode *next;
  ListNode *prev;

};

template <class T>
ListNode<T>::ListNode(){

}

template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
  //
}

#endif
