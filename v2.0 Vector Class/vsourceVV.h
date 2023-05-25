#include "vectorclass.h"

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

class Human {
protected:
    std::string vardas, pavarde;

public:
    virtual ~Human() {}
    virtual std::string getvardas() const  = 0;
    virtual std::string getpavarde() const  = 0;
};

class Student : public Human {
private:
    Vector <int> p;
    double e;
    double gal;
    double med;

public:
    Student() : e(0) {}
    Student(std::istream& is);

    void setvardas(std::string vardas_) { vardas = vardas_; }
    void setpavarde(std::string pavarde_) { pavarde = pavarde_; }
    void setp(Vector <int> p_) { p = p_; }
    void sete(double e_) { e = e_; }
    void setgal(double gal_) { gal = gal_; }
    void setmed(double med_) { med = med_; }

    std::string getvardas() const override { return vardas; }
    std::string getpavarde() const override { return pavarde; }

    Vector <int> getp() const { return p; } 
    double gete() const { return e; } 
    double getgal() const { return gal; }
    double getmed() const { return med; }
    ~Student() {p.clear();}
  
    // copy constructor
    Student(const Student& n) {
        vardas = n.vardas;
        pavarde = n.pavarde;
        p = n.p;
        e = n.e;
        gal = n.gal;
        med = n.med;
    }

    // copy assignment
    Student& operator=(const Student& n) {
        if (this != &n) {
            vardas = n.vardas;
            pavarde = n.pavarde;
            p = n.p;
            e = n.e;
            gal = n.gal;
            med = n.med;
        }
        return *this;
    }

    // move constructor
    Student(Student&& n) noexcept {
        vardas = std::move(n.vardas);
        pavarde = std::move(n.pavarde);
        p = std::move(n.p);
        e = n.e;
        gal = n.gal;
        med = n.med;
    }

    // move assignment
    Student& operator=(Student&& n) noexcept {
        if (this != &n) {
            vardas = std::move(n.vardas);
            pavarde = std::move(n.pavarde);
            p = std::move(n.p);
            e = n.e;
            gal = n.gal;
            med = n.med;
        }
        return *this;
    }

    // student info printing
    friend std::ostream& operator<<(std::ostream& ff, const Student& a) {
        ff << std::left << std::setw(20) << a.getvardas()
        << std::setw(20) << a.getpavarde()
        << std::setw(6) << std::fixed << std::setprecision(2) << a.getgal()
        << std::setw(6) << std::fixed << std::setprecision(2) << a.getmed() << '\n';
        return ff;
    }

    // friend functions for computing the average and median
    friend double aver(const Student&);
    friend double medi(const Student&);
};

void TestFunc5();
void code ();
bool FileExists(const std::string& Filename);
void addstudent(Vector <Student>& students, Student& stud);
void addgrade(Vector <int>& p);
double getavg(const Vector <int>& p);
double getmedian(const Vector <int>& p);
void scan(Vector <Student>& info, int amount, Student& stud);
void print(const Vector <Student>& students); 
void printPGtxt(Vector <Student>& info, int amount, Student& stud, string ammount);
void printtxt(Vector <Student>& info, int amount, Student& stud, string ammount);
bool compN(const Student& first, const Student& scnd);
bool compV(const Student& first, const Student& scnd);
