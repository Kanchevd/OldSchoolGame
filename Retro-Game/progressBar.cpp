//File Made by Daniel Kanchev
void progressBar(int gameEnd,int travel)
{   
    int lineMiles = gameEnd/20; //divide game lenght into 20 pieces
    int currLine = travel/lineMiles + 1 ; //figure out how far the player has gone
    for (int i=1;i<currLine;i++) 
         cout<<"- ";//dashes before *
    cout<<'*';
    for (int i=currLine;i<20;i++)
    cout<<" -";
    cout<<endl;
}