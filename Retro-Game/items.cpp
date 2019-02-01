// File made by Mitko Donchev
#include "items.h" //including .h file 

Item::Item() 
{
    this->name; //declare item attribute
    this->value; //declare item attribute
    this->rarity; //declare item attribute
}
Item::~Item()
{

}

void Item::init(string name, bool rarity) //initializes values to object
{
    this->name = name;
    this->rarity = rarity;
}

void Item::setRarity(bool newRarity) //set the new rarity
{
    this->rarity = newRarity;
}




//Weapon

Weapon Sword;   //create new weapon
Weapon Sword1;  

Weapon Dagger; //create new weapon
Weapon Dagger1; 

Weapon Katana; //create new weapon
Weapon Katana1; 

Armor Shield; //create new armor
Armor Shield1; 

Armor Chest; //create new armor
Armor Chest1; 

Armor Boots; //create new armor
Armor Boots1; 

Jewell Ring; //create new jewell
Jewell Ring1; 

Jewell Necklace; //create new jewell
Jewell Necklace1; 



void abv() 
{
	Sword.init("Zweihander", true); //choose a name and rarity 
	Sword1.init("Yasariz", false); //choose a name and rarity 
    
    Dagger.init("Lazarus", true); //choose a name and rarity 
    Dagger1.init("Amnesia", false); //choose a name and rarity 
    
    Katana.init("Severance", true); //choose a name and rarity 
    Katana1.init("Remorse", false); //choose a name and rarity 
    
    Shield.init("Nirvana", true);
    Shield1.init("Ragnarok", false);
    
    Chest.init("Greatplate", true);
    Chest1.init("Breastplate", false);
    
    Boots.init("Oathkeeper", true);
	Boots1.init("Greatboots", false);
    
    Ring.init("Precious",true);
    Ring1.init("Sun Ring",false);
    
    Necklace.init("The Zircon",true);
    Necklace1.init("The Pearl",false);
}
Weapon::Weapon()
{
    this->strenght; //declare Weapon attribute
    this->bonusStrenght; //declare Weapon attribute
}

Weapon::~Weapon()
{
    
}

void Weapon::init(string name, bool rarity) //function for calculating Weapon attribute
{   
    Item::init(name,rarity);
    srand(time(0)); // makes it so rand() produces different numbers each time
    this->strenght = rand()% 4 + 1; //random number generated
    
    if (isRare() == true) //check if the item is rare or not 
    {
        srand(time(0)); // makes it so rand() produces different numbers each time
        this->bonusStrenght = rand()% 6 + 3; //random number generated
        this->strenght += bonusStrenght;
    } 
}

void Weapon::setStrenght(int newStrenght) //adding bonus strenght
{
    this->strenght += newStrenght + bonusStrenght;
}

void Weapon::setValue() //set the correct value
{
    this->value = 0 + ( 5 * this->strenght);
	if (isRare() == true) //check if the item is rare or not 
	{
        this->value += this->bonusStrenght * 5;
	}
}

    
    
//Armor


void abc()
{
    
}

Armor::Armor() 
{
    this->vitality; //declare Armor attribute
    this->bonusVitality; //declare Armor attribute
}

Armor::~Armor()
{
    
}

void Armor::init(string name, bool rarity) //function for calculating Armor attribute
{
    Item::init(name, rarity);
    srand(time(0)); // makes it so rand() produces different numbers each time
    this->vitality = rand()% 4 + 1; //random number generated
    
    if (isRare() == true) //check if the item is rare or not 
    {
        srand(time(0)); // makes it so rand() produces different numbers each time
        this->bonusVitality = rand()% 6 + 3; //random number generated
        this->vitality += bonusVitality;
    }
    
}

void Armor::setVitality(int newVitality) //adding bonus vitality
{
    this->vitality += newVitality + bonusVitality;
}

void Armor::setValue() //set the correct value
{
    this->value = 0 + ( 5 * this->vitality);
	if (isRare() == true) //check if the item is rare or not 
	{
        this->value += this->bonusVitality * 5;
	}
}

//Jewell

void abb()
{
    
}

Jewell::Jewell() 
{
    this->vitality; //declare Jewell attribute
    this->bonusVitality; //declare Jewell attribute
    this->strenght; //declare Jewell attribute
    this->bonusStrenght; //declare Jewell attribute
}

