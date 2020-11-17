/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 4

This is my main method that implements my GenQueue, Student, and Window classes.
*/


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "DoublyLinkedList.h"
#include "ListNode.h"
#include "GenQueue.h"
#include "Student.h"
#include "Window.h"

using namespace std;


int main(int argc, char** argv){

  string fileName = argv[1];

  ifstream infile(fileName);
  string line;


  int numWindows;

  infile>>numWindows;

  Window windows[numWindows]; //array of windows

  GenQueue<Student> myQueue;

  int time;
  int numStudents;
  int totalStudents = 0;
  Student currStudent;

  int qSize;

  int clockTick = 0;

  int arrivalTime;
  int waitTime;
  int timeNeeded;
  int idleTime;

  int totalTime;

  bool allEmpty = true;
  int count;

  int studentNum = 0;

  infile >> time;


//adds students to queue with their given wait times
  while (infile.good()){

    infile >> numStudents;
    for (int i = 0; i < numStudents; ++i){
      Student s;
      infile >> timeNeeded;
      s.setArrivalTime(time);
      s.setTimeNeeded(timeNeeded);
      myQueue.insert(s);
      totalStudents++;
    }
      infile >> time;
  }

  infile.close();


  Student tempArray[totalStudents]; //when students leave a window they go here so we can calculate stats later

   currStudent = myQueue.peek();

  while ((!myQueue.isEmpty()) || (!allEmpty)){

    //update window idle times
    if (clockTick != 0){ //don't want to add to idle time on clock tick 0
      for (int i = 0; i < numWindows; ++i){
        if(!windows[i].getOccupancy()){
          idleTime = windows[i].getIdleTime();
          idleTime++;
          windows[i].setIdleTime(idleTime); //increments the non occupied windows idle time by one
        }
      }
    }

    //check if a student is done at a window therefore opening it up
    for (int i = 0; i < numWindows; ++i){
      if(windows[i].getOccupancy()){ //window is occupied
        Student s;
        s = windows[i].getStudent();
        arrivalTime = s.getArrivalTime();
        timeNeeded = s.getTimeNeeded();
        waitTime = s.getWaitTime();
        totalTime = arrivalTime + timeNeeded + waitTime;
        if (totalTime == clockTick){
          windows[i].setOccupancy(false); //student is done and leaves so occupancy is now false allowing a new student to go there
          tempArray[studentNum] = s;
          studentNum++;
        }
      }
    }



    //check if a student needs to be assigned to a window only if queue has a student
   if (!myQueue.isEmpty()){
      while (currStudent.getArrivalTime() <= clockTick){ //curr student is still in queue and their arrival time is less than or equal to the clock tick so they are ready to go to a window

        //counts how many windows are occupied
        count = 0;
        for (int i = 0; i < numWindows; ++i){
          if (windows[i].getOccupancy()){
            count++;
          }
        }
        //all windows occupied, can't add a student, so we break out of while loop
        if (count == numWindows){
          break;
        }


        //at least 1 window open to assign a student to
        //need to cycle through to find first empty window
        for (int i = 0; i < numWindows; ++i){
          if (!windows[i].getOccupancy()){ //window is not occupied
            Student s;
            s = myQueue.remove();
            waitTime = (clockTick - s.getArrivalTime());
            s.setWaitTime(waitTime);
            windows[i].setStudent(s);
            windows[i].setOccupancy(true);
            if (!myQueue.isEmpty()){
                currStudent = myQueue.peek(); //updates currStudent since we removed one
            }
            break; //breaks out of for loop because we assigned a student
          }
        }
        if (myQueue.isEmpty()){
          break;
        }
      }
    }


  //check if all windows are empty to update boolean expression for main while loop
    for (int i = 0; i < numWindows; ++i){
      if (windows[i].getOccupancy()){
        allEmpty = false;
        break;
      }else{
        allEmpty = true;
      }
    }



    clockTick++;
  }



  //queue and windows are empty so now we calculate

  double totalWaitTime = 0;
  double meanWaitTime;
  double medianWaitTime;
  double longestWaitTime;
  int overTen = 0;
  double totalIdleTime = 0;
  double meanIdleTime;
  double longestIdleTime;
  int overFive = 0;

  int waitTimes[totalStudents];

  int windowTimes[numWindows];


  //total wait time
  for (int i = 0; i < totalStudents; ++i){
    totalWaitTime += tempArray[i].getWaitTime();
    waitTimes[i] = tempArray[i].getWaitTime(); //adds all wait times to an array
  }

  meanWaitTime = totalWaitTime / totalStudents;

  cout << "Mean wait time: " << meanWaitTime << endl;

  //median wait time
  int n = sizeof(waitTimes) / sizeof(waitTimes[0]);
  sort(waitTimes, waitTimes+n);
  if (n % 2 != 0){
    medianWaitTime = waitTimes[n/2];
  }else{
    medianWaitTime = (waitTimes[(n-1) / 2] + waitTimes[n / 2]) / 2;
  }

  cout << "Median wait time: " << medianWaitTime << endl;


  //longestWaitTime
  longestWaitTime = waitTimes[totalStudents - 1];

  cout << "Longest wait time: " << longestWaitTime << endl;


  //number of students waiting over 10 minutes
  for (int i = 0; i < totalStudents; ++i){
    if (waitTimes[i] > 10){
      overTen++;
    }
  }
  cout << "Number of students waiting over 10 minutes: " << overTen << endl;


  //mean window idle time
  for (int i = 0; i < numWindows; ++i){
    totalIdleTime += windows[i].getIdleTime();
    windowTimes[i] = windows[i].getIdleTime(); //adds all idle times to an array
  }


  meanIdleTime = totalIdleTime / numWindows;
  cout << "Mean idle time: " << meanIdleTime << endl;

  //longest window idle time
  int x = sizeof(windowTimes) / sizeof(windowTimes[0]);
  sort(windowTimes, windowTimes+x);
  longestIdleTime = windowTimes[numWindows-1];
  cout << "Longest Window Idle Time: " << longestIdleTime << endl;


  //number of windows idle over 5 minutes
  for (int i = 0; i < numWindows; ++i){
    if (windowTimes[i] > 5){
      overFive++;
    }
  }
  cout << "Number of windows idle for over 5 minutes: " << overFive << endl;



  return 0;




}
