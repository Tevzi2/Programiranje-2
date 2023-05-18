//
// Created by Tevz on 18/05/2023.
//

#include <Sensor.hpp>

Sensor::Sensor(uint32_t id, bool active)
    :id(id), active(active)
{
    ;
}

[[nodiscard]] uint32_t Sensor::getId() const {
    return id;
}

[[nodiscard]] bool Sensor::isActive() const
{
    return active;
}

[[nodiscard]] std::string Sensor::toString() const
{
    std::string out;
    out += std::to_string(id) +";" + std::to_string(active);

    return out;
}

[[nodiscard]] float Sensor::readValue() const
{
    return (float)(rand()) / (float)(rand());
}
