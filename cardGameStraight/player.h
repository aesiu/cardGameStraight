#include "Pile.h"
#include "Card.h"
#include <vector>


class player{
public:
    player();
	~player();
	void dealNewHand(vector<Card>deck,  int playerNum);
	virtual void discardCard(Card card);
	void playCard(Card card);
protected:
	int score;
	vector<Card> hand;
	vector<Card> discard;
	static Pile pile;
private:
	void destroyCard(Card card);
};

