#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <ctime>

using namespace std;
#define ll long long

struct Date
{
    int day;
    int month;
    int year;
};

const int thisYear = 2024;

struct Name
{
    string firstName;
    string lastName;
};

struct Student
{
    string id;
    Name fullname;
    string address;
    double gpa;
    Date birth;
    char CLASS[2];
};

struct Course
{

    string courseID;
    string courseName;
    int currentMemNum;
    Student member[100];
    bool Status_opening;
    int maximumMemNum;
    int minimumMemNum;
};
void executeP02();
bool compareCharArr(char a[2], char b[2]);
void getTheCurrentDate(Date &today);
bool leapYear(int year);
bool checkDate(Date a);
void inputDate(Date &a);
void outputDate(Date a);
int compare(Date a, Date b);
void tomorrowOf(Date &a);
void yesterdayOf(Date &a);
int distanceBetween(Date a, Date b);
void extractStudentClass(Student &a);
void inputStudent(Student &tmpStu);
void outputStudent(Student tmpStu);
void outputStudentWithAge(Student tmpStu);
int compareByID(Student a, Student b);
int compareByGPA(Student a, Student b);
int comparebyName(Student a, Student b);
int compareByFirstname(Student a, Student b);
int compareByLastName(Student a, Student b);
int compareByDateOfBirth(Student a, Student b);
//
void executeP03();
void inputCourse(Course &tmp);
void outputCourse(Course tmp);
void outputMemberForCourse(Student a);
void addStudentToCourse(Course &a, Student newStu);
void rmStudentToCourse(Course &a, int pos);
bool bornInThisMonth(Student stu);
bool bornInThisDate(Student stu);
bool getDriverLicences(Student stu);
bool is_K19(Student a);
void printK19(Course a);
void printByID(Course a, string Id);
bool FoundName(Student a, string b);
void findByName(Course a, string nameToFind);
void sortByID(Course &a);
void sortByFirstname(Course &a);
void sortByGPA(Course &a);
void sortByDOB(Course &a);

int main()
{

    int choice;
    do
    {
        cout << "1. CHUONG TRINH P02" << endl;
        cout << "2. CHUONG TRINH P03" << endl;
        cout << "0. THOAT" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("clear");
            executeP02(); break;
        }
        case 2:
        {
            system("clear");
            executeP03(); break;
        }
        case 0:
        {
            exit(0);
            break;
        }
        default:
        {
            exit(0);
            break;
        }

        }
        system("clear");
    } while (choice);

    return 0;
}

