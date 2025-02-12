#include "Interface.h"

const Paint::WeatherCode Paint::GetWeatherCode(int code) {
    switch (code) {
        case 0:
            return WeatherCode::kClearSky;
        case 1:
            return WeatherCode::kMainlyClear;
        case 2:
            return WeatherCode::kPartlyCloudy;
        case 3:
            return WeatherCode::kOvercast;
        case 45:
            return WeatherCode::kFog;
        case 48:
            return WeatherCode::kDepositingRimeFog;
        case 51:
            return WeatherCode::kLightDrizzle;
        case 53:
            return WeatherCode::kModerateDrizzle;
        case 55:
            return WeatherCode::kIntensityDrizzle;
        case 56:
            return WeatherCode::kLightFreezingDrizzle;
        case 57:
            return WeatherCode::kIntensityFreezingDrizzle;
        case 61:
            return WeatherCode::kSlightRain;
        case 63:
            return WeatherCode::kModerateRain;
        case 65:
            return WeatherCode::kIntensityRain;
        case 66:
            return WeatherCode::kFreezingLightRain;
        case 67:
            return WeatherCode::kFreezingIntensityRain;
        case 71:
            return WeatherCode::kSlightSnow;
        case 73:
            return WeatherCode::kModerateSnow;
        case 75:
            return WeatherCode::kIntensitySnow;
        case 77:
            return WeatherCode::kSnowGrains;
        case 80:
            return WeatherCode::kSlightRainShowers;
        case 81:
            return WeatherCode::kModerateRainShowers;
        case 82:
            return WeatherCode::kViolentRainShowers;
        case 85:
            return WeatherCode::kSlightSnowShowers;
        case 86:
            return WeatherCode::kHeavySnowShowers;
        case 95:
            return WeatherCode::kThunderstorm;
        case 96:
            return WeatherCode::kThunderstormWithSlightHail;
        case 99:
            return WeatherCode::kThunderstormWithHeavyHail;
    }
}

const std::string Paint::GetWeatherName(const Paint::WeatherCode& weather_code) {
    switch (weather_code) {
        case WeatherCode::kClearSky:
            return "Чистое небо";
        case WeatherCode::kMainlyClear:
            return "Преимущественно ясно";
        case WeatherCode::kPartlyCloudy:
            return "Переменная облачность";
        case WeatherCode::kOvercast:
            return "Пасмурно";
        case WeatherCode::kFog:
            return "Туман";
        case WeatherCode::kDepositingRimeFog:
            return "Отложение инейного тумана";
        case WeatherCode::kLightDrizzle:
            return "Слабая морось";
        case WeatherCode::kModerateDrizzle:
            return "Умеренная морось";
        case WeatherCode::kIntensityDrizzle:
            return "Интенсивная морось";
        case WeatherCode::kLightFreezingDrizzle:
            return "Легкий морозный дождь";
        case WeatherCode::kIntensityFreezingDrizzle:
            return "Плотный морозный дождь";
        case WeatherCode::kSlightRain:
            return "Слабый дождь";
        case WeatherCode::kModerateRain:
            return "Умеренный дождь";
        case WeatherCode::kIntensityRain:
            return "Сильный дождь";
        case WeatherCode::kFreezingLightRain:
            return "Легкий ледяной дождь";
        case WeatherCode::kFreezingIntensityRain:
            return "Интенсивный ледяной дождь";
        case WeatherCode::kSlightSnow:
            return "Слабый снегопад";
        case WeatherCode::kModerateSnow:
            return "Умеренный снегопад";
        case WeatherCode::kIntensitySnow:
            return "Сильный снегопад";
        case WeatherCode::kSnowGrains:
            return "Снежные зерна";
        case WeatherCode::kSlightRainShowers:
            return "Слабый ливень";
        case WeatherCode::kModerateRainShowers:
            return "Умеренный ливень";
        case WeatherCode::kViolentRainShowers:
            return "Сильный ливень";
        case WeatherCode::kSlightSnowShowers:
            return "Слабые снежные ливни";
        case WeatherCode::kHeavySnowShowers:
            return "Сильные снежные ливни";
        case WeatherCode::kThunderstorm:
            return "Гроза";
        case WeatherCode::kThunderstormWithSlightHail:
            return "Гроза с небольшим градом";
        case WeatherCode::kThunderstormWithHeavyHail:
            return "Гроза с сильным градом";
    }
}


