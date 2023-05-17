//
// Created by Lara Abu Hamad on 15/05/2023.
//

#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Team.hpp"
#include "sources/Point.hpp"
#include <sstream>
#include <cmath>

using namespace std;
using namespace ariel;

TEST_SUITE("Initialization") {
    TEST_CASE("Initializing Point") {
        CHECK_NOTHROW(Point p1{});
        CHECK_NOTHROW(Point p2{});
        CHECK_NOTHROW(Point p3{});
        CHECK_NOTHROW(Point p4{});
        CHECK_NOTHROW(Point p5{});
        CHECK_NOTHROW(Point p6{0, 0});
        CHECK_NOTHROW(Point p7{1.33, 2.1});
        CHECK_NOTHROW(Point p8{20, 17});
        CHECK_NOTHROW(Point p9{4, 11.45});
        CHECK_NOTHROW(Point p10{5.5, 5});
    }

    TEST_CASE("Initializing Character - Cowboy/Ninja"){
        //Character
        CHECK_NOTHROW(Character ch1{});
        CHECK_NOTHROW(Character ch2{"Bob", Point(), 4});

        Character ch {};
        CHECK(ch.getName() == "lara");
        CHECK(ch.getLocation().getX() == 0);
        CHECK(ch.getLocation().getY() == 0);
        CHECK(ch.getHitPoints() == 0);

        Character ch3 {"Bob", Point(1,1), 4};
        CHECK(ch3.getName() == "Bob");
        CHECK(ch3.getLocation().getX() == 1);
        CHECK(ch3.getLocation().getY() == 1);
        CHECK(ch3.getHitPoints() == 4);

        //Cowboy
        CHECK_NOTHROW(Cowboy cb{});
        CHECK_NOTHROW(Cowboy cb1{"Bob", Point()});

        Cowboy cb2 {};
        CHECK(cb2.getName() == "lara");
        CHECK(cb2.getHitPoints() == 110);
        CHECK(cb2.getBullets() == 6);

        Cowboy cb3 {"Bob", Point()};
        CHECK(cb3.getName() == "Bob");
        CHECK(cb3.getHitPoints() == 110);
        CHECK(cb3.getBullets() == 6);

        //Ninja
        CHECK_NOTHROW(Ninja n1{});
        CHECK_NOTHROW(Ninja n2{"Bob", Point()});
        CHECK_NOTHROW(Ninja n3{"Bob", Point(), 100, 10});
        CHECK_NOTHROW(YoungNinja yn1{Point()});
        CHECK_NOTHROW(YoungNinja yn2{"Bob", Point()});
        CHECK_NOTHROW(TrainedNinja tn1{Point()});
        CHECK_NOTHROW(TrainedNinja tn2{"Bob", Point()});
        CHECK_NOTHROW(OldNinja on1{Point()});
        CHECK_NOTHROW(OldNinja on2{"Bob", Point()});

        Ninja n {};
        CHECK(n.getSpeed() == 4);
        CHECK(n.getName() == "lara");

        YoungNinja yn3 {"Bob", Point()};
        CHECK(yn3.getSpeed() == 14);
        CHECK(yn3.getHitPoints() == 100);

        TrainedNinja tn3 {"Bob", Point()};
        CHECK(tn3.getSpeed() == 12);
        CHECK(tn3.getHitPoints() == 120);

        OldNinja on3 {"Bob", Point()};
        CHECK(on3.getSpeed() == 8);
        CHECK(on3.getHitPoints() == 150);
    }

    TEST_CASE("Initializing Team"){
        CHECK_NOTHROW(Team t1 {});
        CHECK_NOTHROW(Team2 t21 {});
        CHECK_NOTHROW(SmartTeam st1 {});

        Cowboy lc {"Bob", Point()};
        Team t2 {&lc};
        CHECK(t2.stillAlive() == 0);

        YoungNinja yn {"Bob", Point()};
        SmartTeam st {&yn};
        CHECK(st.stillAlive() == 0);
    }
}

TEST_SUITE("Point functions"){
    Point p1 {1, 1};
    Point p2 {3.5, 6.5};

    TEST_CASE("Getters"){
        CHECK(p1.getX() == 1);
        CHECK(p2.getX() == 3.5);
        CHECK(p1.getY() == 1);
        CHECK(p2.getY() == 6.5);
    }

    TEST_CASE("Distance"){
        CHECK(p1.distance(p2) == sqrt(36.5));
    }

    TEST_CASE("moveTowards"){
        Point p3 = Point::moveTowards(p1, p2, sqrt(36.5));
        CHECK(p3.getX() == 1);
        CHECK(p3.getY() == 1);
    }

    TEST_CASE("Print"){
        stringstream output;
        streambuf* oldCoutStreamBuf = cout.rdbuf(output.rdbuf());
        p2.print();
        cout.rdbuf(oldCoutStreamBuf);
        string printedOutput = output.str();
        REQUIRE(printedOutput == "(3.5,6.5)\n");
    }
}

