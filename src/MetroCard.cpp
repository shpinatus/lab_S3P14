#include "../include/MetroCard.h"
#include <iostream>

using namespace std;

MetroCard::MetroCard(int number, const string& owner, int trips, int balance)
    : TransportCard(number, owner, trips), balance(balance < 0 ? 0 : balance)
{
}

int MetroCard::getBalance() const
{
    return balance;
}

void MetroCard::topUp(int amount)
{
    if (amount <= 0)
    {
        cout << "Ошибка: сумма должна быть больше 0.\n";
        return;
    }
    balance += amount;
    cout << "Баланс пополнен, теперь " << balance << " руб.\n";
}

bool MetroCard::buyTrips(int count)
{
    if (count <= 0)
    {
        cout << "Ошибка: число поездок должно быть больше 0.\n";
        return false;
    }
    int cost = count * TRIP_PRICE;
    if (cost > balance)
    {
        cout << "Недостаточно средств: нужно " << cost << " руб., на балансе " << balance << " руб.\n";
        return false;
    }
    balance -= cost;
    trips += count;
    cout << "Куплено поездок: " << count << ", баланс " << balance << " руб.\n";
    return true;
}

bool MetroCard::ride()
{
    if (trips > 0)
        return TransportCard::ride();
    if (balance >= TRIP_PRICE)
    {
        balance -= TRIP_PRICE;
        cout << "Карта " << number << ": оплата с баланса " << TRIP_PRICE
             << " руб., остаток " << balance << " руб.\n";
        return true;
    }
    cout << "Карта " << number << ": нет поездок и недостаточно средств.\n";
    return false;
}

string MetroCard::type() const
{
    return "Карта метро";
}

void MetroCard::show() const
{
    TransportCard::show();
    cout << " | Баланс: " << balance << " руб.\n";
}
