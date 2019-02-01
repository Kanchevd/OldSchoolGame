/*The whole file is written by Iliyan Mladenov */
#include "player.h"
#include<vector>

Player::Player() //variables are assigned to player class object
{
	this->travel;

	this->level;
	this->exp;
	this->expNext;

	this->gold;

	this->strength;
	this->vitality;
	this->statPoints;
    
    this->equippedWeapon;
    this->equippedArmor;
    this->currWeaponStats;
    this->currArmorStats;
    
    this->equippedJewell;
    this->currJewellStrength;
    this->currJewellVitality;
}

Player::~Player() //Destructor
{

}

void Player::initialize(string name)//Assigns values to the variales
{
	this->travel = 0;

	this->level = 1;
	this->exp = 0;
	this->expNext =((50 / 3)*((pow(level, 3) //Algorithm for leveling
					- 6 * pow(level, 2))
					+ 17 * level - 12)) + 100;
	this->gold = 100;
	
	this->strength = 5;
	this->vitality = 5;

	this->statPoints = 0;
    
    this->equippedWeapon = "None";
    this->equippedArmor = "None";
    this->currWeaponStats = 0;
    this->currArmorStats = 0;
    
    this->equippedJewell = "None";
    this->currJewellStrength = 0;
    this->currJewellVitality = 0;
	Character::initialize(name); //calls the character initialize function
	update(); //updates maxHP, minDamage and maxDamage variables
}

void Player::printStats() const //prints all the variables to the user via calling accessors or accessing variables
{
	cout << "= Character Sheet =" << "\n";
	cout << "Name: " << getname() << "\n";
	cout << "Level: " << this->level << "\n";
	cout << "\033[0;31mHp: \033[0m" << get_currHP() << "/" << get_maxHP() << "\n";
	cout << "\033[0;34mMin Damage: \033[0m" << getMinDamage() << "\n";
	cout << "\033[0;34mMax Damage: \033[0m" << getMaxDamage() << "\n";
	cout << "\033[0;32mExp: \033[0m" << this->exp << "/" << this->expNext << "\n";
	cout << "\n" << "\033[0;33mGold: \033[0m" << this->gold << "\n"; //all the cout lines below in the printStats function change its color of the text inside it
	cout << "\n" << "\033[0;32mStatpoints: \033[0m" << this->statPoints << "\n";
	cout << "\033[0;34mStrength: \033[0m" << this->strength - this->currWeaponStats << " + " << this->currWeaponStats <<"\n";
	cout << "\033[0;31mVitality: \033[0m" << this->vitality - this->currArmorStats << " + " << this->currArmorStats <<"\n"; 
    cout << "\n" <<"Equipped Weapon: " << this->equippedWeapon << " +" << this->currWeaponStats << " \033[0;34mStrength\033[0m" << "\n";
    cout << "Equipped Armor: " << this->equippedArmor << " +" << this->currArmorStats << " \033[0;31mVitality\033[0m" << "\n";
    cout << "Equipped Jewell: " << this->equippedJewell << " +" << this->currJewellStrength << " \033[0;34mStrength\033[0m" << " and +" << this->currJewellVitality << " \033[0;31mVitality\033[0m" << "\n";
	cout << "\n";
}

