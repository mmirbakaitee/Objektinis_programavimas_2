# Objektinis-Programavimas

Sistemos parametrai:

     CPU: 11th Gen Intel(R) Core(TM) i5-11400H @ 2.70GHz   2.69 GHz
     RAM: 8GB
     SSD: 500 GB

---------------------V.0.1 PAPILDYMAI--------------------------------

Programa atlika ir su C masyvu,ir su std::vector konteineriu:
1) Realizuota programa, kuri nuskaito vartotoju ivedamus duomenis (studento vardas, pavarde, namu darbu ir egzamino rezultatas).
2) Baigus duomenu ivedima suskaiciuocamas galutinis vidurkis, mediana.

---------------------V.0.2 PAPILDYMAI--------------------------------

1) Prideta funkcija scan, kuri nuskaito faila. 
2) Apskaiciuojami studentu is failo vidurkiai ir medianos pagal formule. 
3) Rezultatai surikiuojami pagal varda.

---------------------V.0.3 PAPILDYMAI--------------------------------

1) Scan funkcijoje (nuskaito duomenu faila) implementuotas isimciu valdymas. 
2) Programa isskaidyta i kelis *.cpp (main funkcijos, funkciju deklaracijos + strukturos) ir i kelis *.h (bibliotekos, funkciju) failus.

---------------------V.0.4 PAPILDYMAI--------------------------------

1) Papildyta main funkcija. Suteikiama vartotojui daugiau galimybiu (galimas failu generavimas, perejimas tarp pasirinkimu, darbo uzbaigimas po darbo su txt failais).
2) Pridetos kompleksines printPGtxt, printtxt funkcijos, kurios generuoja (jei reikia), nuskaito bei formuoja txt failus pagal reikalavimus. Sugeneruojamas studentu visu pazymiu failas, bendras studentu galutiniu pazymiu failas. Tuomet studentu isrusiuojami pagal nurodytas salygas ir jie su galutiniais rezultatais irasomi i atitinkamai skirtingus txt failus.
3) Implementuotas visos programos, failo sukurimo, failo nuskaitymo, failo rusiavimo, isrusiuotu studentu irasymo i atitinkamus txt failus trukmes skaiciavimas.
4) Atlikta skaiciavimu analize su generuojamais ir jau sugeneruotais failais (galima rasti v.04 release)

a) DARBAS SU GENERUOJAMAIS FAILAIS 

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus:
|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|  Failo sukurimas     | 0.000637   | 0.000508  | 0.000491 | 0.000559 | 0.00058   |
|  Failo nuskaitymas   | 0.021593   | 0.170191  | 1.8625   | 18.0044  | 227.713   |
|  Studentu rusiavimas | 0.003387   | 0.041065  | 0.436892 | 4.3394   | 341.286   |
|  KIETIAKU irasymas    | 0.002521   | 0.024415  | 0.284341 | 2.58672  | 48.2718  |
|  VARGUOLIU irasymas  | 0.001732   | 0.016837  | 0.190583 | 1.78405  | 28.1771   |
|  Bendras laikas      | 12.883     | 10.6924   | 20.4578  | 70.7247  | 1207.23   |

b) DARBAS SU SUGENERUOTAIS FAILAIS 

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus:
|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|  Failo nuskaitymas   | 0.018224   | 0.283451  | 2.64144  | 23.4728  | 256.888   |
|  Studentu rusiavimas | 0.003371   | 0.069602  | 0.586354 | 5.70116  | 253.093   |
|  KIETIAKU irasymas    | 0.002388   | 0.033028  | 0.350438 | 3.37797  | 42.5484  |
|  VARGUOLIU irasymas  | 0.001714   | 0.040592  | 0.281979 | 2.36976  | 25.7387   |
|  Bendras laikas      | 5.19551    | 8.63683   | 15.3479  | 62.9997  | 926.779   |

---------------------V.0.5 PAPILDYMAI--------------------------------

1) Sukurtos trys programos naudojant skirtingo tipo konteinerius (vector, deque, list).
2) Ten, kur reikia (programoje su list tipo konteineriu), atnaujintos sort funkcijos, pakeista medianos skaiciavimo funkcija.
3) Atliekama analize: lyginame, kiek kievieno konteinerio tipo programa trunka nuskaityti txt faila, isrusiuoti pagal vidurki, isskirstyti pagal dvi grupes.
4) Analizei neaktualus laiko matavimai nuimti.
   
ANALIZE SU JAU SUGENERUOTAIS FAILAIS 

