#include "Pile.h"

Pile::Pile(){
	validCards[SPADE]  = SEVEN;
	validCards[SPADE+4] = SEVEN;
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
	return (validCards[card.getSuit()] == card.getRank() -1 
		|| validCards[card.getSuit()+4] == card.getRank()+1);
}