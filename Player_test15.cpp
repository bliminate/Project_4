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
	Hand chand1;
	Hand chand2;

	Card c = Card(Card::ACE, Card::SPADES);
	Card d = Card(Card::FIVE, Card::CLUBS);

	Card f = Card(Card::SIX, Card::CLUBS);

	Card g = Card(Card::TWO, Card::CLUBS);

	Card e = Card(Card::FOUR, Card::SPADES);

	chand.add_card(c);
	chand.add_card(d);

	chand1.add_card(c);
	chand1.add_card(f);

	chand2.add_card(c);
	chand2.add_card(g);

	assert(cplayer->draw(e, chand) == true);
	assert(cplayer->draw(e, chand1) == true);
	assert(cplayer->draw(e, chand2) == true);

return 0;
}