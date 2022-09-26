#include <iostream>
#include <fstream>
#include <stdlib.h>
//#include <cstdlib>
#include <conio.h>
#include"Main.h"
#include<time.h>

using namespace std;

class sprayer
{
private:
	string spsid, fieldid, ifuel, iproduct, productid;
public:
	void Menu();
	void insert();
	void display();
	void deleted();
	void search();
	void randinsert();
};
const int MAX = 26;

void sprayer::Menu()
{
menustart:
	int choice;
	char x;
	system("cls");


	cout << "\n\n*********MENU********:" << endl;


	cout << "1. insert" << endl;
	cout << "2. display" << endl;
	cout << "3. search" << endl;
	cout << "4. random insert" << endl;
	cout << "5. delete" << endl;
	cout << "6. stop" << endl;


	cout << "what would you like to do: " << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		do
		{
			insert();
			cout << " Add another record (Y/N):";
			cin >> x;
		} while (x == 'y' || x == 'Y');
		break;
	case 2:
		display();
		break;
	case 3:
		search();
		break;
	case 4:
		randinsert();
		break;
	case 5:
		deleted();
		break;
	case 6:
		exit(0);
		break;
	default: cout << "invalid try again";
		break;
	}
	_getch();
	goto menustart;
}

void sprayer::insert()
{
	system("cls");
	ofstream fout;


	cout << "--------------------------Add Sprayer Details---------------------------" << endl;

	cout << "Enter spsid: ";
	cin >> spsid;
	cout << "Enter fieldid: ";
	cin >> fieldid;
	cout << "Enter ifuel: ";
	cin >> ifuel;
	cout << "Enter iproduct: ";
	cin >> iproduct;
	cout << "Enter productid: ";
	cin >> productid;
	clock_t t;
	t = clock();
	fout.open("ugg.txt", ios::app);
	fout << " " << spsid << " " << fieldid << " " << ifuel << " " << iproduct << " " << productid << "\n" << endl;
	fout.close();
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; 
	cout << "\n\nIt took " << time_taken << "seconds to insert " << endl;
	
}

void sprayer::display()
{
	system("cls");
	fstream fout;
	int total = 0;
	cout << "-----------Records Available------------" << endl;
	fout.open("ugg.txt", ios::in);
	if (!fout)
	{
		cout << "No record available";
		fout.close();
	}
	else
	{
		fout >> spsid >> fieldid >> ifuel >> iproduct >> productid;
		while (!fout.eof())
		{
			cout << "Record No.: " << total++ << endl;
			cout << "Spsid: " << spsid << endl;
			cout << "Fieldid: " << fieldid << endl;
			cout << "Ifuel: " << ifuel << endl;
			cout << "Iproduct: " << iproduct << endl;
			cout << "Productid: " << productid << endl;
			cout << "\n" << endl;
			fout >> spsid >> fieldid >> ifuel >> iproduct >> productid;
		}
		if (total == 0)
		{
			cout << "No record available";
		}

	}
	fout.close();
}

void sprayer::search()
{
	system("cls");
	fstream fout;
	int found = 0;
	fout.open("ugg.txt", ios::in);
	if (!fout)
	{
		cout << "---------Search Operation---------" << endl;

		cout << "No record available" << endl;
	}
	else
	{
		string xspsid;
		cout << "---------Search Operation---------" << endl;

		cout << "Please eneter the spsid you want to search: ";
		cin >> xspsid;
		clock_t t;
		t = clock();
		fout >> spsid >> fieldid >> ifuel >> iproduct >> productid;
		while (!fout.eof())
		{
			if (xspsid == spsid)
			{
				cout << "Spsid: " << spsid << endl;
				cout << "Fieldid: " << fieldid << endl;
				cout << "Ifuel: " << ifuel << endl;
				cout << "Iproduct: " << iproduct << endl;
				cout << "Productid: " << productid << endl;
				found++;
				t = clock() - t;
				double time_taken = ((double)t) / CLOCKS_PER_SEC;
				cout << "It took " << time_taken << "seconds to search " << endl;
			}
			fout >> spsid >> fieldid >> ifuel >> iproduct >> productid;
			
		}
		if (found == 0)
		{
			clock_t t;
			t = clock();
			cout << "Spsid Not Found";
			t = clock() - t;
			double time_taken = ((double)t) / CLOCKS_PER_SEC;
			cout << "\n\nIt took " << time_taken << "seconds to search " << endl;
		}
		fout.close();
	}

}

void sprayer::deleted()
{
	system("cls");
	fstream file, file1;
	string xspsid;
	int found = 0;
	cout << "-----------Delete Operation-----------" << endl;
	file.open("ugg.txt", ios::in);
	if (!file)
	{
		cout << "No record available";
	}
	else
	{
		cout << "\nEnter the spsid you want to delete: ";
		cin >> xspsid;
		clock_t t;
		t = clock();
		file1.open("temp.txt", ios::app | ios::out);
		file >> spsid >> fieldid >> ifuel >> iproduct >> productid;
		while (!file.eof())
		{
			if (xspsid != spsid)
			{
				file1 << " " << spsid << " " << fieldid << " " << ifuel << " " << iproduct << " " << productid << "\n" << endl;
			}
			file >> spsid >> fieldid >> ifuel >> iproduct >> productid;
		}
		if (found == 0)
		{
			cout << "Spsid sucessfully deleted";

			t = clock() - t;
			double time_taken = ((double)t) / CLOCKS_PER_SEC; 
			cout << "\n\nIt took " << time_taken << "seconds to delete " << endl;

			cout << "Press enter to return to the main menu" << endl;
		}
		file1.close();
		file.close();
		remove("ugg.txt");
		rename("temp.txt", "ugg.txt");
	}

}

string RandStringGenerator(int n)
{
	char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
						  'h', 'i', 'j', 'k', 'l', 'm', 'n',
						  'o', 'p', 'q', 'r', 's', 't', 'u',
						  'v', 'w', 'x', 'y', 'z' };

	string res = "";
	for (int i = 0; i < n; i++)
		res = res + alphabet[rand() % MAX];

	return res;
}

void sprayer::randinsert()
{
	system("cls");

	cout << "---------Rand Insert Operation---------" << endl;
	cout << "\n\n";

	srand(time(NULL));
	fstream fout;
	int choice;
	fout.open("ugg.txt", ios::app);
	cout << "how many record will you like to randomly insert" << endl;
	cin >> choice;

	clock_t t;
	t = clock();
	for (int i = 0; i < choice; i++)
	{
		int n = 5;
		spsid = RandStringGenerator(n);
		fieldid = RandStringGenerator(n);
		ifuel = RandStringGenerator(n);
		iproduct = RandStringGenerator(n);
		productid = RandStringGenerator(n);
		fout << " " << spsid << " " << fieldid << " " << ifuel << " " << iproduct << " " << productid << "\n" << endl;
		

		spsid = "";
		fieldid = "";
		ifuel = "";
		iproduct = "";
		productid = "";
	}
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	cout << "It took " << time_taken << "seconds to randomly insert " << choice << " records" << endl;
	cout << "\nA total of " << choice << " records has been successfully entered" << endl;
	cout << "\n\nPress enter to return to the main menu" << endl;

	fout.close();
}






int main(void)
{
	sprayer s;
	string start;
	cout << "Enter \"start\" to begin program:" << endl;
	cin >> start;
	s.Menu();
	return 0;
}