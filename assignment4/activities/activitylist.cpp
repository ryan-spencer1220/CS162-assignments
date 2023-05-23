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
  int tempActivityType = 0;

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
    inFile >> tempActivityType;
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
void ActivityList::searchByName()
{
  char tempActivity[MAXCHAR], searchActivity[MAXCHAR];
  cout << "Enter the activity name (50 characters or less): ";
  cin.getline(searchActivity, MAXCHAR);
  for (Node *curr = head; curr; curr = curr->next)
  {
    curr->data.getActivityName(tempActivity);
    if (strstr(tempActivity, searchActivity) != NULL)
    {
      curr->data.printActivity();
    }
  }
  cout << endl;
}

// search by activityLocation
void ActivityList::searchByLocation()
{
  char tempLocation[MAXCHAR], searchLocation[MAXCHAR];
  cout << "Enter location name: ";
  cin.getline(searchLocation, MAXCHAR);
  for (Node *curr = head; curr; curr = curr->next)
  {
    curr->data.getActivityLocation(tempLocation);
    if (strstr(tempLocation, searchLocation) != NULL)
    {
      curr->data.printActivity();
    }
  }
  cout << endl;
}

// search by activityType
void ActivityList::searchByType()
{
  int userInt = 0;
  char prompt[MAXCHAR] =
      "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and 4-Others): ";
  userInt = readInt(prompt);
  for (Node *curr = head; curr; curr = curr->next)
  {
    if (userInt == curr->data.getActivityType())
    {
      curr->data.printActivity();
    }
  }
  cout << endl;
}

// writes data to outFile
void ActivityList::writeData(char fileName[])
{
  int count = 0;
  ofstream outFile;
  outFile.open(fileName);
  Node *curr;
  for (curr = head; curr; curr = curr->next)
  {
    curr->data.writeActivity(outFile, count, size);
    count++;
  }
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
  cout << "We haven't implemented this option yet. Check back in a few weeks!" << endl;
}