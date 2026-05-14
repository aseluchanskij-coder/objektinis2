#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "mano_std_vector.h" 

using namespace std;
using namespace std::chrono;

int main() {
    vector<int> dydziai = {10000, 100000, 1000000, 10000000, 100000000};

    cout << left << setw(20) << "Elementu kiekis" 
         << setw(25) << "std::vector laikas (s)" 
         << setw(25) << "Mano Vector laikas (s)" << endl;
    cout << "----------------------------------------------------------------------\n";

    for (int sz : dydziai) {
        
        auto start1 = high_resolution_clock::now();
        
        std::vector<int> v1;
        for (int i = 1; i <= sz; ++i) {
            v1.push_back(i);
        }
        
        auto end1 = high_resolution_clock::now();
        duration<double> laikas1 = end1 - start1;

       
        auto start2 = high_resolution_clock::now();
        
        Vector<int> v2;
        for (int i = 1; i <= sz; ++i) {
            v2.PushBack(i); 
        }
        
        auto end2 = high_resolution_clock::now();
        duration<double> laikas2 = end2 - start2;

        cout << left << setw(20) << sz 
             << setw(25) << fixed << setprecision(6) << laikas1.count() 
             << setw(25) << fixed << setprecision(6) << laikas2.count() << endl;
    }
cout << "\nAtminties perskirstymu skaiciavimas (100000000 elementu):\n";
    cout << "----------------------------------------------------------------------\n";

    size_t test_sz = 100000000;

    std::vector<int> v_std;
    int std_reallocs = 0;
    for (size_t i = 0; i < test_sz; ++i) {
        if (v_std.size() == v_std.capacity()) {
            std_reallocs++;
        }
        v_std.push_back(i);
    }

    Vector<int> v_mano;
    for (size_t i = 0; i < test_sz; ++i) {
        v_mano.PushBack(i);
    }

    cout << "std::vector perskirstymu skaicius: " << std_reallocs << endl;
    cout << "Mano Vector perskirstymu skaicius: " << v_mano.realloc_count << endl;

    return 0;
}