void executeP02()
{
    int input;
    Student tmp = {"NULL", {"NULL", "NULL"}, "NULL", 0, {0, 0, 0}, 0};
    do
    {
        cout << "CHUONG TRINH P02" << endl;
        cout << "1. Nhap vao hoc sinh" << endl;
        cout << "2. Xuat hoc sinh vua nhap" << endl;
        cout << "3. Xuat hoc sinh voi tuoi tinh bang nam, thang, ngay" << endl;
        cout << "4. Xac dinh lop cua hoc sinh" << endl;
        cout << "5. So sanh hai hoc sinh bang ID" << endl;
        cout << "6. So sanh hai hoc sinh bang GPA" << endl;
        cout << "7. So sanh hai hoc sinh bang ho va ten" << endl;
        cout << "8. So sanh hai hoc sinh bang ho" << endl;
        cout << "9. So sanh hai hoc sinh bang ten" << endl;
        cout << "10. So sanh hai hoc sinh bang ngay sinh" << endl;
        cout << "0. THOAT" << endl;
        cout<<"Nhap lua chon: ";
        cin>>input;

        switch (input)
        {
        case 1:
        {
            inputStudent(tmp);
            break;
        }
        case 2:
        {
            outputStudent(tmp);
            break;
        }
        case 3:
        {
            outputStudentWithAge(tmp);
            break;
        }
        case 4:
        {
            cout << "Lop cua hoc sinh la: K" << tmp.CLASS[0] << tmp.CLASS[1] << endl;
            break;
        }
        case 5:
        {
            Student a, b;
            cout << "Nhap thong tin hai hoc sinh de so sanh: ";
            inputStudent(a);
            inputStudent(b);

            if (compareByID(a, b) > 0)
            {
                cout << "ID cua hoc sinh thu nhat lon hon hoc sinh thu hai" << endl;
            }
            else if (compareByID(a, b) == 0)
            {
                cout << "ID cua hai hoc sinh giong nhau" << endl;
            }
            else
            {
                cout << "ID cua hoc sinh thu nhat nho hon hoc sinh thu hai" << endl;
            }
            break;
        }
        case 6:
        {
            Student a, b;
            cout << "Nhap thong tin hai hoc sinh de so sanh: ";
            inputStudent(a);
            inputStudent(b);

            if (compareByGPA(a, b) > 0)
            {
                cout << "GPA cua hoc sinh thu nhat lon hon hoc sinh thu hai" << endl;
            }
            else if (compareByGPA(a, b) == 0)
            {
                cout << "GPA cua hai hoc sinh bang nhau" << endl;
            }
            else
            {
                cout << "GPA cua hoc sinh thu nhat nho hon hoc sinh thu hai" << endl;
            }
            break;
        }
        case 7:
        {
            Student a, b;
            cout << "Nhap thong tin hai hoc sinh de so sanh: ";
            inputStudent(a);
            inputStudent(b);

            if (comparebyName(a, b) > 0)
            {
                cout << "Ho va Ten cua hoc sinh thu nhat dung sau hoc sinh thu hai" << endl;
            }
            else if (compareByGPA(a, b) == 0)
            {
                cout << "Ho va Ten cua hai hoc sinh giong nhau" << endl;
            }
            else
            {
                cout << "Ho va Ten cua hoc sinh thu nhat dung truoc hoc sinh thu hai" << endl;
            }
            break;
        }
        case 8:
        {
            Student a, b;
            cout << "Nhap thong tin hai hoc sinh de so sanh: ";
            inputStudent(a);
            inputStudent(b);

            if (compareByFirstname(a, b) > 0)
            {
                cout << "Ho cua hoc sinh thu nhat dung sau hoc sinh thu hai" << endl;
            }
            else if (compareByFirstname(a, b) == 0)
            {
                cout << "Ho cua hai hoc sinh giong nhau" << endl;
            }
            else
            {
                cout << "Ho cua hoc sinh thu nhat dung truoc hoc sinh thu hai" << endl;
            }
            break;
        }
        case 9:
        {
            Student a, b;
            cout << "Nhap thong tin hai hoc sinh de so sanh: ";
            inputStudent(a);
            inputStudent(b);

            if (compareByLastName(a, b) > 0)
            {
                cout << "Ten cua hoc sinh thu nhat dung sau hoc sinh thu hai" << endl;
            }
            else if (compareByLastName(a, b) == 0)
            {
                cout << "Ten cua hai hoc sinh giong nhau" << endl;
            }
            else
            {
                cout << "Ten cua hoc sinh thu nhat dung truoc hoc sinh thu hai" << endl;
            }
            break;
        }
        case 10:
        {
            Student a, b;
            cout << "Nhap thong tin hai hoc sinh de so sanh: ";
            inputStudent(a);
            inputStudent(b);

            if (compareByDateOfBirth(a, b) > 0)
            {
                cout << "Hoc sinh thu nhat sinh ra truoc hoc sinh thu hai" << endl;
            }
            else if (compareByDateOfBirth(a, b) == 0)
            {
                cout << "Hai hoc sinh sinh cung ngay" << endl;
            }
            else
            {
                cout << "Hoc sinh thu nhat sinh ra sau hoc sinh thu hai" << endl;
            }
            break;
        }

        case 0:
        {
            exit(0);
            break;
        }
        default:
        {
            exit(0);
            break;
        }
        }
        system("pause");
        system("clear");

    } while (input);
}

void uppercase(string &a)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] = a[i] - 'a' + 'A';
        }
    }
}

bool compareCharArr(char a[2], char b[2])
{
    if (a[0] != b[0] || a[1] != b[1])
    {
        return false;
    }
    else
    {
        return true;
    }
}

void getTheCurrentDate(Date &today)
{
    time_t t = time(nullptr); // Get the current time
    tm *now = localtime(&t);
    today.day = now->tm_mday;
    today.month = (now->tm_mon + 1);
    today.year = (now->tm_year + 1900);
}

bool leapYear(int year)
{
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
    {
        return true;
    }
    return false;
}

