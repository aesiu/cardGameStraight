#include "humanPlayer.h"


humanPlayer::humanPlayer(){
	human = true;
}

humanPlayer::~humanPlayer(){
}

void humanPlayer::dealNewHand(vector<Card>deck){
	player::dealNewHand(deck);
}
string humanPlayer::autoplay(){
	throw "Human Players do not support autoplay";
}
