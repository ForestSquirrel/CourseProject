#pragma once
#include <string>
#include "UtilityEnum.h"
#include "Utility.h"
#include <vector>

class Player { //this is our player class
private:
	std::string username; //username is for username
	PlayerType playerType; //check UtilityEnum.h
	CellStat ShipField[10][10]; //here u can see ur ships
	CellStat ShootField[10][10]; //and ur oponents grid where u shoot
	std::vector<int> ShipList = {4, 3, 2, 1}; //and these are game rules determined ship quantities
public:
	Player() { //default constructor
		username.clear();
		playerType = PlayerType::EMPTYSLOT;
		for (auto i = 0; i < 10; i++)
			for (auto j = 0; j < 10; j++) {
				ShipField[i][j] = CellStat::WATER;
				ShootField[i][j] = CellStat::WATER;
			}
	}
	Player(std::string name) { //username constructor //not planing to use but just in case
		username = name;
		playerType = PlayerType::USER;
		for (auto i = 0; i < 10; i++)
			for (auto j = 0; j < 10; j++) {
				ShipField[i][j] = CellStat::WATER;
				ShootField[i][j] = CellStat::WATER;
			}
	}
	Player(bool isAI) { //ai constructor
		username = "Jack The Sparrow";
		playerType = PlayerType::AI;
		for (auto i = 0; i < 10; i++)
			for (auto j = 0; j < 10; j++) {
				ShipField[i][j] = CellStat::WATER;
				ShootField[i][j] = CellStat::WATER;
			}
	}
	//setter, getter for username
	std::string get_username() {
		return username;
	}
	void set_username(std::string name) {
		username = name;
	}
	//setter, getter for player type
	PlayerType get_playerType() {
		return playerType;
	}
	void set_playerType(PlayerType type) {
		playerType = type;
	}
	//WIP
	void place_ship(std::string c1, std::string c2) {
		if (isShip(c1, c2, std::ref(ShipList))) {

		}
	}
};