#include <iostream>
#include <stdexcept>
#include "date_ctls.h"
#include <string>
using namespace std;



string banner = R"(      ██                              ██████             ██
     ░██            ██   ██          ██░░░░██           ░██
     ░██  ██████   ░░██ ██   ██████ ██    ░░   ██████   ░██  █████
  ██████ ░░░░░░██   ░░███   ██░░░░ ░██        ░░░░░░██  ░██ ██░░░██
 ██░░░██  ███████    ░██   ░░█████ ░██         ███████  ░██░██  ░░
░██  ░██ ██░░░░██    ██     ░░░░░██░░██    ██ ██░░░░██  ░██░██   ██
░░██████░░████████  ██      ██████  ░░██████ ░░████████ ███░░█████
 ░░░░░░  ░░░░░░░░  ░░      ░░░░░░    ░░░░░░   ░░░░░░░░ ░░░  ░░░░░  )";

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
int utilWanted;

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
    cout << endl << "This does not include the end date." << endl;
}

int main() {
    cout << banner << endl;
    cout << "Welcome to my days calculator!" << endl;
    cout << "Please enter the number for the utility you would like to use" << endl;
    cout << "1 - Days between dates" << endl << "2 - Leap year test." << endl << "> ";
    cin >> utilWanted;
    if (utilWanted == 1) {
        daysBetweenDatesMAIN();
    }
    else if (utilWanted == 2) {
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
    else {
        throw runtime_error("The hell you doing??");
    }
    return 0;
}