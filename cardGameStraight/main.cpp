
#include <iostream>
#include "Card.h"
#include "Command.h"
#include "aiPlayer.h"
#include "humanPlayer.h"
#include "Deck.h"

//remember to catch after throwing

int main(int seed){
	player* players[4];
	
	for(int i = 0;i<4;i++){
		string s;
		cout<<"Is player "<<(i+1)<<" a human(h) or a computer(c)?"<<endl;
		cin>>s;
		if(s == "c"){
			players[i] = new aiPlayer();
		}else if (s == "h"){
			players[i] = new humanPlayer();
		}else {
			throw "failed shitless";
		}
	}
	while (true){
	Deck deck = *(new Deck());
	int starter;
	for (int i=0; i < 4; i++){
		players[i]->dealNewHand(deck.dealTop());
		if (players[i]->hasCard(Card(SPADE,SEVEN))){
			starter = i;
		}
	}
	
	for (int rounds = 0;rounds<13; rounds++){
		cout <<"A new round begins. It's player "<<(starter+1)<<"'s turn to play."<<endl;
		for (int i =0; i<4; i++){
			int turnPlayer = (starter+i)%4;
			if(players[turnPlayer]->isHuman()){
				cout<<"Cards on the table:"<<endl;
				cout<<"Clubs: "<<player::getRangeOfSuit(CLUB) <<endl;
				cout<<"Diamonds: "<<player::getRangeOfSuit(DIAMOND) <<endl;
				cout<<"Hearts: "<<player::getRangeOfSuit(HEART) <<endl;
				cout<<"Spades: "<<player::getRangeOfSuit(SPADE) <<endl;
				cout<< "Your hand: "<< players[turnPlayer]->getHandString()<<endl;
				cout<< "Legal plays: "<< players[turnPlayer]->getLegalPlaysString()<<endl;
				bool finished = false;
				while (!finished){
				Command c;
				cin>>c;
				
				if (c.type == PLAY){
					try {
						players[turnPlayer]->playCard(c.card);
						cout<< "Player " << turnPlayer+1 << " plays "<< c.card.convertRankToString() << c.card.convertSuitToString()<< endl;
						finished = true;
					}
					catch(string s){
						cout<< s << endl;
					}
				} else if(c.type == DISCARD){
					try {
						players[turnPlayer] ->discardCard(c.card);
						cout<< "Player " << turnPlayer+1 << " discards "<< c.card.convertRankToString() << c.card.convertSuitToString()<<endl;
						finished = true;
					} catch(string s){
						cout<< s << endl;
					}
				} else if (c.type == DECK){
					cout<<deck.getString()<<endl;
					i--;
				} else if (c.type == QUIT){
					throw "ERIC IF YOU DON'T FIND AND FIX THIS I WILL MURDER YOU";
				} else if (c.type == RAGEQUIT){
					players[turnPlayer] = new aiPlayer(players[turnPlayer]);
				}
				}
			} else{
				cout <<"Player "<<turnPlayer+1<<" "<< players[turnPlayer]->autoplay()<<endl;
			}
		}
	}
	for (int i =0; i < 4; i++){
		cout<< "Player "<< i+1<<"'s score is " << players[i]->getScore();
	}
	}
	
}



