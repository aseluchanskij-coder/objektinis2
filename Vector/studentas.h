#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

class studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> paz;
    int egz;
    double rez;
    std::string tipas;

public:
    studentas() : egz(0), rez(0.0) {}

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    const std::vector<int>& getPaz() const { return paz; }
    int getEgz() const { return egz; }
    double getRez() const { return rez; }
    const std::string& getTipas() const { return tipas; }

    void setVardas(const std::string &v) { vardas = v; }
    void setPavarde(const std::string &p) { pavarde = p; }
    void setEgz(int e) { egz = e; }
    void setRez(double r) { rez = r; }
    void setTipas(const std::string &t) { tipas = t; }
    
    void pridetiPazymi(int p) { paz.push_back(p); }
    void skaiciuoti(int sum); 
};

    bool pagalVarda(const studentas &a, const studentas &b);
    bool pagalPavarde(const studentas &a, const studentas &b);
    bool pagalVid(const studentas &a, const studentas &b);
    bool pagalMed(const studentas &a, const studentas &b);
    bool pagalRez(const studentas &a, const studentas &b);

#endif