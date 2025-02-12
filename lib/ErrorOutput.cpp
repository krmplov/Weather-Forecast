#include "ErrorOutput.h"

void ErrorOutput(const Errors& error){
    switch (error) {
        case Errors::kErrorConfig:
            std::cerr << "You didn't enter the config file";
            break;
        case Errors::kErrorFileNotFound:
            std::cerr << "This file not found";
            break;
        case Errors::kErrorListCities:
            std::cerr << "The file doesn't contain a list of cities";
            break;
        case Errors::kErrorApiKeys:
            std::cerr << "The file doesn't contain an api key";
            break;
        case Errors::kErrorTime:
            std::cerr << "The file doesn't contain information about the update time";
            break;
        case Errors::kErrorCountDays:
            std::cerr << "The file doesn't contain information about the count days";
            break;
        case Errors::kErrorCity:
            std::cerr << "The requested resource wasn't found";
            break;
        case Errors::kErrorNegative:
            std::cerr << "You entered a negative number";
    }
    exit(1);
}