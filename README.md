# Stub project for C++
## Synopsis
Short stub project for C++ using CMake (http://www.cmake.org/) and Googletest 
(https://code.google.com/p/googletest/). 
## Layout
`include/` put header files here.

`src/` put the application's source code here.

`test/` put the unit tests here.

## Usage
In the root directory:

```
mkdir build # out of source build location
cmake ..
make
src/<name_of_executable> # run the executable
```

for tests:

```
mkdir build
cmake -Dtest=ON ..
make
make test # using CTest interface
ctest -VV # using CTest interface showing googletest output
test/unittest # run the text executable with the unit tests directly
```