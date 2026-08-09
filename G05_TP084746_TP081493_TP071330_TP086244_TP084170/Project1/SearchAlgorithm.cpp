//TP086244 Chan Jie Lin

#include "SearchAlgorithm.hpp"
#include "PeopleArray.hpp"
#include "PeopleSingleLinkedList.hpp"
#include <iostream>
#include<iomanip>
using namespace std;

// Recategorize residents into the following age groups:
// o 6–17: Children & Teenagers
// o 18–25 : University Students / Young Adults
// o 26–45 : Working Adults(Early Career)
// o 46–60 : Working Adults(Late Career)
// o 61–100 : Senior Citizens / Retirees
bool isAgeGroup(int age, int minAge, int maxAge) {
	return age >= minAge && age <= maxAge;
}

bool isTransportMode(string dataSetTransport, string searchTransport) {
	return dataSetTransport == searchTransport;
}

bool isDistanceThreshould(double dataSetDistance, double threshold) {
	return dataSetDistance > threshold;
}

bool isTransportMatch(string data, string search) {
	if (search == "Car") {
		return (data == "Car" || data == "Carpool");
	}
	return data == search;
}

//task 7a
void printHeader() {
	cout << "\n" << string(100, '=') << endl;
	cout << string(100, '=') << endl;
	cout << left << setw(15) << "ID"
		<< setw(15) << "Age"
		<< setw(15) << "Transport"
		<< setw(15) << "Distance (km)" << endl;
	cout << string(100, '=') << endl;
	cout << " " << endl;
}

void printRow(string id, int age, string transport, double distance) {
	cout << left << setw(15) << id
		<< setw(15) << age
		<< setw(15) << transport
		<< setw(15) << distance << endl;
}

//task 7c 
void printPerformanceTable(double arrayTime, double listTime, int size) {
	cout << "\n" << string(100, '=') << endl;
	cout << "Task 7c: Compare time complexity and memory usage for arrays and singly linked lists" << endl;
	cout << string(100, '=') << endl;

	cout << left << setw(20) << "Array Time" << fixed << setprecision(3) << arrayTime << "ms" << endl;
	cout << setw(20) << "Linked List Time" << fixed << setprecision(3) << listTime << "ms" << endl;

	if (arrayTime == 0)
		arrayTime = 0.001;
	if (listTime == 0)
		listTime = 0.001; //prevent divide by 0

	double speedup = (arrayTime > 0) ? (listTime / arrayTime) : 0;

	cout << setw(20) << "Array Speed Up" << fixed << setprecision(3) << (listTime / arrayTime) << "x" << endl;

	if (arrayTime < listTime) {
		cout << " " << endl;
		cout << "Array is faster." << endl;
	}
	else if (listTime < arrayTime) {
		cout << " " << endl;
		cout << "Both structures show similar performances, the linked list is faster here due to runtime variations." << endl;
	}
	else {
		cout << " " << endl;
		cout << "Both have similar performance (time too small to measure)." << endl;
	}

	//new memory usage mathematical proof (extra)

	//return exact number of records based on passed "size" parameter
	int dataSize = size;
	//array memory: size of the struct * 200 (bc array capacity is fixed at 200 in hpp file)
	size_t arrayMemory = sizeof(Resident) * 200;
	//linked list memory: size of the node struct*the actual num of loaded records
	size_t listMemory = sizeof(PersonNode) * dataSize;

	cout << " " << endl;
	cout << "THE MEMORY USAGE WITH MATHEMATICAL PROOF:" << endl;
	cout << "- Size of one array element (for resident): " << sizeof(Resident) << " bytes" << endl;
	cout << "- Size of one linked list element (for PersonNode): " << sizeof(PersonNode) << " bytes" << endl;
	cout << "- Total array memory (fixed 200 size): " << arrayMemory << " bytes" << endl;
	cout << "- Total linked list memory (" << dataSize << " elements): " << listMemory << " bytes" << endl;

	cout << " " << endl;
	cout << "THE MEMORY ANALYSIS SUMMARY:" << endl;
	cout << "- The array requires contiguous memory and allocates space for 200 items regardless of how many are loaded, causing internal fragmentation." << endl;
	cout << "- The linked list dynamically allocates exact memory, but each node is larger (" << sizeof(PersonNode) << " bytes) because it requires extra memory for the 'next' pointer." << endl;

	//analysis 
	cout << " " << endl;
	cout << "MY ANALYSIS:" << endl;
	cout << "- Linear search has O(n) time complexity in both array and linked list." << endl;
	cout << "- Arrays are usually faster in practice due to better cache locality." << endl;
	cout << " " << endl;

	//memory usage
	cout << "THE MEMORY USAGE:" << endl;
	cout << "- Both array and linked list use O(n) memory." << endl;
	cout << "- Linked list needs more extra memory because each node stores extra pointer." << endl;
	cout << " " << endl;
}

clock_t startTimer() {
	return clock();
}

double endTimer(clock_t start) {
	return (clock() - start) / CLOCKS_PER_SEC * 1000;
}