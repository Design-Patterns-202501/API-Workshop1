#include "../declarations/Mongo.h"
#include <iostream>
using namespace std;

Mongo::Mongo(std::string databaseName) {
  client = mongocxx::client(mongocxx::uri(std::getenv("MONGO_URI")));
  db = client[databaseName];
};

mongoDocument Mongo::jsonToDoc(json &query) {
  return bsoncxx::from_json(query.dump());
}

std::vector<json> Mongo::find(std::string collectionName, json &query) {
  auto collection = db[collectionName];
  auto cursor = collection.find(jsonToDoc(query));
  std::vector<json> result;
  for (auto &&doc : cursor) {
    result.emplace_back(json::parse(bsoncxx::to_json(doc).c_str()));
  }
  return result;
}

std::string Mongo::insert(std::string collectionName, json doc) {
  auto collection = db[collectionName];
  auto result = collection.insert_one(jsonToDoc(doc));
  auto oid = result->inserted_id().get_oid().value;
  return oid.to_string();
}
