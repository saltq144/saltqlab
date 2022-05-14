# saltqlab

## Quick start
### Compiling
Running the following will compile the code into ./build/saltqlab
```
g++ --std=c++17 ./src/saltqlab.cpp ./build/wxdisk.o -o ./build/saltqlab -Wall -Wextra -O2 -lstdc++fs
```
If that doesn't work, then running the following before that should help:  
```
 g++ --std=c++17 -c ./src/wxdisk.cpp -o ./build/wxdisk.o -Wall -Wextra -O2 -lstdc++fs
```
If that doesn't work I have no idea why. Please also note the file extension of the output file.