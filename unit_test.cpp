#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <vector>
#include "Vector/studentas.h"
#include <iostream>

using std::cout;

TEST_CASE("Tikrinamas studentas be pazymiu") {
    studentas s("Vardas", "Pavarde"); 
    CHECK(s.getEgz() == 0);
    CHECK(s.getPaz().size() == 0);
}

TEST_CASE("Tikrinamas rezultato skaiciavimas") {
    std::vector<int> p;
    p.push_back(10);
    p.push_back(8);
    p.push_back(9);
    p.push_back(7);
    p.push_back(6);
    int egz = 10;
    
    studentas s("Test", "Logika", p, egz);
    
    double rezultatas = s.getRez(); 
    CHECK(rezultatas == doctest::Approx(9.2)); 
}

TEST_CASE("Studento klases Rule of Five testas") {
    std::vector<int> p;
    p.push_back(10);
    studentas s1("Jonas", "Jonaitis", p, 10);
    
    std::string originalusVardas = s1.getVardas();
    double originalusEgz = s1.getEgz();

    SUBCASE("Copy Constructor") {
        studentas s2(s1); 
        CHECK(s2.getVardas() == s1.getVardas());
        CHECK(s2.getEgz() == s1.getEgz());
    }

    SUBCASE("Copy Assignment") {
        studentas s3;
        s3 = s1; 
        CHECK(s3.getVardas() == s1.getVardas());
        CHECK(s3.getEgz() == s1.getEgz());
    }

    SUBCASE("Move Constructor") {
        studentas s4(std::move(s1)); 
        CHECK(s4.getVardas() == originalusVardas);
        CHECK(s4.getEgz() == originalusEgz);
    }

    SUBCASE("Move Assignment") {
        studentas s2_temp("Pakeistas", "Pakeistas", p, 5);
        studentas s5;
        s5 = std::move(s2_temp); 
        CHECK(s5.getVardas() == "Pakeistas");
        CHECK(s5.getEgz() == 5);
    }
}
