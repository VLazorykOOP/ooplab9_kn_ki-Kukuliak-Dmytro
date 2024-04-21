#include <iostream>
#include "School.h"

struct ob {
public:
    std::string name;
    std::vector<School> allSchools{};
    ob(std::string n):name(n){}
    void pushback(School s) {
        for (auto i : allSchools) {
            if (s.schoolNumber == i.schoolNumber)
                throw std::exception("Same school number");
        }
        allSchools.push_back(s);
    }
    School& operator[](int k) {
        for (auto& i : allSchools) {
            if (k == i.schoolNumber)
                return i;
        }       
         throw std::invalid_argument("Invalid array index");
       
    }
    friend std::ostream& operator<<(std::ostream& os, ob O){

        std::cout << "Результати областi " << O.name << std::endl;
        for (auto& i : O.allSchools) {
            std::cout << i;
        }
        return os;
    }
};
ob Hliboka("Глибока");
ob Voloka("Волока");
void min(){
    std::cout << "Студенти, які провалили НМТ:" << std::endl;
    for (auto i : Hliboka.allSchools) {
        std::cout << "Студенти школи номер "<< i.schoolNumber<< " Глибоки" << std::endl << std::endl;
        for (auto j : i.getResults()) {
            if (j.getGrades().math <= 50 || j.getGrades().ukr <= 50 || j.getGrades().info <= 50) {
                std::cout << j << std::endl;
            }
        }
    }
    for (auto i : Voloka.allSchools) {
        std::cout << "Студенти школи номер " << i.schoolNumber << " Волоки" << std::endl << std::endl;
        for (auto j : i.getResults()) {
            if (j.getGrades().math <= 50 || j.getGrades().ukr <= 50 || j.getGrades().info <= 50) {
                std::cout << j << std::endl;
            }
        }
    }

}
/*/int main()
{
    setlocale(LC_CTYPE, "ukr");


    // Seed the random number generator
    srand(time(NULL));

    try
    {
        Hliboka.pushback(School(15));
        Hliboka.pushback(School(23));
        Hliboka.pushback(School(13));
        Voloka.pushback(School(8));

        // Add 5 students to each school
        for (int i = 0; i < 5; ++i) {
            Hliboka[15].addResult(Result("Student " + std::to_string(i + 1), "S" + std::to_string(i + 1), Grades(rand() % 201, rand() % 201, rand() % 201)));
            Hliboka[23].addResult(Result("Student " + std::to_string(i + 6), "S" + std::to_string(i + 6), Grades(rand() % 201, rand() % 201, rand() % 201)));
            Hliboka[13].addResult(Result("Student " + std::to_string(i + 11), "S" + std::to_string(i + 11), Grades(rand() % 201, rand() % 201, rand() % 201)));
            Voloka[8].addResult(Result("Student " + std::to_string(i + 16), "S" + std::to_string(i + 16), Grades(rand() % 201, rand() % 201, rand() % 201)));
        }

      //  std::cout << Hliboka;
        //std::cout << Voloka;
        min();
    }
    catch (std::exception& e) {
        std::cerr << "Помилка:" << e.what() << std::endl;
    }
}
*/
#include <list>
#include <iterator>
#include <algorithm>
int main() {
    setlocale(LC_CTYPE, "ukr");
    try {
        std::list<int> L{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
        std::list<int> L1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
        int k;
        std::cout << "Введiть значення k (0 < k < 5): ";
        std::cin >> k;

        if (k < 0 || k > 5) {
            throw std::invalid_argument("k повинно бути в дiапазонi [0, 5]");
        }
       //Логічно правильний код, який так і не запрацював
       /* auto begin = L.end();
        std::advance(begin, -4);
        auto end = L.end();
       // std::advance(end, -5);
        auto  val = L.begin();
        std::advance(val, k);*/
        //в цьому контексті val це ітератор на елемент, який май стати першим
        auto begin = L.begin();
        auto end = L.begin();
        std::advance(end, 5);
        auto val = L.begin();
        std::advance(val, k);
        // Копіюємо елементи з кінця списку на початок списку з циклічним зсувом на k позицій вліво
        std::rotate_copy(begin, val, end, std::front_inserter(L1));

        begin = L.begin();
        end = L.begin();
        std::advance(end, 5);
        val = L.begin();
        std::advance(val, k);
        // Копіюємо елементи з початку списку в кінець списку з циклічним зсувом на k позицій вправо
        std::rotate_copy(begin, val, end, std::back_inserter(L1));


        // Виводимо результат
        std::cout << "Результат після операцій:" << std::endl;
        for (const auto& elem : L1) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}