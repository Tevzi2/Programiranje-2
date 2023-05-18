#include <PressureSensor.hpp>

PressureSensor::PressureSensor(uint32_t id, bool active, PressureUnit unit)
    : Sensor(id, active), unit(unit)
{
    ;
}

[[nodiscard]] std::string PressureSensor::toString() const
{
    std::string out = Sensor::toString();
    out += ";" + std::to_string(static_cast<uint32_t>(unit));
}