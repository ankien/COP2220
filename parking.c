#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Name/N#: Andrew Kien / N01367753
   Course/Section#: COP2220 / Faizan - 16294
   Project 3
   This program calculates the parking fare for customers
   according to their vehicle type and the
   time they've spent in the parking lot.
*/

int main (void) {
  char  vType;
  int   timeHour, timeMinute, hourEntered, minuteEntered, hourLeft, minuteLeft;
  float cost;

  // Local function declarations for readData, calcTime, calcCost, printRes. Called in main
  void readData (char* vType, int* hourEntered, int* minuteEntered, int* hourLeft, int* minuteLeft);
  void calcTime (int* timeHour, int* timeMinute , int* hourEntered, int* minuteEntered, int* hourLeft, int* minuteLeft);
  void calcCost (float* cost, char* vType, int* timeHour, int* timeMinute);
  void printRes (float* cost, int* timeHour, int* timeMinute , int* hourEntered, int* minuteEntered, int* hourLeft, int* minuteLeft);

  // Local function calls
  readData (&vType, &hourEntered, &minuteEntered, &hourLeft, &minuteLeft);
  calcTime (&timeHour, &timeMinute, &hourEntered, &minuteEntered, &hourLeft, &minuteLeft);
  calcCost (&cost, &vType, &timeHour, &timeMinute);
  printRes (&cost, &timeHour, &timeMinute , &hourEntered, &minuteEntered, &hourLeft, &minuteLeft);
  return 0;
}

// Reads data from the customer and uses address to send them to main's functions, error message if invalid input.
void readData (char* vType, int* hourEntered, int* minuteEntered, int* hourLeft, int* minuteLeft) {
  printf ("Type of vehicle (C for car, T for truck, B for bus)? ");
  scanf  ("%c", vType);
  printf ("Time when vehicle entered the lot (h:m)? ");
  scanf  ("%d:%d", hourEntered, minuteEntered);
  printf ("Time when vehicle left the lot (h:m)? ");
  scanf  ("%d:%d", hourLeft, minuteLeft);

  if ((*vType != 'c') && (*vType != 'C') && (*vType != 'b') && (*vType != 'B') && (*vType != 't') && (*vType != 'T')) {
    printf ("\n\nInvalid input");
    exit(0);
  }
  else if (*hourEntered > 24 || *hourEntered < 0 || *minuteEntered > 60 || *minuteEntered < 0 || *hourLeft > 24 || *hourLeft < 0 || *minuteLeft > 60 || *minuteLeft < 0) {
    printf ("\n\nInvalid input");
    exit(0);
  }
  return;
}

// Determines the time the vehicle spent in the parking lot.
void calcTime (int* timeHour, int* timeMinute , int* hourEntered, int* minuteEntered, int* hourLeft, int* minuteLeft) {
  if (*minuteEntered > *minuteLeft) {
    *timeHour = (*hourLeft - 1) - *hourEntered;
    *timeMinute = (60 - *minuteEntered) + *minuteLeft;
  }
  else {
    *timeHour = *hourLeft - *hourEntered;
    *timeMinute = *minuteLeft - *minuteEntered;
  }
  return;
}

// Calculates the cost of the parking fare according to vehicle and time spent in the parking lot.
void calcCost (float* cost, char* vType, int* timeHour, int* timeMinute) {
  if (*vType == 'c' || *vType == 'C') {
    if      (*timeMinute == 0 && *timeHour <= 3) {
      *cost = 0.0;
    }
    else if (*timeMinute == 0) {
      *cost = *timeHour * 1.50;
    }
    else if (*timeHour < 3) {
      *cost = 0.0;
    }
    else {
      *cost = (*timeHour + 1) * 1.50;
    }
  }
  else if (*vType == 't' || *vType == 'T') {
    if      (*timeMinute == 0 && *timeHour <= 2) {
      *cost = *timeHour * 1.0;
    }
    else if (*timeMinute == 0) {
      *cost = 2.0 + ((*timeHour - 2) * 2.30);
    }
    else if (*timeHour < 2) {
      *cost = (*timeHour + 1) * 1.0;
    }
    else if (*timeHour == 0) {
      *cost = 1.0;
    }
    else {
      *cost = 2.0 + ((*timeHour - 2) * 2.30) + 2.30;
    }
  }
  else {
    if      (*timeMinute == 0 && *timeHour <= 1) {
      *cost = *timeHour * 2.0;
    }
    else if (*timeMinute == 0) {
      *cost = 2.0 + ((*timeHour - 1) * 3.70);
    }
    else if (*timeHour == 0) {
      *cost = 2.0;
    }
    else if (*timeHour < 1) {
      *cost = 3.70;
    }
    else {
      *cost = 2.0 + ((*timeHour - 1) * 3.70) + 3.70;
    }
  }
  return;  
}

// Prints the parking time and cost of the parking fare.
void printRes (float* cost, int* timeHour, int* timeMinute , int* hourEntered, int* minuteEntered, int* hourLeft, int* minuteLeft) {
  printf ("\nParking time: %d:%d\nCost: $%.2f\n", *timeHour, *timeMinute, *cost);
  return;
}