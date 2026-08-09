#include "Sorting.hpp"
#include "PeopleArray.hpp"
#include <malloc.h>


// sort by age
void Sorting::sortArrayByAge(PeopleArray& arr) {

    for (int i = 0; i < arr.getSize() - 1; i++) {
        for (int j = 0; j < arr.getSize() - i - 1; j++) {

            if (arr.getResident(j).age > arr.getResident(j + 1).age) {

                Resident temp = arr.getResident(j);
                arr.getResident(j) = arr.getResident(j + 1);
                arr.getResident(j + 1) = temp;
            }
        }
    }
}

// sort by distanse
void Sorting::sortArrayByDistance(PeopleArray& arr)
{
    for (int i = 0; i < arr.getSize() - 1; i++)
    {
        for (int j = 0; j < arr.getSize() - i - 1; j++)
        {
            if (arr.getResident(j).distance > arr.getResident(j + 1).distance)
            {
                Resident temp = arr.getResident(j);
                arr.getResident(j) = arr.getResident(j + 1);
                arr.getResident(j + 1) = temp;
            }
        }
    }
}
//sort by carbon
void Sorting::sortArrayByCarbon(PeopleArray& arr)
{
    for (int i = 0; i < arr.getSize() - 1; i++)
    {
        for (int j = 0; j < arr.getSize() - i - 1; j++)
        {
            if (arr.getResident(j).emission > arr.getResident(j + 1).emission)
            {
                Resident temp = arr.getResident(j);
                arr.getResident(j) = arr.getResident(j + 1);
                arr.getResident(j + 1) = temp;
            }
        }
    }
}

void BubbleList(PeopleSingleLinkedList& list, int type)
{
    if (list.getHead() == NULL) return;

    bool swapped;
    PersonNode* current;
    PersonNode* last = NULL;

    do
    {
        swapped = false;
        current = list.getHead();
        while (current->next != last)
        {
            bool needSwap = false;

            if (type == 1)
            {
                if (current->age > current->next->age)
                    needSwap = true;
            }
            else if (type == 2)
            {
                if (current->dailyDistance > current->next->dailyDistance)
                    needSwap = true;
            }
            else if (type == 3)
            {
                if (current->carbonEmissionFactor > current->next->carbonEmissionFactor)
                    needSwap = true;
            }

            if (needSwap)
            {
                // swap all fields
                string tempID = current->residentID;
                current->residentID = current->next->residentID;
                current->next->residentID = tempID;

                string tempMode = current->modeOfTransport;
                current->modeOfTransport = current->next->modeOfTransport;
                current->next->modeOfTransport = tempMode;

                int tempAge = current->age;
                current->age = current->next->age;
                current->next->age = tempAge;

                double tempDist = current->dailyDistance;
                current->dailyDistance = current->next->dailyDistance;
                current->next->dailyDistance = tempDist;

                double tempCarbon = current->carbonEmissionFactor;
                current->carbonEmissionFactor = current->next->carbonEmissionFactor;
                current->next->carbonEmissionFactor = tempCarbon;

                int tempDays = current->avgUseDaysPerMonth;
                current->avgUseDaysPerMonth = current->next->avgUseDaysPerMonth;
                current->next->avgUseDaysPerMonth = tempDays;

                swapped = true;
            }

            current = current->next;
        }

        last = current;

    } while (swapped);
}

void Sorting::sortListByAge(PeopleSingleLinkedList& list)
{
    BubbleList(list, 1);
}

void Sorting::sortListByDistance(PeopleSingleLinkedList& list)
{
    BubbleList(list, 2);
}

void Sorting::sortListByCarbon(PeopleSingleLinkedList& list)
{
    BubbleList(list, 3);
}



void Sorting::comparePerformance(PeopleArray& arr, PeopleSingleLinkedList& list)
{
    clock_t start, end;

    double arrayAgeTime;
    double listAgeTime;

    double arrayDistanceTime;
    double listDistanceTime;

    double arrayCarbonTime;
    double listCarbonTime;


    // age
    start = clock();
    sortArrayByAge(arr);
    end = clock();
    arrayAgeTime = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    sortListByAge(list);
    end = clock();
    listAgeTime = double(end - start) / CLOCKS_PER_SEC;

    // distance
    start = clock();
    sortArrayByDistance(arr);
    end = clock();
    arrayDistanceTime = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    sortListByDistance(list);
    end = clock();
    listDistanceTime = double(end - start) / CLOCKS_PER_SEC;

    // carbon
    start = clock();
    sortArrayByCarbon(arr);
    end = clock();
    arrayCarbonTime = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    sortListByCarbon(list);
    end = clock();
    listCarbonTime = double(end - start) / CLOCKS_PER_SEC;


    cout << "====================================================" << endl;
    cout << "               Performance comparison               " << endl;
    cout << "====================================================" << endl;

    cout << "Metric              Arrays          Linked Lists" << endl;
    cout << "----------------------------------------------------" << endl;

    cout << "Age               " << arrayAgeTime << "            " << listAgeTime << endl;

    cout << "Distance          " << arrayDistanceTime << "            " << listDistanceTime << endl;

    cout << "Carbon            " << arrayCarbonTime << "            " << listCarbonTime << endl;

    cout << "=====================================================" << endl;


    cout << "Time Complexity:" << endl;
    cout << "Bubble Sort on Array       : O(n^2)" << endl;
    cout << "Bubble Sort on Linked List : O(n^2)" << endl;
    cout << endl;



    int arrayMemory = sizeof(arr);
    int listMemory = sizeof(list) + list.getSize() * sizeof(PersonNode);


    cout << "Memory Usage Estimate:" << endl;
    cout << "Array       : " << arrayMemory << " bytes" << endl;
    cout << "Linked List : " << listMemory << " bytes" << endl;
    cout << endl;

}
void Sorting::displayArrayTable(PeopleArray& arr)
{
    cout << "\n=============== ARRAY DATA ===============\n";

    cout << "ID\tAge\tDistance\tCarbon\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr.getResident(i).id << "\t" << arr.getResident(i).age << "\t" << arr.getResident(i).distance << "\t\t" << arr.getResident(i).emission << endl;
    }
}

void Sorting::displayListTable(PeopleSingleLinkedList& list)
{
    PersonNode* current = list.getHead();

    cout << "\n============ LINKED LIST DATA ============\n";

    cout << "ID\tAge\tDistance\tCarbon\n";
    cout << "-----------------------------------------\n";

    while (current != NULL)
    {
        cout << current->residentID << "\t" << current->age << "\t" << current->dailyDistance << "\t\t" << current->carbonEmissionFactor << endl;

        current = current->next;
    }
}


