#pragma once
#include "activity.h"

// constants
const int CAP = 20;
const int GROWTH = 5;

class ActivityList
{
private:
  struct Node
  {
    Activity data;
    Node *next;
  };
  Node *head;
  Node *tail;
  int size;

public:
  // constructors
  ActivityList();
  ActivityList(char[]);

  // destructor
  ~ActivityList();

  // database functions
  void addActivity(Activity &);
  void searchByName();
  void searchByLocation();
  void searchByType();
  void showList();
  void removeActivity();
  void writeData(char[]);
};