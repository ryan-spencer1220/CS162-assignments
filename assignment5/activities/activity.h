#pragma once
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

const int MAXCHAR = 101;

// Activity class
class Activity
{
private:
  char *activityName;
  char *activityLocation;
  char *activityLevel;
  int activityRating;
  int activityType;

public:
  // constructors
  Activity();
  Activity(char *, char *, char *, int, int);

  // copy constructor
  Activity(const Activity &anActivity);

  // destructor
  ~Activity();

  // mutators
  void setActivityName(char *);
  void setActivityLocation(char *);
  void setActivityLevel(char *);
  void setActivityRating(int);
  void setActivityType(int);

  // accessor functions
  void getActivityName(char *);
  void getActivityLocation(char *);
  void getActivityLevel(char *);
  int getActivityRating();
  int getActivityType();

  // write & print functions
  void printActivity();
  void printActivity(ofstream &);
  void writeActivity(ofstream &outFile, int count, int size);

  // assignment operator overloading
  const Activity &operator=(const Activity &anActivity);
};