#pragma once
#include <utility>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <queue>

std::pair<int, int> IdToIndex(std::string &Id) { // this one converts string to pair e.g. a1 -> <0, 0> or g8 -> <6, 7>
	char letter = Id.at(0);
	std::string temp;
	for (auto i = 1; i < Id.size(); i++) {
		if (std::isdigit(Id.at(i)))
			temp += Id.at(i);
		else
			throw std::invalid_argument("Wrong index");
	}
	int number = stoi(temp) - 1; //minus 1 since starting index of an array is 0
	if (number > 10)
		throw std::invalid_argument("Wrong index");
	switch (letter)
	{
	case 'a':
		return std::make_pair(0, number);
	case 'b':
		return std::make_pair(1, number);
	case 'c':
		return std::make_pair(2, number);
	case 'd':
		return std::make_pair(3, number);
	case 'e':
		return std::make_pair(4, number);
	case 'f':
		return std::make_pair(5, number);
	case 'g':
		return std::make_pair(6, number);
	case 'h':
		return std::make_pair(7, number);
	case 'i':
		return std::make_pair(8, number);
	case 'j':
		return std::make_pair(9, number);
	default:
		throw std::invalid_argument("Wrong index");
		break;
	}
}

bool isShip(std::string c1, std::string c2, std::vector<int>& ShipList) { //this one determines if ur input can be a ship or not
	std::pair<int, int> cell1 = IdToIndex(c1);
	std::pair<int, int> cell2 = IdToIndex(c2);
	if ((cell1.first != cell2.first) && (cell1.second != cell2.second)) { //check if ship is linear
		throw std::invalid_argument("Ship is not linear");
	}
	else if (cell1.second == cell2.second) { //check if u have ship slot for it (determined by game rules) one 4-deck ship, three 2-deck ships etc.
		switch (std::max(cell1.first, cell2.first) - std::min(cell1.first, cell2.first))
		{
		case 0: {
			if (ShipList.at(0) != 0) {
				return true;
			}
			else {
				throw std::logic_error("You have max ships possible of this type");
				return false;
			}
		}
		case 1: {
			if (ShipList.at(1) != 0) {
				return true;
			}
			else {
				throw std::logic_error("You have max ships possible of this type");
				return false;
			}
		}
		case 2: {
			if (ShipList.at(2) != 0) {
				return true;
			}
			else {
				throw std::logic_error("You have max ships possible of this type");
				return false;
			}
		}
		case 3: {
			if (ShipList.at(0) != 0) {
				return true;
			}
			else {
				throw std::logic_error("You have max ships possible of this type");
				return false;
			}
		}
		default:
			throw std::invalid_argument("Ship is too long");
			return false;
		}
	}
	else if (cell1.first == cell2.first) {
		switch (std::max(cell1.second, cell2.second) - std::min(cell1.second, cell2.second))
		{
		case 0: {
			if (ShipList.at(0) != 0) {
				return true;
			}
			else {
				throw std::logic_error("You have max ships possible of this type");
				return false;
			}
		}
		case 1: {
			if (ShipList.at(1) != 0) {
				return true;
			}
			else {
				throw std::logic_error("You have max ships possible of this type");
				return false;
			}
		}
		case 2: {
			if (ShipList.at(2) != 0) {
				return true;
			}
			else {
				throw std::logic_error("You have max ships possible of this type");
				return false;
			}
		}
		case 3: {
			if (ShipList.at(0) != 0) {
				return true;
			}
			else {
				throw std::logic_error("You have max ships possible of this type");
				return false;
			}
		}
		default:
			throw std::invalid_argument("Ship is too long");
			return false;
		}
	}
}

std::queue<std::pair<int, int>> getCollisionZone(std::string c1, std::string c2) { //only if ship IS SHIP... //returns queued area around the ship
	std::pair<int, int> cell1 = IdToIndex(c1);
	std::pair<int, int> cell2 = IdToIndex(c2);
	std::queue<std::pair<int, int>> collisionZone;
	if (cell1.second == cell2.second) { //vertical ship orientation
		int size = std::max(cell1.first, cell2.first) - std::min(cell1.first, cell2.first);
		for (auto i = std::min(cell1.first, cell2.first) - 1; i <= std::max(cell1.first, cell2.first) + 1; i++) {
			if (i >= 0 && cell1.second - 1 >= 0 && i < 10)
				collisionZone.push(std::make_pair(i, cell1.second - 1));
		}
		if (std::min(cell1.first, cell2.first) - 1 >= 0)
			collisionZone.push(std::make_pair(std::min(cell1.first, cell2.first) - 1, cell1.second));
		if (std::max(cell1.first, cell2.first) + 1 < 10)
			collisionZone.push(std::make_pair(std::min(cell1.first, cell2.first) + 1, cell1.second));
		for (auto i = std::min(cell1.first, cell2.first) - 1; i <= std::max(cell1.first, cell2.first) + 1; i++) {
			if (i >= 0 && cell1.second + 1 < 10 && i < 10)
				collisionZone.push(std::make_pair(i, cell1.second + 1));
		}
	}
	else { //horizontal ship orientation
		int size = std::max(cell1.second, cell2.second) - std::min(cell1.second, cell2.second);
		for (auto i = std::min(cell1.second, cell2.second) - 1; i <= std::max(cell1.second, cell2.second) + 1; i++) {
			if (i >= 0 && cell1.first - 1 >= 0 && i < 10)
				collisionZone.push(std::make_pair(cell1.first - 1, i));
		}
		if (std::min(cell1.second, cell2.second) - 1 >= 0)
			collisionZone.push(std::make_pair(std::min(cell1.second, cell2.second) - 1, cell1.first));
		if (std::max(cell1.second, cell2.second) + 1 < 10)
			collisionZone.push(std::make_pair(std::min(cell1.second, cell2.second) + 1, cell1.first));
		for (auto i = std::min(cell1.second, cell2.second) - 1; i <= std::max(cell1.second, cell2.second) + 1; i++) {
			if (i >= 0 && cell1.first + 1 < 10 && i < 10)
				collisionZone.push(std::make_pair(cell1.first + 1, i));
		}
	}
}