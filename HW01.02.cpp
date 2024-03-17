#include "Date.h"
#include "Student.h"
#include <iostream>
#include "Fraction.h"
#include <ctime>
#include <string>;
using namespace std;

int operator - (const Date& date_now, const Date& other_date)
{
    int thisDays = date_now.GetDay() + 31 * (date_now.GetMonth() - 1);
    int otherDays = other_date.GetDay() + 31 * (other_date.GetMonth() - 1);

    thisDays += (date_now.GetYear() % 4 == 0 && date_now.GetMonth() > 2);
    otherDays += (other_date.GetYear() % 4 == 0 && other_date.GetMonth() > 2);

    thisDays += (date_now.GetMonth() > 1);
    otherDays += (other_date.GetMonth() > 1);

    thisDays += date_now.GetMonth() / 2 + ((date_now.GetMonth() % 2 == 0 && date_now.GetMonth() > 7));
    otherDays += other_date.GetMonth() / 2 + ((other_date.GetMonth() % 2 == 0 && other_date.GetMonth() > 7));

    thisDays += 365 * (date_now.GetYear() - 1);
    otherDays += 365 * (other_date.GetYear() - 1);

    return thisDays - otherDays;
}

Group operator + (const Group& one, const Group two)
{
    Group result;
    result.SetGroupName(one.GetGroupName() + two.GetGroupName());
    result.SetCourse(one.GetCourse());
    result.SetSpecialization(one.GetSpecialization());

    for (int i = 0; i < one.GetCountOfStudent(); ++i)
    {
        result.NewStudent(*one.students[i]);
    }
    for (int i = 0; i < two.GetCountOfStudent(); ++i)
    {
        result.NewStudent(*two.students[i]);
    }

    return result;
}


int operator - (const Date& date_now, const Date& other_date)
{
    int thisDays = date_now.GetDay() + 31 * (date_now.GetMonth() - 1);
    int otherDays = other_date.GetDay() + 31 * (other_date.GetMonth() - 1);

    thisDays += (date_now.GetYear() % 4 == 0 && date_now.GetMonth() > 2);
    otherDays += (other_date.GetYear() % 4 == 0 && other_date.GetMonth() > 2);

    thisDays += (date_now.GetMonth() > 1);
    otherDays += (other_date.GetMonth() > 1);

    thisDays += date_now.GetMonth() / 2 + ((date_now.GetMonth() % 2 == 0 && date_now.GetMonth() > 7));
    otherDays += other_date.GetMonth() / 2 + ((other_date.GetMonth() % 2 == 0 && other_date.GetMonth() > 7));

    thisDays += 365 * (date_now.GetYear() - 1);
    otherDays += 365 * (other_date.GetYear() - 1);

    return thisDays - otherDays;
}

bool operator > (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator < (const Student& a, const Student& b)
{
    return a.GetAverageGrade() < b.GetAverageGrade();
}

bool operator >= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator <= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() <= b.GetAverageGrade();
}

bool operator == (const Student& a, const Student& b)
{
    return a.GetAverageGrade() == b.GetAverageGrade();
}

bool operator != (const Student& a, const Student& b)
{
    return a.GetAverageGrade() != b.GetAverageGrade();
}

bool operator > (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() > b.GetCountOfStudent();
}

bool operator < (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() < b.GetCountOfStudent();
}

bool operator >= (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() >= b.GetCountOfStudent();
}

bool operator <= (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() <= b.GetCountOfStudent();
}

bool operator == (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() == b.GetCountOfStudent();
}

bool operator != (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() != b.GetCountOfStudent();
}

istream& operator >> (const istream& i, Student& d)
{

    cout << "surname: ";
    string answear;
    cin >> answear;
    d.SetSurname(answear);

    cout << "name: ";
    cin >> answear;
    d.SetName(answear);

    cout << "middle name: ";
    cin >> answear;
    d.SetMiddlName(answear);

    cout << "adress: ";
    cin >> answear;
    d.SetAdress(answear);

    cout << "phone: ";
    cin >> answear;
    d.SetPhone(answear);

    return cin;

}

ostream& operator << (const ostream& i, Student& d)
{
    d.PrintStudent();
    d.PrintExam();
    d.PrintPractic();
    d.PrintHomeWork();
    return cout;
}

istream& operator >> (const istream& i, Group& g)
{

    cout << "Group: ";
    string answear;
    cin >> answear;
    g.SetGroupName(answear);

    cout << "Group Specialization: ";
    cin >> answear;
    g.SetSpecialization(answear);

    cout << "Course: ";
    unsigned short amswear2;
    cin >> amswear2;
    g.SetCourse(amswear2);

    return cin;

}

ostream& operator << (const ostream& i, Student& d)
{
    d.PrintStudent();
    d.PrintExam();
    d.PrintPractic();
    d.PrintHomeWork();
    return cout;
}

istream& operator >> (const istream& i, Group& g)
{

    cout << "Group Name: ";
    string answear;
    cin >> answear;
    g.SetGroupName(answear);

    cout << "Group Specification: ";
    cin >> answear;
    g.SetSpecialization(answear);

    cout << "Course: ";
    unsigned short amswear2;
    cin >> amswear2;
    g.SetCourse(amswear2);

    return cin;

}


ostream& operator << (const ostream& i, Group& d)
{
    d.Print();
    return cout;
}

istream& operator >> (const istream& i, Fraction& f)
{

    cout << "numerator: ";
    int answear;
    cin >> answear;
    f.SetNumerator(answear);

    cout << "denominator: ";
    cin >> answear;
    f.SetDenominator(answear);

    return cin;

}

ostream& operator << (const ostream& i, Fraction& f)
{
    f.Print();
    return cout;
}

int main()
//1
    //Student Malika;
    //s.AddExam(4);
    //s.AddExam(10);
    //s.AverageGrade();

    //string a = (string)m;
    //cout << a;

    //2
    //Student Malika;
    //Student d;

    //Group g;
    //g += s;
    //g += d;

    //string str = (string)g;
    //cout << str;

    //3:
    //Date today
    //today++; 
    //++today; 
    //--today;
    //today--; 
    //today += 4;
    //today.PrintDate();

    //Date d(13, 3, 2019);
    //d++;
    //d.PrintDate();
}


