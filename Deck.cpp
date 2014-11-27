#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include "Card.h"
#include "Deck.h"

using namespace std; 

// You can call members functions in constructors, but
// YOU CANNOT CALL CONSTRUCTORS IN MEMBERS FUNCTIONS
// Deck default constructor
Deck::Deck() {
	reset();
}

// Reseting the deck
void Deck::reset() {
	int x = 0;
	while (x < DECK_SIZE) {
		for (int suit = 0; suit < 4; ++suit) {
			for (int rank = 0; rank < 13; ++rank) {
				cards[x] = Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));  
				x++; 
			}
		}
	}
	// next pointer is reset to first card in array
	next = &cards[0]; 
}

// Shuffling the deck
void Deck::shuffle(int n) {
	// For invalid inputs
	if(n < 0 || n > 52){
		cout << "Invalid place to cut the deck" << endl;
		return;
	}

	// Making a new array to hold cards from 1st card
	// to the nth card
	Card cards_array[52];
	int card_counter = 0;
	int left_in = 0;
	int right_in = n;

	// Copying over 1st card to nth card into the 
	// new array
	for(int x = 0; x < n; ++x) {
		cards_array[x] = cards[x]; 
	}

	// Updating original cards array in deck
	// by putting first card of right, and then 
	// first card of left, and so on
	while(left_in < n && right_in < 52) {
		cards[card_counter] = cards[right_in];
		card_counter++;
		right_in++;
		cards[card_counter] = cards_array[left_in];
		card_counter++;
		left_in++;
	}

	// This is for when the left deck has more cards
	// than the right deck. If the left deck has more 
	// cards, then the right will get exhausted first.
	// So we use this while loop to place the rest
	// of the left deck into the original cards array
	// in deck. 
	if(n > 26) {
		for(int x = card_counter; x < 52; ++x) {
			cards[x] = cards_array[left_in];
			left_in++; 
		}
	}

	// Reseting next pointer to first card in array
	next = &cards[0]; 
}

// Returns the Card at the position next is at
Card Deck::deal() {
	return *next++; 
}

// Cards remaining in the deck left to deal
int Deck::cards_remaining() const {
	return 52 - (next - cards); 
}






