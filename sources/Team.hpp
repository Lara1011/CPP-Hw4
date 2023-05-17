//
// Created by Lara Abu Hamad on 07/05/2023.
//

#ifndef COWBOY_VS_NINJA_A_TEAM_HPP
#define COWBOY_VS_NINJA_A_TEAM_HPP

#include <vector>
#include "Character.hpp"


using namespace std;
namespace ariel {
    class Team {
    private:
        Character *leader;
        vector<Character *> members;
    public:
        Team();

        Team(Character *leader);

        void add(Character *fighter);

        void attack(Team *enemyTeam);

        int stillAlive();

        void print();

        ~Team();

        Team (Team&) = delete; // Copy Constructor.
        Team (Team&&) noexcept = delete; // Move Constructor.
        Team& operator = (const Team&) = delete; // Copy assignment operator.
        Team& operator = (Team&&) noexcept = delete; // Move assignment operator.
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