void Player::rest()//function which takes gold and adds random number to the hp variable
{   
	srand(time(NULL));//sets the seed of the random number generator algorithm used by the function rand
	this->choice;
	cout << "\n" <<"RESTING WILL COST YOU 50 GOLD!" << endl;
	cout << "DO YOU WISH TO CONTINUE?" << "\n" << endl;
	cout << "0: Yes" << endl;
	cout << "1: No" << endl;
	cin >> choice;

	while (cin.fail() || (choice != 0 && choice != 1))//checks the user input and asks for new input if the old one is not valid
	{
		cout << "PLEASE TYPE AN INTEGER(0 or 1)!" << endl;
		cout << "0:Yes" << endl;
		cout << "1:No" << endl;
		cin.clear();//clears the input from the user
		cin.ignore(256, '\n');//ignoring if there is previous input
		cin >> this->choice;
	}
	if (choice == 0) // checks the user input
	{
		if (get_currHP() < get_maxHP())//executes if the max health of player is greater than current health
		{
			if (getGold() >= 50) //executes if player has gold more than or equal to 50
			{
				this->random = rand() % 11 + 15;//selects random number between 10 and 20
				restHP(this->random);//calls restHP function which adds to the HP variable
                addGold(-50);//calls addGold function which edits the gold variable
				cout << "\n" << "HEALTH REPLENISHED!" << endl;
				cout << "CURRENT HEALTH: " << get_currHP() << "/" << get_maxHP() << "\n" << endl;
			}

			else //executes if player has below 50 gold
			{
				cout << "\n" << "\033[0;31mNOT ENOUGH MONEY!\033[0m" << "\n" << endl;//this line changes its color
			}
		}

		else //executes if player current health is equal to max health
		{
			cout << "\n" << "\033[0;31mYOUR HEALTH IS AT MAXIMUM!\033[0m" << "\n" << endl;//this line changes its color
		}
	}
}

int Player::create_player_table()//creates player table in the database
{
    string sqliteFile = "database_game.db"; //assigning database file to a string variable
    
    try{
        sqlite::sqlite db( sqliteFile ); //connects to the database file
        auto cur = db.get_statement(); //creates cursor

        cur->set_sql("PRAGMA foreign_keys = ON;"); //turning the foreign keys on because they are disabled by default
        cur->prepare(); 
        cur->step();
        
        auto cur2 = db.get_statement();
        cur2->set_sql("CREATE TABLE IF NOT EXISTS player " //creates player table if not exists
                     "(Name TEXT PRIMARY KEY "
                     ",Travel INTEGER "
                     ");");
         
        cur2->prepare();//prepares the sql queries
        cur2->step(); //executes the sql queries (step() returns true if there is any information)
        
        auto cur3 = db.get_statement();//creates cursor
        cur3->set_sql("CREATE TABLE IF NOT EXISTS stats " //creates stats table if not exists
                      "(Name TEXT UNIQUE "
                      ",Health INTEGER "
                      ",Maximum_Health INTEGER "
                      ",Maximum_Damage INTEGER "
                      ",Minimum_Damage INTEGER "
                      ",Level INTEGER "
                      ",Experience INTEGER "
                      ",Experience_next INTEGER "
                      ",Gold INTEGER "
                      ",Stat_points INTEGER "
                      ",Strength INTEGER "
                      ",Vitality INTEGER "
                      ",FOREIGN KEY (Name) REFERENCES player (Name) "
                      ");");
        
        cur3->prepare(); //prepares the sql queries
        cur3->step(); //executes the sql queries (step() returns true if there is any information)
        
        auto cur4 = db.get_statement(); //creates cursor
        cur4->set_sql("CREATE TABLE IF NOT EXISTS player_items " //creates player_items table if not exists
                      "(Name TEXT UNIQUE "
                      ",Equipped_Weapon TEXT "
                      ",Equipped_Armor TEXT "
                      ",Weapon_Stats INTEGER "
                      ",Armor_Stats INTEGER "
                      ",Equipped_Jewell TEXT "
                      ",Jewell_Strength INTEGER "
                      ",Jewell_Vitality INTEGER "
                      ",FOREIGN KEY (Name) REFERENCES stats (Name) "
                      ");");
        
        cur4->prepare(); //prepare the sql queries
        cur4->step();//executes the sql queries (step() returns true if there is any information)
    }
    catch( sqlite::exception e) //lines from 183 to 187 are taken from codio week 4
    {
        std::cerr << e.what() << endl; //catches all sql errors
        return 1;
    }
    return 0;
}

