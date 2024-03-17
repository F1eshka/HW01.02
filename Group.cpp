#include "Group.h"

Group::Group() 
{
    SetGroupName("P26");
    SetCourse(3);
    SetSpecialization("Programmer and software developer");
}


Group::Group(const Group& original){
    this->size = original.size;
    this->students = new Student * [original.size];

    for (int i = 0; i < size; ++i) {
        this->students[i] = new Student(*original.students[i]);
    }

    this->groupName = original.groupName;
    this->specialization = original.specialization;
    this->course = original.course;
}


void Group::Print() const
{
    cout << groupName << "\n";
    for (int i = 0; i < size; i++)
    {
        students[i]->PrintStudent();
        students[i]->PrintExam();
        students[i]->PrintHomeWork();
        students[i]->PrintPractic();
        students[i]->AverageGrade();
    }
}

void Group::NewStudent(const Student& newstudent)
{
    Student** temp = new Student * [size + 1];

    for (int i = 0; i < size; ++i)
    {
        temp[i] = students[i];
    }

    temp[size] = new Student(newstudent);
    size++;
    delete[]students;
    students = temp;
}

void Group::ExcludedStudent(unsigned short index)
{
    Student** temp = new Student * [size - 1];
    for (int i = 0, j = 0; i < size; i++)
    {
        if (i != index)
        {
            temp[j++] = students[i];
        }
    }
    delete students[index];
    delete[] students;
    size--;
    students = temp;
}

void Group::LaggingStudent()
{
    if (size == 0) {
        cout << "The group is empty.\n";
        return;
    }
    int minGradeIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (students[i]->GetAverageGrade() < students[minGradeIndex]->GetAverageGrade()) {
            minGradeIndex = i;
        }
    }
    Student** temp = new Student * [size - 1];
    for (int i = 0, j = 0; i < size; i++)
    {
        if (i != minGradeIndex) {
            temp[j++] = students[i];
        }
    }
    delete students[minGradeIndex];
    delete[] students;
    size--;
    students = temp;
    cout << "The student with the lowest grade is expelled\n";
}
void Group::SetCountOfStudent(int size)
{
    this->size = size;
}

int Group::GetCountOfStudent() const
{
    return size;
}

    void Group::SetGroupName(const string& groupName) {
        this->groupName = groupName;
    }

    string Group::GetGroupName() const {
        return groupName;
    }

    void Group::SetSpecialization(const string& specialization) {
        this->specialization = specialization;
    }

    string Group::GetSpecialization() const {
        return specialization;
    }

    void Group::SetCourse(int course) {
        this->course = course;
    }

    int Group::GetCourse() const {
        return course;
    }

    void Group::PrintAllStudents() const {
        cout << GetGroupName() << "\n";

        for (int i = 0; i < size; ++i) {
            students[i]->PrintStudent();
        }
    }

        Group::~Group() {
            for (int i = 0; i < size; ++i) {
                delete students[i];
            }
            delete[] students;
        }
    };