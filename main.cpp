#include "booking/controller/Controller.h"
#include "include/httplib.h"
#include "utils/Utils.h"

#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace httplib;

using json = nlohmann::json;

int main() {

  Server svr;

  svr.Get("/ping", [](const Request &req, Response &res) {
    res.set_content("Pong", "text/plain");
    cout << "Sended..." << endl;
  });

  BookingController booking(svr);

  auto exceptionHandler =
      std::bind(&Utils::ExceptionHandler, std::placeholders::_1,
                std::placeholders::_2, std::placeholders::_3);

  svr.set_exception_handler(exceptionHandler);

  svr.listen("0.0.0.0", 3000);

  return 0;
}
