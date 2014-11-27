// Passes in invalid input i.e. a number > 52 or < 0.
#include "Deck.h"
#include "Card.h"
#include <cassert>
#include <iostream>
using namespace std;


int main()
{
	Deck d;
	Deck c;

	d.shuffle(76);
	d.shuffle(-34);

	int i = 0;
	int suit = 0;
	int rank = 0;
	while (i < 52) {
		Card cardc = c.deal();
		Card cardd = d.deal();
		assert(cardc.get_rank() == cardd.get_rank());
		assert(cardc.get_suit() == cardd.get_suit());
	++i;
	++rank;
	}
return 0;

}
