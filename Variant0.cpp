#include <iostream>
#include <string>

using namespace std;
enum Achievement{
    Thesis,
    Article_in_special_magazine,
    Report_world_conference,
    Report_world_magazine
};

class Human
{
private:
    // Date Birthsday; 
    string Name;
    string Surname;
public:
    Human(){
        cout << "Constructor without parameters\n";
        // Birthsday = '01.01.2001'
        Name = "John";
        Surname = "Smith";
    }
    Human(string UserName, string UserSurname){
        cout << "Constructor with parameters\n";
        Name = UserName;
        Surname = UserSurname;
    }
    Human(const Human &Example){
        cout << "Copy constructor\n";
        Name = Example.Name;
        Surname = Example.Surname;
    }
    ~Human(){
        cout <<"Destructor Worked\n";
    }

    string HumanNameGet(){
        return Name;
    }
    string HumanSurnameGet(){
        return Surname;
    }

    void Howdoyoudo(){
        cout <<"My name is "<<Name<<endl;
        cout <<"My Surnmane is "<<Surname<<endl;
    }

    void HumanNameSet(string Nm){
        Name = Nm;
    }
    void HumanSurnameSet(string Sn){
        Surname = Sn;
    }
};

class Student: public Human
{
private:
    int Course; 
public:
    Student(/* args */);
    ~Student();
};

Student::Student(/* args */)
{
}

Student::~Student()
{
}



int main(){
    Human t1;
    Human t2("Mark", "Hopp");
    Human t3(t2);
    //t1 and t2 changed 
    t1.HumanSurnameSet("ChSmiths");
    t3.HumanNameSet("Antonio");
    t1.Howdoyoudo();
    t2.Howdoyoudo();
    t3.Howdoyoudo();
}