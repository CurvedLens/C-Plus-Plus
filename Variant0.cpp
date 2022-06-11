#include <iostream>
#include <string>
#include <deque>

using namespace std;
enum Achievement{
    Thesis,
    Article_in_special_magazine,
    Report_world_conference,
    Report_world_magazine
};

class Date // According to tasks, should have been already defined, so we define it only partially
{
private:
    int Year;
    int Month;
    int Day;
public:
    Date(int Y, int M, int D):Year(Y), Month(M), Day(D)
    {
        cout << "\t Date Constructor Worked";
    };
    Date(): Year(2000), Month(6), Day(15){
        cout << "\t Default Constructor Worked";
    };
    void Print(){
        cout<<"Year is "<<Year<<" Mounth is "<<Month<<" Day is "<<Day;
    }
    bool operator < (const Date obj1){
        cout << "Operator Called"<<endl;
        if(Year>obj1.Year){
            return 0;
        }
        else
        {
           if(Year<obj1.Year){
            return 1;
        }
            if(Month>obj1.Month){
            return 0;
        }
            else
            {
            if(Month<obj1.Month){
            return 1;
            }
            if(Day>=obj1.Day)
                return 0;
            }
                return 1;
            
        
        }
        
    }
};


class Human
{
protected:
    Date Birthsday; 
    string Name;
    string Surname;
public:
    Human(){
        cout << "\tConstructor without parameters\n";
        Birthsday = Date(2001, 1,1);
        Name = "John";
        Surname = "Smith";
    }
    Human(string UserName, string UserSurname, int Y = 2001, int M = 1, int D = 1){
        cout << "\tJuman: Constructor with Parameters Worked\n";
        Birthsday = Date(Y,M,D);
        Name = UserName;
        Surname = UserSurname;
    }
    Human(const Human &Example){
        cout << "\tCopy constructor\n";
        Name = Example.Name;
        Surname = Example.Surname;
    }
    ~Human(){
        cout <<"\tDestructor Worked\n";
    }

    string HumanNameGet(){return Name;}
    string HumanSurnameGet(){return Surname;}
    Date HumanBirthsdaySet(){return Birthsday;};

    void Howdoyoudo(){
        cout <<"My name is "<<Name<<endl;
        cout <<"My Surnmane is "<<Surname<<endl;
        Birthsday.Print();
    }
    void HumanNameSet(string Nm){Name = Nm;};
    void HumanSurnameSet(string Sn){Surname = Sn;};
    void HumanDateSet(Date t){Birthsday = t;};
};

class Student: public Human
{
private:
    int Course; 
public:

    void SetCourse(int t){Course = t;};
    int GetGourse(){return Course;};

    Student(int year, string Nm, string Sn, int Y, int M, int D):Human(Nm, Sn, Y, M, D), Course(year){
        cout <<"\tStudent: Constructor with Parameters Worked"<<endl;
    };
    Student(){
        Course = 1;
    }
    void Print(){
        cout<<"Course is "<<Course<<endl;
        Howdoyoudo();
    };
    ~Student(){
        cout <<"Destructor for Student Worked"<<endl;
    }
    Student(const Student &obj1){
        Course = obj1.Course;
        Birthsday = obj1.Birthsday;
        Name = obj1.Name;
        Surname = obj1.Surname;
    }
};

class Publication
{
private:
    Date Cr;
    Student Au;
    Achievement Ac; 
public:
    Publication(int year, string Nm, string Sn, Achievement Pub, int Y, int M, int D,int Y1, int M1, int D1):Au(year, Nm, Sn, Y1, M1, D1), Ac(Pub), Cr(Y, M, D){
        cout << "Publication constructor called"<<endl;
    };
    Publication(const Publication & obj1){
        Cr = obj1.Cr;
        Au = obj1.Au;
        Ac = obj1.Ac; 
    }
    ~Publication(){
        cout<<"Publication destructor called"<<endl;
    }

    void Print(){
        cout<<"\n \nPublication "<<endl;
        Au.Print();
        cout <<"Achievment "<<Ac<<"\n \n"<<endl;
    };

    int GetAcj(){return Ac;};
    Date GetCr(){return Cr;};
    Achievement GetAc(){return Ac;};

