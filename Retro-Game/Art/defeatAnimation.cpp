// File Made by Daniel Kanchev
//https://manytools.org/
#include<iostream>
#include<unistd.h>
using namespace std;


void animation1(){
cout<< "\033[2J\033[1;1H";
cout<<"  _____            __                  _    "<<endl;              
cout<<" |  __ \\          / _|                | |   "<<endl;              
cout<<" | |  | |   ___  | |_    ___    __ _  | |_  "<<endl;              
cout<<" | |  | |  / _ \\ |  _|  / _ \\  / _` | | __| "<<endl;              
cout<<" | |__| | |  __/ | |   |  __/ | (_| | | |_  "<<endl;    
cout<<" |_____/   \\___| |_|    \\___|  \\__,_|  \\__| "<<endl;   
}

void animation2(){
cout<< "\033[2J\033[1;1H";
cout<<"  _____            __                  _    "<<endl;              
cout<<" |  __ \\          / _|                | |   "<<endl;              
cout<<" | |  | |   ___  | |_    ___    __ _  | |_  "<<endl;              
cout<<" | |  | |  / _ \\ |  _|  / _ \\  / _` | | __| "<<endl;              
cout<<" | |__| | |  __/ | |   |  __/ | (_| | | |_     _"<<endl;    
cout<<" |_____/   \\___| |_|    \\___|  \\__,_|  \\__|   (_)"<<endl;
} 
void animation3(){
cout<< "\033[2J\033[1;1H";
cout<<"  _____            __                  _    "<<endl;              
cout<<" |  __ \\          / _|                | |   "<<endl;              
cout<<" | |  | |   ___  | |_    ___    __ _  | |_  "<<endl;              
cout<<" | |  | |  / _ \\ |  _|  / _ \\  / _` | | __| "<<endl;              
cout<<" | |__| | |  __/ | |   |  __/ | (_| | | |_     _   _"<<endl;    
cout<<" |_____/   \\___| |_|    \\___|  \\__,_|  \\__|   (_) (_)"<<endl;
}
void animation4(){
cout<< "\033[2J\033[1;1H";
cout<<"  _____            __                  _    "<<endl;              
cout<<" |  __ \\          / _|                | |   "<<endl;              
cout<<" | |  | |   ___  | |_    ___    __ _  | |_  "<<endl;              
cout<<" | |  | |  / _ \\ |  _|  / _ \\  / _` | | __| "<<endl;              
cout<<" | |__| | |  __/ | |   |  __/ | (_| | | |_     _   _   _"<<endl;    
cout<<" |_____/   \\___| |_|    \\___|  \\__,_|  \\__|   (_) (_) (_)"<<endl;
} 
int defeatAnimation(){
    
   for(int i=0;i<3;i++) 
   {
      animation1();
      usleep(200000);
      animation2();
      usleep(200000);
      animation3();
      usleep(200000);
      animation4();
      usleep(200000);
   }
      return 0;
}
