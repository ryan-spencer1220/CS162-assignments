#include "activity.h"

// function prototypes
int readInt(string prompt, int temp);
void readString(string prompt, char temp[]);
bool isLessThan(char activityName1[], char activityName2[]);
void displayMenu();
char readOption();
void executeCommand(char option, Activity activityList[], int &size, ifstream &inFile, ofstream &outFS);
void writeData(Activity activityList[], int &size, ofstream &outFile);