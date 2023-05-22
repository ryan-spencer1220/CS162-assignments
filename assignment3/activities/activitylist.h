#pragma once
#include "activity.h"

// constants
const int CAP = 20;
const int GROWTH = 5;

class ActivityList
{
private:
  Activity *list;
  int size;
  int capacity;
  void growList();

public:
  // constructors
  ActivityList();
  ActivityList(char[]);

  // destructor
  ~ActivityList();

  // database functions
  void addActivity(Activity &);
  void searchByName();
  void searchByLocation();
  void searchByType();
  void showList();
  void removeActivity();
  void writeData(char[]);
};