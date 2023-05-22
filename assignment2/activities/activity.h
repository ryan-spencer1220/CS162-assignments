#pragma once
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

const int MAXCHAR = 51;

class Activity
{
private:
  char activityName[MAXCHAR];
  char activityLocation[MAXCHAR];
  char activityLevel[MAXCHAR];
  int activityRating;
  char activityType[MAXCHAR];

public:
  // constructors
  Activity();
  Activity(char[], char[], char[], int, char[]);
  // mutators
  void setActivityName(char *);
  void setActivityLocation(char *);
  void setActivityLevel(char *);
  void setActivityRating(int);
  void setActivityType(char *);
  // accessors
  void getActivityName(char *);
  void getActivityLocation(char *);
  void getActivityLevel(char *);
  int getActivityRating(int);
  void getActivityType(char *);
  // print
  void printActivity();
  void writeActivity(ofstream &outFile, int count, int size);
};