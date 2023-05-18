//
// Created by Tevz on 18/05/2023.
//
#include <iostream>
#include <SensorHub.hpp>
#include <Log.hpp>

int main()
{
    std::srand(time(0));

    SensorHub hub;

    Log(LogType::INFO) << "This is additional message. We can also put multiple << and other types, not just strings e.g. " << 5 << "\n";

    hub.addSensor(std::shared_ptr<Sensor>(new PressureSensor(1, true, PressureUnit::PSI)));
    hub.addSensor(std::shared_ptr<Sensor>(new PressureSensor(2, false, PressureUnit::PA)));
    hub.addSensor(std::shared_ptr<Sensor>(new PressureSensor(40, true, PressureUnit::PSI)));
    hub.addSensor(std::shared_ptr<Sensor>(new PressureSensorP12(30, false, PressureUnit::PA, 15.63, 11.54)));
    hub.addSensor(std::shared_ptr<Sensor>(new PressureSensorP12(10, true, PressureUnit::PA, 0.43, 12.4)));

    hub.readValues();

    std::cout << std::endl;

    hub.saveSensorsToFile("/Users/tevz/Documents/Programiranje-2/Vaja11/Naloga1102/out.txt");

    std::cout << std::endl;

    SensorHub hub2;

    hub2.loadSensorsFromFile("/Users/tevz/Documents/Programiranje-2/Vaja11/Naloga1102/out2.txt");

    hub2.readValues();
}