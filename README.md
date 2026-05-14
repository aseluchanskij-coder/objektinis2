# Objektinis-programavimas
Šioje programos versijoje buvo sukurtas nuosavas Vector konteineris, realizuota apie 85% std::vector konteinerio funkcionalumo. 
5 pasirinktų funkcijų aprašymai:

1. Copy Constructor:

Yra išskiriamas atminties blokas. Bloko dydis prilygs kopijuojamo vektor talpą. Tada elementai bus "sukonstruoti" naujame atminties bloke, išviečiant kopijavimo konstruktoriu. (Atminties išskirymas vyksta per operator new, o placement new įstato vektorių į naują vietą).

2. Copy Assignment

Patikrinama ar jis nebando priskirti paties savęs. Įsitikinus, kad objektai skirtingi, yra pakartojamas analogiškas procesas Copy Constructor t. y. rezervuojama nauja atmintis ir nukopijuojami elementai, o seni objektai yra išvalomi iškvietus Clear. 

3. ReAlloc

Šią funkciją naudoju, kad būtų galimybė padidinti vektoriaus talpą, kitaip tariant "Capacity". T. y. išskiriamas naujas pusantro karto didesnis atminties blokas, ir naudojant move yra perkeliami elementai į naują vietą. Ši funkcija įgyvendinta tam, kad nereikėtų kopijuoti kaskart elementų, nes tada nereikia priskirti naujos atminties. Senas objektas išvalomas ir senoji atmintis atlaisvinama.

4. Pushback

Funckija naudojama kad įdėti naują elementą į sąrašo galą. Pradžioje patikrinama ar esamame mano sukurtame vektoriuje yra laisvos vietos, t. y. ar vektoriaus dydis mažesnis už vektoriaus talpą. Jei ne, Realloc funkcijos pagalba talpa padidinama. Tada naujas elementas yra pridedamas į vektoriaus galą. Įgyvendintos dvi Pushback funkcijos, viena kopijavimui, kita perkėlimui (copy, move).

5. EmplaceBack

Ši funkcija yra funkcijos Pushback funkcijos alternatyva, kad galima būtų kurti objektus tiesiogiai vektoriaus atmintyje. Naudojamas kintamasis args (argumentai) t. y. (Args&& ...) ir forward elementai yra siunčiami tiesiai į konstruktorių. Tokiu būtų placement new pagalba objektas sukonstruojamas vektoriaus rezervuotoje atmintyje. EmplaceBack dažnai yra efektyviau naudoti negu Pushback funkciją.


Atlikta spartos analizė std::vector ir mano sukurto vector. Iš rezultatų pateiktų žemiau, matyti kad std::vector užpildymas vyksta šiek tiek greičiau negu mano sukurto vector. Kompiliuojant buvo naudojamas "flag" -O3, kad paspartinti abiejų vektorių užpildymą:

| Elementu kiekis | std::vector laikas (s) | Mano Vector laikas (s) |
|-----------------|------------------------|------------------------|
| 10000           | 0.000041               | 0.000052               |
| 100000          | 0.000241               | 0.000268               |
| 1000000         | 0.001820               | 0.003388               |
| 10000000        | 0.026223               | 0.027327               |
| 100000000       | 0.162524               | 0.268889               |


Konteinerių atminties perskirstymai užpildant 10000000 elementų:

Atminties perskirstymu skaiciavimas (100000000 elementu):
----------------------------------------------------------------------
std::vector perskirstymu skaicius: 28
Mano Vector perskirstymu skaicius: 46

Tokie rezultatai gaunami, kadangi mano vector didindamas vietą skiria 1.5 vietos, o std::vector 2.0 karto padidina talpą. 

Unit testams, buvo panaudotas doctest.h biblioteka, atlikus testą gavau tokius rezultatus: 

[doctest] doctest version is "2.5.0"
[doctest] run with "--help" for options
===============================================================================
[doctest] test cases:  5 |  5 passed | 0 failed | 0 skipped
[doctest] assertions: 21 | 21 passed | 0 failed |
[doctest] Status: SUCCESS!

Iš testo rezultatų matome, kad mano vector konteineris, rule of five veikia gerai.



Linux

Ubuntu / Debian

sudo apt update

sudo apt install cmake g++ make

Fedora

sudo dnf install cmake gcc-c++ make

Arch Linux

sudo pacman -S cmake gcc make

Windows (MSYS2)

pacman -Syu

pacman -Su

pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake make


macOS

xcode-select --install

brew install cmake

Paleidimas

git clone -b v1.0 https://github.com/aseluchanskij-coder/Objektinis-programavimas.git 

cd Objektinis-programavimas

mkdir build

cd build

cmake ..

cmake --build .

Paleidimas:

./build/v1.0_vector

./build/v1.0_deque

./build/v1.0_list