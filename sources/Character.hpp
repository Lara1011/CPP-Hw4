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
    double distance(Character& other);
    void hit(int points);
    string getName();
    Point getLocation();
    void print();
};

    class Cowboy : public Character{
    protected:
        int bullets;

    public:
        Cowboy();
        Cowboy(string name, Point location);
        Cowboy(string name, Point location, int points, int bults);
        void shoot(Character* other);
        bool hasboolets();
        void reload();
        string print();

    };

    class Ninja : public Character{
    protected:
        int speed;

    public:
        Ninja();
        Ninja(string name, Point location);
        Ninja(Point location, string name, int points, int speed);
        void move(Character* other);
        void slash(Character* other);
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
