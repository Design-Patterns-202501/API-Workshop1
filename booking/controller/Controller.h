#ifndef BOOKING_CONTROLLER_H
#define BOOKING_CONTROLLER_H


#include "../../include/httplib.h"
#include "../../utils/Utils.h"
#include "../service/BookingService.h"

using namespace httplib;

class BookingController {

    private:
        Server *app;
        BookingService service;

    public:
        BookingController(Server &srv);

        void GetOneBooking(const Request &req, Response & res);

};



#endif // BOOKING_CONTROLLER_H 
