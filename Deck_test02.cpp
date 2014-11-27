// This tests that the reset function 
// recalls the cards that have been dealt
#include "Deck.h"
#include "Card.h"
#include <cassert>
#include <iostream>
using namespace std;


int main()
{
	Deck d;
	Card c1, c2, c3, c4, c5;
	
	d.shuffle(26);
	c1 = d.deal();
	c2 = d.deal();
	c3 = d.deal();
	c4 = d.deal();
	c5 = d.deal();

	d.reset();

	int i = 0;
	int suit = 0;
	int rank = 0;
	while (i < 52) {
		Card c = d.deal();

		if( c.get_rank() == Card::Rank(Card::TWO) && i > 0){
			suit ++;
			rank = 0;
		}

		assert(c.get_rank() == Card::Rank(rank));
		assert(c.get_suit() == Card::Suit(suit));
	++i;
	++rank;
	}

	cout << "Passed Deck_test02!" << endl; 

return 0;
}
