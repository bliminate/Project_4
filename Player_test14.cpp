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

	Card c = Card(Card::QUEEN, Card::SPADES);
	Card d = Card(Card::FIVE, Card::CLUBS);

	Card n = Card(Card::SEVEN, Card::SPADES);
	Card o = Card(Card::SIX, Card::SPADES);

	Card p = Card(Card::SEVEN, Card::SPADES);
	Card q = Card(Card::SEVEN, Card::DIAMONDS);

	Card r = Card(Card::KING, Card::SPADES);
	Card s = Card(Card::SIX, Card::CLUBS);

	Card e = Card(Card::JACK, Card::SPADES);
	Card f = Card(Card::SEVEN, Card::HEARTS);
	Card g = Card(Card::EIGHT, Card::CLUBS);
	Card h = Card(Card::NINE, Card::DIAMONDS);
	Card i = Card(Card::TEN, Card::HEARTS);
	Card k = Card(Card::QUEEN, Card::HEARTS);
	Card l = Card(Card::KING, Card::CLUBS);
	Card m = Card(Card::ACE, Card::DIAMONDS);

	chand.add_card(c);
	chand.add_card(d);

	chand1.add_card(n);
	chand1.add_card(o);

	chand2.add_card(p);
	chand2.add_card(q);

	chand3.add_card(r);
	chand3.add_card(s);

	assert(cplayer->draw(e, chand) == true);
	assert(cplayer->draw(f, chand) == true);
	assert(cplayer->draw(g, chand) == true);
	assert(cplayer->draw(h, chand) == true);
	assert(cplayer->draw(i, chand) == true);
	assert(cplayer->draw(k, chand) == true);
	assert(cplayer->draw(l, chand) == true);
	assert(cplayer->draw(m, chand) == true);

	assert(cplayer->draw(e, chand1) == true);
	assert(cplayer->draw(f, chand1) == true);
	assert(cplayer->draw(g, chand1) == true);
	assert(cplayer->draw(h, chand1) == true);
	assert(cplayer->draw(i, chand1) == true);
	assert(cplayer->draw(k, chand1) == true);
	assert(cplayer->draw(l, chand1) == true);
	assert(cplayer->draw(m, chand1) == true);

	assert(cplayer->draw(e, chand2) == true);
	assert(cplayer->draw(f, chand2) == true);
	assert(cplayer->draw(g, chand2) == true);
	assert(cplayer->draw(h, chand2) == true);
	assert(cplayer->draw(i, chand2) == true);;
	assert(cplayer->draw(k, chand2) == true);
	assert(cplayer->draw(l, chand2) == true);
	assert(cplayer->draw(m, chand2) == true);

	assert(cplayer->draw(e, chand3) == true);
	assert(cplayer->draw(f, chand3) == true);
	assert(cplayer->draw(g, chand3) == true);
	assert(cplayer->draw(h, chand3) == true);
	assert(cplayer->draw(i, chand3) == true);
	assert(cplayer->draw(k, chand3) == true);
	assert(cplayer->draw(l, chand3) == true);
	assert(cplayer->draw(m, chand3) == true);

return 0;
}