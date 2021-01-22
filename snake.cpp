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

void Snake:: spawnSnake(){
  snake.push_back(make_pair(1,1));
  snake.push_back(make_pair(2,1));
  snake.push_back(make_pair(3,1));
}
void Snake:: spawnFood(){
   srand (time(NULL));
  foodCoor=make_pair(rand()%9+1,rand()%9+1);
  board[foodCoor.first][foodCoor.second]=food;
}
void Snake:: display(){
  for(int i=0;i<10;i++){
    for(int x=0;x<10;x++){
      board[i][x]=' ';}cout<<endl;}
  for(int i=0;i<snake.size();i++){
    board[snake[i].first][snake[i].second]=snk;
  }
  board[foodCoor.first][foodCoor.second]=food;

int i;
i=snake.size();
cout<<i;
}


void Snake:: eat(){
  if(snake[snake.size()-1]==foodCoor){
    auto it = snake.insert(snake.end(),make_pair(foodCoor.first,foodCoor.second));
    snakeSize++;
    spawnFood();
    display();
  }
}

 bool Snake:: die(){
   for(int i=0;i<snake.size()-2;i++){
     if(snake[i]==snake[snake.size()-1]){
       return true;
     }
   }
   if(snake[snake.size()-1].first==0||snake[snake.size()-1].first==10){
     return true;
   }
   if(snake[snake.size()-1].second==0||snake[snake.size()-1].second==10){
     return true;
   }
   return false;
 }

void Snake:: restart(){
  snake.clear();
  spawnSnake();
}


  void Snake::spawnMap(){
  for(int i=0;i<10;i++){
    for(int x=0;x<10;x++){
      cout << board[i][x];}cout<<endl;}
}

void Snake::move(){
  char m;
  cin>>m;
  switch(m){
    case 'w':
        snake.push_back(make_pair(snake[snake.size()-1].first-1,snake[snake.size()-1].second));
        board[snake[0].first][snake[0].second]=' ';
        snake.erase(snake.begin());
                eat();
        display();
        die();
        if(die()==true){
          cout<<"game over\n";
            restart();
        }
        spawnMap();
        break;

    case 'a':
        snake.push_back(make_pair(snake[snake.size()-1].first,snake[snake.size()-1].second-1));
        snake.erase(snake.begin());
        eat();
        display();
        die();
        if(die()==true){
            cout<<"game over\n";
            restart();
        }
        spawnMap();
        break;
    
    case 's':
        snake.push_back(make_pair(snake[snake.size()-1].first+1,snake[snake.size()-1].second));
        snake.erase(snake.begin());
        eat();
        display();
        die();
        if(die()==true){
          cout<<"game over\n";
            restart();
        }
        spawnMap();
        break;
    
    case 'd':
        snake.push_back(make_pair(snake[snake.size()-1].first,snake[snake.size()-1].second+1));
        snake.erase(snake.begin());
        eat();
        display();
        die();
        if(die()==true){
          cout<<"game over\n";
            restart();
        }
        spawnMap();     
        break;
  }
}
