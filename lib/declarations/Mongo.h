#ifndef MONGO_H
#define MONGO_H

#include <mongocxx/client.hpp>
#include <cstdlib>
#include <vector>
#include <map>
#include <nlohmann/json.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

using json = nlohmann::json;
using mongoDocument = bsoncxx::document::value;
using namespace bsoncxx::builder::basic;

class Mongo {
    private:
        mongocxx::client client;
        mongocxx::database db;
        mongoDocument jsonToDoc(json &query);

    public:
        Mongo(std::string databaseName);
        std::vector<json> find(std::string collection, json &query);
        std::string insert(std::string collectionName, json doc);

};

#endif // !MONGO_H
