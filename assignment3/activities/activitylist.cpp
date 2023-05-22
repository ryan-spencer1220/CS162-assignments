#include "activitylist.h"
#include "tools.h"

// constructors
ActivityList::ActivityList()
{
  capacity = CAP;
  list = new Activity[capacity];
  size = 0;
}

// constructor from file
ActivityList::ActivityList(char fileName[])
{
  capacity = CAP;

  list = new Activity[capacity];

  size = 0;
  ifstream inFile;
  Activity anActivity;
  char tempActivityName[MAXCHAR];
  char tempActivityLocation[MAXCHAR];
  char tempActivityLevel[MAXCHAR];
  int tempActivityRating = 0;
  char tempActivityType[MAXCHAR];

  inFile.open(fileName);
  if (!inFile)
  {
    cout << "cannot open file! Exiting!!" << endl;
    exit(0);
  }
  while (!inFile.eof())
  {
    inFile.get(tempActivityName, MAXCHAR, ';');
    inFile.ignore(100, ';');
    inFile.get(tempActivityLocation, MAXCHAR, ';');
    inFile.ignore(100, ';');
    inFile.get(tempActivityLevel, MAXCHAR, ';');
    inFile.ignore(100, ';');
    inFile >> tempActivityRating;
    inFile.ignore(100, ';');
    inFile.get(tempActivityType, MAXCHAR, '\n');
    inFile.ignore(100, '\n');
    anActivity.setActivityName(tempActivityName);
    anActivity.setActivityLocation(tempActivityLocation);
    anActivity.setActivityLevel(tempActivityLevel);
    anActivity.setActivityRating(tempActivityRating);
    anActivity.setActivityType(tempActivityType);

    addActivity(anActivity);
  }
  inFile.close();
}

// destructor
ActivityList::~ActivityList()
{
  if (list)
  {
    delete[] list;
    list = NULL;
  }
}

// Add activity to activityList
void ActivityList::addActivity(Activity &anActivity)
{
  if (size == capacity)
  {
    growList();
  }

  int i = 0;
  char tempActivityName[MAXCHAR];
  char newActivityName[MAXCHAR];

  anActivity.getActivityName(newActivityName);

  for (i = 0; i < size; i++)
  {
    list[i].getActivityName(tempActivityName);

    if (!(isLessThan(tempActivityName, newActivityName)))
    {
      break;
    }
  }
  for (int j = size; j > i; j--)
  {
    list[j] = list[j - 1];
  }
  list[i] = anActivity;
  size++;
}

// search by activityName
void ActivityList::searchByName()
{
  char searchName[MAXCHAR];
  char tempName[MAXCHAR];
  int count = 1;

  cout << "Enter the activity name (50 characters or less): ";
  cin.get(searchName, MAXCHAR);

  for (int i = 0; i < size; i++)
  {
    list[i].getActivityName(tempName);
    if (strstr(tempName, searchName) != NULL)
    {
      if (count == 1)
      {
        cout << "Activity found!" << endl
             << endl;
      }
      cout << count << ".";
      list[i].printActivity();
      count++;
    }
  }

  if (count == 1)
  {
    cout << "Activity not found!!" << endl;
  }

  cout << endl;
}

// search by activityLocation
void ActivityList::searchByLocation()
{
  char searchLocation[MAXCHAR];
  char tempLocation[MAXCHAR];
  int count = 1;

  cout << "Enter location name: ";
  cin.get(searchLocation, MAXCHAR);

  for (int i = 0; i < size; i++)
  {
    list[i].getActivityLocation(tempLocation);
    if (strstr(tempLocation, searchLocation) != NULL)
    {
      if (count == 1)
      {
        cout << "Activity found!" << endl
             << endl;
      }
      cout << count << ".";
      list[i].printActivity();
      count++;
    }
  }

  if (count == 1)
  {
    cout << "Activity not found!!" << endl;
  }

  cout << endl;
}

// search by activityType
void ActivityList::searchByType()
{
  char searchType[MAXCHAR];
  char tempType[MAXCHAR];
  int userInt;
  int count = 1;
  char prompt[MAXCHAR] =
      "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and 4-Others): ";

  userInt = readInt(prompt);

  retrieveActivityType(userInt, searchType);

  cout << endl;

  for (int i = 0; i < size; i++)
  {
    list[i].getActivityType(tempType);
    if (strstr(tempType, searchType) != NULL)
    {
      if (count == 1)
      {
        cout << "Activity found!" << endl
             << endl;
      }
      cout << count << ".";
      list[i].printActivity();
      count++;
    }
  }

  if (count == 1)
  {
    cout << "Activity not found!!" << endl;
  }

  cout << endl;
}

// writes data to outFile
void ActivityList::writeData(char fileName[])
{
  ofstream outFile;
  outFile.open(fileName);

  for (int i = 0; i < size; i++)
  {
    list[i].writeActivity(outFile, i, size);
  }
}

// displays list
void ActivityList::showList()
{
  for (int i = 0; i < size; i++)
  {
    cout << i + 1 << ") ";
    list[i].printActivity();
  }
  cout << endl;
}

// remove activity from activityList
void ActivityList::removeActivity()
{
  int delIndex = 0;
  char prompt[MAXCHAR] = "Please enter index to delete: ";
  delIndex = readInt(prompt);
  if (delIndex < size)
  {
    for (int i = delIndex; i < size; i++)
    {
      list[i - 1] = list[i];
    }
  }
  size--;
  cout << endl
       << "Activity removed!" << endl;
}

// adds capacity to activityList IF full
void ActivityList::growList()
{
  capacity += GROWTH;

  Activity *tempList = new Activity[capacity];
  for (int i = 0; i < size; i++)
  {
    tempList[i] = list[i];
  }

  delete[] list;
  list = tempList;
  tempList = NULL;
}