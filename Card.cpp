#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include "Card.h"

// READ LAST PAGE IN THE SPEC
// TO PROPERLY COUT "RANK of SUIT"
std::ostream& operator << (std::ostream& os, const Card& c) {
	const char *const SUIT_NAMES[] = {"Spades", "Hearts", "Clubs", "Diamonds"};
	const char *const RANK_NAMES[] = {"Two", "Three", "Four", "Five", "Six", 
                                  "Seven", "Eight", "Nine", "Ten", "Jack", 
                                  "Queen", "King", "Ace"};
    int rank = c.get_rank();
    int suit = c.get_suit();
	os << RANK_NAMES[rank] << " of " << SUIT_NAMES[suit]; 
	return os;
}

using namespace std; 
// Card default constructor
Card::Card() 
	: rank(TWO), suit(SPADES) {}

// Card custom constructor
Card::Card(Rank rank_in, Suit suit_in)
	: rank(rank_in), suit(suit_in) {}

// Getter function for rank
Card::Rank Card::get_rank() const {
	return rank; 
}

// Getter function for suit
Card::Suit Card::get_suit() const {
	return suit; 
}