ftxui::Element Paint::GetWeatherImage(const Paint::WeatherCode& weather_code) {
    switch (weather_code) {
        case WeatherCode::kClearSky:
        case WeatherCode::kMainlyClear:
            return ftxui::vbox({ftxui::text("   \\    /        ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("   . —— .         ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("  / \"  \" \\       ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("——\\  ︺  /——      ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("   ` —— '        ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("   /    \\        ") | ftxui::color(ftxui::Color::White)
                               });
        case WeatherCode::kPartlyCloudy:
            return ftxui::vbox({ftxui::text("   \\    /        ") | ftxui::color(ftxui::Color::White),
                                ftxui::text(" __/\" \". – .     ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("   \\ _( ' ' ).   ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("   / (_ _⏝_(_)    ") | ftxui::color(ftxui::Color::White),
                               });
        case WeatherCode::kOvercast:
            return ftxui::vbox({ftxui::text("   . – .        ") | ftxui::color(ftxui::Color::White),
                                ftxui::text(" .(' _ ').      ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("(_ _ . _)_)     ") | ftxui::color(ftxui::Color::White),
                               });
        case WeatherCode::kFog:
        case WeatherCode::kDepositingRimeFog:
            return ftxui::vbox({ftxui::text("_ – _ – _        ") | ftxui::color(ftxui::Color::White),
                                ftxui::text(" _ – _ –         ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("_ – _ – _        ") | ftxui::color(ftxui::Color::White),
                               });
        case WeatherCode::kLightDrizzle:
        case WeatherCode::kModerateDrizzle:
        case WeatherCode::kIntensityDrizzle:
        case WeatherCode::kSlightRain:
        case WeatherCode::kModerateRain:
        case WeatherCode::kIntensityRain:
        case WeatherCode::kSlightRainShowers:
        case WeatherCode::kModerateRainShowers:
        case WeatherCode::kViolentRainShowers:
            return ftxui::vbox({ftxui::text("      .–.        ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("     (/_\\).      ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("    (_ _(_)      ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("    ' ' ' '      ") | ftxui::color(ftxui::Color::Blue),
                                ftxui::text("    ' ' ' '      ") | ftxui::color(ftxui::Color::Blue),
                               });
        case WeatherCode::kFreezingLightRain:
        case WeatherCode::kLightFreezingDrizzle:
        case WeatherCode::kIntensityFreezingDrizzle:
        case WeatherCode::kFreezingIntensityRain:
        case WeatherCode::kSlightSnowShowers:
        case WeatherCode::kHeavySnowShowers:
            return ftxui::vbox({ftxui::text("      .–.        ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("     (/_\\).      ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("    (_ _(_)      ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("    ' * ' *      ") | ftxui::color(ftxui::Color::Blue),
                                ftxui::text("    ' * ' *      ") | ftxui::color(ftxui::Color::Blue),
                               });
        case WeatherCode::kSlightSnow:
        case WeatherCode::kModerateSnow:
        case WeatherCode::kIntensitySnow:
        case WeatherCode::kSnowGrains:
            return ftxui::vbox({ftxui::text("      .–.        ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("     (/_\\).      ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("    (_ _(_)      ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("    * * * *      ") | ftxui::color(ftxui::Color::Blue),
                                ftxui::text("    * * * *      ") | ftxui::color(ftxui::Color::Blue),
                               });
        case WeatherCode::kThunderstorm:
            return ftxui::vbox({ftxui::text("       .–.       ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("     (\\/ ).      ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("    (_^( _ )     ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("      //         ") | ftxui::color(ftxui::Color::Blue),
                                ftxui::text("      \\\\         ") | ftxui::color(ftxui::Color::Blue),
                               });
        case WeatherCode::kThunderstormWithSlightHail:
        case WeatherCode::kThunderstormWithHeavyHail:
            return ftxui::vbox({ftxui::text("       .–.       ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("     (\\/ ).      ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("    (_^( _ )     ") | ftxui::color(ftxui::Color::White),
                                ftxui::text("     ' // '      ") | ftxui::color(ftxui::Color::Blue),
                                ftxui::text("     ' \\\\ '      ") | ftxui::color(ftxui::Color::Blue),
                               });
    }
}

std::string Paint::GetMonth(const int num) {
    switch (num) {
        case 1:
            return "Январь";
        case 2:
            return "Февраль";
        case 3:
            return "Март";
        case 4:
            return "Апрель";
        case 5:
            return "Май";
        case 6:
            return "Июнь";
        case 7:
            return "Июль";
        case 8:
            return "Август";
        case 9:
            return "Сентябрь";
        case 10:
            return "Октябрь";
        case 11:
            return "Ноябрь";
        case 12:
            return "Декабрь";
    }
}

std::string Paint::DateParsing(std::string data) {
    std::string year = data.substr(1, 4);
    std::string month = data.substr(6, 7);
    std::string day = data.substr(9, 10);
    day = day.substr(0, 2);
    month = month.substr(0, 2);
    if (month[0] == '0') {
        month = month[1];
    }
    if (day[0] == '0') {
        day = day[1];
    }
    month = GetMonth(std::stoi(month));
    return (day + " " + month + " " + year);
}

ftxui::Element Interface::OneLineCity(std::string& city) {
    std::string res = "Город: " + city;
    return ftxui::hbox({ftxui::center(ftxui::text(res)) | ftxui::underlined | ftxui::border});
}

ftxui::Element Interface::TwoLineTimeOfDay(int i, nlohmann::json weather_city) {
    std::string data = std::string((weather_city["hourly"]["time"][i]).dump(1));
    std::string res = Paint::DateParsing(data);
    return ftxui::vbox({ftxui::center(
            ftxui::hbox({ftxui::text(res)})),
                        ftxui::separator(),
                        ftxui::hbox({ftxui::center(ftxui::text("Утро")) | ftxui::flex | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 40),
                                     ftxui::separator(),
                                     ftxui::center(ftxui::text("День")) | ftxui::flex | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 40),
                                     ftxui::separator(),
                                     ftxui::center(ftxui::text("Вечер")) | ftxui::flex | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 40),
                                     ftxui::separator(),
                                     ftxui::center(ftxui::text("Ночь")) | ftxui::flex | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 40), ftxui::separator()}) | ftxui::bold | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 160), ftxui::separator()
                        });
}

ftxui::Element Interface::LineMorning(int i, nlohmann::json weather_city) {
    ftxui::Element weather_image_ = ftxui::hbox({Paint::GetWeatherImage(Paint::GetWeatherCode(
            std::stoi((weather_city["hourly"]["weather_code"][i +
                                                              6]).dump())))});
    ftxui::Element weather_name_ = ftxui::hbox({ftxui::center(ftxui::text(Paint::GetWeatherName(Paint::GetWeatherCode(
            std::stoi((weather_city["hourly"]["weather_code"][i +
                                                              6]).dump())))))});

    ftxui::Element temperature_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["temperature_2m"][i + 6]).dump() + " (" +
            (weather_city["hourly"]["apparent_temperature"][i + 6]).dump() +
            ") " + (weather_city["hourly_units"]["apparent_temperature"]).dump()))});

    ftxui::Element wind_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["wind_speed_10m"][i + 6]).dump() + " " +
            (weather_city["hourly_units"]["wind_speed_10m"]).dump()))});

    ftxui::Element visibility_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["visibility"][i + 6]).dump() + " " +
            (weather_city["hourly_units"]["visibility"]).dump())) |
                                              ftxui::flex,
                                              ftxui::separator(), ftxui::center(ftxui::text(
                    (weather_city["hourly"]["wind_direction_10m"][i +
                                                                  6]).dump() +
                    " " +
                    (weather_city["hourly_units"]["wind_direction_10m"]).dump())) |
                                                                  ftxui::flex});

    ftxui::Element precipitation_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["relative_humidity_2m"][i + 6]).dump() +
            " " + (weather_city["hourly_units"]["relative_humidity_2m"]).dump())) |
                                                 ftxui::flex,
                                                 ftxui::center(ftxui::text(
                    (weather_city["hourly"]["precipitation"][i + 6]).dump() +
                    " " + (weather_city["hourly_units"]["precipitation"]).dump())) |
                                                                     ftxui::flex});

    return ftxui::hbox({weather_image_ | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20), ftxui::vbox({weather_name_ | ftxui::flex, temperature_ | ftxui::flex,
                                                                   wind_ | ftxui::flex, visibility_| ftxui::flex, precipitation_ | ftxui::flex}) | ftxui::flex | ftxui::bold | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20), ftxui::separator()});


}

