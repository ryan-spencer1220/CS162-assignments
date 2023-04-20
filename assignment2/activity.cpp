#include "activity.h"
#include "main.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

// constructors
// default constructor
Activity::Activity()
{
  strcpy(activityName, "unknown");
  strcpy(activityLocation, "unknown");
  strcpy(activityLevel, "unknown");
  activityRating = 0;
  strcpy(activityType, "unknown");
}

Activity::Activity(char newActivityName[], char newActivityLocation[],
                   char newActivityLevel[], int newActivityRating,
                   char newActivityType[])
{
  strcpy(activityName, newActivityName);
  strcpy(activityLocation, newActivityLocation);
  strcpy(activityLevel, newActivityLevel);
  activityRating = newActivityRating;
  strcpy(activityType, newActivityType);
}

// mutator functions
void Activity::setActivityName(char *newActivityName)
{
  strcpy(activityName, newActivityName);
}

void Activity::setActivityLocation(char *newActivityLocation)
{
  strcpy(activityLocation, newActivityLocation);
}

void Activity::setActivityLevel(char *newActivityLevel)
{
  strcpy(activityLevel, newActivityLevel);
}

void Activity::setActivityRating(int newActivityRating)
{
  activityRating = newActivityRating;
}

void Activity::setActivityType(char *newActivityType)
{
  strcpy(activityType, newActivityType);
}

// accessor functions
void Activity::getActivityName(char *returnActivityName)
{
  strcpy(returnActivityName, activityName);
}

void Activity::getActivityLocation(char *returnActivityLocation)
{
  strcpy(returnActivityLocation, activityLocation);
}

void Activity::getActivityLevel(char *returnActivityLevel)
{
  strcpy(returnActivityLevel, activityLevel);
}

int Activity::getActivityRating(int returnActivityRating)
{
  return returnActivityRating;
}

void Activity::getActivityType(char *returnActivityType)
{
  strcpy(returnActivityType, activityType);
}

void Activity::printActivity()
{
  cout << activityName << ";" << activityLocation << ";" << activityLevel << ";"
       << activityRating << ";" << activityType << endl;
}

void Activity::writeActivity(ofstream &outFile, int count, int size)
{
  outFile << activityName << ";";
  outFile << activityLocation << ";";
  outFile << activityLevel << ";";
  outFile << activityRating << ";";
  if (count == (size - 1))
  {
    outFile << activityType;
  }
  else
  {
    outFile << activityType << endl;
  }
}