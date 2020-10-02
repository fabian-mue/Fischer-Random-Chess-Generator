# Fischer-Random-Chess-Generator

## Goal

The aim of this project is to build a generator which creates the starting positions of the pieces for the fischer random chess game variation. The starting positions are randomly generated. In total there are 960 unique possible starting positions. 
Check the following link to get more detailed information regarding to the "Fischer random chess": https://en.wikipedia.org/wiki/Fischer_random_chess.



## Approach

The implementation shall be done in C++.

In the first step a generator shall be implemented which outputs a 2D-Array representing the randomly generated starting positions of the chess board.

In the next iteration an attractive graphical representation of the computed positions shall be established.



## Running the Code

Requirements: 

- minimum CMake version: 3.5
  - All OSes: https://cmake.org/install/

- make 4.1
  - Linux: make is installed by default on most Linux distros
  - Mac: install Xcode command line tools to get make (https://developer.apple.com/xcode/features/)
  - Windows: http://gnuwin32.sourceforge.net/packages/make.htm

- gcc/g++: 5.4
  - Linux: gcc / g++ is installed by default on most Linux distros
  - Mac: same deal as make (https://developer.apple.com/xcode/features/)
  - Windows: recommend using MinGW (http://www.mingw.org/)

As soon as the required setup is ready the code can be compiled and the Fischer-Random-Chess-Generator is generated. To apply this, only the resulting binary file "FischerGen" needs to be executed. 
To compile and execute the final binary, perform the following steps from the project top directory:

1. mkdir build & cd build
2. cmake ..
3. make
4. ./FischerGen