Jewell::~Jewell()
{
    
}

void Jewell::init(string name, bool rarity) //function for calculating Jewell attribute
{
    Item::init(name, rarity);
    srand(time(0)); // makes it so rand() produces different numbers each time
    this->vitality = (rand()% 4 + 0) - 2; //random number generated
    if (this->vitality > 1)
    {
        this->strenght = (rand()% 2 + 1) - 2; //random number generated
    }
    else
    {
        this->strenght = rand()% 3 + 1; //random number generated
    }
    
    if (isRare() == true) //check if the item is rare or not 
    { 
        srand(time(0)); // makes it so rand() produces different numbers each time
        if (this->vitality > 0)
        {
            this->bonusVitality = rand()% 3 + 3; //random number generated
            this->vitality += bonusVitality;
        }
        else
        {
            this->bonusStrenght = rand()% 4 + 3; //random number generated
            this->strenght += bonusStrenght;
        }
    }
    
}

void Jewell::setVitality(int newVitality) //adding bonus vitality
{
    this->vitality += vitality + bonusVitality;
}

void Jewell::setStrenght(int newStrenght) //adding bonus strenght
{
    this->strenght += strenght + bonusStrenght;
}

void Jewell::setValue() //set the correct value
{
    this->value = 5 + ( 5 * this->strenght);
	if (isRare() == true) //check if the item is rare or not 
	{
        this->value += this->bonusStrenght * 5;
	}

    this->value += 5 + ( 5 * this->vitality);
	if (isRare() == true) //check if the item is rare or not 
	{
        this->value += this->bonusVitality * 5;
	}
}


