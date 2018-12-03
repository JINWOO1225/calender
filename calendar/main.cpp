//
//  main.cpp
//  calendar
//
//  Created by hongjinwoo on 03/12/2018.
//  Copyright © 2018 hongjinwoo. All rights reserved.
//
/*문제 1
 
 여러분은 아래와 같은 Date 클래스를 디자인 하려고 합니다. set_date 는 말그대로 Date 함수 내부를 초기화 하는 것이고 add_day, add_month, add_year 는 일, 월, 년을 원하는 만큼 더하게 됩니다. 한 가지 주의할 점은 만일 2012 년 2 월 28 일에 3 일을 더하면 2012 년 2 월 31 일이 되는 것이 아니라 2012 년 3 월 2 일이 되겠지요? (난이도 : 上)
 */
//이 코드는 그레고리력 달력을 참고했습니다.
//"https://ko.wikipedia.org/wiki/윤년"
#include <iostream>

using namespace std;

class Date
{
private:
	
	int year;
	int month;
	int day,dayMax;
	bool LeapYear;
	
public:
	void set_date(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}
	void isitLeapYear()//리턴값으로 윤년의 여부를 확인해주는 함수
	{
		LeapYear = 0;
		if(!(year % 4))
		{
			LeapYear = 1;
		}
		if(!(year % 100))
		{
			LeapYear = 0;
		}
		if(!(year % 400))
		{
			LeapYear = 1;
		}
	}
	void setDayMax()
	{
		switch (month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 11:
				dayMax = 31;
				break;
				
			case 4:
			case 6:
			case 9:
				dayMax = 30;
				break;
				
			case 2:
				isitLeapYear();
				if (LeapYear)
				{
					dayMax = 29;
				}
				else
				{
					dayMax = 28;
				}
			default:
				break;
		}
	}
	void add_day(int inc)
	{
		day += inc;
	}
	void add_month(int inc)
	{
		month += inc;
	}
	void add_year(int inc)
	{
		year += inc;
	}
	void get_date()
	{
		cout << year << ":" << month << ":" << day << endl;
	}
};

int main(int argc, const char * argv[])
{
	int index;
	
	Date date;
	
	
	for (; ; )
	{
		cout << "1 : 날짜 설정\n2 : 추가\n3 : 날짜 표시\n";
		cin >> index;
		
		switch (index)
		{
			case 1:	//날짜 설정
				
				int year,month,day;
				cout << "년 월 일 순으로 입력하세요.";
				cin >> year >> month >> day;
				date.set_date(year, month, day);
				break;
				
			case 2:	//날짜 추가
				
				int select_add,inc;
				cout << "1 : 일 추가\n2 : 월 추가\n3 : 년 추가\n";
				cin >> select_add;
				cout << "입력할 양 입력\n";
				cin >> inc;
				switch (select_add) {
					case 1:
						date.add_day(inc);
						break;
						
					case 2:
						date.add_month(inc);
						break;
						
					case 3:
						date.add_month(inc);
						break;
						
					default:
						break;
				}
				break;
				
			case 3:	//날짜 표시
				
				date.get_date();
				break;
				
			default:
				break;
		}
	}
	
	return 0;
}
