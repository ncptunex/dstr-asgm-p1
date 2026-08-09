#include "AgeGroupCategorization.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

AgeGroupNode::AgeGroupNode(string t, int min, int max)
{
    title = t;
    minAge = min;
    maxAge = max;
    size = 0;

    next = nullptr;
}

AgeGroupCategorization::AgeGroupCategorization()
{
    head = nullptr;
    size = 0;

    insertToEnd("Children & Teenagers", 6, 17);
    insertToEnd("University Students / Young Adults", 18, 25);
    insertToEnd("Working Adults (Early Career)", 26, 45);
    insertToEnd("Working Adults (Late Career)", 46, 60);
    insertToEnd("Senior Citizens / Retirees", 61, 100);
}

void AgeGroupCategorization::insertToEnd(string t, int min, int max)
{
    AgeGroupNode* newnode = new AgeGroupNode(t, min, max);

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        AgeGroupNode* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    size++;
}

void AgeGroupCategorization::categorizeByAgeGroup(PeopleSingleLinkedList* people)
{
    if (head == NULL || people->getHead() == NULL) return;

    AgeGroupNode* ptr1 = head;
    AgeGroupNode* ptr2 = ptr1->next;
    AgeGroupNode* ptr3 = ptr2->next;
    AgeGroupNode* ptr4 = ptr3->next;
    AgeGroupNode* ptr5 = ptr4->next;

    PersonNode* curr = people->getHead();

    while (curr != NULL)
    {
        int age = curr->age;
        AgeGroupNode* category = nullptr;

        // Children & Teenagers
        if (age >= ptr1->minAge && age <= ptr1->maxAge) category = ptr1;
        // University Students / Young Adults
        else if (age >= ptr2->minAge && age <= ptr2->maxAge) category = ptr2;
        // Working Adults (Early Career)
        else if (age >= ptr3->minAge && age <= ptr3->maxAge) category = ptr3;
        // Working Adults (Late Career)
        else if (age >= ptr4->minAge && age <= ptr4->maxAge) category = ptr4;
        // Senior Citizens / Retirees
        else if (age >= ptr5->minAge && age <= ptr5->maxAge) category = ptr5;

        if (category != NULL)
        {
            category->people.InsertToEnd(
                curr->residentID,
                curr->modeOfTransport,
                curr->age,
                curr->dailyDistance,
                curr->carbonEmissionFactor,
                curr->avgUseDaysPerMonth
            );
            category->size++;
        }
        curr = curr->next;
    }
}

void AgeGroupCategorization::selectAgeGroup()
{
    AgeGroupNode* curr = head;
    int i = 1;

    cout << "==== SELECT AGE GROUP ====" << endl;

    while (curr != NULL)
    {
        cout << i << ". " << curr->title << " (" << curr->minAge << "-" << curr->maxAge << ")" << endl;
        curr = curr->next;
        i++;
    }

    cout << "Enter age group selection: ";
}

AgeGroupNode* AgeGroupCategorization::getAgeGroup(int i)
{
    AgeGroupNode* curr = head;
    int count = 1;

    while (curr != NULL)
    {
        if (count == i) return curr;
        curr = curr->next;
        count++;
    }
    return nullptr;
}

void AgeGroupCategorization::displayAgeGroup(AgeGroupNode* ptr)
{
    if (ptr == NULL)
    {
        cout << "Invalid selection. Please try again." << endl;
        return;
    }

    PersonNode* curr = ptr->people.getHead();

    if (curr == NULL)
    {
        cout << "No data found for this age group." << endl << endl;
        return;
    }

    cout << "Age Group: " << ptr->minAge << "-" << ptr->maxAge << " (" << ptr->title << ")" << endl;
    cout << string(123, '-') << endl;
    cout << "ResidentID | Age | Mode of Transport | Daily Distance (km) | Carbon Emission Factor (kg CO2/km) | Average Days Per Month |" << endl;
    cout << string(123, '-') << endl;

    while (curr != NULL)
    {
        cout << left << setw(13) << curr->residentID << setw(6) << curr->age << setw(20) << curr->modeOfTransport << setw(22) << curr->dailyDistance << setw(37) << curr->carbonEmissionFactor << curr->avgUseDaysPerMonth << endl;
        curr = curr->next;
    }

    calculateMostPreferredTransport(ptr);
    calculateCarbonEmissions(ptr);
}

void AgeGroupCategorization::calculateMostPreferredTransport(AgeGroupNode* ptr)
{
    int car = 0, bus = 0, bicycle = 0, walking = 0, school_bus = 0, carpool = 0;
    PersonNode* curr = ptr->people.getHead();

    while (curr != NULL)
    {
        string mode = curr->modeOfTransport;

        if (mode == "Car") car++;
        else if (mode == "Bus") bus++;
        else if (mode == "Bicycle") bicycle++;
        else if (mode == "Walking") walking++;
        else if (mode == "School Bus") school_bus++;
        else if (mode == "Carpool") carpool++;

        curr = curr->next;
    }

    string preferred;
    int value = 0;

    if (car > value) { value = car; preferred = "Car"; }

    if (bus > value) { value = bus; preferred = "Bus"; }

    if (bicycle > value) { value = bicycle; preferred = "Bicycle"; }

    if (walking > value) { value = walking; preferred = "Walking"; }

    if (school_bus > value) { value = school_bus; preferred = "School Bus"; }

    if (carpool > value) { value = carpool; preferred = "Carpool"; }

    cout << endl << "==== ANALYTICS ====" << endl;
    cout << "Most Preferred Mode of Transport: " << preferred << " (" << value << " people)" << endl;
}

void AgeGroupCategorization::calculateCarbonEmissions(AgeGroupNode* ptr)
{
    double total = 0;
    PersonNode* curr = ptr->people.getHead();

    while (curr != NULL)
    {
        total += curr->carbonEmissionFactor;
        curr = curr->next;
    }

    cout << "Total Carbon Emissions Produced: " << total << "kg CO2/km" << endl;
    cout << "Average Carbon Emissions Per Resident: " << total / ptr->size << "kg CO2/km" << endl << endl;
}

void AgeGroupCategorization::displayMainMenu()
{
    AgeGroupCategorization ageGroupSLL;
    PeopleSingleLinkedList people;

    PopulateSingleLLFromFile(&people, "Data/dataset1-cityA.csv");
    PopulateSingleLLFromFile(&people, "Data/dataset2-cityB.csv");
    PopulateSingleLLFromFile(&people, "Data/dataset3-cityC.csv");

    ageGroupSLL.categorizeByAgeGroup(&people);
    int selection = 0;

    while (true)
    {
        ageGroupSLL.selectAgeGroup();
        cin >> selection;

        AgeGroupNode* group = ageGroupSLL.getAgeGroup(selection);
        ageGroupSLL.displayAgeGroup(group);
    }
}