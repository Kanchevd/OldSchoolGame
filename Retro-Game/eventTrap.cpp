//Start of Dimitar Smilov's code
#include "Art/trapImage.cpp"
int create_faced_trap_table() // creates table o ffaced traps
{
    string sqliteFile = "database_game.db"; //database file 
    
    try{
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement();
        cur->set_sql("CREATE TABLE IF NOT EXISTS facedTrap "
                     "(TIMES INTEGER "
                     ",NAME TEXT "
                     ",PLAYER TEXT "
                     ",FOREIGN KEY (NAME) REFERENCES trap (Name) "
                     ");");
        cur->prepare();
        cur->step();
    }   
    catch( sqlite::exception e){ //Week 4 Codio
        std::cerr << e.what() << endl;
        return 1;
    }
}
//End of Dimitar Smilov's code
//Start of Daniel Kanchev's code 
int eventTrap(Player& player,int travel)
{   
    trapCreate(); //creates database of traps from trap.cpp
    create_faced_trap_table();

    vector<string> Traps; // traps with rolled rarity
    string trapName;  
    int trapPrc = rand()% 100+1; 
    int trapRare; // Trap Rarity. 0 = Common, 1 = Rare;
    int trapInteger; //Integer to select a trap from Traps vector, randomly selected;
    int trapHP=0, trapDMG=0,trapGold=0; //trap stats from database
    int damageDealt; // damage player deals to trap
    int trapChoice; //user's choice on how to pass the trap
    int timesFaced;
    if (trapPrc>90)   //rarity odds    
    {
        //trap is rare
        trapRare = 1;
    }
    else 
    {
        // not that rare
        trapRare = 0;
    }
    
    string sqliteFile = "database_game.db"; //database file
    
    try
    {
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement(); //new cursor 
         
        //select the names of all traps with appropriate rarity
        cur->set_sql("SELECT Name FROM trap "   
                     "WHERE Rarity = ? "
                     ";");
        cur->prepare();
        cur->bind(1,trapRare); 
        while( cur->step() )
           Traps.emplace_back(cur->get_text(0));  //add found traps to Vector "Traps";
     

       trapInteger= rand()% (Traps.size())+0;   // random integer from 0 to the amount of traps   
       trapName = Traps[trapInteger]; //get trap at that integer in the vector
         
        
       auto cur2 = db.get_statement(); // new cursor 
       //get the stats of the selected trap
       cur2->set_sql("SELECT Defense,Damage,Gold FROM trap "
                     "WHERE Name = ? "
                     ";");
       cur2->prepare();
       cur2->bind(1,trapName);
     
       while (cur2->step())
       {   
           //assign traps stats to variables
           trapHP = cur2->get_int(0);
           trapDMG = cur2->get_int(1);
           trapGold = cur2->get_int(2);
       }
         
       skullSign(); // ascii art - clears terminal
       
       //End of Daniel Kanchev's code
       //Start of Dimitar Smilov's code 
       auto cur3 = db.get_statement(); // new cursor
       cur3->set_sql("SELECT TIMES FROM facedTrap " //check how many times we faced the current trap
                     "WHERE NAME = ? AND PLAYER = ? ;");
       cur3->prepare();
       cur3->bind(1,trapName);
       cur3->bind(2,player.getname());
       cur3->step();
       timesFaced = cur3->get_int(0); 
         
       auto cur4 = db.get_statement(); // new cursor
       if (timesFaced == 0) // if we haven't faced it before
       {    
            //insert it as a new row in the database 
            cur4->set_sql("INSERT OR REPLACE INTO facedTrap " 
                          "VALUES (1, ?, ?) ;");         
            cur4->prepare();
            cur4->bind(1,trapName);
            cur4->bind(2,player.getname()); 
            cur4->step();
       }
       else  //if we have faced it before
       {    
            //increment value in existing row
            cur4->set_sql("UPDATE facedTrap SET TIMES = ? WHERE NAME = ? AND PLAYER = ?;");         
            cur4->prepare();
            cur4->bind(1,timesFaced+1);
            cur4->bind(2,trapName);
            cur4->bind(3,player.getname());
            cur4->step();
       }
       //End of Dimitar Smilov's code 
       //Start of Daniel Kanchev's code     
       cout<<"On mile "<<travel<<", you stumble upon a "<<trapName<<'!'<<endl;
       cout<<"Do you want to pass through it safely, or quickly?"<<endl;
       cout<<"0:Pass safely"<<endl;
       cout<<"1:Pass quickly"<<endl;
       cin.clear();
       trapChoice = input_check(trapChoice); //checks input
       cout<<endl;
       if(trapChoice==1) //we want to risk it 
       {
           int safePass = rand()% 100+1; //chance we pass safe
           if (safePass>60) 
           {
               cout<<"You pass through without taking damage! Good Job!"<<endl;
           }
           else
           {
               cout<<"Ouch! You take "<<trapDMG<<" from "<<trapName<<'!'<<endl;
               player.dealDamage(trapDMG);
           }
       }
       else // we pass safely
       {
           cout<<"You pass safely through "<<trapName<<" and only take "<<trapDMG/2<<" damage."<<endl;
           player.dealDamage(trapDMG/2);
       }
       cout<<"HP:"<<player.get_currHP()<<endl;
       cout<<endl;
       if(trapHP>0 & player.get_currHP()>0) // if it is a killable trap and we're alive
       {  
           int trapFightChoice;
           cout<<"Do you want to destroy the trap?"<<endl;
           cout<<"0:Yes"<<endl;
           cout<<"1:No"<<endl;
           trapFightChoice = input_check(trapFightChoice); //checks input
           cout<<endl;
           if (trapFightChoice == 1) // we don't fight it
           {
               cout<<"You continue onwards."<<endl;
               cout<<endl;
           }
           else //we hit it
           {   
                damageDealt = player.Attack()*6; //traps take 6 times more damage
                trapHP -= damageDealt;
                cout<<"You hit the trap for "<<damageDealt<<" damage,";
                if (trapHP>0) //if we manage to kill the trap in 1 hit
                {
                    cout<<"but you didn't manage to destroy it. You decide to move on."<<endl;
                }
                else // if we don't 
                {
                    cout<<"and you destroy it...and you find "<<trapGold<<" gold under it!"<<endl;
                    player.addGold(trapGold);
                }    
               
           }  //closes else 
           
       }  //closes if (TrapHP>0)
       this_thread::sleep_for (chrono::seconds(1)); //sleep
    }  //closes try
    catch( sqlite::exception e) //Week 4 Codio
    {
        std::cerr << e.what() << endl;
        return 1;
    }
    return 0;

}
//End of Daniel Kanchev's code