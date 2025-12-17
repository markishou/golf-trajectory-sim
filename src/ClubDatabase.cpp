#include "ClubDatabase.hpp"

// Create list of clubs that can be selected by user
std::vector<Club> createClubs() {
    return {
        {"Driver", 70.0, 12.0},
        {"Iron", 50.0, 25.0},
        {"Wedge", 35.0, 45.0}
    };
}