#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
#include <cstring>
#include <locale.h>
#include "RandomNumber.h"

using namespace std;
void gotoString(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
//faces
string face1 = "(^.^)";
string face2 = "(>_<)";
string face3 = "[*_*]";
string face4 = "{@-@}";

//names
string name1 = "Василий";
string name2 = "Обрыган";
string name3 = "Сыч";

//surnames
string surname1 = "Обрыганов";
string surname2 = "колбаса";
string surname3 = "колбастер";

//cities
string city1 = "Мухосранс";
string city2 = "Обосранск";
string city3 = "Обрыгановка";

void main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int faceId = 0;
	int nameId = 0;
	int surnameId = 0;
	int cityId = 0;
	struct date
	{
		int year;
		int month;
		int day;
	};
	struct students
	{
		string face;
		string name;
		string surname;
		string city;

		date born;
	};
	students student[100];
	cout << "\n\tNAME\t" << "\tPHOTO\t" << "\tCITY\t" << "\tBIRHDAY\t\n";
	for (int i = 0; i < 99; i++) {
		faceId = randomNumber(1, 4);
		nameId = randomNumber(1, 3);
		surnameId = randomNumber(1, 3);
		cityId = randomNumber(1, 3);
		//faces
		if (faceId == 1) {
			student[i].face = face1;
		}
		else if (faceId == 2) {
			student[i].face = face2;
		}
		else if (faceId == 3) {
			student[i].face = face3;
		}
		else if (faceId == 4) {
			student[i].face = face4;
		}
		//names
		if (nameId == 1) {
			student[i].name = name1;
		}
		else if (nameId == 2) {
			student[i].name = name2;
		}
		else if (nameId == 3) {
			student[i].name = name3;
		}
		//surnames
		if (surnameId == 1) {
				student[i].surname = surname1;
		}
		else if (surnameId == 2) {
				student[i].surname = surname2;
		}
		else if (surnameId == 3) {
			student[i].surname = surname3;
		}
		//cities
		if (cityId == 1) {
			student[i].city = city1;
		}
		else if (cityId == 2) {
			student[i].city = city2;
		}
		else if (cityId == 3) {
			student[i].city = city3;
		}
		//birthdey
		student[i].born.day = randomNumber(1, 30);
		student[i].born.month = randomNumber(1, 12);
		student[i].born.year = randomNumber(1990, 2001);
		cout << "  " << student[i].name << " " << student[i].surname; 
		gotoString(24, i + 2 );
		cout << student[i].face;
		gotoString(38, i + 2);
		cout << student[i].city;
		gotoString(55, i + 2);
		cout << student[i].born.day << "." << student[i].born.month << "." << student[i].born.year << endl;
	}
	system("pause");
}