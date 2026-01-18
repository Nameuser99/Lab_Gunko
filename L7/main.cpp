#include "student.h"
#include <iostream>

int main() {
    int grades1[4] = {4, 5, 3, 4};
    int grades2[5] = {5, 4, 5, 3, 4};
    int grades3[4] = {3, 4, 3, 3};
    int grades4[5] = {4, 5, 4, 5, 5};

    const int num_students = 5;
    Student* students[num_students];
    students[0] = new Student("Alex", 1, 101, 1001);
    students[1] = new FirstSessionStudent("Bob", 1, 101, 1002, grades1);
    students[2] = new SecondSessionStudent("Charlie", 1, 101, 1003, grades1, grades2);
    students[3] = new FirstSessionStudent("David", 1, 102, 1004, grades3);
    students[4] = new SecondSessionStudent("Eve", 2, 101, 1005, grades1, grades4);

    for (int i = 0; i < num_students; ++i) {
        std::cout << *students[i] << std::endl;
    }

    double avg_all = 0.0;
    int count_with_avg = 0;
    for (int i = 0; i < num_students; ++i) {
        double av = students[i]->average();
        if (av > 0.0) {
            avg_all += av;
            ++count_with_avg;
        }
    }
    if (count_with_avg > 0) {
        avg_all /= count_with_avg;
    }
    std::cout << "Avg for students with grades: " << avg_all << std::endl;

    double avg_101_first = average_in_group_after_first(101, students, num_students);
    std::cout << "Avg group 101 after first: " << avg_101_first << std::endl;

    double avg_101_two = average_in_group_after_two(101, students, num_students);
    std::cout << "Avg group 101 after two: " << avg_101_two << std::endl;

    Student copy1(*students[0]);
    std::cout << "Copy student: " << copy1 << std::endl;

    FirstSessionStudent copy2(*static_cast<FirstSessionStudent*>(students[1]));
    std::cout << "Copy first: " << copy2 << std::endl;

    SecondSessionStudent copy3(*static_cast<SecondSessionStudent*>(students[2]));
    std::cout << "Copy second: " << copy3 << std::endl;

    static_cast<FirstSessionStudent*>(students[1])->set_first_grade(1, 5);
    std::cout << "Updated Bob: " << *students[1] << std::endl;

    static_cast<SecondSessionStudent*>(students[2])->set_second_grade(2, 5);
    std::cout << "Updated Charlie: " << *students[2] << std::endl;

    for (int i = 0; i < num_students; ++i) {
        delete students[i];
    }
}