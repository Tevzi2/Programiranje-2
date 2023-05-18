//
// Created by Tevz on 18/05/2023.
//

#include <PressureSensorP12.hpp>

PressureSensorP12::PressureSensorP12(uint32_t id, bool active, PressureUnit unit, float latitude, float longitude)
    : PressureSensor(id, active, unit), latitude(latitude), longitude(longitude)
{
    ;
}

[[nodiscard]] std::string PressureSensorP12::toString() const
{
    std::string out = PressureSensor::toString();
    out += ";" + std::to_string(latitude) + ";" + std::to_string(longitude);

    return out;
}