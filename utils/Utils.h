#ifndef UTILS_H
#define UTILS_H

#include "../include/httplib.h"
#include <nlohmann/json.hpp>

using namespace nlohmann;

class Utils {

public:
  static std::string BuildResponse(json data, json error = json(nullptr)) {
    json response;
    response["data"] = data;
    response["error"] = error;
    return response.dump();
  };

  static void SetContentJSON(httplib::Response &res, std::string content) {
    res.set_content(content, "application/json");
  }

  static void BadRequest(httplib::Response &res, std::string msg) {
    json data(nullptr);
    json error;
    error["message"] = msg;
    res.status = httplib::StatusCode::BadRequest_400;
    Utils::SetContentJSON(res, BuildResponse(data, error));
  };

  static void Ok(httplib::Response &res, json data) {
    res.status = httplib::StatusCode::OK_200;
    Utils::SetContentJSON(res, BuildResponse(data));
  }

  static std::string CleanDate(std::string date) {
    std::string res;
    for (auto c : date)
      if (c != '/')
        res += c;
    return res;
  }

  static void ExceptionHandler(const httplib::Request &req,
                               httplib::Response &res, std::exception_ptr ep) {
    std::string exceptionString;
    try {
      std::rethrow_exception(ep);
    } catch (std::exception &e) {
      exceptionString = e.what();
    } catch (...) {
      exceptionString = "Unknown Exception";
    }

    Utils::BadRequest(res, exceptionString);
  };
};

#endif // !UTILS_H
