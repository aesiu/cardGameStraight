#ifndef _PILE_
#define _PILE_


#include "Card.h"
#include <vector>

class Pile{#include "Pile.h"

Pile::Pile(){
	for (int i =0; i < 8; i++){
		validCards[i]  = -2;
	}

}

Pile::~Pile(){
	
}

void Pile::addToPile(Card card){
	pile.push_back(card);
	if(card.getRank() == SEVEN){
		validCards[card.getSuit()] = SEVEN;
		validCards[card.getSuit()+4] = SEVEN;
	}
	if(card.getRank() < validCards[card.getSuit()]){
		validCards[card.getSuit()] = card.getRank();	    
	}else{
		validCards[card.getSuit()+4] = card.getRank();
	}
	
}

bool Pile::isValidMove(Card card){
	if(validCards[SPADE]==-2){
		return (card.getRank() == SEVEN && card.getSuit() == SPADE);
	}else if (card.getRank() == SEVEN)
		return true;
	return (validCards[card.getSuit()]-1 == card.getRank() 
		|| validCards[card.getSuit()+4]+1 == card.getRank());
}

string Pile::getRangeOfSuit(Suit suit){
	if (validCards[suit] == -2){
		return "";
	}
	string ranks[RANK_COUNT] = {"A", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "J", "Q", "K"};
	string s = "";
	for (int i = validCards[suit]; i <= validCards[suit+4]; i++){
		s += ranks[i]+" ";
	}
	return s;
}
public:
	Pile();
	~Pile();
	void addToPile(Card card);
	bool isValidMove(Card card);
	string getRangeOfSuit(Suit suit);
private:
	vector <Card> pile;
	int validCards[8]; // first four are the smallest value of all suites, the next four are the biggest value
};

#endif
