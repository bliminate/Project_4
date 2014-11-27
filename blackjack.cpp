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
#include "rand.h"

using namespace std;

// REQUIRES: Deck and a pointer to a Player
// MODIFIES: Deck
// EFFECTS: Changes the deck that was passed by reference by shuffling. 
// Also informs the player that deck was shuffled. Also outputs where 
// the deck was cut for each shuffle. 
static void shuffler(Deck &gamedeck, Player *p) {
	cout << "Shuffling the deck\n";
	for(int cut_count = 0; cut_count < 7; ++cut_count) {
		int cut = get_cut();
		gamedeck.shuffle(cut); 
		p->shuffled(); 
		cout << "cut at " << cut << endl;	
	} 
	return; 
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		cout << "Usage: blackjack <bankroll> <hands> [simple|counting|competitor]" << endl; 
		exit(EXIT_FAILURE);
	}
	if (strcmp(argv[3], "simple") == 1) {
		if (strcmp(argv[3], "counting") == 1) {
			if (strcmp(argv[3], "competitor") == 1) {
				cout << "Usage: blackjack <bankroll> <hands> [simple|counting|competitor]" << endl; 
				exit(EXIT_FAILURE);
			}
		}
	}
	Player *player = player_factory(argv[3]); 
	Deck game_deck;
	Hand player_hand;
	Hand dealer_hand; 
	int bankroll = atoi(argv[1]);
	int hands = atoi(argv[2]);
	int minimum_bet = 5; 
	int thishand = 0;
	int wager = 0;

	shuffler(game_deck, player); 
	
	while(bankroll >= minimum_bet && thishand < hands) {
		//makes sure that hand is clear to begin with
		player_hand.discard_all();
		dealer_hand.discard_all();

		// Keeps track of hand count 
		++thishand; 
		cout << "Hand " << thishand << " bankroll " << bankroll << endl; 

		// If there are fewer than 20 cards left in the deck, reshuffle
		if(game_deck.cards_remaining() < 20) {
			shuffler(game_deck, player);
		}

		// Ask player for wager and announce it
		wager = player->bet(bankroll, minimum_bet); 
		cout << "Player bets " << wager << endl; 

		// Deal four cards
		// First card is dealt to player face up
		Card first_card_player = game_deck.deal();
		player_hand.add_card(first_card_player);
		cout << "Player dealt " << first_card_player << endl;
		// Expose player to the card that was dealt
		player->expose(first_card_player); 

		// Second card is dealt face up to dealer
		Card second_card_up_dealer = game_deck.deal(); 
		dealer_hand.add_card(second_card_up_dealer);
		cout << "Dealer dealt " << second_card_up_dealer << endl;
		// Expose player to the card that was dealt
		player->expose(second_card_up_dealer); 

		// Third card is dealt face up to player
		Card third_card_player = game_deck.deal();
		player_hand.add_card(third_card_player);
		cout << "Player dealt " << third_card_player << endl; 
		// Expose player to the card that was dealt
		player->expose(third_card_player); 

		// Fourth card is dealth face DOWN to the dealer
		Card fourth_card_down_dealer = game_deck.deal(); 
		dealer_hand.add_card(fourth_card_down_dealer); 

		// Checks to see if player is dealt natural 21
		if(player_hand.hand_value() == 21 && player_hand.hand_is_soft() == true) {
			cout << "Player dealt natural 21\n";
			// Immediately pay player 3/2 of bet and he wins the hand
			bankroll = (wager * 3)/2 + bankroll;
			continue; 
		}

		// Since player is not dealt a natural 21, we have player play his card
		// Draw cards until the player either stands or busts
		// Announce and expose each card

		while (player->draw(second_card_up_dealer, player_hand)) {
			Card add_to_player = game_deck.deal();
			player_hand.add_card(add_to_player);
			cout << "Player dealt " << add_to_player << endl;
			player->expose(add_to_player); 
		}

		cout << "Player's total is " << player_hand.hand_value() << endl;

		// If the player busts
		if(player_hand.hand_value() > 21) {
			cout << "Player busts\n";
			bankroll = bankroll - wager; 
			continue; 
		}
		
		// Since the player hasn't busted after playing his hand,
		// we announce the "hole card", FACE DOWN, card and expose it
		// NOTE: The hole card is NOT exposed if either the player
		// busts or is dealt a natural 21
		cout << "Dealer's hole card is " << fourth_card_down_dealer << endl;
		player->expose(fourth_card_down_dealer); 

		// Since player hasn't busted, play the dealer's hand
		// The dealer must hit until reaching seventeen or busting. 
		// Announce and expose
		while (dealer_hand.hand_value() < 17) {
			Card add_to_dealer = game_deck.deal();
			dealer_hand.add_card(add_to_dealer);
			cout << "Dealer dealt " << add_to_dealer << endl;
			player->expose(add_to_dealer); 
		}

		cout << "Dealer's total is " << dealer_hand.hand_value() << endl;

		if(dealer_hand.hand_value() > 21) {
			cout << "Dealer busts\n"; 
			bankroll = bankroll + wager; 
			player_hand.discard_all();
			dealer_hand.discard_all();
			continue;
		}

		else if(dealer_hand.hand_value() > player_hand.hand_value()) {
			cout << "Dealer wins\n";
			bankroll = bankroll - wager; 
		}
		else if(dealer_hand.hand_value() < player_hand.hand_value()) {
			cout << "Player wins\n"; 
			bankroll = bankroll + wager; 
		}
		else {
			cout << "Push\n"; 
		}
	}
	cout << "Player has " << bankroll << " after " << thishand << " hands\n";

	return 0; 
 }

