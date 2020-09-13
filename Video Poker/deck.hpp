/*
 Student Name: Amit Sharma Paudyal
 Student NetID: as4912
 Compiler Used: Xcode
 Program Description:
  This program builds a simple single hand video poker machine which implements the basic rules of a five card draw hand.
 */

#ifndef deck_hpp
#define deck_hpp

#include <stdio.h>
#include<iostream>
#include "card.hpp"
class deck
{
private:
    
    card pile[52];
    int remaining;
    
    
public:
    static const int noCardException = -100;
    
    deck();
    
    int getRemaining();
    
    void shuffle();
    card deal();
    bool isEmpty();
    void reset();
    
};
#endif



