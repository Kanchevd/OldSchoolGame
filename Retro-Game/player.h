/*The whole file is written by Iliyan Mladenov */
#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include <time.h>
#include <math.h>
#include "libsqlite.hpp"

using namespace std;

class Player: public Character
{
public:
	
    //Constructor
	Player();
	
    //Destructor
	virtual ~Player();

	//Functions 
	void initialize(string name);
	void printStats() const;
	void rest();
    int create_player_table();
    int load_player_database();
    int count_player_names();

	//Accessors to get the value of the variables
	inline const double getTravel() const { return this->travel; }
	inline const int getLevel() const { return this->level; }
	inline const int getExp() const { return this->exp; }
	inline const double getExpNext() const { return this->expNext; }
	inline const int getGold() const { return this->gold; }
	inline const int getStrength() const { return this->strength; }
	inline const int getVitality() const { return this->vitality; }
	inline const int getStat() const { return this->statPoints; }
    inline const string getEquippedArmor() const { return this->equippedArmor; }
    inline const string getEquippedWeapon() const { return this->equippedWeapon; }
	inline const int getCurrWeaponStats() const { return this->currWeaponStats; }
	inline const int getCurrArmorStats() const { return this->currArmorStats; }
    inline const string getEquippedJewell() const { return this->equippedJewell; }
    inline const int getCurrJewellStrength() const { return this->currJewellStrength; }
    inline const int getCurrJewellVitality() const { return this->currJewellVitality; }

	//Modifiers
	void levelUp();
    void updateStats();
    void update();
    int update_player_database();
    int delete_player_entry();
    
    void addExp(int exp);
    void addGold(int gold);
    void setGold(int gold);
    void addTravel(int travel);
    void setTravel(int travel);
    void setLevel(int level);
    void setExp(int exp);
    void setExpNext(int expNext);
    void setStatPoints(int statPoints);
    void addStrength(int strength);
    void addVitality(int vitality);
    void setStrength(int strength);
    void setVitality(int vitality);
    
    void setEquippedWeapon(string equippedWeapon);
    void setEquippedArmor(string equippedArmor);
    void setCurrWeaponStats(int currWeaponStats);
    void setCurrArmorStats(int currArmorStats);
    
    void setEquippedJewell(string equippedJewell);
    void setJewellStats (int currJewellStrength, int currJewellVitality);

private:
    
    //Private variables accessible only from the class
	int choice;
	int random;
	int travel;

	int level;
	int exp;
	int expNext;

	int gold;

	int statPoints;
	
	int strength;
	int vitality;
    
    string equippedWeapon;
    string equippedArmor;
    int currWeaponStats;
    int currArmorStats;
    
    string equippedJewell;
    int currJewellStrength;
    int currJewellVitality;
};
#endif
