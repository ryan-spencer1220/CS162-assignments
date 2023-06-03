#include "tools.h"
#include "activity.h"

// displays welcome message
void welcomeMessage()
{
  cout << "Welcome!" << endl;
  cout << "This program will help you manage your activities." << endl
       << endl;
}

// displays goodbye message
void goodbyeMessage()
{
  cout << endl
       << "Activities written to file! Thank you for using my program!!" << endl
       << endl;
}

// displays the menu
void displayMenu()
{
  cout << "Pick an option from below:" << endl
       << endl;
  cout << "(a)Add a new activity" << endl;
  cout << "(b)List activities by name" << endl;
  cout << "(c)List activities by location" << endl;
  cout << "(d)List activities by type" << endl;
  cout << "(e)Remove an activity" << endl;
  cout << "(f)Search by activity name" << endl;
  cout << "(g)List the last activity in the list" << endl;
  cout << "(h)List activities by name in reverse order" << endl;
  cout << "(q)Quit" << endl
       << endl;
}

// read the option from the user
char readOption()
{
  char input;
  cin >> input;
  cin.ignore(100, '\n');
  return input;
}

// execute the option
void exeCmd(char option, ActivityList &activityList)
{
  Activity anActivity;
  char locationPrompt[MAXCHAR] = "Enter location name: ";
  char typePrompt[MAXCHAR] =
      "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and 4-Others): ";
  char namePrompt[MAXCHAR] = "Enter the activity name (50 characters or less): ";
  int userInt = 0, size = 0, toRemove = 0;

  switch (tolower(option))
  {
  case 'a':
    addActivity(anActivity, activityList);
    cout << endl
         << "Activity Added!"
         << endl;
    activityList.showList();
    break;
  case 'b':
    activityList.showList();
    break;
  case 'c':
    char searchLocation[MAXCHAR];
    readString(locationPrompt, searchLocation);
    activityList.searchByLocation(searchLocation);
    break;
  case 'd':
    userInt = readInt(typePrompt);
    activityList.searchByType(userInt);
    break;
  case 'e':
    activityList.showList();
    size = activityList.getSize();
    toRemove = deleteIndexDisplay(size);
    activityList.removeActivity(toRemove);
    cout << endl;
    activityList.showList();
    break;
  case 'f':
    char searchActivity[MAXCHAR];
    readString(namePrompt, searchActivity);
    activityList.searchByName(searchActivity);
    break;
  case 'g':
    activityList.showLast();
    break;
  case 'h':
    activityList.reverseList();
    break;
  case 'q':
    break;
  default:
    cout << "Invalid input, please try again!!" << endl;
  }
}

// read interget check if
int readInt(char prompt[])
{
  int temp = 0;
  cout << prompt;
  cin >> temp;
  // data validation
  while (!cin || temp < 0)
  {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Invalid input!! Please try again!!";
    cout << prompt;
    cin >> temp;
  }
  cin.ignore(100, '\n');

  return temp;
}

void readString(char prompt[], char temp[])
{
  cout << prompt;
  cin.getline(temp, MAXCHAR);
  for (int i = 0; temp[i]; i++)
  {
    if (temp[i] == ';')
    {
      cout << "Invalid string! Please remove all semicolons from entry!" << endl;
      cout << prompt;
      cin.clear();
      readString(prompt, temp);
    }
  }
}

// populate activity from the user
void addActivity(Activity &anActivity, ActivityList &activityList)
{
  // temp variables
  char tempName[MAXCHAR], tempLocation[MAXCHAR], tempLevel[MAXCHAR];
  int tempRating = 0;
  int tempType = 0;

  // prompt variables
  char namePrompt[MAXCHAR] = "Enter the activity name (50 characters or less): ";
  char locationPrompt[MAXCHAR] = "Enter the activity location (50 characters or less): ";
  char levelPrompt[MAXCHAR] = "Enter the activity level: ";
  char ratingPrompt[MAXCHAR] = "Enter the activity rating: ";
  char typePrompt[MAXCHAR] =
      "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and 4-Others): ";

  // read user input
  readString(namePrompt, tempName);
  readString(locationPrompt, tempLocation);
  readString(levelPrompt, tempLevel);
  tempRating = readInt(ratingPrompt);
  tempType = readInt(typePrompt);

  // call setter functions
  anActivity.setActivityName(tempName);
  anActivity.setActivityLocation(tempLocation);
  anActivity.setActivityLevel(tempLevel);
  anActivity.setActivityRating(tempRating);
  anActivity.setActivityType(tempType);

  // add activity to list
  activityList.addActivity(anActivity);
}

// converts all text to upper case
void convertCase(char tempStr[])
{
  for (int i = 0; i < strlen(tempStr); i++)
  {
    tempStr[i] = toupper(tempStr[i]);
  }
}

// sets activityListType to char array based on numerical input
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

// compares two char arrays, used to sort list alphabetically
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

void activityFoundDisplay(int count)
{
  count == 1 && cout << "Activity Found!" << endl;
  cout << count << ". ";
}

void activityNotFoundDisplay(int count)
{
  count == 1 && cout << "Activity Not Found..." << endl;
  cout << endl;
}

int deleteIndexDisplay(int size)
{
  int index = 0;
  char prompt[MAXCHAR] = "Select number for song to remove: ";
  char prompt2[MAXCHAR] = "Bad Index, please re-enter: ";
  index = readInt(prompt);
  while (index < 1 || index > size)
  {
    index = readInt(prompt2);
  }
  return index;
}