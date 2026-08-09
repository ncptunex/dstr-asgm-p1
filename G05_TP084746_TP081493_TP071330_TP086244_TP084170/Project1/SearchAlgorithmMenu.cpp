#include "PeopleSingleLinkedList.hpp"
#include "PeopleArray.hpp"
#include <iostream>
#include "SearchAlgorithm.hpp"
#include "SearchAlgorithmMenu.hpp"
#include <chrono>

using namespace std;

//task 7a
void SearchAlgorithmMenu::searchLinkedList(PeopleSingleLinkedList* list,
    int minAge, int maxAge,
    string transport, double minDistance)
{
    printHeader();

    PersonNode* current = list->getHead();

    while (current != nullptr)
    {
        if (current->age >= minAge && current->age <= maxAge &&
            current->modeOfTransport == transport &&
            current->dailyDistance > minDistance)
        {
            printRow(current->residentID,
                current->age,
                current->modeOfTransport,
                current->dailyDistance);
        }
        current = current->next;
    }
}

void SearchAlgorithmMenu::compareTimeComplexityAndMemory(PeopleArray& metroArr, PeopleArray& uniArr, PeopleArray& ruralArr, PeopleSingleLinkedList* metroList, PeopleSingleLinkedList* uniList, PeopleSingleLinkedList* ruralList) {
    //TP086244 Chan Jie Lin task 7
    cout << " " << endl;
    cout << "\n" << string(100, '=') << endl;
    cout << "Task 7 Searching Algorithm" << endl;
    cout << string(100, '=') << endl << endl;

    //task 7a
    cout << "Task 7a: Search for residents matching specific criteria" << endl;
    cout << " " << endl;

    //task 7a array lnear search
    cout << "Test Case: Age = 26 to 45, Transport = Car, Distance more than 15" << endl;
    cout << " " << endl;

    //timer start
    cout << "[Array - Linear Search]" << endl;
    cout << "\nDataset 1\n";
    auto startArray = chrono::high_resolution_clock::now();
    metroArr.linearSearch(26, 45, "Car", 15.0);
    auto endArray = chrono::high_resolution_clock::now();
    //calculate time in ms w decimal point
    double arrayTime = chrono::duration<double, std::milli>(endArray - startArray).count();

    cout << "\nDataset 2\n";
    auto startArrayUni = chrono::high_resolution_clock::now();
    uniArr.linearSearch(26, 45, "Car", 15.0);
    auto endArrayUni = chrono::high_resolution_clock::now();
    double timeUniArr = chrono::duration<double, std::milli>(endArrayUni - startArrayUni).count();

    cout << "\nDataset 3\n";
    auto startArrayRural = chrono::high_resolution_clock::now();
    ruralArr.linearSearch(26, 45, "Car", 15.0);
    auto endArrayRural = chrono::high_resolution_clock::now();
    double timeRuralArr = chrono::duration<double, std::milli>(endArrayRural - startArrayRural).count();

    //cout << "[Array - Linear Search]" << endl;
    //clock_t t1 = startTimer();
    //metroArr.linearSearch(26, 45, "Car", 15.0); // dataset too small & excution too fast so fail

    //for (int i = 0; i < 100000; i++) {
    //    metroArr.linearSearchNoPrint(26, 45, "Car", 15.0);
    //}
    //double arrayTime = endTimer(t1);

    //task 7a linked list linear search
    cout << " " << endl;
    cout << "[Linked List - Linear Search]" << endl;
    cout << "\nDataset 1\n";
    auto startList = chrono::high_resolution_clock::now();
    metroList->linearSearch(26, 45, "Car", 15.0);
    auto endList = chrono::high_resolution_clock::now();
    //calculate time in ms w decimal point
    double listTime = chrono::duration<double, std::milli>(endList - startList).count();

    cout << "\nDataset 2\n";
    auto startListUni = chrono::high_resolution_clock::now();
    uniList->linearSearch(26, 45, "Car", 15.0);
    auto endListUni = chrono::high_resolution_clock::now();
    double timeUniList = chrono::duration<double, std::milli>(endListUni - startListUni).count();

    cout << "\nDataset 3\n";
    auto startListRural = chrono::high_resolution_clock::now();
    ruralList->linearSearch(26, 45, "Car", 15.0);
    auto endListRural = chrono::high_resolution_clock::now();
    double timeRuralList = chrono::duration<double, std::milli>(endListRural - startListRural).count();


    //cout << " " << endl;
    //cout << "[Linked List - Linear Search]" << endl;
    //clock_t t2 = startTimer();
    //metroList->linearSearchNoPrint(26, 45, "Car", 15.0);

    //for (int i = 0; i < 100000; i++) {
    //    metroList->linearSearchNoPrint(26, 45, "Car", 15.0);
    //}
    //double listTime = endTimer(t2);

    //task 7b
    cout << "\n" << string(100, '=') << endl;
    cout << "Task 7b: Implement different search algorithms on unsorted / sorted data" << endl;
    cout << "\n" << string(100, '=') << endl;
    metroArr.sortByAge();
    cout << "Array sorted by age. Binary searching 26-45.";
    cout << " " << endl;
    cout << " " << endl;
    cout << " Dataset 1" << endl;
    metroArr.binarySearchAge(26, 45, "Car", 15.0);
    cout << " " << endl;
    cout << " " << endl;
    cout << " Dataset 2" << endl;
    uniArr.binarySearchAge(26, 45, "Car", 15.0);
    cout << " " << endl;
    cout << " " << endl;
    cout << " Dataset 3" << endl;
    ruralArr.binarySearchAge(26, 45, "Car", 15.0);

    cout << " " << endl;
    cout << "Linked list binary inefficient (there is no random O(1) access)." << endl;
    cout << " " << endl;
    cout << "Hence, binary search is not suitable for linked list because it do not support random access." << endl;
    cout << " " << endl;

    //task 7c
    cout << "\n" << string(100, '=') << endl;
    cout << "Task 7c: Compare time complexity and memory usage\n";
    cout << string(100, '=') << endl;

    cout << "\nDataset 1\n";
    printPerformanceTable(arrayTime, listTime, metroArr.getSize());

    cout << "- Time: Array " << fixed << setprecision(3) << arrayTime
        << "ms vs List " << listTime << "ms" << endl;
    cout << "- Both O(n) linear, Array cache advantage" << endl;
    cout << "- Linked list has extra pointer overhead\n";

    cout << "\nDataset 2\n";
    printPerformanceTable(timeUniArr, timeUniList, uniArr.getSize());

    cout << "- Time: Array " << timeUniArr
        << "ms vs List " << timeUniList << "ms" << endl;
    cout << "- Both O(n) linear\n";

    cout << "\nDataset 3\n";
    printPerformanceTable(timeRuralArr, timeRuralList, ruralArr.getSize());

    cout << "- Time: Array " << timeRuralArr << "ms vs List " << timeRuralList << "ms" << endl;
    cout << "- Both O(n) linear\n";
    cout << " " << endl;

}