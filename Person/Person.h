/*
* @Author: Nathaniel Kuga
*/
#include <string>

class Person
{
public:
	Person();
	Person(int Age, std::string Name, double Height, std::string Job);
	int getAge();
	double getHeight();
	std::string getName();
	std::string getJob();
	bool operator== (Person& other) const;

private:
	int age;
	std::string name;
	double height;
	std::string job;
};