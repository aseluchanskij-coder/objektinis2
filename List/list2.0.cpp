#include <iostream>
#include <list>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>
#include "studentas.h"
#include "ivedimas_isvedimas.h"
#include "testavimas.h"

using namespace std::chrono;
using std::string;
using std::list;

int main() {
    list<int> kiekiai = {1000, 10000, 100000, 1000000, 10000000};

    for (int kiekis : kiekiai) {
        // Pakeista, kad atitiktų tavo failų vardus: 1000.txt, 10000.txt ir t.t.
        string failas = std::to_string(kiekis) + ".txt";
        list<studentas> pradine_grupe;

        try {
            skaitymas_rez(failas, pradine_grupe);
            if (pradine_grupe.empty()) {
                continue;
            }
        } catch (...) {
            continue;
        }

        std::cout << "\n--- REZULTATAI SU " << kiekis << " IRASU (LIST) ---" << std::endl;

        {
            list<studentas> grupe = pradine_grupe;
            list<studentas> v1, k1;
            auto s = high_resolution_clock::now();
            strategija1(grupe, v1, k1);
            auto e = high_resolution_clock::now();
            std::cout << "1 Strategija: " << std::fixed << std::setprecision(5) << duration<double>(e - s).count() << " s" << std::endl;
        }

        {
            list<studentas> grupe = pradine_grupe;
            list<studentas> v2;
            auto s = high_resolution_clock::now();
            strategija2(grupe, v2);
            auto e = high_resolution_clock::now();
            std::cout << "2 Strategija: " << std::fixed << std::setprecision(5) << duration<double>(e - s).count() << " s" << std::endl;
        }

        {
            list<studentas> grupe = pradine_grupe;
            list<studentas> v3;
            auto s = high_resolution_clock::now();
            strategija3(grupe, v3);
            auto e = high_resolution_clock::now();
            std::cout << "3 Strategija: " << std::fixed << std::setprecision(5) << duration<double>(e - s).count() << " s" << std::endl;
        }
    }

    return 0;
}
