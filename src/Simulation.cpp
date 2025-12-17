#include "iostream"
#include "Simulation.hpp"
#include <cmath>

static constexpr double GRAVITY = -9.81; // m/s^2
static constexpr double DT = 0.016; // 60 FPS
static constexpr double DRAGG_COFF = 0.005; // change later

// constructor for simulator class
// - sets initial position of 0,0
// - sets velocity based on speed and angle
Simulation::Simulation(const Vector2& velocity, const Vector2& windVector) : position(0,0), velocity(velocity), wind(windVector) {}

// Return Trajectory array
const std::vector<Vector2>& Simulation::getTrajectory() const {
    return trajectory;
}

// Core game loop
// - repeatedly adds updated position to trajectory
void Simulation::run() {
    double apexHeight = 0;
    while (position.y >= 0) {
        trajectory.push_back(position);
        // Get apex height
        if (position.y > apexHeight) {
            apexHeight = position.y;
        }

        // print current position
        static int step = 0;
        if (step % 10 == 0) {
            std::cout << "x: " << position.x << "m, y: " << position.y << "m\n";

        }
        step++;

        // compute relative velocity
        Vector2 relVel = velocity - wind;
        // Drag acceleration (opposite direction of motion)
        Vector2 dragAcc = relVel.normalized() * (-DRAGG_COFF * relVel.length() * relVel.length());
        // Gravity
        dragAcc.y += GRAVITY;
        // Update velocity
        velocity = velocity + dragAcc * DT;
        // Update Position
        position = position + velocity * DT;
    }

    // total simulation time
    double simTime = trajectory.size() * DT;

    // total distance + apex height + Time of flight
    std::cout << "\nSimulation complete.\n";
    std::cout << "Total distance: " << trajectory.back().x << " m\n";
    std::cout << "Apex height: " << apexHeight << " m\n";
    std::cout << "Time of flight: " << simTime << " s\n";

}
