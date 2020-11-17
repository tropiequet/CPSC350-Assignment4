/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 4

This is my Student class.
*/

#include "Student.h"

using namespace std;

Student::Student(){
  arrivalTime = 0;
  timeNeeded = 0;
  waitTime = 0;
}

Student::Student(int timeA, int timeN){
  arrivalTime = timeA;
  timeNeeded = timeN;
  waitTime = 0;
}

Student::~Student(){

}

int Student::getArrivalTime(){
  return arrivalTime;
}


int Student::getTimeNeeded(){
  return timeNeeded;
}

int Student::getWaitTime(){
  return waitTime;
}

void Student::setWaitTime(int time){
  waitTime = time;
}

void Student::setTimeNeeded(int time){
  timeNeeded = time;
}

void Student::setArrivalTime(int time){
  arrivalTime = time;
}
