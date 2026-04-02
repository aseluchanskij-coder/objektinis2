# Objektinis-programavimas
🗂️ Versions / Releases
🔹 v.pradinė

Pirmoji programos iteracija.
Įgyvendintas studentų informacijos įvedimas, galutinio įvertinimo skaičiavimas (pagal vidurkį ir medianą) bei aiškus rezultatų pateikimas.

🔹 v0.1

Sistema pritaikyta darbui su dinamišku studentų ir namų darbų kiekiu.

Realizuoti du sprendimo būdai:

naudojant C masyvus
naudojant std::vector

Papildomai įdiegta atsitiktinio pažymių generavimo funkcija.

🔹 v0.2

Pridėtas duomenų nuskaitymas iš failų (std::vector).

Įgyvendintas lankstus rūšiavimas pagal:

vardą
pavardę
galutinį balą (vidurkis / mediana)

Rezultatai pateikiami tvarkingai išlygiuotu formatu. Programa patikrinta su dideliais duomenų rinkiniais.

🔹 v0.3

Atliktas projekto kodo pertvarkymas.

Kodas išskaidytas į atskirus .cpp ir .h failus, pagerinant struktūrą.
Taip pat įdiegtas klaidų valdymas naudojant išimtis.

🔹 v0.4

Sukurta duomenų generavimo funkcija bei paruošti dideli testiniai failai.

Įgyvendintas studentų skirstymas į grupes pagal galutinį balą, rezultatus išvedant į atskirus failus.
Atlikta veikimo spartos analizė įvairiuose apdorojimo etapuose.

🔹 v1.0

Galutinė versija.

Vektoriu versija prašo vartotojo padaryti pasirinkimą: 1- ranka įvesti studentų vardus bei jų pažymius, 2 - prašo įvesti studento vardus, bet namų darbų bei egzamino pažymiai generuojami atsitiktinai nuo 1 iki 10, 3 - sugeneruoja studentų vardus bei pavardes, analogiškai ir visus gautus pažymius, 4 - nuskaito duomenis iš failo, 5 - nuskaityti is anksto sugeneruota faila, 6 - baigti.
Yra galimybė skaityti duomenis iš failo, taip pat juos rūšiuoti pagal vieną iš penkių parinkčių. Sukurti papildomi funkcionalumai, sukurta daugiau .cpp ir .h failų, panaudota exception handling funckija dviejuose vietuose. Dabartinėje versijoje pridėtas studentų atskirimas į vargšus ir kietuolius, taip pat pridėta galimybė skaityti duomenis iš vartotojo įvesto failo ir rašyti į vartotojo pasirinktą failą. Taip pat yra galimybė atlikti testavimą, o būtent programos veikimo laiko. Buvo atlikti du tyrimai: 1 tyrimas (darbas su failais tik failų sukūrimas, atskira testavimo funkcija):  
failų kūrimas ir jo uždarymas.


📊 Performance Analysis
🖥️ Testavimo aplinka
OS: MacOS
CPU: Apple silicon M1
RAM: 16 GB
Diskas: 512 GB NVMe SSD


REZULTATAI:

 | Failo versija(2 strategija):        | 1000000.txt                | 10000000.txt               |
|-------------------------------------|----------------------------|----------------------------|
| Klasės:                             |                            |                            |
| Nuskaitymo laikas (s)               | 0.6729 s                   | 7.4083 s                   |
| Rūšiavimo laikas (s)                | 0.0740 s                   | 0.8984 s                   |
| Skirstymo laikas (s)                | 0.0349 s                   | 0.3249 s                   |
| Struktūra:                          |                            |                            |
| Nuskaitymo laikas (s)               | 0.6639 s                   | 6.8750 s                   |
| Rūšiavimo laikas (s)                | 0.0818 s                   | 0.9278 s                   |
| Skirstymo laikas (s)                | 0.0291 s                   | 0.4319 s                   |
| Klasės tikrinimas naudojant "Flag": | 1000000.txt                | 10000000.txt               |
| -O1 Nuskaitymo laikas (s):          | 0.7048 s                   | 7.3539 s                   |
| -O1 Rusiavimo laikas (s):           | 0.1545 s                   | 1.7485 s                   |
| -O1 Skirstymo laikas (s):           | 0.0282 s                   | 0.4577 s                   |
| -O2 Nuskaitymo laikas (s):          | 0.6814 s                   | 7.1690 s                   |
| -O2 Rusiavimo laikas (s):           | 0.1562 s                   | 1.7997 s                   |
| -O2 Skirstymo laikas (s):           | 0.0286 s                   | 0.5442 s                   |
| -O3 Nuskaitymo laikas (s):          | 0.6822 s                   | 6.9968 s                   |
| -O3 Rusiavimo laikas (s):           | 0.1547 s                   | 1.8515 s                   |
| -O3 Skirstymo laikas (s):           | 0.0266 s                   | 0.4318 s                   |
| -O1 .exe failo dydis: 83KB          | -O2 .exe failo dydis: 84KB | -O3 .exe failo dydis: 91KB |



Tarp klasių ir struktūrų esminio greitaveikos skirtumo nėra, rezultatai beveik identiški.
Optimizavimo lygis -O3 efektyviausias apdorojant 10 mln. įrašų, ypač paspartinant duomenų nuskaitymą.
Skirtumas tarp -O1 ir -O2 rūšiavimo greičio yra minimalus arba paklaidos ribose.
Padidinus duomenų kiekį 10 kartų, rūšiavimo laikas išauga daugiau nei 20 kartų dėl algoritmo sudėtingumo.
Didžiausią įtaką programos našumui turi duomenų kiekis ir pasirinktas optimizavimo lygis, o ne duomenų tipas.



🚀 Getting Started

🔧 Reikalavimai

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