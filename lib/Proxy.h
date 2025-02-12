#pragma once

#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <chrono>
#include <thread>

#include "nlohmann/json.hpp"

#include "HttpClient.h"

class Proxy {
public:
    Proxy(HttpWeather& client, uint64_t time);
    nlohmann::json GetWeather(std::string& city);
    void ChangeCountDaysUp();
    void ChangeCountDaysDown();

private:
    bool CheckUpdate(std::string& city);
    HttpWeather client_;
    std::unordered_map<std::string, nlohmann::json> cache_;
    std::unordered_map<std::string, std::chrono::steady_clock::time_point> last_update_;
    std::chrono::minutes time_;
    int64_t update_days_ = 0;
};