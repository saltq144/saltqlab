# Compiling

## g++

### Required libraries

```
g++ --std=c++17 -c ./src/wxdisk.cpp -o ./build/wxdisk.o -Wall -Wextra -O2 -lstdc++fs
```

### Compiling the actual app.

```
g++ --std=c++17 ./src/saltqlab.cpp ./build/wxdisk.o -o ./build/saltqlab -Wall -Wextra -O2 -lstdc++fs
```

## Debugging

### Paths

Those commands assume the source code is in ./src, using this on windows requires that all ```/```s are replaced by ```\```s.

### Experimental library problems

Replacing ```#include <experimental/filesystem>``` with ```#include <filesystem>``` and replacing ```std::experimental::filesystem::create_directories(path);``` with ```std::filesystem::create_directories(path);``` may help.

### g++ version

This program requires C++17 compatibility. This is due to the ```std::filesystem::create_directories()``` function used in ```./src/wxdisk.cpp```.