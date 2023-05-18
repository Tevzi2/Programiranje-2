#pragma once

#include<cstdio>
#include<string>
#include<iostream>

class Sensor
{
    public:
        Sensor(uint32_t id, bool active);

        [[nodiscard]] uint32_t getId() const;

        [[nodiscard]] bool isActive() const;

        [[nodiscard]] virtual std::string toString() const;

        [[nodiscard]] virtual float readValue() const;

    protected:
        uint32_t id;
        bool active;
};
