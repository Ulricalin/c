#include <iostream>
#include <iomanip>
using namespace std;
class Date {
	private:
    	int m_year;
    	int m_month;
    	int m_day;
	public:
  Date();

  Date(int t_year, int t_month, int t_day);

  Date(std::string dateString);

  int getYear(void) const;

  void setYear(const int t_year);

  int getMonth(void) const;

  void setMonth(const int t_month);

  int getDay(void) const;

  void setDay(const int t_day);

  static bool isValid(const Date t_date);

  Date &operator=(const Date &t_date);

  bool operator==(const Date &t_date) const;

  bool operator>(const Date &t_date) const;

  bool operator<(const Date &t_date) const;

  bool operator>=(const Date &t_date) const;

  bool operator<=(const Date &t_date) const;
};
Date::Date(int t_year, int t_month, int t_day):m_year(t_year),
    m_month(t_month), m_day(t_day) {}
int Date::getYear(void) const {
    return m_year;
}

void Date::setYear(const int t_year) {
    m_year = t_year;
}

int Date::getMonth(void) const {
    return m_month;
}

void Date::setMonth(const int t_month) {
    m_month = t_month;
}

int Date::getDay(void) const {
    return m_day;
}

void Date::setDay(const int t_day) {
    m_day = t_day;
}
bool Date::isValid(const Date t_date) {
    if (t_date.getMonth() <= 0 ||t_date.getMonth() > 12) return false;
    if (t_date.getDay()  <= 0) return false;
    else if ((t_date.getMonth()%2 == 1 && t_date.getMonth() < 8) || (t_date.getMonth() >= 8 && t_date.getMonth()%2 == 0)) {
        if (t_date.getDay() > 31) return false;
    }
    else if (t_date.getMonth() != 2) {
        if (t_date.getDay() > 30) return false;
    }
    else if ((t_date.getYear()%4 == 0 && t_date.getYear()%100 != 0 )|| t_date.getYear()%400 == 0) {
        if (t_date.getDay() > 29) return false;
    } else {
        if (t_date.getDay() > 28) return false;
    }
    return true;
}
Date &Date::operator=(const Date &t_date) {
    m_year = t_date.m_year;
    m_month = t_date.m_month;
    m_day = t_date.m_day;
    return *this;
}

/**
* @brief check whether the CurrentDate is equal to the t_date
*/
bool Date::operator==(const Date &t_date) const {
    if (m_year == t_date.m_year &&
    m_month == t_date.m_month &&
    m_day == t_date.m_day) return true;
    return false;
}

/**
* @brief check whether the CurrentDate is  greater than the t_date
*/
bool Date::operator>(const Date &t_date) const {
    if (m_year > t_date.m_year) return true;
    if (m_year < t_date.m_year) return false;
    if (m_month > t_date.m_month) return true;
    if (m_month < t_date.m_month) return false;
    if (m_day > t_date.m_day) return true;
    if (m_day < t_date.m_day) return false;

    return false;
}

/**
* @brief check whether the CurrentDate is  less than the t_date
*/
bool Date::operator<(const Date &t_date) const {
    if (m_year < t_date.m_year) return true;
    if (m_year > t_date.m_year) return false;
    if (m_month < t_date.m_month) return true;
    if (m_month > t_date.m_month) return false;
    if (m_day < t_date.m_day) return true;
    if (m_day > t_date.m_day) return false;

    return false;
}

/**
* @brief check whether the CurrentDate is  greater or equal than the t_date
*/
bool Date::operator>=(const Date &t_date) const {
    if (m_year > t_date.m_year) return true;
    if (m_year < t_date.m_year) return false;
    if (m_month > t_date.m_month) return true;
    if (m_month < t_date.m_month) return false;
    if (m_day > t_date.m_day) return true;
    if (m_day < t_date.m_day) return false;

    return true;
}

