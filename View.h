#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;


class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif

/*
-> the view class is the class that contains the menu and takes in users input and provides results accrdg to the users input
-> taken refernece from previous assignments
*/
