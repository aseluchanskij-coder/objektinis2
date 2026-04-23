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
V1.5 versijos testai:

Rule of five kūrimo testai:

Iveskite studenta:
Vardas: alan
Pavarde: selu 
Egzamino balas: 4
Iveskite pazymius (0 - baigti): 1
7
6
5
2
3
2
0
Stud3 (perkeltas is S1): alan           selu           3.89
Stud2 (kopija): alan           selu           3.89
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

Failu kūrimo testai:
Generuojami failai...
1000 irasu failo kurimo laikas: 0.00
10000 irasu failo kurimo laikas: 0.02
100000 irasu failo kurimo laikas: 0.09
(galima ir didesnius)

Abstrakčios klasės testas:
(v1.5) testas:
S4 (perkeltas): Testas         Testaitis      9.20
Visi Rule of Five metodai patikrinti.

Apdorojimo testai:
Pradedamas testas su failu: 1000.txt
Rezultatai nuskaityti is failo!
1. Nuskaitymo laikas:  0.0046 s
2. Rusiavimo laikas:    0.0003 s
3. Skirstymo laikas:    0.0002 s
Is viso studentu: 1000 (Vargsai: 411, Kietuoliai: 589)

Pradedamas testas su failu: 10000.txt
Rezultatai nuskaityti is failo!
1. Nuskaitymo laikas:  0.0169 s
2. Rusiavimo laikas:    0.0017 s
3. Skirstymo laikas:    0.0006 s
Is viso studentu: 10000 (Vargsai: 4100, Kietuoliai: 5900)

Flag/struktūrų testai:
| Failo versija(2 strategija):            | 1000000.txt                | 10000000.txt               |
|-----------------------------------------|----------------------------|----------------------------|
| Klasės:                                 |                            |                            |
| Nuskaitymo laikas (s)                   | 0.6729 s                   | 7.4083 s                   |
| Rūšiavimo laikas (s)                    | 0.0740 s                   | 0.8984 s                   |
| Skirstymo laikas (s)                    | 0.0349 s                   | 0.3249 s                   |
| Struktūra:                              |                            |                            |
| Nuskaitymo laikas (s)                   | 0.6639 s                   | 6.8750 s                   |
| Rūšiavimo laikas (s)                    | 0.0818 s                   | 0.9278 s                   |
| Skirstymo laikas (s)                    | 0.0291 s                   | 0.4319 s                   |
| Klasės tikrinimas naudojant "Flag":     | 1000000.txt                | 10000000.txt               |
| -O1 Nuskaitymo laikas (s):              | 0.7048 s                   | 7.3539 s                   |
| -O1 Rusiavimo laikas (s):               | 0.1545 s                   | 1.7485 s                   |
| -O1 Skirstymo laikas (s):               | 0.0282 s                   | 0.4577 s                   |
| -O2 Nuskaitymo laikas (s):              | 0.6814 s                   | 7.1690 s                   |
| -O2 Rusiavimo laikas (s):               | 0.1562 s                   | 1.7997 s                   |
| -O2 Skirstymo laikas (s):               | 0.0286 s                   | 0.5442 s                   |
| -O3 Nuskaitymo laikas (s):              | 0.6822 s                   | 6.9968 s                   |
| -O3 Rusiavimo laikas (s):               | 0.1547 s                   | 1.8515 s                   |
| -O3 Skirstymo laikas (s):               | 0.0266 s                   | 0.4318 s                   |
| -O1 .exe failo dydis: 83KB              | -O2 .exe failo dydis: 84KB | -O3 .exe failo dydis: 91KB |
| Struktūros tikrinimas naudojant "Flag": | 1000000.txt                | 10000000.txt               |
| -O1 Nuskaitymo laikas (s):              | 0.7308 s                   | 7.8239 s                   |
| -O1 Rusiavimo laikas (s):               | 0.1965 s                   | 1.8785 s                   |
| -O1 Skirstymo laikas (s):               | 0.0382 s                   | 0.4577 s                   |
| -O2 Nuskaitymo laikas (s):              | 0.6814 s                   | 7.8690 s                   |
| -O2 Rusiavimo laikas (s):               | 0.1562 s                   | 1.5997 s                   |
| -O2 Skirstymo laikas (s):               | 0.0286 s                   | 0.2442 s                   |
| -O3 Nuskaitymo laikas (s):              | 0.6822 s                   | 7.0168 s                   |
| -O3 Rusiavimo laikas (s):               | 0.1547 s                   | 1.8515 s                   |
| -O3 Skirstymo laikas (s):               | 0.0346 s                   | 0.5318 s                   |
| -O1 .exe failo dydis: 84KB              | -O2 .exe failo dydis: 85KB | -O3 .exe failo dydis: 90KB |


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