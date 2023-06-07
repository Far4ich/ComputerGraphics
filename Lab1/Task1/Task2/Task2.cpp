#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <memory>

using namespace sf;
using namespace std;

class Rocket {
public:
    Rocket()
    {
        CreateTriangleTop();
        CreateBody();
        CreateWings();
        CreateWindows();
    }

    void Draw(RenderWindow& window)
    {
        window.draw(m_triangleTop);
        window.draw(m_body);
        window.draw(m_wingLeft);
        window.draw(m_wingRight);
        window.draw(m_rocketWindow1);
        window.draw(m_rocketWindow2);
    }

    void Jump(Vector2f delta)
    {
        m_triangleTop.move(delta);
        m_body.move(delta);
        m_wingLeft.move(delta);
        m_wingRight.move(delta);
        m_rocketWindow1.move(delta);
        m_rocketWindow2.move(delta);
    }

    bool IsContainPoint(Vector2i point)
    {
        return m_triangleTop.getGlobalBounds().contains((Vector2f)point) ||
            m_body.getGlobalBounds().contains((Vector2f)point) ||
            m_wingLeft.getGlobalBounds().contains((Vector2f)point) ||
            m_wingRight.getGlobalBounds().contains((Vector2f)point) ||
            m_rocketWindow1.getGlobalBounds().contains((Vector2f)point) ||
            m_rocketWindow2.getGlobalBounds().contains((Vector2f)point);
    }

private:
    ConvexShape m_triangleTop;
    RectangleShape m_body;
    ConvexShape m_wingLeft;
    ConvexShape m_wingRight; 
    CircleShape m_rocketWindow1;
    CircleShape m_rocketWindow2;

    void CreateTriangleTop()
    {
        m_triangleTop.setPointCount(3);
        m_triangleTop.setPoint(0, Vector2f(350, 100));
        m_triangleTop.setPoint(1, Vector2f(300, 200));
        m_triangleTop.setPoint(2, Vector2f(400, 200));
        m_triangleTop.setFillColor(Color::Red);
    }

    void CreateBody()
    {
        m_body.setSize(Vector2f(100, 300));
        m_body.setPosition(Vector2f(300, 200));
        m_body.setFillColor(Color::Blue);
    }

    void CreateWings()
    {
        m_wingLeft.setPointCount(4);
        m_wingLeft.setPoint(0, Vector2f(300, 400));
        m_wingLeft.setPoint(1, Vector2f(250, 500));
        m_wingLeft.setPoint(2, Vector2f(250, 600));
        m_wingLeft.setPoint(3, Vector2f(300, 500));
        m_wingLeft.setFillColor(Color::Red);

        m_wingRight.setPointCount(4);
        m_wingRight.setPoint(0, Vector2f(400, 400));
        m_wingRight.setPoint(1, Vector2f(450, 500));
        m_wingRight.setPoint(2, Vector2f(450, 600));
        m_wingRight.setPoint(3, Vector2f(400, 500));
        m_wingRight.setFillColor(Color::Red);
    }

    void CreateWindows()
    {
        m_rocketWindow1.setRadius(30);
        m_rocketWindow1.setPosition(Vector2f(320, 330));
        m_rocketWindow1.setFillColor(Color(230, 230, 230));
        m_rocketWindow1.setOutlineThickness(5);
        m_rocketWindow1.setOutlineColor(Color(100, 100, 100));

        m_rocketWindow2.setRadius(30);
        m_rocketWindow2.setPosition(Vector2f(320, 240));
        m_rocketWindow2.setFillColor(Color(230, 230, 230));
        m_rocketWindow2.setOutlineThickness(5);
        m_rocketWindow2.setOutlineColor(Color(100, 100, 100));
    }
};

int main()
{
    RenderWindow window(VideoMode(800, 600), "Rocket");

    Rocket* rocket = new Rocket();

    Vector2f mouseDeltaPosition;
    bool isMove = false;
    Vector2i mousePosition;
    while (window.isOpen())
    {
        mousePosition = Mouse::getPosition(window);

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.key.code == Mouse::Left)
                {
                    if (rocket->IsContainPoint(mousePosition))
                    {
                        mouseDeltaPosition = (Vector2f)mousePosition;
                        isMove = true;
                    }
                }
            }
            if (event.type == Event::MouseButtonReleased)
                if (event.key.code == Mouse::Left)
                    isMove = false; 
        }

        window.clear(Color::White);

        if (isMove)
        {
            rocket->Jump((Vector2f)mousePosition - mouseDeltaPosition);
            mouseDeltaPosition = (Vector2f)mousePosition;
        }

        rocket->Draw(window);

        window.display();
    }

    return 0;
}
