//File created by Byron Hall.
int loading_Screen(){
        unsigned int microseconds;
        int i;
        for(i=0;i<=100;i++){//loop from 1 to 100 to show loading progress
            usleep(50000);
                cout << "Loading..." << endl;
                cout << i << "%" << endl;
                cout << "\033[2J\033[1;1H";//linux command to clear the terminal
        }
    sleep(1);
    cout << "\033[2J\033[1;1H";
    cout << "Loading Complete!"<< endl;
    sleep(2);
    cout << "\033[2J\033[1;1H";
    
}
