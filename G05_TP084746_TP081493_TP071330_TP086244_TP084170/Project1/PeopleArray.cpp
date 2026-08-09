#include "PeopleArray.hpp"
#include "SearchAlgorithm.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>  //jl
#include <iostream> //jl
using namespace std;

PeopleArray::PeopleArray() {
    size = 0;
}

void PeopleArray::loadFromFile(string filename) {
    ifstream file(filename);
    string line;

    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string temp;

        getline(ss, residents[size].id, ',');

        getline(ss, temp, ',');
        residents[size].age = stoi(temp);

        getline(ss, residents[size].transport, ',');

        getline(ss, temp, ',');
        residents[size].distance = stod(temp);

        getline(ss, temp, ',');
        residents[size].emission = stod(temp);

        getline(ss, temp, ',');
        residents[size].avgDays = stoi(temp);

        size++;
    }

    file.close();
}

void PeopleArray::displayData() {
    cout << "\n================ ARRAY DATA ================\n";

    cout << left
        << setw(8) << "ID"
        << setw(8) << "Age"
        << setw(15) << "Transport"
        << setw(12) << "Distance"
        << setw(12) << "Emission"
        << setw(8) << "Days" << endl;

    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << left
            << setw(8) << residents[i].id
            << setw(8) << residents[i].age
            << setw(15) << residents[i].transport
            << setw(12) << residents[i].distance
            << setw(12) << residents[i].emission
            << setw(8) << residents[i].avgDays << endl;
    }
}

//TP086244 Chan Jie Lin
//task 7a
void PeopleArray::linearSearch(int minAge, int maxAge, string transport, double minDistance) {
    printHeader();

    int matches = 0;
    for (int i = 0; i < size; i++) {
        if (isAgeGroup(residents[i].age, minAge, maxAge) &&
            isTransportMatch(residents[i].transport, transport) &&
            isDistanceThreshould(residents[i].distance, minDistance)) {

            printRow(residents[i].id, residents[i].age, residents[i].transport, residents[i].distance);
            matches++;

        }
    }
    cout << "Matches found: " << matches << endl;
}

//task 7b binray search sorting age
void PeopleArray::sortByAge() {
    cout << "Sorting by age with age: " << endl;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (residents[j].age > residents[j + 1].age) {
                Resident temp = residents[j];
                residents[j] = residents[j + 1];
                residents[j + 1] = temp;
            }
        }
    }
    cout << "Done!" << endl;
}

//task 7b sorted 
void PeopleArray::binarySearchAge(int minAge, int maxAge, string transport, double minDistance) {
    printHeader();

    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (residents[mid].age < minAge)
            left = mid + 1;
        else if (residents[mid].age > maxAge)
            right = mid - 1;
        else {
            int i = mid;
            // print kleft side of range
            while (i >= 0 && isAgeGroup(residents[i].age, minAge, maxAge)) {
                if (isTransportMatch(residents[i].transport, transport) &&
                    isDistanceThreshould(residents[i].distance, minDistance)) {
                    printRow(residents[i].id, residents[i].age,
                        residents[i].transport, residents[i].distance);
                }
                i--;
            }
            // print right side of rangeee
            i = mid + 1;
            while (i < size && isAgeGroup(residents[i].age, minAge, maxAge)) {
                if (isTransportMatch(residents[i].transport, transport) &&
                    isDistanceThreshould(residents[i].distance, minDistance)) {
                    printRow(residents[i].id, residents[i].age,
                        residents[i].transport, residents[i].distance);
                }
                i++;
            }
            break;
        }
    }
}

void PeopleArray::linearSearchNoPrint(int minAge, int maxAge, string transport, double minDistance)
{
    for (int i = 0; i < size; i++) {
        if (residents[i].age >= minAge && residents[i].age <= maxAge &&
            isTransportMatch(residents[i].transport, transport) &&
            residents[i].distance > minDistance) {
            //x priting
        }
    }
}


//task 7c
int PeopleArray::getSize() {
    return size;
}

Resident& PeopleArray::getResident(int index)
{
    return residents[index];
}