#include "../declarations/Booking.h"

Booking::Booking(json file) {
  this->id_ = file["id"].template get<string>();
  this->clientName_ = file["clientName"].template get<string>();
  this->clientAge_ = file["clientAge"].template get<int>();
  this->hour_ = file["hour"].template get<int>();
  this->minute_ = file["minute"].template get<int>();
  this->date_ = file["date"].template get<string>();
};

json Booking::ToJson() {
  json f = {{"id", this->id_},
            {"clientName", this->clientName_},
            {"clientAge", this->clientAge_},
            {"hour", this->hour_},
            {"minute", this->minute_},
            {"date", this->date_}};

  return f;
};
