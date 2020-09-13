/*
 Student Name: Amit Sharma Paudyal
 Student NetID: as4912
 Compiler Used: Xcode
 Program Description:
 This program builds a simple single hand video poker machine which implements the basic rules of a five card draw hand.
 */

#ifndef hand_hpp
#define hand_hpp

#include <stdio.h>
#include<iostream>
#include "deck.hpp"
#include "card.hpp"
using namespace std;
class hand
{
public:
    static const int FOUROFAKIND=1;
    static const int FULLHOUSE=2;
    static const int THREEOFAKIND=3;
    static const int TWOPAIR=4;
    static const int ONEPAIR=5;
    static const int HIGHCARD=6;
    static const int FLUSH=7;
    static const int ROYALFLUSH=8;
    static const int STRAIGHT=9;
    static const int STRAIGHTFLUSH=10;
    hand();
    void Deal(deck &d);
    void draw(deck &d);
    bool ACECheck();
    void displayHand(ostream &os);
    void keepCard(int x);
    void discardCard(int x);
    int evaluate(void);
    
    
private:
    card cards[5];
    short rank[5];
    short suit[5];
};
#endif