ftxui::Element Interface::LineDay(int i, nlohmann::json weather_city) {
    ftxui::Element weather_image_ = ftxui::hbox({Paint::GetWeatherImage(Paint::GetWeatherCode(
            std::stoi((weather_city["hourly"]["weather_code"][i +
                                                              13]).dump())))});
    ftxui::Element weather_name_ = ftxui::hbox({ftxui::center(ftxui::text(Paint::GetWeatherName(Paint::GetWeatherCode(
            std::stoi((weather_city["hourly"]["weather_code"][i +
                                                              13]).dump())))))});

    ftxui::Element temperature_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["temperature_2m"][i + 13]).dump() + " (" +
            (weather_city["hourly"]["apparent_temperature"][i + 13]).dump() +
            ") " + (weather_city["hourly_units"]["apparent_temperature"]).dump()))});

    ftxui::Element wind_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["wind_speed_10m"][i + 13]).dump() + " " +
            (weather_city["hourly_units"]["wind_speed_10m"]).dump()))});

    ftxui::Element visibility_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["visibility"][i + 13]).dump() + " " +
            (weather_city["hourly_units"]["visibility"]).dump())) |
                                              ftxui::flex,
                                              ftxui::separator(), ftxui::center(ftxui::text(
                    (weather_city["hourly"]["wind_direction_10m"][i +
                                                                  13]).dump() +
                    " " +
                    (weather_city["hourly_units"]["wind_direction_10m"]).dump())) |
                                                                  ftxui::flex});

    ftxui::Element precipitation_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["relative_humidity_2m"][i + 13]).dump() +
            " " + (weather_city["hourly_units"]["relative_humidity_2m"]).dump())) |
                                                 ftxui::flex,
                                                 ftxui::center(ftxui::text(
                    (weather_city["hourly"]["precipitation"][i + 13]).dump() +
                    " " + (weather_city["hourly_units"]["precipitation"]).dump())) |
                                                                     ftxui::flex});

    return ftxui::hbox({weather_image_ | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20), ftxui::vbox({weather_name_ | ftxui::flex, temperature_ | ftxui::flex,
                                                                   wind_ | ftxui::flex, visibility_| ftxui::flex, precipitation_ | ftxui::flex}) | ftxui::flex | ftxui::bold | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20), ftxui::separator()});
}

