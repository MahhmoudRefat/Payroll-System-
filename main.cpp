
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

struct employee
{

	int emp_num; //employee number
	string fname; //employee first name
	string lname; //employee last name
	float wh /*works hour per month*/, ph /*price per hour*/, salary;
};

employee emp[10];
void startpage(int size);
int Get_data();
void add_emp(int size);
void compute(int size);
double total(int size);
double max(int size);
double mini(int size);
float tax(float salary);
float net_salary(float salary);
float gross_Salary(float salaary);
int delete_emp(int size);
void print_data(int size);
void edit(int size);
void save(int size);
void quit();

int main()
{
	int size = Get_data();
	startpage(size);
	return 0;
	system("pause");
}
void startpage(int size)
{
	string com;char comm;
	cout << "\t\t\t Payroll System \t\t\t\n";
	cout << "\t\t    welcome in our project\t\t \n";
	cout << "Enter A for Add any new employee \n";
	cout << "Enter P for print the saved employee information \n";
	cout << "Enter C for compute employee or company information\n";
	cout << "Enter E for Edit the employee information \n";
	cout << "Enter D for delet any saved employee \n";
	cout << "Enter Q for quit the program \n";
	cout << "\nPlease Enter you ordar here : ";cin >> com;
	comm = com.at(0);
	switch (comm)
	{
	case 'a':
	case 'A':
		add_emp(size);
		startpage(size);
		break;
	case 'p':
	case 'P':
		print_data(size);
		startpage(size);
		break;
	case 'C':
	case'c':
		compute(size);
		startpage(size);
		break;
	case 'E':
	case'e':
		edit(size);
		startpage(size);
		break;
	case 'Q':
	case 'q':
		quit();
		break;
	case'D':
	case'd':
		delete_emp(size);
		break;
	case 'H':
	case 'h':
		cout << "\n\n A ) to add employee     .  D ) to delete employee\n\n"
			<< "c ) compute some information .  E ) to edit employee\n\n"
			<< "P ) print the employees \n\n";
		startpage(size);
		break;
	default:
		cout << "use \"h\" to get help :)\n ";
		startpage(size);
		break;
	}

}
int Get_data()
{
	string data ;int size = 0;
	ifstream file;
	//**********************************get size*********************************************

	file.open("empdata.txt");
	while (!file.eof())
	{
		file >> data;
		size++;
	}
	size /= 4;
	file.close();
	//****************************************************************************************************

	file.open("empdata.txt");
	for (int i = 0; i < size;i++)
	{
		file >> emp[i].fname;
		file >> emp[i].lname;
		file >> emp[i].wh;
		file >> emp[i].ph;
		emp[i].salary = emp[i].wh*emp[i].ph;
	}
	file.close();
	return size;
}
void save(int size)
{
	ofstream save;
	save.open("empdata.txt");
	for (int i = 0;i < size;i++)
	{
		save << emp[i].fname << " " << emp[i].lname << " " << emp[i].wh << " " << emp[i].ph << endl;
	}
	save.close();
	startpage(size);
}
void add_emp(int size)
{
	cout << "Please Enter The  "<< size + 1 <<"  employee information \n";
	cout << "The First Name : ";cin >> emp[size].fname;
	cout << "The last Name   : ";cin >> emp[size].lname;
	cout << "The employee work hours at month : ";cin >> emp[size].wh;
	cout << "The Price Per hour  : ";cin >> emp[size].ph;
	emp[size].salary = emp[size].ph*emp[size].wh;
	size++;
	save(size);
}
void print_data(int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "The  "<< i+1 << "  employee information is : \n";
		cout << "*************************************************************\n";
		cout << "The first Name is : " << emp[i].fname << endl;
		cout << "The Last  Name is : " << emp[i].lname << endl;
		cout << "The employee Salary  is : " << emp[i].salary << endl << endl;
	}
}
void edit(int size)
{
	/*interface***************************************************** */
	//print all employee number and first name
	int x, y;
	for (int i = 0;i < size;i++)
	{
		cout << i + 1 << " : " << emp[i].fname << endl;
	}
	cout << "enter the number of emp that you want to edit : ";cin >> x;
	x--;
	/****************************************************************/
	cout << "\nFirst Name : " << emp[x].fname;
	cout << "\nlast  Name : " << emp[x].lname;
	cout << "\nPrice Per hour : " << emp[x].ph;
	cout << "\nWork hours : " << emp[x].wh <<endl;
	cout << "\nEnter :-\n\n";
	cout << "1) To Edit first Name"; cout << "     2) To Edit last Name\n\n";
	cout << "3) To Edit price per hour "; cout <<"    4) To Edit work hours per month  ";
	cout << "Enter your choose here : ";cin >> y;
	switch (y)
	{
	case 1:
		cout << "Enter The New edit here : ";
		cin >> emp[x].fname;
		break;
	case 2:
		cout << "Enter The New edit here : ";
		cin >> emp[x].lname;
		break;
	case 3:
		cout << "Enter The New edit here : ";
		cin >> emp[x].ph;
		break;
	case 4:
		cout << "Enter The New edit here : ";
		cin >> emp[x].wh;
		break;
	default:
		cout << "error ... ";
		break;
	}
	emp[x].salary = emp[x].ph*emp[x].wh;
	save(size);
}
void compute(int size)
{
	char x;float temp = 0;
	cout << " \n*************Compute**************\n";
	cout << "Enter B to go back to home mnue \n";
	cout << "Enter T to Compute the total salary for the company \n";
	cout << "Enter X to Compute the max salary in the company\n";
	cout << "Enter M to Compute the mini salary in the  company \n";
	cout << "Enter N to Compute the net salaty \n";
	cout << "Enter G to compute the gross salary \n";
	cout << "Enter S to compute the tax \n";
	cout << "Enter your choose here : ";cin >> x;
	switch (x)
	{
		//if you want to back again
	case 'b':
	case 'B':
		startpage(size);
		break;
	case 't':
	case 'T':
		cout << "The Total salary is : " << total(size);
		compute(size);
		break;
	case 'M':
	case 'm':
		cout << "The Mini salary is : " << mini(size);
		compute(size);
		break;
	case 'x':
	case 'X':
		cout << "The Max salary is : " << max(size);
		compute(size);
		break;
	case 'n'://net salary
	case 'N':
		temp = 0;
		for (int i = 0;i < size; i++)
		{
			temp += net_salary(emp[i].salary);
		}
		cout << " \n The net salary for all : " << temp << endl << endl;
		for (int i = 0;i < size; i++)
		{
			cout << emp[i].fname << " : " << net_salary(emp[i].salary) << endl;
		}
		compute(size);
		break;
	case 'g':
	case 'G':
		temp = 0;
		for (int i = 0;i < size; i++)
		{
			temp += gross_Salary(emp[i].salary);
		}
		cout << " \nThe gross salary for all : " << temp << endl << endl;
		for (int i = 0;i < size; i++)
		{
			cout << emp[i].fname << " : " << gross_Salary(emp[i].salary) << endl;
		}
		compute(size);
		break;
	case 's':
	case 'S':
		temp = 0;
		for (int i = 0;i < size; i++)
		{
			temp += tax(emp[i].salary);
		}
		cout << " \nThe Tax for all : " << temp << endl << endl;
		for (int i = 0;i < size; i++)
		{
			cout << emp[i].fname << " : " << tax(emp[i].salary) << endl;
		}
		compute(size);
		break;

	default:
		cout << "\n Entet B to go back ";
		compute(size);
		break;
	}
}
double total(int size)
{
	double t = 0;
	for (int i = 0;i < size;i++)
	{
		t += emp[i].salary;
	}
	return t;
}
double mini(int size)
{
	double t = emp[0].salary;
	for (int i = 1;i < size;i++)
	{
		if (emp[i].salary < t)
			t = emp[i].salary;
	}
	return t;
}
double max(int size)
{
	double t = emp[0].salary;
	for (int i = 1;i < size;i++)
	{
		if (emp[i].salary > t)
			t = emp[i].salary;
	}
	return t;
}
float  tax(float salary)
{
	float tax;
	if (salary < 0.00)
		tax = -1;
	else if (salary < 15000.00) // first range
		tax = 0.15 * salary;
	else if (salary < 30000.00) // second range
		tax = (salary - 15000.00) * 0.16 + 2250.00;
	else if (salary < 50000.00) // third range
		tax = (salary - 30000.00) * 0.18 + 4650.00;
	else if (salary < 80000.00) // fourth range
		tax = (salary - 50000.00) * 0.20 + 8250.00;
	else if (salary <= 150000.00) // fifth range
		tax = (salary - 80000.00) * 0.25 + 14250.00;
	else
		tax = -1;
	return tax;
}
float gross_Salary(float salary)
{
	salary = (10 * salary) / 100;
	salary = (12 * salary) / 100;
	return salary;

}
float net_salary(float salary)
{
	return (salary + salary*0.52) - tax(salary);
}
int delete_emp(int size)
{
	/*interface***************************************************** */
	int x;
	cout << endl;
	for (int i = 0;i < size;i++)
	{
		cout << i + 1 << " : " << emp[i].fname << endl;
	}
	cout << "enter the number of employee that you want to delete : ";cin >> x;
	x--;
	/****************************************************************/
	emp[x].fname = emp[size - 1].fname;
	emp[x].lname = emp[size - 1].lname;
	emp[x].salary = emp[size - 1].salary;
	emp[x].ph = emp[size - 1].ph;
	emp[x].wh = emp[size - 1].wh;
	size--;
	save(size);
	return size;
}
void quit()
{
	//it,s not return any thing
}




