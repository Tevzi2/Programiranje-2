#include "FuelLog.hpp"

FuelLog::FuelLog(uint32_t kilometers, uint32_t day, uint32_t month, uint32_t year, float pricePerLiter, float quantity)
    :kilometers(kilometers), day(day), month(month), year(year), pricePerLiter(pricePerLiter), quantity(quantity)
{
    ;
}

[[nodiscard]] uint32_t FuelLog::getKilometers() const
{
    return kilometers;
}

[[nodiscard]] uint32_t FuelLog::getDay() const
{
    return day;
}

[[nodiscard]] uint32_t FuelLog::getMonth() const
{
    return month;
}

[[nodiscard]] uint32_t FuelLog::getYear() const
{
    return year;
}

[[nodiscard]] float FuelLog::getPricePerLiter() const
{
    return pricePerLiter;
}

[[nodiscard]] float FuelLog::getQuantity() const
{
    return quantity;
}

[[nodiscard]] float FuelLog::getTotalCost() const
{
    return quantity * pricePerLiter;
}

void FuelLog::setKilometers(uint32_t newKilometers)
{
    kilometers = newKilometers;
}

[[nodiscard]] std::string FuelLog::toString() const
{
    std::string out =
        "KM driven: " +
        std::to_string(kilometers) +
        ", on date: " +
        std::to_string(day) + ". " +
        std::to_string(month) + ". " +
        std::to_string(year) + ". " +
        ", fuel used: " +
        std::to_string(quantity);

    return out;
}

[[nodiscard]] float FuelLog::getConsumption() const
{
    return 100.0f / (static_cast<float>(kilometers) / quantity);
}