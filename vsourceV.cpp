#include "studentlib.h"
char CDfv[] =  "kursiokai.txt";
char CRPfv[] = "studentai.txt";
char CRP1fv[] = "studentai1000.txt";
char CRP2fv[] = "studentai10000.txt";
char CRP3fv[] = "studentai100000.txt";
char CRP4fv[] = "studentai1000000.txt";
char CRP5fv[] = "studentai10000000.txt";
char CRGfv[] = "studentugalutiniai.txt";
char CRKfv[] = "kietiakai.txt";
char CRVfv[] = "varguoliai.txt";

class Student {
private:
    string vardas, pavarde;
    vector<int> p;
    double e;
    double gal;
    double med;
public:
    Student() : e(0) {}
    Student(std::istream& is);
//
    void setvardas(string vardas_) { vardas = vardas_; }
    void setpavarde(string pavarde_) { pavarde = pavarde_; }
    void setp(vector<int> paz_) { p = paz_; }
    void sete(double egz_) { e = egz_; }
    void setgal(double gal_) { gal = gal_; }
    void setmed(double med_) { med = med_; }

    string getvardas() const { return vardas; }
    string getpavarde() const { return pavarde; }
    vector<int> getp() const { return p; } 
    double gete() const { return e; } 
    double getgal() const { return gal; }
    double getmed() const { return med; }
    ~Student() {p.clear();}
    //
    std::istream& readStudent(std::istream&);

    // friend functions for computing the average and median
    friend double aver(const Student&);
    friend double medi(const Student&);
};
bool FileExists(const std::string& Filename);
void addstudent(vector<Student>& students, Student& stud);
void addgrade(vector<int>& p);
double getavg(const vector<int>& p);
double getmedian(const vector<int>& p);
void scan(vector<Student>& info, int amount, Student& stud);
void print(const vector<Student>& students); 
void printPGtxt(vector<Student>& info, int amount, Student& stud, string ammount);
void printtxt(vector<Student>& info, int amount, Student& stud, string ammount);
bool compN(const Student& first, const Student& scnd);
bool compV(const Student& first, const Student& scnd);