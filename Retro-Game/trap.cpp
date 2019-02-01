// File made by Dimitar Smilov
#include "trap.h" //incudes the .h file
#include "libsqlite.hpp" // incudes the libsqlite.hpp file

Trap::Trap()
{

	this->name; //declare trap attribute
	this->damage; //declare trap attribute
	this->defense; //declare trap attribute
	this->bonusGold; //declare trap attribute
	this->rarity; //declare trap attribute

}

Trap::~Trap()
{


}

void Trap::initialise(string name) //initialises the values of the objects
{
	this->damage = 0;
	this->defense = 0;
	this->name = name;
	this->bonusGold = 0;
	this->rarity = 0;
}
void Trap::stats() //prints the curent stats
{
	cout << "Damage" << this->damage << endl;
	cout << "Defense" << this->defense << endl;
	cout << "Name" << this->name << endl;
	cout << "Gold" << this->bonusGold << endl;
	cout << "Rarity" << this->rarity << endl;
}

void Trap::set_damage(int dam) // set the value of damage
{
	this->damage = dam;
}

void Trap::set_defense(int def) // set the value of defense
{
	this->defense = def;
}

void Trap::set_gold(int gold) // set the value of gold
{
	this->bonusGold = gold;
}

void Trap::set_rarity(int rar) // set the value of rarity
{
	this->rarity = rar;
}

Trap spikes; //create a new trap
void spike()
{
	spikes.initialise("Spikes");
    spikes.set_damage(20);
    spikes.set_rarity(1);
}

Trap poisonousSwamp; //create a new trap
void pswamp()
{
	poisonousSwamp.initialise("Poisonous Swamp");
    poisonousSwamp.set_damage(14);
    poisonousSwamp.set_rarity(0);
}

Trap needleWall; //create a new trap
void needle()
{
	needleWall.initialise("Needle Wall");
    needleWall.set_damage(12);
    needleWall.set_defense(40);
    needleWall.set_gold(20);
    needleWall.set_rarity(1);
}

Trap bearTrap; //create a new trap
void beart()
{
	bearTrap.initialise("Bear Trap");
    bearTrap.set_damage(18);
    bearTrap.set_rarity(0);
}

Trap flameThrower; //create a new trap
void flame()
{
    flameThrower.initialise("Flame Thrower");
    flameThrower.set_damage(25);
    flameThrower.set_defense(100);
    flameThrower.set_gold(35);
    flameThrower.set_rarity(0);
}

Trap explosiveThrower; //create a new trap
void exposive()
{
    explosiveThrower.initialise("Explosive Thrower");
    explosiveThrower.set_damage(22);
    explosiveThrower.set_defense(60);
    explosiveThrower.set_gold(30);
    explosiveThrower.set_rarity(1);
}

Trap lavaGround; //create a new trap
void lava()
{
    lavaGround.initialise("Lava Ground");
    lavaGround.set_damage(31);
    lavaGround.set_rarity(1);
}

Trap electricityPulser; //create a new trap
void electric()
{
    electricityPulser.initialise("Electricity Pulser");
    electricityPulser.set_damage(30);
    electricityPulser.set_defense(60);
    electricityPulser.set_gold(40);
    electricityPulser.set_rarity(0);
    
}

int create_trap_table() //create trap table in the database
{
    string sqliteFile = "database_game.db"; //assigning database file to a string variable
    
    try{
        sqlite::sqlite db( sqliteFile ); //connects to the database file
        auto cur = db.get_statement(); //creates cursor
        
        cur->set_sql("CREATE TABLE IF NOT EXISTS trap " //creates stats table
                     "(Name TEXT PRIMARY KEY "
                     ",Defense INTEGER "
                     ",Damage INTEGER "
                     ",Gold INTEGER "
                     ",Rarity INTEGER "
                     ");");
        cur->prepare(); //prepares the sql quarry
        cur->step(); //executes the sql qarry
    }
    catch( sqlite::exception e)
    {
        std::cerr << e.what() << endl; //catch all sql errors
        return 1;
    }
    return 0;
}

