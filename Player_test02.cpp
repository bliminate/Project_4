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
	Card c = cdeck.deal();
	Card d = cdeck.deal();
	Card e = cdeck.deal();

	cplayer->expose(c);
	cplayer->expose(d);
	cplayer->expose(e);

	assert(cplayer->bet(10,3) == 6);

	cplayer->shuffled();

	assert(cplayer->bet(10,3) == 3);

return 0;
}