bool checkDate(Date a)
{
    bool leapYear = 0;
    if ((a.year % 4 == 0 && a.year % 100 != 0) || a.year % 400 == 0)
    {
        leapYear = 1;
    }

    int dayNumInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (a.month != 2)
    {
        if (a.day < 0 || a.day > dayNumInMonth[a.month])
        {
            return false;
        }
    }
    else
    {
        if (a.day < 0 || a.day > dayNumInMonth[a.month] + (int)leapYear)
        {
            return false;
        }
    }
    return true;
}

void inputDate(Date &a)
{
    int inpCount = 0;
    do
    {
        if (inpCount)
        {
            cout << "Ngay khong hop le!" << endl;
        }
        cin >> a.day;
        cin >> a.month;
        cin >> a.year;
        inpCount++;
    } while (checkDate(a) == false);
}

void outputDate(Date a)
{
    cout << (a.day) / 10 << a.day % 10 << '/' << a.month / 10 << a.month % 10 << '/' << a.year << endl;
}

int compare(Date a, Date b)
{
    if (a.year == b.year)
    {
        if (a.month == b.month)
        {
            if (a.day == b.day)
            {
                return 0;
            }
            return a.day - b.day;
        }
        return a.month - b.month;
    }
    return a.year - b.year;
}

void tomorrowOf(Date &a)
{
    bool leapYear = 0;
    if ((a.year % 4 == 0 && a.year % 100 != 0) || a.year % 400 == 0)
    {
        leapYear = 1;
    }
    int dayNumInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    a.day++;
    if (a.month != 2 && a.month != 12)
    {
        if (a.day == dayNumInMonths[a.month] + 1)
        {
            a.day = 1;
            a.month++;
        }
    }
    else if (a.month == 2 && a.day == dayNumInMonths[a.month] + leapYear + 1)
    {
        a.day = 1;
        ++a.month;
    }
    else if (a.month == 12 && a.day == dayNumInMonths[a.month] + 1)
    {
        a.day = 1;
        a.month = 1;
        ++a.year;
    }
}

void yesterdayOf(Date &a)
{
    bool leapYear = 0;
    if ((a.year % 4 == 0 && a.year % 100 != 0) || a.year % 400 == 0)
    {
        leapYear = 1;
    }

    a.day--;
    int dayNumInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (a.month != 1 && a.month != 3)
    {
        if (a.day == 0)
        {
            a.day = dayNumInMonths[a.month];
            a.month--;
        }
    }
    else if (a.month == 1 && a.day == 0)
    {
        a.month = 12;
        a.day = dayNumInMonths[a.month];
        a.year--;
    }
    else if (a.month == 3 && a.day == 0)
    {
        a.day = (leapYear) ? (29) : (28);
        a.month--;
    }
}

int distanceBetween(Date a, Date b)
{
    if (compare(a, b) < 0)
    {
        int count = 0;
        do
        {
            tomorrowOf(a);
            count++;
        } while (compare(a, b));
        return count;
    }
    else if (compare(a, b) > 0)
    {
        int count = 0;
        do
        {
            tomorrowOf(b);
            count++;
        } while (compare(a, b));
        return count;
    }
    else
        return 0;
}

void extractStudentClass(Student &a)
{
    string tmp = a.id;
    a.CLASS[0] = tmp[0];
    a.CLASS[1] = tmp[1];
}

void inputStudent(Student &tmpStu)
{

    cout << "ID: ";
    cin >> tmpStu.id;

    cout << "Ho va Ten: ";
    cin.ignore();
    getline(cin, tmpStu.fullname.firstName, ' ');
    uppercase(tmpStu.fullname.firstName);
    getline(cin, tmpStu.fullname.lastName);
    uppercase(tmpStu.fullname.lastName);

    cout << "DTB (GPA): ";
    cin >> tmpStu.gpa;
    cin.ignore();

    cout << "Dia chi (Address): ";
    getline(cin, tmpStu.address);

    cout << "Ngay sinh (Birthday): ";
    inputDate(tmpStu.birth);

    extractStudentClass(tmpStu);
}

void outputStudent(Student tmpStu)
{
    cout << "ID: " << tmpStu.id << endl;
    cout << "Ho va Ten: " << tmpStu.fullname.firstName << " " << tmpStu.fullname.lastName << endl;
    cout << "DTB: " << tmpStu.gpa << endl;
    cout << "Dia Chi: " << tmpStu.address << endl;
    cout << "Ngay sinh: ";
    outputDate(tmpStu.birth);
}

