#include "studentlib.h"

struct student {
    string vardas = "";
    string pavarde = "";
    vector<int> p;
    int e = 0;
    double avg = 0, median = 0;
};

void addstudent(vector<student>& students);
void addgrade(vector<int>& p);
double getavg(const vector<int>& p);
double getmedian(const vector<int>& p);
void print(const vector<student>& students);

int main() {
    vector<student> students;
    char q = '0';

    do {
        addstudent(students);
        cout << endl;
        cout << "Spauskite n klavisa, jei norite tikrai baigti darba. Kitu atveju spustelkite kitoki klavisa. | ";
        cin >> q;
        cout << endl << endl;
        if (q == 'N' || q == 'n') {
            cout << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Vidurkis" << setw(15) << "Mediana" << endl;
            cout << "-------------------------------------------------------------------------------------------------------\n";
        }
    } while (q != 'N' && q != 'n');

    print(students);

    return 0;
}

void addstudent(vector<student>& students) {
    student info;
    int query; int n = 0;
    cout << "Iveskite studento varda bei pavarde: ";
    cin >> info.vardas >> info.pavarde;

    while (!all_of(info.vardas.begin(), info.vardas.end(), isalpha) || !all_of(info.pavarde.begin(), info.pavarde.end(), isalpha)) {
        cout << "SUKLYDOTE! VARDAS TURI TURETI TIK RAIDES. BANDYKITE DAR KARTA.\n";
        cout << "Iveskite studento varda bei pavarde: ";
        cin >> info.vardas >> info.pavarde;
    }

    cout << "Iveskite studento namu darbu pazymius intervale 1-10. Kiekvienas pazymys vedamas is naujos eilutes." << endl;
    addgrade(info.p);

    cout << "Iveskite studento egzamino pazymi intervale 1-10: ";
    cin >> info.e;

    while (info.e < 1 || info.e > 10 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "SUKLYDOTE! EGZAMINO REZULTATAS TURI BUTI SKAICIUS INTERVALE 1-10. BANDYKITE DAR KARTA: ";
        cin >> info.e;
    }
    cout << "Kokius duomenis naudojant turetu buti isvedami rezultatai?" << endl;
    cout << "Jei ranka rasykite 1, jei atsistiktinai - 2" << endl;
    cout << "Jusu pasirinkimas: ";
    cin >> query;
    while (query != 1 && query != 2 || cin.fail())
    {
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
        for (int i = 0; i < info.p.size(); i++) {
            info.p[i] = dist(gen);
            cout << info.p[i] << " ";
        }

        cout << endl;
        info.e = dist(gen);
        cout << "Atsitiktinai sugeneruotas studento egzamino pazymys: " << info.e;
        cout << endl;
    }

    info.avg = getavg(info.p);
    info.median = getmedian(info.p);

    students.push_back(info);
}

void addgrade(vector<int>& p) {
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

double getavg(const vector<int>& p) {
    int suma = 0;
    for (auto i : p) {
        suma += i;
    }
    return (double)suma / p.size();
}

double getmedian(const vector<int>& p) {
    vector<int> sortedp = p;
    sort(sortedp.begin(), sortedp.end());
    if (sortedp.size() % 2 == 0) {
        int vid = sortedp.size() / 2;
        return (double)(sortedp[vid - 1] + sortedp[vid]) / 2;
    }
    else {
        return (double)sortedp[sortedp.size() / 2];
    }
}

void print(const vector<student>& students) {
    cout << fixed << setprecision(2);
    for (auto i : students) {
        cout << i.vardas << setw(15) << i.pavarde << setw(15) << i.avg * 0.4 + i.e * 0.6 << setw(15) << i.median * 0.4 + i.e * 0.6 << endl;
    }
}
