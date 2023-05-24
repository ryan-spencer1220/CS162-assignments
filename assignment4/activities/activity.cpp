#include "activity.h"

// constructors
// default constructor
Activity::Activity()
{
  activityName = NULL;
  activityLocation = NULL;
  activityLevel = NULL;
  activityRating = 0;
  activityType = 0;
}

// constructor with parameters
Activity::Activity(char *newName, char *newLocation, char *newLevel,
                   int newRating, int newType)
{
  activityName = new char[strlen(newName) + 1];
  strcpy(activityName, newName);
  activityLocation = new char[strlen(newLocation) + 1];
  strcpy(activityLocation, newLocation);
  activityLevel = new char[strlen(newLevel) + 1];
  strcpy(activityLevel, newLevel);
  activityRating = newRating;
  activityType = newType;
}

// Copy Constructor
Activity::Activity(const Activity &anActivity)
{
  activityName = new char[strlen(anActivity.activityName) + 1];
  activityLocation = new char[strlen(anActivity.activityLocation) + 1];
  activityLevel = new char[strlen(anActivity.activityLevel) + 1];
  *this = anActivity;
}

// destructor
Activity::~Activity()
{
  // deallocate memory for activityName
  if (activityName)
  {
    delete[] activityName;
    activityName = NULL;
  }
  // deallocate memory for activityLocation
  if (activityLocation)
  {
    delete[] activityLocation;
    activityLocation = NULL;
  }
  // deallocate memory for activityLevel
  if (activityLevel)
  {
    delete[] activityLevel;
    activityLevel = NULL;
  }
}

// mutator functions
void Activity::setActivityName(char *newName)
{
  if (activityName)
  {
    delete[] activityName;
    activityName = NULL;
  }
  activityName = new char[strlen(newName) + 1];
  strcpy(activityName, newName);
}

void Activity::setActivityLocation(char *newLocation)
{
  if (activityLocation)
  {
    delete[] activityLocation;
    activityLocation = NULL;
  }
  activityLocation = new char[strlen(newLocation) + 1];
  strcpy(activityLocation, newLocation);
}

void Activity::setActivityLevel(char *newLevel)
{
  if (activityLevel)
  {
    delete[] activityLevel;
    activityLevel = NULL;
  }
  activityLevel = new char[strlen(newLevel) + 1];
  strcpy(activityLevel, newLevel);
}

void Activity::setActivityRating(int newRating) { activityRating = newRating; }

void Activity::setActivityType(int newType) { activityType = newType; }

// accessor functions
void Activity::getActivityName(char *returnName)
{
  strcpy(returnName, activityName);
}

void Activity::getActivityLocation(char *returnLocation)
{
  strcpy(returnLocation, activityLocation);
}

void Activity::getActivityLevel(char *returnLevel)
{
  strcpy(returnLevel, activityLevel);
}

int Activity::getActivityRating() { return activityRating; }

int Activity::getActivityType() { return activityType; }

// print single activity
void Activity::printActivity()
{
  cout << activityName << ';' << activityLocation << ';' << activityLevel << ';'
       << activityRating << ';' << activityType << endl;
}

// prints single activity to file
void Activity::printActivity(ofstream &outFile)
{
  cout << activityName << ';' << activityLocation << ';' << activityLevel << ';'
       << activityRating << ';' << activityType << endl;
}

// assignment operator overloaded
const Activity &Activity::operator=(const Activity &anActivity)
{
  if (this == &anActivity)
    return *this;
  else
  {
    this->setActivityName(anActivity.activityName);
    this->setActivityLocation(anActivity.activityLocation);
    this->setActivityLevel(anActivity.activityLevel);
    this->activityRating = anActivity.activityRating;
    this->setActivityType(anActivity.activityType);

    return *this;
  }
}

// write data to outfile
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