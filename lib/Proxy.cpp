#include "Proxy.h"

Proxy::Proxy(HttpWeather& client, uint64_t time)
        : client_(client), time_(std::chrono::minutes(time)) {
}

bool Proxy::CheckUpdate(std::string& city) {
    if (this->cache_.find(city) == this->cache_.end()) {
        return true;
    }

    auto now = std::chrono::steady_clock::now();
    auto last = this->last_update_[city];
    return std::chrono::duration_cast<std::chrono::minutes>(now - last) > this->time_;
}

nlohmann::json Proxy::GetWeather(std::string& city) {
    if (!this->CheckUpdate(city)){
        return this->cache_[city];
    }
    nlohmann::json result = client_.Get(city, update_days_);

    this->cache_[city] = result;
    this->last_update_[city] = std::chrono::steady_clock::now();

    return result;
}

void Proxy::ChangeCountDaysUp() {
    this->update_days_++;
    this->cache_.clear();
}

void Proxy::ChangeCountDaysDown() {
    this->update_days_--;
    this->cache_.clear();
}