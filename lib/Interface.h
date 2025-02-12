#pragma once

#include <conio.h>
#include <thread>

#include "ftxui/component/component.hpp"
#include "ftxui/component/event.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/component/loop.hpp"

#include "Proxy.h"
#include "ParseJson.h"
class Paint;

class Interface {
public:
    Interface(Proxy& proxy, std::vector<std::string>& cities, uint64_t time);
    void Run();
private:
    std::vector<ftxui::Element> Draw(nlohmann::json weather_city);
    void ChangeCityLeft();
    void ChangeCityRight();
    Proxy proxy_;
    std::vector<std::string> cities_;
    int64_t number_city_ = 0;
    std::chrono::minutes time_;
    ftxui::Element OneLineCity(std::string& city);
    ftxui::Element TwoLineTimeOfDay(int i, nlohmann::json weather_city);
    ftxui::Element LineMorning(int i, nlohmann::json weather_city);
    ftxui::Element LineDay(int i, nlohmann::json weather_city);
    ftxui::Element LineEvening(int i, nlohmann::json weather_city);
    ftxui::Element LineNight(int i, nlohmann::json weather_city);
};

class Paint { // FIXME Use an object that creates complete block to render?
public:
    friend class Interface; // FIXME why?
private:
    enum class WeatherCode {
        kClearSky, // 0 Чистое небо +
        kMainlyClear, // 1 Преимущественно ясно +
        kPartlyCloudy, // 2 Переменная облачность +
        kOvercast, // 3 Пасмурно +
        kFog, // 45 Туман +
        kDepositingRimeFog, // 48 Отложение инейного тумана +
        kLightDrizzle, // 51 Слабая морось +
        kModerateDrizzle, // 53 Умеренная морось +
        kIntensityDrizzle, // 55 Интенсивная морось +
        kLightFreezingDrizzle, // 56 Легкий морозный дождь +
        kIntensityFreezingDrizzle, // 57 Плотный морозный дождь +
        kSlightRain, // 61  Слабый дождь +
        kModerateRain, // 63 Умеренный дождь +
        kIntensityRain, // 65 Сильный дождь +
        kFreezingLightRain, // 66 Легкий ледяной дождь +
        kFreezingIntensityRain, // 67 Интенсивный ледяной дождь +
        kSlightSnow, // 71 Слабый снегопад +
        kModerateSnow, // 73 Умеренный снегопад +
        kIntensitySnow, // 75 Сильный снегопад +
        kSnowGrains, // 77 Снежные зерна +
        kSlightRainShowers, // 80 Слабый ливень +
        kModerateRainShowers, // 81 Умеренный ливень +
        kViolentRainShowers, // 82 Сильный ливень +
        kSlightSnowShowers, // 85 Слабые снежные ливни +
        kHeavySnowShowers, // 86 Сильные снежные ливни +
        kThunderstorm, // 95 Гроза +
        kThunderstormWithSlightHail, // 96 Гроза с небольшим градом
        kThunderstormWithHeavyHail, // 99 Гроза с сильным градом
    };

    static const WeatherCode GetWeatherCode(int code);
    static const std::string GetWeatherName(const WeatherCode& weather_code); // FIXME map::operator[] ?
    static ftxui::Element GetWeatherImage(const WeatherCode& weather_code);
    static std::string GetMonth(const int num);
    static std::string DateParsing(std::string data);
};