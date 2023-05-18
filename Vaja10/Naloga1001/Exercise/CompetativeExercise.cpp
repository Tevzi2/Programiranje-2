#include <CompetativeExercise.hpp>

CompetativeExercise::CompetativeExercise(Difficulty difficulty, std::string name, Time duration, int32_t calloriesBurned, int32_t avgHeartRate, Date date, Person* competitor, double points)
    : Exercise(difficulty, name, duration, calloriesBurned, avgHeartRate, date), competitor(competitor), points(points)
{
    ;
}

void CompetativeExercise::setCompetitor(Person* competitor)
{
    this->competitor = competitor;
}

void CompetativeExercise::setPoints(double points)
{
    this->points = points;
}

[[nodiscard]] Person* CompetativeExercise::getCompetitor() const
{
    return competitor;
}

[[nodiscard]] double CompetativeExercise::getPoints() const
{
    return points;
};

[[nodiscard]] std::string CompetativeExercise::toString() const
{
    std::string out =
        Exercise::toString()
        + " | Competitor: " +
        competitor->toString()
        + " | Points: " +
        std::to_string(points);

    return out;
}

void CompetativeExercise::print() const
{
    std::cout << toString() << std::endl;
}