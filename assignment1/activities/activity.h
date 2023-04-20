#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

#pragma once

using namespace std;

// constants
const int CAP = 30;
const int MAXCHAR = 50;

// data type for Activity
struct Activity
{
  char name[MAXCHAR];
  char location[MAXCHAR];
  char level[MAXCHAR];
  int rating;
  char type[MAXCHAR];
};

// function prototypes
void printData(Activity activityList[], int size);
void addActivity(Activity activityList[], int &size);
void removeActivity(Activity activityList[], int &size, ofstream &outFS);
void searchByName(Activity activityList[], int &size);
void searchByType(Activity activityList[], int &size);
void searchByLocation(Activity activityList[], int &size);
void printActivityType(int tempNumber, char activityListType[]);
void loadData(ifstream &inFile, Activity activityList[], int &size);