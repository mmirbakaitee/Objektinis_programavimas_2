#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "vheaderisV.cpp"

TEST_CASE("Vidurkis ir Mediana") {

    SECTION("Vidurkio skaiciavimo tikrinimas") {
        vector<int> p = {5,5,5};
        Student t1;
        t1.setp(p);
        t1.sete(5);
        t1.setgal(aver(t1));
        REQUIRE(t1.getgal() == 5);
    }
    SECTION("Medianos skaiciavimo tikrinimas")
    {
        vector<int> p = {10,10,10};
        Student t2;
        t2.setp(p);
        t2.sete(10);
        t2.setmed(medi(t2));
        REQUIRE(t2.getmed() == 10);
    }
    SECTION("Medianos skaiciavimas, kai egzamino pazymys neigiamas")
    {
        Student t3;
        vector<int> p = {10,10,10};
        t3.setp(p);
        t3.sete(-10);
        t3.setmed(medi(t3));
        REQUIRE(t3.getmed() == 4);
    }
}