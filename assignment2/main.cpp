#include "main.h"
#include "activity.h"
#include "activityList.h"
#include <iostream>

int main()
{
  char fileName[MAXCHAR] = "activities.txt";
  char option;

  welcomeMessage();
  ActivityList activityList(fileName);

  do
  {
    displayMenu();
    option = readOption();
    executeCommand(option, activityList);
  } while (tolower(option != 'q'));

  activityList.writeData(fileName);

  goodbyeMessage();
}

// displays the menu
void displayMenu()
{
  cout << "Pick an option from below:" << endl
       << endl;
  cout << "(a)Add a new activity" << endl;
  cout << "(b)List activities by name" << endl;
  cout << "(c)List activities by location" << endl;
  cout << "(d)List activities by Type" << endl;
  cout << "(e)Remove an activity" << endl;
  cout << "(f)Search by activity name" << endl;
  cout << "(q)Quit" << endl
       << endl;
}

void welcomeMessage()
{
  cout << "Welcome!" << endl;
  cout << "This program will help you manage your activities." << endl
       << endl;
}

void goodbyeMessage()
{
  cout << endl
       << "Activities written to file! Thank you for using my program!!" << endl
       << endl;
}

char readOption()
{
  char input;
  cin >> input;
  cin.ignore(100, '\n');
  return input;
}

int readInt(string prompt, int temp)
{
  cout << prompt;
  cin >> temp;
  while (!cin || temp < 0)
  {
    cout << "Invalid number! Please try again!!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << prompt;
    cin >> temp;
  }
  cin.ignore(5, '\n');
  return temp;
}

void readString(string prompt, char temp[])
{
  cout << prompt;
  cin.getline(temp, MAXCHAR);
  for (int i = 0; temp[i]; i++)
  {
    if (temp[i] == ';')
    {
      cout << "Invalid string! Please remove all commas from entry!" << endl;
      cin.clear();
      readString(prompt, temp);
    }
  }
}

void executeCommand(char option, ActivityList &activityList)
{
  Activity activity;
  switch (tolower(option))
  {
  case 'a':
    addActivity(activity);
    activityList.addActivity(activity);
    activityList.showList();
    break;
  case 'b':
    activityList.showList();
    break;
  case 'c':
    activityList.searchByLocation();
    break;
  case 'd':
    activityList.searchByType();
    break;
  case 'e':
    activityList.showList();
    activityList.removeActivity();
    activityList.showList();
    break;
  case 'f':
    activityList.searchByName();
    break;
  case 'q':
    break;
  default:
    cout << "Invalid option!! Please try again!" << endl
         << endl;
  }
}

// populate activity from user
void addActivity(Activity &activity)
{
  char letter;
  char tempName[MAXCHAR], tempLocation[MAXCHAR], tempLevel[MAXCHAR],
      tempType[MAXCHAR];
  int tempRating = 0;
  int tempIntType = 0;

  cout << "Enter the activity name (50 characters or less): ";
  cin.get(tempName, MAXCHAR, '\n');
  cin.ignore(100, '\n');
  cout << "Enter the activity location (50 characters or less): ";
  cin.get(tempLocation, MAXCHAR, '\n');
  cin.ignore(100, '\n');
  cout << "Enter the activity level: ";
  cin.get(tempLevel, MAXCHAR, '\n');
  cin.ignore(100, '\n');
  tempRating = readInt("Enter the activity rating: ", tempRating);
  tempIntType = readInt(
      "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and 4-Others): ",
      tempIntType);
  retrieveActivityType(tempIntType, tempType);

  // populate activity calling the mutator functions
  activity.setActivityName(tempName);
  activity.setActivityLocation(tempLocation);
  activity.setActivityLevel(tempLevel);
  activity.setActivityRating(tempRating);
  activity.setActivityType(tempType);
}

void retrieveActivityType(int tempNumber, char activityListType[])
{
  switch (tempNumber)
  {
  case 0:
    strcpy(activityListType, "Athletics");
    break;
  case 1:
    strcpy(activityListType, "Food");
    break;
  case 2:
    strcpy(activityListType, "Arts");
    break;
  case 3:
    strcpy(activityListType, "Games");
    break;
  case 4:
    strcpy(activityListType, "Others");
    break;
  }
  return;
}

bool isLessThan(char activityName1[], char activityName2[])
{
  if (strcmp(activityName1, activityName2) < 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}