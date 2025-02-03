#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace nlohmann;

class Booking {
private:
  string id_;
  string clientName_;
  int clientAge_;
  int hour_;
  int minute_;
  string date_;

public:
  Booking() = default;
  Booking(bool empty) : id_("-1") {}
  Booking(string cc, string name, int age, int h, int m, string date)
      : id_(cc), clientName_(name), clientAge_(age), hour_(h), minute_(m),
        date_(date) {};
  Booking(json file);

  json ToJson();

  string id() const { return id_; };
  void id(string id) { id_ = move(id); };

  string clientName() const { return clientName_; };
  void clientName(string clientName) { clientName_ = move(clientName); };

  int clientAge() const { return clientAge_; };
  void clientAge(int clientAge) { clientAge_ = move(clientAge); };

  int hour() const { return hour_; };
  void hour(int hour) { hour_ = move(hour); };

  int minute() const { return minute_; };
  void minute(int minute) { minute_ = move(minute); };

  string date() const { return date_; };
  void date(string date) { date_ = move(date); };
};

#endif // !BOOKING_H
