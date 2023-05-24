//
// Created by Tevz on 18/05/2023.
//

#include <PressureSensorP12.hpp>

PressureSensorP12::PressureSensorP12(uint32_t id, bool active, PressureUnit unit, float latitude, float longitude)
    : PressureSensor(id, active, unit), latitude(latitude), longitude(longitude)
{
    if(latitude < -90 || latitude > 90) throw InvalidLocationException("Latitude is out of bounds.");
    if(longitude < -180 || longitude > 180) throw InvalidLocationException("Longitude is out of bounds.");
}

[[nodiscard]] std::string PressureSensorP12::toString() const
{
    std::string out = PressureSensor::toString();
    out += ";" + std::to_string(latitude) + ";" + std::to_string(longitude);

    return out;
}