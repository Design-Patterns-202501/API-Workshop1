#include "booking/controller/Controller.h"
#include "include/httplib.h"
#include "include/dotenv-cpp.h"
#include "utils/Utils.h"

#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace httplib;

using json = nlohmann::json;

int main() {

  dotenv::init();

  Server svr;

  // Preflight routes
  svr.Options(R"(\*)", [](const auto& req, auto& res) {
    res.set_header("Access-Control-Allow-Origin", "*");
    res.set_header("Allow", "GET, POST, HEAD, OPTIONS");
    res.set_header("Access-Control-Allow-Headers", "X-Requested-With, Content-Type, Accept, Origin, Authorization");
    res.set_header("Access-Control-Allow-Methods", "OPTIONS, GET, POST, HEAD");
  });

  svr.Options("/booking/create", [](const auto& req, auto& res) {
    res.set_header("Access-Control-Allow-Origin", "*");
    res.set_header("Allow", "GET, POST, HEAD, OPTIONS");
    res.set_header("Access-Control-Allow-Headers", "X-Requested-With, Content-Type, Accept, Origin, Authorization");
    res.set_header("Access-Control-Allow-Methods", "OPTIONS, GET, POST, HEAD");
  });

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
