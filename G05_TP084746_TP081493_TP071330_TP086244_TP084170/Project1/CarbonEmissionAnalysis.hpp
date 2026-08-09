#ifndef CARBON_EMISSION_ANALYSIS_HPP
#define CARBON_EMISSION_ANALYSIS_HPP

#include "PeopleSingleLinkedList.hpp"
#include "AgeGroupCategorization.hpp"
#include <string>
using namespace std;

class CarbonEmissionAnalysis
{
public:
    PeopleSingleLinkedList people;

    PeopleSingleLinkedList metro;

    PeopleSingleLinkedList uni;

    PeopleSingleLinkedList rural;

    void populateDatasets(int mode);

    void calculateTotalEmissions();

    double calculateEmissionsByDataset(PeopleSingleLinkedList& people);

    void displayTable(PeopleSingleLinkedList* dataset, string title);

    void displayEmissionsByTransport(AgeGroupNode* group);

    void displayEmissionsByDataset(PeopleSingleLinkedList* dataset, string title);

    void compareDatasetAndAgeGroup(PeopleSingleLinkedList* dataset, AgeGroupNode* group);

    static void displayMainMenu();
};

#endif