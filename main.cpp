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

//current
int firstDay;
int firstMonth;
int firstYear;

// User
int secondDay;
int secondMonth;
int secondYear;

//flags
bool monthsValid = { false };
bool daysValid { false };
int daysInChosenMonth { daysInMonth(secondMonth, secondYear) };

void validateMonths() {
    if (((secondMonth < 13) && (secondMonth > 0)) && ((firstMonth < 13) && firstMonth > 0)) {
        // Input is valid for months :D
        monthsValid = true;
    }
    else {
        throw runtime_error("Months entered not valid -- must be in a numerical format.");
    }
}
void validateDays() {
    if (((secondDay > 0) && (secondDay <= daysInMonth(secondMonth,secondYear))) && ((firstDay > 0) && (firstDay <= daysInMonth(firstMonth, firstYear)))) {
        daysValid = true;
    }
    else {
        throw runtime_error("Number of days is invalid for the month -- must be in a numerical format.");
    }
}

int main() {
    cout << banner << endl;
    cout << "Please enter the numerical forms ONLY for the dates." << endl << endl << "Please enter the day for the first date." << endl << "> ";
    cin >> secondDay;
    cout << "Please enter the month for the first date." << endl << "> ";
    cin >> secondMonth;
    cout << "Please enter the year for the first date." << endl << "> ";
    cin >> secondYear;
    cout << "Please enter the day for the second date." << endl << "> ";
    cin >> firstDay;
    cout << "Please enter the month for the second date." << endl << "> ";
    cin >> firstMonth;
    cout << "Please enter the year for the second date." << endl << "> ";
    cin >> firstYear;
    cout << endl << "The number of days between these dates: ";
    validateDays();
    validateMonths();
    cout << daysBetweenDates(firstDay, firstMonth, firstYear, secondDay, secondMonth, secondYear);
    cout << endl;
    return 0;
}
