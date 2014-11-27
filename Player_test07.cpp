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

int main()
{
	const char* counting = "counting";
	Player *cplayer = player_factory(counting);

	Hand chand; 
	Deck cdeck; 
	cdeck.shuffle(15);

	for(int i = 0; i < 4; ++i){
		cplayer->expose(cdeck.deal());
	}

	assert(cplayer->bet(10, 3) == 6);

return 0;
}