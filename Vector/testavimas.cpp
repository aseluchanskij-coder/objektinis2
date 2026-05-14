#include "testavimas.h"
#include "studentas.h"
#include "ivedimas_isvedimas.h"
#include "mano_std_vector.h"
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void failo_kurimo_testas(int kiek)
{
    auto start = high_resolution_clock::now();

    ofstream f("studentai_" + to_string(kiek) + ".txt");

    for(int i=0;i<kiek;i++){
        f << "Vardas" << i << " Pavarde" << i;

        for(int j=0;j<5;j++)
            f << " " << rand()%10+1;

        f << " " << rand()%10+1 << "\n";
    }

    f.close();

    auto end = high_resolution_clock::now();

    cout << kiek << " irasu failo kurimo laikas: "
         << duration<double>(end-start).count() << endl;
}


void apdorojimo_testas(const string& failas) {
    Vector<studentas> grupe;
    Vector<studentas> vargsai, kietuoliai;

    cout << "\nPradedamas testas su failu: " << failas << endl;

    auto s1 = high_resolution_clock::now();
    skaitymas_rez(failas, grupe); 
    auto e1 = high_resolution_clock::now();
    double t1 = duration<double>(e1 - s1).count();

    auto s2 = high_resolution_clock::now();
    std::sort(grupe.begin(), grupe.end(), pagalVid); 
    auto e2 = high_resolution_clock::now();
    double t2 = duration<double>(e2 - s2).count();

    auto s3 = high_resolution_clock::now();
    padalinti_studentus(grupe, vargsai, kietuoliai);
    auto e3 = high_resolution_clock::now();
    double t3 = duration<double>(e3 - s3).count();

    cout << fixed << setprecision(4);
    cout << "1. Nuskaitymo laikas:  " << t1 << " s" << endl;
    cout << "2. Rusiavimo laikas:    " << t2 << " s" << endl;
    cout << "3. Skirstymo laikas:    " << t3 << " s" << endl;
    cout << "Is viso studentu: " << grupe.size() << " (Vargsai: " << vargsai.size() << ", Kietuoliai: " << kietuoliai.size() << ")" << endl;

    ofstream f1("vargsai.txt");
    output(f1, vargsai);
    f1.close();

    ofstream f2("kietuoliai.txt");
    output(f2, kietuoliai);
    f2.close();
} 
void strategija1(Vector<studentas>& grupe, Vector<studentas>& vargsai, Vector<studentas>& kietuoliai) {
    for (const auto& s : grupe) {
        if (s.getRez() < 5.0) vargsai.push_back(s);
        else kietuoliai.push_back(s);
    }
}

void strategija2(Vector<studentas>& grupe, Vector<studentas>& vargsai){
    sort(grupe.begin(), grupe.end(), pagalRez);

    while (!grupe.empty() && grupe.back().getRez() < 5.0) {
        vargsai.push_back(grupe.back());
        grupe.PopBack();
    }
}

void strategija3(Vector<studentas>& grupe, Vector<studentas>& vargsai) {
    auto it = std::stable_partition(grupe.begin(), grupe.end(), [](const studentas& s) {
        return s.getRez() >= 5.0; 
    });
    for (auto i = it; i != grupe.end(); ++i) {
        vargsai.PushBack(*i);
    }

    while (grupe.end() != it) {
        grupe.PopBack();
    }
}