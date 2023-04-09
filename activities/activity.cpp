#include "activity.h"
#include "main.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

// Name:		      printData()
// Description:   This function loops through a list of structs and displays the details of each entry
// input:         Activity activityList[], int &size
// output:        struct data
// return:	      n/a
void printData(Activity activityList[], int size)
{
  cout << endl;
  for (int i = 0; i < size; i++)
  {
    cout << i + 1 << ". " << activityList[i].name << ";"
         << activityList[i].location << ";" << activityList[i].level << ";"
         << activityList[i].rating << ";" << activityList[i].type << endl;
  }
  cout << endl;
}

// Name:		      addActivity()
// Description:   This function prompts the user for information about a new activity, and adds infromation to external file.
// input:         Activity activityList[], int &size
// output:        prompts for activity details, possible error message, possible confirmation message
// return:	      n/a
void addActivity(Activity activityList[], int &size)
{
  ofstream outFS;
  int typeNumber = 0;
  outFS.open("activities.txt", ios::app);

  if (!outFS.is_open())
  {
    cout << "Could not open file activities.txt." << endl;
    exit(0);
  }
  cout << endl;
  outFS << endl;

  readString(
      "Enter the activity name (50 characters or less): ",
      activityList[size].name);
  outFS << activityList[size].name;
  outFS << ";";
  readString(
      "Enter the activity location (50 characters or less): ",
      activityList[size].location);
  outFS << activityList[size].location;
  outFS << ";";
  readString("Enter the activity level: ", activityList[size].level);
  outFS << activityList[size].level;
  outFS << ";";
  activityList[size].rating =
      readInt("Enter the activity rating: ", activityList[size].rating);
  outFS << activityList[size].rating;
  outFS << ";";
  typeNumber = readInt(
      "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and "
      "4-Others): ",
      typeNumber);
  while (typeNumber > size)
  {
    cout << "Invalid! Please select a number between 1 and 4" << endl;
    typeNumber = readInt(
        "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and "
        "4-Others): ",
        typeNumber);
  }
  printActivityType(typeNumber, activityList[size].type);
  outFS << activityList[size].type;

  cout << endl
       << "Activity added!" << endl;
}

// Name:		      removeActivity()
// Description:   This function prompts the user for the index of an item to delete, then removes the item from the list.
// input:         Activity activityList[], int &size
// output:        prompt for index, possible error message
// return:	      n/a
void removeActivity(Activity activityList[], int &size, ofstream &outFS)
{
  int typeNumber = 0;
  int delIndex = 0;
  delIndex = readInt("Pick the index to remove: ", delIndex);

  while (delIndex > size)
  {
    cout << "Please select a number between 1 and " << size << endl;
    delIndex = readInt("Pick the index to remove: ", delIndex);
  }

  delIndex--;
  if (delIndex < size)
  {
    for (int i = delIndex + 1; i < size; i++)
    {
      activityList[i - 1] = activityList[i];
    }
  }
  size--;
  writeData(activityList, size, outFS);
}

// Name:		      searchByName()
// Description:   This function prompts the user for a name and searches through the activityList. If matching results are found they will be displayed, otherwise a fail message will be displayed.
// input:         Activity activityList[], int &size
// output:        prompt for name, list of activities or fail message
// return:	      n/a
void searchByName(Activity activityList[], int &size)
{
  int count = 0;
  char searchActivity[MAXCHAR];
  cout << "Enter the activity name (50 characters or less): ";
  cin.get(searchActivity, MAXCHAR, '\n');

  for (int i = 0; i < size; i++)
  {
    if (strstr(activityList[i].name, searchActivity) != NULL)
    {
      count++;
      if (count == 1)
      {
        cout << endl
             << "Activity found!" << endl;
      }
      cout << count << ". " << activityList[i].name << ";"
           << activityList[i].location << ";" << activityList[i].level
           << ";" << activityList[i].rating << ";" << activityList[i].type
           << endl;
    }
  }
  if (count == 0)
  {
    cout << endl
         << "Activity not found!!" << endl;
  }
}

