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
	Hand chand3;

	Card c = Card(Card::SEVEN, Card::SPADES);
	Card d = Card(Card::EIGHT, Card::CLUBS);

	Card j = Card(Card::SEVEN, Card::SPADES);
	Card k = Card(Card::SIX, Card::SPADES);

	Card l = Card(Card::SEVEN, Card::SPADES);
	Card m = Card(Card::SEVEN, Card::DIAMONDS);

	Card n = Card(Card::KING, Card::SPADES);
	Card o = Card(Card::SIX, Card::CLUBS);

	Card e = Card(Card::FOUR, Card::SPADES);
	Card f = Card(Card::TWO, Card::HEARTS);
	Card g = Card(Card::THREE, Card::CLUBS);
	Card h = Card(Card::FIVE, Card::DIAMONDS);
	Card i = Card(Card::SIX, Card::HEARTS);

	chand.add_card(c);
	chand.add_card(d);

	chand1.add_card(j);
	chand1.add_card(k);

	chand2.add_card(l);
	chand2.add_card(m);

	chand3.add_card(n);
	chand3.add_card(o);

	assert(cplayer->draw(e, chand) == false);
	assert(cplayer->draw(f, chand) == false);
	assert(cplayer->draw(g, chand) == false);
	assert(cplayer->draw(h, chand) == false);
	assert(cplayer->draw(i, chand) == false);

	assert(cplayer->draw(e, chand1) == false);
	assert(cplayer->draw(f, chand1) == false);
	assert(cplayer->draw(g, chand1) == false);
	assert(cplayer->draw(h, chand1) == false);
	assert(cplayer->draw(i, chand1) == false);

	assert(cplayer->draw(e, chand2) == false);
	assert(cplayer->draw(f, chand2) == false);
	assert(cplayer->draw(g, chand2) == false);
	assert(cplayer->draw(h, chand2) == false);
	assert(cplayer->draw(i, chand2) == false);

	assert(cplayer->draw(e, chand3) == false);
	assert(cplayer->draw(f, chand3) == false);
	assert(cplayer->draw(g, chand3) == false);
	assert(cplayer->draw(h, chand3) == false);
	assert(cplayer->draw(i, chand3) == false);

return 0;
}