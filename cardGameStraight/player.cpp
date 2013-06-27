#include "player.h"

Pile player::pile = *(new Pile());
player::player(){
	score = 0;
	//hand = NULL;
	//discard = NULL;
}

player::~player(){
}

void player::dealNewHand(vector<Card>deck){
	hand = deck;
}

void player::discardCard(Card card){
	bool legal = false;
	for(vector<Card>::iterator i = hand.begin(); i != hand.end(); i++){
		if (pile.isValidMove(*i)){
			legal = true;
		}
	}
	if(legal){
		throw string("You have a legal play. You may not discard.");
	}
	discard.push_back(card);
	score += card.getRank();
	destroyCard(card);
	//discard the selected card from the hand

}

void player::destroyCard(Card card){
	for(vector<Card>::iterator i = hand.begin(); i != hand.end(); i++){
		if(*i == card){
			hand.erase(i);
			return;
		}
	}
}

void player::playCard(Card card){
	if(pile.isValidMove(card)){
		pile.addToPile(card);
		destroyCard(card);
	} else{
		throw string("This is not a legal play.");
	}
}

string player::getRangeOfSuit(Suit suit){
	return pile.getRangeOfSuit(suit);
}
string player::getHandString(){
	string s ="";
	for(vector<Card>::iterator i = hand.begin(); i != hand.end(); i++){
		s+= i->convertRankToString() + i->convertSuitToString() + " ";
	}
	return s;
}
string player::getLegalPlaysString(){
	string s ="";
	for(vector<Card>::iterator i = hand.begin(); i != hand.end(); i++){
		if (pile.isValidMove(*i)){
			s+= i->convertRankToString() + i->convertSuitToString() + " ";
		}
	}
	return s;
}

bool player::hasCard(Card card){
	for(vector<Card>::iterator i = hand.begin(); i != hand.end(); i++){
		if(*i == card){
			return true;
		}
	}
	return false;
}
int player::getScore(){
	return score;
}
vector<Card> player::getHand(){
	return hand;
}
vector<Card> player::getDiscard(){
	return discard;
}
bool player::isHuman(){
	return human;
}
