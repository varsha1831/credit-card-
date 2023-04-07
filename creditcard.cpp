#include <iostream>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>
using namespace std;
class signup
{
protected:
    char name[30],gender[6],occ[20];
    int age,CVV,ai,balance,due=0,pin;
    unsigned long long cno,phno,aadhar;
public:
    void register_();
    void details();

};
class login:public signup
{
    public:
        void Login();
        void changepin();
        void payment();
        void paydue();

};
void login::Login()
{
  int  cardno,cvv,choice,temp=1;
  t:
  system("cls");
  if(temp==0)
     cout<<"\nEntered wrong credentials\nPlease reenter once again\n";
  cout<<"\nEnter Card number: ";
  cin>>cardno;
  cout<<"\nEnter CVV : ";
  cin>>cvv;
  if(cardno!=cno || cvv!=CVV)
  {
    temp=0;

    goto t;
  }
  else
  {

  while(1)
  {
  cout<<"\n1:Profile\n2:Change pin\n3:Payment\n4:Pay Due\n5:Exit\n";
  cout<<"Enter your choice :";
  cin>>choice;
  switch(choice)
        {
        case 1:details();
                break;
        case 2:changepin();
                break;
        case 3:payment();
                break;
        case 4:paydue();
                break;
        case 5:exit(0);
        }
  }
}
}

    void login::changepin()
        {
            int oldpin,newpin;
            system("cls");
            t:
            cout<<"\nEnter your old pin: ";
            cin>>oldpin;
            cout<<"\nEnter your new pin: ";
            cin>>newpin;
            if(oldpin==pin)
            {
                pin=newpin;
                cout<<"\nPin changed Successfully\n";
            }
            else
            {
            cout<<"\nEntered wrong credentials \nPlease Try again";
            goto t;
            }

        }
    void login::payment()
    {
      int ppin,amount,n=4;
      cout<<"\nEnter the amount :";
      cin>>amount;
      t:
      n--;
      cout<<"\n Enter the pin :";
      cin>>ppin;
      if(ppin==pin)
            {
            if(amount<=balance)
                {
                    cout<<"\nPayment Successfull\n";
                    balance=balance-amount;
                    due=due+(amount+amount/100);
                }
            else
            cout<<"\nInsufficient balance\n";
           }
            else
                {
                if(n!=0)
                {
                cout<<"\nWrong pin "<<n<<" attempts left";
                goto t;
                }
                else
                cout<<"\n Number of Wrong PIN Limit extended";

            }
system("cls");
    }

    void login::paydue()
            {
            int amount;
            cout<<"\nDue Amount is :"<<due;
            cout<<"\nEnter the amount paying: ";
            cin>>amount;
            balance=balance+(amount-amount/100);
            due=due-amount;
            cout<<"\n\t\tBalance:\t"<<balance;
            cout<<"\n\t\tPayment Due:\t"<<due;
            system("cls");

            }
void signup::register_()
    {
        int choice;
        t:
        system("cls");
        cout<<"\nName :";
        cin>>name;

        cout<<"\nPhone number :";
        cin>>phno;
        cout<<"\nAadhar Number :";
        cin>>aadhar;
        cout<<"\nAge :";
        cin>>age;
        cout<<"\nGender :";
        cin>>gender;
        cout<<"\nOccupation :";
        cin>>occ;
        cout<<"\nAnnual Income :";
        cin>>ai;
        if(ai<200000)
        balance=15000;
        else if(200000<ai && ai<500000)
        balance=30000;
        else
        balance=50000;
        cout<<"\n1:Submit\n2:Edit\n";
        cin>>choice;
        switch(choice)
            {
            case 1:break;
            case 2:goto t;
            }

        srand(time(NULL));
        cno=rand()%9 +1;
        for(int i=0;i<3;i++)
            {
            cno*=10;
            cno+=rand()%10;
            }
        CVV=rand()%1000;
        details();
         cout<<"\nSet your Pin\n";
         cin>>pin;


}
void signup::details()
{

    cout<<"\nName:\t"<<name;
    cout<<"\nCard Number:\t"<<cno;
    cout<<"\nCVV\t:"<<CVV;
    cout<<"\nBalance:\t"<<balance;
    cout<<"\nPayment Due:\t"<<due;

}
int main()
{
int choice;
login l;
    while(1)
        {
            cout<<"\n1:Register\n2:Login\n3:Exit\n";
            cout<<"\nEnter your choice\n";
            cin>>choice;
            switch(choice)
                {

                    case 1:l.register_();
                           system("cls");
                           break;
                    case 2:l.Login();
                             system("cls");
                            break;
                    case 3:exit(0);
                }
        }
        return 0;

}