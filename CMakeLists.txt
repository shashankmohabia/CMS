cmake_minimum_required(VERSION 3.8)
project(CMS)

set(CMAKE_CXX_STANDARD 14)

include_directories(cmake-build-debug/User cmake-build-debug/Conference)

set(SOURCE_FILES Src/main.cpp Src/Init.cpp Src/Init.h Src/Auth/User.cpp Src/Auth/User.h "Src/Conference Details/Conference.cpp" "Src/Conference Details/Conference.h" Src/Registration/Payment.cpp Src/Registration/Payment.h Src/View/Views.cpp Src/View/Views.h Src/View/Menu.cpp Src/View/Menu.h Src/Database/File.cpp Src/Database/File.h cmake-build-debug/user.txt cmake-build-debug/conference.txt)
add_executable(CMS ${SOURCE_FILES})