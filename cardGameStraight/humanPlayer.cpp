#include "player.h"
#include<algorithm>
#include<sstream>

class humanPlayer: public player{
public:
	humanPlayer();
	~humanPlayer();
	string output[6];
	virtual void dealNewHand(vector<Card>deck,  int playerNum);
private:
	vector<int> outputInt[4];
}

void humanPlayer::dealNewHand(vector<Card>deck,  int playerNum){
	player::dealNewHand(deck,playerNum);
	for(int i =0;i<13;i++){
		outputInt[hand[i].getSuit()].push_back(hand[i].getRank());
		output[4].append(hand[i].convertRankToString().append( hand[i].convertSuitToString()));
		output[4].append(" ");
		if(pile.isValidMove(hand[i])){
			output[5].append(hand[i].convertRankToString().append( hand[i].convertSuitToString()));
			output[5].append(" ");
		}
	}
	for(int i = 0;i<4;i++){
		sort(outputInt[i].begin(), outputInt[i].end());
		for(int j = 0;j<outputInt[i].size();j++){
			ostringstream os;
			os << outputInt[i].at(j);
			output[i].append(os.str());
		}
	}
}
