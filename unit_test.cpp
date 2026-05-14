#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "mano_std_vector.h"
#include "Vector/studentas.h"
#include <iostream>

using std::cout;

TEST_CASE("Tikrinamas studentas be pazymiu") {
    studentas s("Vardas", "Pavarde"); 
    CHECK(s.getEgz() == 0);
    CHECK(s.getPaz().size() == 0);
}

TEST_CASE("Tikrinamas rezultato skaiciavimas") {
    Vector<int> p;
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
    Vector<int> p;
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
TEST_CASE("Vector baziniu metodu testas") {
    Vector<int> v;
    
    SUBCASE("Pradines busenos tikrinimas") {
        CHECK(v.size() == 0);
        CHECK(v.capacity() == 2);
    }
    
    SUBCASE("PushBack ir talpos didejimas") {
        v.push_back(1);
        v.push_back(2);
        CHECK(v.size() == 2);
        CHECK(v.capacity() >= 2);
        CHECK(v[0] == 1);
        CHECK(v[1] == 2);
    }
    
    SUBCASE("PopBack ir Clear") {
        v.PushBack(10);
        v.PopBack();
        CHECK(v.size() == 0);
        
        v.push_back(5);
        v.clear();
        CHECK(v.size() == 0);
    }
}
TEST_CASE("Vector elementu pasiekiamumas") {
    Vector<int> v;
    v.push_back(100);
    v.push_back(200);
    
    CHECK(v[0] == 100);
    v[0] = 500;
    CHECK(v[0] == 500);
}