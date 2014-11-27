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

	Deck d; 
	Hand chand;
	Card c = d.deal();

	chand.add_card(d.deal());
	chand.add_card(d.deal());

	assert(cplayer->draw(c, chand) == true);
	
	return 0;
	}