// File Made by Daniel Kanchev
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Character
{
public:
    //Constructor
    Character();
    //Destructor
    virtual ~Character();

    //Object Methods
    void initialize(string name);
    void dealDamage(int damageTaken);
    void restHP(int heal);
    bool isDead();
    void setMaxHP(int newMax);
    void setMinDamage(int newMin);
    void setMaxDamage(int newMax);
    int Attack();
    void setCurrHP(int newHP);
    void changeName(string newName);
    
    //Accessors
    inline const string& getname() const { return this->name; }
    inline const int& get_currHP() const { return this->currHP; }
    inline const int& get_maxHP() const { return this->maxHP; }
    inline const int& getMinDamage() const { return this->minDamage; }
    inline const bool& isPlayerCheck() const { return this->isPlayer; }
    inline const int& getMaxDamage() const { return this->maxDamage; }

protected:
    //Object Attributes
    string name;
    int currHP;
    int maxHP;
    int maxDamage;
    int minDamage;
    bool isPlayer;
    
};
#endif
