# S3P14 Наследование — вариант 14

Исполнитель: Нестеренко М. (ИКТГ-2521)

- Базовый класс `TransportCard` — магнитная карта для проезда на транспорте
- `MetroCard` — карта общего назначения для проезда в метро
- `StudentCard` — льготная транспортная карта учащегося

Вычисляемый параметр: количество карт без поездок.

Структура проекта:

```
main.cpp
include/TransportCard.h  include/MetroCard.h  include/StudentCard.h
src/TransportCard.cpp    src/MetroCard.cpp    src/StudentCard.cpp
```

Сборка и запуск:

```
g++ main.cpp src/*.cpp -o lab
./lab
```
