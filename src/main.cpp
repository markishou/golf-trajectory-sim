#include <iostream>
#include "Simulation.hpp"
#include "Vector2.hpp"
#include "ClubDatabase.hpp"
#include "ClubInput.hpp"
#include "Renderer.hpp"

int main() {
    // Get club input from user
    auto clubs = createClubs();
    printClubs(clubs);
    int choice = getClubChoice(clubs.size());
    const Club& club = clubs[choice];

    // set tailwind
    Vector2 wind(2.0, 0.0);

    // set initial velocity based on user-inputted club
    double angleRad = club.launchAngleDeg * M_PI / 180.0;
    Vector2 initialVelocity{
        club.launchSpeed * std::cos(angleRad),
        club.launchSpeed * std::sin(angleRad)
    };

    Simulation sim(initialVelocity, wind);
    sim.run();

    renderTrajectory(sim.getTrajectory());

    return 0;
}