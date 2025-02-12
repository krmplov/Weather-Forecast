#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <fstream>

#include "nlohmann/json.hpp"

#include "ErrorOutput.h"

class ParseJson {
public:
    ParseJson(const std::string& config_path);

    std::vector<std::string>& GetCities();
    uint64_t GetTime();
    uint64_t GetCountDays();
    std::string& GetApi();

private:
    std::vector<std::string> cities_;
    uint64_t time_ = 0;
    uint64_t count_days_ = 0;
    std::string api_key_;
};