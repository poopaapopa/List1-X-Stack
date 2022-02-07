#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
using namespace std;

class HomePet
{
	char Name[20];
	char Podvid[30];
	int age;
public:
	HomePet(const char* n, const char* p, int age)
	{
		strcpy(Name, n);
		strcpy(Podvid, p);
		this->age = age;
	}
	virtual void speak() = 0;
	virtual void ShowName()
	{
		cout << Name << " ";
	}
	virtual void ShowType()
	{
		cout << Podvid << " ";
	}
};
class Dog : public HomePet
{
public:
	Dog(const char* n, const char* p, int age) :HomePet(n, p, age) {}
	virtual void speak()
	{
		cout << "say: \'gav-gav\'\n";
	}
};
class Cat : public HomePet
{
public:
	Cat(const char* n, const char* p, int age) :HomePet(n, p, age) {}
	virtual void speak()
	{
		cout << "say: \'meow-meow\'\n";
	}
};
class Parrot : public HomePet
{
public:
	Parrot(const char* n, const char* p, int age) :HomePet(n, p, age) {}
	virtual void speak()
	{
		cout << "say: \'chirik-chirik\'\n";
	}
};
class Hamster : public HomePet
{
public:
	Hamster(const char* n, const char* p, int age) :HomePet(n, p, age) {}
	virtual void speak()
	{
		cout << "say: \'chrum-chrum\'\n";
	}
};

struct Elem
{
	int val;
	Elem* Next = NULL;
};
class List
{
	Elem* First;
	Elem* Last;
public:
	List()
	{
		First = Last = 0;
	}
	virtual void Del() = 0;
	virtual void Add(int val) = 0;
};
class Ochered : public List
{
	Elem* First;
	Elem* Last;
public:
	Ochered()
	{
		First = Last = 0;
	}
	virtual void Add(int val)
	{
		Elem* temp = new Elem;
		temp->val = val;
		temp->Next = NULL;
		if (First != NULL)
		{
			Last->Next = temp;
			Last = temp;
		}
		else
			Last = First = temp;
	}
	virtual void Del()
	{
		if (First != NULL)
		{
			Elem* temp = First;
			cout << "ÝËÅÌÅÍÒ " << First->val << " ÂÛØÅË\n";
			First = First->Next;
			delete temp;
		}
	}
};
class Stack :public List
{
	Elem* Head;
public:
	Stack()
	{
		Head = 0;
	}
	virtual void Add(int val)
	{
		Elem* temp = new Elem;
		temp->val = val;
		temp->Next = Head;
		Head = temp;
	}
	virtual void Del()
	{
		if (Head != NULL)
		{
			Elem* temp = Head;
			cout << "ÝËÅÌÅÍÒ " << Head->val << " ÂÛØÅË\n";
			Head = Head->Next;
			delete temp;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	/*Dog a1("Bobik", "Mops", 3);
	Cat a2("Murka", "British", 4);
	Parrot a3("Petua", "Ara", 2);
	Hamster a4("Sema", "None", 1);
	a1.ShowType();
	a1.ShowName();
	a1.speak();
	a2.ShowType();
	a2.ShowName();
	a2.speak();
	a3.ShowType();
	a3.ShowName();
	a3.speak();
	a4.ShowType();
	a4.ShowName();
	a4.speak();*/
	cout << "ÐÀÁÎÒÀ Î×ÅÐÅÄÈ:\n";
	Ochered och;
	och.Add(1);
	och.Add(2);
	och.Add(3);
	och.Add(4);
	och.Del();
	och.Del();
	och.Del();
	och.Del();
	cout << "ÐÀÁÎÒÀ ÑÒÅÊÀ:\n";
	Stack stk;
	stk.Add(1);
	stk.Add(2);
	stk.Add(3);
	stk.Add(4);
	stk.Del();
	stk.Del();
	stk.Del();
	stk.Del();
	return 0;
}