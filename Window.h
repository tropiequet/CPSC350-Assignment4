/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 4

This is my Window class header file.
*/

#ifndef WINDOW_H
#define WINDOW_H
#include "Student.h"

class Window{

public:
  Window();
  Window(int time, Student s);
  ~Window();

  int idleTime;
  Student student;
  bool occupancy;

  int getIdleTime();
  void setIdleTime(int time);
  bool getOccupancy();
  void setOccupancy(bool b);
  void setStudent(Student s);
  Student getStudent();

};
#endif
