// This tests the reset function to see if the deck is properly reset
// to the "newly opened" state.
#include "Deck.h"
#include "Card.h"
#include <cassert>
#include <iostream>
using namespace std;


int main()
{
	Deck d;
	
	d.shuffle(26); //shuffles the deck
	d.reset(); //resets the deck to a "newly opened" deck

	int i = 0;
	int suit = 0;
	int rank = 0;
	while (i < 52) {
		Card c = d.deal();

		if( c.get_rank() == Card::Rank(Card::TWO) && i > 0){
			suit ++;
			rank = 0; 
		}

		assert(c.get_rank() == static_cast<Card::Rank>(rank));
		assert(c.get_suit() == static_cast<Card::Suit>(suit));
	++i;
	++rank;
	}

	cout << "Passed Deck_test01!" << endl; 

return 0;
}
