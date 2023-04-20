#include "activityList.h"
#include "main.h"

// constructors
// default constructor
ActivityList::ActivityList() { size = 0; }

// constructor from file
ActivityList::ActivityList(char fileName[])
{
  size = 0;
  ifstream inFile;
  Activity activity;
  char tempString[MAXCHAR];
  int tempNumber = 0;

  inFile.open(fileName);

  if (!inFile)
  {
    cout << "File did not open! Program terminating!!" << endl;
    exit(0);
  }

  while (inFile)
  {
    // load activityName
    inFile.get(tempString, MAXCHAR, ';');
    activity.setActivityName(tempString);
    inFile.ignore(100, ';');
    // load activityLocation
    inFile.get(tempString, MAXCHAR, ';');
    activity.setActivityLocation(tempString);
    inFile.ignore(100, ';');
    // load activityLevel
    inFile.get(tempString, MAXCHAR, ';');
    activity.setActivityLevel(tempString);
    inFile.ignore(100, ';');
    // load activityRating
    inFile >> tempNumber;
    activity.setActivityRating(tempNumber);
    inFile.ignore(100, ';');
    // load activityType
    inFile.get(tempString, MAXCHAR, '\n');
    activity.setActivityType(tempString);
    inFile.ignore(100, '\n');

    activityList[size] = activity;
    size++;
  }
  inFile.close();
}

// destructor
ActivityList::~ActivityList()
{
  // do nothing
}

// add activity
void ActivityList::addActivity(Activity activity)
{
  int i = 0;
  char tempActivityName[MAXCHAR];
  char newActivityName[MAXCHAR];

  activity.getActivityName(newActivityName);

  for (i = 0; i < size; i++)
  {
    activityList[i].getActivityName(tempActivityName);
    if (!(isLessThan(tempActivityName, newActivityName)))
    {
      break;
    }
  }
  for (int j = size; j > i; j--)
  {
    activityList[j] = activityList[j - 1];
  }
  activityList[i] = activity;
  size++;
  cout << endl
       << "Activity added!" << endl
       << endl;
}

// search by Type
void ActivityList::searchByType()
{
  char searchType[MAXCHAR];
  char tempType[MAXCHAR];
  int userInt;
  int count = 1;

  userInt = readInt(
      "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and 4-Others): ",
      userInt);

  retrieveActivityType(userInt, searchType);

  cout << endl;

  for (int i = 0; i < size; i++)
  {
    activityList[i].getActivityType(tempType);
    if (strstr(tempType, searchType) != NULL)
    {
      if (count == 1)
      {
        cout << "Activity found!" << endl
             << endl;
      }
      cout << count << ".";
      activityList[i].printActivity();
      count++;
    }
  }

  if (count == 1)
  {
    cout << "Activity not found!!" << endl;
  }

  cout << endl;
}

// search by Location
void ActivityList::searchByLocation()
{
  char searchLocation[MAXCHAR];
  char tempLocation[MAXCHAR];
  int count = 1;

  cout << "Enter location name: ";
  cin.get(searchLocation, MAXCHAR);

  for (int i = 0; i < size; i++)
  {
    activityList[i].getActivityLocation(tempLocation);
    if (strstr(tempLocation, searchLocation) != NULL)
    {
      if (count == 1)
      {
        cout << "Activity found!" << endl
             << endl;
      }
      cout << count << ".";
      activityList[i].printActivity();
      count++;
    }
  }

  if (count == 1)
  {
    cout << "Activity not found!!" << endl;
  }

  cout << endl;
}

// search by Name
void ActivityList::searchByName()
{
  char searchName[MAXCHAR];
  char tempName[MAXCHAR];
  int count = 1;

  cout << "Enter the activity name (50 characters or less): ";
  cin.get(searchName, MAXCHAR);

  for (int i = 0; i < size; i++)
  {
    activityList[i].getActivityName(tempName);
    if (strstr(tempName, searchName) != NULL)
    {
      if (count == 1)
      {
        cout << "Activity found!" << endl
             << endl;
      }
      cout << count << ".";
      activityList[i].printActivity();
      count++;
    }
  }

  if (count == 1)
  {
    cout << "Activity not found!!" << endl;
  }

  cout << endl;
}

void ActivityList::writeData(char fileName[])
{
  ofstream outFile;
  outFile.open(fileName);

  for (int i = 0; i < size; i++)
  {
    activityList[i].writeActivity(outFile, i, size);
  }
}

// displays the list
void ActivityList::showList()
{
  for (int i = 0; i < size; i++)
  {
    cout << i + 1 << ".";
    activityList[i].printActivity();
  }

  cout << endl;
}

// removes activity
void ActivityList::removeActivity()
{
  int delIndex = 0;

  delIndex = readInt("Please enter index of song to delete: ", delIndex);

  if (delIndex < size)
  {
    for (int i = delIndex; i < size; i++)
    {
      activityList[i - 1] = activityList[i];
    }
  }

  size--;
  cout << endl
       << "Activity removed!" << endl
       << endl;
}