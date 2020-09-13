/*
 Student Name: Amit Sharma Paudyal
 Student NetID: as4912
 Compiler Used: Xcode
 Program Description:
  This program builds a simple single hand video poker machine which implements the basic rules of a five card draw hand.
 */

#include "deck.hpp"
#include "card.hpp"
#include<cstdlib>
#include<ctime>

int deck::getRemaining()
{
    return remaining;
    
}

deck::deck()
{
    reset();
}

void deck::reset()
{
    remaining =  0;
    for (short suit = card::CLUBS; suit <= card::SPADES; suit++)
    {
        for (short rank = card::ACE; rank <= card::KING; rank++)
        {
            pile[remaining].setSuit(suit);
            pile[remaining].setRank(rank);
            remaining += 1;
        }
    }
}

bool deck::isEmpty()
{
    return remaining==0;
}
card deck::deal()
{
    if (isEmpty()) { throw noCardException; }
    return pile[--remaining];
}
void deck::shuffle()
{
    srand((int)time(NULL));
    
    for (int i = 0; i<52; i++) {
        
        int s = rand() % 52;
        
        swap(pile[i], pile[s]);
    }
}
