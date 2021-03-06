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
    Tree(): high(0), root(NULL){};
    ~Tree();
    struct Leaf{
        T element;
        Leaf *Right;
        Leaf *Left;
        Leaf *parent;
    };
    Leaf *root;
    int high;
    void Del(Leaf *kot);
    void insert(T& d);
    void print_inorder();
	void inorder(Leaf*);
    bool isEmpty() const { return root==NULL; }
};
template <class T>
void Tree<T>::insert(T& d)
{
	Leaf* t = new Leaf;
	t->element = d;
	t->Left = NULL;
	t->Right = NULL;
	t->parent = NULL;
	//
	if (isEmpty()) root = t;
	else
	{
		Leaf* curr;
		curr = root;
		while(curr)
		{
			t->parent = curr;
			if(t->element > curr->element) curr = curr->Right;
			else curr = curr->Left;
		}

		if(t->element < t->parent->element)
			t->parent->Left = t;
		else
			t->parent->Right = t;
	}
}
template <typename T>
void Tree <T> :: Del(Leaf *kot){
    if (kot!=NULL)
    {
        Del(kot->Left);
        Del(kot->Right);
        delete kot;
    }
}
template<class T>
void Tree<T>::print_inorder()
{
	inorder(root);
}
template<class T>
void Tree<T>::inorder(Leaf* p)
{
	if(p != NULL)
	{
		if(p->Left) inorder(p->Left);
		cout<<" "<<p->element<<" ";
		if(p->Right) inorder(p->Right);
	}
	else return;
}

class Student{
    public:
    string surname;
    string name;
    string patronymic;
    string group;
    bool operator<(Student& p1)
    {
        if(strcmp(surname.c_str(),p1.surname.c_str())<0) return 1;
        else return 0;
    }
    bool operator>(Student& p1)
    {
        if(strcmp(surname.c_str(),p1.surname.c_str())<0)return 0;
        else return 1;
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
    bool operator<(Professors& p1){
        if(strcmp(surname.c_str(),p1.surname.c_str())<0)return 1;
        else return 0;
        }
     bool operator>(Professors& p1){
        if(strcmp(surname.c_str(),p1.surname.c_str())<0)return 0;
        else return 1;
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
    this->Del(root);
}


int main(){
    Tree <Student> Stud1;

	int ch;

	Student petr;

	while(1)
	{
		cout<<endl<<endl;
		cout<<" Binary Search Tree Operations "<<endl;
		cout<<" ----------------------------- "<<endl;
		cout<<" 1. Insertion/Creation "<<endl;
		cout<<" 2. Show In-Order "<<endl;
		cout<<" 3. Exit "<<endl;
		cout<<" Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1 : cout<<" Enter data to be inserted : ";
			cin.ignore(1);
			cin >> petr;
			Stud1.insert(petr);
			break;
		case 2 : cout<<endl;
			cout<<" In-Order Traversal "<<endl;
			cout<<" -------------------"<<endl;
			Stud1.print_inorder();
			break;
		case 3 : system("pause");
			return 0;
			break;
		}
	}
}

