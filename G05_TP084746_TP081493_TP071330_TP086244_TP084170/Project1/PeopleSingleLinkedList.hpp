#ifndef PEOPLE_SINGLE_LINKED_LIST_HPP
#define PEOPLE_SINGLE_LINKED_LIST_HPP

#include <string>

using namespace std;

struct PersonNode
{
    string residentID;
    string modeOfTransport;

    int age;
    int dailyDistance;

    double carbonEmissionFactor;
    double avgUseDaysPerMonth;

    PersonNode* next;
};

class PeopleSingleLinkedList
{
protected:
    PersonNode* head;

private:
    int size;

public:
    PeopleSingleLinkedList();

    PersonNode* CreateNewNode(string residentID, string modeOfTransport, int age, double dailyDistance, double carbonEmissionFactor, int avgUseDaysPerMonth);

    void InsertToFront(string residentID, string modeOfTransport, int age, double dailyDistance, double carbonEmissionFactor, int avgUseDaysPerMonth);

    // Her Cheng En TP084746
    void InsertToEnd(string residentID, string modeOfTransport, int age, double dailyDistance, double carbonEmissionFactor, int avgUseDaysPerMonth);

    void DeleteFromFront();

    void DisplayList();

    void EmptySingleLinkedList();

    virtual ~PeopleSingleLinkedList();

    void linearSearch(int minAge, int maxAge, string transport, double minDistance); //jl

    void linearSearchNoPrint(int minAge, int maxAge, string transport, double minDistance); // jl

    PersonNode* getHead();

    int getSize();
};

class MetroPeopleSingleLL : public PeopleSingleLinkedList
{
public:
    MetroPeopleSingleLL();
};

class UniPeopleSingleLL : public PeopleSingleLinkedList
{
public:
    UniPeopleSingleLL();
};

class RuralPeopleSingleLL : public PeopleSingleLinkedList
{
public:
    RuralPeopleSingleLL();
};

// Function declaration
void PopulateSingleLLFromFile(PeopleSingleLinkedList* list, string fileName);

#endif
#pragma once