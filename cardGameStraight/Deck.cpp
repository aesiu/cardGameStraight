#include <stdlib.h>
#include "Deck.h"


const int Deck::CARD_COUNT = 52;
Deck::Deck(){
  deckDistance = 0;
	for(int j =0; j < 4;j++){
		for(int i = 0; i<13;i++){
			Card* c = new Card(	(Suit)j, (Rank)i);
			deck_.push_back(*c);
		}
	}
	//shuffle();
}
Deck::~Deck(){}

void Deck::shuffle(){
	int n = CARD_COUNT;
	while ( n > 1 ) {
		int k;//can only be excuted on unix || int k = (int) (lrand48() % n);
		--n;
		Card c = deck_[n];
		deck_[n] = deck_[k];
		deck_[k] = c;
	}
}

vector<Card> Deck::dealTop(){
	vector<Card> ret;
	for (int i =0; i < 13; i++){
		ret.push_back(deck_[deckDistance]);
		deckDistance++;
	}
	return ret;
}

string Deck::getString(){
	string s ="";
	for (vector<Card>::iterator i = deck_.begin(); i != deck_.end(); i++){
		s+= i->convertRankToString() + i->convertSuitToString() + " ";
	}
	return s;
}
