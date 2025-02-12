#include <iostream>

#include "lib/ErrorOutput.h"
#include "lib/HttpClient.h"
#include "lib/Interface.h"
#include "lib/ParseJson.h"
#include "lib/Proxy.h"


int main(int argc, char** argv) {
    if (argc != 2) {
        ErrorOutput(Errors::kErrorConfig);
    }
    std::string config_path = argv[1];
    ParseJson parseJson(config_path);
    HttpCoordinates httpCoordinates(parseJson.GetApi());
    httpCoordinates.Get(parseJson.GetCities());
    HttpWeather httpWeather(httpCoordinates.GetCity(), parseJson.GetCountDays());
    for (size_t i = 0; i < parseJson.GetCities().size(); ++i){
        httpWeather.Get(parseJson.GetCities()[i]);
    }
    Proxy proxy(httpWeather, parseJson.GetTime());
    Interface Myinterface(proxy, parseJson.GetCities(), parseJson.GetTime());
    Myinterface.Run();
    return 0;
}