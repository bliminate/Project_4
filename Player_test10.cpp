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
	Card c = Card(Card::SIX, Card::SPADES);
	Card d = Card(Card::SIX, Card::CLUBS);
	Card e = Card(Card::FOUR, Card::SPADES);
	Card f = Card(Card::FIVE, Card::DIAMONDS);
	Card g = Card(Card::SIX, Card::HEARTS);

	chand.add_card(c);
	chand.add_card(d);

	assert(cplayer->draw(e, chand) == false);
	assert(cplayer->draw(f, chand) == false);
	assert(cplayer->draw(g, chand) == false);

return 0;
}