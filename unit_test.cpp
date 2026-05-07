#include <iostream>
#include <cassert>
#include <vector>
#include "Vector/studentas.h"
using std::cout;
void testuoti_rule_of_five() {
                cout << "\n1 Ivedimo operatorius" << std::endl;
                studentas s1;
                std::cin >> s1;
                std::string originalusVardas = s1.getVardas();
                double originalusEgz = s1.getEgz();

                cout << "\n2 Copy Constructor: " << std::endl;
                studentas s2(s1); 
                assert(s2.getVardas() == s1.getVardas());
                assert(s2.getEgz() == s1.getEgz());
                cout << "s2 (s1 kopija): " << s2 << std::endl;

                cout << "\n3 Copy Assignment" << std::endl;
                studentas s3;
                s3 = s2; 
                assert(s3.getVardas() == s2.getVardas());
                assert(s3.getEgz() == s2.getEgz());
                cout << "s3 priskirtas is s2: " << s3 << std::endl;

                cout << "\n4 Move Constructor: " << std::endl;
                studentas s4(std::move(s1)); 
                assert(s4.getVardas() == originalusVardas);
                assert(s4.getEgz() == originalusEgz);
                cout << "s4 perkeltas is s1: " << s4 << std::endl;
                cout << "s1 po perkelimo: [" << s1.getVardas() << "] egz: " << s1.getEgz() << std::endl;

                cout << "\n5 Move Assigment:" << std::endl;
                studentas s5;
                s5 = std::move(s2); 
                assert(s5.getVardas() == originalusVardas);
                assert(s5.getEgz() == originalusEgz);
                cout << "s5 perkeltas is s2: " << s5 << std::endl;
                cout << "s2 po perkelimo: [" << s2.getVardas() << "] egz: " << s2.getEgz() << std::endl;

                cout << "\n6 Isvedimo operatorius: " << std::endl;
                cout << "s5 objektas: " << s5 << std::endl;
                
                cout << "\nVISI ASSERT TESTAI PRAEITI SEKMINGAI!" << std::endl;
}      
void test_be_paz() {
    cout << "Tikrinamas studentas be pazymiu:" << std::endl;
    
    studentas s("Vardas", "Pavarde"); 
    
    
    assert(s.getEgz() == 0); 
    
    cout << "Studentas be pazymiu apdorotas." << std::endl;
}
void test_skaiciavimas() {
    cout << "Tikrinamas rezultato skaiciavimas: " << std::endl;
    
    std::vector<int> p = {10, 8, 9, 7, 6}; 
    int egz = 10;
    
    studentas s("Test", "Logika", p, egz);
    
    double rezultatas = s.getRez(); 
    assert(rezultatas > 9.19 && rezultatas < 9.21);
    
    cout << "Skaiciavimo logika teisinga." << std::endl;
}

int main() {
    try {
        cout << "Testavimas\n";
        test_be_paz();
        test_skaiciavimas();
        cout << "---------------------------------------\n\n";

        testuoti_rule_of_five();

        cout << "\nPenkiu taisykle veikia" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Klaida testavimo metu: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}