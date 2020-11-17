/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 4

This is my Student class header file.
*/


#ifndef STUDENT_H
#define STUDENT_H

class Student{

public:
  Student();
  Student(int timeA, int timeN);
  ~Student();

  int waitTime;
  int timeNeeded;
  int arrivalTime;

  int getArrivalTime();
  int getTimeNeeded();
  int getWaitTime();
  void setWaitTime(int time);
  void setTimeNeeded(int time);
  void setArrivalTime(int time);





};

#endif
