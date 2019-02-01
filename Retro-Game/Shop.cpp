//File created by Byron Hall.
#include <iostream>
#include <string>
#include <unistd.h>
#include <ctype.h>
#include "player.h"
using namespace std;

#include "libsqlite.hpp"


//Function to create the shop table
int shop_table(Player& player)
{
	
    string sqliteFile = "database_game.db";
    
    try{
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement();
        
        cur->set_sql("CREATE TABLE IF NOT EXISTS shop "
                     "(Name TEXT PRIMARY KEY NOT NULL "
                     ",ID INTEGER "
                     ",Strength INTEGER "
                     ",Vitality INTEGER "
                     ",Gold INTEGER"
                     ");");//SQL command to create shop table if it doesn't already exist
         
        cur->prepare();
        cur->step();
    }
    catch( sqlite::exception e){
        std::cerr << e.what() << endl; //catch all sql errors
        return 1;
    }
    return 0;
}


//Function to add all items to the shop_table

int update_table(Player& player)
{
    
    string sqliteFile = "database_game.db";
    
    try
    {
        sqlite::sqlite db( sqliteFile );
        
        //adding item "Fish" to table
        
        auto cur = db.get_statement();
        
        cur->set_sql("INSERT OR REPLACE INTO shop (Name, Strength, Vitality, Gold, ID) "
                     "VALUES (?, ?, ?, ?, ?) ;");
        cur->prepare();
        cur->bind( 1 , "Fish");
        cur->bind( 2 , 10);//Strength
        cur->bind( 3 , 0);//Vitality
        cur->bind( 4 , 10);//Gold
        cur->bind( 5 , 1);// ID
        cur->step();
        
        
        //adding item "Lucky Stone" to table
        cur->prepare();
        cur->bind( 1 , "Lucky Stone");
        cur->bind( 2 , 0);//Strength
        cur->bind( 3 , 10);//Vitality
        cur->bind(4 , 10);//Gold
        cur->bind( 5 , 2);// ID
        
        cur->step();
        
        
        //adding item "Trophy" to table
        cur->prepare();
        cur->bind( 1 , "Trophy");
        cur->bind( 2 , 5);//Strength
        cur->bind( 3 , 5);//Vitality
        cur->bind(4 , 10);//Gold
        cur->bind( 5 , 3);// ID

        cur->step();
        
        
        //adding item "Bandage" to table
        cur->prepare();
        cur->bind( 1 , "Bandage");
        cur->bind( 2 , 0);//Strength
        cur->bind( 3 , 5);//Vitality
        cur->bind(4 , 5);//Gold
        cur->bind( 5 , 4);// ID
        cur->step();
        
        
        //adding item "Medallion" to table
        cur->prepare();
        cur->bind( 1 , "Medallion");
        cur->bind( 2 , 10);//Strength
        cur->bind( 3 , 10);//Vitality
        cur->bind(4 , 30);//Gold
        cur->bind( 5 , 5);// ID
        cur->step();
	
    }
    catch( sqlite::exception e)
    {
        std::cerr << e.what() << endl;
        return 1;
    }
    return 0;
}

/*Function to pull all data from 
database and display in terminal*/

int load_table(Player& player)
{
    
    cout<<endl;
    string sqliteFile = "database_game.db";
    
    try{
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement();
        
        
        cur->set_sql("SELECT * FROM shop");
        cur->prepare();
        
        while(cur->step())
        {
            int ID = cur-> get_int(1);
            string Name = cur-> get_text(0);
            int Strength = cur-> get_int(2);
            int Vitality = cur-> get_int(3);
            int Gold = cur-> get_int(4);
            
            cout << "\033[1;31mID:\033[0m" << " " << ID << endl;//This will display the shop in the terminal
            cout << "Name:" << " " << Name << endl;
            cout << "\033[1;34mStrength:\033[0m" << " " << Strength << endl;
            cout << "\033[1;31mVitality:\033[0m" << " " << Vitality << endl;
            cout << "\033[1;33mGold:\033[0m" << " " << Gold << endl;
            cout << endl;
        }
        
         
    }
    catch( sqlite::exception e){
        std::cerr << e.what() << endl;
        return 1;
    }
    return 0;
}



//Function to delete entire table 

int clear_table()
{
    
    string sqliteFile = "database_game.db";
    
    try{
        sqlite::sqlite db( sqliteFile );//open database
        auto cur = db.get_statement();
        
        
        cur->set_sql("DROP TABLE shop");
        cur->prepare();
        cur->step();
         
    }
    catch( sqlite::exception e){
        std::cerr << e.what() << endl;
        return 1;
    }
    return 0;
}//Mainly used for testing purpose


//Function to take input from the user

int purchase_input()
{
    int choice;
    cout << "Please enter the ID of the item you want to buy?" << endl;//Asking the user for an ID of an item they wish to buy
    cin >> choice;
    
    if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
        return choice;
    
    else;
        cout << "PLEASE ENTER AN INTEGER OF AN ITEM" << endl;
}



//function to buy an item 

int purchase_item(Player& player){
    int choice = purchase_input();
    string sqliteFile = "database_game.db";
    
    try{
        sqlite::sqlite db( sqliteFile );//open database
        auto cur = db.get_statement();
        
        
        cur->set_sql("SELECT Name,Strength,Vitality,Gold FROM shop " //Selecting the item to purcahse using the ID
                     "WHERE ID = ?");
        cur->prepare();
        cur->bind(1 , choice);
        
        while(cur->step())
        {
            
            string Name = cur-> get_text(0);
            int Strength = cur-> get_int(1);
            int Vitality = cur-> get_int(2);
            int Gold = cur-> get_int(3);
            
            player.addStrength(Strength);//Adding strength to player
            player.addVitality(Vitality);//Adding vitality to player
            player.addGold(-Gold);//Taking gold from player 
            
                cout << "You have purchased " << Name << endl;
        }
         
    }
    catch( sqlite::exception e){
        std::cerr << e.what() << endl;
        return 1;
    }
    return 0;
}


//Function which calls all other functions and is called by the main game to run all functions

void shop(Player& player)
{
    shop_table(player);
    update_table(player);
    load_table(player);  
    purchase_item(player);
    player.update();
}
