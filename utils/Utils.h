#ifndef UTILS_H
#define UTILS_H

#include <nlohmann/json.hpp>
#include "../include/httplib.h"

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
};

#endif // !UTILS_H