TEST_SUITE("Character functions"){
    Character ch {"Bob", Point(1,1), 4};

    TEST_CASE("Getters"){
        CHECK(ch.getName() == "Bob");
        CHECK(ch.getHitPoints() == 4);
        CHECK(ch.getLocation().getX() == ch.getLocation().getY());
    }

    TEST_CASE("Distance"){
        Character ch1 {"Tom", Point(3.5,6.5), 8};
        CHECK(ch.distance(&ch1) == 1.0);
    }

    TEST_CASE("Print"){
        stringstream output;
        streambuf* oldCoutStreamBuf = cout.rdbuf(output.rdbuf());
        ch.print();
        cout.rdbuf(oldCoutStreamBuf);
        string printedOutput = output.str();
        REQUIRE(printedOutput == "");
    }

    TEST_CASE("isAlive"){
        CHECK_FALSE(ch.isAlive());
    }

    TEST_CASE("void functions"){
        CHECK_NOTHROW(ch.hit(6));
    }
}

TEST_SUITE("Cowboy functions"){
    Cowboy cw {"Bob", Point()};

    TEST_CASE("hasboolets"){
        CHECK_FALSE(!cw.hasboolets());
    }

    TEST_CASE("getBullets"){
        CHECK(cw.getBullets() == 6);
    }

    TEST_CASE("print"){
        CHECK(cw.print() == "C- Bob, Hit points: 110, Location: (0,0)");
    }

    TEST_CASE("void functions"){
        Ninja n{"Bob", Point(), 100, 10};
        CHECK_NOTHROW(cw.shoot(&n));
        CHECK_NOTHROW(cw.reload());
    }
}

TEST_SUITE("Ninja functions"){
    Ninja n{"Bob", Point(), 100, 10};

    TEST_CASE("Getters"){
        CHECK(n.getSpeed() == 10);
    }

    TEST_CASE("void functions"){
        Ninja n1{"Tom", Point(), 100, 10};
        CHECK_NOTHROW(n.slash(&n1));
        CHECK_NOTHROW(n.move(&n1));
    }

    TEST_CASE("print"){
        stringstream output;
        streambuf* oldCoutStreamBuf = cout.rdbuf(output.rdbuf());
        n.print();
        cout.rdbuf(oldCoutStreamBuf);
        string printedOutput = output.str();
        REQUIRE(printedOutput == "N- Bob, Hit points: 100, Location: (0,0)");
    }
}

TEST_SUITE("Team Functions"){
    YoungNinja yn{"Bob", Point()};
    TrainedNinja tn{"Bob", Point()};
    OldNinja on{"Bob", Point()};
    Team t1{&yn};

    TEST_CASE("add"){
        CHECK_NOTHROW(t1.add(&yn));
    }

    TEST_CASE("still alive"){
        t1.add(&yn);
        t1.add(&tn);
        t1.add(&on);
        CHECK(t1.stillAlive() == 4);
    }

    Cowboy cw{"Bob", Point()};
    Team2 t2{&cw};

    TEST_CASE("attack"){
        CHECK_NOTHROW(t1.attack(&t2));
    }

    TEST_CASE("print"){
        CHECK_NOTHROW(t1.print());
    }

    TEST_CASE("Throw an error when trying to add a Character whose already a member of the team"){
        t1.add(&yn);
        CHECK_THROWS(t1.add(&yn));
    }

    TEST_CASE("get an error when trying to add more than 10 members to a team"){
        Cowboy cw1{"Yan", Point()};
        YoungNinja yn1{"Yin", Point()};
        TrainedNinja tn1{"Yon", Point()};
        OldNinja on1{"Tom", Point()};
        Cowboy cw2{"Lily", Point()};
        YoungNinja yn2{"Lara", Point()};
        TrainedNinja tn2{"Lizy", Point()};
        Team2 t3{&cw};
        t3.add(&cw);
        t3.add(&yn);
        t3.add(&tn);
        t3.add(&on);
        t3.add(&yn1);
        t3.add(&tn1);
        t3.add(&on1);
        t3.add(&cw1);
        t3.add(&yn2);
        t3.add(&tn2);
        CHECK_THROWS(t2.add(&cw2));
    }
}