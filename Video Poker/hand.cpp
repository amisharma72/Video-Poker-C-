/*
 Student Name: Amit Sharma Paudyal
 Student NetID: as4912
 Compiler Used: Xcode
 Program Description:
  This program builds a simple single hand video poker machine which implements the basic rules of a five card draw hand.
 */

#include "hand.hpp"
#include "deck.hpp"
#include "card.hpp"
#include<ostream>

hand::hand()
{
    
}
void hand::Deal(deck &d)
{
    if(d.getRemaining()<9)
    {
        d.shuffle();
        d.reset();
    }
    for(int i=0;i<5;i++)
    {
        cards[i]=d.deal();
        rank[i]=cards[i].getRank();
        suit[i]=cards[i].getSuit();
    }
}

void hand::draw(deck &d)
{
    for(int i=0;i<5;i++)
        {
            if (cards[i].getFaceUp()==false)
            {
            cards[i]=d.deal();
                rank[i]=cards[i].getRank();
                suit[i]=cards[i].getSuit();
            }
        }
    
}
void hand::displayHand(ostream &os)
{
    for(int i=0;i<5;i++)
    {
        cards[i].printCard(os);
    }
    cout<<endl;
}
void hand::keepCard(int x)
{
    cards[x].getFaceUp();
}
void hand::discardCard(int x)
{
    cards[x].flipOver();
}
bool hand::ACECheck()
{
    if((rank[0]==1)||(rank[1]==1)||(rank[2]==1)||(rank[3]==1)||(rank[4]==1))
    {
        return true;
    }
    else
    {
        return false;
    }
    }
int hand::evaluate(void)
{
    bool swapped = true;
    int j = 0;
    card tmp;
    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < 5-j; i++)
        {
            if ((cards[i].getRank())> (cards[i + 1].getRank()))
            {
                tmp = cards[i];
                cards[i] =cards[i + 1];
                cards[i + 1] = tmp;
                swapped = true;
            }
        }
    }
    for(int i=0;i<5;i++)
    {
    rank[i]=cards[i].getRank();
    suit[i]=cards[i].getSuit();
    }
    if((rank[0] == rank[1] &&rank[1]== rank[2]&&rank[2] == rank[3])||(rank[1] == rank[2] &&rank[2]== rank[3]&&rank[3] == rank[4]))
    {
        return FOUROFAKIND;
    }
    else if(((rank[0]==rank[1] &&rank[1]==rank[2])&&(rank[3]==rank[4]))||((rank[0]==rank[1]) && (rank[2]==rank[3]&&rank[3]==rank[4])))
    {
        return FULLHOUSE;
    }
    else if((rank[0]==rank[1]&& rank[1]==rank[2])||(rank[1]==rank[2]&&rank[2]==rank[3])||(rank[2]==rank[3]&&rank[3]==rank[4]))
    {
        return THREEOFAKIND;
    }
        else if (rank[1] == rank[0]+1 && rank[2]==rank[1]+1 && rank[3]==rank[2]+1 && rank[4]==rank[3]+1)
            {
                return STRAIGHT;
            }
        else if ((rank[0] == rank[1] && rank[2] == rank[3])|| (rank[0] == rank[1] && rank[3] == rank[4])||(rank[1] == rank[2] && rank[3] == rank[4]))
        {
            return TWOPAIR;
        }
        else if (rank[0] == rank[1] || rank[1]==rank[2] || rank[2]==rank[3] || rank[3]==rank[4])
        {
            return ONEPAIR;
        }
        else if((rank[4]-rank[0])==12 && (suit[0]==suit[1]&&suit[1]==suit[2]&&suit[2]==suit[3]&&suit[3]==suit[4])&& (rank[1]==10))
        {
            return ROYALFLUSH;
        }
    else if((rank[4]-rank[0])==4 && (suit[0]==suit[1]&&suit[1]==suit[2]&&suit[2]==suit[3]&&suit[3]==suit[4]))
    {
        return STRAIGHTFLUSH;
    }
        else if (rank[1] == rank[0]+1 && rank[2]==rank[1]+1 && rank[3]==rank[2]+1 && rank[4]==rank[3]+1)
        {
            return STRAIGHT;
        }
        else if(suit[0] == suit[1] && suit[1]==suit[2] && suit[2]==suit[3] && suit[3]==suit[4])
                {
                    return FLUSH;
                }
    else
    {
        return HIGHCARD;
    }
}


