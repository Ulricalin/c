#include <iostream>
#include <iomanip>
using namespace std;

class calendarType {
public:
    calendarType(int Year = 1500, int Month = 1);
    void setYear(int Year);
    void setMonth(int Month);
    int getYear();
    int getMonth();
    int getDays(int Year, int Month);
    int  getweek(int year, int month, int date);
    void printweekofdate(int year, int month, int date);
    bool IsLeapYear(int Year);
    void disCalendar(int Year, int Month);
private:
    int year;
    int month;
    int days;
};

int main()
{
    int year, month, day;
    cout << "请输入年份和月份：";
    cout << flush;
    cin >> year >> month;
    calendarType Cal(year, month);
    Cal.disCalendar(year, month);
    /* 
    cout << "请输入年份和月份和日期：";
    cout << flush;
    cin >> year >> month >> day;
    Cal.printweekofdate( year, month, day);
    getchar(); getchar();
    */ 
    return 0;
     
}

calendarType::calendarType(int Year, int Month)
{
    if (Year < 1500 || Year > 3000)
        year = 1500;
    else
        year = Year;
    if (Month > 12 || Month < 1)
        month = 1;
    else
        month = Month;
    getDays(year, month);
}

void calendarType::setYear(int Year)
{
    if (Year >= 1500 && Year <= 3000)
        year = Year;
}

void calendarType::setMonth(int Month)
{
    if (Month >=1 && Month <= 12)
        month = Month;
}

inline int calendarType::getYear()
{
    return year;
}

inline int calendarType::getMonth()
{
    return month;
}

int calendarType::getDays(int Year, int Month)
{
    switch(Month) {
    case 1: case 3: case 5:
    case 7: case 8: case 10:
    case 12:
        days = 31;
        break;
    case 4: case 6: case 9:
    case 11:
        days = 30;
        break;
    case 2:
        if (IsLeapYear(Year))
            days = 29;
        else
            days = 28;
    }
    return days;
}

bool calendarType::IsLeapYear(int Year)
{
    if ((Year % 4 == 0 && Year % 100 != 0)
            || Year % 400 == 0)
        return true;
    else
        return false;
}
int  calendarType::getweek(int year, int month, int date) {
	if (date > getDays(year, month)) return -1; 
	int totalDays = 0;
    for (int i = 1500; i < year; i++)
    {
        if (IsLeapYear(i))
            totalDays += 366;
        else
            totalDays += 365;
    }
    for (int i = 1; i < month; i++)
    {
        totalDays += getDays(year, i);
    }
    totalDays += date;
    return totalDays%7;
}
void calendarType::printweekofdate(int year, int month, int date) {
	cout << year << "年" << month << "月" << " ";
	switch(getweek(year, month, date)) {
		case 0: cout << "Sun" << endl; break;
		case 1: cout << "Mon" << endl; break;
		case 2: cout << "Tue" << endl; break;
		case 3: cout << "Wed" << endl; break;
		case 4: cout << "Thu" << endl; break;
		case 5: cout << "Fri" << endl; break;
		case 6: cout << "Sat" << endl; break;
	}
}
void calendarType::disCalendar(int Year, int Month)
{
    int week = getweek(Year, Month, 1);
    cout << setw(30) << Year << "年" << Month << "月";
    cout << endl;
    cout << setw(8) << "Sun";
    cout << setw(8) << "Mon";
    cout << setw(8) << "Tue";
    cout << setw(8) << "Wed";
    cout << setw(8) << "Thu";
    cout << setw(8) << "Fri";
    cout << setw(8) << "Sat";
    cout << endl;
    week++;
    if (week > 7) week = 1;
    for (int i = 1; i < week; i++)
        cout << setw(8) << "";
    getDays(Year, Month);
    for (int i = 1; i <= days; i++)
    {
        if (week > 7) {
            cout << endl;
            week = 1;
        }
        cout << setw(8) << i;
        week++;
    }
    cout << endl;
}

