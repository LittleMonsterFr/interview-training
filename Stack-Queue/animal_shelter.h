//
// Created by Damien Laidin on 24/10/2019.
//

#ifndef INTERVIEW_TRAINING_ANIMAL_SHELTER_H
#define INTERVIEW_TRAINING_ANIMAL_SHELTER_H

#include "queue.hpp"
#include <string>
#include <utility>
#include <ostream>

using namespace std;

class Animal
{
public:

    explicit Animal(string name) : _name(std::move(name)) {};
    explicit Animal() = default;
    virtual bool IsDog() = 0;
    virtual bool IsCat() = 0;
    virtual bool IsSameBreedAs(Animal& animal) = 0;

    virtual ~Animal() = default;

    friend ostream &operator <<(ostream &os, const Animal &animal)
    {
        os << "_name: " << animal._name;
        return os;
    }

private:
    string _name;
};

class Dog : public Animal
{
public:
    explicit Dog(string name) : Animal(std::move(name)) {};
    explicit Dog() = default;

    bool IsDog() override;

    bool IsCat() override ;

    bool IsSameBreedAs(Animal& animal) override ;
};

class Cat : public Animal
{
public:
    explicit Cat(string name) : Animal(std::move(name)) {};
    explicit Cat() = default;

    bool IsDog() override;

    bool IsCat() override;

    bool IsSameBreedAs(Animal& animal) override;
};

class AnimalShelter : Queue<Animal> {

public:
    void Enqueue(Animal& animal);

    Animal& dequeueAny();

    Dog& dequeueDog();

    Cat& dequeueCat();

private:
    Animal& dequeueDogOrCat(Animal& animal);

};

#endif //INTERVIEW_TRAINING_ANIMAL_SHELTER_H