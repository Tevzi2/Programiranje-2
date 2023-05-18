#pragma once

#include <memory>
#include <Sensor.hpp>
#include <vector>

class SensorHub {
    public:
        SensorHub();

        void addSensor(std::unique_ptr<Sensor> sensor);

        void readValues();

        void saveSensorsToFile(const std::string& file);

        void loadSensorsFromFile(const std::string& file);

    private:
        std::vector<std::unique_ptr<Sensor>> sensors{};
};
