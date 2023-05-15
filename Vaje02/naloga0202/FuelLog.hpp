#pragma once

#include <string>

class FuelLog
{
    public:
        FuelLog(uint32_t kilometers, uint32_t day, uint32_t month, uint32_t year, float pricePerLiter, float quantity);

        [[nodiscard]] uint32_t getKilometers() const;

        [[nodiscard]] uint32_t getDay() const;

        [[nodiscard]] uint32_t getMonth() const;

        [[nodiscard]] uint32_t getYear() const;

        [[nodiscard]] float getPricePerLiter() const;

        [[nodiscard]] float getQuantity() const;

        [[nodiscard]] float getTotalCost() const;

        void setKilometers(uint32_t kilometers);

        [[nodiscard]] std::string toString() const;

        [[nodiscard]] float getConsumption() const;

    private:
        uint32_t kilometers;
        uint32_t  day;
        uint32_t  month;
        uint32_t  year;
        float pricePerLiter;
        float quantity;
};