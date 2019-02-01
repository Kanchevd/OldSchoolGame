// File Made by Daniel Kanchev
// https://manytools.org/hacker-tools/convert-images-to-ascii-art/
#include<unistd.h>
void werewolfImage()
{    
    cout<< "\033[2J\033[1;1H";
    cout<<"                              %@@@@@@@@@@@@@@@@&                    "<<endl;
    cout<<"                          %@@@@@@@@@@@@@@@@@@@@@@@@&                "<<endl;
    cout<<"                       ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/             "<<endl;
    cout<<"                     (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%           "<<endl;
    cout<<"                    @@@@@@@@@@@@@@@@@@@@@@@   (@@@@@@@@@@@          "<<endl;
    cout<<"                  (@@@@@@@@@@@@@@@@@@@@@@(     @@@@@@@@@@@@&        "<<endl;
    cout<<"                 &@@@@@@@@@@@@@@@@@@@@@&        @/@@@@@@@@@@@       "<<endl;
    cout<<"                ,@@@@@@@@@@@@@@@@@@@@&          @@@@@@@@@@@@@#      "<<endl;
    cout<<"                @@@@@@@@@@@@@@@                 @@@@@@@@@@@@@@      "<<endl;
    cout<<"               #@@@@@@@@@@@@@                   %&@@@@@@@@@@@@&     "<<endl;
    cout<<"               @@@@@@@@@&.                         @@@@@@@@@@@@     "<<endl;
    cout<<"               @@@@@@@/                           @@@@@@@@@@@@@     "<<endl;
    cout<<"               @@@,                             &@@@@@@@@@@@@@@     "<<endl;
    cout<<"               @                               @@@@@@@@@@@@@@@@     "<<endl;
    cout<<"                                             /@@@@@@@@@@@@@@@@      "<<endl;
    cout<<"                                            @@@@@@@@@@@@@@@@@&      "<<endl;
    cout<<"                                            @@@@@@@@@@@@@@@@@       "<<endl;
    cout<<"                                             &@@@@@@@@@@@@@@        "<<endl;
    cout<<"                                              @@@@@@@@@@@@@         "<<endl;
    cout<<"                                             @@@@@@@@@@@@           "<<endl;
    cout<<"                                             @@@@@@@@@@             "<<endl;
    cout<<"                                             @@@@@@@@               "<<endl;
    cout<<"                                             @@@@*                  "<<endl;
    cout<<"                                                                    "<<endl;
    cout<<"                                                                    "<<endl;
    cout<<"                                                                    "<<endl;
}

void werewolfAnimation()
{    
    for(int i=0;i<5;i++)
     {
         
     int space = (i%2)*2;
     usleep(120000);
     cout<< "\033[2J\033[1;1H";
    cout<<string(space,' ')<<"                              %@@@@@@@@@@@@@@@@&                    "<<endl;
    cout<<string(space,' ')<<"                          %@@@@@@@@@@@@@@@@@@@@@@@@&                "<<endl;
    cout<<string(space,' ')<<"                       ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/             "<<endl;
    cout<<string(space,' ')<<"                     (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%           "<<endl;
    cout<<string(space,' ')<<"                    @@@@@@@@@@@@@@@@@@@@@@@   (@@@@@@@@@@@          "<<endl;
    cout<<string(space,' ')<<"                  (@@@@@@@@@@@@@@@@@@@@@@(     @@@@@@@@@@@@&        "<<endl;
    cout<<string(space,' ')<<"                 &@@@@@@@@@@@@@@@@@@@@@&        @/@@@@@@@@@@@       "<<endl;
    cout<<string(space,' ')<<"                ,@@@@@@@@@@@@@@@@@@@@&          @@@@@@@@@@@@@#      "<<endl;
    cout<<string(space,' ')<<"                @@@@@@@@@@@@@@@                 @@@@@@@@@@@@@@      "<<endl;
    cout<<string(space,' ')<<"               #@@@@@@@@@@@@@                   %&@@@@@@@@@@@@&     "<<endl;
    cout<<string(space,' ')<<"               @@@@@@@@@&.                         @@@@@@@@@@@@     "<<endl;
    cout<<string(space,' ')<<"               @@@@@@@/                           @@@@@@@@@@@@@     "<<endl;
    cout<<string(space,' ')<<"               @@@,                             &@@@@@@@@@@@@@@     "<<endl;
    cout<<string(space,' ')<<"               @                               @@@@@@@@@@@@@@@@     "<<endl;
    cout<<string(space,' ')<<"                                             /@@@@@@@@@@@@@@@@      "<<endl;
    cout<<string(space,' ')<<"                                            @@@@@@@@@@@@@@@@@&      "<<endl;
    cout<<string(space,' ')<<"                                            @@@@@@@@@@@@@@@@@       "<<endl;
    cout<<string(space,' ')<<"                                             &@@@@@@@@@@@@@@        "<<endl;
    cout<<string(space,' ')<<"                                              @@@@@@@@@@@@@         "<<endl;
    cout<<string(space,' ')<<"                                             @@@@@@@@@@@@           "<<endl;
    cout<<string(space,' ')<<"                                             @@@@@@@@@@             "<<endl;
    cout<<string(space,' ')<<"                                             @@@@@@@@               "<<endl;
    cout<<string(space,' ')<<"                                             @@@@*                  "<<endl;
    cout<<string(space,' ')<<"                                                                    "<<endl;
    cout<<string(space,' ')<<"                                                                    "<<endl;
    cout<<string(space,' ')<<"                                                                    "<<endl;
    }
}