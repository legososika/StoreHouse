cmake_minimum_required(VERSION 3.23)
project(PrakSklad)

set(CMAKE_CXX_STANDARD 14)

add_executable(PrakSklad main.cpp Button.h ItemDescription.h Controller.h Controller.cpp
        ITimeController.cpp ITimeController.h ProductInfo.cpp ProductInfo.h ShopAssistant.cpp ShopAssistant.h
        Storage.cpp Storage.h Shop.h Shop.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(PrakSklad sfml-graphics sfml-audio)