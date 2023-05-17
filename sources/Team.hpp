//
// Created by Lara Abu Hamad on 07/05/2023.
//

#ifndef CPP_HW4_TEAM_HPP
#define CPP_HW4_TEAM_HPP
#include "Point.hpp"
#include "Character.hpp"
#include <vector>

using namespace std;
namespace ariel {
    class Team {
    private:
        Character* leader;
        vector<Character*> members;
    public:
        Team();
        Team(Character* leader);
        Team(const Team& other); // Copy constructor
        Team& operator=(const Team& other) noexcept; // Copy assignment operator
        Team(Team&& other) noexcept; // Move constructor
        Team& operator=(Team&& other) noexcept; // Move assignment operator
        ~Team();
        void add(Character* member);
        void attack(Team* enemy_team);
        int stillAlive();
        vector<Character*> getMembers();
        void print();
    };

    class Team2 : public Team {
    public:
        Team2();
        Team2(Character* leader);
    };

    class SmartTeam : public Team {
    public:
        SmartTeam();
        SmartTeam(Character* leader);
    };
}

#endif //CPP_HW4_TEAM_HPP
