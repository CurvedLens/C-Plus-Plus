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
    Student(int year, string Nm, string Sn){
        Course = year;
        Human(Nm, Sn);
    };
    Student(){
        Course = 1900;
        Human();
    }
    void Print(){
        cout<<"Course is "<<Course<<endl;
        Howdoyoudo();
    };
};

class Publication
{
private:
    Student Au;
    Achievement Ac; 
public:
    Publication(int year, string Nm, string Sn, Achievement Pub):Au(year, Nm, Sn), Ac(Pub){
        cout << "Publication constructor called"<<endl;
    };

    void Print(){
        cout<<"Publication "<<endl;
        Au.Print();
        cout <<"Achievment "<<Ac<<endl;
    };

    int GetAcj(){
    return Ac;
    };
};




int main(){
    Publication Mc(25, "Albert", "Einstein", Thesis);
    Mc.Print();
}