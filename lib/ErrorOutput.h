#pragma once

#include <iostream>

enum class Errors {
    kErrorConfig,
    kErrorFileNotFound,
    kErrorListCities,
    kErrorApiKeys,
    kErrorTime,
    kErrorCountDays,
    kErrorCity,
    kErrorNegative,
};

void ErrorOutput(const Errors& error);