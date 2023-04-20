#pragma once
#include "activity.h"

// constants
const int CAP = 30;

class ActivityList
{
private:
  Activity activityList[CAP];
  int size;

public:
  // constructors
  ActivityList();
  ActivityList(char[]);

  // destructors
  ~ActivityList();

  // database functions
  void addActivity(Activity);
  void removeActivity();
  void searchByType();
  void searchByLocation();
  void searchByName();
  void showList();
  void writeData(char[]);
};