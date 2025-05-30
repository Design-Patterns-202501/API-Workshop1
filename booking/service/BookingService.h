#ifndef BOOKING_SERVICE_H
#define BOOKING_SERVICE_H

#include "../../lib/declarations/Mongo.h"
#include "../../schemas/declarations/Booking.h"
#include "../../utils/Utils.h"
#include <iostream>
#include <vector>

class BookingService {

private:
  Mongo db;

public:
  BookingService();

  /**
   * Mantain the format YYYYMMDD
   */
  vector<Booking> GetBookingsByDate(std::string date);

  string CreateBooking(Booking add, bool &good);
};

#endif // !BOOKING_SERVICE_H
