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
	Card c = Card(Card::KING, Card::SPADES);
	Card d = Card(Card::EIGHT, Card::CLUBS);
	Card e = Card(Card::NINE, Card::SPADES);

	chand.add_card(c);
	chand.add_card(d);

	assert(cplayer->draw(e, chand) == false);

return 0;
}