// File Made by Daniel Kanchev
#include<iostream>
#include<stdlib.h> //rand,srand
#include<thread>   //needed for sleep_for
#include<chrono>   //needed also for sleep_for
#include<string>  
#include<vector>   
#include<ctime> //needed for srand, to make diff number
// all files used included here
#include "trap.cpp" 
#include "items.cpp"
#include "progressBar.cpp"
#include "eventMonster.cpp"
#include "eventItem.cpp"
#include "eventTrap.cpp"
#include "gameOverScreen.cpp"
using namespace std;

bool eventGen(Player& player,int travel, int& monsters, int& items)
{   

    int distance; //distance user enters
    int eventPrc; // random number to signify if event happends or not; //progress from 0 to game end
    int gameEnd = 500; //distance needed to win the game
    srand(time(0)); // makes it so rand() produces different numbers each time
    progressBar(gameEnd,travel); //prints progress
    cout<< "\033[2J\033[1;1H"; // clear terminal command
    cout<<"You're on mile "<<travel<<'.'<<endl; 
    cout<<"Game ends at "<<gameEnd<<" miles."<<endl;
    cout<<"Enter a distance:";
    cin>>distance;
    while (cin.fail() || (distance+travel>gameEnd && distance!=303030 & distance!= 202020) ) //if we'll end up farther than the end
      {     
            
            cout<<"Invalid input.Try again!"<<endl;
            cout<<"Enter a distance:";
            cin.clear();
		  cin.ignore(256, '\n');
            cin>>distance;;
            cout<<endl;
      }
    if (distance == 303030) // victory test
    {
         gameOverScreen(player,"Victory",monsters,items);
         return false;
    }
    if (distance == 202020) //defeat test
    {
         gameOverScreen(player,"Defeat",monsters,items);
         return false;
    }
    int currEnd = travel+distance;  
    cout<<"Travelling from mile "<<travel<<" to mile " <<currEnd<<"...."<<endl;
    this_thread::sleep_for (std::chrono::seconds(2)); //slep
    while(travel<currEnd) //until we reach user's entered distance
      {   
          travel++;
          eventPrc = rand()% 100+1; //random number generated
          
          if (eventPrc>90) //10%
          {  
              //monster branch
              monsters++;
              eventMonster(player,travel);
              if (player.isDead()) // we died
              {   
                  this_thread::sleep_for (chrono::seconds(1)); //sleep
                  gameOverScreen(player,"Defeat",monsters,items);
                  return false;
              }         
              this_thread::sleep_for (chrono::seconds(1)); //sleep
          }
          else if (eventPrc>85) //5%
          {  
              //trap branch
              eventTrap(player,travel);
              if (player.isDead()) // we died
              {   
                  this_thread::sleep_for (chrono::seconds(1)); //sleep
                  gameOverScreen(player,"Defeat",monsters,items);
                  return false;
              }
              
              this_thread::sleep_for (std::chrono::seconds(1)); //sleep 
          }
          else if (eventPrc>81) //4%
          {
              //item branch
              items++;
              eventItem(player,travel); 
              this_thread::sleep_for (std::chrono::seconds(1)); //sleep
          }
           
      }
      cout<< "\033[2J\033[1;1H"; //clear terminal
      cout<<"Travelled so far:"<<travel<<" miles."<<endl;
      progressBar(gameEnd,travel); //prints progress
      cout<<endl;
      this_thread::sleep_for (std::chrono::seconds(1)); //sleep
      player.addTravel(distance); //updates how much player has travelled
      if (travel == gameEnd) // if we got to the end 
      {   
         gameOverScreen(player,"Victory",monsters,items);
         return false;
      }
      return true;
}