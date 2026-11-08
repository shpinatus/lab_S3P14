#include <iostream>
#include <string>
#include "include/TransportCard.h"
#include "include/MetroCard.h"
#include "include/StudentCard.h"

using namespace std;

const int COUNT = 5;

int readInt(const string& prompt)
{
    string line;
    while (true)
    {
        cout << prompt;
        if (!getline(cin, line))
            exit(0);
        try
        {
            size_t pos;
            int value = stoi(line, &pos);
            if (line.find_first_not_of(" \t\r", pos) == string::npos)
                return value;
        }
        catch (...)
        {
        }
        cout << "Ошибка: введите целое число.\n";
    }
}

string readLine(const string& prompt)
{
    string line;
    while (true)
    {
        cout << prompt;
        if (!getline(cin, line))
            exit(0);
        if (!line.empty())
            return line;
        cout << "Ошибка: строка не должна быть пустой.\n";
    }
}

void showAll(TransportCard* cards[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". ";
        cards[i]->show();
    }
}

int readIndex(int n)
{
    int k = readInt("Номер элемента массива (1-" + to_string(n) + "): ");
    while (k < 1 || k > n)
        k = readInt("Нет такого элемента, повторите: ");
    return k - 1;
}

void editCard(TransportCard* cards[], int n)
{
    TransportCard* card = cards[readIndex(n)];
    card->show();
    MetroCard* metro = dynamic_cast<MetroCard*>(card);
    StudentCard* student = dynamic_cast<StudentCard*>(card);
    cout << "1. Сменить владельца\n";
    if (metro)
        cout << "2. Пополнить баланс\n3. Купить поездки\n";
    if (student)
        cout << "2. Сменить учебное заведение\n3. Продлить срок действия\n4. Начислить месячный лимит\n";
    int action = readInt("Действие: ");
    if (action == 1)
        card->setOwner(readLine("Новый владелец: "));
    else if (metro && action == 2)
        metro->topUp(readInt("Сумма, руб.: "));
    else if (metro && action == 3)
        metro->buyTrips(readInt("Количество поездок: "));
    else if (student && action == 2)
        student->setSchool(readLine("Учебное заведение: "));
    else if (student && action == 3)
        student->prolong(readInt("Год окончания действия: "));
    else if (student && action == 4)
        student->renewMonth();
    else
        cout << "Нет такого действия.\n";
    card->show();
}

int countWithoutTrips(TransportCard* cards[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (!cards[i]->hasTrips())
            count++;
    return count;
}

int main()
{
    MetroCard m1(1001, "Иванов И.", 20, 150);
    MetroCard m2(1002, "Петрова А.", 0, 30);
    MetroCard m3(1003, "Сидоров П.", 3, 500);
    StudentCard s1(2001, "Нестеренко М.", 45, "СПбГУТ", 2027);
    StudentCard s2(2002, "Смирнова Е.", 0, "Лицей №239", 2025);

    TransportCard* cards[COUNT] = { &m1, &m2, &m3, &s1, &s2 };

    int work = 1;
    while (work)
    {
        cout << "\n===== Транспортные карты =====\n"
             << "1. Показать все карты\n"
             << "2. Поездка по карте\n"
             << "3. Изменить свойства карты\n"
             << "4. Количество карт без поездок\n"
             << "0. Выход\n";
        int command = readInt("Введите номер команды -> ");
        switch (command)
        {
        case 1:
            showAll(cards, COUNT);
            break;
        case 2:
            cards[readIndex(COUNT)]->ride();
            break;
        case 3:
            editCard(cards, COUNT);
            break;
        case 4:
            cout << "Карт без поездок: " << countWithoutTrips(cards, COUNT) << " из " << COUNT << "\n";
            break;
        case 0:
            work = 0;
            break;
        default:
            cout << "Нет такой команды.\n";
        }
    }
    cout << "Работа завершена.\n";
    return 0;
}
