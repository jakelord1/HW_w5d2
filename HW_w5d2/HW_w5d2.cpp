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

    char* GetName() {
        return name;
    }
    char* GetUniv() {
        return university;
    }
    int GetAge() {
        return age;
    }
    void SetName(const char* inp) {
        name = new char[strlen(inp) + 1];
        strcpy_s(name, strlen(inp) + 1, inp);
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


int main()
{
    Student obj("Irina", 18, "ITStep");
    obj.Print();
    obj.Input("Vasiliy");
    obj.Print();
}