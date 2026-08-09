#ifndef AGE_GROUP_CATEGORIZATION_HPP
#define AGE_GROUP_CATEGORIZATION_HPP

#include "PeopleSingleLinkedList.hpp"
#include <string>
using namespace std;

struct AgeGroupNode
{
    string title;
    int minAge, maxAge, size;

    PeopleSingleLinkedList people;
    AgeGroupNode* next;

    AgeGroupNode(string t, int min, int max);
};

class AgeGroupCategorization
{
protected:
    AgeGroupNode* head;

private:
    int size;

public:
    AgeGroupCategorization();

    void insertToEnd(string t, int min, int max);

    void selectAgeGroup();

    void categorizeByAgeGroup(PeopleSingleLinkedList* people);

    AgeGroupNode* getAgeGroup(int i);

    void displayAgeGroup(AgeGroupNode* ptr);

    void calculateMostPreferredTransport(AgeGroupNode* ptr);

    void calculateCarbonEmissions(AgeGroupNode* ptr);

    static void displayMainMenu();
};

#endif