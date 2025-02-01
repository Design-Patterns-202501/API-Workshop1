#include "BookingService.h"

vector<Booking> BookingService::GetBookingsByDate(std::string date) {
    vector<Booking> res;

    const function<void(std::string)> callback = [&](std::string path) -> void {
        json j = json::parse( db.DumpText(path) );
        res.emplace_back(j);
    };

    db.IterateFiles(date, callback);   

    return res;
};
