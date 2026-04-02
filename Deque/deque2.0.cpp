#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "studentas.h"
#include "ivedimas_isvedimas.h"
#include "testavimas.h"

using namespace std::chrono;
int main() {

    /*
    std::deque<studentas> grupe;

    auto start = std::chrono::high_resolution_clock::now();

    try {
        input(grupe);

        if (!grupe.empty()) {
            rusiuotistud(grupe);  
        }
    }
    catch (const std::exception &e) {
        std::cout << "Klaida: " << e.what() << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Visos programos veikimo laikas yra: "
              << elapsed.count() << " sekundes\n";
              */
    /*
    std::cout << "1 TYRIMAS – Failu kurimo sparta\n";

    failo_kurimo_testas(1000);
    failo_kurimo_testas(10000);
    failo_kurimo_testas(100000);
    failo_kurimo_testas(1000000);
    failo_kurimo_testas(10000000);
*/
/*
    std::cout << "Testavimas su skirtingo dydzio failais:\n";

    apdorojimo_testas("1000.txt");
    apdorojimo_testas("10000.txt");
    apdorojimo_testas("100000.txt");
    apdorojimo_testas("1000000.txt");
    apdorojimo_testas("10000000.txt");
    */
   deque<int> kiekiai = {1000, 10000, 100000, 1000000, 10000000};

    for (int kiekis : kiekiai) {
        string failas = std::to_string(kiekis) + ".txt";
        deque<studentas> pradine_grupe;

        try {
            skaitymas_rez(failas, pradine_grupe);
        } catch (...) {
            continue;
        }

        std::cout << "\n--- REZULTATAI SU " << kiekis << " IRASU ---" << std::endl;

        {
            std::deque<studentas> grupe = pradine_grupe;
            std::deque<studentas> v1, k1;
            auto s = high_resolution_clock::now();
            strategija1(grupe, v1, k1);
            auto e = high_resolution_clock::now();
            std::cout << "1 Strategija: " << std::fixed << std::setprecision(5) << duration<double>(e - s).count() << " s" << std::endl;
        }

        {
            std::deque<studentas> grupe = pradine_grupe;
            std::deque<studentas> v2;
            auto s = high_resolution_clock::now();
            strategija2(grupe, v2);
            auto e = high_resolution_clock::now();
            std::cout << "2 Strategija: " << std::fixed << std::setprecision(5) << duration<double>(e - s).count() << " s" << std::endl;
        }

        {
            std::deque<studentas> grupe = pradine_grupe;
            std::deque<studentas> v3;
            auto s = high_resolution_clock::now();
            strategija3(grupe, v3);
            auto e = high_resolution_clock::now();
            std::cout << "3 Strategija: " << std::fixed << std::setprecision(5) << duration<double>(e - s).count() << " s" << std::endl;
        }
    }

    return 0;
}
