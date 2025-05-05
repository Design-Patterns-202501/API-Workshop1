#include "BookingService.h"

BookingService::BookingService(): db("barber") {
};

vector<Booking> BookingService::GetBookingsByDate(std::string date) {
  vector<Booking> res;
  json query; query.emplace("date", date);
  auto jsonResults = db.find("bookings", query);

  for (json result: jsonResults) res.emplace_back(result);
  return res;
};

string BookingService::CreateBooking(Booking add, bool &good) {
  add.date(Utils::CleanDate(add.date()));
  auto result = db.insert("bookings", add.ToJson());
  return result;
};