int items_DB() //creates item table in the database
{
    string sqliteFile = "database_game.db"; //assigning database file to a string variable
    
    try{
        sqlite::sqlite db( sqliteFile ); //connects to the database file
        auto cur = db.get_statement(); //creates cursor
        
        cur->set_sql("CREATE TABLE IF NOT EXISTS items " //creates stats table
                     "(Name TEXT PRIMARY KEY "
                     ",Strength INTEGER "
                     ",Vitality INTEGER "
                     ",Rarity TEXT "
                     ",Type TEXT "
                     ",Value INTEGER "
                     ");");
         
        cur->prepare(); //prepares the sql quarry
        cur->step(); //executes the sql quarry
        
    }
    catch( sqlite::exception e){
        std::cerr << e.what() << endl; //catch all sql errors
        return 1;
    }
    return 0;
}
int insert()
{
    
    string sqliteFile = "database_game.db";
    
    try{
        sqlite::sqlite db( sqliteFile ); //connects to the database file
        auto cur = db.get_statement(); //creates cursor
        
        cur->set_sql("INSERT OR REPLACE INTO items (Name, Strength, Vitality, Rarity, Type, Value) " //insert or replace into an existing row in item table 
                     "VALUES (?, ?, ?, ?, ?, ?) ;");
        
        //Cursor is binded multiple times to different functions and variables
         
        cur->prepare();   // legendary shield
        cur->bind(1,Shield.get_name());
        cur->bind(3,Shield.get_vitality());
        cur->bind(4,Shield.isRare());
        cur->bind(5,"Armor");
        cur->bind(6,Shield.get_value());
        cur->step();
        
        cur->prepare(); // second shield
        cur->bind(1,Shield1.get_name());
        cur->bind(3,Shield1.get_vitality());
        cur->bind(4,Shield1.isRare());
        cur->bind(5,"Armor");
        cur->bind(6,Shield1.get_value());                  
        cur->step();
        
        cur->prepare();   // legendary chest
        cur->bind(1,Chest.get_name());
        cur->bind(3,Chest.get_vitality());
        cur->bind(4,Chest.isRare());
        cur->bind(5,"Armor");
        cur->bind(6,Chest.get_value());
        cur->step();
        
        cur->prepare();   // second chest
        cur->bind(1,Chest1.get_name());
        cur->bind(3,Chest1.get_vitality());
        cur->bind(4,Chest1.isRare());
        cur->bind(5,"Armor");
        cur->bind(6,Chest1.get_value());
        cur->step();
        
        cur->prepare(); // legendary boots
        cur->bind(1,Boots.get_name());
        cur->bind(3,Boots.get_vitality());
        cur->bind(4,Boots.isRare());
        cur->bind(5,"Armor");
        cur->bind(6,Boots.get_value());                  
        cur->step();
        
        cur->prepare(); // second boots
        cur->bind(1,Boots1.get_name());
        cur->bind(3,Boots1.get_vitality());
        cur->bind(4,Boots1.isRare());
        cur->bind(5,"Armor");
        cur->bind(6,Boots1.get_value());                  
        cur->step();
        
        cur->prepare(); // legendary sword
        cur->bind(1,Sword.get_name());
        cur->bind(2,Sword.get_strenght());
        cur->bind(4,Sword.isRare());
        cur->bind(5,"Weapon");
        cur->bind(6,Sword.get_value());
        cur->step();
        
        cur->prepare(); // second sword
        cur->bind(1,Sword1.get_name());
        cur->bind(2,Sword1.get_strenght());
        cur->bind(4,Sword1.isRare());
        cur->bind(5,"Weapon");
        cur->bind(6,Sword1.get_value());
        cur->step();
        
        cur->prepare(); // legendary dagger
        cur->bind(1,Dagger.get_name());
        cur->bind(2,Dagger.get_strenght());
        cur->bind(4,Dagger.isRare());
        cur->bind(5,"Weapon");
        cur->bind(6,Dagger.get_value());
        cur->step();
        
        cur->prepare(); // second dagger
        cur->bind(1,Dagger1.get_name());
        cur->bind(2,Dagger1.get_strenght());
        cur->bind(4,Dagger1.isRare());
        cur->bind(5,"Weapon");
        cur->bind(6,Dagger1.get_value());
        cur->step();
        
        cur->prepare(); // legendary katana
        cur->bind(1,Katana.get_name());
        cur->bind(2,Katana.get_strenght());
        cur->bind(4,Katana.isRare());
        cur->bind(5,"Weapon");
        cur->bind(6,Katana.get_value());
        cur->step();
        
        cur->prepare(); // second katana
        cur->bind(1,Katana1.get_name());
        cur->bind(2,Katana1.get_strenght());
        cur->bind(4,Katana1.isRare());
        cur->bind(5,"Weapon");
        cur->bind(6,Katana1.get_value());
        cur->step();
        
        cur->prepare(); // legendary ring
        cur->bind(1,Ring.get_name());
        cur->bind(2,Ring.get_strenght());
        cur->bind(3,Boots1.get_vitality());
        cur->bind(4,Ring.isRare());
        cur->bind(5,"Jewell");
        cur->bind(6,Ring.get_value());
        cur->step();
        
        cur->prepare(); // second ring
        cur->bind(1,Ring1.get_name());
        cur->bind(2,Ring1.get_strenght());
        cur->bind(3,Boots1.get_vitality());
        cur->bind(4,Ring1.isRare());
        cur->bind(5,"Jewell");
        cur->bind(6,Ring1.get_value());
        cur->step();
        
        cur->prepare(); // legendary necklace
        cur->bind(1,Necklace.get_name());
        cur->bind(2,Necklace.get_strenght());
        cur->bind(3,Boots1.get_vitality());
        cur->bind(4,Necklace.isRare());
        cur->bind(5,"Jewell");
        cur->bind(6,Necklace.get_value());
        cur->step();
        
        cur->prepare(); // second necklace
        cur->bind(1,Necklace1.get_name());
        cur->bind(2,Necklace1.get_strenght());
        cur->bind(3,Boots1.get_vitality());
        cur->bind(4,Necklace1.isRare());
        cur->bind(5,"Jewell");
        cur->bind(6,Necklace1.get_value());
        cur->step();
        
    }
    catch( sqlite::exception e){
        std::cerr << e.what() << endl; //catch all sql errors
        return 1;
    }
    return 0;
}
int itemCreate(){ //calling all functions which are used to crate each item
    
    abv();
    items_DB();
    
    Shield.setValue(); //calling set value function
    Shield1.setValue();
    
    Chest.setValue();
    Chest1.setValue();
    
    Boots.setValue();
    Boots1.setValue();
    
    Sword.setValue();
    Sword1.setValue();
    
    Dagger.setValue();
    Dagger1.setValue();
    
    Katana.setValue();
    Katana1.setValue();
    
    Ring.setValue();
    Ring1.setValue();
    
    Necklace.setValue();
    Necklace1.setValue();
    
    insert();
    return 0;
}