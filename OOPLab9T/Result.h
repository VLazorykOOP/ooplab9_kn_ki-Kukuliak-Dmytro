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
	}
};

class School;
class Result {
	School* school;
	std::string Surname;
	std::string Initials;
	Grades ownGrades;
};