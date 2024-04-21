#pragma once
#include "Result.h"
#include <algorithm>
class School {
private:
	std::vector<Result> allResults;
	
public:
	short schoolNumber;
	School(int no) :allResults{} {
		if (no < 0) {
			throw std::exception("Invalid school number");
		}
		schoolNumber = no;
		
	}
	~School(){}
	void addResult(Result r) {
		allResults.push_back(r);
	}
	friend std::ostream& operator<<(std::ostream& os, School S) {
		std::sort(S.allResults.begin(),S.allResults.end());
		os <<std::endl<< "Студенти школи номер " << S.schoolNumber << std::endl << std::endl;
		for (auto& i : S.allResults) {
			os << i;
		}
		return os;
	}
	std::vector<Result>& getResults() { return allResults; }

};