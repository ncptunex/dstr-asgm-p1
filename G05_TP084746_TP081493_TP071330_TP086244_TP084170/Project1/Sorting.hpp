#ifndef SORTING_HPP
#define SORTING_HPP

#include <iostream>
#include <ctime>
#include "PeopleArray.hpp"
#include "PeopleSingleLinkedList.hpp"

using namespace std;

class Sorting
{
public:
    static void sortArrayByAge(PeopleArray& arr);
    static void sortArrayByDistance(PeopleArray& arr);
    static void sortArrayByCarbon(PeopleArray& arr);

    static void sortListByAge(PeopleSingleLinkedList& list);
    static void sortListByDistance(PeopleSingleLinkedList& list);
    static void sortListByCarbon(PeopleSingleLinkedList& list);

    static void comparePerformance(PeopleArray& arr, PeopleSingleLinkedList& list);
    static void displayArrayTable(PeopleArray& arr);
    static void displayListTable(PeopleSingleLinkedList& list);
};

#endif