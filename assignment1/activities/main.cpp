#include "main.h"
#include <iostream>

// main function
int main()
{
  Activity activityList[CAP];
  char fileName[MAXCHAR];
  char option;
  ifstream inFile;
  ofstream outFile;
  int size = 0;

  loadData(inFile, activityList, size);
  cout << "Welcome!" << endl;
  cout << "This program will help you manage your activities." << endl;

  do
  {
    displayMenu();
    option = readOption();
    executeCommand(option, activityList, size, inFile, outFile);
  } while (tolower(option != 'q'));

  writeData(activityList, size, outFile);

  return 0;
}

// Name:		      readInt()
// Description:   This function checks to see if the input is an integer. If the function is not an integer, the function returns an error message and prompts the user to enter an integer.
// input:         string prompt, int temp
// output:        error message (possibly)
// return:	      int temp
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

// Name:		      readString()
// Description:   This function checks to see if the input contains a semicolon.
// input:         string prompt, char temp[]
// output:        error message (possibly)
// return:	      n/a
void readString(string prompt, char temp[])
{
  cout << prompt;
  cin.getline(temp, MAXCHAR);
  for (int i = 0; temp[i]; i++)
  {
    if (temp[i] == ';')
    {
      cout << "Invalid string! Please remove all commas from entry!"
           << endl;
      cin.clear();
      readString(prompt, temp);
    }
  }
}

// Name:		      isLessThan()
// Description:   This function compares two char arrays
// input:         char activityName1[], char activityName2[]
// output:        n/a
// return:	      bool
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

// Name:		      displayMenu()
// Description:   This function displays a menu of options the user can choose from
// input:         n/a
// output:        n/a
// return:	      n/a
void displayMenu()
{
  cout << endl;
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

// Name:		      readOption()
// Description:   This function reads an option from a user
// input:         n/a
// output:        n/a
// return:	      char option
char readOption()
{
  char input;
  cin >> input;
  cin.ignore(100, '\n');
  return input;
}

// Name:		      executeCommand
// Description:   This function reads the user choice and fires the function assoicated with their choice
// input:         char option, Activity activityList[], int &size, ifstream &inFile
// output:        error message (possibly)
// return:	      n/a
void executeCommand(
    char option,
    Activity activityList[],
    int &size,
    ifstream &inFile, ofstream &outFS)
{
  switch (tolower(option))
  {
  case 'a':
    if (size == CAP)
    {
      cout << "Your list is Full! Activity not added!!";
      return;
    }
    addActivity(activityList, size);
    loadData(inFile, activityList, size);
    printData(activityList, size);
    break;
  case 'b':
    loadData(inFile, activityList, size);
    printData(activityList, size);
    break;
  case 'c':
    searchByLocation(activityList, size);
    break;
  case 'd':
    searchByType(activityList, size);
    break;
  case 'e':
    printData(activityList, size);
    removeActivity(activityList, size, outFS);
    printData(activityList, size);
    break;
  case 'f':
    searchByName(activityList, size);
    break;
  case 'q':
    break;
  default:
    cout << "Invalid option!! Please try again!" << endl;
  }
}

// Name:		      writeData()
// Description:   This function writes data to an external file and displays a confirmation message
// input:         Activity activityList[], int &size, ofstream &outFile
// output:        confirmation message
// return:	      n/a
void writeData(Activity activityList[], int &size, ofstream &outFile)
{
  outFile.open("activities.txt", std::ofstream::out | std::ofstream::trunc);

  for (int i = 0; i < size; i++)
  {
    outFile << activityList[i].name;
    outFile << ";";
    outFile << activityList[i].location;
    outFile << ";";
    outFile << activityList[i].level;
    outFile << ";";
    outFile << activityList[i].rating;
    outFile << ";";
    outFile << activityList[i].type;
    if (i != size - 1)
    {
      outFile << endl;
    }
  }
  outFile.close();

  cout << endl
       << "Activities written to file! Thank you for using my program!!"
       << endl;
}