#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Letter
{
public:
    Letter(float startSpeed, vector<ConvexShape> convexShapes, vector<RectangleShape> rectangleShapes)
    {
        m_startSpeed = startSpeed;
        m_startPos = convexShapes[0].getPosition();
        m_convexShapes = convexShapes;
        m_rectangleShapes = rectangleShapes;
    }

    void Draw(RenderWindow& window)
    {
        for (auto shape : m_convexShapes)
        {
            window.draw(shape);
        }
        for (auto shape : m_rectangleShapes)
        {
            window.draw(shape);
        }
    }

    void Jump(float time)
    {
        float speed = 0;
        if (isToTop)
        {
            speed = m_startSpeed * (time - lastJumpTime) + (6 * (time - lastJumpTime) * (time - lastJumpTime)) / 2;
            if (speed > 0)
            {
                isToTop = false;
            }
        }
        else
        {
            if (m_startPos.y <= m_convexShapes[0].getPosition().y)
            {
                speed = m_convexShapes[0].getPosition().y - m_startPos.y;
                lastJumpTime = time;
                isToTop = true;
            }
            else
            {
                speed = m_startSpeed * (time - lastJumpTime) + (6 * (time - lastJumpTime) * (time - lastJumpTime)) / 2;
            }
        }

        Vector2f delta(0, speed);
        for (auto& shape : m_convexShapes)
        {
            shape.move(delta);
        }
        for (auto& shape : m_rectangleShapes)
        {
            shape.move(delta);
        }
    }
private:
    bool isToTop = true;
    float lastJumpTime = 0;
    float m_startSpeed;
    Vector2f m_startPos;
    vector<ConvexShape> m_convexShapes;
    vector<RectangleShape> m_rectangleShapes;
}; 