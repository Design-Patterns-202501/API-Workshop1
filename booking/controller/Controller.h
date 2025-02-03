#ifndef BOOKING_CONTROLLER_H
#define BOOKING_CONTROLLER_H

#include "../../include/httplib.h"
#include "../../utils/Utils.h"
#include "../service/BookingService.h"

#include <nlohmann/json.hpp>

using namespace httplib;
using namespace nlohmann;

class BookingController {

private:
  Server *app;
  BookingService service;

public:
  BookingController(Server &srv);

  void GetBookings(const Request &req, Response &res);
  void CreateOneBooking(const Request &req, Response &res,
                        const ContentReader &reader);
};

#endif // BOOKING_CONTROLLER_H
