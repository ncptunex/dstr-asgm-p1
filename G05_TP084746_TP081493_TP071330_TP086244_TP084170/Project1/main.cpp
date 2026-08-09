#include "PeopleSingleLinkedList.hpp"
#include "PeopleArray.hpp"
#include "SortingMenu.hpp"
#include "SearchAlgorithm.hpp"
#include "SearchAlgorithmMenu.hpp"
#include "AgeGroupCategorization.hpp"
#include "CarbonEmissionAnalysis.hpp"
#include <iostream>
#include <chrono>

using namespace std;

void showMainMenu()
{
    cout << "1. Sorting Algorithm - Kulikova Yana TP71330" << endl;
    cout << "2. Searching Algorithm - Chan Jie Lin TP86244" << endl;
    cout << "3. Age Group Categorization - Her Cheng En TP084746" << endl;
    cout << "4. Carbon Emission Analysis - Her Cheng En TP084746" << endl;

    cout << "0. Exit" << endl << endl;
    cout << "Enter choice: ";
}

int main()
{
    //task 3
    PeopleSingleLinkedList* metroList = new MetroPeopleSingleLL();
    PopulateSingleLLFromFile(metroList, "Data/dataset1-cityA.csv");

    PeopleSingleLinkedList* uniList = new UniPeopleSingleLL();
    PopulateSingleLLFromFile(uniList, "Data/dataset2-cityB.csv");

    PeopleSingleLinkedList* ruralList = new RuralPeopleSingleLL();
    PopulateSingleLLFromFile(ruralList, "Data/dataset3-cityC.csv");

    // === ARRAY IMPLEMENTATION === 

    PeopleArray metroArr;
    metroArr.loadFromFile("Data/dataset1-cityA.csv");

    PeopleArray uniArr;
    uniArr.loadFromFile("Data/dataset2-cityB.csv");

    PeopleArray ruralArr;
    ruralArr.loadFromFile("Data/dataset3-cityC.csv");

    int choice;

    do
    {
        showMainMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            SortingMenu::displayMenu(metroArr, uniArr, ruralArr, metroList, uniList, ruralList);
            break;

        case 2:
            SearchAlgorithmMenu::compareTimeComplexityAndMemory(metroArr, uniArr, ruralArr, metroList, uniList, ruralList);
            break;

        case 3:
            AgeGroupCategorization::displayMainMenu();
            break;

        case 4:
            CarbonEmissionAnalysis::displayMainMenu();
            break;
        }
    } while (choice != 0);
}