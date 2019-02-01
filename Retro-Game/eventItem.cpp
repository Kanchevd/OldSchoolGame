// File Made by Daniel Kanchev and Mitko Donchev
#include "Art/shieldAnimation.cpp"
#include "Art/weaponAnimation.cpp"
#include "Art/jewellAnimation.cpp"
//Start of Mitko Donchev's code
void equipWeapon(Player& player, string itemName,int itemStrength) //function to equip Weapon
{    
     int choice;
     if (player.getEquippedWeapon()  == "None") // we don't have a weapon equipped 
     {    
          cout<<"You equip "<<itemName<<'!'<<endl;
          //give player appropriate stats
          player.addStrength(itemStrength);
          player.setEquippedWeapon(itemName);
          player.setCurrWeaponStats(itemStrength);
     }
     else //we do have a weapon equipped 
     {    
          cout<<"You have "<<player.getEquippedWeapon()<<" as a weapon.It has a strength of "<<player.getCurrWeaponStats()<<". Do you want to replace it?"<<endl;
          cout<<"0:Yes"<<endl;
          cout<<"1:No"<<endl;
          choice = input_check(choice);
          this_thread::sleep_for (chrono::seconds(1)); //sleep
          if (choice == 0)// we choose to replace old item
          {   
              cout<<endl;
              cout<<"You replace "<<player.getEquippedWeapon()<<" with "<<itemName<<'.'<<endl;
              player.addStrength(itemStrength-player.getCurrWeaponStats());//removes previous stat
              player.setEquippedWeapon(itemName);
              player.setCurrWeaponStats(itemStrength);
          }
          else // we choose not to replace        
                 cout<<"You chose to stick with your current item."<<endl;
     }
}
void equipArmor(Player& player, string itemName,int itemVitality) //function to equip Armor
{    
     int choice;
     if(player.getEquippedArmor() == "None") // we don't have armor equipped 
     {          
          cout<<"You equip "<<itemName<<'!'<<endl;
          //give player appropriate stats
          player.addVitality(itemVitality); 
          player.setEquippedArmor(itemName);
          player.setCurrArmorStats(itemVitality);
     }
     else //we do have armor equipped 
     {  
           cout<<endl;
           cout<<"You have "<<player.getEquippedArmor()<<" as armor.It has a vitality of "<<player.getCurrArmorStats()<<". Do you want to replace it?"<<endl;
           cout<<"0:Yes"<<endl;
           cout<<"1:No"<<endl;
           choice = input_check(choice);
           this_thread::sleep_for (chrono::seconds(1)); //sleep
           if (choice == 0)// we equip the new item
           {   
               cout<<endl;
               cout<<"You replace "<<player.getEquippedArmor()<<" with "<<itemName<<'.'<<endl;
               player.addVitality(itemVitality-player.getCurrArmorStats()); //removes previous stats
               player.setEquippedArmor(itemName);
               player.setCurrArmorStats(itemVitality);
           }
           else // we choose not to re-equip
               cout<<"You chose to stick with your current item."<<endl;
     }
}
void equipJewell(Player& player, string itemName,int itemStrength,int itemVitality) //function to equip Jewell
{    
     int choice;
     if(player.getEquippedJewell() == "None") // we don't have a jewell equipped 
     {          
          cout<<"You equip "<<itemName<<'!'<<endl;
          //give player appropriate stats
          player.addStrength(itemStrength); 
          player.addVitality(itemVitality);
          player.setEquippedJewell(itemName);
          player.setJewellStats(itemStrength,itemVitality);
     }
     else //we do have a jewell equipped 
     {  
           cout<<endl;
           cout<<"You have "<<player.getEquippedJewell()<<" as a jewell."<<endl;
           cout<<"It has a strength of "<<player.getCurrJewellStrength()<<" and vitality of "<<player.getCurrJewellVitality();
           cout<<". Do you want to replace it?"<<endl;
           cout<<"0:Yes"<<endl;
           cout<<"1:No"<<endl;
           choice = input_check(choice);
           this_thread::sleep_for (chrono::seconds(1)); //sleep
           if (choice == 0)// we equip the new item
           {   
               cout<<endl;
               cout<<"You replace "<<player.getEquippedJewell()<<" with "<<itemName<<'.'<<endl;
               player.addVitality(itemVitality-player.getCurrJewellVitality()); //removes previous stats
               player.addStrength(itemStrength-player.getCurrJewellStrength());
               player.setEquippedJewell(itemName);
               player.setJewellStats(itemStrength,itemVitality);
           }
           else // we choose not to replace
               cout<<"You chose to stick with your current item."<<endl;
     }
}
//End of Mitko Donchev's code
//Start of Daniel Kanchev's code
int eventItem(Player& player,int travel)// if we encounter an item
{   
    vector<string> Items; // holds item names that first query returns
    srand(time(0));  //random algorithm  
    itemCreate();   //creates the 'items' database 
    int itemRarityPrc = rand()% 100+1,itemRarity,itemStrength=0,itemVitality=0,itemValue,itemInteger,equipChoice;
    string itemType,itemName;    
    
    if (itemRarityPrc > 95) //odds we get a rare item,result used in query
        itemRarity = 1;
    else 
        itemRarity = 0;
    
    
    if (itemRarityPrc>66) // 1/3 odds   on the type of item,result used in query
        itemType = "Armor";    
    else if (itemRarityPrc>34)
        itemType = "Weapon";
    else 
        itemType = "Jewell";
    try
    {  
        string sqliteFile = "database_game.db";
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement();
        cur->set_sql("SELECT Name FROM items "  // All items that fit our random criteria
                     "WHERE Rarity = ? AND Type = ? "
                     ";");
        cur->prepare();
        cur->bind(1,itemRarity); 
        cur->bind(2,itemType); 
        while(cur->step())
           Items.emplace_back(cur->get_text(0));  //add all fitting items to a list
        
       itemInteger= rand()% (Items.size())+0;   // random integer from 0 to the amount of items
       itemName = Items[itemInteger]; // get item at that integer in the vector
       
       auto cur2 = db.get_statement();
       // query to get the item's stats
       cur2->set_sql("SELECT Strength,Vitality,Value FROM items "
                    "WHERE Name = ? "
                    ";");
       cur2->prepare();
       cur2->bind(1,itemName);
       cur2->step();     
       //assign values and print stats          
       if (itemType == "Weapon") 
       {
            itemStrength = cur2->get_int(0);
            weaponAnimation();
       }
       else if (itemType == "Armor")
       {    
            
            itemVitality = cur2->get_int(1);
            shieldAnimation();
       }
       else 
       {
            itemStrength = cur2->get_int(0);
            itemVitality = cur2->get_int(1);
            jewellAnimation();
       }
       itemValue = cur2->get_int(2);
       cout<<"On mile "<<travel<<", you found an item!"<<endl;
       cout<<endl;
       cout<<"Stats:"<<endl;
       cout<<endl;
       cout<<"Type:"<<itemType<<endl;
       cout<<"Name:"<<itemName<<endl;
       if (itemStrength!=0)
            cout<<"Strength:"<<itemStrength<<endl;
       if (itemVitality!=0)
            cout<<"Vitality:"<<itemVitality<<endl;
       cout<<"Value:"<<itemValue<<endl;
       if (itemRarity == 1)
            cout<<"Rarity:RARE!"<<endl;
       else
            cout<<"Rarity:Common"<<endl; 
        
       this_thread::sleep_for (chrono::seconds(1)); //sleep
       cout<<endl;
       cout<<"Equip it?"<<endl; 
       cout<<"0:Yes"<<endl;
       cout<<"1:No"<<endl;
       cout<<endl;
       equipChoice = input_check(equipChoice);
       cout<<endl;
       if (equipChoice==0)  // if we equip the item  
       {   
           this_thread::sleep_for (chrono::seconds(1)); //sleep
           if (itemType == "Weapon") // is a weapon
                equipWeapon(player,itemName,itemStrength);             
           else if (itemType == "Armor")
                equipArmor(player,itemName,itemVitality);
           else 
                equipJewell(player,itemName,itemStrength,itemVitality);
       }
       else // we don't want to equip the item
           cout<<"You chose not to equip the item."<<endl;
 
      cout<<endl;
      player.update();
    } // end of try
    
    catch( sqlite::exception e)
    {
        std::cerr << e.what() << endl;
        return 1;
    }
    return 0;   
}
// End of Daniel Kanchev's code