// File Made by Daniel Kanchev
//http://ascii.co.uk/art/jewels
#include<iostream>
#include<unistd.h>
using namespace std;

//http://ascii.co.uk/art/jewels
void j_animation1()
{
    cout << "\033[2J\033[1;1H"; 
         cout<<"                                                 '             "<<endl;
         cout<<"                                   '                 '"<<endl;
         cout<<"                           '         '      '      '        '"<<endl;
         cout<<"                              '        \\    '    /       '"<<endl;
         cout<<"                                  ' .   .-'```'-.  . '"<<endl;
         cout<<"                                        \\`-._.-`/"<<endl;
         cout<<"                             - -  =      \\\\ | //      =  -  -"<<endl;
         cout<<"                                        ' \\\\|// '"<<endl;
         cout<<"                                  . '      \\|/     ' ."<<endl;
         cout<<"                               .         '  `  '         ."<<endl;
         cout<<"                            .          /    .    \\           ."<<endl;
         cout<<"                                     .      .      ."<<endl;
}
void j_animation2(){
cout << "\033[2J\033[1;1H"; 
         cout<<"                                                               "<<endl;
         cout<<"                                                      "<<endl;
         cout<<"                                                             "<<endl;
         cout<<"                                                          "<<endl;
         cout<<"                                        .-'```'-.     "<<endl;
         cout<<"                                        \\`-._.-`/"<<endl;
         cout<<"                                         \\\\ | //             "<<endl;
         cout<<"                                          \\\\|//  "<<endl;
         cout<<"                                           \\|/        "<<endl;
         cout<<"                                            `             "<<endl;
         cout<<"                                                              "<<endl;
         cout<<"                                                    "<<endl;
                                                                                                              
}

int jewellAnimation(){
   for (int i = 0;i<8;i++)
   {
      j_animation1();
      usleep(100000);
      j_animation2();
      usleep(100000);
   }
   return 0;
}
