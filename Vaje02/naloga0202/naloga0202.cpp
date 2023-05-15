#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "FuelLog.hpp"

using namespace std;

#define KM_TO_MILE 0.621371192
#define L_TO_GAL 0.264172

void menu()
{
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "1 ... GENERATE KM TRAVELLED" << endl;
    cout << "2 ... PRINT KM TRAVELLED" << endl;
    cout << "3 ... PRINT AVERAGE DISTANCE TRAVELED IN KM" << endl;
    cout << "4 ... AVERAGE FUEL CONSUMPTION PER 100 KM" << endl;
    cout << "5 ... DISTANCE DRIVEN WITH HIGHEST FUEL CONSUMPTION" << endl;
    cout << "6 ... NUMBER OF TRIPS WITHIN 850 AND 900 KM" << endl;
    cout << "7 ... MILES DRIVEN PER GALLON" << endl;
    cout << "8 ... SUM OF REFUELING COSTS" << endl;
    cout << "0 ... EXIT" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

void fillArray(std::vector<FuelLog*>& array, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        array.push_back(new FuelLog(rand()%201 + 800, i % 30 + 1, i % 12 + 1, 2022, static_cast<float>(((rand() % 40) + 110.0f)/ 100.0f) ,static_cast<float>((rand() % 31) + 30)));
    }
}

float sumOfFuelCosts(const std::vector<FuelLog*>& array, const unsigned int size)
{
    float accumulator = 0;

    for(unsigned int i = 0; i < size; i++)
    {
        accumulator += array[i]->getTotalCost();
    }

    return accumulator;
}

void printArray(const std::vector<FuelLog*>& array, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        cout << array[i]->toString() << endl;
    }
}

float averageDistanceDriven(const std::vector<FuelLog*>& array, const unsigned int size)
{
    float averageAccumulator = 0;
    for(unsigned int i = 0; i < size; i++)
    {
        averageAccumulator += static_cast<float>(array[i]->getKilometers());
    }

    return averageAccumulator / static_cast<float>(size);
}

float averageGasUsed(const std::vector<FuelLog*>& array, const unsigned int size)
{
    float averageAccumulator = 0;
    for(unsigned int i = 0; i < size; i++)
    {
        averageAccumulator += array[i]->getQuantity();
    }

    return averageAccumulator / static_cast<float>(size);
}

float averageFuelConsumption(const std::vector<FuelLog*>& array, const unsigned int size)
{
    float averageAccumulator = 0.0f;
    for(unsigned int i = 0; i < size; i++)
    {
        averageAccumulator += array[i]->getConsumption();
    }

    return averageAccumulator / static_cast<float>(size);
}

unsigned int distanceWithHighestFuelConsumption(const std::vector<FuelLog*>& array, const unsigned int size)
{
    FuelLog* lowest = array[0];

    for(unsigned int i = 1; i < size; i++)
    {
        if(array[i]->getConsumption() < lowest->getConsumption())
            lowest = array[i];
    }

    return lowest->getKilometers();
}

unsigned int tripsInRange(const std::vector<FuelLog*>& array, const unsigned int size)
{
    unsigned int counter = 0;
    for(unsigned int i = 0; i < size; i++)
    {
        if(array[i]->getKilometers() > 850 && array[i]->getKilometers() < 900)
            counter++;
    }

    return counter;
}

float milesDrivenPerGallon(const std::vector<FuelLog*>& array, const unsigned int size)
{
    float averageMiles = averageDistanceDriven(array, size) * KM_TO_MILE;
    float gasUsed = averageGasUsed(array, size) * L_TO_GAL;

    return averageMiles / gasUsed;
}


int main()
{
    srand(std::time(0));

    const unsigned int refueling = 20;
    std::vector<FuelLog*> kilometers;

    bool running = true;
    int selection;

    do
    {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                fillArray(kilometers, refueling);
                break;
            case 2:
                printArray(kilometers, refueling);
                break;
            case 3:
                cout << "Average distance driven: " << averageDistanceDriven(kilometers, refueling) << endl;
                break;
            case 4:
                cout << "Average fuel consumption per 100km is: " << averageFuelConsumption(kilometers, refueling) << endl;
                break;
            case 5:
                cout << "Distance driven with highest fuel consumption: " << distanceWithHighestFuelConsumption(kilometers, refueling) << endl;
                break;
            case 6:
                cout << "Trips within 850km and 900km: " << tripsInRange(kilometers, refueling) << endl;
                break;
            case 7:
                cout << "Miles driven per gallon: " << milesDrivenPerGallon(kilometers, refueling) << endl;
                break;
            case 8:
                cout << "Cost of all refuelings: " << sumOfFuelCosts(kilometers, refueling) << endl;
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Wrong selection!" << endl;
                break;
        }
        cout << endl;
    } while (running);

    for(unsigned int i = 0; i < refueling; i++)
    {
        delete kilometers[i];
    }

    return 0;
}