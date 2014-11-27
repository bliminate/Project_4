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
	Card c = Card(Card::SEVEN, Card::SPADES);
	Card d = Card(Card::ACE, Card::CLUBS);

	Card e = Card(Card::SEVEN, Card::HEARTS);
	Card f = Card(Card::TWO, Card::SPADES);
	Card g = Card(Card::EIGHT, Card::SPADES);

	chand.add_card(c);
	chand.add_card(d);

	assert(cplayer->draw(e, chand) == false);
	assert(cplayer->draw(f, chand) == false);
	assert(cplayer->draw(g, chand) == false);

return 0;
}