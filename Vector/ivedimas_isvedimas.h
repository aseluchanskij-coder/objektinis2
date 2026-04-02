#ifndef IVEDIMAS_ISVEDIMAS_H
#define IVEDIMAS_ISVEDIMAS_H

#include "studentas.h"
#include <vector>
#include <ostream>
#include <string>

using std::vector;
//////////////void output(std::ostream &out, const vector<studentas> &grupe);
void input(vector<studentas> &grupe);
void output(std::ostream &out, const vector<studentas> &grupe);
void rusiuotistud(vector<studentas> &grupe);
void skaitymas(const std::string &failo_pav, vector<studentas> &grupe);
void skaitymas_rez(const std::string &failo_pav, vector<studentas> &grupe);
void padalinti_studentus(const std::vector<studentas> &grupe, std::vector<studentas> &vargsai, std::vector<studentas> &kietuoliai);
#endif