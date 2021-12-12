#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int dateDifferent(int year, int month, int day);
int toDay(const char *dateStr);
int daysBetweenDates(char *date1, char *date2);

int main(void)
{
	int year = 1921;
	int month = 7;
	int day = 23;
	char *date = malloc(sizeof(char) * 10 + 1);
	int dayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int dateDifferent_returnValue = 0;
	int daysBetweenDates_returnValue = 0;
	while(1) {
		sprintf(date, "%4d-%02d-%02d", year, month, day);
		//if((dateDifferent_returnValue = dateDifferent(year, month, day)) != (daysBetweenDates_returnValue = daysBetweenDates(partyBuildingdate, date))) {
		printf("%s:\n\t-dateDifferent:%d\n\t-daysBetweenDates:%d\n", date, dateDifferent(year, month, day), daysBetweenDates("1921-07-23", date));
		//}
		day++;
		if((!(year / 4.0) && (year / 100.0) || !(year / 400.0) && month == 2 && day == 29)) {
			continue;
		}
		if(day > dayInMonth[month - 1]) {

			day = 1;
			month++;
			if(month > 12) {
				month = 1;
				year++;
			}
		}
		if(year == 1921 && month == 8 && day == 31) {
			break;
		}
	}

	return 0;
}
//1
int toDay(const char *dateStr)
{
	int year, month, day;
	sscanf(dateStr, "%d-%d-%d", &year, &month, &day);
	if(month <= 2) {
		year--;
		month += 10;
	} else month -= 2;
	return 365 * year + year / 4 - year / 100 + year / 400 + 30 * month + (3 * month - 1) / 5 + day /* -584418 */;
}
int daysBetweenDates(char *date1, char *date2)
{
	return abs(toDay(date1) - toDay(date2));
}
//2
int dateDifferent(int year, int month, int day)
{
	if(month <= 2) {
		year--;
		month += 10;
	} else month -= 2;
	return 365 * year + year / 4 - year / 100 + year / 400 + 30 * month + (3 * month - 1) / 5 + day - 701805;
}