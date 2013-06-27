#include "aiPlayer.h"

aiPlayer::aiPlayer(){
  human = false;
}

aiPlayer::aiPlayer(player* humanPlayer){
	human = false;
	vector<Card> hand(humanPlayer->getHand());
	vector<Card> discard(humanPlayer->getDiscard());
	score = humanPlayer->getScore();

	//copy values used for ragequit
}

aiPlayer::~aiPlayer(){
	human = false;
}

string aiPlayer::autoplay(){
	for(int i =0; i < hand.size(); i++){
		if(pile.isValidMove(hand[i])){
			string ret = hand[i].convertSuitToString()+hand[i].convertRankToString();
			player::playCard(hand[i]);
			return "plays "+ret;
		}
	}
	return discard();
}

string aiPlayer::discard(){
	string ret = hand[0].convertSuitToString()+hand[0].convertRankToString();
	player::discardCard(hand[0]);
	return "discards "+ret;
}
void aiPlayer::dealNewHand(vector<Card>deck){
	player::dealNewHand(deck);
}
