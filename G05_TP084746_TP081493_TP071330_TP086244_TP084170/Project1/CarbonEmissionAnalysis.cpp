#include "CarbonEmissionAnalysis.hpp"
#include "AgeGroupCategorization.hpp"
#include <iostream>
#include <iomanip>

void CarbonEmissionAnalysis::populateDatasets(int mode)
{
    people.EmptySingleLinkedList();

    switch (mode)
    {
    case 0:
        metro.EmptySingleLinkedList();
        uni.EmptySingleLinkedList();
        rural.EmptySingleLinkedList();

        PopulateSingleLLFromFile(&metro, "Data/dataset1-cityA.csv");
        PopulateSingleLLFromFile(&uni, "Data/dataset2-cityB.csv");
        PopulateSingleLLFromFile(&rural, "Data/dataset3-cityC.csv");
        break;

    case 1:
        PopulateSingleLLFromFile(&people, "Data/dataset1-cityA.csv");
        PopulateSingleLLFromFile(&people, "Data/dataset2-cityB.csv");
        PopulateSingleLLFromFile(&people, "Data/dataset3-cityC.csv");
        break;
    }
}

void CarbonEmissionAnalysis::calculateTotalEmissions()
{
    double total = 0;

    total += calculateEmissionsByDataset(metro);
    total += calculateEmissionsByDataset(uni);
    total += calculateEmissionsByDataset(rural);
}

double CarbonEmissionAnalysis::calculateEmissionsByDataset(PeopleSingleLinkedList& dataset)
{
    double emission = 0;
    PersonNode* curr = dataset.getHead();

    while (curr != NULL)
    {
        emission += curr->carbonEmissionFactor * curr->dailyDistance;
        curr = curr->next;
    }
    return emission;
}

void CarbonEmissionAnalysis::displayTable(PeopleSingleLinkedList* dataset, string title)
{
    if (dataset == NULL || dataset->getHead() == NULL) return;

    int car = 0, bus = 0, bicycle = 0, walking = 0, school_bus = 0, carpool = 0;
    double car_total = 0, bus_total = 0, bicycle_total = 0, walking_total = 0, school_bus_total = 0, carpool_total = 0;

    PersonNode* curr = dataset->getHead();
    while (curr != NULL)
    {
        string mode = curr->modeOfTransport;
        double emission = curr->carbonEmissionFactor * curr->dailyDistance;

        if (mode == "Car") { car++; car_total += emission; }
        else if (mode == "Bus") { bus++; bus_total += emission; }
        else if (mode == "Bicycle") { bicycle++; bicycle_total += emission; }
        else if (mode == "Walking") { walking++; walking_total += emission; }
        else if (mode == "School Bus") { school_bus++; school_bus_total += emission; }
        else if (mode == "Carpool") { carpool++; carpool_total += emission; }

        curr = curr->next;
    }

    cout << title << endl;
    cout << string(84, '-') << endl;
    cout << "Mode of Transport | Count | Total Carbon Emission (kg CO2) | Average Per Resident |" << endl;
    cout << string(84, '-') << endl;

    cout << left << setw(20) << "Car" << setw(8) << car << setw(33) << car_total <<
        (car > 0 ? car_total / car : 0) << endl;

    cout << left << setw(20) << "Bus" << setw(8) << bus << setw(33) << bus_total <<
        (bus > 0 ? bus_total / bus : 0) << endl;

    cout << left << setw(20) << "Bicycle" << setw(8) << bicycle << setw(33) << bicycle_total <<
        (bicycle > 0 ? bicycle_total / bicycle : 0) << endl;

    cout << left << setw(20) << "Walking" << setw(8) << walking << setw(33) << walking_total <<
        (walking > 0 ? walking_total / walking : 0) << endl;

    cout << left << setw(20) << "School Bus" << setw(8) << school_bus << setw(33) << school_bus_total <<
        (school_bus > 0 ? school_bus_total / school_bus : 0) << endl;

    cout << left << setw(20) << "Carpool" << setw(8) << carpool << setw(33) << carpool_total <<
        (carpool > 0 ? carpool_total / carpool : 0) << endl;

    int total_count = car + bus + bicycle + walking + school_bus + carpool;
    double total_emission = car_total + bus_total + bicycle_total + walking_total + school_bus_total + carpool_total;
    cout << endl << "Sample Size: " << total_count << " people" << endl;
    cout << "Total Carbon Emissions: " << total_emission << "kg CO2" << endl << endl;
}

void CarbonEmissionAnalysis::displayEmissionsByTransport(AgeGroupNode* group)
{
    if (group == NULL) return;

    string title = "Age Group: " + group->title + " (" + to_string(group->minAge) + "-" + to_string(group->maxAge) + ")";
    displayTable(&group->people, title);
}

void CarbonEmissionAnalysis::displayEmissionsByDataset(PeopleSingleLinkedList* dataset, string title)
{
    if (dataset == NULL) return;

    displayTable(dataset, title);
}

void CarbonEmissionAnalysis::compareDatasetAndAgeGroup(PeopleSingleLinkedList* dataset, AgeGroupNode* group)
{
    if (group == NULL) return;

    cout << endl << "============================================" << endl;
    cout << "      TOTAL CARBON EMISSIONS BY DATASET " << endl;
    cout << "============================================" << endl;

    cout << left << setw(45) << "Dataset 1 (Metropolitan City): " << calculateEmissionsByDataset(metro) << " kg CO2" << endl;
    cout << left << setw(45) << "Dataset 2 (University Town): " << calculateEmissionsByDataset(uni) << " kg CO2" << endl;
    cout << left << setw(45) << "Dataset 3 (Suburban/Rural Area): " << calculateEmissionsByDataset(rural) << " kg CO2" << endl;

    cout << "\n============================================" << endl;
    cout << "     TOTAL CARBON EMISSIONS BY AGE GROUP " << endl;
    cout << "============================================" << endl;

    AgeGroupNode* temp = group;
    while (temp != NULL)
    {
        double total = calculateEmissionsByDataset(temp->people);
        string label = temp->title + " (" + to_string(temp->minAge) + "-" + to_string(temp->maxAge) + "): ";
        cout << left << setw(45) << label << total << " kg CO2" << endl;

        temp = temp->next;
    }
}

void CarbonEmissionAnalysis::displayMainMenu()
{
    CarbonEmissionAnalysis analysis;
    AgeGroupCategorization ageGroups;

    analysis.populateDatasets(0);
    analysis.populateDatasets(1);

    ageGroups.categorizeByAgeGroup(&analysis.people);
    int selection = 1;

    while (selection != 0)
    {
        ageGroups.selectAgeGroup();

        cin >> selection;
        analysis.displayEmissionsByTransport(ageGroups.getAgeGroup(selection));
        analysis.compareDatasetAndAgeGroup(&analysis.metro, ageGroups.getAgeGroup(selection));
    }

    analysis.displayEmissionsByDataset(&analysis.metro, "Dataset 1 - Metrapolitan City");
    analysis.displayEmissionsByDataset(&analysis.uni, "Dataset 2 - University Town");
    analysis.displayEmissionsByDataset(&analysis.rural, "Dataset 3 - Suburban / Rural Area");
    analysis.displayEmissionsByDataset(&analysis.people, "Full Dataset");
}