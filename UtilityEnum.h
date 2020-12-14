#pragma once
enum class CellStat { //status of grid cell
	WATER, //ok  its simple just water
	SHIP,  //ship...
	MISS,  //ribbles on water when u miss //for fancy gui
	SSHIP  //damaged or killed ship  //fancy gui here
};

enum class PlayerOrder { //this determines whos turn now
	FIRST, 
	SECOND
};

enum class PlayerType { //and this one to determine who are they/them player
	USER, //its a user
	AI, //ai
	EMPTYSLOT //this one for default player constructor
};