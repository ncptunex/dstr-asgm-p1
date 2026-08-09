#include "PeopleSingleLinkedList.hpp"
#include "SearchAlgorithm.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Constructor
PeopleSingleLinkedList::PeopleSingleLinkedList()
{
    size = 0;
    head = nullptr;
}

// Destructor
PeopleSingleLinkedList::~PeopleSingleLinkedList()
{
    EmptySingleLinkedList();
}

// Create Node
PersonNode* PeopleSingleLinkedList::CreateNewNode(string residentID, string modeOfTransport, int age, double dailyDistance, double carbonEmissionFactor, int avgUseDaysPerMonth)
{
    PersonNode* newNode = new PersonNode();

    newNode->residentID = residentID;
    newNode->modeOfTransport = modeOfTransport;
    newNode->age = age;
    newNode->dailyDistance = dailyDistance;
    newNode->carbonEmissionFactor = carbonEmissionFactor;
    newNode->avgUseDaysPerMonth = avgUseDaysPerMonth;
    newNode->next = nullptr;

    return newNode;
}

// Insert
void PeopleSingleLinkedList::InsertToFront(string residentID, string modeOfTransport, int age, double dailyDistance, double carbonEmissionFactor, int avgUseDaysPerMonth)
{
    PersonNode* newNode = CreateNewNode(residentID, modeOfTransport, age, dailyDistance, carbonEmissionFactor, avgUseDaysPerMonth);

    newNode->next = head;
    head = newNode;
    size++;
}

// Her Cheng En TP084746
void PeopleSingleLinkedList::InsertToEnd(string residentID, string modeOfTransport, int age, double dailyDistance, double carbonEmissionFactor, int avgUseDaysPerMonth)
{
    PersonNode* newnode = CreateNewNode(residentID, modeOfTransport, age, dailyDistance, carbonEmissionFactor, avgUseDaysPerMonth);

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        PersonNode* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    size++;
}

// Delete
void PeopleSingleLinkedList::DeleteFromFront()
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    PersonNode* temp = head;
    head = head->next;
    delete temp;
    size--;
}

// Display
void PeopleSingleLinkedList::DisplayList()
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    PersonNode* current = head;

    while (current != nullptr)
    {
        cout << "Resident ID: " << current->residentID
            << ", Mode: " << current->modeOfTransport
            << ", Age: " << current->age
            << ", Distance: " << current->dailyDistance
            << ", Carbon: " << current->carbonEmissionFactor
            << ", Days: " << current->avgUseDaysPerMonth << endl;

        current = current->next;
    }
}

// Empty List
void PeopleSingleLinkedList::EmptySingleLinkedList()
{
    while (head != nullptr)
    {
        PersonNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Derived Constructors
MetroPeopleSingleLL::MetroPeopleSingleLL() {}
UniPeopleSingleLL::UniPeopleSingleLL() {}
RuralPeopleSingleLL::RuralPeopleSingleLL() {}

// CSV Loader
void PopulateSingleLLFromFile(PeopleSingleLinkedList* list, string fileName)
{
    ifstream file(fileName);

    if (!file.is_open())
    {
        cout << "Error opening file: " << fileName << endl;
        return;
    }

    string line;
    bool firstLoop = true;

    while (getline(file, line))
    {
        if (firstLoop)
        {
            firstLoop = false;
            continue;
        }

        stringstream ss(line);
        string cell;

        string residentID, modeOfTransport;
        int age = 0;
        double dailyDistance = 0;
        double carbonEmissionFactor = 0;
        int avgUseDaysPerMonth = 0;

        int count = 0;

        while (getline(ss, cell, ','))
        {
            switch (count)
            {
            case 0: residentID = cell; break;
            case 1: if (!cell.empty()) age = stoi(cell); break;
            case 2: modeOfTransport = cell; break;
            case 3: if (!cell.empty()) dailyDistance = stod(cell); break;
            case 4: if (!cell.empty()) carbonEmissionFactor = stod(cell); break;
            case 5: if (!cell.empty()) avgUseDaysPerMonth = stoi(cell); break;
            }
            count++;
        }

        list->InsertToEnd(residentID, modeOfTransport, age, dailyDistance, carbonEmissionFactor, avgUseDaysPerMonth);
    }

    file.close();
}

PersonNode* PeopleSingleLinkedList::getHead() {
    return head;
}

int PeopleSingleLinkedList::getSize() {
    int count = 0;
    PersonNode* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

//task 7a linked list search
void PeopleSingleLinkedList::linearSearch(int minAge, int maxAge, string transport, double minDistance) {
    printHeader();

    PersonNode* current = head;
    int matches = 0;

    while (current != nullptr) {
        if (current->age >= minAge && current->age <= maxAge &&
            isTransportMatch(current->modeOfTransport, transport) &&
            current->dailyDistance > minDistance) {

            printRow(current->residentID,
                current->age,
                current->modeOfTransport,
                current->dailyDistance);

            matches++;
        }
        current = current->next;
    }
    cout << "Found Matches: " << matches << endl;
}

void PeopleSingleLinkedList::linearSearchNoPrint(int minAge, int maxAge, string transport, double minDistance)
{
    PersonNode* current = head;

    while (current != nullptr) {
        if (current->age >= minAge && current->age <= maxAge &&
            isTransportMatch(current->modeOfTransport, transport) &&
            current->dailyDistance > minDistance) {
            // X printing
        }
        current = current->next;
    }
}