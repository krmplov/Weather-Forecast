add_library(ErrorOutput ErrorOutput.cpp)
add_library(HttpClient HttpClient.cpp)
add_library(Interface Interface.cpp)
add_library(ParseJson ParseJson.cpp)
add_library(Proxy Proxy.cpp)

target_link_libraries(HttpClient PRIVATE cpr::cpr)
target_link_libraries(HttpClient PRIVATE nlohmann_json::nlohmann_json)

target_link_libraries(ParseJson PRIVATE cpr::cpr)
target_link_libraries(ParseJson PRIVATE nlohmann_json::nlohmann_json)

target_link_libraries(Proxy PRIVATE cpr::cpr)
target_link_libraries(Proxy PRIVATE nlohmann_json::nlohmann_json)

target_link_libraries(Interface PRIVATE cpr::cpr)
target_link_libraries(Interface PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(Interface
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component)

target_link_libraries(ParseJson PRIVATE ErrorOutput)
target_link_libraries(HttpClient PRIVATE ErrorOutput)
target_link_libraries(Interface PRIVATE ErrorOutput)
target_link_libraries(Proxy PRIVATE ErrorOutput)

target_link_libraries(Proxy PRIVATE HttpClient)
target_link_libraries(Interface PRIVATE Proxy)
