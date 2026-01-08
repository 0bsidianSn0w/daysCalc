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
        cout << "The year " << year << " is a leap year." << endl;
    }
    else {
        cout << "The year " << year << " isn't a leap year." << endl;
    }
}

int main() {
    cout << banner << endl;
    cout << "Welcome to my days calculator!" << endl;
    while (true) {
        cout << "Please enter the number for the utility you would like to use" << endl;
        cout << "1 - Days between dates" << endl << "2 - Leap year test." << endl << "3 - What day of the week is $Date?" // << endl << "4 - How many days alive?"
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
        else if ((utilWanted == 'Q') || (utilWanted == 'q')) {
            cout << endl << "Are you sure you would you like to quit? (Y/n)\n> ";
            cin >> wantsToQuit;
            if (wantsToQuit == 'Y' || (wantsToQuit == 'y')) { return 0; }
        }
        else {
            throw runtime_error("The hell you doing??");
        }
    }
}
