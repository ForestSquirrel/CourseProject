#pragma once
#include "Player.h"
#include <ctime>

class GameCore { //this is supposed to be main game class
private:
	Player Player1; //first victim
	Player Player2; //second victim
	PlayerOrder WhosTurn; //and who is going to be dominatrix for this turn
public:
	GameCore() { //multiplayer game constructor
		Player1 = Player();
		Player2 = Player();

		srand(time(0));
		int coin = rand() % 2;
		switch (coin)
		{
		case 0:
			WhosTurn = PlayerOrder::FIRST;
			break;
		case 1:
			WhosTurn = PlayerOrder::SECOND;
			break;
		}
	}

	GameCore(bool withAI) { //singleplayer game constructor (with AI)
		Player1 = Player(true);
		Player2 = Player();

		srand(time(0));
		int coin = rand() % 2;
		switch (coin)
		{
		case 0:
			WhosTurn = PlayerOrder::FIRST;
			break;
		case 1:
			WhosTurn = PlayerOrder::SECOND;
			break;
		}
	}
	//getters to acces players via reference
	Player& get_player1() {
		return Player1;
	}
	Player& get_player2() {
		return Player2;
	}
	//getter, setter for turn based system
	PlayerOrder get_whosturn() {
		return WhosTurn;
	}
	void set_whosturn(PlayerOrder turn) {
		WhosTurn = turn;
	}
	//and this one for regestering players who wanna play
	void reg_player(std::string username) {
		if (get_player1().get_playerType() == PlayerType::EMPTYSLOT) {
			get_player1().set_username(username);
		}
		else if (get_player2().get_playerType() == PlayerType::EMPTYSLOT) {
			get_player2().set_username(username);
		}
		else {
			throw std::logic_error("Game is full");
		}
	}
};