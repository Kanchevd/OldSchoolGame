// File Made by Daniel Kanchev
//https://manytools.org/
#include<iostream>
#include<unistd.h>
using namespace std;


void w_animation1(){
cout<< "\033[2J\033[1;1H";
cout<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
cout<< "@@&  /@@@@( .@#  @@@/  .,.  /@@         &@*  .,.  .@@@/        .@&  #@@@, ,@@"<<endl;
cout<< "@@@%  @@@&  @@#  @@. ,@@@@@(&@@@@@( *@@@@* ,@@@@@#  @@/  @@@@&  @@@  #@  /@@@"<<endl;
cout<< "@@@@,  @@  %@@#  @@  %@@@@@@@@@@@@( *@@@@  &@@@@@@  %@/        %@@@@,   %@@@@"<<endl;
cout<< "@@@@@. #/ .@@@#  @@  /@@@@@(@@@@@@( *@@@@  #@@@@@@  &@/  @@*  &@@@@@@  %@@@@@"<<endl;
cout<< "@@@@@@    @@@@#  @@@  .&@&  .@@@@@( *@@@@@  ,@@@&  *@@/  @@@@  ,@@@@@  %@@@@@"<<endl;
cout<< "@@@@@@/  &@@@@#  @@@@@/   /@@@@@@@( *@@@@@@#     /@@@@/  @@@@@  .@@@@  %@@@@@"<<endl;
cout<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
}

void w_animation2(){
cout << "\033[2J\033[1;1H"; 
cout<<endl;
cout<<"   .@@(    /@& *@@   (@@&%&@@(  @@@@@@@@@. #@@&%&@@&   (@@@@@@@@& .@@*   %@%  "<<endl;              
cout<<"    ,@@   .@@  *@@  &@%     /.     /@#    #@%     *@@  (@@    .@@   @@* @@(   "<<endl;              
cout<<"     %@@  @@,  *@@  @@,            /@#    @@.      @@, (@@@@@@@@,    %@@@,    "<<endl;              
cout<<"      &@*(@&   *@@  @@(     /      /@#    @@*      @@. (@@  #@@.      @@,     "<<endl;              
cout<<"       @@@@    *@@   @@&. .@@&     /@#     @@%   .@@#  (@@    @@%     @@,     "<<endl;              
cout<<"       (@@.    *@@     (@@@(       /@#      *@@@@@(    (@@     @@&    @@,     "<<endl;             
cout<<endl;                                                                                                             
                                                                                                                 
}

int victoryAnimation(){
   for (int i = 0;i<20;i++)
   {
      w_animation1();
      usleep(80000);
      w_animation2();
      usleep(80000);
   }
   return 0;
}