void outputStudentWithAge(Student tmpStu)
{

    cout << "ID: " << tmpStu.id << endl;
    cout << "Ho va Ten: " << tmpStu.fullname.firstName << " " << tmpStu.fullname.lastName << endl;
    cout << "DTB: " << tmpStu.gpa << endl;
    cout << "Dia Chi: " << tmpStu.address << endl;

    Date today;
    getTheCurrentDate(today);
    int tmp = distanceBetween(today, tmpStu.birth);
    int leapYearCount = 0;
    for (int i = tmpStu.birth.year; i <= today.year; i++)
    {
        if (leapYear(i))
        {
            leapYearCount++;
        }
    }
    int lyear = (tmp - leapYearCount) / 365;
    tmp = tmp % 365 - leapYearCount;
    int lmonth = tmp / 30;
    tmp -= lmonth * 30;
    int lday = tmp;
    cout << "So tuoi: " << lyear << " nam, " << lmonth << " thang, " << lday << " ngay" << endl;
}

int compareByID(Student a, Student b)
{
    if (a.id == b.id)
    {
        return 0;
    }
    int tmp1 = stoi(a.id);
    int tmp2 = stoi(b.id);

    return tmp1 - tmp2;
}

int compareByGPA(Student a, Student b)
{
    return a.gpa - b.gpa;
}

int comparebyName(Student a, Student b)
{

    if (a.fullname.firstName == b.fullname.firstName && a.fullname.lastName == b.fullname.lastName)
    {
        return 0;
    }
    int fnlengthA = a.fullname.firstName.length();
    int fnlengthB = b.fullname.firstName.length();

    for (int i = 0; i < min(fnlengthA, fnlengthB); i++)
    {
        if (a.fullname.firstName[i] != b.fullname.firstName[i])
        {
            return a.fullname.firstName[i] - b.fullname.firstName[i];
        }
    }
    if (fnlengthA != fnlengthB)
    {
        return fnlengthA - fnlengthB;
    }

    int lnlengthA = a.fullname.lastName.length();
    int lnlengthB = b.fullname.lastName.length();

    for (int i = 0; i < min(lnlengthA, lnlengthB); i++)
    {
        if (a.fullname.lastName[i] != b.fullname.lastName[i])
        {
            return a.fullname.lastName[i] - b.fullname.lastName[i];
        }
    }
    return fnlengthA + lnlengthA - (fnlengthB + lnlengthB);
}

int compareByFirstname(Student a, Student b)
{
    int tmp;
    if (a.fullname.firstName == b.fullname.firstName)
    {
        return 0;
    }
    int fnlengthA = a.fullname.firstName.length();
    int fnlengthB = b.fullname.firstName.length();

    for (int i = 0; i < min(fnlengthA, fnlengthB); i++)
    {
        if (a.fullname.firstName[i] != b.fullname.firstName[i])
        {
            return a.fullname.firstName[i] - b.fullname.firstName[i];
        }
    }
    if (fnlengthA != fnlengthB)
    {
        return fnlengthA - fnlengthB;
    }
}

int compareByLastName(Student a, Student b)
{
    if (a.fullname.firstName == b.fullname.firstName && a.fullname.lastName == b.fullname.lastName)
    {
        return 0;
    }
    int lnlengthA = a.fullname.lastName.length();
    int lnlengthB = b.fullname.lastName.length();

    for (int i = 0; i < min(lnlengthA, lnlengthB); i++)
    {
        if (a.fullname.lastName[i] != b.fullname.lastName[i])
        {
            return a.fullname.lastName[i] - b.fullname.lastName[i];
        }
    }
    return lnlengthA - (lnlengthB);
}

int compareByDateOfBirth(Student a, Student b)
{
    return compare(a.birth, b.birth);
}

////////////////////////////////////////////////////////////

