#ifndef ACTIVITIES_H
#define ACTIVITIES_H

#include "activity.h"
#include "activitylist.h"

// function prototypes
int readInt(char prompt[]);
void readString(char prompt[], char temp[]);
void displayMenu();
char readOption();
void exeCmd(char option, ActivityList &);
void addActivity(Activity &, ActivityList &);
void convertCase(char tempStr[]);
void retrieveActivityType(int tempNumber, char activityListType[]);
bool isLessThan(char activityName1[], char activityName2[]);
void welcomeMessage();
void goodbyeMessage();

#endif