int Player::load_player_database()//loads player save into the game
{
    string sqliteFile = "database_game.db";
    vector<string> charList; //creates a vector
    int choice;
    int i = 1;
    try
    {
        sqlite::sqlite db( sqliteFile );//connects to the database file
        auto cur = db.get_statement(); //creates cursor
        cur->set_sql("SELECT Name FROM player " //select all the names in the database
                     ";");
        cur->prepare();//prepares the sql queries
        
        cout<<endl;
        cout << "SELECT CHARACTER NUMBER" << endl;
        cout<< 0 << " - " << "Back" << endl;
        
        while(cur->step())//print all the names from the database
        {
            string name = cur->get_text(0);//get the names in order
            cout << i << " - " << name << endl;
            charList.push_back(name);//store each name into the vector
            i += 1;
        }
        
        cout << endl;
        cout << "Choice: " << endl;
        int vectorSize = charList.size();//get the vector size
        
        cin >> choice;
        while (cin.fail() || (choice > (vectorSize)))//checks user input and asks again if it is not correct
            {
                cout << "PLEASE TYPE AN INTEGER!(between 0 and " << vectorSize << ")" << endl;
                cin.clear();
                cin.ignore(256, '\n');//ignoring 256 characters before the specified break stop in this case '\n' newline
                cin >> choice;
            }
        if (choice == 0) //executes if the user's choice is 0
            return 0;
        
        else //executes if the user's choice is integer different than 0
        {
            auto cur2 = db.get_statement();//creates cursor
            cur2->set_sql("SELECT * FROM player " //selects one row specified by name from the player table
                          "WHERE Name = ? "
                          ";");
            cur2->prepare();//prepares the sql queries
            cur2->bind( 1 , charList[choice-1] );//assign value of the first placeholder
            cur2->step();//executes the sql queries (step() returns true if there is any information)
            
            //lines from 243 to 244 modifies the player name and travel values 
            changeName(cur2->get_text(0));
            setTravel(cur2->get_int(1));
            
            auto cur3 = db.get_statement();//creates cursor
            cur3->set_sql("SELECT * FROM stats " //selects one row specified by name from the stats table
                          "WHERE Name = ? "
                          ";");
            cur3->prepare();//prepares the sql queries
            cur3->bind( 1 , charList[choice-1] );//assign value of the first placeholder
            cur3->step();//executes the sql queries (step() returns true if there is any information)
            
            //lines from 255 to 265 modifies the player stats and items with given information of the database
            setCurrHP(cur3->get_int(1));
            setMaxHP(cur3->get_int(2));
            setMaxDamage(cur3->get_int(3));
            setMinDamage(cur3->get_int(4));
            setLevel(cur3->get_int(5));
            setExp(cur3->get_int(6));
            setExpNext(cur3->get_int(7));
            setGold(cur3->get_int(8));
            setStatPoints(cur3->get_int(9));
            setStrength(cur3->get_int(10));
            setVitality(cur3->get_int(11));
            
            auto cur4 = db.get_statement();//creates cursor
            cur4->set_sql("SELECT * FROM player_items " //selects one row specified by name from the player_items table
                          "WHERE Name = ? "
                          ";");
            
            cur4->prepare(); //prepares the sql queries
            cur4->bind( 1 , charList[choice-1] );//assigns value of the first placeholder
            cur4->step(); //executes the sql queries (step() returns true if there is any information)
            
            
            //lines from 277 to 282 modifies the player items with given information of the database
            setEquippedWeapon(cur4->get_text(1));
            setEquippedArmor(cur4->get_text(2));
            setCurrWeaponStats(cur4->get_int(3));
            setCurrArmorStats(cur4->get_int(4));
            setEquippedJewell(cur4->get_text(5));
            setJewellStats(cur4->get_int(6),cur4->get_int(7));
            return 2;
        }
    }
    catch( sqlite::exception e)//lines from 286 to 291 are taken from codio week 4
    {
        std::cerr << "\n" << "THERE ARE NO ENTRIES!" << "\n" << endl; //catch all sql errors
        return 1;
    }
    return 0;
}

