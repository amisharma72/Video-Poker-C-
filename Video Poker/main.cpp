/*
 Student Name: Amit Sharma Paudyal
 Student NetID: as4912
 Compiler Used: Xcode
 Program Description:
  This program builds a simple single hand video poker machine which implements the basic rules of a five card draw hand.
 */

#include<iostream>
#include"card.hpp"
#include"deck.hpp"
#include"hand.hpp"
using namespace std;
int main()
{
    char z;
    do
    {
    int Aca;
    hand a;
    deck d;
    card c;
    d.shuffle();
    a.Deal(d);
    cout<<"This is your starting hand:"<<endl;
    a.displayHand(cout);
    if(a.ACECheck()==true)
        {
            Aca=1;
        }
    else  Aca=0;
    if(Aca==1)
    {
        cout<<"Hurray!That's an ACE."<<endl;
        cout<<"Do you want have an ACE?(Y/N)"<<endl;
        char f;
        cin>>f;
        if (f=='y'||f=='Y')
        {
            cout<<"You can discard all remamining cards except ACE."<<endl;
            for(int j=0; j<4; j++)
            {
                cout<<"Please select a card to keep or discard."<<endl;
                cout<<"Enter 0 to finalize your selection."<<endl;
                int e;
                cin>>e;
                if(e!=0)
                {
                    a.discardCard(e-1);
                    a.displayHand(cout);
                }
                else break;
            }
        }
        else
        {
            Aca=0;
        }
    }
     if(Aca==0)
    {
        cout<<"Oops!No ACE. You can only discard 3 cards."<<endl;
        for(int j=0;j<3;j++)
        {
        cout<<"Please select a card to keep or discard."<<endl;
        cout<<"Enter 0 to finalize your selection."<<endl;
        int e=4;
        cin>>e;
         if (e!=0)
         {
          a.discardCard(e-1);
          a.displayHand(cout);
         }
         else break;
        }
    }
        cout<<"Your final hand is:";
        a.draw(d);
        a.evaluate();
        a.displayHand(cout);
    if(a.evaluate()==1)
    {
        cout<<" You have a FOUROFAKIND"<<endl;
    }
    if(a.evaluate()==2)
    {
        cout<<" You have a FULLHOUSE"<<endl;
    }
    if(a.evaluate()==3)
    {
        cout<<" You have a THREEOFAKIND"<<endl;
    }
    if(a.evaluate()==4)
    {
        cout<<" You have a TWO PAIR"<<endl;
    }
    if(a.evaluate()==5)
    {
        cout<<" You have a ONE PAIR"<<endl;
    }
    if(a.evaluate()==6)
    {
        cout<<" You have a HIGHCARD"<<endl;
    }
    if(a.evaluate()==7)
    {
        cout<<" You have a FLUSH"<<endl;
    }
    if(a.evaluate()==8)
    {
        cout<<" You have a ROYALFLUSH"<<endl;
    }
    if(a.evaluate()==9)
    {
        cout<<" You have a STRAIGHT"<<endl;
    }
    if(a.evaluate()==10)
    {
        cout<<" You have a STRAIGHTFLUSH"<<endl;
    }
        cout<<"Do you wish to continue?(Y/N)"<<endl;
        cin>>z;
    }
    while(z=='y'||z=='Y');
}
