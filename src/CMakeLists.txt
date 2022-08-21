add_library(servo-lib
    servo.cpp
)

target_link_libraries(servo-lib pico_stdlib hardware_pwm)

