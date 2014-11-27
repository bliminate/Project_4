#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"

using namespace std;

// You don't need to store the actual card values in a hand
// object.
// The only thing that matters is what the value of all the 
// cards in the hand is and whether or not the hand is hard 
// or soft. This is why there is no array member variable 

// Custom constructor for Hand
Hand::Hand() {
	discard_all(); 
}

// Discards "cards" in hand and resets count to 0 and 
// initialized the hand to a hard hand
void Hand::discard_all() {
	value = 0;
	soft = false;

}

// Adding a card to the hand and determining whether 
// a hand is soft or hard when an Ace is added
// Ace is the tricky case
void Hand::add_card(Card c) {
	int RANK_VALUES_SOFT[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10,
		10, 10, 10, 11};
	int RANK_VALUES_HARD[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10,
		10, 10, 10, 1};
	for(int rank = 0; rank < 13; ++rank) {
		// Check the rank of the card passed in
		if (static_cast<Card::Rank>(rank) == c.get_rank()) {
			// If the card is an Ace
			if(rank == 12) {
				// If the Ace can bust the hand
				if (value + 11 > 21) {
					// If the Ace can bust the hand, but there is 
					// also another Ace in the hand
					if(soft) {
						// Change the value of the Ace in 
						// the hand to 1
						value = value - 10; 
						// Add a soft value of the current Ace
						value = value + RANK_VALUES_SOFT[rank];
						// If a soft value of the current Ace can 
						// bust the hand
						if(value > 21) {
							// Take back the soft value and add
							// the current Ace as hard, hand is hard
							value = value - 11; 
							value = value + RANK_VALUES_HARD[rank];
							soft = false;
						}
						else {
							soft = true; 
						}
					}
					// If there is no other Ace in the hand
					else {
						value = value + RANK_VALUES_HARD[rank];
						soft = false;
					}
				}
				// If the current Ace cannot bust the hand, add it 
				// as a soft value
				else {
						value = value + RANK_VALUES_SOFT[rank];
						soft = true; 
					}
			}
			// If the current card is not an Ace, but it can still bust
			// the hand and the hand contains an Ace
			else if (value + RANK_VALUES_HARD[rank] > 21 && soft == true) { 
				// Turn the value of the Ace in the 
				// hand to a hard value, hand is hard. 
				value = value - 10;
				soft = false;
				value = value + RANK_VALUES_HARD[rank];
			}
			// For all other cases, might bust the hand
			else {
				value = value + RANK_VALUES_HARD[rank];
			}
		}
	}
}

// Getter function for value
int Hand::hand_value() const {
	return value; 
}

// Getter function for soft
bool Hand::hand_is_soft() const{
	if (soft) {
		return true; 
	}
	return false;
}

