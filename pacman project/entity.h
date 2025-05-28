#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Point.h"
#include "Board.h"

class Entity {
private:
    constexpr static int NUM_KEYS = 10;
    char figure;
    char arrowKeys[NUM_KEYS];
    enum class Direction {
        UP_LEFT = 0,
        UP = 1,
        UP_RIGHT = 2,
        LEFT = 3,
        CENTER = 4,
        RIGHT = 5,
        DOWN_LEFT = 6,
        DOWN = 7,
        DOWN_RIGHT = 8,
        INVALID = 9
    };
    Direction direction;
    Point initialPos;
    Point body;

public:
    Entity(int body_x, int body_y, char _figure, Direction _dir) {
        body.setX(body_x);
        body.setY(body_y);
        initialPos.setX(body_x);
        initialPos.setY(body_y);
        figure = _figure;
        setArrowKeys("wWxXaAdDsS");
        direction = _dir;
    }

    void setArrowKeys(const char* keys); // "wWxXaAdDsS"
    Point& getBody();
    Point& getInitialPos();
    char getFigure() const;
    string getArrowKeys() const;
    Direction getCurrentDirection() const;
    void setFigure(const char c);
    void setDirection(Direction dir);
    virtual Direction getDirectionFromKey(char key) const;
    virtual Direction getDirectionFromKey() const;
    virtual void move(char visited) {}
};

#endif
