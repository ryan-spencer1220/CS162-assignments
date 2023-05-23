#include "activitylist.h"
#include "tools.h"

// constructors
ActivityList::ActivityList()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

// constructor from file
ActivityList::ActivityList(char fileName[])
{
  head = NULL;
  tail = NULL;
  size = 0;
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
  Node *curr = head;
  while (curr)
  {
    head = curr->next;
    delete curr;
    curr = head;
  }
  tail = NULL;
}

// Add activity to activityList
void ActivityList::addActivity(Activity &anActivity)
{

  Node *newNode = NULL, *curr = NULL, *prev = NULL;
  char str1[MAXCHAR], str2[MAXCHAR];
  // populate newNode
  newNode = new Node;
  newNode->data = anActivity;
  newNode->next = NULL;
  // check to see if list is empty
  if (!head)
  {
    head = newNode;
    tail = newNode;
  }
  // if list is not empty, then insert sorted by title
  else
  {
    curr = head;
    curr->data.getActivityName(str1);
    newNode->data.getActivityName(str2);
    while (curr && isLessThan(str1, str2))
    {
      prev = curr;
      curr = curr->next;
      if (curr)
      {
        curr->data.getActivityName(str1);
      }
    }
    // check to see if we are at the end of our list
    if (!curr)
    {
      tail->next = newNode;
      tail = newNode;
    }
    // insert in between
    else if (prev)
    {
      newNode->next = curr;
      prev->next = newNode;
    }
    // insert at the beginning
    else
    {
      newNode->next = curr;
      head = newNode;
    }
  }
  size++;
}

// search by activityName
// void ActivityList::searchByName()
// {
//   char searchName[MAXCHAR];
//   char tempName[MAXCHAR];
//   int count = 1;

//   cout << "Enter the activity name (50 characters or less): ";
//   cin.get(searchName, MAXCHAR);

//   for (int i = 0; i < size; i++)
//   {
//     list[i].getActivityName(tempName);
//     if (strstr(tempName, searchName) != NULL)
//     {
//       if (count == 1)
//       {
//         cout << "Activity found!" << endl
//              << endl;
//       }
//       cout << count << ".";
//       list[i].printActivity();
//       count++;
//     }
//   }

//   if (count == 1)
//   {
//     cout << "Activity not found!!" << endl;
//   }

//   cout << endl;
// }

// search by activityLocation
// void ActivityList::searchByLocation()
// {
//   char searchLocation[MAXCHAR];
//   char tempLocation[MAXCHAR];
//   int count = 1;

//   cout << "Enter location name: ";
//   cin.get(searchLocation, MAXCHAR);

//   for (int i = 0; i < size; i++)
//   {
//     list[i].getActivityLocation(tempLocation);
//     if (strstr(tempLocation, searchLocation) != NULL)
//     {
//       if (count == 1)
//       {
//         cout << "Activity found!" << endl
//              << endl;
//       }
//       cout << count << ".";
//       list[i].printActivity();
//       count++;
//     }
//   }

//   if (count == 1)
//   {
//     cout << "Activity not found!!" << endl;
//   }

//   cout << endl;
// }

// search by activityType
// void ActivityList::searchByType()
// {
//   char searchType[MAXCHAR];
//   char tempType[MAXCHAR];
//   int userInt;
//   int count = 1;
//   char prompt[MAXCHAR] =
//       "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and 4-Others): ";

//   userInt = readInt(prompt);

//   retrieveActivityType(userInt, searchType);

//   cout << endl;

//   for (int i = 0; i < size; i++)
//   {
//     list[i].getActivityType(tempType);
//     if (strstr(tempType, searchType) != NULL)
//     {
//       if (count == 1)
//       {
//         cout << "Activity found!" << endl
//              << endl;
//       }
//       cout << count << ".";
//       list[i].printActivity();
//       count++;
//     }
//   }

//   if (count == 1)
//   {
//     cout << "Activity not found!!" << endl;
//   }

//   cout << endl;
// }

// writes data to outFile
void ActivityList::writeData(char fileName[])
{
  ofstream outFile;
  outFile.open(fileName);
  Node *curr;
  for (curr = head; curr; curr = curr->next)
  {
    curr->data.printActivity(outFile);
  }
  cout << endl;
}

// displays list
void ActivityList::showList()
{
  int count = 1;
  Node *curr;
  for (curr = head; curr; curr = curr->next)
  {
    cout << count << ".";
    curr->data.printActivity();
    count++;
  }
  cout << endl;
}

// remove activity from activityList
void ActivityList::removeActivity()
{
  // code
}