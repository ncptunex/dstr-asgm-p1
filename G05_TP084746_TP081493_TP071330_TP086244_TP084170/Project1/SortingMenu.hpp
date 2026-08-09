#ifndef SORTING_MENU_HPP
#define SORTING_MENU_HPP

#include <iostream>
#include <ctime>
#include "PeopleArray.hpp"
#include "PeopleSingleLinkedList.hpp"

class SortingMenu
{
public:
    static void displayMenu(PeopleArray& metroArr, PeopleArray& uniArr, PeopleArray& ruralArr, PeopleSingleLinkedList* metroList, PeopleSingleLinkedList* uniList, PeopleSingleLinkedList* ruralList);

    static void selection(PeopleArray& metroArr, PeopleArray& uniArr, PeopleArray& ruralArr, PeopleSingleLinkedList* metroList, PeopleSingleLinkedList* uniList, PeopleSingleLinkedList* ruralList);
};

#endif