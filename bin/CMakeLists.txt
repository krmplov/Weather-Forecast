add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ErrorOutput)
target_link_libraries(${PROJECT_NAME} PRIVATE HttpClient)
target_link_libraries(${PROJECT_NAME} PRIVATE Interface)
target_link_libraries(${PROJECT_NAME} PRIVATE ParseJson)
target_link_libraries(${PROJECT_NAME} PRIVATE Proxy)

target_link_libraries(${PROJECT_NAME} PRIVATE cpr::cpr)

target_link_libraries(${PROJECT_NAME}
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
)

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})