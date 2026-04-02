#include "studentas.h"
#include <algorithm>

using std::sort;

void studentas::skaiciuoti(int sum) {
    double skaicius;
    if (tipas == "vid") {
        skaicius = sum * 1.0 / paz.size();
    } else {
        sort(paz.begin(), paz.end());
        int n = paz.size();
        if (n % 2 == 0)
            skaicius = (paz[n/2 - 1] + paz[n/2]) / 2.0;
        else
            skaicius = paz[n/2];
    }
    rez = 0.4 * skaicius + 0.6 * egz;
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
