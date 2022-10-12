// CGT 215 Game physics practice- Evan Yoder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp> // Providing the images to the code.
#include <SFPhysics.h> // Providing the physics to the code.

using namespace std;
using namespace sf;
using namespace sfp;


int main()
{
    RenderWindow window(VideoMode(800, 600), "Bounce"); // Creating the range of our window.
    World world(Vector2f(0, 1));

    PhysicsCircle ball; // Draws the circle.
    ball.setCenter(Vector2f(400, 300)); // The center of the ball.
    ball.setRadius(20); // The size of the ball.
    world.AddPhysicsBody(ball); // Adding the physics to the ball.

    PhysicsRectangle floor; // Draws the rectangle (window).
    floor.setSize(Vector2f(800, 20)); // setSize(creating the dimensions for the window). 
    // Vector2f(shows the image).
    floor.setCenter(Vector2f(400, 590));
    // setCenter (gives dimensions to the ball).
    floor.setStatic(true);
    world.AddPhysicsBody(floor); // Adding a "floor" barrier to the window.

    Clock clock; // Clock gives us current time.
    Time lastTime(clock.getElapsedTime()); // Time holds a moment in time. 
    while (true) {
        Time currentTime(clock.getElapsedTime());
        Time deltaTime(currentTime - lastTime);
        // "deltaTime" is (present time minus past time).
        int deltaTimeMS(deltaTime.asMilliseconds()); 
        // The time is done calculated in Milliseconds.
        if (deltaTimeMS > 0) {
            world.UpdatePhysics(deltaTimeMS);
            lastTime = currentTime;
            
             window.clear(Color (0,0,0));
             window.draw(ball);
             window.draw(floor);
             window.display();
             while (true);
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
