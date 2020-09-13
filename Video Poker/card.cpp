/*
 Student Name: Amit Sharma Paudyal
 Student NetID: as4912
 Compiler Used: Xcode
 Program Description:
  This program builds a simple single hand video poker machine which implements the basic rules of a five card draw hand.
 */

#include "card.hpp"
#include<ostream>
void card::printCard(ostream &os)
{
    static const char suitChar[] = {'C','D','H','S'};
    static const char rankChar[] = {' ','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    
    if (faceUp)
    {
        os << "| " << rankChar[rank] << " " << suitChar[suit] << " |";
    } else
    {
        os << "| # # |";
    }
}

void card::flipOver()
{
    faceUp = !faceUp;
}
