#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "cpr/cpr.h"
#include "nlohmann/json.hpp"

#include "ErrorOutput.h"

class HttpCoordinates {
public:
    HttpCoordinates(std::string& api_key);
    void Get(std::vector<std::string>& cities);
    std::unordered_map<std::string, std::pair<std::string, std::string>>& GetCity();
private:
    const std::string kUrl_ = "https://api.api-ninjas.com/v1/city";
    std::string api_key_;
    std::unordered_map<std::string, std::pair<std::string, std::string>> cities_coordinates_;
};

class HttpWeather {
public:
    HttpWeather(std::unordered_map<std::string, std::pair<std::string, std::string>>& coordinates, uint64_t count_days);
    nlohmann::json Get(std::string& city, int64_t update = 0);
private:
    std::unordered_map<std::string, std::pair<std::string, std::string>> coordinates_;
    uint64_t count_days_;
    const std::string kUrl_ = "https://api.open-meteo.com/v1/forecast";
};