//
// Created by Lara Abu Hamad on 07/05/2023.
//

#include "Team.hpp"

namespace ariel{
    Team::Team() {
        Character ch = Character();
        this->leader = &ch;
    }
    Team::Team(Character *leader) : leader(leader) {
        members.push_back(leader);
    }


    Team::~Team() {
        for (Character* member : members) {
            delete member;
        }
    }


    void Team::add(Character *fighter) {
        members.push_back(fighter);
    }

    void Team::attack(Team *enemyTeam) {
    }

    int Team::stillAlive() {
        return 0;
    }

    void Team::print() {
    }

    Team2::Team2() : Team(){}
    Team2::Team2(Character *leader) : Team(leader){}

    SmartTeam::SmartTeam() : Team(){}
    SmartTeam::SmartTeam(Character *leader) : Team(leader){}
}