//
// Created by Damien Laidin on 22/10/2019.
//

#include <iostream>
#include <string>

#include "animal_shelter.h"

using namespace std;

int main()
{
    auto shelter = new AnimalShelter();

    Dog willow = Dog(string("Willow"));
    Dog buddy = Dog(string("Buddy"));
    Dog jipsy = Dog(string("Jipsy"));
    Dog henry = Dog(string("Henry"));

    Cat echo = Cat(string("Echo"));
    Cat whisky = Cat(string("Whisky"));
    Cat felix = Cat(string("Felix"));
    Cat cesar = Cat(string("Cesar"));

    shelter->Enqueue(echo);
    shelter->Enqueue(whisky);
    shelter->Enqueue(felix);
    shelter->Enqueue(willow);
    shelter->Enqueue(buddy);
    shelter->Enqueue(cesar);
    shelter->Enqueue(jipsy);
    shelter->Enqueue(henry);

    cout <<  shelter->dequeueDog() << endl;
    cout << shelter->dequeueAny() << endl;
    cout <<  shelter->dequeueDog() << endl;
    cout <<  shelter->dequeueDog() << endl;
    cout <<  shelter->dequeueDog() << endl;

    try
    {
        shelter->dequeueDog();
    }
    catch (logic_error &e)
    {
        cout << e.what() << endl;
    }

    cout << shelter->dequeueAny() << endl;

    cout <<  shelter->dequeueCat() << endl;
    cout <<  shelter->dequeueCat() << endl;

    try
    {
        shelter->dequeueAny();
    }
    catch (logic_error &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}