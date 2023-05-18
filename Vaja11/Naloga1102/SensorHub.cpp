//
// Created by Tevz on 18/05/2023.
//

#include <SensorHub.hpp>

void SensorHub::addSensor(std::shared_ptr<Sensor> sensor)
{
    auto f = std::find_if(sensors.begin(), sensors.end(), [&](std::shared_ptr<Sensor> val) -> bool {
        return val->getId() == sensor->getId();
    });

    if(f != sensors.end())
        throw DuplicateSensorException(std::string{"Sensor with id: "} + std::to_string(sensor->getId()) + " already exists!");

    sensors.push_back(sensor);
}

void SensorHub::readValues() const
{
    for(const auto& el : sensors)
        if(el->isActive())
            std::cout << "Sensor value: " << el->readValue() << " sensor data: " << el->toString() << std::endl;
}

void SensorHub::saveSensorsToFile(const std::string& file)
{
    std::ofstream f(file);

    if(f.is_open())
        for(const auto& el : sensors)
            f << el->toString() << std::endl;

    f.close();
}

void SensorHub::loadSensorsFromFile(const std::string& file)
{
    std::ifstream f(file);

    if(f.is_open())
    {
        std::string current;
        while(std::getline(f, current))
        {
            std::string curr;
            std::vector<std::string> args{};
            std::for_each(current.begin(), current.end(), [&](char el) -> void{
                if(el == ';')
                {
                    args.push_back(curr);
                    curr = "";
                }
                else if(el != '\n')
                    curr += el;
            });

            args.push_back(curr);

            if(args.size() == 5)
            {
                try
                {
                    std::shared_ptr<Sensor> sens(new PressureSensorP12(std::stoi(args[0]), static_cast<bool>(std::stoi(args[1])), static_cast<PressureUnit>(std::stoi(args[2])), std::stof(args[3]), std::stof(args[4])));

                    addSensor(sens);
                }catch(DuplicateSensorException& e)
                {
                    Log(LogType::ERROR) << "Error when adding sensor: " << e.what() << '\n';
                }catch(std::exception& e)
                {
                    Log(LogType::ERROR) << "Some other error happened: " << e.what() << '\n';
                }
            }
            else if(args.size() == 3)
            {
                try
                {
                    std::shared_ptr<Sensor> sens(new PressureSensor(std::stoi(args[0]), static_cast<bool>(std::stoi(args[1])), static_cast<PressureUnit>(std::stoi(args[2]))));

                    addSensor(sens);
                }catch(DuplicateSensorException& e)
                {
                    Log(LogType::ERROR) << "Error when adding sensor: " << e.what() << '\n';
                }catch(std::exception& e)
                {
                    Log(LogType::ERROR) << "Some other error happened: " << e.what() << '\n';
                }
            }
        }
    }
}