#include "Controller.h"

BookingController::BookingController(Server &srv) : app(&srv) {
    auto getController = std::bind(&BookingController::GetOneBooking, this, std::placeholders::_1, std::placeholders::_2);
    this->app->Get("/booking", getController);
};


void BookingController::GetOneBooking(const Request &req, Response & res) {
    if (!req.has_param("date")) {
        Utils::BadRequest(res, "Date param required");
        return;
    }

    vector<Booking> bookings = service.GetBookingsByDate( req.get_param_value("date") );


};
