//File made by Daniel Kanchev
int input_check(int choice)
{
   cin>>choice;
   while (cin.fail() || (choice!=1 && choice!=0)) //ensures valid answer
   {
       cout<<"Invalid choice, try again."<<endl;
       cin.clear();
       cin.ignore(256, '\n');
       cin>>choice;
   }  
   return choice;
}