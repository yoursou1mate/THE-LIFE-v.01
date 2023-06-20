//
//  main.cpp
//  THE LIFE_V_0.1
//
//  Created by a1ex on 6/20/23.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <cstdlib>
#include <ctime>


const int width = 20;
const int height = 20;

using Space = int[width][height];

int get_x (int i){
  return (width  + i) % width;
}

int get_y (int j){
  return (height  + j) % height;
}

void fill_rand(Space space){
  std::srand(std::time(nullptr));
for (int i = 0; i < width; ++i){
  for (int j = 0; j  < height; ++j){
    if (rand() % 10  == 0) {
      space[i][j] = 1;
    } else {
      space[i][j]  = 0;
    }
  }
 }
}


  void printSpace(const Space space){
    for (int i = 0; i < width; ++i){
  for (int j = 0; j  < height; ++j){
    if (space[i][j] == 1) {
      std::cout << "*";
    } else {
      std::cout << "-";
    }
    }
      std::cout << '\n';
  }
}


void copy (Space  src, Space dst){
  for (int i = 0; i < width; ++i){
  for (int j = 0; j  < height; ++j){
    dst[i][j] =  src[i][j];
    }
  }
}


void nextStep (Space space){
  Space prev;
  copy(space, prev);
  for (int i = 0; i < width; ++i){
  for (int j = 0; j  < height; ++j){
    int countNeib = 0;
    countNeib += prev[get_x(i-1)][get_y(j-1)];
    countNeib += prev[get_x(i-1)][get_y(j)];
    countNeib += prev[get_x(i-1)][get_y(j+1)];
    countNeib += prev[get_x(i)][get_y(j-1)];
    countNeib += prev[get_x(i)][get_y(j+1)];
    countNeib += prev[get_x(i+1)][get_y(j-1)];
    countNeib += prev[get_x(i+1)][get_y(j)];
    countNeib += prev[get_x(i+1)][get_y(j+1)];

    if ((prev[i][j] == 0) && (countNeib == 3)){
      space[i][j] = 1;
    } else if ((countNeib <  2) || (countNeib > 3)) {
      space[i][j] = 0;
    }
}
  }
}


int main () {

std::cout <<  "Welcome to THE  LIFE!" << std::endl;

  Space space;

  fill_rand(space);
  
  

  for (int k = 0; k < 100; ++k){
    printSpace(space);
    nextStep(space);
    sleep(1);
    system("clear");
  }

  return 0;
}
