#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>   
#include <stdlib.h> 
#include <time.h> 
#include <algorithm>
#include <utility>
using namespace std;

class Snake{
  public: 
    char snk ='.';
    vector< pair <int,int> > snake; 
    char board[10][10];
    pair<int,int> foodCoor=make_pair(rand()%9+1,rand()%9+1);
    int snakeSize=1;
    char food = '@';

  public:
    void adjust();
    void eat();
    void move();
    void spawnFood();
    void spawnSnake();
    void spawnMap();
    bool die();
    void display();
    void restart();
};
