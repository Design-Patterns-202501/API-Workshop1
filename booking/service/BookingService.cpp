#include "BookingService.h"

vector<Booking> BookingService::GetBookingsByDate(std::string date) {
  vector<Booking> res;

  const function<void(std::string)> callback = [&](std::string path) -> void {
    json j = json::parse(db.DumpText(path));
    res.emplace_back(j);
  };

  db.IterateFiles(date, callback);

  return res;
};


string BookingService::CreateBooking(Booking add, bool &good) {

    add.date( Utils::CleanDate( add.date() ) );
    std::string bookingPath = db.CWD + add.date() + "/" + add.id() + ".json";
    string rawContent = db.DumpText(bookingPath);

    if (rawContent != "") {
        good = false; return "Booking already exist"; 
    }

    db.WriteFile(bookingPath, add.ToJson().dump(), add.date());

    return "Booking created.";
};
