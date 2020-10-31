// DemoSTL_Alg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

class People {

	friend std::ostream& operator<<(std::ostream& s, const People& p);

	std::string firstName;
	std::string lastName;
	int age;
public:
	People(const char* firstName, const char* lastName, int age)
		:firstName(firstName), lastName(lastName), age(age) {
	}
	std::string getFirstName() const{
		return firstName;
	}
	std::string getLastName() const{
		return lastName;
	}
	int getAge() const{
		return age;
	}
};

std::ostream& operator<<(std::ostream& s, const People& p) {
	s << p.firstName << " " << p.lastName << " " << p.age << " year old\n";
	return s;
}


int main()
{
	std::vector<People> peoples = {
		People("Vasa", "Pupkin",  25),
	    People("Oleg", "Ivanoff", 25), 
		People("Dima", "Petroff", 25),
		People("Li", "Si Cin",    25)};


	//std::for_each(peoples.begin(), peoples.end(), [](People& p) {std::cout << p; });

	std::ostream_iterator<People> iter(std::cout);
	std::copy(peoples.begin(), peoples.end(), iter);

	//std::vector<People>::iterator res
	auto res = std::find_if(peoples.begin(), peoples.end(), 
		[](const People p) { return p.getLastName().compare("Pupkin")==0; });


	if (res == peoples.end()) {

	}
	else {
		std::cout <<"Finded people::  "<< *res;
	}


}

