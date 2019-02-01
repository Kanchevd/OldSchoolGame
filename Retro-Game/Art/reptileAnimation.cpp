// File Made by Daniel Kanchev
//http://ascii.co.uk/art/monster
//Art by Zeus
#include<unistd.h>
void reptileImage()
{    
     cout<< "\033[2J\033[1;1H";
     cout<<"                                                ,--,  ,.-."<<endl;
     cout<<"                  ,                   \\,       '-,-`,'-.' | ._"<<endl;
     cout<<"                 /|           \\    ,   |\\         }  )/  / `-,',"<<endl;
     cout<<"                 [ '          |\\  /|   | |        /  \\|  |/`  ,`"<<endl;
     cout<<"                 | |       ,.`  `,` `, | |  _,...(   (      _',"<<endl;
     cout<<"                 \\  \\  __ ,-` `  ,  , `/ |,'      Y     (   \\_L\\"<<endl;
     cout<<"                  \\  \\_\\,``,   ` , ,  /  |         )         _,/"<<endl;
     cout<<"                   \\  '  `  ,_ _`_,-,<._.<        /         /"<<endl;
     cout<<"                    ', `>.,`  `  `   ,., |_      |         /"<<endl;
     cout<<"                      \\/`  `,   `   ,`  | /__,.-`    _,   `\\"<<endl;
     cout<<"                  -,-..\\  _  \\  `  /  ,  / `._) _,-\\`       \\"<<endl;
     cout<<"                   \\_,,.) /\\    ` /  / ) (-,, ``    ,        |"<<endl;
     cout<<"                  ,` )  | \\_\\       '-`  |  `(               \\"<<endl;
     cout<<"                 /  /```(   , --, ,' \\   |`<`    ,            |"<<endl;
     cout<<"                /  /_,--`\\   <\\  V /> ,` )<_/)  | \\      _____)"<<endl;
     cout<<"          ,-, ,`   `   (_,\\ \\    |   /) / __/  /   `----`"<<endl;
     cout<<"         (-, \\           ) \\ ('_.-._)/ /,`    /"<<endl;
     cout<<"         | /  `          `/ \\ V   V, /`     /"<<endl;
     cout<<"      ,--\\(        ,     <_/`\\     ||      /"<<endl;
     cout<<"     (   ,``-     \\/|         \\-A.A-`|     /"<<endl;
     cout<<"    ,>,_ )_,..(    )\\          -,,_-`  _--`"<<endl;
     cout<<"   (_ \\|`   _,/_  /  \\_            ,--`"<<endl;
     cout<<"    \\( `   <.,../`     `-.._   _,-`"<<endl;
     cout<<"     `                      ```"<<endl;
     cout<<endl;
}

void reptileAnimation()
{    
    for(int i=0;i<7;i++)
     {
          int space = (i%2)*2;
          usleep(120000);
          cout << "\033[2J\033[1;1H"; 
          cout<<string(space,' ')<<"                                                ,--,  ,.-."<<endl;
          cout<<string(space,' ')<<"                  ,                   \\,       '-,-`,'-.' | ._"<<endl;
          cout<<string(space,' ')<<"                 /|           \\    ,   |\\         }  )/  / `-,',"<<endl;
          cout<<string(space,' ')<<"                 [ '          |\\  /|   | |        /  \\|  |/`  ,`"<<endl;
          cout<<string(space,' ')<<"                 | |       ,.`  `,` `, | |  _,...(   (      _',"<<endl;
          cout<<string(space,' ')<<"                 \\  \\  __ ,-` `  ,  , `/ |,'      Y     (   \\_L\\"<<endl;
          cout<<string(space,' ')<<"                  \\  \\_\\,``,   ` , ,  /  |         )         _,/"<<endl;
          cout<<string(space,' ')<<"                   \\  '  `  ,_ _`_,-,<._.<        /         /"<<endl;
          cout<<string(space,' ')<<"                    ', `>.,`  `  `   ,., |_      |         /"<<endl;
          cout<<string(space,' ')<<"                      \\/`  `,   `   ,`  | /__,.-`    _,   `\\"<<endl;
          cout<<string(space,' ')<<"                  -,-..\\  _  \\  `  /  ,  / `._) _,-\\`       \\"<<endl;
          cout<<string(space,' ')<<"                   \\_,,.) /\\    ` /  / ) (-,, ``    ,        |"<<endl;
          cout<<string(space,' ')<<"                  ,` )  | \\_\\       '-`  |  `(               \\"<<endl;
          cout<<string(space,' ')<<"                 /  /```(   , --, ,' \\   |`<`    ,            |"<<endl;
          cout<<string(space,' ')<<"                /  /_,--`\\   <\\  V /> ,` )<_/)  | \\      _____)"<<endl;
          cout<<string(space,' ')<<"          ,-, ,`   `   (_,\\ \\    |   /) / __/  /   `----`"<<endl;
          cout<<string(space,' ')<<"         (-, \\           ) \\ ('_.-._)/ /,`    /"<<endl;
          cout<<string(space,' ')<<"         | /  `          `/ \\ V   V, /`     /"<<endl;
          cout<<string(space,' ')<<"      ,--\\(        ,     <_/`\\     ||      /"<<endl;
          cout<<string(space,' ')<<"     (   ,``-     \\/|         \\-A.A-`|     /"<<endl;
          cout<<string(space,' ')<<"    ,>,_ )_,..(    )\\          -,,_-`  _--`"<<endl;
          cout<<string(space,' ')<<"   (_ \\|`   _,/_  /  \\_            ,--`"<<endl;
          cout<<string(space,' ')<<"    \\( `   <.,../`     `-.._   _,-`"<<endl;
          cout<<string(space,' ')<<"     `                      ```"<<endl;
          cout<<endl;
    }
}