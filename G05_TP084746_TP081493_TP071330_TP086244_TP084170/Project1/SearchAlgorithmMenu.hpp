#ifndef SEARCH_ALGORITHM_MENU_HPP
#define SEARCH_ALGORITHM_MENU_HPP

#include <iostream>
#include <ctime>
#include "PeopleArray.hpp"
#include "PeopleSingleLinkedList.hpp"

class SearchAlgorithmMenu
{
public:
    static void searchLinkedList(PeopleSingleLinkedList* list, int minAge, int maxAge, string transport, double minDistance);

    static void compareTimeComplexityAndMemory(PeopleArray& metroArr, PeopleArray& uniArr, PeopleArray& ruralArr, PeopleSingleLinkedList* metroList, PeopleSingleLinkedList* uniList, PeopleSingleLinkedList* ruralList);
};

#endif