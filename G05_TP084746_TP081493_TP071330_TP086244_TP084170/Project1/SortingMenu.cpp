#include "PeopleSingleLinkedList.hpp"
#include "PeopleArray.hpp"
#include "SortingMenu.hpp"
#include "Sorting.hpp"

using namespace std;

void SortingMenu::displayMenu(PeopleArray& metroArr, PeopleArray& uniArr, PeopleArray& ruralArr, PeopleSingleLinkedList* metroList, PeopleSingleLinkedList* uniList, PeopleSingleLinkedList* ruralList)
{

    cout << "1. Display Metro Dataset (City A)" << endl;
    cout << "2. Display Uni Dataset (City B)" << endl;
    cout << "3. Display Rural Dataset (City C)" << endl;
    cout << "4. Sort by Age" << endl;
    cout << "5. Sort by Distance" << endl;
    cout << "6. Sort by Carbon Emission" << endl;
    cout << "7. Compare Performance" << endl;
    cout << "8. Display Result Tables for city A" << endl;
    cout << "9. Display Result Tables for city B" << endl;
    cout << "10. Display Result Tables for city C" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter choice: ";

    selection(metroArr, uniArr, ruralArr, metroList, uniList, ruralList);
}

void SortingMenu::selection(PeopleArray& metroArr, PeopleArray& uniArr, PeopleArray& ruralArr, PeopleSingleLinkedList* metroList, PeopleSingleLinkedList* uniList, PeopleSingleLinkedList* ruralList)
{
    int choice;

    do
    {
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n===== METRO DATASET =====" << endl;
            cout << "\n--- Array ---" << endl;
            metroArr.displayData();
            cout << "\n--- Linked List ---" << endl;
            metroList->DisplayList();
            break;

        case 2:
            cout << "\n===== UNI DATASET =====" << endl;
            cout << "\n--- Array ---" << endl;
            uniArr.displayData();
            cout << "\n--- Linked List ---" << endl;
            uniList->DisplayList();
            break;

        case 3:
            cout << "\n===== RURAL DATASET =====" << endl;
            cout << "\n--- Array ---" << endl;
            ruralArr.displayData();
            cout << "\n--- Linked List ---" << endl;
            ruralList->DisplayList();
            break;

        case 4:
            Sorting::sortArrayByAge(metroArr);
            Sorting::sortListByAge(*metroList);
            Sorting::sortArrayByAge(uniArr);
            Sorting::sortListByAge(*uniList);
            Sorting::sortArrayByAge(ruralArr);
            Sorting::sortListByAge(*ruralList);

            cout << "Sorting by age is finished for all 3 tables. Choose 8, 9 or 10 to see tables." << endl;
            break;

        case 5:
            Sorting::sortArrayByDistance(metroArr);
            Sorting::sortListByDistance(*metroList);
            Sorting::sortArrayByDistance(uniArr);
            Sorting::sortListByDistance(*uniList);
            Sorting::sortArrayByDistance(ruralArr);
            Sorting::sortListByDistance(*ruralList);

            cout << "Sorting by distance is finished for all 3 tables. Choose 8, 9 or 10 to see tables." << endl;
            break;

        case 6:
            Sorting::sortArrayByCarbon(metroArr);
            Sorting::sortListByCarbon(*metroList);
            Sorting::sortArrayByCarbon(uniArr);
            Sorting::sortListByCarbon(*uniList);
            Sorting::sortArrayByCarbon(ruralArr);
            Sorting::sortListByCarbon(*ruralList);
            cout << "Sorting by Carbon is finished for all 3 tables. Choose 8, 9 or 10 to see exact tables." << endl;
            break;

        case 7:
            Sorting::comparePerformance(metroArr, *metroList);
            Sorting::comparePerformance(uniArr, *uniList);
            Sorting::comparePerformance(ruralArr, *ruralList);
            break;

        case 8:
            cout << "\n===== Result Tables =====" << endl;
            Sorting::displayArrayTable(metroArr);
            Sorting::displayListTable(*metroList);
            break;

        case 9:
            cout << "\n===== Result Tables =====" << endl;
            Sorting::displayArrayTable(uniArr);
            Sorting::displayListTable(*uniList);
            break;

        case 10:
            cout << "\n===== Result Tables =====" << endl;
            Sorting::displayArrayTable(ruralArr);
            Sorting::displayListTable(*ruralList);
            break;

        case 0:
            cout << "\nProgram terminated." << endl;
            break;

        default:
            cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    delete metroList;
    delete uniList;
    delete ruralList;
}