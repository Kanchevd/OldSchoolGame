// File Made by Daniel Kanchev
#include "character.h"

Character::Character() //declares character object attribute
{
	this->name;
	this->maxHP;
	this->currHP;
	this->minDamage;
     this->maxDamage;

}

Character::~Character() 
{

}
void Character::initialize(string name="Ivan") //initializes values to object
{
    this->name = name;
    this->maxHP = 100;
    this->currHP = 100;
    this->minDamage = 5;
    this->maxDamage = 15;
    
}
void Character::dealDamage(int damageTaken) //reduces character HP
{

   if (damageTaken >  this->currHP && damageTaken>=0)
		 this->currHP = 0;
	else this->currHP =  this->currHP - damageTaken;
}

void Character::restHP(int heal) //restores character HP
{
   if ( this->currHP + heal > this->maxHP && heal>0)
       this->currHP = this->maxHP;
   else  this->currHP =  this->currHP + heal;
}

bool Character::isDead() //checks if character is dead
{
   if (this->currHP == 0)
       return true;
   else 
       return false;
}

void Character::setMaxHP(int newMax) // sets character's max MP at a value
{
    if (newMax>0)
    {
       if (this->currHP>newMax)
           this->currHP = newMax;
       this->maxHP = newMax; 
    }
}

int Character::Attack() //returns a random number inbetween character's min and max HP
{
    return rand()% (maxDamage-minDamage)+minDamage;
}

void Character::setMinDamage(int newMin) // sets character's min DMG at a value
{
   if(newMin>0)
       this->minDamage = newMin;
}

void Character::setMaxDamage(int newMax) // sets character's max DMG at a value
{
   if(newMax>0)
       this->maxDamage = newMax;
}

void Character::setCurrHP(int newHP) // sets character's current HP at a value
{    
    if(newHP>0)
       this->currHP = newHP;
}

void Character::changeName(string newName) //changes character name
{
   this->name = newName;
}

