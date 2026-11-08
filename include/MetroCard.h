#ifndef METROCARD_H
#define METROCARD_H

#include "TransportCard.h"

class MetroCard : public TransportCard
{
public:
    static const int TRIP_PRICE = 70;

    MetroCard(int number, const std::string& owner, int trips, int balance);

    int getBalance() const;
    void topUp(int amount);
    bool buyTrips(int count);

    bool ride() override;
    void show() const override;
    std::string type() const override;

private:
    int balance;
};

#endif
