#include "studentas.h"
#include <algorithm>
#include <iomanip>
#include <iostream>

using std::sort;

studentas::~studentas() {
    paz.clear();
    egz = 0;
    rez = 0.0;
    tipas.clear();
}   

void studentas::skaiciuoti(int isores_sum) {
    double skaicius = 0;
    if (paz.empty()) {
        rez = 0.6 * egz;
        return;
    }

    int tikroji_suma = isores_sum;
    if (tikroji_suma == 0) {
        for (int p : paz) tikroji_suma += p;
    }

    if (tipas == "vid") {
        skaicius = (double)tikroji_suma / paz.size();
    } else {
        std::vector<int> temp_paz = paz; 
        std::sort(temp_paz.begin(), temp_paz.end());
        int n = temp_paz.size();
        if (n % 2 == 0)
            skaicius = (temp_paz[n/2 - 1] + temp_paz[n/2]) / 2.0;
        else
            skaicius = temp_paz[n/2];
    }
    rez = 0.4 * skaicius + 0.6 * egz;
}

std::istream& operator>>(std::istream& is, studentas& s) {
    std::cout << "Vardas: "; is >> s.vardas;
    std::cout << "Pavarde: "; is >> s.pavarde;
    std::cout << "Egzamino balas: "; is >> s.egz;
    
    int p, sum = 0;
    s.paz.clear(); 
    std::cout << "Iveskite pazymius (0 - baigti): ";
    while (is >> p && p != 0) {
        if (p > 0 && p <= 10) {
            s.paz.push_back(p);
            sum += p;
        }
    }
    
    if (s.tipas.empty()) s.tipas = "vid";
    s.skaiciuoti(sum); 
    
    return is;
}

std::ostream& operator<<(std::ostream& os, const studentas& s) {
    os << std::left << std::setw(15) << s.vardas 
       << std::setw(15) << s.pavarde 
       << std::fixed << std::setprecision(2) << s.rez;
    return os;
}

studentas::studentas(const studentas& other) 
    : zmogus(other), paz(other.paz), egz(other.egz), rez(other.rez), tipas(other.tipas) {}

studentas& studentas::operator=(const studentas& other) {
    if (this != &other) {
        zmogus::operator=(other);
        paz = other.paz;
        egz = other.egz;
        rez = other.rez;
        tipas = other.tipas;
    }
    return *this;
}

studentas::studentas(studentas&& other) noexcept 
    : zmogus(std::move(other)), paz(std::move(other.paz)), egz(other.egz), rez(other.rez), tipas(std::move(other.tipas)) {
    other.egz = 0;
    other.rez = 0.0;
}

studentas& studentas::operator=(studentas&& other) noexcept {
    if (this != &other) {
        zmogus::operator=(std::move(other));
        paz = std::move(other.paz);
        egz = other.egz;
        rez = other.rez;
        tipas = std::move(other.tipas);

        other.egz = 0;
        other.rez = 0.0;
    }
    return *this;
}

bool pagalVarda(const studentas &a, const studentas &b) {
    return a.getVardas() < b.getVardas();
}

bool pagalPavarde(const studentas &a, const studentas &b) {
    return a.getPavarde() < b.getPavarde();
}

bool pagalVid(const studentas &a, const studentas &b) {
    return (a.getTipas() == "vid" ? a.getRez() : -1) < (b.getTipas() == "vid" ? b.getRez() : -1);
}

bool pagalMed(const studentas &a, const studentas &b) {
    return (a.getTipas() == "med" ? a.getRez() : -1) > (b.getTipas() == "med" ? b.getRez() : -1);
}

bool pagalRez(const studentas &a, const studentas &b) {
    return a.getRez() > b.getRez();
}