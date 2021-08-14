#include <iostream>
using namespace std;

struct date {
	int day;
	int month;
	int year;
};

bool isLeap(date d) {
	if (d.year % 4 == 0 && (d.year % 100 != 0 || d.year % 400 == 0))
		return true;
	else return false;
}

int daysInMonth(date d) {
	if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) {
		return 30;
	}
	else if (d.month == 2) {
		if (isLeap(d))
			return 29;
		else return 28;
	}
	else return 31;
}

long unsigned int nbOfDaysSince1Jan1900(date d) {
	long unsigned int nb = 0;
	date d1;
	d1.year = 1900;
	d1.month = 1;
	d1.day = 1;
	for (int i = d1.year; i < d.year; i++) {
		if (isLeap(d1)) {
			nb += 366;
		}
		else nb += 365;
		d1.year++;
	}
	for (int i = d1.month; i < d.month; i++) {
		nb += daysInMonth(d1);
		d1.month++;
	}
	nb += d.day - 1;
	return nb;
}

short int dayOfWeek(date d) {
	return nbOfDaysSince1Jan1900(d) % 7;
	//monday: 0
	//..
	//sunday: 6
}
date operator+(date d, int i) {
	while (i > 365) {
		if (isLeap(d)) {
			i -= 366;
		}
		else { 
			i -= 365; 
		}
		d.year++;
	}
	while (i > 30) {
		i -= daysInMonth(d);
		if (d.month == 12) {
			d.year++;
			d.month = 1;
		}
		else d.month++;
	}
	if (i + d.day > daysInMonth(d)) {
		int rest = i + d.day - daysInMonth(d);
		if (d.month == 12) {
			d.year++;
			d.month = 1;
		}
		else { d.month++; }
		d.day = rest;
	}
	else d.day += i;
	return d;
}

bool operator<(date d1, date d2) {
	if (d2.year > d1.year)
		return true;
	if (d2.year < d1.year)
		return false;
	if (d2.month > d1.month)
		return true;
	if (d2.month < d1.month)
		return false;
	return d2.day >= d1.day;
}
int main() {
	date startDate;
	startDate.day = 1;
	startDate.month = 1;
	startDate.year = 1901;

	date endDate;
	endDate.day = 31;
	endDate.month = 12;
	endDate.year = 2000;

	//finding the first sunday

	
	while (dayOfWeek(startDate) != 6) {
		startDate = startDate + 1;
	}
	int count = 0;
	while (startDate < endDate) {
		if (startDate.day == 1) {
			count++;
			startDate = startDate + 28; //optimization of the code
			continue;
		}
		startDate = startDate + 7; //finding next sunday
	}
	cout << count;
	
}