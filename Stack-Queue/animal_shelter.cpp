//
// Created by Damien Laidin on 24/10/2019.
//

#include "animal_shelter.h"

bool Dog::IsDog()
{
    return true;
}

bool Dog::IsCat()
{
    return false;
}

bool Dog::IsSameBreedAs(Animal& animal)
{
    return animal.IsDog();
}

bool Cat::IsDog()
{
    return false;
}

bool Cat::IsCat()
{
    return true;
}

bool Cat::IsSameBreedAs(Animal &animal)
{
    return animal.IsCat();
}

void AnimalShelter::Enqueue(Animal& animal)
{
    this->add(animal);
}

Animal& AnimalShelter::dequeueAny()
{
    return this->remove();
}

Animal& AnimalShelter::dequeueDogOrCat(Animal& animal)
{
    if (first == nullptr)
    {
        throw logic_error("The shelter is empty. No animal is alone. =)");
    }

    QueueNode<Animal> *current = first;
    QueueNode<Animal> *prev = nullptr;
    while (current != nullptr)
    {
        if (((Animal&)current->_val).IsSameBreedAs(animal))
        {
            Animal& returnAnimal = current->_val;

            if (current == first)
            {
                first = first->next;
            }
            else if (current == last)
            {
                last = prev;
                last->next = nullptr;
            }
            else
            {
                prev->next = current->next;
            }

            delete current;
            return returnAnimal;
        }
        prev = current;
        current = current->next;
    }

    throw logic_error("The shelter doesn't contain the required breed.");
}

Dog &AnimalShelter::dequeueDog()
{
    Dog dog = Dog(std::string());
    return (Dog&) this->dequeueDogOrCat((Animal&) dog);
}

Cat &AnimalShelter::dequeueCat()
{
    Cat cat = Cat();
    return (Cat&) this->dequeueDogOrCat((Animal&) cat);
}


