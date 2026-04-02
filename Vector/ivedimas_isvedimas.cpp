#include "ivedimas_isvedimas.h"
#include "studentas.h"
#include "pagalbines.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::left;
using std::setw;
using std::endl;
using std::fixed;
using std::setprecision;
using std::sort;

void skaitymas(const string &failo_pav, vector<studentas> &grupe) {
    std::ifstream failas("duomenys/" + failo_pav);
    if (!failas) {
        throw std::runtime_error("Nepavyko atidaryti failo!");
    }

    grupe.clear();

    string tipas;
    cout << "Skaiciuoti su vidurkiu (vid) ar mediana (med)? ";
    cin >> tipas;
    while (tipas != "vid" && tipas != "med") {
        cout << "Klaida! Pasirinkite 'vid' arba 'med': ";
        cin >> tipas;
    }

    string line;
    while (getline(failas, line)) {
        std::stringstream fs(line);
        studentas A;
        int x, sum = 0;

        string v, p;
        fs >> v >> p;
        A.setVardas(v);
        A.setPavarde(p);

        vector<int> temp;
        while (fs >> x) temp.push_back(x);

        if (temp.size() < 2) continue;

        A.setEgz(temp.back());
        temp.pop_back();

        for (int paz : temp) {
            A.pridetiPazymi(paz);
            sum += paz;
        }

        A.setTipas(tipas);
        A.skaiciuoti(sum);
        grupe.push_back(A);
    }

    failas.close();
    cout << "Duomenys nuskaityti is failo!\n";
}

void skaitymas_rez(const string &failo_pav, vector<studentas> &grupe) {
    std::ifstream failas("duomenys/" + failo_pav);
    if (!failas) {
        throw std::runtime_error("Nepavyko atidaryti failo!");
    }

    grupe.clear();

    string line;
    getline(failas, line);
    getline(failas, line);

    while (getline(failas, line)) {
        std::stringstream fs(line);
        studentas A;

        string v, p;
        double r;

        fs >> v >> p >> r;

        A.setVardas(v);
        A.setPavarde(p);
        A.setRez(r);
        A.setTipas("vid");

        grupe.push_back(A);
    }

    cout << "Rezultatai nuskaityti is failo!\n";
}

void input(vector<studentas> &grupe) {
    while (true) {
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti viska, 4 - nuskaityti is failo,\n5 - nuskaityti sugeneruota faila, 6 - baigti: ";
        int menu = skaiciaus_nusk();

        if (menu == 6) break;

        if (menu == 4) {
            skaitymas("duomenys/kursiokai.txt", grupe);
            continue;
        }

        if (menu == 5) {
            string failo_pav;

            cout << "Iveskite rezultatu failo pavadinima: ";
            cin >> failo_pav;

            try {
                skaitymas_rez(failo_pav, grupe);
            }
            catch (const std::exception &e) {
                cout << "Klaida: " << e.what() << endl;
            }

            continue;
        }

        if (menu == 3) {
            cout << "Kiek studentu generuoti? ";
            int kiek_stud = skaiciaus_nusk();

            string bendras_tipas;
            cout << "Skaiciuoti su vidurkiu (vid) ar mediana (med)? ";
            cin >> bendras_tipas;
            while (bendras_tipas != "vid" && bendras_tipas != "med") {
                cout << "Klaida! Pasirinkite 'vid' arba 'med': ";
                cin >> bendras_tipas;
            }

            cin.ignore(10000, '\n');

            for (int k = 0; k < kiek_stud; k++) {
                studentas A;
                int sum = 0;

                A.setVardas(random_vardas());
                A.setPavarde(random_pavarde());

                int kiek = rand() % 5 + 3;
                for (int i = 0; i < kiek; i++) {
                    int r = random_paz();
                    A.pridetiPazymi(r);
                    sum += r;
                }

                A.setEgz(random_paz());
                A.setTipas(bendras_tipas);

                A.skaiciuoti(sum);
                grupe.push_back(A);
            }
            continue;
        }

        studentas A;
        int sum = 0;

        if (menu == 1 || menu == 2) {
            string v;
            cout << "Iveskite studento varda (arba 0): ";
            cin >> v;
            if (v == "0") break;

            while (!string_nusk(v)) {
                cout << "Klaida! Vardas negali buti skaicius: ";
                cin >> v;
            }
            A.setVardas(v);

            string p;
            cout << "Iveskite studento pavarde: ";
            cin >> p;

            while (!string_nusk(p)) {
                cout << "Klaida! Pavarde negali buti skaicius: ";
                cin >> p;
            }
            A.setPavarde(p);
        }

        if (menu == 1) {
            cout << "Iveskite pazymius (0 - baigti): ";
            int temp;

            while (true) {
                temp = skaiciaus_nusk();
                if (temp == 0) break;
                if (temp < 1 || temp > 10) continue;

                A.pridetiPazymi(temp);
                sum += temp;
            }

            cout << "Iveskite egzamino bala: ";
            A.setEgz(skaiciaus_nusk());
        }

        if (menu == 2) {
            int kiek = rand() % 5 + 3;
            for (int i = 0; i < kiek; i++) {
                int r = random_paz();
                A.pridetiPazymi(r);
                sum += r;
            }
            A.setEgz(random_paz());
        }

        string t;
        cout << "Skaiciuoti su vidurkiu (vid) ar mediana (med)? ";
        cin >> t;

        while (t != "vid" && t != "med") {
            cout << "Klaida! Pasirinkite 'vid' arba 'med': ";
            cin >> t;
        }

        cin.ignore(10000, '\n');

        A.setTipas(t);
        A.skaiciuoti(sum);
        grupe.push_back(A);
    }
}

void padalinti_studentus(const std::vector<studentas> &grupe,
                         std::vector<studentas> &vargsai,
                         std::vector<studentas> &kietuoliai) {
    for (const auto &A : grupe) {
        if (A.getRez() < 5.0)
            vargsai.push_back(A);
        else
            kietuoliai.push_back(A);
    }
}

void output(std::ostream &out, const std::vector<studentas> &grupe) {
    out << left << setw(20) << "Vardas"
        << left << setw(25) << "Pavarde"
        << setw(20) << "Galutinis(vid.)"
        << setw(20) << "Galutinis(med.)" << endl;

    out << "----------------------------------------------------------------------------" << endl;

    for (const auto &A : grupe) {
        out << left << setw(20) << A.getVardas()
            << left << setw(25) << A.getPavarde();

        if (A.getTipas() == "vid") {
            out << setw(20) << fixed << setprecision(2) << A.getRez()
                << setw(20) << "-" << endl;
        } else {
            out << setw(20) << "-"
                << setw(20) << fixed << setprecision(2) << A.getRez() << endl;
        }
    }
}
void rusiuotistud(vector<studentas> &grupe) {
    if (grupe.empty()) return;

    if (grupe[0].getTipas() == "vid") {
        sort(grupe.begin(), grupe.end(), pagalVid);
    } else {
        sort(grupe.begin(), grupe.end(), pagalMed);
    }
}