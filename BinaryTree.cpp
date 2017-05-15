#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <vector>
#include <cmath>
using namespace std;

template <typename T>
class Tree{
public:
    Tree():Root(NULL), high(0){};
    ~Tree();
    struct Leaf{
        T element;
        Leaf *Right;
        Leaf *Left;
    };
    Leaf *Root;
    int high;
    void Del(Leaf *kot);
};
template <typename T>
void Tree <T> :: Del(Leaf *kot){
    if (kot!=NULL)
    {
        Del(kot->Left);
        Del(kot->Right);
        delete kot;
    }
}
class Student{
    public:
    string surname;
    string name;
    string patronymic;
    string group;
    bool operator==(Student& pumba){
        return pumba.name == name && pumba.surname == surname && pumba.patronymic == patronymic && pumba.group == group;
    }
    friend ostream& operator<<(ostream& os, Student& petr){
        os << petr.surname << " " << petr.name << " " << petr.patronymic << " " << petr.group << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Student& petr){
        is >> petr.surname;
        is >> petr.name;
        is >> petr.patronymic;
        is >> petr.group;
        return is;
    }
};
class Professors{
    public:
    string surname;
    string name;
    string patronymic;
    string subject;
    bool operator==(Professors& pumba){
        return pumba.name == name && pumba.surname == surname && pumba.patronymic == patronymic && pumba.subject == subject;
    }
    friend ostream& operator<<(ostream& os, Professors& petr){
        os << petr.surname << " " << petr.name << " " << petr.patronymic << " " << petr.subject << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Professors& petr){
        is >> petr.surname;
        is >> petr.name;
        is >> petr.patronymic;
        is >> petr.subject;
        return is;
    }

};

template <typename T>
Tree <T> :: ~Tree(){
    this->Del(Root);
}


int main(){
    Tree <Student> Stud1;
}

