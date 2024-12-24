add_executable(MyGame TheGame.cpp Counter.h Counter.cpp FruitFall.h FruitFall.cpp)

include_directories(../Power/include)

target_link_libraries(MyGame Power)