int Player::count_player_names() // counts the names from the player table
{
    string sqliteFile = "database_game.db";
    try
    {
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement();
        cur->set_sql("SELECT COUNT(Name) FROM player " //counts the names 
                     ";");
        cur->prepare();
        cur->step();
        
        if(cur->get_int(0) == 0) //executes if there are no entries
            return 1;
    }
    catch( sqlite::exception e)//lines from 310 to 313 are taken from codio week 4
    { 
        return 2;
    }
    return 0;
}

void Player::levelUp()//function which changes player level
{         
	if (this->exp >= this->expNext)//checks the exp if it is enough for level up
	{
		this->exp -= this->expNext;//subtracts exp for leveling up with current exp
		this->level++;
		this->expNext = //updates the needed exp for the next level
			((50 / 3)*((pow(level, 3)
				- 6 * pow(level, 2))
				+ 17 * level - 12)) + 100;
		this->statPoints++;
		
		cout << "\n" << "\033[0;32mYOU LEVELED UP!\033[0m" <<  endl;//this line changes its color
		cout << "YOUR LEVEL IS " << this->level << "!" <<"\n" << endl;
          this->currHP = this->maxHP;
	}

	else //executes when there is not enough exp to level up
	{
		cout << "\n" << "\033[0;31mNOT ENOUGH EXP!\033[0m" << "\n" << endl;//this line changes its color
	}

}

void Player::updateStats()//updating strength and vitality of the player
{

	if (this->statPoints > 0)//checks if there is enough points for assigning
	{
		do //do-while loop - first the loop is executed and then the condition is checked
		{
				cout << "\n" << "INCREASE STRENGTH OR VITALITY" << "\n" << endl;
				cout << "\033[0;32mAvailable stat points:\033[0m " << getStat() << endl;//this line changes its color
				cout << "0: NOT NOW" << endl;
				cout << "1: \033[0;34mSTRENGTH\033[0m" << endl;//this line changes its color
				cout << "2: \033[0;31mVITALITY\033[0m" << endl;//this line changes its color
				cin >> this->choice;

				while (cin.fail())//checks the user input and asks for new input if the old one is not valid
				{
					cout << "PLEASE TYPE AN INTEGER(0,1 or 2)!" << endl;
					cin.clear();
					cin.ignore(256, '\n');//ignoring 256 characters before the specified break stop in this case '\n' newline
					cin >> this->choice;
				}

				switch (this->choice) //choice is compared for equality below
				{
				case 0://if choice equals 0
                    return;
					break;

				case 1://if choice equals 1 - update minimum damage and maximum damage of player 
					this->strength++;
					setMinDamage(this->strength);
					setMaxDamage(this->strength + 2);
					this->statPoints--;
					cout << "\n" << "\033[0;32mSTRENGTH HAS BEEN UPDATED!\033[0m" << endl;
					cout << "\033[0;34mSTRENGTH:\033[0m " << getStrength() << endl;
					break;

				case 2://if choice equals 2 - updates vitality of player
                    this->vitality++;
					setMaxHP((this->vitality * 5) + (this->strength) + this->level * 5);
					this->statPoints--;
					cout << "\n" << "\033[0;32mVITALITY HAS BEEN UPDATED!\033[0m" << endl;
					cout << "\033[0;31mVITALITY:\033[0m " << getVitality() << endl;
					break;

				default://executes if the choice is different from the choices above
					cout << "\n" << "TYPE AN INTEGER (0 or 1)" << endl;
					updateStats();//call the function again
					break;
				}
		} while ((this->statPoints > 0) && (this->choice == 1 || this->choice == 2));//check the available stats and user input
	}
	
	else //executes if there is not enought stat points to assing
	{
		cout << "\n" << "\033[0;31mTHERE IS NO AVAILABLE STAT POINTS!\033[0m" << "\n" << endl;
	}
}

