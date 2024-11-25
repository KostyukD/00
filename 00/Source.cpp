#include <iostream>
#include <cstring>

using namespace std;


class Employer 
{
public:
    virtual void Print() const = 0;
};


class President : public Employer 
{
private:
    char* name;
public:
    President(const char* n) 
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    ~President() 
    {
        delete[] name;
    }

    void Print() const override
    {
        cout << "President Name: " << name << endl;
    }
};


class Manager : public Employer 
{
private:
    char* department;
public:
    Manager(const char* d) 
    {
        department = new char[strlen(d) + 1];
        strcpy(department, d);
    }

    ~Manager()
    {
        delete[] department;
    }

    void Print() const override 
    {
        cout << "Manager Department: " << department << endl;
    }
};


class Worker : public Employer 
{
private:
    char* position;
public:
    Worker(const char* p) 
    {
        position = new char[strlen(p) + 1];
        strcpy(position, p);
    }

    ~Worker() {
        delete[] position;
    }

    void Print() const override 
    {
        cout << "Worker Position: " << position << endl;
    }
};

int main()
{

    President pres("John Doe");
    Manager mgr("Sales");
    Worker wrk("Technician");


    Employer* employees[] = { &pres, &mgr, &wrk };


    for (int i = 0; i < 3; ++i) {
        employees[i]->Print();
    }
}