Laikas sekundėmis, kurį užtruko programa (VECTOR):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
| Failo nuskaitymas          | 0.017201 | 0.135471 | 1.16704  | 11.7178 | 141.443 |
| Rūsiavimas                 | 0.00574  | 0.069801 | 0.641486 | 6.9062  | 98.8297 |
| Skirstymas į dvi grupes    | 0.003488 | 0.057485 | 0.561964 | 4.61347 | 422.128 |
| Bendras laikas             | 0.026429 | 0.262757 | 2.37049  | 23.2375 | 662.401 | 

Laikas sekundėmis, kurį užtruko programa (DEQUE):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000 |
|---|---|---|---|---|---|
| Failo nuskaitymas          | 0.022373 | 0.179341 | 1.75345  | 17.6518 | 195.584  |
| Rūsiavimas                 | 0.008568 | 0.075929 | 0.747798 | 10.2411 | 114.12   |
| Skirstymas į dvi grupes    | 0.002596 | 0.025294 | 0.281616 | 3.48125 | 377.355  |
| Bendras laikas             | 0.033537 | 0.280564 | 2.78287  | 31.3741 | 687.059  | 

Laikas sekundėmis, kurį užtruko programa (LIST):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000 |
|---|---|---|---|---|---|
| Failo nuskaitymas          | 0.016    | 0.163196 | 1.46236  | 14.84    | 160.417 |
| Rūsiavimas                 | 0.000175 | 0.003546 | 0.044946 | 0.804268 | 20.0921 |
| Skirstymas į dvi grupes    | 0.001894 | 0.021843 | 0.245001 | 2.74138  | 1402.82 |
| Bendras laikas             | 0.018069 | 0.188585 | 1.7523   | 18.3856  | 1583.33 | 

Greiciausiai veikia list'ai, o vector'iai ir deque'ai panasiai, isskyrus su 10000000, tuomet vector'iai veikia greiciausiai.

---------------------V.1.0 PAPILDYMAI--------------------------------

1) Implementuotas 2-osios strategijos studentu skirstymas (sukuriamas tik vienas naujas vektor'ius, o is pagr. vektor'iaus istrinama neaktualus duomenis)
2) Implementuotas 2-osios strategijos studentu duomenu irasymas (irasome likusius duomenis is master vector'iaus ir varguoliu vector duomenis)
3) Suteikta vartotojui galimybe pasirinkti, kokia strategija naudoti: naujaja ar senaja.
4) Skirstymo pagreitinimui panaudoti std::erase bei std::partition algoritmai.

ANALIZE SU JAU SUGENERUOTAIS FAILAIS (2-oji strategija (1-aja galite rasti V.0.5 PAPILDYMO aprasyme))

a) Laikas sekundėmis, kurį užtruko programa (VECTOR std::erase):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.006263 | 0.066761 | 4.339465 | 282.0652 | --dideli sk-- |
| Skirstymas į dvi grupes    | 0.029743 | 2.72006  | 176.8039 | 5304.117 | --dideli sk-- |
| Bendras laikas             | 0.036006 | 2.78682  | 181.1433 | 6340.016 | --dideli sk-- | 

b) Laikas sekundėmis, kurį užtruko programa (VECTOR std::partition):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.00582  | 0.064008 | 0.604973 | 9.44182 | 151.6273 |
| Skirstymas į dvi grupes    | 0.002003 | 0.017828 | 0.18182  | 1.99382 | 19.9382  |
| Bendras laikas             | 0.007967 | 0.078294 | 0.779234 | 11.4356 | 114.356  | 

TASK MANAGER STATS (kompiuterio atmintis su 1000000):

          1 strategija: 71%
          2 strategija: 64%

Laikas sekundėmis, kurį užtruko programa (DEQUE):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000 |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.007274 | 0.076244 | 0.71878  | 7.83325 | 78.3325 |
| Skirstymas į dvi grupes    | 0.002376 | 0.020917 | 0.217998 | 2.20474 | 22.0474 |
| Bendras laikas             | 0.00965  | 0.097161 | 0.936778 | 10.038  | 100.38  | 

TASK MANAGER STATS (kompiuterio atmintis su 1000000):

          1 strategija: 74%
          2 strategija: 63%

Laikas sekundėmis, kurį užtruko programa (LIST):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000 |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.000175 | 0.002379 | 0.042083 | 0.698188 | 9.774632 |
| Skirstymas į dvi grupes    | 0.002242 | 0.025324 | 0.251771 | 2.64195  | 26.4195  |
| Bendras laikas             | 0.002417 | 0.027703 | 0.293854 | 3.34014  | 33.4014  | 

