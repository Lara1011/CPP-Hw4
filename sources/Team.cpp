//
// Created by Lara Abu Hamad on 07/05/2023.
//

#include "Team.hpp"

namespace ariel{
    Team::Team() {
        Character l = Character();
        this->leader = &l;
        //this->add(&l);
    }
    Team::Team(Character *leader) : leader(leader){
        //this->add(this->leader);
    }

    // Copy constructor
    Team::Team(const Team& other) {
    }

// Copy assignment operator
    Team& Team::operator=(const Team& other) noexcept{
        return *this;
    }

    // Move constructor
    Team::Team(Team&& other)  noexcept {
    }

    // Move assignment operator
    Team& Team::operator=(Team&& other)  noexcept {
        return *this;
    }

    Team::~Team() {
        for (Character* member : members) {
            delete member;
        }
    }

    void Team::add(Character *member) {
        //this->members.push_back(member);
    }

    void Team::attack(Team *enemy_team) {
    }

    int Team::stillAlive() {
        return 0;
        //return this->members.size();
    }

    vector<Character*> Team::getMembers() {
        return this->members;
    }

    void Team::print() {}

    Team2::Team2() : Team(){}
    Team2::Team2(Character *leader) : Team(leader){}

    SmartTeam::SmartTeam() : Team(){}
    SmartTeam::SmartTeam(Character *leader) : Team(leader){}
}