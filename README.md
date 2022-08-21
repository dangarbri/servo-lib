# Servo Library for Raspberry Pi Pico
Welcome! This is a fully documented servo library
for the raspberry pi pico using C++.

I haven't found a complete well documented servo
library. Some do come up which I'm sure might even
be better than this library, but don't have enough
documentation to make them easily usable. This library
intends to be fully documented so you can hack in
any changes you need (please make pull requests!)
and easily include it in your own projects.

## Building docs
You can build the documentation with doxygen.
```
cd docs && doxygen && open html/index.html
```

## Interface
Using the servo library is simple, but it does have a few
issues to note. You must be running at 125MHz (the default
clock speed out of the box) and you need to generally be
aware of how PWM works on the pico. Note that each PWM slice
controls 2 pins, they share a counter and clock speed.
So if you're using your own PWM along with this servo library
then make sure they're not both trying to configure the
same slice.

Now that that's out of the way, the code has a super simple
interface. It is C++, because I believe objects are superior
to functional C.

```C++
// Minimal example.
// include the servo library
#include "servo.h"

int main() {
    // Create a servo and specify the pin it will use
    Servo my_servo {0}; // Create a servo on pin 0

    while (true) {
        // Rotate a full 180 degrees
        my_servo.SetRotation(180);
        sleep_ms(1000);
        // Rotate back to starting position
        my_servo.SetRotation(0);
        sleep_ms(1000);
    }
}
```

`SetRotation` is the only function on the servo, as it's the
only thing a servo can do. Internally, creating a servo instance
with `Servo my_servo {0}` will set up the clock divider, counter,
enable PWM, and set the rotation to position 0. It initializes
the servo. Then you simply use `SetRotation` to rotate the servo
as needed.

Use the code above to test the library with your servo!

## Installation
Including this library in your project is simple.

1. Clone the library into your repository. Using submodules is the simplest way to make sure
   all your repository users will have the same library you're using.

2. Update your `CMakeLists.txt' to point to the library
```cmake
include_directories(
    ... # your include directories
    servo-lib/include # Add servo-lib's include directory to get "servo.h"
)
# Add the subdirectory so the library gets compiled
add_subdirectory(servo-lib)
# include it in your link libraries
target_link_libraries(your_program pico_stdlib servo-lib)
```

That's it. Have fun!

