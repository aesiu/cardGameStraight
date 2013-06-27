#ifndef _COMPUTER_
#define _COMPUTER_


#include "player.h"

class aiPlayer: public player{
public:
  aiPlayer();
	aiPlayer(player *human);
	~aiPlayer();
	virtual void dealNewHand(vector<Card>deck);
	virtual string autoplay();
	string discard();
//private:
};

#endif
