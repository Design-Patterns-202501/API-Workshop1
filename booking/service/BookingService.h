#ifndef BOOKING_SERVICE_H
#define BOOKING_SERVICE_H

#include <iostream>
#include <vector>
#include "../../schemas/declarations/Booking.h"
#include "../../lib/declarations/FileManager.h"

class BookingService {

    private:
        FileManager db;

    public:

        BookingService() = default;

        /**
         * Mantain the format YYYYMMDD
         */
        vector<Booking> GetBookingsByDate(std::string date);
};

#endif // !BOOKING_SERVICE_H
