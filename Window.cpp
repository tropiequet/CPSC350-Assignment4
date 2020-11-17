/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 4

This is my Window class.
*/



#include "Window.h"

using namespace std;

Window::Window(){
  idleTime = 0;
  occupancy = false;
}

Window::Window(int time, Student s){
  idleTime = time;
  student = s;
  occupancy = false;
}

Window::~Window(){

}

int Window::getIdleTime(){
  return idleTime;
}

void Window::setIdleTime(int t){
  idleTime = t;
}

bool Window::getOccupancy(){
  return occupancy;
}

void Window::setOccupancy(bool b){
  occupancy = b;
}

void Window::setStudent(Student s){
  student = s;
}

Student Window::getStudent(){
  return student;
}
