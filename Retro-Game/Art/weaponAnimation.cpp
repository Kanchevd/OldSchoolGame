// File Made by Daniel Kanchev
//http://www.asciiworld.com/-Blades-.html
#include<iostream>
#include<unistd.h>
#include<string>
using namespace std;
int weaponAnimation(){
    for(int i =0;i<20;i++)
    {
     cout << "\033[2J\033[1;1H";      
     cout<<string(i, ' ')<<"             _____                                        "<<endl;  
     cout<<string(i, ' ')<<"             |   |                                        "<<endl; 
     cout<<string(i, ' ')<<".__.         |   |________________________________         "<<endl;        
     cout<<string(i, ' ')<<"|  |_________|   |                                 \\      "<<endl;          
     cout<<string(i, ' ')<<"|  |         |   |__________________________________\\    "<<endl;            
     cout<<string(i, ' ')<<"|  |_________|   |                                  /     "<<endl;         
     cout<<string(i, ' ')<<"|__|         |   |________________________________ /       "<<endl;           
     cout<<string(i, ' ')<<"             |   |                                        "<<endl; 
     cout<<string(i, ' ')<<"             |___|                                        "<<endl;
     usleep(40000);                                                                        
    }
    cout<<endl;
    return 0;

}
