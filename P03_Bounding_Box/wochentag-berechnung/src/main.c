 /* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab P03 weekday
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


// *** TASK1: typedef enum types for month_t (Jan=1,...Dec} ***
// BEGIN-STUDENTS-TO-ADD-CODE
typedef enum {Jan=1, Feb=2, Mar=3, Apr=4, May=5, Jun=6, Jul=7, Aug=8, Sep=9, Oct=10, Nov=11, Dec=12} month_t;

// END-STUDENTS-TO-ADD-CODE



// *** TASK1: typedef struct for date_t ***
// BEGIN-STUDENTS-TO-ADD-CODE
typedef struct { int day; int month; int year; } date_t;

// END-STUDENTS-TO-ADD-CODE



// *** TASK2: typedef enum weekday_t (Sun=0, Mon, ...Sat) ***
// BEGIN-STUDENTS-TO-ADD-CODE
typedef enum {Sun, Mon, Tue, Wed, Thu, Fri, Sat} weekday_t;

// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is a leap year.
 * @returns 0 = is not leap year, 1 = is leap year
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int is_leap_year(date_t date){
	if ((date.year % 400) == 0){
		return 1;
	} else if ((date.year % 100) == 0) {
		return 0;
	} else if ((date.year % 4) == 0) {
		return 1;
	}
	return 0;
}

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Calculates the length of the month given by the data parameter
 * @returns 28, 29, 30, 31 if a valid month, else 0
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int get_month_length(date_t date){
	if (date.month == 2){
		if (is_leap_year(date)){
		       return 29;
		} else {
			return 28;
		}
	} else if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12 ){
	       return 31;
	}
	return 30;	

}

// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is in the gregorian date range
 * @returns 0 = no, 1 = yes
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int is_gregorian_date(date_t date){
	if (date.year < 9999 && date.year > 1582){
		return 1;
	} else if (date.year == 1582){
		if (date.month > 10 || (date.month == 10 && date.day > 14)){
			return 1;
		}
	}
	return 0;
}

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Checks if the given date is a valid date.
 * @returns 0 = is not valid date, 1 = is valid date
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int is_valid_date(date_t date){
	if(is_gregorian_date(date)){
		if (date.month < 13 && date.month > 0){
			if (date.day <= get_month_length(date) && date.day > 0){
				return 1;
			}
		}
	}
	return 0;
}

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK2: calculated from a valid date the weekday
 * @returns returns a weekday in the range Sun...Sat
 */
// BEGIN-STUDENTS-TO-ADD-CODE
weekday_t calculate_weekday(date_t date){
	assert(is_valid_date(date));
	int m = 1 + (date.month + 9) % 12;
	int a, y, c;
	if (date.month < Mar){
		a = date.year - 1;
	} else {
		a = date.year;
	}
	y = a % 100;
	c = a / 100;
	return ((date.day + (13 * m - 1 ) / 5 + y + y / 4 + c / 4 - 2 * c ) % 7 + 7) % 7;
}

// END-STUDENTS-TO-ADD-CODE



/**
 * @brief   TASK2: print weekday as 3-letter abreviated English day name
 */
// BEGIN-STUDENTS-TO-ADD-CODE
char* getDayName(weekday_t day){
	switch (day){
		case Sun: return "Sun";
		case Mon: return "Mon";
		case Tue: return "Tue";
		case Wed: return "Wed";
		case Thu: return "Thu";
		case Fri: return "Fri";
		case Sat: return "Sat";
		default: assert(!"day is out-of-range");
	}
}

void print_weekday(weekday_t day){
	printf("%s%s", getDayName(day), "\n");
}

// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   main function
 * @param   argc [in] number of entries in argv
 * @param   argv [in] program name plus command line arguments
 * @returns returns success if valid date is given, failure otherwise
 */
int main(int argc, const char *argv[])
{
    // TASK1: parse the mandatory argument into a date_t variable and check if the date is valid
    // BEGIN-STUDENTS-TO-ADD-CODE
	date_t date;
	if(argc < 2){
		return EXIT_FAILURE;	
	}
	sscanf(argv[1], "%d-%d-%d", &date.year, &date.month, &date.day);
	if (is_valid_date(date)){
		printf("%04d-%02d-%02d %s", date.year, date.month, date.day, "is a ");
		print_weekday(calculate_weekday(date));
		return EXIT_SUCCESS;
	} else {
		printf(stderr, "%04d-%02d-%02d %s", date.year, date.month, date.day, "is not a valid date!\n ");
		return EXIT_FAILURE;
	}

    // END-STUDENTS-TO-ADD-CODE

    
    // TASK2: calculate the weekday and print it in this format: "%04d-%02d-%02d is a %s\n"
    // BEGIN-STUDENTS-TO-ADD-CODE


    // END-STUDENTS-TO-ADD-CODE
    
    return EXIT_SUCCESS;
}