ftxui::Element Interface::LineEvening(int i, nlohmann::json weather_city) {
    ftxui::Element weather_image_ = ftxui::hbox({Paint::GetWeatherImage(Paint::GetWeatherCode(
            std::stoi((weather_city["hourly"]["weather_code"][i +
                                                              18]).dump())))});
    ftxui::Element weather_name_ = ftxui::hbox({ftxui::center(ftxui::text(Paint::GetWeatherName(Paint::GetWeatherCode(
            std::stoi((weather_city["hourly"]["weather_code"][i +
                                                              18]).dump())))))});

    ftxui::Element temperature_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["temperature_2m"][i + 18]).dump() + " (" +
            (weather_city["hourly"]["apparent_temperature"][i + 18]).dump() +
            ") " + (weather_city["hourly_units"]["apparent_temperature"]).dump()))});

    ftxui::Element wind_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["wind_speed_10m"][i + 18]).dump() + " " +
            (weather_city["hourly_units"]["wind_speed_10m"]).dump()))});

    ftxui::Element visibility_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["visibility"][i + 18]).dump() + " " +
            (weather_city["hourly_units"]["visibility"]).dump())) |
                                              ftxui::flex,
                                              ftxui::separator(), ftxui::center(ftxui::text(
                    (weather_city["hourly"]["wind_direction_10m"][i +
                                                                  18]).dump() +
                    " " +
                    (weather_city["hourly_units"]["wind_direction_10m"]).dump())) |
                                                                  ftxui::flex});

    ftxui::Element precipitation_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["relative_humidity_2m"][i + 18]).dump() +
            " " + (weather_city["hourly_units"]["relative_humidity_2m"]).dump())) |
                                                 ftxui::flex,
                                                 ftxui::center(ftxui::text(
                    (weather_city["hourly"]["precipitation"][i + 18]).dump() +
                    " " + (weather_city["hourly_units"]["precipitation"]).dump())) |
                                                                     ftxui::flex});

    return ftxui::hbox({weather_image_ | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20), ftxui::vbox({weather_name_ | ftxui::flex, temperature_ | ftxui::flex,
                                                                   wind_ | ftxui::flex, visibility_| ftxui::flex, precipitation_ | ftxui::flex}) | ftxui::flex | ftxui::bold | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20), ftxui::separator()});
}