/**
* @brief check whether the CurrentDate is  less than or equal to the t_date
*/
bool Date::operator<=(const Date &t_date) const {
    if (m_year < t_date.m_year) return true;
    if (m_year > t_date.m_year) return false;
    if (m_month < t_date.m_month) return true;
    if (m_month > t_date.m_month) return false;
    if (m_day < t_date.m_day) return true;
    if (m_day > t_date.m_day) return false;

    return true;
}

class calendar {
public:
	static int getDays(int Year, int Month);
    static int  getweek(int year, int month, int date);
	static void disCalendar(int Year, int Month);
	static void printweekofdate(int year, int month, int date);
    static int datebetween(int year1, int month1, int date1,
    						int year2, int month2, int date2);
    static bool IsLeapYear(int Year);
};

int calendar::getDays(int Year, int Month)
{	int days;
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
        break;
    }
    return days;
}

bool calendar::IsLeapYear(int Year)
{
    if ((Year % 4 == 0 && Year % 100 != 0)
            || Year % 400 == 0)
        return true;
    else
        return false;
}

int  calendar::getweek(int year, int month, int date) {
	if (date > getDays(year, month)) return -1; 
	int totalDays = 0;
	year = year%400;
	if (year == 0) year = 400;
    for (int i = 1; i < year; i++)
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

void calendar::printweekofdate(int year, int month, int date) {
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

void calendar::disCalendar(int Year, int Month)
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
    int days = getDays(Year, Month);
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

int calendar::datebetween(int year1, int month1, int date1,
    						int year2, int month2, int date2) {
	Date D1(year1, month1, date1), D2(year2, month2, date2);
	if (!(Date::isValid(D1) && Date::isValid(D2))) return -1;
	if (D1 < D2) {
		Date temp = D1;
		D1 = D2;
		D2 = temp;
	}
	int totalDays = 0;
	if (D1.getYear() > D2.getYear()) {
		totalDays = getDays(D2.getYear(), D2.getMonth()) - D2.getDay();
		for (int i = D2.getMonth()+1; i <= 12; i++) {
			totalDays += getDays(D2.getYear(), i);
		}
		for (int i = D2.getYear()+1; i < D1.getYear(); i++) {
        	if (IsLeapYear(i))
            totalDays += 366;
        	else
            totalDays += 365;
    	}
    	for (int i = 1; i < D1.getMonth(); i++) {
        	totalDays += getDays(D1.getYear(), i);
    	}
    	totalDays += D1.getDay();
	}
	else if (D1.getMonth() > D2.getMonth()) {
		totalDays = getDays(D2.getYear(), D2.getMonth()) - D2.getDay();
		for (int i = D2.getMonth()+1; i < D1.getMonth(); i++) {
        	totalDays += getDays(D1.getYear(), i);
    	}
    	totalDays += D1.getDay();
	} else {
		totalDays = D1.getDay() - D2.getDay();
	}
	return totalDays;
}
int main()
{	
    int year, month, day;
    cout << "请输入年份和月份：";
    cout << flush;
    cin >> year >> month;
    calendar::disCalendar(year, month);

    cout << "请输入年份和月份和日期：";
    cout << flush;
    cin >> year >> month >> day;
    calendar::printweekofdate( year, month, day);

	cout << "请输入两个日期 年 月 日 年 月 日" << endl;
	cout << flush;
	cin >> year >> month >> day;
	int  year1, month1, day1;
	cin >> year1 >> month1 >> day1;
	cout << calendar::datebetween(year, month, day,year1, month1, day1) << endl; 
    int week = 6, date = 1, total = 0;
	for (int year = 2000; year < 2100; year++) {
		for (int i = 1; i < 13; i++) {
			date = 1;
			while (date <= calendar::getDays(year, i)) {
				if (date == 13 && week == 5) total++;
				date++;
				week++;
				week %= 7;
			}
		}
	}
	cout << total << endl;
	return 0;
     
}
