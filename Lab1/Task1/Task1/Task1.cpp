#include <SFML/Graphics.hpp>
#include <vector>
#include "Task1.h"
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(800, 600), "Initials", Style::Default, settings);

    int letterSize = 50;
    Vector2f position1 = Vector2f(50, 150);
    Vector2f position2 = position1 + Vector2f(letterSize * 5, 0);
    Vector2f position3 = position2 + Vector2f(letterSize * 5, 0);

    Letter* letterYa = CreateShapeYa(-0.7, position1, letterSize);
    Letter* letterA = CreateShapeA(-0.9, position2, letterSize);
    Letter* letterV = CreateShapeV(-0.5, position3, letterSize);

    Clock clock;
    float time;
    while (window.isOpen())
    {
        time = clock.getElapsedTime().asSeconds();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);

        letterYa->Jump(time);
        letterA->Jump(time);
        letterV->Jump(time);

        letterYa->Draw(window);
        letterA->Draw(window);
        letterV->Draw(window);

        window.display();
    }

    return 0;
}

Letter* CreateShapeA(float axceleration, sf::Vector2f position, int size)
{
    vector<ConvexShape> convexShapes;
    vector<RectangleShape> rectangleShapes;
    Color color = Color::Red;

    ConvexShape shapeL;
    shapeL.setPointCount(6);
    shapeL.setPoint(0, position + Vector2f(0, 4 * size));
    shapeL.setPoint(1, position + Vector2f(size, 4 * size));
    shapeL.setPoint(2, position + Vector2f(2 * size, size));
    shapeL.setPoint(3, position + Vector2f(3 * size, 4 * size));
    shapeL.setPoint(4, position + Vector2f(4 * size, 4 * size));
    shapeL.setPoint(5, position + Vector2f(2 * size, 0));
    shapeL.setFillColor(color);
    convexShapes.push_back(shapeL);

    RectangleShape centerRectangle(Vector2f(2 * size, 0.5 * size));
    centerRectangle.setPosition(position + Vector2f(size, 2.7 * size));
    centerRectangle.setFillColor(color);
    rectangleShapes.push_back(centerRectangle);

    return new Letter(axceleration, convexShapes, rectangleShapes);
}

Letter* CreateShapeYa(float startSpeed, sf::Vector2f position, int size)
{
    vector<ConvexShape> convexShapes;
    vector<RectangleShape> rectangleShapes;
    Color color = Color::Blue;

    ConvexShape shapeTopPartRight;
    shapeTopPartRight.setPointCount(6);
    shapeTopPartRight.setPoint(0, position + Vector2f(2 * size, 0));
    shapeTopPartRight.setPoint(1, position + Vector2f(4 * size, 0));
    shapeTopPartRight.setPoint(2, position + Vector2f(4 * size, 2 * size));
    shapeTopPartRight.setPoint(3, position + Vector2f(3 * size, 2 * size));
    shapeTopPartRight.setPoint(4, position + Vector2f(3 * size, size));
    shapeTopPartRight.setPoint(5, position + Vector2f(2 * size, size));
    shapeTopPartRight.setFillColor(color);

    ConvexShape shapeTopPartLeft;
    shapeTopPartLeft.setPointCount(4);
    shapeTopPartLeft.setPoint(0, position + Vector2f(2 * size, 0));
    shapeTopPartLeft.setPoint(1, position + Vector2f(size, size));
    shapeTopPartLeft.setPoint(2, position + Vector2f(size, 2 * size));
    shapeTopPartLeft.setPoint(3, position + Vector2f(2 * size, 3 * size));
    shapeTopPartLeft.setFillColor(color);

    ConvexShape shapeBotPartRight;
    shapeBotPartRight.setPointCount(6);
    shapeBotPartRight.setPoint(0, position + Vector2f(2 * size, 2 * size));
    shapeBotPartRight.setPoint(1, position + Vector2f(4 * size, 2 * size));
    shapeBotPartRight.setPoint(2, position + Vector2f(4 * size, 4 * size));
    shapeBotPartRight.setPoint(3, position + Vector2f(3 * size, 4 * size));
    shapeBotPartRight.setPoint(4, position + Vector2f(3 * size, 3 * size));
    shapeBotPartRight.setPoint(5, position + Vector2f(2 * size, 3 * size));
    shapeBotPartRight.setFillColor(color);

    ConvexShape shapeBotPartLeft;
    shapeBotPartLeft.setPointCount(4);
    shapeBotPartLeft.setPoint(0, position + Vector2f(2 * size, 2 * size));
    shapeBotPartLeft.setPoint(1, position + Vector2f(size, 3 * size));
    shapeBotPartLeft.setPoint(2, position + Vector2f(size, 4 * size));
    shapeBotPartLeft.setPoint(3, position + Vector2f(2 * size, 4 * size));
    shapeBotPartLeft.setFillColor(color);

    convexShapes.push_back(shapeTopPartRight);
    convexShapes.push_back(shapeTopPartLeft);
    convexShapes.push_back(shapeBotPartRight);
    convexShapes.push_back(shapeBotPartLeft);

    return new Letter(startSpeed, convexShapes, rectangleShapes);
}

