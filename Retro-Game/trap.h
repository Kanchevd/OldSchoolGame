#ifndef TRAP_H
#define TRAP_H
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Trap
{
public:

	//Constructor
	Trap();

	//Destructor
	virtual ~Trap();

	//Functions
	void initialise(string name);
	void stats();

	//Accessors
	inline const string& get_name() const { return this->name; }
	inline const int& get_damage() const { return this->damage; }
	inline const int& get_defense() const { return this->defense; }
	inline const int& get_rare() const { return this->rarity; }
	inline const int& get_bonusGold() const { return this->bonusGold; }

	//Modifiers
	void set_damage(int dam);
	void set_defense(int def);
	void set_rarity(int rar);
	void set_gold(int gold);

private:

	string name;
	int damage;
	int defense;
	int rarity;
	int bonusGold;
};
#endif
