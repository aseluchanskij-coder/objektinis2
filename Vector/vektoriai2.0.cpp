#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "studentas.h"
#include "ivedimas_isvedimas.h"
#include "testavimas.h"

using namespace std::chrono;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
int main() {
    vector<studentas> grupe;
    int pasirinkimas;

    do {
        cout << "\n========= Programos paleidimas =========\n";
        cout << "1 - Pradine programa\n";
        cout << "2 - Rule of Five ir Operatoriu testas\n";
        cout << "3 - Generuoti testo failus, 1000 - 10 mln. irasu)\n";
        cout << "4 - Apdorojimo testas\n";
        cout << "5 - Strategiju lyginimas \n";
        cout << "0 - Baigti programa\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                try {
                    input(grupe);
                    if (!grupe.empty()) {
                        sort(grupe.begin(), grupe.end(), pagalRez);
                        output(cout, grupe);
                    }
                } catch (const std::exception &e) {
                    cout << "Klaida: " << e.what() << endl;
                }   
                break;

            case 2: {
                studentas s1;
                cout << "Iveskite studenta:\n";
                cin >> s1;
                
                studentas s2 (s1); // Copy constructor
                studentas s3 (std::move(s1)); // Mov
                
                cout << "Stud3 (perkeltas is S1): " << s3 << endl;
                cout << "Stud2 (kopija): " << s2 << endl;
                break;
            }//visus penkis rules tikrint reik. 
//operatorius isvedimo ivedimo panaudot
            case 3:
                cout << "Generuojami failai...\n";
                failo_kurimo_testas(1000);
                failo_kurimo_testas(10000);
                failo_kurimo_testas(100000);
                break;

            case 4:
                apdorojimo_testas("1000.txt");
                apdorojimo_testas("10000.txt");
                break;

            case 5: {
    vector<int> kiekiai = {1000000, 10000000};

    for (int kiekis : kiekiai) {
        string failas = std::to_string(kiekis) + ".txt";
        vector<studentas> pradine_grupe;

        try {
            skaitymas_rez(failas, pradine_grupe);
        } catch (...) {
            cout << "Nepavyko nuskaityti failo: " << failas << endl;
            continue;
        }

        std::cout << "\n--- REZULTATAI SU " << kiekis << " IRASU ---" << std::endl;

        {
            vector<studentas> grupe = pradine_grupe;
            vector<studentas> v1, k1;
            auto s = high_resolution_clock::now();
            strategija1(grupe, v1, k1);
            auto e = high_resolution_clock::now();
            std::cout << "1 Strategija: " << std::fixed << std::setprecision(5) << duration<double>(e - s).count() << " s" << std::endl;
        }

        {
            vector<studentas> grupe = pradine_grupe;
            vector<studentas> v2;
            auto s = high_resolution_clock::now();
            strategija2(grupe, v2);
            auto e = high_resolution_clock::now();
            std::cout << "2 Strategija: " << std::fixed << std::setprecision(5) << duration<double>(e - s).count() << " s" << std::endl;
        }

        {
            vector<studentas> grupe = pradine_grupe;
            vector<studentas> v3;
            auto s = high_resolution_clock::now();
            strategija3(grupe, v3);
            auto e = high_resolution_clock::now();
            std::cout << "3 Strategija: " << std::fixed << std::setprecision(5) << duration<double>(e - s).count() << " s" << std::endl;
        }
    }
    break;
}

            case 0:
                cout << "Programa baigiama.\n";
                break;

            default:
                cout << "Blogas pasirinkimas, bandykite dar karta.\n";
        }
    } while (pasirinkimas != 0);

    return 0;
}
/*
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "studentas.h"
#include "ivedimas_isvedimas.h"
#include "testavimas.h"

using namespace std::chrono;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {
    vector<studentas> grupe;

    auto start = high_resolution_clock::now();

    try {
        input(grupe);

        if (!grupe.empty()) {
            cout << "\nPagal ka rusiuoti?\n1 - Varda\n2 - Pavarde\n3 - Rezultata\nPasirinkimas: ";
            int r_pasirinkimas;
            cin >> r_pasirinkimas;

            if (r_pasirinkimas == 1) std::sort(grupe.begin(), grupe.end(), pagalVarda);
            else if (r_pasirinkimas == 2) std::sort(grupe.begin(), grupe.end(), pagalPavarde);
            else std::sort(grupe.begin(), grupe.end(), pagalRez);

            cout << "\nKur isvesti rezultatus?\n1 - I konsole\n2 - I faila (rezultatai.txt)\n3 - Padalinti i dvi grupes (vargsai.txt ir kietuoliai.txt)\nPasirinkimas: ";
            int i_pasirinkimas;
            cin >> i_pasirinkimas;

            if (i_pasirinkimas == 1) {
                output(cout, grupe);
            } 
            else if (i_pasirinkimas == 2) {
                std::ofstream f("rezultatai.txt");
                output(f, grupe);
                f.close();
                cout << "Duomenys surasyti i rezultatai.txt" << endl;
            }
            else if (i_pasirinkimas == 3) {
                vector<studentas> vargsai, kietuoliai;
                padalinti_studentus(grupe, vargsai, kietuoliai);
                
                std::ofstream f1("vargsai.txt"), f2("kietuoliai.txt");
                output(f1, vargsai);
                output(f2, kietuoliai);
                f1.close(); f2.close();
                cout << "Studentai padalinti i vargsai.txt ir kietuoliai.txt" << endl;
            }
        }
    }
    catch (const std::exception &e) {
        cout << "Klaida: " << e.what() << endl;
    }

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    cout << "\nVisos programos veikimo laikas yra: " << elapsed.count() << " sekundes" << endl;
    
    std::cout << "1 TYRIMAS – Failu kurimo sparta\n";

    failo_kurimo_testas(1000);
    failo_kurimo_testas(10000);
    failo_kurimo_testas(100000);
    failo_kurimo_testas(1000000);
    failo_kurimo_testas(10000000);

    std::cout << "Testavimas su skirtingo dydzio failais:\n";

    apdorojimo_testas("1000.txt");
    apdorojimo_testas("10000.txt");
    apdorojimo_testas("100000.txt");
    apdorojimo_testas("1000000.txt");
    apdorojimo_testas("10000000.txt");
    
   vector<int> kiekiai = {1000000, 10000000};

    for (int kiekis : kiekiai) {
        string failas = std::to_string(kiekis) + ".txt";
        vector<studentas> pradine_grupe;

        try {
            skaitymas_rez(failas, pradine_grupe);
        } catch (...) {
            continue;
        }

        std::cout << "\n--- REZULTATAI SU " << kiekis << " IRASU ---" << std::endl;

        {
            vector<studentas> grupe = pradine_grupe;
            vector<studentas> v1, k1;
            auto s = high_resolution_clock::now();
            strategija1(grupe, v1, k1);
            auto e = high_resolution_clock::now();
            std::cout << "1 Strategija: " << std::fixed << std::setprecision(5) << duration<double>(e - s).count() << " s" << std::endl;
        }
        
        {
            vector<studentas> grupe = pradine_grupe;
            vector<studentas> v2;
            auto s = high_resolution_clock::now();
            strategija2(grupe, v2);
            auto e = high_resolution_clock::now();
            std::cout << "2 Strategija: " << std::fixed << std::setprecision(5) << duration<double>(e - s).count() << " s" << std::endl;
        }
        

        {
            vector<studentas> grupe = pradine_grupe;
            vector<studentas> v3;
            auto s = high_resolution_clock::now();
            strategija3(grupe, v3);
            auto e = high_resolution_clock::now();
            std::cout << "3 Strategija: " << std::fixed << std::setprecision(5) << duration<double>(e - s).count() << " s" << std::endl;
        }
            
    }

    return 0;
}
*/
