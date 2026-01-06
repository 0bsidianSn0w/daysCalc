//
// Created by awkgnu on 31/12/2025.
//

#ifndef DAYSCALC_DATE_CTLS_H
#define DAYSCALC_DATE_CTLS_H
bool isLeap(int year);
int daysInMonth(int months, int year);
int dateValid(int firstDay, int firstMonth, int firstYear, int secondDay, int secondMonth, int secondYear);
int daysBetweenDates(int currentDay, int currentMonth, int currentYear, int chosenDay, int chosenMonth, int chosenYear);
int findDaysAcrossMonths(int smallDay, int smallMonth, int smallYear, int chosenDay, int chosenMonth, int bigYear);
int findDaysAcrossYears(int smallDay, int smallMonth, int smallYear, int bigDay, int bigMonth, int bigYear);
#endif //DAYSCALC_DATE_CTLS_H