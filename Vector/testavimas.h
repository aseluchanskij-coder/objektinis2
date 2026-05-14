#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include "mano_std_vector.h"
#include <string>
#include "studentas.h" 

void strategija1(Vector<studentas>& grupe, Vector<studentas>& vargsai, Vector<studentas>& kietuoliai);
void strategija2(Vector<studentas>& grupe, Vector<studentas>& vargsai);
void strategija3(Vector<studentas>& grupe, Vector<studentas>& vargsai);
void failo_kurimo_testas(int kiek);
void apdorojimo_testas(const std::string& failas);

#endif
