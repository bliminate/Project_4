// Player_test00.cpp
// 
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

int main() {
	const char* counting = "counting";
	Player *cplayer = player_factory(counting);

	assert(cplayer->bet(10,3) == 3);

  return 0;
}
