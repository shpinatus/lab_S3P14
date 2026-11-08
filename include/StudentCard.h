#ifndef STUDENTCARD_H
#define STUDENTCARD_H

#include "TransportCard.h"

class StudentCard : public TransportCard
{
public:
    static const int MONTH_LIMIT = 70;
    static const int CURRENT_YEAR = 2026;

    StudentCard(int number, const std::string& owner, int trips,
                const std::string& school, int validYear);

    bool isValid() const;
    void setSchool(const std::string& school);
    void prolong(int year);
    void renewMonth();

    bool ride() override;
    void show() const override;
    std::string type() const override;

private:
    std::string school;
    int validYear;
};

#endif
