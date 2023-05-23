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
  cout << "(d)List activities by Type" << endl;
  cout << "(e)Remove an activity" << endl;
  cout << "(f)Search by activity name" << endl;
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
  switch (tolower(option))
  {
  case 'a':
    addActivity(anActivity, activityList);
    activityList.showList();
    break;
  case 'b':
    activityList.showList();
    break;
  case 'c':
    // activityList.searchByLocation();
    break;
  case 'd':
    // activityList.searchByType();
    break;
  case 'e':
    activityList.showList();
    // activityList.removeActivity();
    activityList.showList();
    break;
  case 'f':
    // activityList.searchByName();
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
      cin.clear();
      readString(prompt, temp);
    }
  }
}

// populate activity from the user
void addActivity(Activity &anActivity, ActivityList &activityList)
{
  // temp variables
  char tempName[MAXCHAR], tempLocation[MAXCHAR], tempLevel[MAXCHAR],
      tempType[MAXCHAR];
  int tempRating = 0;
  int tempIntType = 0;

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
  tempIntType = readInt(typePrompt);

  retrieveActivityType(tempIntType, tempType);

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