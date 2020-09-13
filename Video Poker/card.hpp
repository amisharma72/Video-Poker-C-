/*
 Student Name: Amit Sharma Paudyal
 Student NetID: as4912
 Compiler Used: Xcode
 Program Description:
  This program builds a simple single hand video poker machine which implements the basic rules of a five card draw hand.
 */

#ifndef card_hpp
#define card_hpp

#include <stdio.h>
using namespace std;
#include<iostream>
#include<string>

class card
{
private:
    short suit;
    short rank;
    bool faceUp;
public:
    static const short CLUBS = 0;
    static const short DIAMONDS = 1;
    static const short HEARTS = 2;
    static const short SPADES = 3;
    static const short ACE = 1;
    static const short JACK = 11;
    static const short QUEEN = 12;
    static const short KING = 13;
    
    card(short r, short s): rank(r), suit(s), faceUp(true) {};
    card(): card(ACE, CLUBS) {};
    
    void setSuit(short s) {suit = s;};
    void setRank(short r) {rank = r;};
    void setFaceUp(bool f) { faceUp = f;};
    
    short getSuit() { return suit;};
    short getRank() { return rank;};
    bool getFaceUp() { return faceUp;};
    
    void printCard(ostream &os);
    void flipOver();
    
};
#endif
