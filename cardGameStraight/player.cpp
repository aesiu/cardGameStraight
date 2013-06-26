#include "player.h"

player::player(){
	score = 0;
	//hand = NULL;
	//discard = NULL;
}

void player::dealNewHand(vector<Card>deck , int playerNum){
	int counter = 0;
	for(int i = 13 * (playerNum-1); i < 13 * (playerNum); i++ ){
		hand[counter++] = deck[i];
	}
}

void player::discardCard(Card card){
	discard.push_back(card);
	score += card.getRank();
	destroyCard(card);
	//discard the selected card from the hand

}

void player::destroyCard(Card card){
	for(vector<Card>::iterator i = hand.begin(); i != hand.end(); i++){
		if(*i == card){
			hand.erase(i);
		}
	}
}

void player::playCard(Card card){
	if(pile.isValidMove(card)){
		pile.addToPile(card);
		destroyCard(card);
	}
	throw "This is not a legal play.";
}