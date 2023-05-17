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
        leader = new Character(*other.leader); // Deep copy the leader

        for (Character* member : other.members) {
            members.push_back(new Character(*member)); // Deep copy each member
        }
    }

// Copy assignment operator
    Team& Team::operator=(const Team& other) noexcept{
        if (this != &other) {
            // Delete existing members
            for (Character *member: members) {
                delete member;
            }
            members.clear();

            // Copy leader
            delete leader;
            leader = new Character(*other.leader); // Deep copy the leader

            // Copy members
            for (Character *member: other.members) {
                members.push_back(new Character(*member)); // Deep copy each member
            }
        }
        return *this;
    }

    // Move constructor
    Team::Team(Team&& other)  noexcept {
        leader = other.leader;
        members = std::move(other.members);
        other.leader = nullptr;
        other.members.clear();
    }

    // Move assignment operator
    Team& Team::operator=(Team&& other)  noexcept {
        if (this != &other) {
// Delete existing members
            for (Character *member: members) {
                delete member;
            }
            members.clear();
            // Move leader and members
            delete leader;
            leader = other.leader;
            members = std::move(other.members);

            // Reset other object
            other.leader = nullptr;
            other.members.clear();
        }
        return *this;
    }

    Team::~Team() {
        for (Character* member : members) {
            delete &member;
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