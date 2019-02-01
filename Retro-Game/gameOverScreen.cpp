// File Made by Daniel Kanchev
#include <iostream>
#include "Art/victoryAnimation.cpp" //art
#include "Art/defeatAnimation.cpp"  //art
int gameOverScreen(Player& player,string outcome,int monsters,int items)
{    
     if (outcome == "Defeat") // if it's a loss
     {
         defeatAnimation();
         cout<<"Unfortunately, you lost."<<endl;
         cout<<"Why not reload the game and try again?"<<endl; 
     }
     else if (outcome == "Victory")// if it's a win 
     { 
         victoryAnimation();
         cout<<"Congratulations! You Won."<<endl;
         cout<<"Through your journey, you faced many difficulties, but you pulled through!"<<endl;
     }
     else 
          cout <<"Input other than Victory or Defeat"<<endl;
     
     
     
     cout<<"Here are some stats from your playthrough:"<<endl;
     cout<<endl;
     cout<<"Items found:"<<items<<endl;
     cout<<"Monsters Killed:"<<monsters<<endl;
     cout<<endl;
     cout<<"Traps faced:"<<endl;
     cout<<"------------"<<endl;
     
     string sqliteFile = "database_game.db";
     try
     {
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement();
        cur->set_sql("SELECT NAME,TIMES FROM facedTrap WHERE PLAYER = ? ;"); //check how many traps of each we faced
        cur->prepare();
        cur->bind(1,player.getname());
        while(cur->step())
             cout<<cur->get_text(0)<<':'<<cur->get_int(1)<<endl;
        
        auto cur2 = db.get_statement();
        cur2->set_sql("DELETE FROM facedTrap WHERE PLAYER =  ? ;"); //delete it from the database at the end
        cur2->prepare();
        cur2->bind(1,player.getname());
        cur2->step();
          
     }  //closes try
         catch( sqlite::exception e) // Week 4 Codio
     {
        std::cerr << e.what() << endl;
        return 1;
     }
        
     
 
     cout<<endl;
     return 0;
}