int update_trap_table()
{
    
    string sqliteFile = "database_game.db";
    
    try{
        sqlite::sqlite db( sqliteFile ); //connects to the database file
        auto cur = db.get_statement(); //create cursor
  
        cur->set_sql("INSERT OR REPLACE INTO trap (Name, Damage, Defense, Gold, Rarity) "
                     "VALUES (?, ?, ?, ?, ?);");
        
        //Cursor is binded multiple times to different functions and variables
        
        cur->prepare(); //spikes trap
        cur->bind( 1 , spikes.get_name());
        cur->bind( 2 , spikes.get_damage());
        cur->bind( 3 , spikes.get_defense());
        cur->bind( 4 , spikes.get_bonusGold());
        cur->bind( 5 , spikes.get_rare());
        cur->step();
        
        cur->prepare(); //poisonous swamp trap
        cur->bind( 1 , poisonousSwamp.get_name());
        cur->bind( 2 , poisonousSwamp.get_damage());
        cur->bind( 3 , poisonousSwamp.get_defense());
        cur->bind( 4 , poisonousSwamp.get_bonusGold());
        cur->bind( 5 , poisonousSwamp.get_rare());
        cur->step();
        
        cur->prepare(); //needle wall trap
        cur->bind( 1 , needleWall.get_name());
        cur->bind( 2 , needleWall.get_damage());
        cur->bind( 3 , needleWall.get_defense());
        cur->bind( 4 , needleWall.get_bonusGold());
        cur->bind( 5 , needleWall.get_rare());
        cur->step();
        
        cur->prepare(); //bear trap
        cur->bind( 1 , bearTrap.get_name());
        cur->bind( 2 , bearTrap.get_damage());
        cur->bind( 3 , bearTrap.get_defense());
        cur->bind( 4 , bearTrap.get_bonusGold());
        cur->bind( 5 , bearTrap.get_rare());
        cur->step();
        
        cur->prepare(); //flame thrower
        cur->bind( 1 , flameThrower.get_name());
        cur->bind( 2 , flameThrower.get_damage());
        cur->bind( 3 , flameThrower.get_defense());
        cur->bind( 4 , flameThrower.get_bonusGold());
        cur->bind( 5 , flameThrower.get_rare());
        cur->step();
        
        cur->prepare(); //explosive thrower
        cur->bind( 1 , explosiveThrower.get_name());
        cur->bind( 2 , explosiveThrower.get_damage());
        cur->bind( 3 , explosiveThrower.get_defense());
        cur->bind( 4 , explosiveThrower.get_bonusGold());
        cur->bind( 5 , explosiveThrower.get_rare());
        cur->step();
        
        
        cur->prepare(); //lava ground trap
        cur->bind( 1 , lavaGround.get_name());
        cur->bind( 2 , lavaGround.get_damage());
        cur->bind( 3 , lavaGround.get_defense());
        cur->bind( 4 , lavaGround.get_bonusGold());
        cur->bind( 5 , lavaGround.get_rare());
        cur->step();
        
        cur->prepare(); //electricity pulser trap
        cur->bind( 1 , electricityPulser.get_name());
        cur->bind( 2 , electricityPulser.get_damage());
        cur->bind( 3 , electricityPulser.get_defense());
        cur->bind( 4 , electricityPulser.get_bonusGold());
        cur->bind( 5 , electricityPulser.get_rare());
        cur->step();
    }
    catch( sqlite::exception e){
        std::cerr << e.what() << endl; //catch all sql errors
        return 1;
    }
    return 0;
}

int trapCreate() //calling all functions which are used to create each trap
{
    spike(); //calling function to create trap
    pswamp();
    needle();
    beart();
    flame();
    exposive();
    lava();
    electric();
    create_trap_table();
    update_trap_table();
    
	return 0;
}

