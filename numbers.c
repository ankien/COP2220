#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Name/N#: Andrew Kien / N01367753
   Course/Section#: COP2220 / Faizan - 16294
   Project 4
   This program takes the range of integers between two selected integers (including endpoints) and calculates their sum, product, average, geometric mean, and harmonic mean.
*/

int main(void) {
  int a, b, counterMax;

  // Local function declaration for all functions used in the program.
  int sum(int, int, int);
  int product(int, int, int);
  double average(int, int, int);
  double geoMean(int, int, int);
  double harMean(int, int, int);

  printf("Input two integers: ");
  scanf("%d %d", &a, &b);

  // Determines the maximum number in the range for the functions.
  if(a >= b) {
    counterMax = a;
  }
  else {
    counterMax = b;
  }

  // Prints out the result of all functions.
  printf("Sum: %d\nProduct: %d\nAverage: %.2lf\nGeometric mean: %.2lf\nHarmonic mean: %.2lf\n", sum(a, b, counterMax), product(a, b, counterMax), average(a, b, counterMax), geoMean(a, b, counterMax), harMean(a, b, counterMax));

  return 0;
}

// Adds up all numbers in the range given.
int sum(int a, int b, int counterMax) {
  int sumEquals;

  for(int i = 0; i <= abs(a - b); i++) {
    sumEquals += counterMax--; 
  }
  
  return sumEquals;
}

// Multiplies all numbers in the range given.
int product(int a, int b, int counterMax){
  int productEquals = 1;

  for(int i = 0; i <= abs(a - b); i++) {
    productEquals *= counterMax--; 
  }  

  return productEquals;
}

// Adds all numbers in the range then divides them by the amount of numbers involved.
double average(int a, int b, int counterMax) {
  double averageSum;
  double averageEquals;
  
  for(int i = 0; i <= abs(a - b); i++) {
    averageSum += counterMax--; 
  }

  averageEquals = averageSum / (abs(a - b) + 1);

  return averageEquals;
}

// Finds the geometric mean using a formula.
double geoMean(int a, int b, int counterMax) {
  double geoEquals;
  double geoProduct = 1.0;

  for(int i = 0; i <= abs(a - b); i++) {
    geoProduct *= counterMax--; 
  }  

  geoEquals = pow(geoProduct, (1.0/(abs(a - b) + 1.0)));
  
  return geoEquals;
}

// Finds the harmonic mean using a formula.
double harMean(int a, int b, int counterMax) {
  double harSum = 0.0;
  double harEquals;

  for(int i = 0; i <= abs(a - b); i++) {
    harSum += (1.0/counterMax--); 
  }

  harEquals = (abs(a - b) + 1.0) / harSum;

  return harEquals;
}