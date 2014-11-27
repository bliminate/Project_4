// Tests shuffle when split at "52".
#include "Deck.h"
#include "Card.h"
#include <cassert>
#include <iostream>
using namespace std;


int main()
{
	Deck d;
	Deck c;

	d.shuffle(52);
	
	int i = 0;
	int suit = 0;
	int rank = 0;
	while (i < 52) {
		Card card = c.deal();

		if( card.get_rank() == Card::Rank(Card::TWO) && i > 0){
			suit ++;
			rank = 0; 
		}

		assert(card.get_rank() == static_cast<Card::Rank>(rank));
		assert(card.get_suit() == static_cast<Card::Suit>(suit));
	++i;
	++rank;
	}

	cout << "Passed Deck_test04!" << endl; 

return 0;
}
