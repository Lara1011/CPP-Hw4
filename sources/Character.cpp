//
// Created by Lara Abu Hamad on 07/05/2023.
//

#include "Character.hpp"

namespace ariel{
    Character::Character() : name("lara"), location(Point()), hitPoints(0){}
    Character::Character(string name, Point location, int points) : name(name), location(location), hitPoints(points){}

    double Character::distance(Character *other) {
        return 1.0;
    }

    string Character::getName() {
        return this->name;
    }

    Point Character::getLocation() {
        return this->location;
    }

    int Character::getHitPoints(){
        return this->hitPoints;
    }

    bool Character::isAlive() {
        return false;
    }

    void Character::hit(int points) {}

    void Character::print() {
//        cout << this->getName() + ", hit points: " + to_string(this->getHitPoints()) << ", location: ";
//        this->getLocation().print();
//        cout << endl;
    }

    Cowboy::Cowboy() : bullets(6), Character("lara", Point(), 110){}
    Cowboy::Cowboy(string name, Point location) : bullets(6), Character(name, location, 110){}

    int Cowboy::getBullets() {
        return this->bullets;
    }
    string Cowboy::print() {
        cout << "C- " + this->getName() + ", Hit points: " + to_string(this->getHitPoints()) + ", Location: ";
        this->getLocation().print();
        return "";
    }

    void Cowboy::reload() {}
    void Cowboy::shoot(Character *other) {}
    bool Cowboy::hasboolets() {
        return true;
    }

    Ninja::Ninja() : speed(4), Character(){}
    Ninja::Ninja(string name, Point location) : speed(4), Character(name, location, 0){}
    Ninja::Ninja(string name, Point location, int points, int speed) : speed(speed), Character(name, location, points){}

    void Ninja::move(Character *other) {}

    void Ninja::slash(Character *other) {}

    int Ninja::getSpeed() {
        return this->speed;
    }

    string Ninja::print() {
        return "";
        //return "N- " + this->getName() + ", Hit points: " + to_string(this->getHitPoints()) + ", Location: (" + to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getX()) +")\n";
    }


    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location, 100, 14){}
    YoungNinja::YoungNinja(Point location) : Ninja("lara", location, 100, 14){}

    TrainedNinja::TrainedNinja(Point location) :Ninja("lara", location, 120, 12){}
    TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location, 120, 12){}

    OldNinja::OldNinja(Point location) : Ninja("lara", location, 150, 8){}
    OldNinja::OldNinja(string name, Point location) : Ninja(name, location, 150, 8){}
}