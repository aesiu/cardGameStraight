#ifndef _PLAYER_
#define _PLAYER_


#include "Pile.h"
#include "Card.h"
#include <vector>


class player{
public:
    player();
	~player();
	void dealNewHand(vector<Card>deck);
	virtual void discardCard(Card card);
	void playCard(Card card);
	virtual string autoplay() = 0;
	static string getRangeOfSuit(Suit);
	string getHandString();
	string getLegalPlaysString();
	int getScore();
	vector<Card> getHand();
	vector<Card> getDiscard();
	bool isHuman();
	bool hasCard(Card card);
protected:
	int score;
	vector<Card> hand;
	vector<Card> discard;
	static Pile pile;
	bool human;
private:
	void destroyCard(Card card);
};

#endif