void Player::update()//updates player maxHp,setMinDamage and setMaxDamage
{
	setMaxHP((this->vitality * 5) + (this->strength) + (this->level * 5));
	setMinDamage(this->strength);
	setMaxDamage(this->strength + 2);
}

int Player::update_player_database()//updates or replaces row into the player database
{ 
    string sqliteFile = "database_game.db";
    try
    {
        sqlite::sqlite db( sqliteFile ); //connects to the database file
        auto cur = db.get_statement(); //creates cursor
  
        cur->set_sql("INSERT OR REPLACE INTO player " //insert or replace into an existing row in player table 
                     "(Name, Travel) "
                     "VALUES (?, ?);");
        
        cur->prepare();
        
        //Cursor is binded to getname function and travel variable
        cur->bind( 1 , getname());
        cur->bind( 2 , this->travel);
        cur->step();
        
        auto cur2 = db.get_statement();
        cur2->set_sql("INSERT OR REPLACE INTO stats "
                      "(Name, "
                      "Health, "
                      "Maximum_Health, "
                      "Maximum_Damage, "
                      "Minimum_Damage, "
                      "Level, "
                      "Experience, "
                      "Experience_next, "
                      "Gold, "
                      "Stat_points, "
                      "Strength, "
                      "Vitality) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");
        cur2->prepare();
        //Cursor is binded multiple times to different functions and variables
        cur2->bind( 1 , getname());
        cur2->bind( 2 , get_currHP());
        cur2->bind( 3 , get_maxHP());
        cur2->bind( 4 , getMaxDamage());
        cur2->bind( 5 , getMinDamage());
        cur2->bind( 6 , this->level);
        cur2->bind( 7 , this->exp);
        cur2->bind( 8 , this->expNext);
        cur2->bind( 9, this->gold);
        cur2->bind( 10 , this->statPoints);
        cur2->bind( 11 , this->strength);
        cur2->bind( 12 , this->vitality);

        cur2->step();
        
        auto cur3 = db.get_statement();
        cur3->set_sql("INSERT OR REPLACE INTO player_items "
                      "(Name, "
                      "Equipped_Weapon, "
                      "Equipped_Armor, "
                      "Weapon_Stats, "
                      "Armor_Stats, "
                      "Equipped_Jewell, "
                      "Jewell_Strength, "
                      "Jewell_Vitality) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?);");
        
        cur3->prepare();
        
        //Cursor is binded multiple times to different functions and variables
        cur3->bind( 1 , getname());
        cur3->bind( 2 , this->equippedWeapon);
        cur3->bind( 3 , this->equippedArmor);
        cur3->bind( 4 , this->currWeaponStats);
        cur3->bind( 5 , this->currArmorStats);
        cur3->bind( 6 , this->equippedJewell);
        cur3->bind( 7 , this->currJewellStrength);
        cur3->bind( 8 , this->currJewellVitality);
        
        cur3->step();
        cout << "\n" << "\033[0;32mGAME SAVED!\033[0m" << "\n" << endl;
    }
    catch( sqlite::exception e)//lines from 483 to 487 are taken from codio week 4
    {
        std::cerr << e.what() << endl;
        return 1;
    }
    return 0;
}

