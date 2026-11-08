#include "../include/TransportCard.h"
#include <iostream>

using namespace std;

TransportCard::TransportCard() : number(0), owner("Noname"), trips(0)
{
}

TransportCard::TransportCard(int number, const string& owner, int trips)
    : number(number), owner(owner), trips(trips < 0 ? 0 : trips)
{
}

TransportCard::~TransportCard()
{
}

int TransportCard::getNumber() const
{
    return number;
}

int TransportCard::getTrips() const
{
    return trips;
}

string TransportCard::getOwner() const
{
    return owner;
}

void TransportCard::setOwner(const string& owner)
{
    this->owner = owner;
}

bool TransportCard::hasTrips() const
{
    return trips > 0;
}

bool TransportCard::ride()
{
    if (trips == 0)
    {
        cout << "Карта " << number << ": поездок нет, проход запрещён.\n";
        return false;
    }
    trips--;
    cout << "Карта " << number << ": проход разрешён, осталось поездок: " << trips << "\n";
    return true;
}

string TransportCard::type() const
{
    return "Транспортная карта";
}

void TransportCard::show() const
{
    cout << type() << " №" << number << " | Владелец: " << owner
         << " | Поездок: " << trips;
}
