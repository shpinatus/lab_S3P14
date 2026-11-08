#ifndef TRANSPORTCARD_H
#define TRANSPORTCARD_H

#include <string>

class TransportCard
{
public:
    TransportCard();
    TransportCard(int number, const std::string& owner, int trips);
    virtual ~TransportCard();

    int getNumber() const;
    int getTrips() const;
    std::string getOwner() const;
    void setOwner(const std::string& owner);
    bool hasTrips() const;

    virtual bool ride();
    virtual void show() const;
    virtual std::string type() const;

protected:
    int number;
    std::string owner;
    int trips;
};

#endif
