include_directories(../include)
add_library(servo-lib
    servo.cpp
    pwm.cpp
)

target_link_libraries(servo-lib pico_stdlib hardware_pwm)

