#pragma once
#include <vector>
#include "Vector2.hpp"

class Simulation {
    public:
        Simulation(const Vector2& velocity, const Vector2& wind);
        const std::vector<Vector2>& getTrajectory() const;
        void run();
    private:
        Vector2 position; // position point
        Vector2 velocity; // velocity vector (m/s)
        Vector2 wind; // wind vector (m/s)
        std::vector<Vector2> trajectory;
};