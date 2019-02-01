//File Made by Daniel Kanchev
#include "Art/reptileAnimation.cpp"
#include "Art/mysteryAnimation.cpp"
#include "Art/snakeAnimation.cpp"
#include "Art/spiderAnimation.cpp"
#include "Art/werewolfAnimation.cpp"
#include "Art/witchAnimation.cpp"
#include "Art/defaultAnimation.cpp"
#include "Art/gremlinAnimation.cpp"
#include "enemy.cpp"
#include "input_check.cpp"
void animation(string monster) // pick animation for respective monster
{
     if (monster=="Werewolf")
          werewolfAnimation();
     else if (monster=="Reptillian")
          reptileAnimation();
     else if (monster=="Spider")
          spiderAnimation();
     else if (monster=="Snake")
          snakeAnimation();
     else if (monster=="Witch")
          witchAnimation();
     else if (monster=="?????")
          mysteryAnimation();
     else if (monster=="Gremlin")
          gremlin();
     else
          defaultAnimation();
}
void image(string monster) // pick image for respective monster
{
     if (monster=="Werewolf")
          werewolfImage();
     else if (monster=="Reptillian")
          reptileImage();
     else if (monster=="Spider")
          spiderImage();
     else if (monster=="Snake")
          snakeImage();
     else if (monster=="Witch")
          witchImage();
     else if (monster=="?????")
          mysteryImage();
     else if (monster=="Gremlin")
          gremlin();
     else
          defaultAnimation();
}
bool escape() // 50/50 to escape or not, returns outcome
 {
    int escapePRC = rand()% 4+0;
    if (escapePRC%2 == 0) 
    {
         cout<<"You've escaped successfully!"<<endl;
         return true;
    }
    else
    {
         cout<<"You couldn't manage to escape!"<<endl;
         this_thread::sleep_for (std::chrono::seconds(1));
         return false;
    }
}
int rarity(int travel)// returns chosen rarity based on current mile
{ 
     int RarityPRC = rand()& 100+1;
     if (travel<100)
     {
          if (RarityPRC>80)
               return 2;
          else
               return 1;
     }
     else if (travel<250)
     {
          if (RarityPRC>40)
               return 2;
          else
               return 1;
     }
     else
     {     
          if (RarityPRC>70)
               return 2;
          else if (RarityPRC>30)
               return 1;
          else 
               return 3;
     }
}
int battle(Player& player,int monsterHealth,int monsterAttack,string monsterName,int monsterGold,int monsterXP) 
{    
     int playerDamage,escapeChoice,escapePRC;
     while(true) 
     {    
          image(monsterName);
          cout<<endl;
          playerDamage = player.Attack(); //how much the player attacks for
          cout<<"You hit the "<<monsterName<<" for "<<playerDamage<<'.'<<endl;
          monsterHealth -=playerDamage; //deal damage to the monster
          this_thread::sleep_for (std::chrono::seconds(1));
          if (monsterHealth<=0) //we killed it
          {
               cout<<"You killed the "<<monsterName<<'!'<<endl; 
               cout<<"Found "<<monsterGold<< " Gold!"<<endl;
               player.addGold(monsterGold);               
               cout<<"Gained "<<monsterXP<< " XP!"<<endl;
               player.addExp(monsterXP);
               return 0;
          }
          else 
          {   
              cout<<monsterName<<" HP left:"<<monsterHealth<<endl;
              this_thread::sleep_for (std::chrono::seconds(1));
              cout<<endl;
              cout<<"The "<<monsterName<<" hits you for "<<monsterAttack<<'.'<<endl; 
              player.dealDamage(monsterAttack);// deal damage to us
              this_thread::sleep_for (std::chrono::seconds(1));
              cout<<"HP:"<<player.get_currHP()<<endl; 
              cout<<endl;
              if (player.isDead())
              {    
                   this_thread::sleep_for (std::chrono::seconds(1));
                   return 0;
              }
              else
              {                     
                   this_thread::sleep_for (std::chrono::seconds(1));
                   cout<<"Do you keep fighting or try to escape?"<<endl;
                   cout<<"0:Keep fighting"<<endl;
                   cout<<"1:Try to escape"<<endl;
                   escapeChoice = input_check(escapeChoice); //check for correct input
                   if (escapeChoice) // if we tried to escape
                   {
                        if(escape()==true) // if we escape, while loop and battle over, if we don't, continue
                        return 0;
                   }
              }
          }
     }
     
}
int eventMonster(Player& player,int travel) //if a monster is generated
{       
    enemy_table();
    update_table(); // both functions to create and update monster table
    string monsterName;
    int monsterRarity,monsterAttack,monsterGold,monsterHealth,monsterIter,monsterChoice;
    vector<string> monsters;
     
    monsterRarity = rarity(travel);
    int monsterXP = monsterRarity*monsterRarity*100;
    string sqliteFile = "database_game.db"; //database file
    
    try
    {
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement(); //new cursor 
         
        //select the names of all monsters with appropriate rarity
        cur->set_sql("SELECT Name FROM enemies "   
                     "WHERE Rarity = ? "
                     ";");
        cur->prepare();
        cur->bind(1,monsterRarity); 
        while( cur->step() )
          monsters.emplace_back(cur->get_text(0));  //add found traps to Vector "monsters"
                  
        monsterIter= rand()% (monsters.size())+0;   // random integer from 0 to the amount of monsters  
        monsterName = monsters[monsterIter]; //get trap at that integer in the vector
         
         auto cur2 = db.get_statement(); // new cursor 
        //get the stats of the selected monster
        cur2->set_sql("SELECT Health,Attack,Gold FROM enemies "
                      "WHERE Name = ? "
                      ";");
        cur2->prepare();
        cur2->bind(1,monsterName);
      
        while (cur2->step())
        {   
            //assign monster stats to variables
            monsterHealth= cur2->get_int(0);
            monsterAttack = cur2->get_int(1);
            monsterGold = cur2->get_int(2);
        }
        animation(monsterName);//displays monster animation for current monster
        cout<<"On mile "<<travel<<",you encountered a "<<monsterName<<'!'<<endl; 
        cout<<"Health:"<<monsterHealth<<endl;
        cout<<"Attack:"<<monsterAttack<<endl;
        cout<<"Gold:"<<monsterGold<<endl;
        cout<<endl;
        cout<<"What do you want to do?"<<endl;
        cout<<"0:Fight"<<endl;
        cout<<"1:Try to Run"<<endl;
        monsterChoice = input_check(monsterChoice); //checks for invalid input
        if (monsterChoice == 0) //we choose to battle
        {
             battle(player,monsterHealth,monsterAttack,monsterName,monsterGold,monsterXP);
        }
        else if (escape()==false) //if we don't,  escape() is called to try and escape
        {
             battle(player,monsterHealth,monsterAttack,monsterName,monsterGold,monsterXP);
        }  
    }
        catch( sqlite::exception e) //Week 4 Codio
    {
        std::cerr << e.what() << endl;
        return 1;
    }
    
    this_thread::sleep_for (std::chrono::seconds(1));
     
    //level up if you have enough XP
    if (player.getExp()>=player.getExpNext())
    {    
         cout<< "\033[2J\033[1;1H"; //clear terminal
         this_thread::sleep_for (std::chrono::seconds(1)); //sleep
         while (player.getExp()>=player.getExpNext())
         {
              player.levelUp();
         }
         this_thread::sleep_for (std::chrono::seconds(1)); //sleep
         player.updateStats(); // commit stat points
         player.update(); //make health and attack proper values according to stats
    }
    return 0;
}