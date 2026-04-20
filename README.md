# Objektinis-programavimas
Šioje programos versijoje buvo realizuotos "Rule of five" taisyklė. 
T. y.:
1. Destruktorius
2. Copy konstruktorius
3. Move konstruktorius
4. Copy priskyrimo operatorius
5. Move priskyrimo operatorius

Papildomai buvo pridetas switch/case meniu, kuris leidžia vartotojui naudotis pilna programa, pasirenkant ko jam tiksliai reikia(ankstesnėse versijose buvo daug užkomentuotų main failo eilučių, kas gali klaidinti).
Swtich meniu pasirinkę case 2 galima patikrinti copy ir move priskyrimo operatorius:
V1.2 versijos testas:


Iveskite studenta:
Vardas: alan
Pavarde: selu
Egzamino balas: 10
Iveskite pazymius (0 - baigti): 8 
6
5
4
0
Stud3 (perkeltas is S1): alan           selu           8.30
Stud2 (kopija): alan           selu           8.30

Iveskite studenta:
Vardas: alans1
Pavarde: selu2
Egzamino balas: 5
Iveskite pazymius (0 - baigti): 2
3
4
1
2
2
2
1
0
Stud3 (perkeltas is S1): alans1         selu2          3.85
Stud2 (kopija): alans1         selu2          3.85

Copy ir move operatoriai veikia teisingai, buvo naudoti įvesties ir išvesties operatoriai.

 Reikalavimai

🐧 Linux

Ubuntu / Debian

sudo apt update

sudo apt install cmake g++ make

Fedora

sudo dnf install cmake gcc-c++ make

Arch Linux

sudo pacman -S cmake gcc make

🪟 Windows (MSYS2)

pacman -Syu

pacman -Su

pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake make


🍏 macOS

xcode-select --install

brew install cmake

▶️ Paleidimas

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