void executeP03()
{
    int input;
    Course tmp;
    do
    {
        cout << "CHUONG TRINH P03" << endl;
        cout << "1. Nhap vao 1 hoc phan" << endl;
        cout << "2. Xuat thong tin cua hoc phan vua nhap" << endl;
        cout << "3. Them hoc sinh vao hoc phan" << endl;
        cout << "4. Xoa hoc sinh o mot vi tri trong hoc phan" << endl;
        cout << "5. Tim nhung hoc sinh co ngay sinh giong voi thang hien tai" << endl;
        cout << "6. Tim nhung hoc sinh co ngay sinh giong voi ngay hien tai" << endl;
        cout << "7. Tim nhung hoc sinh du 18 tuoi lay bang lai" << endl;
        cout << "8. Tim nhung hoc sinh o lop K19" << endl;
        cout << "9. Tim nhung hoc sinh theo ten" << endl;
        cout << "10. Sap xep theo ID" << endl;
        cout << "11. Sap xep theo GPA" << endl;
        cout << "12. Sap xep theo ngay sinh" << endl;
        cout << "0. THOAT " << endl;
        cout<<"Nhap lua chon: ";
        cin >> input;
        switch (input)
        {
        case 1:
        {
            inputCourse(tmp);
            break;
        }
        case 2:
        {
            outputCourse(tmp);
            break;
        }
        case 3:
        {
            Student newGuy;
            cout << "Nhap thong tin cua hoc sinh moi: ";
            inputStudent(newGuy);
            addStudentToCourse(tmp, newGuy);

            cout << "Thong tin hoc phan hien tai:"<<endl;
            outputCourse(tmp);
            break;
        }
        case 4:
        {
            int pos;
            do
            {
                cout << "Nhap vi tri de xoa(tu 1 den so hoc sinh hien tai): ";
                cin >> pos;
            } while (pos <= 0);
            rmStudentToCourse(tmp, pos);

            cout << "Thong tin hoc phan hien tai:"<<endl;
            outputCourse(tmp);
            break;
        }
        case 5:
        {
            cout << "Cac hoc sinh co ngay sinh giong voi thang hien tai: " << endl;
            for (int i = 0; i < tmp.currentMemNum; i++)
            {
                if (bornInThisMonth(tmp.member[i]))
                {
                    outputMemberForCourse(tmp.member[i]);
                }
            }
            break;
        }
        case 6:
        {
            cout << "Cac hoc sinh co ngay sinh giong ngay hien tai: " << endl;
            for (int i = 0; i < tmp.currentMemNum; i++)
            {
                if (bornInThisDate(tmp.member[i]))
                {
                    outputMemberForCourse(tmp.member[i]);
                }
            }
            break;
        }
        case 7:
        {
            cout << "Cac hoc sinh du tuoi lay bang lai: " << endl;
            for (int i = 0; i < tmp.currentMemNum; i++)
            {
                if (getDriverLicences(tmp.member[i]))
                {
                    outputMemberForCourse(tmp.member[i]);
                }
            }
            break;
        }
        case 8:
        {
            cout << "Cac hoc sinh o lop K19: " << endl;
            for (int i = 0; i < tmp.currentMemNum; i++)
            {
                if (is_K19(tmp.member[i]))
                {
                    outputMemberForCourse(tmp.member[i]);
                }
            }
            break;
        }
        case 9:
        {
            string nameToFind;
            cout << "Nhap Ho (hoac Ho va Ten) cua hoc sinh de tim kiem: ";
            cin.ignore();
            getline(cin, nameToFind);
            findByName(tmp,nameToFind);
            break;
        }
        case 10:
        {
            cout << "Danh sach hoc sinh da duoc sap xep theo ID: " << endl;
            sortByID(tmp);
            for (int i = 0; i < tmp.currentMemNum; i++)
            {
                outputMemberForCourse(tmp.member[i]);
            }
            break;
        }
        case 11:
        {
            cout << "Danh sach hoc sinh da duoc sap xep theo GPA: " << endl;
            sortByGPA(tmp);
            for (int i = 0; i < tmp.currentMemNum; i++)
            {
                outputMemberForCourse(tmp.member[i]);
            }
            break;
        }
        case 12:
        {
            cout << "Danh sach hoc sinh da duoc sap xep theo ngay sinh: " << endl;
            sortByDOB(tmp);
            for (int i = 0; i < tmp.currentMemNum; i++)
            {
                outputMemberForCourse(tmp.member[i]);
            }
            break;
        }
        case 0:
        {
            exit(0);
        }
        default:
        {
            exit(0);
        }
        }
        system("pause");
        system("clear");
    } while (input);

}