ftxui::Element Interface::LineNight(int i, nlohmann::json weather_city) {
    ftxui::Element weather_image_ = ftxui::hbox({Paint::GetWeatherImage(Paint::GetWeatherCode(
            std::stoi((weather_city["hourly"]["weather_code"][i +
                                                              23]).dump())))});
    ftxui::Element weather_name_ = ftxui::hbox({ftxui::center(ftxui::text(Paint::GetWeatherName(Paint::GetWeatherCode(
            std::stoi((weather_city["hourly"]["weather_code"][i +
                                                              23]).dump())))))});

    ftxui::Element temperature_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["temperature_2m"][i + 23]).dump() + " (" +
            (weather_city["hourly"]["apparent_temperature"][i + 23]).dump() +
            ") " + (weather_city["hourly_units"]["apparent_temperature"]).dump()))});

    ftxui::Element wind_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["wind_speed_10m"][i + 23]).dump() + " " +
            (weather_city["hourly_units"]["wind_speed_10m"]).dump()))});

    ftxui::Element visibility_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["visibility"][i + 23]).dump() + " " +
            (weather_city["hourly_units"]["visibility"]).dump())) |
                                              ftxui::flex,
                                              ftxui::separator(), ftxui::center(ftxui::text(
                    (weather_city["hourly"]["wind_direction_10m"][i +
                                                                  23]).dump() +
                    " " +
                    (weather_city["hourly_units"]["wind_direction_10m"]).dump())) |
                                                                  ftxui::flex});

    ftxui::Element precipitation_ = ftxui::hbox({ftxui::center(ftxui::text(
            (weather_city["hourly"]["relative_humidity_2m"][i + 23]).dump() +
            " " + (weather_city["hourly_units"]["relative_humidity_2m"]).dump())) |
                                                 ftxui::flex,
                                                 ftxui::center(ftxui::text(
                    (weather_city["hourly"]["precipitation"][i + 23]).dump() +
                    " " + (weather_city["hourly_units"]["precipitation"]).dump())) |
                                                                     ftxui::flex});

    return ftxui::hbox({weather_image_ | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20), ftxui::vbox({weather_name_ | ftxui::flex, temperature_ | ftxui::flex,
                                                                   wind_ | ftxui::flex, visibility_| ftxui::flex, precipitation_ | ftxui::flex}) | ftxui::flex | ftxui::bold | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 20), ftxui::separator()});
}

Interface::Interface(Proxy& proxy, std::vector<std::string>& cities, uint64_t time)
    : proxy_(proxy), cities_(cities), time_(time) {};

void Interface::ChangeCityRight() {
    this->number_city_++;
    if (this->number_city_ == this->cities_.size()) {
        this->number_city_ = 0;
    }
}

void Interface::ChangeCityLeft() {
    this->number_city_--;

    if (this->number_city_ < 0) {
        this->number_city_ = this->cities_.size() - 1;
    }
}

std::vector<ftxui::Element> Interface::Draw(nlohmann::json weather_city) {
    std::vector<ftxui::Element> documents;
    documents.push_back(this->OneLineCity(this->cities_[this->number_city_]));
    for (int i = 0; i < weather_city["hourly"]["time"].size(); i = i + 24) {
        auto document = ftxui::hbox({ftxui::vbox({this->TwoLineTimeOfDay(i, weather_city) | ftxui::flex | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 160),
                                     ftxui::hbox({ this->LineMorning(i, weather_city) | ftxui::flex | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 40), ftxui::separator(),
                                                  this->LineDay(i, weather_city) | ftxui::flex | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 40), ftxui::separator(),
                                                  this->LineEvening(i, weather_city) | ftxui::flex | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 40), ftxui::separator(),
                                                  this->LineNight(i, weather_city) | ftxui::flex | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 40)})}) | ftxui::border | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 160)});

        documents.push_back(document);

    }

    return documents;
}

void Interface::Run() {
    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();
    auto component = ftxui::Renderer([&] {
        return ftxui::vbox(this->Draw(this->proxy_.GetWeather(this->cities_[this->number_city_])));
    });
    component |= ftxui::CatchEvent( [&](const ftxui::Event& event) {
        if (event == ftxui::Event::Escape) { // TODO return true if event handled (FTXUI rule)
            screen.ExitLoopClosure()();
        } else if (event.input() == "n") {
            this->ChangeCityRight();
        } else if (event.input() == "p") {
            this->ChangeCityLeft();
        } else if (event.input() == "+") {
            this->proxy_.ChangeCountDaysUp();
        } else if (event.input() == "-") {
            this->proxy_.ChangeCountDaysDown();
        }
        return false;
    });
    ftxui::Loop loop(&screen, component);
    auto last_time = std::chrono::steady_clock::now();
    while (!loop.HasQuitted()) {
        auto cur_time = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_time) > this->time_) { // FIXME wasting processor time?
            last_time = cur_time;
            screen.Post(ftxui::Event::Custom);
        }
        loop.RunOnce();
    }
}
