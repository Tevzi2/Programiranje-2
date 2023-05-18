#pragma once

#include <Sensor.hpp>
#include <string>
#include <PressureUnit.hpp>

class PressureSensor : public Sensor {
    public:
        PressureSensor() = delete;

        PressureSensor(uint32_t id, bool active, PressureUnit unit);

        [[nodiscard]] float readValue() const final;

        [[nodiscard]] std::string toString() const override;
    protected:
        PressureUnit unit;
};
