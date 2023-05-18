#pragma once

#include <memory>
#include <Sensor.hpp>
#include <PressureSensor.hpp>
#include <PressureSensorP12.hpp>
#include <DuplicateSensorException.hpp>
#include <fstream>
#include <vector>

class SensorHub {
    public:
        SensorHub() = default;

        void addSensor(std::shared_ptr<Sensor> sensor);

        void readValues() const;

        void saveSensorsToFile(const std::string& file);

        void loadSensorsFromFile(const std::string& file);

    private:
        std::vector<std::shared_ptr<Sensor>> sensors{};
};
