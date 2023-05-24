//
// Created by Tevz on 18/05/2023.
//
#include <iostream>
#include <SensorHub.hpp>
#include <DuplicateSensorException.hpp>

int main() {
    std::srand(time(0));

    SensorHub hub;

    hub.addSensor(std::shared_ptr<Sensor>(new PressureSensor(1, true, PressureUnit::PSI)));
    hub.addSensor(std::shared_ptr<Sensor>(new PressureSensor(2, false, PressureUnit::PA)));
    hub.addSensor(std::shared_ptr<Sensor>(new PressureSensor(40, true, PressureUnit::PSI)));
    hub.addSensor(std::shared_ptr<Sensor>(new PressureSensorP12(30, false, PressureUnit::PA, 15.63, 11.54)));
    hub.addSensor(std::shared_ptr<Sensor>(new PressureSensorP12(10, true, PressureUnit::PA, 0.43, 12.4)));
    try
    {
        hub.addSensor(std::shared_ptr<Sensor>(new PressureSensorP12(10, true, PressureUnit::PA, 0.43, 200.4)));
    }
    catch(InvalidLocationException& e)
    {
        std::cout << "Invalid location provided: " << e.what() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Some other error happened: " << e.what() << std::endl;
    }

    hub.readValues();

    std::cout << std::endl;

    hub.saveSensorsToFile("/Users/tevz/Documents/Programiranje-2/Vaja11/Naloga1101/out.txt");

    std::cout << std::endl;

    SensorHub hub2;

    hub2.loadSensorsFromFile("/Users/tevz/Documents/Programiranje-2/Vaja11/Naloga1101/out.txt");

    hub2.readValues();

    std::cout << "Total amount of invalid locatin exceptions thrown: " << InvalidLocationException::get_count();
}