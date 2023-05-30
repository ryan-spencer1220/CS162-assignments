#pragma once
#include "activity.h"

class ActivityList
{
private:
  struct Node
  {
    Activity data;
    Node *prev;
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
  void showLast();
  void reverseList();
  void removeActivity();
  void writeData(char[]);
};