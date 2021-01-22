#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>   
#include <stdlib.h> 
#include <time.h> 
#include <algorithm>
#include <utility>
#include "snake.h"
using namespace std;

int main() {
  Snake obj;
  obj.spawnFood();
  obj.spawnSnake();
  obj.spawnMap();
  while(true){
    obj.move();
  }
return 0;
}
