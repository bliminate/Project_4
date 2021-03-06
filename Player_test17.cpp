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
	Card c = Card(Card::ACE, Card::SPADES);
	Card d = Card(Card::SEVEN, Card::CLUBS);

	Card e = Card(Card::TEN, Card::SPADES);
	Card f = Card(Card::THREE, Card::SPADES);
	Card g = Card(Card::FOUR, Card::SPADES);
	Card h = Card(Card::FIVE, Card::SPADES);
	Card i = Card(Card::SIX, Card::SPADES);
	Card j = Card(Card::NINE, Card::SPADES);
	Card k = Card(Card::JACK, Card::SPADES);
	Card l = Card(Card::QUEEN, Card::SPADES);
	Card m = Card(Card::KING, Card::SPADES);
	Card n = Card(Card::ACE, Card::CLUBS);

	chand.add_card(c);
	chand.add_card(d);

	assert(cplayer->draw(e, chand) == true);
	assert(cplayer->draw(f, chand) == true);
	assert(cplayer->draw(g, chand) == true);
	assert(cplayer->draw(h, chand) == true);
	assert(cplayer->draw(i, chand) == true);
	assert(cplayer->draw(j, chand) == true);
	assert(cplayer->draw(k, chand) == true);
	assert(cplayer->draw(l, chand) == true);
	assert(cplayer->draw(m, chand) == true);
	assert(cplayer->draw(n, chand) == true);

return 0;
}