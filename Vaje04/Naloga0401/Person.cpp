#include "Person.hpp"

Person::Person(const std::string &firstName, const std::string &lastName, unsigned int age, float weight,
               unsigned int height) : firstName(firstName), lastName(lastName), age(age), weight(weight), height(height) {
}

const std::string &Person::getFirstName() const {
    return firstName;
}

void Person::setFirstName(const std::string &firstName) {
    Person::firstName = firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

void Person::setLastName(const std::string &lastName) {
    Person::lastName = lastName;
}

unsigned int Person::getAge() const {
    return age;
}

void Person::setAge(unsigned int age) {
    Person::age = age;
}

float Person::getWeight() const {
    return weight;
}

void Person::setWeight(float weight) {
    Person::weight = weight;
}

unsigned int Person::getHeight() const {
    return height;
}

void Person::setHeight(unsigned int height) {
    Person::height = height;
}

std::string Person::toString() const {
    return firstName + " " + lastName + " | Age: " + std::to_string(age) + " | Height: " + std::to_string(height) +
           " cm | Weight: " + std::to_string(weight) + " kg";
}
