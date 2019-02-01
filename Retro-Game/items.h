/* This file is written by Mitko Donchev */
#ifndef ITEMS_H
#define ITEMS_H
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "libsqlite.hpp"
using namespace std;

class Item
{
public:

    //Constructor 
    Item();
    
    //Destructor
    virtual ~Item();
    
    //Functions
    void init(string name, bool rarity); 
    int items_DB();
    
    //Accessors to get the value of the variables
    inline const string& get_name() const { return this->name; }
    inline const int& get_value() const { return this->value; }
    inline const bool& isRare() const { return this->rarity; }
    
    //Modifiers       
    void setRarity(bool rarity);   

protected:
    //Private variables accessible only from the classes
    int value;
    
private:

    //Private variables accessible only from the class
    string name;
    bool rarity;
};

class Armor : public Item
{
public:
    Armor();
    
    virtual ~Armor();
    
    void init(string name, bool rarity);
    void setValue();
    void setVitality(int vitality);
    
    inline const int& get_vitality() const { return this->vitality; }
    inline const int& get_bonusVitality() const { return this->bonusVitality; }

private:
    int vitality;
    int bonusVitality;

};

class Weapon : public Item
{
public:
    Weapon();
    
    virtual ~Weapon();
    void init(string name, bool rarity);
    void setValue();
    void setStrenght(int strenght);
    
    inline const int& get_strenght() const { return this->strenght; }
    inline const int& get_bonusStrenght() const { return this->bonusStrenght; }

private:
    int strenght;
    int bonusStrenght;

};

class Jewell : public Item
{
public:
    Jewell();

    virtual ~Jewell();
    void init(string name, bool rarity);
    void setValue();
    void setStrenght(int strenght);
    void setVitality(int vitality);
    
    inline const int& get_vitality() const { return this->vitality; }
    inline const int& get_bonusVitality() const { return this->bonusVitality; }
    inline const int& get_strenght() const { return this->strenght; }
    inline const int& get_bonusStrenght() const { return this->bonusStrenght; }

private:
    int strenght;
    int bonusStrenght;
    int vitality;
    int bonusVitality;
};

#endif