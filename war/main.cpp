#include <iostream>
#include "card.hpp"

int main() {
    std::cout << "This is a game of war\n";
 
    // Create King of Spades   
    Card c(King, Spades);
    std::cout << "Created King of Spades\n";
}
