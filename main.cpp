#include <iostream>
#include <stdexcept>
#include "date_ctls.h"
#include <string>
using namespace std;


string banner = R"(     _                  ____      _
  __| | __ _ _   _ ___ / ___|__ _| | ___
 / _` |/ _` | | | / __| |   / _` | |/ __|
| (_| | (_| | |_| \__ \ |__| (_| | | (__
 \__,_|\__,_|\__, |___/\____\__,_|_|\___|
             |___/                       )";

//Values
int firstDay;
int firstMonth;
int firstYear;
int secondDay;
int secondMonth;
int secondYear;

//flags
bool monthsValid = { false };
bool daysValid { false };
int daysInChosenMonth { daysInMonth(secondMonth, secondYear) };
char utilWanted;
char wantsToQuit;

void dayOfTheWeekMAIN() {
    int day;
    int month;
    int year;
    cout << "Please enter the day." << endl << "> ";
    cin >> day;
    cout << "Please enter the month." << endl << "> ";
    cin >> month;
    cout << "Please enter the year." << endl << "> ";
    cin >> year;
    dateValid(day, month, year, day, month, year);
    switch (dayOfTheWeek(day, month, year)) {
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
        case 7:
            cout << "Sunday" << endl;
            break;
        default:
            throw runtime_error("dayOfTheWeek funct returned invalid.");
    }
}
void daysBetweenDatesMAIN() {
    cout << "Please enter the numerical forms ONLY for the dates." << endl << endl;
    cout << "Please enter the day for the first date." << endl << "> ";
    cin >> firstDay;
    cout << "Please enter the month for the first date." << endl << "> ";
    cin >> firstMonth;
    cout << "Please enter the year for the first date." << endl << "> ";
    cin >> firstYear;
    cout << "Please enter the day for the second date." << endl << "> ";
    cin >> secondDay;
    cout << "Please enter the month for the second date." << endl << "> ";
    cin >> secondMonth;
    cout << "Please enter the year for the second date." << endl << "> ";
    cin >> secondYear;
    cout << endl << "The number of days between these dates: ";
    if (!dateValid(firstDay, firstMonth, firstYear, secondDay, secondMonth, secondYear)) { throw runtime_error("Date not valid"); };
    cout << daysBetweenDates(firstDay, firstMonth, firstYear, secondDay, secondMonth, secondYear);
    cout << endl << "This does not include the end date." << endl << endl;
}
void isLeapMAIN() {
    int year;
    cout << "What year would you like to test?" << endl << "> ";
    cin >> year;
    if (isLeap(year)) {
        cout << year << " is a leap year." << endl;
    }
    else {
        cout << year << " isn't a leap year." << endl;
    }
}
void calenderPrintMAIN(int month, int year) {
    string calenderHeader {"| Mon | Tue | Wed | Thu | Fri | Sat | Sun |"};
    int days { daysInMonth(month, year)};
    int day { 1 };
    int column { 1 };
    int startColumn { dayOfTheWeek(day, month, year) };
    string ending;
    //1st 2nd 3rd 4th 5th 6th 7th 8th 9th 10th 11th 12th
    switch (month) {
        case 1:
            ending = "st";
            break;
        case 2:
            ending = "nd";
            break;
        case 3:
            ending = "rd";
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            ending = "th";
            break;
        default:
            throw runtime_error("Invalid month passed to switch statement in calenderGen funct.");
    }
    cout << "This is the calender for the " << month << ending << " month of " << year << "." << endl;
    cout << calenderHeader << endl << "|";
    cout.flush();

    for (; column <= startColumn; column ++) {
        cout << "  -  |";
    }
    for (; day <= days; day ++) {
        if (column == 7) {
            if (day >= 10) {
                cout << "  " << day << " |"  << endl;
            }
            else {
                cout << "  " << day << "  |" << endl;
            }
            cout << "|";
            column = 1;
        }
        else {
            if (day >= 10) {
                cout << "  " << day << " |";
            }
            else {
                cout << "  " << day << "  |";
            }
            column += 1;
        }
    }
    cout << endl << endl;
}



int main() {
    cout << banner << endl;
    cout << "Welcome to my days calculator!" << endl;
    while (true) {
        cout << "Please enter the number for the utility you would like to use" << endl;
        cout << "1 - Days between dates." << endl << "2 - Leap year test." << endl << "3 - What day of the week is $Date?"
        << endl << "4 - Calender Generator (for a month)."
        << endl << "Q - Quit" << endl << "> ";

        cin >> utilWanted;
        if (utilWanted == '1') {
            daysBetweenDatesMAIN();
        }
        else if (utilWanted == '2') {
            isLeapMAIN();
        }
        else if (utilWanted == '3') {
            dayOfTheWeekMAIN();
        }
        else if (utilWanted == '4') {
            int month;
            int year;
            cout << "Please enter the month's number in the format %M or %MM eg '7' or '12'." << endl << "> ";
            cin >> month;
            cout << "Please enter the year in the format %YYYY." << endl << "> ";
            cin >> year;
            calenderPrintMAIN(month, year);
        }
        else if ((utilWanted == 'Q') || (utilWanted == 'q')) {
            cout << endl << "Are you sure you would you like to quit? (Y/n)\n> ";
            cin >> wantsToQuit;
            if (wantsToQuit == 'Y' || (wantsToQuit == 'y')) { return 0; }
        }
        else {
            throw runtime_error("The hell you doing??");
        }
        cout << endl << endl;
    }
}
