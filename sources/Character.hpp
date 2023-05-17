//
// Created by Lara Abu Hamad on 07/05/2023.
//

#ifndef CPP_HW4_CHARACTER_HPP
#define CPP_HW4_CHARACTER_HPP


#include "Point.hpp"

namespace ariel{
class Character {
private:
    string name;
    Point location;
    int hitPoints;

public:
    Character();
    Character(string name, Point location, int points);
    bool isAlive();
    double distance(Character* other);
    void hit(int points);
    string getName();
    Point getLocation();
    int getHitPoints();
    void print();
};

    class Cowboy : public Character{
    private:
        int bullets;

    public:
        Cowboy();
        Cowboy(string name, Point location);
        void shoot(Character* other);
        bool hasboolets();
        void reload();
        int getBullets();
        string print();

    };

    class Ninja : public Character{
    private:
        int speed;

    public:
        Ninja();
        Ninja(string name, Point location);
        Ninja(string name, Point location, int points, int speed);
        void move(Character* other);
        void slash(Character* other);
        int getSpeed();
        string print();
    };

    class YoungNinja : public Ninja{
    public:
        YoungNinja(Point location);
        YoungNinja(string name, Point location);
    };

    class TrainedNinja : public Ninja{
    public:
        TrainedNinja(Point location);
        TrainedNinja(string name, Point location);
    };

    class OldNinja : public Ninja{
    public:
        OldNinja(Point location);
        OldNinja(string name, Point location);
    };
}

#endif //CPP_HW4_CHARACTER_HPP
