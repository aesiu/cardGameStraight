
#ifndef _DECK_
#define _DECK_


#include <stdlib.h>
#include "Card.h"
#include <vector>

class Deck{
public:
  Deck();
	~Deck();
	void shuffle();
	static const int CARD_COUNT;
	string getString();
	vector<Card> dealTop();
private:
	vector<Card> deck_;
	int deckDistance;
};
#endif