    void SetAcj(Achievement t){Ac = t;};
    void SetAu(Student t){Au = t;};
    void SetAc(Date t){Cr = t;};
};

class Research
{
private:
    string topic;
    deque<Publication> deq; 
public:
    string GetTop(){return topic;};
    deque<Publication> GetPub(){return deq;};

    void SetTop(string t){topic = t;};
    void SetDeq(deque<Publication> t){deq = t;};

    Research(string t1, Publication t2){
        topic = t1;
        deq.push_back(t2);
    };

    ~Research(){
        deq.clear();
    }
    Research(const Research &obj1){
        topic = obj1.topic;
        deq = obj1.deq;
    }

    void addPublication(Publication t){
        deq.push_back(t);
    }

    void DeleteByDate(Date t){
         for (auto it = deq.begin(); it != deq.end(); ++it)
              if((*it).GetCr()<t){
                  cout<<"\tTried to Erase"<<endl;;
                  deq.erase(it);
              }
    }

    void Print(){
        cout<<"Topic"<<topic<<endl;
        for (auto &&i : deq)
        {
            i.Print();
        }
    }

    void ShortPrint(){
        int T1, T2 , T3, T4;
        T1=T2=T3=T4=0;
        for (auto &&i : deq)
        {
            switch (i.GetAcj())
            {
            case 0: T1++;
                break;
            case 1: T2++;
                break;
            case 2: T3++;
                break;
            case 3: T4++;
                break;
            }
        }
        cout <<"Breakdown on topics: \n";
        cout<<"Thesis - "<<T1<<endl;
        cout<<"Article_in_special_magazine - "<<T2<<endl;
        cout<<"Report_world_conference - "<<T3<<endl;
        cout<<"Report_world_magazine - "<<T4<<endl;  
    }

    friend std::ostream& operator<< (std::ostream &out, const Research &point);

    Research operator + (Research const &obj) {
        for (auto &&i : obj.deq)
        {
            deq.push_back(i);
        }
        return *this;
    }
};

std::ostream& operator<< (std::ostream &out, const Research &point)
{
        int T1, T2 , T3, T4;
        T1=T2=T3=T4=0;
        deque<Publication> deq1 = point.deq;
        for (auto &&i : deq1)
        {
            switch (i.GetAcj())
            {
            case 0: T1++;
                break;
            case 1: T2++;
                break;
            case 2: T3++;
                break;
            case 3: T4++;
                break;
            }
        }
    out <<"Breakdown on topics: \n"<<"Thesis - "<<T1<<"\n"<<"Article_in_special_magazine - "<<T2<<"\n"<<"Report_world_conference - "<<T3<<"\n"<<"Report_world_magazine - "<<T4<<endl;  
    return out;
}




int main(){

    cout<<"Creation of Human"<<endl;
    Human Me("Illlia", "Kvashuk", 2001, 11, 4);
    Me.Howdoyoudo();
    Me.HumanSurnameSet("Illia");
    Me.Howdoyoudo();
    cout<<"My Name is "<<Me.HumanNameGet()<<endl;

    cout<<"Creation of Student"<<endl;
    Student AlsoMe(4,"Illlia", "Kvashuk", 2001, 11, 4);
    Student SomebodyElse();



    Publication Photo(2, "Albert", "Einstein",  Report_world_conference, 1908, 1,1, 1879, 03, 14);
    Publication Gravity(3, "Albert", "Einstein",  Report_world_conference, 1909, 1,1, 1879, 03, 14);
    Publication Gravity2(4, "Albert", "Einstein",  Report_world_magazine, 1911, 1,1, 1879, 03, 14);
    Research EinsteinLife("Life of Einstein", Photo);
    EinsteinLife.addPublication(Gravity);
    EinsteinLife.addPublication(Gravity2);
    Date NewDawn(1908, 2,1);
    cout<<EinsteinLife;
    EinsteinLife.DeleteByDate(NewDawn);
    cout<<EinsteinLife;
    EinsteinLife.ShortPrint();
    EinsteinLife.Print();
    cout<<EinsteinLife<<endl;
    Research doubleEin = EinsteinLife + EinsteinLife;
    cout<<doubleEin<<endl;
}