// File Made by Daniel Kanchev
// https://manytools.org/hacker-tools/convert-images-to-ascii-art/
#include<unistd.h>
void mysteryImage()
{    
     cout<< "\033[2J\033[1;1H";
     cout<<"\n\n";
     cout<<"                         %&@@@@@@@@@&.            "<<endl; 
     cout<<"                  *@@@@@@@@@@@@@@@@@@@@@@@@%      "<<endl; 
     cout<<"                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@    "<<endl; 
     cout<<"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&   "<<endl; 
     cout<<"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   "<<endl; 
     cout<<"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/  "<<endl; 
     cout<<"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  "<<endl; 
     cout<<"               @@@@@@       @@@@@@       @@@@@@@  "<<endl; 
     cout<<"               @@@@@@       @@@@@@       @@@@@@@  "<<endl; 
     cout<<"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  "<<endl; 
     cout<<"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  "<<endl; 
     cout<<"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%  "<<endl; 
     cout<<"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   "<<endl; 
     cout<<"               (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   "<<endl; 
     cout<<"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,   "<<endl; 
     cout<<"                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@    "<<endl; 
     cout<<"                  @@@@@@@@@@@@@@@@@@@@@@@@@@@,    "<<endl; 
     cout<<"                   @@@@@@@@@@@@@@@@@@@@@@@@@      "<<endl; 
     cout<<"                     @@@@@@@@@@@@@@@@@@@@@        "<<endl; 
     cout<<"                       @@@@@@@@@@@@@@@@@          "<<endl; 
     cout<<"                         &@@@@@@@@@@@@            "<<endl; 
     cout<<"                            @@@@@@#               "<<endl; 
     cout<<"\n"<<endl;
}

void mysteryAnimation()
{    
    for(int i=0;i<5;i++)
     {
         
     int space = (i%2)*2;
     usleep(300000);
     cout << "\033[2J\033[1;1H"; 
     cout<<"\n\n";
     cout<<string(space,' ')<<"                         %&@@@@@@@@@&.            "<<endl; 
     cout<<string(space,' ')<<"                  *@@@@@@@@@@@@@@@@@@@@@@@@%      "<<endl; 
     cout<<string(space,' ')<<"                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@    "<<endl; 
     cout<<string(space,' ')<<"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&   "<<endl; 
     cout<<string(space,' ')<<"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   "<<endl; 
     cout<<string(space,' ')<<"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/  "<<endl; 
     cout<<string(space,' ')<<"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  "<<endl; 
     cout<<string(space,' ')<<"               @@@@@@       @@@@@@       @@@@@@@  "<<endl; 
     cout<<string(space,' ')<<"               @@@@@@       @@@@@@       @@@@@@@  "<<endl; 
     cout<<string(space,' ')<<"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  "<<endl; 
     cout<<string(space,' ')<<"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  "<<endl; 
     cout<<string(space,' ')<<"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%  "<<endl; 
     cout<<string(space,' ')<<"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   "<<endl; 
     cout<<string(space,' ')<<"               (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   "<<endl; 
     cout<<string(space,' ')<<"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,   "<<endl; 
     cout<<string(space,' ')<<"                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@    "<<endl; 
     cout<<string(space,' ')<<"                  @@@@@@@@@@@@@@@@@@@@@@@@@@@,    "<<endl; 
     cout<<string(space,' ')<<"                   @@@@@@@@@@@@@@@@@@@@@@@@@      "<<endl; 
     cout<<string(space,' ')<<"                     @@@@@@@@@@@@@@@@@@@@@        "<<endl; 
     cout<<string(space,' ')<<"                       @@@@@@@@@@@@@@@@@          "<<endl; 
     cout<<string(space,' ')<<"                         &@@@@@@@@@@@@            "<<endl; 
     cout<<string(space,' ')<<"                            @@@@@@#               "<<endl; 
     cout<<"\n"<<endl;
    }
}