# Objektinis-Programavimas

---------------------v.03 papildymai--------------------------------

1) Scan funkcijoje (nuskaito duomenu faila) implementuotas isimciu valdymas. 
2) Programa isskaidyta i kelis *.cpp (main funkcijos, funkciju deklaracijos + strukturos) ir i kelis *.h (bibliotekos, funkciju) failus.

---------------------v.04 papildymai--------------------------------

1) Papildyta main funkcija. Suteikiama vartotojui daugiau galimybiu (galimas failu generavimas, perejimas tarp pasirinkimu, darbo uzbaigimas po darbo su txt failais).
2) Pridetos kompleksines printPGtxt, printtxt funkcijos, kurios generuoja (jei reikia), nuskaito bei formuoja txt failus pagal reikalavimus. Sugeneruojamas studentu visu pazymiu failas, bendras studentu galutiniu pazymiu failas. Tuomet studentu isrusiuojami pagal nurodytas salygas ir jie su galutiniais rezultatais irasomi i atitinkamai skirtingus txt failus.
3) Implementuotas visos programos, failo sukurimo, failo nuskaitymo, failo rusiavimo, isrusiuotu studentu irasymo i atitinkamus txt failus trukmes skaiciavimas.
4) Atlikta skaiciavimu analize su generuojamais ir jau sugeneruotais failais (galima rasti v.04 release)

---------------------v.05 papildymai--------------------------------

1) Sukurtos trys programos naudojant skirtingo tipo konteinerius (vector, deque, list).
2) Ten, kur reikia (programoje su list tipo konteineriu), atnaujintos sort funkcijos, pakeista medianos skaiciavimo funkcija.
3) Atliekama analize: lyginame, kiek kievieno konteinerio tipo programa trunka nuskaityti txt faila, isrusiuoti pagal vidurki, isskirstyti pagal dvi grupes.
4) Analizei neaktualus laiko matavimai nuimti.

---------------------SPARTOS ANALIZE--------------------------------

Sistemos parametrai:

     CPU: 11th Gen Intel(R) Core(TM) i5-11400H @ 2.70GHz   2.69 GHz
     RAM: 8GB
     SSD: 500 GB
   
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
