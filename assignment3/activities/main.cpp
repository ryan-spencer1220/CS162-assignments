#include "activity.h"
#include "tools.h"

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
    exeCmd(option, activityList);
  } while (tolower(option != 'q'));

  goodbyeMessage();
  activityList.writeData(fileName);

  return 0;
}