TASK MANAGER STATS (kompiuterio atmintis su 1000000):

          1 strategija: 81%
          2 strategija: 75%
          
 NAUDOJIMOSI INSTRUKCIJA:

          1. Parsisiųskite šiuos failus:
               a) final.v.1.0.vector.cpp, final.v.1.0.deque.cpp, final.v.1.0.list.cpp
               b) vsourceV.cpp, vsourceD.cpp, vsourceL.cpp
               c) vheaderisV.h, vheaderisD.h, vheaderisL.h
               d) studentlib.h, kursiokai.txt, CMakeLists.txt
           2. Sudėkite juos į vieną sukurtą folderį (pareadaguokite CMakeLists.txt faile projekto pavadinimą pagal sukurto aplanko pavadinimą).
           3. Build'inkite CMakeLists.txt
           4. Terminale build/<paleidziamojofailopavadinimas>.exe
           
  ---------------------V.1.1 PAPILDYMAI--------------------------------
  
  1) Vector Struct pakeistas į Vector Class
  2) Pakeistos tam tikros funkcijos, jog būtų labiau pritaikytoms Class konteineriui
  3) Pareadaguotas CMakeLists.txt failas, jog būtų kompiliuojama naudojant Flag'us
  
NAUDOJIMOSI INSTRUKCIJA:

          1. Įsidiegti terminalą, kuris turi *git bash*
          2. Įsidiegti *mingw* ir *cmake* extensions
          3. Parsisiųskite šiuos failus:
               a) final.v.1.0.vector.cpp, final.v.1.0.deque.cpp, final.v.1.0.list.cpp
               b) vsourceV.cpp, vsourceD.cpp, vsourceL.cpp
               c) vheaderisV.h, vheaderisD.h, vheaderisL.h
               d) studentlib.h, kursiokai.txt, CMakeLists.txt
           4. Sudėkite juos į vieną sukurtą folderį (pareadaguokite CMakeLists.txt faile projekto pavadinimą pagal sukurto aplanko pavadinimą).
           5. Build'inkite CMakeLists.txt
           6. Terminale build/<paleidziamojofailopavadinimas>.exe
          
          
Laikas sekundėmis, kurį užtruko programa (Struct Vector -03 2 strategija):
|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.000151  | 0.00501  | 0.16533  | 5.45589 | 180.0444 |
| Skirstymas į dvi grupes    | 0.007359  | 0.508052 | 4.064416 | 16.2577 | 130.0613 |
| Bendras laikas             | 0.00751   | 0.513062 | 4.229746 | 21.7136 | 310.1057 | 

Laikas sekundėmis, kurį užtruko programa (Class Vector -03 2 strategija):
|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.002      | 0.045863  | 0.68754  | 10.31316 | 154.6975 |
| Skirstymas į dvi grupes    | 0.007351   | 0.508044  | 0.64408  | 16.2569  | 130.605  |
| Bendras laikas             | 0.009351   | 0.553907  | 1.33162  | 26.57006 | 281.3025 | 

Laikas sekundėmis, kurį užtruko programa (Class Vector -02 2 strategija):
|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.006218  | 0.068398 | 0.752378  | 8.276158  | 91.037738 |
| Skirstymas į dvi grupes    | 0.017526  |1.05156   | 6.30936   | 37.85616  | 227.13696 |
| Bendras laikas             | 0.023744  | 1.119958 | 7.061738  | 46.132318 | 318.17478 | 

Laikas sekundėmis, kurį užtruko programa (Class Vector -01 2 strategija):
|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.005844  | 0.061428 | 0.67571  | 7.432836 | 81.76120  |
| Skirstymas į dvi grupes    | 0.01521   | 0.09126  | 0.54756  | 3.28536  | 19.71216  |
| Bendras laikas             | 0.021054  | 0.152688 | 1.22327  | 10.71819 | 101.473   | 

Laikas sekundėmis, kurį užtruko programa (Class Vector 2 strategija):
|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.00524  | 0.04764 | 0.63404  | 6.97444  | 76.71884  |
| Skirstymas į dvi grupes    | 0.01631  | 0.09786 | 0.58716  | 3.52296  | 21.3776   |
| Bendras laikas             | 0.02155  | 0.1455  | 1.2212   | 10.4974  | 98.09644  | 


