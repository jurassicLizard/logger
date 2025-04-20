# jlizard logger

A simple C++ logging utility I created for my personal projects. This is nothing fancy - just a straightforward logging implementation that does what I need without the complexity of larger logging frameworks.

## Why another logger?

Yes, I know there are plenty of logging libraries out there. Many are excellent but often come with more features than I need. This minimal implementation gives me just enough functionality for day-to-day development without the overhead.

## Usage

```cpp
#include "logger.h"

using namespace jlizard::logger;

int main() {
    info("Application started");
    
    // Do something important...
    
    warn("This operation might be slow");
    
    // If something goes wrong
    error("Failed to process data");
    
    return 0;
}
```

## Integration 

``` cmake
add_subdirectory(path/to/jlizard-logger)
target_link_libraries(your_target PRIVATE jlizard::logger)
```

## Tests
The project includes a test suite that can be run using CTest. Enable testing in your CMake build to run them:

``` bash
mkdir build && cd build
cmake -DBUILD_TESTING=ON ..
make
ctest
```

## License
MIT License — See [LICENSE.md](LICENSE.md) for details.
