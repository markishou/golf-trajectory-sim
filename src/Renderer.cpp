#include "Renderer.hpp"
#include <SFML/Graphics.hpp>

// Convert physics coordinates (meters) to screen coordinates (pixels)
sf::Vector2f toScreen(const Vector2& coordinate) {
    const float scale = 5.0f;       // 1 meter = 5 pixels
    const float padding = 50.0f;    // bottom-left padding

    float x = padding + coordinate.x * scale;
    float y = 600 - (padding + coordinate.y * scale);   // invert Y

    return sf::Vector2f(x,y);
}

void renderTrajectory(const std::vector<Vector2>& trajectory) {
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Golf Ball Trajectory");

    // Prepare dots for drawing
    sf::CircleShape dot(2.f);
    dot.setFillColor(sf::Color::White);

    std::vector<sf::Vector2f> trail; // store past positions for trail effect
    size_t currentIndex = 0;

    sf::Clock clock;
    float frameDelay = 0.01f; // seconds between each trajectory point

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                // no braces are needed if it's a single statement
                window.close();
        }

        if (currentIndex < trajectory.size() && clock.getElapsedTime().asSeconds() > frameDelay) {
            trail.push_back(toScreen(trajectory[currentIndex])); // add to trail
            dot.setPosition(toScreen(trajectory[currentIndex]));
            currentIndex++;
            clock.restart();
        }

        window.clear(sf::Color::Black);

        // Draw each point
        for (const auto& p : trail) {
            dot.setPosition(p);
            window.draw(dot);
        }

        window.display();
    }
}