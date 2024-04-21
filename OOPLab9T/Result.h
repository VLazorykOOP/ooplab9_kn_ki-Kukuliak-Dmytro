#pragma once
#include <vector>
#include <string>

struct Grades {
	unsigned short math;
	unsigned short ukr;
	unsigned short info;
	Grades():math(0),ukr(0),info(0) {}
	Grades(int a, int b, int c) {
		if (a > 200 || a < 0 || b>200 || b < 0 || c>200 || c < 0) {
			throw std::exception("Grades must have a range of [0;200]");
		}
		math = a;
		ukr = b;
		info = c;

	}
	friend std::ostream& operator<<(std::ostream& os, Grades G) {
		os << "Математика: " << G.math << std::endl;
		os << "Українська мова: " << G.ukr << std::endl;
		os << "iнформатика: " << G.info << std::endl;
		return os;
	}
	bool operator<(const Grades& other)  {

		unsigned short total_this = math + ukr + info;
		unsigned short total_other = other.math + other.ukr + other.info;

		return total_this < total_other;
	}

};

class School;
class Result {
private:
	std::string Surname;
	std::string Initials;
	Grades ownGrades;
public:
	Result(){}
	Result(std::string sname,std::string in, Grades g) {
		Surname = sname;
		Initials = in;
		ownGrades = g;
	}
	Grades& getGrades() { return ownGrades; }
	friend std::ostream& operator<<(std::ostream& os, Result R) {

		os << "Прiзвище: " << R.Surname<< std::endl;
		os << "iнiцiали: " << R.Initials << std::endl;
		os << "Оцiнки НМТ:" << R.ownGrades << std::endl;
		return os;
	}
	bool operator<(const Result& rhs)  {

		if (Surname != rhs.Surname) {
			return Surname < rhs.Surname;
		}

		if (Initials != rhs.Initials) {
			return Initials < rhs.Initials;
		}
		return ownGrades < rhs.ownGrades;
	}


	
};