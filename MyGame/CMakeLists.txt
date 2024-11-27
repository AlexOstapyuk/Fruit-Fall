add_executable(MyGame TheGame.cpp)

include_directories(../Power/include)

target_link_libraries(MyGame Power)