void inputCourse(Course &tmp)
{
    cin.ignore();
    cout << "Ma hoc phan: ";
    getline(cin, tmp.courseID);

    cout << "Ten hoc phan: ";
    //cin.ignore();
    getline(cin, tmp.courseName);

    int inpCount = 0;
    do
    {
        if (inpCount != 0)
        {
            cout << "Khong hop le!" << endl;
        }
        cout << "Nhap so luong hoc sinh cua hoc phan: ";
        cin >> tmp.currentMemNum;
    } while (tmp.currentMemNum <= 0);

    for (int i = 0; i < tmp.currentMemNum; i++)
    {
        cout << "Hoc sinh so " << i + 1 << ":";
        inputStudent(tmp.member[i]);
    }
}

void outputMemberForCourse(Student a)
{
    cout << "ID: " << a.id << " ";
    cout << "Ho va Ten: " << a.fullname.firstName << " " << a.fullname.lastName << " ";
    cout << "Ngay sinh: ";
    outputDate(a.birth);
    cout << "Dia chi: " << a.address << " DTB: " << a.gpa << endl;
}

void outputCourse(Course tmp)
{
    cout << "Course ID: " << tmp.courseID << endl;
    cout << "Course Name: " << tmp.courseName << endl;

    for (int i = 0; i < tmp.currentMemNum; i++)
    {
        outputMemberForCourse(tmp.member[i]);
    }
}

void addStudentToCourse(Course &a, Student newStu)
{
    a.currentMemNum++;
    a.member[a.currentMemNum - 1] = newStu;
}

void rmStudentToCourse(Course &a, int pos)
{
    for (int i = pos - 1; i < a.currentMemNum; i++)
    {
        a.member[i] = a.member[i + 1];
    }
    a.currentMemNum--;
}

bool bornInThisMonth(Student stu)
{
    Date tmp;
    getTheCurrentDate(tmp);
    if (stu.birth.month == tmp.month)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool bornInThisDate(Student stu)
{
    Date tmp;
    getTheCurrentDate(tmp);
    if (stu.birth.day == tmp.day && stu.birth.month == tmp.month )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool getDriverLicences(Student stu)
{
    Date tmp;
    getTheCurrentDate(tmp);
    int tmp2 = stu.birth.year+18;
    if (compare({stu.birth.day, stu.birth.month, tmp2}, tmp) >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_K19(Student a)
{
    char K19[2] = {'1','9'};
    if (compareCharArr(a.CLASS, K19))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printK19(Course a)
{
    for (int i = 0; i < a.currentMemNum; i++)
    {
        if (is_K19(a.member[i]))
        {
            outputMemberForCourse(a.member[i]);
        }
    }
}

void printByID(Course a, string Id)
{
    for (int i = 0; i < a.currentMemNum; i++)
    {
        if (a.member[i].id == Id)
        {
            outputMemberForCourse(a.member[i]);
        }
    }
}

bool FoundName(Student a, string b)
{
    string tmp = a.fullname.firstName + " " + a.fullname.lastName;
    if (a.fullname.firstName == b || (b == tmp))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void findByName(Course a, string nameToFind)
{
    uppercase(nameToFind);
    for (int i = 0; i < a.currentMemNum; i++)
    {
        if (FoundName(a.member[i], nameToFind))
        {
            outputMemberForCourse(a.member[i]);
        }
    }
}

void sortByID(Course &a)
{
    int n = a.currentMemNum;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compareByID(a.member[i], a.member[j]) > 0)
            {
                Student tmp = a.member[i];
                a.member[i] = a.member[j];
                a.member[j] = tmp;
            }
        }
    }
}

void sortByFirstname(Course &a)
{
    int n = a.currentMemNum;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compareByFirstname(a.member[i], a.member[j]) > 0)
            {
                Student tmp = a.member[i];
                a.member[i] = a.member[j];
                a.member[j] = tmp;
            }
        }
    }
}

void sortByGPA(Course &a)
{
    int n = a.currentMemNum;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compareByGPA(a.member[i], a.member[j]) > 0)
            {
                Student tmp = a.member[i];
                a.member[i] = a.member[j];
                a.member[j] = tmp;
            }
        }
    }
}

void sortByDOB(Course &a)
{
    int n = a.currentMemNum;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compareByDateOfBirth(a.member[i], a.member[j]) > 0)
            {
                Student tmp = a.member[i];
                a.member[i] = a.member[j];
                a.member[j] = tmp;
            }
        }
    }
}