Letter* CreateShapeV(float startSpeed, sf::Vector2f position, int size)
{
    vector<ConvexShape> convexShapes;
    vector<RectangleShape> rectangleShapes;
    Color color = Color::Green;

    ConvexShape shapeBotPartLeft;
    shapeBotPartLeft.setPointCount(8);
    shapeBotPartLeft.setPoint(0, position + Vector2f(size, 4 * size));
    shapeBotPartLeft.setPoint(1, position + Vector2f(0, 3.5 * size));
    shapeBotPartLeft.setPoint(2, position + Vector2f(0, 2.5 * size));
    shapeBotPartLeft.setPoint(3, position + Vector2f(size, 2 * size));
    shapeBotPartLeft.setPoint(4, position + Vector2f(size, 2.5 * size));
    shapeBotPartLeft.setPoint(5, position + Vector2f(0.5 * size, 2.5 * size));
    shapeBotPartLeft.setPoint(6, position + Vector2f(0.5 * size, 3 * size));
    shapeBotPartLeft.setPoint(7, position + Vector2f(size, 3.5 * size));
    shapeBotPartLeft.setFillColor(color);

    ConvexShape shapeTopPartLeft;
    shapeTopPartLeft.setPointCount(8);
    shapeTopPartLeft.setPoint(0, position + Vector2f(size, 2 * size));
    shapeTopPartLeft.setPoint(1, position + Vector2f(0, 1.5 * size));
    shapeTopPartLeft.setPoint(2, position + Vector2f(0, 0.5 * size));
    shapeTopPartLeft.setPoint(3, position + Vector2f(size, 0));
    shapeTopPartLeft.setPoint(4, position + Vector2f(size, 0.5 * size));
    shapeTopPartLeft.setPoint(5, position + Vector2f(0.5 * size, 0.5 * size));
    shapeTopPartLeft.setPoint(6, position + Vector2f(0.5 * size, size));
    shapeTopPartLeft.setPoint(7, position + Vector2f(size, 1.5 * size));
    shapeTopPartLeft.setFillColor(color);

    ConvexShape shapeBotPartRight;
    shapeBotPartRight.setPointCount(6);
    shapeBotPartRight.setPoint(0, position + Vector2f(1 * size, 1.5 * size));
    shapeBotPartRight.setPoint(1, position + Vector2f(3 * size, 1.5 * size));
    shapeBotPartRight.setPoint(2, position + Vector2f(3 * size, 3.5 * size));
    shapeBotPartRight.setPoint(3, position + Vector2f(2 * size, 3.5 * size));
    shapeBotPartRight.setPoint(4, position + Vector2f(2 * size, 2.5 * size));
    shapeBotPartRight.setPoint(5, position + Vector2f(1 * size, 2.5 * size));
    shapeBotPartRight.setFillColor(color);

    ConvexShape shapeTopPartRight;
    shapeTopPartRight.setPointCount(6);
    shapeTopPartRight.setPoint(0, position + Vector2f(1 * size, 0));
    shapeTopPartRight.setPoint(1, position + Vector2f(3 * size, 0));
    shapeTopPartRight.setPoint(2, position + Vector2f(3 * size, 1.5 * size));
    shapeTopPartRight.setPoint(3, position + Vector2f(2 * size, 1.5 * size));
    shapeTopPartRight.setPoint(4, position + Vector2f(2 * size, 0.5 * size));
    shapeTopPartRight.setPoint(5, position + Vector2f(1 * size, 0.5 * size));
    shapeTopPartRight.setFillColor(color);

    RectangleShape rectangleBotRight(Vector2f(2 * size, 0.5 * size));
    rectangleBotRight.setPosition(position + Vector2f(size, 3.5 * size));
    rectangleBotRight.setFillColor(color);

    convexShapes.push_back(shapeTopPartRight);
    convexShapes.push_back(shapeTopPartLeft);
    convexShapes.push_back(shapeBotPartRight);
    convexShapes.push_back(shapeBotPartLeft);
    rectangleShapes.push_back(rectangleBotRight);

    return new Letter(startSpeed, convexShapes, rectangleShapes);
}