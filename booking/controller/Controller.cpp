#include "Controller.h"

BookingController::BookingController(Server &srv) : app(&srv) {
  auto getController = std::bind(&BookingController::GetBookings, this,
                                 std::placeholders::_1, std::placeholders::_2);
  this->app->Get("/bookings", getController);

  auto postController = std::bind(&BookingController::CreateOneBooking, this,
                                  std::placeholders::_1, std::placeholders::_2,
                                  std::placeholders::_3);
  this->app->Post("/booking/create", postController);
};

void BookingController::GetBookings(const Request &req, Response &res) {
  if (!req.has_param("date")) {
    Utils::BadRequest(res, "Date param required");
    return;
  }

  std::string paramDate = req.get_param_value("date");

  paramDate = Utils::CleanDate(paramDate);

  vector<Booking> bookings = service.GetBookingsByDate(paramDate);

  json result = json::array();

  for (auto b : bookings)
    result.push_back(b.ToJson());

  Utils::Ok(res, result);
};

void BookingController::CreateOneBooking(const Request &req, Response &res,
                                         const ContentReader &reader) {
  std::string rawBooking;

  reader([&](const char *data, size_t data_length) {
    rawBooking.append(data, data_length);
    return true;
  });

  Booking nw(json::parse(rawBooking));

  bool good = true;

  std::string msg = service.CreateBooking(nw, good);

  if (!good) {
    Utils::BadRequest(res, msg);
    return;
  }

  Utils::Ok(res, msg);
};
