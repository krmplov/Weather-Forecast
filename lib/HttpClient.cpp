#include "HttpClient.h"

HttpCoordinates::HttpCoordinates(std::string& api_key) {
    this->api_key_ = api_key;
}

void HttpCoordinates::Get(std::vector<std::string>& cities) {
    for (size_t i = 0; i < cities.size(); ++i){
        cpr::Response r = cpr::Get(cpr::Url{this->kUrl_}, cpr::Parameters{{"name", cities[i]}},
                                   cpr::Header{{"X-Api-Key", this->api_key_}});
        if (r.status_code != 200){
            ErrorOutput(Errors::kErrorCity);
        }
        nlohmann::json file = nlohmann::json::parse(r.text.substr(1, r.text.size() - 2));
        this->cities_coordinates_[cities[i]].first = file["latitude"].dump();
        this->cities_coordinates_[cities[i]].second = file["longitude"].dump();
    }
}

std::unordered_map<std::string, std::pair<std::string, std::string>>& HttpCoordinates::GetCity() {
    return this->cities_coordinates_;
}

HttpWeather::HttpWeather(std::unordered_map<std::string, std::pair<std::string, std::string>>& coordinates, uint64_t count_days) {
    this->coordinates_ = coordinates;
    this->count_days_ = count_days;
}

nlohmann::json HttpWeather::Get(std::string& city, int64_t update) {
    uint64_t res;
    if ((this->count_days_ + update) < 1) {
         res = 1;
    } else {
        res = (this->count_days_ + update);
    }
    cpr::Response r = cpr::Get(cpr::Url{this->kUrl_},
                               cpr::Parameters{{"latitude", this->coordinates_[city].first},
                                               {"longitude", this->coordinates_[city].second},
                                               {"hourly",        "wind_speed_10m"},
                                               {"hourly",        "wind_direction_10m"},
                                               {"hourly",        "weather_code"},
                                               {"hourly",        "temperature_2m"},
                                               {"hourly",        "apparent_temperature"},
                                               {"hourly",        "relative_humidity_2m"},
                                               {"hourly",        "precipitation"},
                                               {"hourly",        "visibility"},
                                               {"forecast_days", std::to_string(res)}});

    if (r.status_code != 200){
        ErrorOutput(Errors::kErrorCity);
    }
    nlohmann::json file = nlohmann::json::parse(r.text);

    return file;
}