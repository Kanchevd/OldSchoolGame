/*The whole file is written by Iliyan Mladenov */


#include "game.h"
#include "EventGenerator.cpp"
#include "Shop.cpp"
#include "loading_screen.cpp"
#include "Art/startBanner.cpp"
Game::Game()
{
	this->choice = 0;
	this->playing = true;
	this->player;
}

Game::~Game()
{

}

void Game::initialStart()//showing loading screen and the banner to the user when the game is run
{
    loading_Screen();
    startBanner();
}

void Game::initialize() // function for creating new character or selecting an existing one from the database
{

    string name;
    cout << "Do you have an exising character?" << endl;
    cout << "0:Yes" << endl;
    cout << "1:No" << endl;
    cout << "Choice: ";
    cin >> this->choice;
    while (cin.fail() || (this->choice != 0 && this->choice != 1))//checks the user input and asks for new input if the old one is not valid
    {
       cout << "PLEASE TYPE AN INTEGER!(0 or 1)" << endl;
       cin.clear();
       cin.ignore(256, '\n');//ignoring 256 characters before the specified break stop in this case '\n' newline
       cin >> this->choice;
    }
        
    if(this->choice == 1) //executes if the user's choice is 1
    {
        cout << endl;
        cout << "Type your character name!" << endl;
        cin.ignore(256, '\n');//ignoring 256 characters before the specified break stop in this case '\n' newline
        getline(cin, name);
        while (name.size() == 0) // checks if the user typed an empty name
        {
            cout << "Please type your character name!" << endl;
            getline(cin, name);
        }
        player.initialize(name); //creates character with given name as input
    }
	else //executes if the user's input is different than 1 and it is integer
    {
        sleep(1);
        cout << "\033[2J\033[1;1H"; //clears the terminal
        if ((player.count_player_names() == 1) || (player.count_player_names() == 2))//executes if there are not any entries in 'player' database
        {
            cout << "\n" << "THERE ARE NO ENTRIES!" << "\n" << endl;
            cout << "Type your character name!" << endl;
            cin.ignore(256, '\n');//ignoring 256 characters before the specified break stop in this case '\n' newline
            getline(cin, name);
            while (name.size() == 0) // checks if the user typed an empty name
            {
                cout << "Please type your character name!" << endl;
                getline(cin, name);
            }
            player.initialize(name); //creates character with given name as input
        }
        else //executes if there are any entries in 'player' database
        {
            sleep(1);
            cout << "\033[2J\033[1;1H";//clears the terminal
            if(player.load_player_database() == 0) // load_player_database function is run and if the output is 0 then the if statement is executed
                initialize(); //executes the initialize function again
            
        }
            
        
    }
}

void Game::mainMenu() //the main menu of the game
{   
    int monsters=0,items=0; //statistics for the user at the end of the game
    do //do-while loop - first the loop is executed and then the condition is checked
    {
        sleep(1);
        cout << "\033[2J\033[1;1H";//clears the terminal
        cout << "MAIN MENU" << endl << endl;
        cout << "0: Quit" << endl;
        cout << "1: Travel" << endl;
        cout << "2: Shop" << endl;
        cout << "3: Spend stats" << endl;
        cout << "4: Rest" << endl;
        cout << "5: Character Sheet" << endl;
        cout << "6: Save game" << endl;
        cout << "7: Load save" << endl;
        cout << "8: Delete save" << endl << endl;
        cout << "Choice: " << endl;
	
        cin >> this->choice;
        while (cin.fail()) //checks the user input and asks for new input if the old one is not valid
        {
            cout << "PLEASE TYPE AN INTEGER!" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> this->choice;
        }
	
        switch (this->choice) //choice is compared for equality below
		{
            case 0: //if the choice is equal to 0 - game ends
                playing = false;
                break;
        
            case 1: //if the choice is equal to 1 - executes eventGen function
                playing = eventGen(player, player.getTravel(),monsters,items);
                break; 
             
            case 2: //if the choice is equal to 2 - executes shop function
                cout << "\033[2J\033[1;1H";//clears the terminal
                shop(player);
                break;

            case 3: //if the choice is equal to 3 - executes updateStats function on the existing 'player' object
                cout << "\033[2J\033[1;1H";//clears the terminal
                player.updateStats();
                break;

            case 4: //if the choice is equal to 4 - executes rest function on the existing 'player' object
                cout << "\033[2J\033[1;1H";//clears the terminal
                player.rest();
                break;

            case 5://if the choice is equal to 5 - executes printStats on the existing 'player' object
                cout << "\033[2J\033[1;1H";//clears the terminal
                player.printStats(); 
                sleep(5);
                break;
                
            case 6://if the choice is equal to 6 - create database tables if there is none and updates them 
                cout << "\033[2J\033[1;1H";//clears the terminal
                player.create_player_table();
                player.update_player_database();
                break;
                
            case 7://if the choice is equal to 7 - loads information from the database into the game
                cout << "\033[2J\033[1;1H";//clears the terminal
                player.load_player_database();
                break;
                
            case 8://if the choice is equal to 8 - delete entry from the database
                cout << "\033[2J\033[1;1H";//clears the terminal
                player.delete_player_entry();
                break;

            default: //executes if the choice is different from the choices above
                cout << "\n" << "WRONG INPUT!" << "\n" << endl;
                break;
		}
   
    }while((player.get_currHP()>0) && (playing != false)); //checks if the player health is above 0 and playing variable is true
	
}
