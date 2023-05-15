#include <iostream>
#include <ctime>
#include <cstdlib>

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
    cout << "0 ... EXIT" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

void fillArray(unsigned int* array, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        array[i] = (rand()%201 + 800);
    }
}

void printArray(const unsigned int* array, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        cout << ((i > 0) ? ", " : "") << array[i];
    }
}

float averageDistanceDriven(const unsigned int* array, const unsigned int size)
{
    float averageAccumulator = 0;
    for(unsigned int i = 0; i < size; i++)
    {
        averageAccumulator += static_cast<float>(array[i]);
    }

    return averageAccumulator / 20.0f;
}

float averageFuelConsumption(const unsigned int* array, const unsigned int size)
{
    float average = averageDistanceDriven(array, size);

    return 100.0f / (average / 60);
}

unsigned int distanceWithHighestFuelConsumption(const unsigned  int* array, const unsigned int size)
{
    unsigned int lowest = array[0];

    for(unsigned int i = 1; i < size; i++)
    {
        if(array[i] < lowest)
            lowest = array[i];
    }

    return lowest;
}

unsigned int tripsInRange(const unsigned int* array, const unsigned int size)
{
    unsigned int counter = 0;
    for(unsigned int i = 0; i < size; i++)
    {
        if(array[i] > 850 && array[i] < 900)
            counter++;
    }

    return counter;
}

float milesDrivenPerGallon(const unsigned int* array, const unsigned int size)
{
    float averageMiles = averageDistanceDriven(array, size) * KM_TO_MILE;
    float gasUsed = 60.0f * L_TO_GAL;

    return averageMiles / gasUsed;
}


int main()
{
    srand(std::time(0));

    const unsigned int refueling = 20;
    unsigned int* kilometers = new unsigned int[refueling];

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
            case 0:
                running = false;
                break;
            default:
                cout << "Wrong selection!" << endl;
                break;
        }
        cout << endl;
    } while (running);

    delete[] kilometers;

    return 0;
}