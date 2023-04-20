#include "activity.h"
#include "activityList.h"

// function prototypes
int readInt(string prompt, int temp);
void readString(string prompt, char temp[]);
void displayMenu();
char readOption();
void executeCommand(char option, ActivityList &);
void writeData(ofstream &outFile);
void welcomeMessage();
void goodbyeMessage();
void addActivity(Activity &);
void retrieveActivityType(int tempNumber, char activityListType[]);
bool isLessThan(char activityName1[], char activityName2[]);
