#include "ClubInput.hpp"
#include <iostream>

// Prompt for valid clubs
void printClubs(const std::vector<Club>& clubs) {
    for (size_t i = 0; i < clubs.size(); i++) {
        std::cout << i+1 << ". " << clubs[i].name << "\n";
    }
}

// Prompts user to input a valid index within the list of clubs
int getClubChoice(int maxIndex) {
    int choice = 0;

    while (true) {
        std::cout << "Select a club (1-" << maxIndex << "): ";
        std::cin >> choice;
        if (choice >= 1 && choice <= maxIndex) break;
        std::cout << "Invalid input. Try again.\n";
    }

    return choice - 1;
}