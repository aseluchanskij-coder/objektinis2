#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include "mano_std_vector.h"
#include <iostream>
#include <utility>

class zmogus {
protected:
    std::string vardas;
    std::string pavarde;

public:
    zmogus() = default;
    zmogus(const std::string& v, const std::string& p) : vardas(v), pavarde(p) {}
    virtual ~zmogus() = 0;

    zmogus(const zmogus& other) = default;
    zmogus& operator=(const zmogus& other) = default;
    zmogus(zmogus&& other) noexcept = default;
    zmogus& operator=(zmogus&& other) noexcept = default;

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    void setVardas(const std::string &v) { vardas = v; }
    void setPavarde(const std::string &p) { pavarde = p; }
};

inline zmogus::~zmogus() {}

class studentas : public zmogus {
private:
    Vector<int> paz;
    int egz;
    double rez;
    std::string tipas;

public:
    studentas(std::string v = "", std::string p = "", Vector<int> pz = {}, int e = 0, std::string t = "vid");
    ~studentas();

    studentas(const studentas& other);
    studentas& operator=(const studentas& other);
    studentas(studentas&& other) noexcept;
    studentas& operator=(studentas&& other) noexcept;

    const Vector<int>& getPaz() const { return paz; }
    int getEgz() const { return egz; }
    double getRez() const { return rez; }
    const std::string& getTipas() const { return tipas; }

    friend std::ostream& operator<<(std::ostream& os, const studentas& s);
    friend std::istream& operator>>(std::istream& is, studentas& s);

    void setEgz(int e) { egz = e; }
    void setRez(double r) { rez = r; }
    void setTipas(const std::string &t) { tipas = t; }
    
    void pridetiPazymi(int p) { paz.push_back(p); }
    void skaiciuoti(int sum = 0); 
};

bool pagalVarda(const studentas &a, const studentas &b);
bool pagalPavarde(const studentas &a, const studentas &b);
bool pagalVid(const studentas &a, const studentas &b);
bool pagalMed(const studentas &a, const studentas &b);
bool pagalRez(const studentas &a, const studentas &b);

#endif