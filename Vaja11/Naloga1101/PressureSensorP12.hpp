#pragma once

#include<PressureSensor.hpp>

class PressureSensorP12 final : public PressureSensor {
    public:
        PressureSensorP12(uint32_t id, bool active, PressureUnit unit, float latitude, float longitude);

        [[nodiscard]] std::string toString() const override;

    protected:
        float latitude;
        float longitude;
};
