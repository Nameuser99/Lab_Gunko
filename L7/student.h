// student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
private:
    int id;
    std::string name;
    int course;
    int group;
    const int record_book_number;
    static int next_id;

protected:
    void set_name(const std::string& new_name);

public:
    Student(const std::string& init_name, int init_course, int init_group, int init_record_book);
    Student(const Student& other);
    ~Student();
    int get_id() const;
    const std::string& get_name() const;
    int get_course() const;
    void set_course(int new_course);
    int get_group() const;
    void set_group(int new_group);
    int get_record_book_number() const;
    virtual double average() const;
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

class FirstSessionStudent : public Student {
private:
    int first_grades[4];

public:
    FirstSessionStudent(const std::string& init_name, int init_course, int init_group, int init_record_book, const int init_grades[4]);
    FirstSessionStudent(const FirstSessionStudent& other);
    int get_first_grade(int index) const;
    void set_first_grade(int index, int value);
    double average() const override;
    friend std::ostream& operator<<(std::ostream& os, const FirstSessionStudent& s);
};

class SecondSessionStudent : public FirstSessionStudent {
private:
    int second_grades[5];

public:
    SecondSessionStudent(const std::string& init_name, int init_course, int init_group, int init_record_book, const int init_first_grades[4], const int init_second_grades[5]);
    SecondSessionStudent(const SecondSessionStudent& other);
    int get_second_grade(int index) const;
    void set_second_grade(int index, int value);
    double average() const override;
    friend std::ostream& operator<<(std::ostream& os, const SecondSessionStudent& s);
};

double average_in_group_after_first(int group, Student** students, int count);
double average_in_group_after_two(int group, Student** students, int count);

#endif