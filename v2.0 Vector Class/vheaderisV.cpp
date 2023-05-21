//#include "vsourceV.h"
#include "vsourceVV.h"
// pratestuosime rule of five
void TestFunc5 () {

  Vector <int> pazymiai {1, 1, 1, 10};
  Student s1;
    s1.setvardas("First");
    s1.setpavarde("Student");
    s1.setp(pazymiai);
    s1.setgal(aver(s1));
    s1.setmed(medi(s1));
  cout << "s1: \n" << s1 << endl;

  // copy constructor
  Student s2(s1);
  cout << "s2: \n" << s2 << endl;

  // default constructor and copy assignment 
  Student s3;
  cout << "Tuscias s3: \n" << s3 << endl;
  s3 = s2;
  cout << "Priskirtas is s2 naujas s3: \n" << s3 << endl;

  // move constructor
  Student s4;
    s4.setvardas("New");
    s4.setpavarde("Student");
    s4.setp(pazymiai);
    s4.setgal(aver(s4));
    s4.setmed(medi(s4));
  cout << "s4: \n" << s4 << endl;

  // move assignment 
  Student s5 = std::move(s4);
    s5.setp(pazymiai);
    s5.setgal(aver(s5));
    s5.setmed(medi(s5));
  cout << "s5: \n" << s5 << endl;
}

template <typename T>
void sort_time(vector<Student> info)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(info.begin(), info.end());
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time in milliseconds
    decltype(start) diff = end - start;
    double elapsed_ms = std::chrono::duration<double, std::milli>(diff).count();

    cout << "Time taken: " << elapsed_ms << " ms\n";
}

double aver(const Student &stud)
{
    int suma = 0;
    Vector <int> p = stud.getp();
    for (auto i : p) {
        suma += i;
    }
    return (double)suma / p.size()*0.4+stud.gete()*0.6;

}

double medi(const Student &stud)
{
    Vector <int>p = stud.getp();
    sort(p.begin(), p.end());
    if (p.size() % 2 == 0) {
        int vid = p.size() / 2;
        return ((p[vid - 1] + p[vid]) / 2.0)*0.4+stud.gete()*0.6;
    }
    else {
        return p[p.size() / 2]*0.4+stud.gete()*0.6;
    }
}

bool FileExists(const std::string& Filename)
{
    struct stat Buffer;
    return stat(Filename.c_str(), &Buffer) == 0;
}

