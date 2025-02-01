#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace nlohmann;

class Booking {
    private:
        string id;
        string clientName;
        int clientAge;
        int hour;
        int minute;

    public:
        Booking() = default;
        Booking(string cc, string name, int age, int h, int m) : id(cc), clientName(name), clientAge(age), hour(h), minute(m) {};
        Booking(json file);

        json ToJson();
};

#endif // !BOOKING_H
