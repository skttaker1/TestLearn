#include<iostream>
#include<string> 
using namespace std;

class student
{
public:
	string name;
	int age;
	void setName(string n)
	{
		name = n;
	}
	void initInfo(string n, int a)
	{
		name = n;
		age = a;
	}
	void print()
	{
		cout << name << " " << age << endl;
	}
};

class person
{
public:
	string name;
	int age;
	int* p;
	void init()
	{
		p = new int[4];
		for (int i = 0; i < 4; i++)
		{
			cin >> p[i];
		}
	}
	void print()
	{
		for (int i = 0; i < 4; i++)
		{
			cout << p[i] << endl;
		}
	}

	void release()
	{
		delete[] p;
	}
	void setName(string n)
	{
		name = n;
	}
};

class Array
{
public:
	int arr[3][4];
	void init()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				arr[i][j] = i + j;
			}
		}
	}
	void print()
	{
		print(' ');
	}
	void print(char space)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << arr[i][j] << (j == 3 ? '\0' : space);
			}
			cout << endl;
		}
	}
};

int main()
{
	/*student stu[2];
	stu[0].name = "zongyuan";
	stu[0].age = 20;
	
	stu[1].initInfo("jiayu", 20);

	for (int i = 0; i < 2; i++)
	{
		stu[i].print();
	}*/

	/*person per;
	per.setName("zongyuan");
	cout << per.name << endl;

	per.init();
	per.print();
	per.release();*/

	/*Array arr;
	arr.init();
	arr.print();
	arr.print('#');

	cout << '\0';*/

	student* p = new student();
	p->initInfo("zongyuan", 18);

	return 0;
}