bool all_letters(const std::string& str) {
    for (char c : str) {
        if (!std::isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool compN(const Student& first, const Student& scnd) {
 return first.getvardas() < scnd.getvardas();
}

bool compV(const Student& first, const Student& scnd) {
    double first_avg = first.getgal();
    double scnd_avg = scnd.getgal();
    
    if (first_avg == scnd_avg) { 
        return scnd_avg < first_avg;
    }
    
    return first_avg > scnd_avg;
}

void print(const Vector<Student>& students) {
    cout << fixed << setprecision(2);
    for (auto i : students)
        cout << i;
}

void addstudent(Vector<Student>& students, Student& stud) {
    char choice;
    int query;
    cout << "Ar norite kad skaitytume faila, jei taip iveskite 'p'.\nKitu atveju - bet kokia raide. \nJusu pasirinkimas: ";
    cin >> choice;
    if (choice == 'p' || choice == 'P') {
        int n = 0;
        scan(students, n, stud);
        sort(students.begin(), students.end(), compN);
        for (int i = 0; i < static_cast<int>(students.size()); i++) {
             students[i].setgal(aver(students[i]));
             students[i].setmed(medi(students[i]));
        }
    }
   else {
    Student info;
    cout << "Iveskite studento varda bei pavarde: ";
    string vardas, pavarde;
    cin >> vardas >> pavarde;
    info.setvardas(vardas);
    info.setpavarde(pavarde);
    while (!all_letters(info.getvardas()) || !all_letters(info.getpavarde())) {
        cout << "SUKLYDOTE! VARDAS TURI TURETI TIK RAIDES. BANDYKITE DAR KARTA.\n Iveskite studento varda bei pavarde:";
        cin >> vardas >> pavarde;
        info.setvardas(vardas);
        info.setpavarde(pavarde);
    }

        cout << "Iveskite studento namu darbu pazymius intervale 1-10. Kiekvienas pazymys vedamas is naujos eilutes." << endl;
        Vector <int>grades = info.getp();
        addgrade(grades);
        info.setp(grades);
        cout << "Iveskite studento egzamino pazymi intervale 1-10: ";
        int e_val;
        cin >> e_val;
        info.sete(e_val);

        while (info.gete() < 1 || info.gete() > 10 || cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "SUKLYDOTE! EGZAMINO REZULTATAS TURI BUTI SKAICIUS INTERVALE 1-10. BANDYKITE DAR KARTA: ";
            int e_val;
            cin >> e_val;
            info.sete(e_val);
        }
        cout << "Kokius duomenis naudojant turetu buti isvedami rezultatai? \n Jei ranka rasykite 1, jei atsistiktinai - 2. \n Jusu pasirinkimas: " << endl;
        cin >> query;
        while ((query != 1 && query != 2) || cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "SUKLYDOTE! PASIRINKIMAS TURI BUTI SKAICIUS. BANDYKITE DAR KARTA. ";
            cin >> query;
        }
        if (query == 2) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dist(1, 10);
            cout << endl;
            cout << "Atsitiktinai sugeneruoti studento namu darbu pazymiai: ";
            for (int i = 0; i < static_cast<int>(grades.size()); i++) {
                info.getp()[i] = dist(gen);
                cout << info.getp()[i] << " ";
            }
            cout << endl;
            info.sete(dist(gen));
            cout << "Atsitiktinai sugeneruotas studento egzamino pazymys: " << info.gete();
            cout << endl;
        }
        info.setgal(aver(info));
        info.setmed(medi(info));
        students.push_back(info);
    } 
}

void addgrade(Vector <int>& p) {
    int r;
    cin >> r;
    while (r < 1 || r > 10 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "SUKLYDOTE! STUDENTO NAMU DARBU PAZYMYS TURI BUTI INTERVALE 1-10. BANDYKITE DAR KARTA: ";
        cin >> r;
    }
    p.push_back(r);

    while (cin >> r)
    {
        if (r < 1 || r > 10)
        {
            break;
        }
        p.push_back(r);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void scan(Vector<Student>& info, int amount, Student& stud) {
    string vardas, pavarde;
    double e = 0; 
    int grades;
    ifstream fd(CDfv);
    try {
        if (fd.is_open()) {
            fd >> vardas >> pavarde;
            string row;
            getline(fd, row);
            while (!row.empty()) {
                ++amount;
                stud.setvardas(vardas);
                stud.setpavarde(pavarde);
                stringstream r(row);
                while (r >> grades)
                {
                    stud.getp().push_back(grades);
                }
                int e_val;
                fd >> e_val;
                stud.sete(e_val);
                info.push_back(stud);
                stud.getp().clear();
                getline(fd, row);
            }
            fd.close();
        }
        else {
            throw runtime_error("FAILAS NEATIDAROMAS");
        }
    }
    catch (const exception& e) {
        cerr << "KLAIDA: " << e.what() << endl;
    }
}


//funkcija, kuri veikia kai sugeneruotas failas egzistuoja
void printtxt(Vector<Student>& info, int amount, Student& stud, string ammount) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> pazymys(1, 10);
    vector<Student> kietiakaii;
    vector<Student> varguoliaii;
    string vardas, pavarde;
    char eil[100];
    int gradeam=0;
    int strategija;
    Vector <int> pazz;

    decltype(std::chrono::high_resolution_clock::now()) startrus;
    decltype(std::chrono::high_resolution_clock::now()) endrus;
    decltype(std::chrono::duration_cast<std::chrono::microseconds>(endrus - startrus)) durationrus;
    decltype(std::chrono::high_resolution_clock::now()) startsort;
    decltype(std::chrono::high_resolution_clock::now()) endsort;
    decltype(std::chrono::duration_cast<std::chrono::microseconds>(endsort - startsort)) durationsort; 
    decltype(std::chrono::high_resolution_clock::now()) startkiet;
    decltype(std::chrono::high_resolution_clock::now()) endkiet;
    decltype(std::chrono::duration_cast<std::chrono::microseconds>(endkiet - startkiet)) durationkiet;
    decltype(std::chrono::high_resolution_clock::now()) startvarg;
    decltype(std::chrono::high_resolution_clock::now()) endvarg;
    decltype(std::chrono::duration_cast<std::chrono::microseconds>(endvarg - startvarg)) durationvarg;

amount = stoi(ammount);
char x[100];
if (amount == 1000)     strncpy(x, CRP1fv, sizeof(x));
if (amount == 10000)    strncpy(x, CRP2fv, sizeof(x));
if (amount == 100000)   strncpy(x, CRP3fv, sizeof(x));
if (amount == 1000000)  strncpy(x, CRP4fv, sizeof(x));
if (amount == 10000000) strncpy(x, CRP5fv, sizeof(x));
    ifstream fq(x);
    fq >> vardas >> pavarde;
    string row;
    string w;
    getline(fq, row);
        stringstream r(row);
        while (r >> w)
        {
            gradeam++;
        }
        auto startnus = std::chrono::high_resolution_clock::now();
        while (getline(fq, row)) {
            amount++;
            stringstream ss(row);
            std::string vardas, pavarde;
            ss >> vardas >> pavarde;
            Student stud;
            stud.setvardas(vardas);
            stud.setpavarde(pavarde);
            for (int j = 1; j < gradeam; j++) {
    int pazz1;
    ss >> pazz1;
    pazz.push_back(pazz1);
}
    stud.setp(pazz);
    int e_val;
    ss >> e_val;
    stud.sete(e_val);
    Vector <int>grades = stud.getp();
    stud.setgal(aver(stud));
    stud.setmed(medi(stud));
    info.push_back(stud);
    pazz.clear();
    stud.getp().clear();
    }
    fq.close();
        auto endnus = std::chrono::high_resolution_clock::now();
        auto durationnus = std::chrono::duration_cast<std::chrono::microseconds>(endnus - startnus);

        ofstream fg(CRGfv); ofstream fk(CRKfv); ofstream fv(CRVfv);
        fg << fixed << setprecision(2);
        fg << fixed << setprecision(2);
        fg << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(5) << left << "Vid." << setw(5) << right << "Med." << endl;
        fg << setfill('-') << setw(60) << "" << setfill(' ') << endl;
        fk << fixed << setprecision(2);
        fk << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(5) << left << "Vid." << setw(5) << right << "Med." << endl;
        fk << setfill('-') << setw(60) << "" << setfill(' ') << endl;
        fv << fixed << setprecision(2);
        fv << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(5) << left << "Vid." << setw(5) << right << "Med." << endl;
        fv << setfill('-') << setw(60) << "" << setfill(' ') << endl;

        for (auto i : info) {
            fg << i;
        }

       startsort = std::chrono::high_resolution_clock::now();
       std::sort(info.begin(), info.end(), 
              [](const Student& first, const Student& scnd) -> bool {
                 return (first.getgal() < scnd.getgal());
              });
        endsort = std::chrono::high_resolution_clock::now();
        durationsort = std::chrono::duration_cast<std::chrono::microseconds>(endsort - startsort);

        cout << "Jei norite skirstyti studentus pagal pirma strategija spauskite 1, pagal antra - 2\nJusu pasirinkimas: ";
        cin >> strategija; cout << endl;
        while (cin.fail() || strategija < 1 || strategija > 2) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite norima strategija:  ";
            cin >> strategija;
        }
        cout << endl;
        if (strategija == 1) {
            startrus = std::chrono::high_resolution_clock::now();
            for (auto t = info.begin(); t != info.end(); ) {
                if (t->getgal() >= 5.00) {
                    kietiakaii.push_back(*t);
                     t = info.erase(t);
                }
                else {
                    varguoliaii.push_back(*t);
                     t = info.erase(t);
                }
            }
            endrus = std::chrono::high_resolution_clock::now();
            durationrus = std::chrono::duration_cast<std::chrono::microseconds>(endrus - startrus);

            startkiet = std::chrono::high_resolution_clock::now();
            for (auto i : kietiakaii) {
                fk << i;
            }
            endkiet = std::chrono::high_resolution_clock::now();
            durationkiet = std::chrono::duration_cast<std::chrono::microseconds>(endkiet - startkiet);

            startvarg = std::chrono::high_resolution_clock::now();
            for (auto i : varguoliaii) {
                fv << i;
            }
            endvarg = std::chrono::high_resolution_clock::now();
            durationvarg = std::chrono::duration_cast<std::chrono::microseconds>(endvarg - startvarg);

        }
        else {
            startrus = std::chrono::high_resolution_clock::now();
            ///*
            for (auto t = info.begin(); t != info.end(); ) {
                if (t->getgal()  < 5.00) {
                    varguoliaii.push_back(*t);
                    t = info.erase(t);
                }
                else {
                    ++t;
                }
            }
            //*/
             /*
             auto partition_it = std::partition(info.begin(), info.end(),
                [](const auto& i) { return i.avg * 0.4 + i.e * 0.6 < 5.00; });
            varguoliaii.insert(varguoliaii.end(), info.begin(), partition_it);
            info.erase(info.begin(), partition_it);
             */
            endrus = std::chrono::high_resolution_clock::now();
            durationrus = std::chrono::duration_cast<std::chrono::microseconds>(endrus - startrus);

            startkiet = std::chrono::high_resolution_clock::now();
            for (auto i : info) {
                fk << i;
            }
            endkiet = std::chrono::high_resolution_clock::now();
            durationkiet = std::chrono::duration_cast<std::chrono::microseconds>(endkiet - startkiet);

            startvarg = std::chrono::high_resolution_clock::now();
            for (auto i : varguoliaii) {
              fv << i;
            }
            endvarg = std::chrono::high_resolution_clock::now();
            durationvarg = std::chrono::duration_cast<std::chrono::microseconds>(endvarg - startvarg);
        }     
        cout << endl;
        cout << left << "FAILO NUSKAITYMO TRUKME:       " << left << durationnus.count() / 1000000.0 << " seconds. " << endl;
        cout << left << "FAILO RUSIAVIMO TRUKME:        " << left << durationsort.count() / 1000000.0 << " seconds. " << endl;
        cout << left << "FAILO SKIRSTYMO TRUKME:        " << left << durationrus.count() / 1000000.0 << " seconds. " << endl;
       //cout << left << "KIETIAKU IRASYMO TRUKME:       " << left << durationkiet.count() / 1000000.0 << " seconds. " << endl;
       //cout << left << "VARGUOLIU IRASYMO TRUKME:      " << left << durationvarg.count() / 1000000.0 << " seconds. " << endl;
        cout << left << "\nBENDRA TRUKME:                 " << left << durationnus.count() / 1000000.0 + durationsort.count() / 1000000.0 + durationrus.count() / 1000000.0 << " seconds. " << endl;
        cout << endl;

        fv.close(); fk.close(); fg.close();
        info.clear();
        kietiakaii.clear();
        varguoliaii.clear();
        
}

//funkcija, kuri veikia kai sugeneruoto failo nera
void printPGtxt(Vector<Student>& info, int amount, Student& stud, string ammount) {
    // nuo cia iki pazymetos vietos generuoja failus ok krc nafik
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> pazymys(1, 10);
    Vector<Student> kietiakaii;
    Vector<Student> varguoliaii;
    int gradeam, strategija;

    decltype(std::chrono::high_resolution_clock::now()) startrus;
    decltype(std::chrono::high_resolution_clock::now()) endrus;
    decltype(std::chrono::duration_cast<std::chrono::microseconds>(endrus - startrus)) durationrus;
    decltype(std::chrono::high_resolution_clock::now()) startkiet;
    decltype(std::chrono::high_resolution_clock::now()) endkiet;
    decltype(std::chrono::duration_cast<std::chrono::microseconds>(endkiet - startkiet)) durationkiet;
    decltype(std::chrono::high_resolution_clock::now()) startvarg;
    decltype(std::chrono::high_resolution_clock::now()) endvarg;
    decltype(std::chrono::duration_cast<std::chrono::microseconds>(endvarg - startvarg)) durationvarg;
  
    char eil[100];
    cout << "Kiek pazymiu turetu tureti studentas (1-100):  ";
    cin >> gradeam;
    while (cin.fail() || gradeam <= 0 || gradeam > 100) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Iveskite pazymiu kieki tarp 1-100:  ";
        cin >> gradeam;
    }
    cout << endl;
   
    amount = stoi(ammount);
    char x[100];
if (amount == 1000)     strncpy(x, CRP1fv, sizeof(x));
if (amount == 10000)    strncpy(x, CRP2fv, sizeof(x));
if (amount == 100000)   strncpy(x, CRP3fv, sizeof(x));
if (amount == 1000000)  strncpy(x, CRP4fv, sizeof(x));
if (amount == 10000000) strncpy(x, CRP5fv, sizeof(x));
   
    auto startkur = std::chrono::high_resolution_clock::now();
    ofstream fr(x);
    auto endkur = std::chrono::high_resolution_clock::now();
    auto durationkur = std::chrono::duration_cast<std::chrono::microseconds>(endkur - startkur); cout << endl;
    fr << left << setw(21) << "Vardas" << setw(21) << "Pavarde";
    for (int i = 1; i < gradeam + 1; i++) {
        fr << left << "PAZ" << setw(3) << i << "   ";
    }
    fr << setw(3) << "Egz." << endl;

    for (int i = 1; i <= amount; i++) {
        fr << left << "Vardas" << setw(15) << i << "Pavarde" << setw(15) << i;
        for (int j = 0; j < gradeam; j++) {
            fr << left << setw(9) << pazymys(gen);
        }
        fr << left << setw(6) << pazymys(gen) << endl;

    }
    fr.close();

   auto startnus = std::chrono::high_resolution_clock::now();
ifstream fq(x);
string line;
getline(fq, line);
for (int i = 0; i < amount; i++) {
  Student stud;
  string name, lname;
  Vector <int>grd;
  int exam;
    fq >> name >> lname;
    stud.setvardas(name);
    stud.setpavarde(lname);
    for (int j = 0; j < gradeam; j++) {
        int pazz;
        fq >> pazz;
        grd.push_back(pazz);
    }
    stud.setp(grd);
    fq >> exam;
    stud.sete(exam);
    stud.setgal(aver(stud));
    stud.setmed(medi(stud));
    info.push_back(stud);
    stud.getp().clear();
    grd.clear();
}
    fq.close();
    auto endnus = std::chrono::high_resolution_clock::now();
    auto durationnus = std::chrono::duration_cast<std::chrono::microseconds>(endnus - startnus);

    ofstream fg(CRGfv); ofstream fk(CRKfv); ofstream fv(CRVfv);
    fg << fixed << setprecision(2);
    fg << fixed << setprecision(2);
    fg << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(5) << left << "Vid." << setw(5) << right << "Med." << endl;
    fg << setfill('-') << setw(60) << "" << setfill(' ') << endl;
    fk << fixed << setprecision(2);
    fk << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(5) << left << "Vid." << setw(5) << right << "Med." << endl;
    fk << setfill('-') << setw(60) << "" << setfill(' ') << endl;
    fv << fixed << setprecision(2);
    fv << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(5) << left << "Vid." << setw(5) << right << "Med." << endl;
    fv << setfill('-') << setw(60) << "" << setfill(' ') << endl;

    for (auto i : info) {
        cout << i;
    }
   

    auto startsort = std::chrono::high_resolution_clock::now();
  
    sort(info.begin(), info.end(), compV);
   
    auto endsort = std::chrono::high_resolution_clock::now();
    auto durationsort = std::chrono::duration_cast<std::chrono::microseconds>(endsort - startsort);


    cout << "Jei norite skirstyti studentus pagal pirma strategija spauskite 1, pagal antra - 2\nJusu pasirinkimas: ";
    cin >> strategija; 
    cout << endl;
    while (cin.fail() || strategija < 1 || strategija > 2) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Iveskite norima strategija:  ";
        cin >> strategija;
    }
    cout << endl;
    if (strategija == 1) {
        startrus = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < amount; i++) {
            if (info[i].getgal() >= 5.00) {
                kietiakaii.push_back(info[i]);
            }
            else {
                varguoliaii.push_back(info[i]);
            }
        }
        endrus = std::chrono::high_resolution_clock::now();
        durationrus = std::chrono::duration_cast<std::chrono::microseconds>(endrus - startrus);

        startkiet = std::chrono::high_resolution_clock::now();
        for (auto i : kietiakaii) {
            fk << i;
        }
        endkiet = std::chrono::high_resolution_clock::now();
        durationkiet = std::chrono::duration_cast<std::chrono::microseconds>(endkiet - startkiet);

        startvarg = std::chrono::high_resolution_clock::now();
        for (auto i : varguoliaii) {
            fv << i;
        }
        endvarg = std::chrono::high_resolution_clock::now();
        durationvarg = std::chrono::duration_cast<std::chrono::microseconds>(endvarg - startvarg);

    }
    else {
        startrus = std::chrono::high_resolution_clock::now();
        /*
        for (auto t = info.begin(); t != info.end(); ) {
            if (t->avg * 0.4 + t->e * 0.6 < 5.00) {
                varguoliaii.push_back(*t);
                t = info.erase(t);
            }
            else {
                ++t;
            }
        }
        */
        auto partition_it = std::partition(info.begin(), info.end(),
            [](const auto& i) { return i.getgal() < 5.00; });
        varguoliaii.insert(varguoliaii.end(), info.begin(), partition_it);
        info.erase(info.begin(), partition_it);
            endrus = std::chrono::high_resolution_clock::now();
            durationrus = std::chrono::duration_cast<std::chrono::microseconds>(endrus - startrus);
    
            startkiet = std::chrono::high_resolution_clock::now();
            for (auto i : info) {
                fk << i;
            }
            endkiet = std::chrono::high_resolution_clock::now();
            durationkiet = std::chrono::duration_cast<std::chrono::microseconds>(endkiet - startkiet);

            startvarg = std::chrono::high_resolution_clock::now();
            for (auto i : varguoliaii) {
                fv << i;
            }
            endvarg = std::chrono::high_resolution_clock::now();
            durationvarg = std::chrono::duration_cast<std::chrono::microseconds>(endvarg - startvarg);
    }


    cout << endl;
    cout << left << "FAILO SUKURIMO TRUKME:         " << left << durationkur.count() / 1000000.0 << " seconds. " << endl;
    cout << left << "FAILO NUSKAITYMO TRUKME:       " << left << durationnus.count() / 1000000.0 << " seconds. " << endl;
    cout << left << "FAILO RUSIAVIMO TRUKME:        " << left << durationsort.count() / 1000000.0 << " seconds. " << endl;
    cout << left << "FAILO SKIRSTYMO TRUKME:        " << left << durationrus.count() / 1000000.0 << " seconds. " << endl;
    cout << left << "KIETIAKU IRASYMO TRUKME:       " << left << durationkiet.count() / 1000000.0 << " seconds. " << endl;
    cout << left << "VARGUOLIU IRASYMO TRUKME:      " << left << durationvarg.count() / 1000000.0 << " seconds. " << endl;
    cout << left << "\nBENDRA TRUKME:                 " << left << durationkur.count() / 1000000.0 + durationnus.count() / 1000000.0 + durationsort.count() / 1000000.0 + durationrus.count() / 1000000.0 << " seconds. " << endl;

    cout << endl;

    fv.close(); fk.close(); fg.close();
    info.clear();
    kietiakaii.clear();
    varguoliaii.clear();
}


