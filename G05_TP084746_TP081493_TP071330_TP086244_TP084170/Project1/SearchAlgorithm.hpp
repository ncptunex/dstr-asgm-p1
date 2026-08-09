//TP086244 Chan Jie Lin

#ifndef SEARCH_ALGORITHM_HPP
#define SEARCH_ALGORITHM_HPP

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

struct PersonNode;

//task 7a
bool isAgeGroup(int age, int minAge, int maxAge); //check age between 
bool isTransportMode(string dataSetTransport, string searchTransport); //check match onot
// dataSetTransport = from dataset & searchTransport = search the value
bool isDistanceThreshould(double dataSetDistance, double threshold);  // check if distance > threshould
bool isTransportMatch(string data, string search);

//task 7d
void printHeader();
void printRow(string id, int age, string transport, double distance);
void printPerformanceTable(double arrayTime, double listTime, int size); //compre array vs linkedlist speed

//measure search time
//https://www.geeksforgeeks.org/c/ctime-function-in-c-c/ 
clock_t startTimer();
double endTimer(clock_t start);

#endif