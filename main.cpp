#include <iostream>
#include "booking/controller/Controller.h"
#include "include/httplib.h"
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

    svr.Post("/test", [](const Request &req, Response &res) {
            string body = req.body;
            json postBody = json::parse(body);

            // =O
            cout << boolalpha << postBody["jm"].is_null() << endl;

            // .template get<T>() es para obtener el valor ya casteado a T
            if (!postBody["jm"].is_null())  cout << postBody["jm"].template get<string>() << endl;

            json resp;
            resp["data"] = "Test con el parser del JSON";

            res.set_content(resp.dump(), "application/json");
            });

    BookingController booking(svr);

    svr.listen("0.0.0.0", 3000);

    return 0;
}