// Name:		      searchByType()
// Description:   This function prompts the user for a tuype and searches through the activityList. If matching results are found they will be displayed, otherwise a fail message will be displayed.
// input:         Activity activityList[], int &size
// output:        prompt for type, list of activities or fail message
// return:	      n/a
void searchByType(Activity activityList[], int &size)
{
  int searchLocationNumber = 0;
  char searchLocation[MAXCHAR];
  int count = 0;
  searchLocationNumber = readInt(
      "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and "
      "4-Others): ",
      searchLocationNumber);
  printActivityType(searchLocationNumber, searchLocation);

  cout << endl;

  for (int i = 0; i < size; i++)
  {
    if (strstr(activityList[i].type, searchLocation) != NULL)
    {
      count++;
      if (count == 1)
      {
        cout << endl
             << "Activity found!" << endl;
      }
      cout << count << ". " << activityList[i].name << ";"
           << activityList[i].location << ";" << activityList[i].level
           << ";" << activityList[i].rating << ";" << activityList[i].type
           << endl;
    }
  }
  if (count == 0)
  {
    cout << endl
         << "Activity not found!!" << endl;
  }
}

// Name:		      searchByLocation()
// Description:   This function prompts the user for a location and searches through the activityList. If matching results are found they will be displayed, otherwise a fail message will be displayed.
// input:         Activity activityList[], int &size
// output:        prompt for location, list of activities or fail message
// return:	      n/a
void searchByLocation(Activity activityList[], int &size)
{
  char searchLocation[MAXCHAR];
  int count = 0;
  cout << "Enter location name: ";
  cin.get(searchLocation, MAXCHAR, '\n');

  cout << endl;

  for (int i = 0; i < size; i++)
  {
    if (strstr(activityList[i].location, searchLocation) != NULL)
    {
      count++;
      if (count == 1)
      {
        cout << endl
             << "Activity found!" << endl;
      }
      cout << count << ". " << activityList[i].name << ";"
           << activityList[i].location << ";" << activityList[i].level
           << ";" << activityList[i].rating << ";" << activityList[i].type
           << endl;
    }
  }
  if (count == 0)
  {
    cout << endl
         << "Activity not found!!" << endl;
  }
}

// Name:		      printActivityType()
// Description:   This function maps the number to the associated activity type string
// input:         int tempNumber, char activityListType[]
// output:        activityListType
// return:	      n/a
void printActivityType(int tempNumber, char activityListType[])
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

// Name:		      loadData()
// Description:   This function writes data to an external file and displays a confirmation message
// input:         ifstream &inFile, Activity activityList[], int &size
// output:        possible error message
// return:	      n/a
void loadData(ifstream &inFile, Activity activityList[], int &size)
{
  Activity tempActivity;
  int i = 0;
  size = 0;

  inFile.open("activities.txt");

  if (!inFile)
  {
    cout << "File did not open! Program terminating!!" << endl;
    exit(0);
  }

  while (inFile)
  {
    inFile.get(tempActivity.name, MAXCHAR, ';');
    inFile.ignore(100, ';');
    inFile.get(tempActivity.location, MAXCHAR, ';');
    inFile.ignore(100, ';');
    inFile.get(tempActivity.level, MAXCHAR, ';');
    inFile.ignore(100, ';');
    inFile >> tempActivity.rating;
    inFile.ignore(100, ';');
    inFile >> tempActivity.type;
    inFile.ignore(100, '\n');

    if (!size)
    {
      activityList[size] = tempActivity;
    }
    else
    {
      for (i = 0; i < size; i++)
      {
        if (!(isLessThan(activityList[i].name, tempActivity.name)))
        {
          break;
        }
      }
      for (int j = size; j > i; j--)
      {
        activityList[j] = activityList[j - 1];
      }
      activityList[i] = tempActivity;
    }
    size++;
  }
  inFile.close();
}