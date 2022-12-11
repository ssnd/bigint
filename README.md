# bigint
A simple library that implements simple operations with big integers (e.g. integers that cannot fit in the standart C++ types). 
A basic command line interface is also available along with the bigint library.

Supported operations: `+` , `-`


## Getting started
### Pre-requisites
- C++17
- CMake >= 3.0

### Building the project
Build the project using CMake:  
`mkdir build && cd build && cmake .. && make`

## Launching the CLI
Execute the `./build/main` script from the project root.

## Tests
Simple unit tests that handle the most common inputs & corner cases are located in the `bigint/tests` directory.

In order to launch the tests, you'll have to build the project as described in the `Building the project` section and then launch one of the executables located in the build/bigint/tests directory. The unit tests are split into different suites depending on what part of the functionality is tested, each suite has its own binary in the `build/bigint/tests` folder. 

The `build/bigint/tests/run_all` executable launches all available tests.

