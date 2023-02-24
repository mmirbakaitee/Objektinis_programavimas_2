#include "studentlib.h"

struct student {
    string vardas = "";
    string pavarde = "";

    int* p = 0; // PAZYMYS
    int  e = 0;       // EGZAMINAS
    double median, avg;


};

struct studentcount {
    student* student;
    int lenght;
};

void data(student* info);
void print(student* info, int n);
void addpeople(student*& arr, int size);
void add(int*& arr, int size);
double getAverage(int* arr, int size, student* info);
double getMedian(student* info);


int main() {
    int n = 0;
    char q = '0';
    studentcount people;
    do {
        if (n == 0) {
            people.student = new student[1];
            n++;
            people.lenght = n;
            data(&people.student[0]);
        }
        else {
            n++;
            addpeople(people.student, n);
            data(&people.student[n - 1]);
        }
        if (people.student[n - 1].p == 0) {
            cout << "SUKLYDOTE! IVESTAS NAMU DARBU PAZYMYS PRIVALO BUTI 1-10. BANDYKITE IS NAUJO" << endl;
            data(&people.student[n - 1]);
        }
        people.lenght = n;
        cout << "Spauskite n klavisa, jei norite tikrai baigti darba. Kitu atveju spustelkite kitoki klavisa. | ";
        cin >> q;
        cout << endl;
        cout << endl; cout << endl;
        if (q == 'N' || q == 'n')
        {
            cout << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Vidurkis" << setw(15) << "Mediana" << endl;
            cout << "-------------------------------------------------------------------------------------------------------";
        }
    } while (q != 'N' && q != 'n');
    for (int i = 0; i < n; i++)
        print(&people.student[i], n);
}


void addpeople(student*& arr, int size) {
    student* mas = new student[size];
    for (int i = 0; i < size - 1; i++) {
        mas[i] = arr[i];
    }
    delete[] arr;
    arr = mas;
}


void add(int*& arr, int size) {
    int* mas = new int[size];
    for (int i = 0; i < size - 1; i++) {
        mas[i] = arr[i];
    }
    delete[] arr;
    arr = mas;
}


void data(student* info) {
    int query;
    cout << "Iveskite studento varda bei pavarde: ";
    cin >> info->vardas >> info->pavarde;
    while (!all_of(info->vardas.begin(), info->vardas.end(), isalpha) || !all_of(info->pavarde.begin(), info->pavarde.end(), isalpha)) {
        cout << "SUKLYDOTE! VARDAS TURI TURETI TIK RAIDES. BANDYKITE DAR KARTA.\n";
        cout << "Iveskite studento varda bei pavarde: ";
        cin >> info->vardas >> info->pavarde;

    }
    cin.clear();
    std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    int r, sum = 0;
    int n = 0;
    info->p;
    cout << endl;
    cout << "Iveskite studento namu darbu pazymius intervale 1-10. Kiekvienas pazymys vedamas is naujos eilutes." << endl;
    cout << "Pirmas ivestas simbolis privalo buti skaicius. Baige darba spustelkite bet kokia raide. PRADEKITE:" << endl;
    while (cin >> r) {

        if (n == 0) {
            info->p = new int[1];
            info->p[0] = r;
            sum += r;
            n++;
        }
        else {
            sum += r;
            n++;
            add(info->p, n);
            info->p[n - 1] = r;
        }
        if (r < 1 || r > 10 || cin.fail()) {
            cout << "SUKLYDOTE! PAZYMYS TURI BUTI SKAICIUS INTERVALE 1-10. BANDYKITE DAR KARTA: ";
            cin >> r;
        }
    }
    cin.clear();
    std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

    cout << "Iveskite studento egzamino pazymi intervale 1-10: ";
    cin >> info->e;
    while (info->e < 1 || info->e > 10 || cin.fail()) {
        cin.clear();
        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "SUKLYDOTE! EGZAMINO REZULTATAS TURI BUTI SKAICIUS INTERVALE 1-10. BANDYKITE DAR KARTA: ";
        cin >> info->e;
    }
    cin.clear();
    std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout << endl;

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
        for (int i = 0; i < n; i++) {
            info->p[i] = dist(gen);
            cout << info->p[i] << " ";
        }
        cout << endl;
        info->e = dist(gen);
        cout << "Atsitiktinai sugeneruotas studento egzamino pazymys: " << info->e;
        cout << endl;
    }

    cin.clear();
    std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

    cout << endl;
    cout << "Valio! Studento duomenys irasyti sekmingai!" << endl;
}


double getAverage(int* arr, int size, student* info) {
    int n = 0;
    double sum = 0;
    while (info->p[n] >= 0 && info->p[n] <= 10)
    {
        n++;
    }
    for (int i = 0; i < n; i++)
    {
        sum = sum + info->p[i];
    }
    double k = double(sum / n);
    return k * 0.4 + info->e * 0.6;
}


double getMedian(student* info) {
    int n = 0;
    while (info->p[n] >= 0 && info->p[n] <= 10)
        n++;
    sort(info->p, info->p + n);
    if (n % 2 == 0) {
        return 0.4 * ((info->p[n / 2 - 1] + info->p[n / 2]) / 2.0) + info->e * 0.6;
    }
    else {
        return 0.4 * (info->p[n / 2]) + info->e * 0.6;
    }
}


void print(student* info, int n) {
    cout << endl;
    cout << info->vardas << setw(15) << info->pavarde;
    cout << setw(15) << fixed << setprecision(2) << getAverage(info->p, n, info);
    cout << setw(15) << fixed << setprecision(2) << getMedian(info);
    double s = 0;
    cout << endl;
    delete[] info->p;
}

