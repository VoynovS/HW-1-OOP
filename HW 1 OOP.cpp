
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Human {
public:
	Human(){}
	Human(int day, int month, int year){
		birthday.tm_wday = day;
		birthday.tm_mon = month;
		birthday.tm_year = year;
	}
	Human(string surname, 
		string name,
		string patronymic,
		int day, int month, int year)
		:surname(surname), 
		name(name),		
		patronymic(patronymic) 
	{
		birthday.tm_wday = day;
		birthday.tm_mon = month;
		birthday.tm_year = year;
	}
	
	void setName(string name) {
		this->name = name;
	}

	const auto getName() {
		return name;
	}

	void setSurname(string surname) {
		this->surname = surname;
	}

	const auto getSurname() {
		return surname;
	}

	void setPatronymic(string patronymic) {
		this->patronymic = patronymic;
	}

	const auto getPatronymic() {
		return patronymic;
	}

	void setBirthday(int day, int month, int year) {
		birthday.tm_wday = day;
		birthday.tm_mon = month;
		birthday.tm_year = year;
	}
	const auto getBirthday() {
		return to_string (birthday.tm_wday) + "."
			+ to_string(birthday.tm_mon) + "."
			+ to_string(birthday.tm_year);
	}

	void fullNameHuman() {
		cout << "Fullname: " << surname << " " << name << " " << patronymic << endl;;
	}
	
	void showHuman(){
		cout << "Fullname: " << surname << " " << name << " " << patronymic
			<< ", birthday: " << getBirthday() << endl;
	}

private:
	string name;
	string surname;
	string patronymic;
	tm birthday;
};

class Student {
public:
	Student(){}
	Student(
		Human humans,
		vector<int> evaluations,
		string group,
		string direction) {
		humans = humans;
		this->evaluations = evaluations;
		this->group = group;
		this->direction = direction;
	}
	
	void setEvaluations(vector<int> evaluations) {
		this->evaluations = evaluations;
	}

	const auto getEvaluations() {
		return evaluations;
	}

	void setGroup(string group) {
		this->group = group;
	}

	const auto getGroup() {
		return group;
	}

	void setDirection(string direction) {
		this->direction = direction;
	}

	const auto getDirection() {
		return direction;
	}

	void fullName() {
		humans.fullName();
	}

	void showStudent() {
		fullName();
		cout << " Group: " << getGroup() << ", direction: " 
			<< getDirection() << ", evaluations: ";
		
		for (int i = 0; i < evaluations.capacity(); ++i)
		{
			cout << evaluations[i] << ",";
		}
		cout << "\b.";
		cout << endl;
	}

	void setShowStudents(string group, string direction, vector<int> evaluations) {
		this->group = group;
		this->direction = direction;
		this->evaluations = evaluations;
	}

	void setFullName(string serName,
		string name,
		string patronymic) {
		humans.setFullName(serName, name, patronymic);

	};
	

		
private:
	class Human {
	public:
		Human(){}
		Human(string serName,
		string name,
		string patronymic)
			:serName(serName),
			name(name),
			patronymic(patronymic)
		{}

		void setSerName(string serName) {
			this->serName = serName;
		}

		const auto getSerName() {
			return serName;
		}

		void setName(string name) {
			this->name = name;
		}

		const auto getName() {
			return name;
		}

		void setPatronymic(string patronymic) {
			this->patronymic = patronymic;
		}

		const auto getPatronymic() {
			return patronymic;
		}

		void fullName() {
			cout << "Fullname: " << getSerName() << " " << getName() << " " << getPatronymic();
		}
		
		void setFullName(string serName,
			string name,
			string patronymic) {
			this->serName = serName;
			this->name = name;
			this->patronymic = patronymic;
		}
	
		string serName;
		string name;
		string patronymic;
	};
	Human humans;
	vector<int> evaluations;
	string group;
	string direction;
};

class Flat
{
public:
	Flat(){}
	Flat(Human h, string adress, float square, vector<string> people)
		:adress(adress), square(square), people(people){
		this->h = h;
	}

	Flat(string adress, float square, vector<string> people)
		:adress(adress), square(square), people(people) {}
	
	void setAdress(string adress) {
		this->adress = adress;
	}

	const auto getAdress() {
		return adress;
	}

	void setSquare(float square) {
		this->square = square;
	}

	const auto getSquare()	{
		return square;
	}

	void setPeople(vector<string> people) {
		this->people = people;
	}

	const auto getPeople() {
		return people;
	}

	void showPeople() {

	}

	void minSquare() {
		int n = people.capacity();
		float sq = getSquare() / n;
		cout << sq;
	}

	void listPeople() {
		for (size_t i = 0; i < people.capacity(); i++)
		{
			cout << people[i] <<  endl;
		}
	}

	void required() {
		if (people.capacity() <= 0) {
			cout << " 0m2" << endl;
		} else
		if (people.capacity() == 1) {
			cout << " 33m2 " << endl;
		} else
		if (people.capacity() == 2) {
			cout << "21m2" << endl;
		}
		else {
			cout << "18m2" << endl;
		}

	}

	void showFlat() {
		cout << "Adress: " << getAdress() << ", square: " << getSquare() << endl;
		listPeople();
		cout << "Square per person: ";
		minSquare();
		cout << endl;
		cout << "Required square per person: ";
		required();
	}
private:
	Human h;
	string adress;
	float square = 0;
	vector<string> people;
};





int main() {
	setlocale(LC_ALL, "");
	system("chcp 1251>nul");

	//class Human
	Human human;
	human.setBirthday(16, 12, 2001);
	cout << human.getBirthday() << endl;
	Human human_1("Voynov", "Sergey", "Aleksandrovich", 6, 8, 1983);
	human_1.showHuman();

	//class Student
	Student student;
	student.setFullName("Petrov ", "Petr ", "Ivanovich");
	cout << endl;
	student.setShowStudents("BV-111", "Developer", { 5,6,4,8 });
	student.showStudent();
	cout << endl;

	//class Flat
	Flat flat("Rassvetnaya 11 A - 59", 55.6, { "Войнов Сергей", "Петров Петр", "Иванов Иван" });
	flat.showFlat();
	Flat flat1("Shevchenko 18 - 81", 33.5, { "People 1", "People 2" });
	flat1.showFlat();
	
	

	return 0;
}

