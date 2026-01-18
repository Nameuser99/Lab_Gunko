#include "student.h"

int Student::next_id = 0;

Student::Student(const std::string& init_name, int init_course, int init_group, int init_record_book)
    : record_book_number(init_record_book) {
    id = ++next_id;
    name = init_name;
    course = init_course;
    group = init_group;
}

Student::Student(const Student& other)
    : record_book_number(other.record_book_number) {
    id = ++next_id;
    name = other.name;
    course = other.course;
    group = other.group;
}

Student::~Student() {
}

int Student::get_id() const {
    return id;
}

const std::string& Student::get_name() const {
    return name;
}

void Student::set_name(const std::string& new_name) {
    name = new_name;
}

int Student::get_course() const {
    return course;
}

void Student::set_course(int new_course) {
    course = new_course;
}

int Student::get_group() const {
    return group;
}

void Student::set_group(int new_group) {
    group = new_group;
}

int Student::get_record_book_number() const {
    return record_book_number;
}

double Student::average() const {
    return 0.0;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "ID: " << s.id << ", Name: " << s.name << ", Course: " << s.course
       << ", Group: " << s.group << ", Record Book: " << s.record_book_number;
    return os;
}

FirstSessionStudent::FirstSessionStudent(const std::string& init_name, int init_course, int init_group, int init_record_book, const int init_grades[4])
    : Student(init_name, init_course, init_group, init_record_book) {
    for (int i = 0; i < 4; ++i) {
        first_grades[i] = init_grades[i];
    }
}

FirstSessionStudent::FirstSessionStudent(const FirstSessionStudent& other)
    : Student(other) {
    for (int i = 0; i < 4; ++i) {
        first_grades[i] = other.first_grades[i];
    }
}

int FirstSessionStudent::get_first_grade(int index) const {
    if (index < 4 && index >= 0) {
        return first_grades[index];
    }
    return 0;
}

void FirstSessionStudent::set_first_grade(int index, int value) {
    if (index < 4 && index >= 0) {
        first_grades[index] = value;
    }
}

double FirstSessionStudent::average() const {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += first_grades[i];
    }
    return static_cast<double>(sum) / 4;
}

std::ostream& operator<<(std::ostream& os, const FirstSessionStudent& s) {
    os << static_cast<const Student&>(s) << ", First Grades: ";
    for (int i = 0; i < 4; ++i) {
        os << s.first_grades[i] << " ";
    }
    return os;
}

SecondSessionStudent::SecondSessionStudent(const std::string& init_name, int init_course, int init_group, int init_record_book, const int init_first_grades[4], const int init_second_grades[5])
    : FirstSessionStudent(init_name, init_course, init_group, init_record_book, init_first_grades) {
    for (int i = 0; i < 5; ++i) {
        second_grades[i] = init_second_grades[i];
    }
}

SecondSessionStudent::SecondSessionStudent(const SecondSessionStudent& other)
    : FirstSessionStudent(other) {
    for (int i = 0; i < 5; ++i) {
        second_grades[i] = other.second_grades[i];
    }
}

int SecondSessionStudent::get_second_grade(int index) const {
    if (index < 5 && index >= 0) {
        return second_grades[index];
    }
    return 0;
}

void SecondSessionStudent::set_second_grade(int index, int value) {
    if (index < 5 && index >= 0) {
        second_grades[index] = value;
    }
}

double SecondSessionStudent::average() const {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += get_first_grade(i);
    }
    for (int i = 0; i < 5; ++i) {
        sum += second_grades[i];
    }
    return static_cast<double>(sum) / 9;
}

std::ostream& operator<<(std::ostream& os, const SecondSessionStudent& s) {
    os << static_cast<const FirstSessionStudent&>(s) << ", Second Grades: ";
    for (int i = 0; i < 5; ++i) {
        os << s.second_grades[i] << " ";
    }
    return os;
}

double average_in_group_after_first(int group, Student** students, int count) {
    double total = 0.0;
    int num = 0;
    for (int i = 0; i < count; ++i) {
        if (students[i]->get_group() == group) {
            FirstSessionStudent* fs = dynamic_cast<FirstSessionStudent*>(students[i]);
            if (fs) {
                total += fs->average();
                ++num;
            }
        }
    }
    if (num == 0) return 0.0;
    return total / num;
}

double average_in_group_after_two(int group, Student** students, int count) {
    double total = 0.0;
    int num = 0;
    for (int i = 0; i < count; ++i) {
        if (students[i]->get_group() == group) {
            SecondSessionStudent* ss = dynamic_cast<SecondSessionStudent*>(students[i]);
            if (ss) {
                total += ss->average();
                ++num;
            }
        }
    }
    if (num == 0) return 0.0;
    return total / num;
}