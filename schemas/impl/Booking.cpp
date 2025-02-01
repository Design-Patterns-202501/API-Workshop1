#include "../declarations/Booking.h"

Booking::Booking(json file) {
    this->id = file["id"].template get<string>();
    this->clientName = file["clientName"].template get<string>();
    this->clientAge = file["clientAge"].template get<int>();
    this->hour = file["hour"].template get<int>();
    this->minute = file["minute"].template get<int>();
};

json Booking::ToJson() {
    json f = {
        {"id", this->id},
        {"clientName", this->clientName},
        {"clientAge", this->clientAge},
        {"hour", this->hour},
        {"minute", this->minute}
    };

    return f;
};
