/*
* @Author: Nathaniel Kuga
*/

#include "Person.h"

Person::Person()
{
	age = 0;
	name = "?";
	height = 0;
	job = "?";
}

Person::Person(int Age, std::string Name, double Height, std::string Job)
{
	age = Age;
	name = Name;
	height = Height;
	job = Job;
}

int Person::getAge() { return age; }

double Person::getHeight() { return height; }

std::string Person::getName() { return name; }

std::string Person::getJob() { return job; }

bool Person::operator==(Person& other) const
{
	if (this->age == other.age && this->height == other.height && this->job == other.job && this->name == other.name) { return true; }
	else { return false; }
}