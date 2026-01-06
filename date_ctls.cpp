#include "date_ctls.h"
#include <stdexcept>

bool isLeap(int year) {
    if ((((year % 4) == 0) && !((year % 100) == 0)) || (((year % 4) == 0) && ((year % 100) == 0) && ((year % 400) == 0))) {
        return true;
    }
    else {
        return false;
    }
}

int daysInMonth(int months, int year) {
    if ((!((months % 2) == 0) && (months < 8) || (((months % 2) == 0) && (months >= 8)))) {
        // THis happens if month has 31 days
        return 31;
    }
    else if (((((months % 2 == 0) && (months < 8)) || ((!(months % 2 == 0) && (months >= 8)))) && (months != 2))) {
        // for 30 Day months
        return 30;
    }
    else if (months == 2) {
        if (isLeap(year)) {
            return 29;
        }
        else if (!isLeap(year)) {
            return 28;
        }
        else {
            throw std::runtime_error("?");
        }
    }
    else {
        throw std::runtime_error("WHAT DID YOU DID?!?!?!");
    }
}


int daysBetweenDates(int currentDay, int currentMonth, int currentYear, int chosenDay, int chosenMonth, int chosenYear) {
    if ((chosenMonth == currentMonth) && (chosenDay == currentDay) && (chosenYear == currentYear)) {
        //User silly.
        return 0;
    }
    else if ((chosenMonth == currentMonth) && (chosenYear == currentYear)) {
        // if days are the only difference
        if (chosenDay > currentDay) {
            return (chosenDay - currentDay);
        }
        else {
            return (currentDay - chosenDay);
        }
    }
    else if (chosenYear == currentYear) {
        // If months & days are the difference
        if (chosenMonth > currentMonth) {
            return findDaysAcrossMonths(currentDay, currentMonth, currentYear, chosenDay, chosenMonth, chosenYear);
        }
        else {
            return findDaysAcrossMonths(chosenDay, chosenMonth, chosenYear, currentDay, currentMonth, currentYear);
        }
    }
    else {
        //YEARS ARE THE DIFF
        if (chosenYear > currentYear) {
            return findDaysAcrossYears(currentDay, currentMonth, currentYear, chosenDay, chosenMonth, chosenYear);
        }
        else {
            return findDaysAcrossYears(chosenDay, chosenMonth, chosenYear, currentDay, currentMonth, currentYear);
        }
    }
}


int findDaysAcrossMonths(int smallDay, int smallMonth, int smallYear, int bigDay, int bigMonth, int bigYear) {
    int days { 0 };
    // If months & days are the difference
    days += (daysInMonth(smallMonth, smallYear) - smallDay);
    smallMonth += 1;
    while (smallMonth != bigMonth) {
        days += daysInMonth(smallMonth, smallYear);
        smallMonth += 1;
    }
    days += bigDay;
    return days;
}

int findDaysAcrossYears(int smallDay, int smallMonth, int smallYear, int bigDay, int bigMonth, int bigYear) {
    // YEARS ARE THE DIFF
    int days { 0 };
    days += (daysInMonth(smallMonth, smallYear) - smallDay);
    smallDay = 0;
    smallMonth += 1;
    while (smallMonth != 13) {
        days += daysInMonth(smallMonth, smallYear);
        smallMonth += 1;
    }
    smallYear += 1;
    smallMonth = 1;
    while (smallYear != bigYear) {
        if (isLeap(smallYear)) {
            days += 366;
        }
        else {
            days += 365;
        }
        smallYear += 1;
        smallMonth = 1;
    }
    if (smallMonth == bigMonth) {
        return days += (bigDay);
    }
    else {
        days += (findDaysAcrossMonths(smallDay, smallMonth, smallYear, bigDay, bigMonth, bigYear));
    }
    return days;
}