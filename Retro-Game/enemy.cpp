/*

(` /|       Created by Sharjeel Ahmad.
_)/-|
   

*/
#include <iostream>
#include "libsqlite.hpp"

using namespace std;

int enemy_table() //Creates a SQL table to store the various enemies and their stats.
{
    
    
    string sqliteFile = "database_game.db";
    try{
            
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement(); //Creates a cursor on this connection.
            
           
        cur->set_sql("CREATE TABLE IF NOT EXISTS enemies " //Configures our SQL query.
                     "(Name TEXT PRIMARY KEY NOT NULL "
                     ",Rarity INTEGER "
                     ",Attack INTEGER "
                     ",Health INTEGER "
                     ",Gold INTEGER"
                     ");");//SQL command to create enemies table if it doesn't already exist.
            
        cur->prepare(); //prepare() sends the query to the databse.
        cur->step(); //step() gets the first row of results.
                      
        }

    catch( sqlite::exception e) //Taken from Codio week 4.
    {
        std::cerr << e.what() << endl; //catches all SQL errors.
        return 1;
    }
    
    

}

    
    
//Function to add all enemies to the enemies table

int update_table()
    
{
    
    string sqliteFile = "database_game.db";
    
    try
       {
        sqlite::sqlite db( sqliteFile );
            
        auto cur = db.get_statement();
        cur->set_sql("INSERT OR REPLACE INTO enemies (Name, Gold, Attack, Health, Rarity) "
                     "VALUES (?, ?, ?, ?, ?) ;");
        
        //The following code adds the enemies to the database along with thier stats.
        cur->prepare();
        cur->bind( 1 , "Werewolf");
        cur->bind( 2 , 15);//Gold
        cur->bind( 3 , 7);//Attack
        cur->bind( 4 , 45);//Health
        cur->bind( 5 , 2);// Rarity (1 is the least rare and 3 is the rarest)
        cur->step();
            
        cur->prepare();
        cur->bind( 1 , "Gremlin");
        cur->bind( 2 , 50);//Gold
        cur->bind( 3 , 20);//Attack
        cur->bind( 4 , 40);//Health
        cur->bind( 5 , 3);// Rarity 
        cur->step();
            
        cur->prepare();
        cur->bind( 1 , "Witch");
        cur->bind( 2 , 35);//Gold
        cur->bind( 3 , 15);//Attack
        cur->bind( 4 , 35);//Health
        cur->bind( 5 , 2);// Rarity 
        cur->step();
        
        cur->prepare();
        cur->bind( 1 , "Snake");
        cur->bind( 2 , 40);//Gold
        cur->bind( 3 , 15);//Attack
        cur->bind( 4 , 53);//Health
        cur->bind( 5 , 3);// Rarity 
        cur->step();
        
        cur->prepare();
        cur->bind( 1 , "Spider");
        cur->bind( 2 , 10);//Gold
        cur->bind( 3 , 5);//Attack
        cur->bind( 4 , 8);//Health
        cur->bind( 5 , 1);// Rarity 
        cur->step();
           
        cur->prepare();
        cur->bind( 1 , "Reptillian");
        cur->bind( 2 , 20);//Gold
        cur->bind( 3 , 8);//Attack
        cur->bind( 4 , 17);//Health
        cur->bind( 5 , 1);// Rarity 
        cur->step();
            
        cur->prepare();
        cur->bind( 1 , "?????");
        cur->bind( 2 , 100);//Gold
        cur->bind( 3 , 35);//Attack
        cur->bind( 4 , 80);//Health
        cur->bind( 5 , 3);// Rarity 
        cur->step();
        
    }  


catch( sqlite::exception e){
        std::cerr << e.what() << endl;
        return 1;}} //Once again, catching any errors in SQL.
