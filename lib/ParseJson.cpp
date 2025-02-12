#include "ParseJson.h"

ParseJson::ParseJson(const std::string& config_path) {
    std::ifstream config_file(config_path);
    if (!config_file){
        ErrorOutput(Errors::kErrorFileNotFound);
    }
    nlohmann::json config = nlohmann::json::parse(config_file);
    config_file.close();
    if (!config.contains("api_key")) {
        ErrorOutput(Errors::kErrorApiKeys);
    }
    if (!config.contains("count_days")) {
        ErrorOutput(Errors::kErrorCountDays);
    }
    if (!config.contains("time")) {
        ErrorOutput(Errors::kErrorTime);
    }
    if (!config.contains("cities")) {
        ErrorOutput(Errors::kErrorListCities);
    }
    if ((config["time"] < 0) || (config["count_days"] < 0)) {
        ErrorOutput(Errors::kErrorNegative);
    }
    this->api_key_ = config["api_key"];
    this->count_days_ = config["count_days"];
    this->time_ = config["time"];
    this->cities_ = config["cities"];
}

std::string& ParseJson::GetApi() {
    return this->api_key_;
}

std::vector<std::string>& ParseJson::GetCities(){
    return this->cities_;
}

uint64_t ParseJson::GetCountDays() {
    return this->count_days_;
}

uint64_t ParseJson::GetTime() {
    return this->time_;
}