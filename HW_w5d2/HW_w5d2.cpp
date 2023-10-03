#include<iostream>
using namespace std;

class Person
{
protected:
    char* name;
    int age;
public:
    Person() = default;
    Person(const char* n, int a) :age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        //cout << "Person Constructor\n";
    }
    char* GetName() {
        return name;
    }
    int GetAge() {
        return age;
    }
    void SetName(const char* inp) {
        name = new char[strlen(inp) + 1];
        strcpy_s(name, strlen(inp) + 1, inp);
    }
    void SetAge(int a) {
        age = a;
    }

    void Print()
    {
        cout << "Name: " << name << "\tAge: " << age << "\t";
    }
    void Input()
    {
        char buff[20];
        cout << "Enter Name: ";
        cin.getline(buff, 20);
        name = new char[strlen(buff) + 1];
        strcpy_s(name, strlen(buff) + 1, buff);
        cout << "Enter age: ";
        cin >> age;
    }
    ~Person()
    {
        delete[]name;
        //cout << "Person Destructor\n";
    }
};

class Student : public Person
{
    //char* name;
    //int age;
    char* university;
public:
    Student() = default;
    Student(const char* n, int a, const char* Univer) :Person(n, a) {
        university = new char[strlen(Univer) + 1];
        strcpy_s(university, strlen(Univer) + 1, Univer);
        //cout << "Person Constructor\n";
    }
    ~Student() {
        delete[] university;
        //cout << "Student Destructor\n";
    }

    char* GetUniv() {
        return university;
    }
    void SetUniv(const char* inp) {
        university = new char[strlen(inp) + 1];
        strcpy_s(university, strlen(inp) + 1, inp);
    }

    void Input(const char* Univer)
    {
        delete[] university;
        university = new char[strlen(Univer) + 1];
        strcpy_s(university, strlen(Univer) + 1, Univer);

        Person::Input();
    }

    void Print()
    {
        //cout << "Name: " << name << "\tAge: " << age << "\t";
        Person::Print();
        cout << "University: " << university << endl;
    }
};

class Teacher : public Person {
    string school;
    double payment;
    string classes[5];
public:
    Teacher() = default;
    Teacher(const char* n, int a, string sc, double p, string s[5]) : Person(n, a) {
        school = sc;
        payment = p;
        for (size_t i = 0; i < 5; i++)
        {
            classes[i] = s[i];
        }
    }

    void SetSchool(string s) {
        school = s;
    }
    void SetPayment(double s) {
        payment = s;
    }
    void SetClasses(string s[5]) {
        for (size_t i = 0; i < 5; i++)
        {
            classes[i] = s[i];
        }
    }
    string GetSchool() {
        return school;
    }
    double GetPayment() {
        return payment;
    }
    string* GetClasses() {
        return classes;
    }

    void Input(string s, double p, string c[5]) {
        school = s;
        payment = p;
        for (size_t i = 0; i < 5; i++)
        {
            classes[i] = c[i];
        }
        Person::Input();
    }
    
    void Print() {
        Person::Print();
        cout << "\nSchool: " << school << "\tPayment: " << payment << "$\tClasses: ";
        for (size_t i = 0; i < 5; i++)
        {
            cout << classes[i] << '\t';
        }
    }
};

class Driver : public Person {
    int docum;
    string color;
public:
    Driver() = default;
    Driver(const char* n, int a, string col, int d) : Person(n, a) {
        color = col;;
        docum = d;
    }

    void SetColor(string s) {
        color = s;
    }
    void SetDocumentNum(int s) {
        docum = s;
    }
    
    string GetColor() {
        return color;
    }
    double GetDocumentNum() {
        return docum;
    }

    void Input(string s, int p) {
        color = s;
        docum = p;
        
        Person::Input();
    }

    void Print() {
        Person::Print();
        cout << "\nColor of car: " << color << "\tDocument num: " << docum << endl;
    }
};

class Doctor : public Person {
    bool isFamilyDoc;
    int exp;
    string spec;
public:
    Doctor() = default;
    Doctor(const char* n, int a, string sp, int ex, bool f) : Person(n, a) {
        spec = sp;
        exp = ex;
        isFamilyDoc = f;
    }

    void SetSpecialization(string s) {
        spec = s;
    }
    void SetExpierence(int s) {
        exp = s;
    }
    void SetFamilyDoc(bool f) {
        isFamilyDoc = f;
    }

    string GetSpecialization() {
        return spec;
    }
    double GetExpierence() {
        return exp;
    }
    bool GetFamilyDoc() {
        return isFamilyDoc;
    }

    void Input(string s, int ex, bool f) {
        spec = s;
        exp = ex;
        isFamilyDoc = f;

        Person::Input();
    }

    void Print() {
        Person::Print();
        cout << "\nSpecialization: " << spec << "\tWorking expierence: " << exp << "\nIs family doctor: " << isFamilyDoc << endl;
    }
};

int main()
{
    Student obj("Mia", 19, "ITStep");
    obj.Print();

    string scd[5] = { "science", "computers", "driver wifia", "-", "-" };
    Teacher t("Johny", 30, "Itstep", 10000, scd);
    t.Print();

    Driver dr("Johny", 30, "black", 15794);
    dr.Print();

    Doctor doc("Johny", 30, "Hinecolog", 7, true);
    doc.Print();
}