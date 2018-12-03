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

#include <iostream>

using namespace std;

class Date {
	int year;
	int month;
	int day;
	
public:
	void set_date(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
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
	
	
	for (; ; ) {
		cout << "1 : 날짜 설정\n2 : 추가\n3 : 날짜 표시\n";
		cin >> index;
		switch (index) {
			case 1:
				int year,month,day;
				cout << "년 월 일 순으로 입력하세요.";
				cin >> year >> month >> day;
				date.set_date(year, month, day);
				break;
				
			case 2:
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
				
			case 3:
				date.get_date();
				
			default:
				break;
		}
	}
	
	return 0;
}
