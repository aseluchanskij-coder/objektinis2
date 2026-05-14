#ifndef IVEDIMAS_ISVEDIMAS_H
#define IVEDIMAS_ISVEDIMAS_H

#include "studentas.h"
#include "mano_std_vector.h"
#include <ostream>
#include <string>

void input(Vector<studentas> &grupe);
void output(std::ostream &out, const Vector<studentas> &grupe);
void rusiuotistud(Vector<studentas> &grupe);
void skaitymas(const std::string &failo_pav, Vector<studentas> &grupe);
void skaitymas_rez(const std::string &failo_pav, Vector<studentas> &grupe);
void padalinti_studentus(const Vector<studentas> &grupe, Vector<studentas> &vargsai, Vector<studentas> &kietuoliai);
#endif