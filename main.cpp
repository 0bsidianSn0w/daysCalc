#include <iostream>
#include <stdexcept>
#include "date_ctls.h"
using namespace std;

//current
int currentDay;
int currentMonth;
int currentYear;

// User
int chosenDay;
int chosenMonth;
int chosenYear;
//flags
bool monthsValid = { false };
bool daysValid { false };
int daysInChosenMonth { daysInMonth(chosenMonth, chosenYear) };

void validateMonths() {
    if ((chosenMonth < 13) && (chosenMonth > 0)) {
        // Input is valid for months :D
        monthsValid = true;
    }
    else {
        throw runtime_error("Months entered not valid");
    }
}
void validateDays() {
    if ((chosenDay > 0) && (chosenDay <= daysInChosenMonth)) {
        daysValid = true;
    }
    else {
        throw runtime_error("Number of days is invalid for the month.");
    }
}

int main() {
    cout << "Please enter the numerical forms ONLY for the dates." << endl << endl << "Please enter the day for the first date." << endl << "> ";
    cin >> chosenDay;
    cout << "Please enter the month for the first date." << endl << "> ";
    cin >> chosenMonth;
    cout << "Please enter the year for the first date." << endl << "> ";
    cin >> chosenYear;
    cout << "Please enter the day for the second date." << endl << "> ";
    cin >> currentDay;
    cout << "Please enter the month for the first date." << endl << "> ";
    cin >> currentMonth;
    cout << "Please enter the year for the second date." << endl << "> ";
    cin >> currentYear;
    cout << endl << "The number of days between these dates: ";
    validateMonths();
    validateDays();
    cout << daysBetweenDates(currentDay, currentMonth, currentYear, chosenDay, chosenMonth, chosenYear);
}
