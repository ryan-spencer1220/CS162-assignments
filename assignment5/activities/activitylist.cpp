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
  if (!head)
  {
    head = newNode;
    tail = newNode;
  }
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
    if (!curr)
    {
      tail->next = newNode;
      tail = newNode;
    }
    else if (prev)
    {
      newNode->next = curr;
      prev->next = newNode;
    }
    else
    {
      newNode->next = curr;
      head = newNode;
    }
  }
  size++;
}

// search by activityName
void ActivityList::searchByName(char searchActivity[])
{
  char tempActivity[MAXCHAR];
  int count = 1;
  for (Node *curr = head; curr; curr = curr->next)
  {
    curr->data.getActivityName(tempActivity);
    if (strstr(tempActivity, searchActivity) != NULL)
    {
      activityFoundDisplay(count);
      curr->data.printActivity();
      count++;
    }
  }
  activityNotFoundDisplay(count);
}

// search by activityLocation
void ActivityList::searchByLocation(char searchLocation[])
{
  char tempLocation[MAXCHAR];
  int count = 1;
  for (Node *curr = head; curr; curr = curr->next)
  {
    curr->data.getActivityLocation(tempLocation);
    if (strstr(tempLocation, searchLocation) != NULL)
    {
      activityFoundDisplay(count);
      curr->data.printActivity();
      count++;
    }
  }
  activityNotFoundDisplay(count);
}

// search by activityType
void ActivityList::searchByType(int userInt)
{
  int count = 1;
  for (Node *curr = head; curr; curr = curr->next)
  {
    if (userInt == curr->data.getActivityType())
    {
      activityFoundDisplay(count);
      curr->data.printActivity();
      count++;
    }
  }
  activityNotFoundDisplay(count);
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

// displays last node
void ActivityList::showLast()
{
  int count = 1;
  Node *curr;
  for (curr = head; curr; curr = curr->next)
  {
    if (count == size)
    {
      cout << count << ".";
      curr->data.printActivity();
    }
    count++;
  }
  cout << endl;
}

// reverse linked list
void ActivityList::reverseList()
{
  int count = 1;
  Node *curr;
  Node *temp;
  for (curr = head; curr; curr = curr->next)
  {
    if (curr == head)
    {
      curr->prev = NULL;
    }
    else
    {
      curr->prev = temp;
    }
    temp = curr;
  }
  for (curr = tail; curr; curr = curr->prev)
  {
    cout << count << ".";
    curr->data.printActivity();
    count++;
  }
  cout << endl;
}

// remove activity from activityList
void ActivityList::removeActivity(int toRemove)
{
  int count = 1;
  if (!size)
  {
    cout << "Nothing to remove! Terminating..." << endl;
    return;
  }
  Node *curr = head;
  Node *prev = NULL;

  while (curr && count < toRemove)
  {
    prev = curr;
    curr = curr->next;
    count++;
  }
  if (!prev)
  {
    head = curr->next;
  }
  else if (curr == tail)
  {
    prev->next = curr->next;
    tail = prev;
  }
  else
  {
    prev->next = curr->next;
  }
  delete curr;
  curr = NULL;
  prev = NULL;
  size--;
}

int ActivityList::getSize()
{
  return size;
}
