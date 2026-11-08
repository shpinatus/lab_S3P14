#include "../include/StudentCard.h"
#include <iostream>

using namespace std;

StudentCard::StudentCard(int number, const string& owner, int trips,
                         const string& school, int validYear)
    : TransportCard(number, owner, trips), school(school), validYear(validYear)
{
    if (this->trips > MONTH_LIMIT)
        this->trips = MONTH_LIMIT;
}

bool StudentCard::isValid() const
{
    return validYear >= CURRENT_YEAR;
}

void StudentCard::setSchool(const string& school)
{
    this->school = school;
}

void StudentCard::prolong(int year)
{
    if (year < CURRENT_YEAR || year > CURRENT_YEAR + 5)
    {
        cout << "Ошибка: год должен быть от " << CURRENT_YEAR << " до " << CURRENT_YEAR + 5 << ".\n";
        return;
    }
    validYear = year;
    cout << "Карта продлена до " << validYear << " года.\n";
}

void StudentCard::renewMonth()
{
    if (!isValid())
    {
        cout << "Карта просрочена, пополнение невозможно.\n";
        return;
    }
    trips = MONTH_LIMIT;
    cout << "Начислен месячный лимит: " << trips << " поездок.\n";
}

bool StudentCard::ride()
{
    if (!isValid())
    {
        cout << "Карта " << number << ": срок действия истёк в " << validYear << " году.\n";
        return false;
    }
    return TransportCard::ride();
}

string StudentCard::type() const
{
    return "Льготная карта учащегося";
}

void StudentCard::show() const
{
    TransportCard::show();
    cout << " | Учебное заведение: " << school << " | Действует до: " << validYear
         << (isValid() ? "" : " (просрочена)") << "\n";
}