EKSPERIMENTINĖ ANALIZĖ (su studentai1000000.txt failu):
|   | -01 | -02  | -03  | 
|---|---|---|---|
| Skaičiavimų trukmė  (sek.) | 10.71819 | 46.132318 | 26.57006 | 
| Projekto dydis      | 391KB  | 383KB | 368KB |  

 ---------------------V.1.2 PAPILDYMAI--------------------------------
 
 1) Realizuota "*Rule of five*" implementacija klasėje:

           a) Klasėje pridėtas objekto destruktorius (jau buvo implementuotas ir v1.1 versijoje).
           b) Klasėje pridėtas objekto kopijavimo konstruktorius.
           c) Klasėje pridėtas objekto konstruktorius (**move**).
           d) Klasėje pridėtas reikšmių perdavimo funkcija.
           e) Klasėje pridėta reikšmių perdavimo funckija (**move**).
           
2) Klasėje implementuota studentų informacijos išvedimo funkcija.
3) Funkcijų faile pakoreguotas studentų infomacijos išvedimas pritaikant klasėje esančią studentų informacijos išvedimo funkciją.
4) Implementuota Rule of five testavimo f-ja

Laikas sekundėmis, kurį užtruko programa įrašdama į file'us:
|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
| sprinf  | 0.005888 | 0.052992 | 0.476928  | 4.292352  | 38.631168  |
| ostream  | 0.013506  | 0.121554 | 1.093986  | 9.845874  | 88.612866  |

---------------------V.1.5 PAPILDYMAI--------------------------------

1) Senoji klasė pakeista į bazinę ir jos išvestinę. 
2) Studento vardas, pavardė yra apsaugoti: nebėra vieši, tačiau vis dar prieinami.

Abstrakčiosios f-jos:

               virtual std::string getvardas() const { return vardas; }
               virtual std::string getpavarde() const { return pavarde; }
               
---------------------V.2.0 PAPILDYMAI--------------------------------

1) Sukurta dokumentacija panaudojant Doxygen 1.5 projekto pagrindu.
2) Realizuoti Unit Testai naudojant catch.
3) Sukurtas automatinis diegimo file setup.exe

NAUDOJIMOSI INSTRUKCIJA:

          1) Parsisiuskite setup.exe file
          2) Pasirinkite norima path
          3) Paleiskite toje path .exe file
          4) Sekite konsoleje esenacias tolimesnes instrukcijas

---------------------V.3.0 PAPILDYMAI--------------------------------

1) Sukurta Vector Class, kuri bus naudojama std::vector vietoje
2) Pratestuotas Vector Class funkcijų funkcionalumas
3) Vector Class implementuota V2.0 programoje 

FUNKCIJŲ PALYGINIMAS (Modifiers Test):
|   | std::vector | Vector Class  |  
|---|---|---|
| Original Array:     | 10 20 30          | 10 20 30          | 
| After Clear:        |                   |                   | 
| After Assign:       | 40 40 40          | 40 40 40          | 
| After Insert:       | 10 40 40 40       | 10 40 40 40       | 
| After Emplace:      | 10 80 40 40 40    | 10 80 40 40 40    |
| After Erase:        | 10 80 40 40       | 10 80 40 40       | 
| After Emplace Back: | 10 80 40 40 90 100| 10 80 40 40 90 100| 
| After Pop Back:     | 10 80 40 40 90    | 10 80 40 40 90    |
| After Resize:       | 10 80 40 40 90 0  | 10 80 40 40 90 0  | 
| After Swap:         | 200 300           | 200 300           | 

Laikas sekundėmis, kurį užtruko programa užpildydama vektorius:
|   | std::vector | Vector Class  |  
|---|---|---|
| 10000     | 0.000945 | 0.000479 | 
| 100000    | 0.006788 | 0.004063 | 
| 1000000   | 0.051145 | 0.040929 | 
| 10000000  | 0.415288 | 0.479569 | 
| 100000000 | 4.58199  | 4.31924  | 

Laikas sekundėmis, kurį užtruko v2.0 programa:
|   | std::vector | Vector Class |  
|---|---|---|
| NUSKAITYMAS:         | 0.263025 | 2.677977  |
| RUSIAVIMAS:          | 0.558477 | 0.722223  | 
| SKIRSTYMAS:          | 82.07793 | 72.64143  | 
| KIETIAKU IRASYMAS:   | 0.645723 | 0.613089  | 
| VARGUOLIU IRASYMAS:  | 0.458991 | 0.449208  | 
| BENDRA TRUKME:       | 84.00415 | 77.10392  | 