int Player::delete_player_entry()//deletes row of the player database
{
    string sqliteFile = "database_game.db";
    int choice;
    vector<string> charList;
    int i = 1;
    try
    {
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement();
        cur->set_sql("SELECT Name FROM player"
                     ";");
        cur->prepare();
        
        cout<<endl;
        cout << "WHICH SAVE YOU WANT TO DELETE?" << endl;
        cout << 0 << " - " << "Back" << endl;
        
        while(cur->step())
        {
            string name = cur->get_text(0);//get the names from player table
            cout << i << " - " << name << endl;
            charList.push_back(name);//store each name into the vector
            i += 1;
        }
        cout<<endl;
        cout<<"Choice: "<<endl;
        int vectorSize = charList.size();
        
        cin >> choice;
        
        while (cin.fail() || (choice > (vectorSize)))//checking if a user's input is in range and is an integer
            {
                cout << "PLEASE TYPE AN INTEGER!(between 0 and " << vectorSize << ")" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> choice;
            }
        
        if (choice == 0) //checks if the user choice is 0
            return 0;
        
        else //executes if the user choice is different than 0 and is integer
        {
            auto cur2 = db.get_statement();//create cursor
            cur2->set_sql("DELETE FROM player "//creates queries to delete a specific row with given name
                         "WHERE Name = ? "
                         ";");
            cur2->prepare();
            cur2->bind( 1 , charList[choice-1]);
            cur2->step();
        
            auto cur3 = db.get_statement();
            cur3->set_sql("DELETE FROM stats "//creates queries to delete a specific row with given name
                          "WHERE Name = ? "
                          ";");
            cur3->prepare();
            cur3->bind( 1 , charList[choice-1]);
            cur3->step();
            
            auto cur4 = db.get_statement();
            cur4->set_sql("DELETE FROM player_items "//creates queries to delete a specific row with given name
                         "WHERE Name = ? "
                         ";");
            cur4->prepare();
            cur4->bind( 1 , charList[choice-1]);
            cur4->step();
            cout << "\n" << "\033[0;32mSAVE DELETED!\033[0m" << "\n" << endl;
        }
    }
    catch( sqlite::exception e)//lines from 561 to 565 are taken from codio week 4
    {
        std::cerr << e.what() << endl;
        return 1;
    }
    return 0;
}

void Player::addExp(int exp)//add integer to the player exp
{
    this->exp += exp;
}

void Player::addGold(int gold)//add integer to the player gold
{
    this->gold += gold; 
}

void Player::setGold(int gold)//modifies player gold
{
    this->gold = gold;
}

void Player::addTravel(int travel)//add integer to the player travel
{
    this->travel += travel;
}

void Player::setTravel(int travel)//modifies player travel value
{
    this->travel = travel;
}

void Player::setLevel(int level)//modifies player level values
{
    this->level = level;
}

void Player::setExp(int exp)//modifies player exp value
{
    this->exp = exp;
}

void Player::setExpNext(int expNext)//modifies player expNext value
{
    this->expNext = expNext;
}

void Player::setStatPoints(int statPoints)//modifies player stat points value
{
    this->statPoints = statPoints;
}

void Player::addStrength(int strength)//add integer to the player strength
{
    this->strength += strength;
}

void Player::addVitality(int vitality)//add integer to the player vitality
{
    this->vitality += vitality;
}

void Player::setStrength(int strength)//modifies player strength value
{
    this->strength = strength;
}

void Player::setVitality(int vitality)//modifies player vitality value
{
    this->vitality = vitality;
}

void Player::setEquippedWeapon(string equippedWeapon)//modifies player equippedWeapon name value
{
    this->equippedWeapon = equippedWeapon;
}

void Player::setEquippedArmor(string equippedArmor)//modifies player equippedArmor namevalue
{
    this->equippedArmor = equippedArmor;
}

void Player::setCurrWeaponStats(int currWeaponStats)//modifies player weapon stats value
{
    this->currWeaponStats = currWeaponStats;
}

void Player::setCurrArmorStats(int currArmorStats)//modifies player armor stats value
{
    this->currArmorStats = currArmorStats;
}

void Player::setEquippedJewell(string equippedJewell)//modifies player equippedJewell name value
{
    this->equippedJewell = equippedJewell;
}

void Player::setJewellStats(int currJewellStrength, int currJewellVitality)//modifies player Jewell strength and vitality value
{
    this->currJewellStrength = currJewellStrength;
    this->currJewellVitality = currJewellVitality;
}