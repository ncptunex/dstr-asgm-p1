#ifndef PEOPLE_ARRAY_HPP
#define PEOPLE_ARRAY_HPP

#pragma once //jl
#include <iostream>
#include <string>
using namespace std;

struct Resident {
    string id;
    int age;
    string transport;
    double distance;
    double emission;
    int avgDays;
};

class PeopleArray {
public:
    Resident residents[600];
    int size;
    PeopleArray();

    void loadFromFile(string filename);
    void displayData();

    //Task 7 methods (jl)
    void linearSearch(int minAge, int maxAge, string transport, double minDistance);
    void sortByAge();
    void binarySearchAge(int minAge, int maxAge, string transport, double minDistance);
    void linearSearchNoPrint(int minAge, int maxAge, string transport, double minDistance);
    int getSize();
    Resident& getResident(int index);
};

#endif