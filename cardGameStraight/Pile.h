#include "Card.h"
#include <vector>

class Pile{
public:
	Pile();
	~Pile();
	void addToPile(Card card);
	bool isValidMove(Card card);
private:
	vector <Card> pile;
	int validCards[8]; // first four are the smallest value of all suites, the next four are the biggest value
};

