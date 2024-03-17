#pragma once
#include "Student.h"

class Group {
public:
    Student** students = nullptr;
private:
    unsigned short size = 0;
    string groupName;
    string specialization;
    unsigned short course = 0;

public:
    Group();

    Group(const Group& original);

    void Print() const;

    void NewStudent(const Student& newstudent);

    void ExcludedStudent(unsigned short index);

    void LaggingStudent();

    void SetCountOfStudent(int countstudent);

    int  GetCountOfStudent() const;

    void SetGroupName(string groupName);

    string GetGroupName() const;

    void SetSpecialization(string specialization);

    string GetSpecialization() const;

    void SetCourse(int course);

    int  GetCourse() const;

    ~Group();


    Group& operator += (const Student& n)
    {
        NewStudent(n);
        return *this;
    }
    void PrintAllStudents() const;

    operator string()
    {
        return groupName + "\n" + specialization + "\n" + tostring(course) + "\n" + tostring(size);

    }
};