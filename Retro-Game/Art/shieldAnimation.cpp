// File Made by Daniel Kanchev
//https://www.asciiart.eu/weapons/shields
//Art by Nobody
#include<iostream>
#include<unistd.h>
#include<string>
#include <cmath>
using namespace std;
int shieldAnimation(){
    for(int i =0;i<30;i++)
    {
     cout << "\033[2J\033[1;1H";
     int newLineNumber = 15 - abs(15-i);
     for (int j=0;j<newLineNumber;j++)
          cout<<endl;
     cout<<string(i, ' ')<<" _________________"<<endl;
     cout<<string(i, ' ')<<"|       | |       |"<<endl;
     cout<<string(i, ' ')<<"|       | |       |"<<endl;
     cout<<string(i, ' ')<<"|       | |       |"<<endl;
     cout<<string(i, ' ')<<"|_______| |_______|"<<endl;
     cout<<string(i, ' ')<<"|_______   _______|"<<endl;
     cout<<string(i, ' ')<<"|       | |       |"<<endl;
     cout<<string(i, ' ')<<"|       | |       |"<<endl;
     cout<<string(i, ' ')<<" \\      | |      /"<<endl;
     cout<<string(i, ' ')<<"  \\     | |     /"<<endl;
     cout<<string(i, ' ')<<"   \\    | |    /"<<endl;
     cout<<string(i, ' ')<<"    \\   | |   /"<<endl;
     cout<<string(i, ' ')<<"     \\  | |  /"<<endl;
     cout<<string(i, ' ')<<"      \\ | | /"<<endl;
     cout<<string(i, ' ')<<"       \\| |/"<<endl;
     cout<<string(i, ' ')<<"        \\_/"<<endl;
     usleep(35000);                                                                        
    }
    cout<<endl;
    return 0;
    
}
