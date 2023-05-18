#pragma once

#include <Sensor.hpp>
#include <string
#include <PressureUnit.hpp>

class PressureSensor : public Sensor {
    public:
        PressureSensor(uint32_t id, bool active, PressureUnit unit);

        [[nodiscard]] std::string toString() const override;
    protected:
        PressureUnit unit;
};
