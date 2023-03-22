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

struct student {
    string vardas = "";
    string pavarde = "";
    list<int> p;
    int e = 0;
    double avg = 0, median = 0;
};

bool FileExists(const std::string& Filename);
void addstudent(list<student>& students, student& stud);
void addgrade(list<int>& p);
double getavg(const list<int>& p);
double getmedian(const list<int>& p);
void scan(list<student>& info, int amount, student& stud);
void print(const list<student>& students); 
void printPGtxt(list<student>& info, int amount, student& stud, string ammount);
void printtxt(list<student>& info, int amount, student& stud, string ammount);
bool compN(const student& first, const student& scnd);
bool compV(const student& first, const student& scnd);