#ifndef TASK1001_PERSON_H
#define TASK1001_PERSON_H

#include <string>

class Person {
private:
    std::string firstName;
    std::string lastName;
    unsigned int age;
    float weight; //in kg
    unsigned int height; //in cm

public:
    Person(const std::string& firstName, const std::string& lastName, unsigned int age, float weight, unsigned int height);

    const std::string &getFirstName() const;
    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;
    void setLastName(const std::string &lastName);

    unsigned int getAge() const;
    void setAge(unsigned int age);

    float getWeight() const;
    void setWeight(float weight);

    unsigned int getHeight() const;
    void setHeight(unsigned int height);

    std::string toString() const;
};


#endif //TASK1001_PERSON_H
