#include <stdio.h>

/* Name/N#: Andrew Kien / N01367753
   Course/Section#: COP2220 - Faizan / 16294 
   Project 2
   This program creates a bill for the customers of a carpet company
   according to the size, and price of the carpet
   including customer discounts.
*/

// Defines labor cost per square foot and tax rate as constants and their values
#define laborCostRate 0.55
#define taxRate       0.06

int main (void) {
  // Function Declarations for getData, calculate, and printRes. Called in main
  void getData   (int* length, int* width, float* customerDiscount, float* costPerSquareFoot);
  void calculate (int* length, int* width, float* customerDiscount, float* costPerSquareFoot, int* area, float* carpetCost, float* laborCost, float* installedPrice, float* subTotalValue, float* discountTotal, float* tax, float* totalPrice);
  void printRes  (int* length, int* width, float* customerDiscount, float* costPerSquareFoot, int* area, float* carpetCost, float* laborCost, float* installedPrice, float* subTotalValue, float* discountTotal, float* tax, float* totalPrice);

  // Local declaration of all the variables used in this program
  int   length, width, area;
  float customerDiscount, costPerSquareFoot, carpetCost, laborCost, installedPrice, subTotalValue, discountTotal, tax, totalPrice;

  // Local function calls
  getData   (&length, &width, &customerDiscount, &costPerSquareFoot);
  calculate (&length, &width, &customerDiscount, &costPerSquareFoot, &area, &carpetCost, &laborCost, &installedPrice, &subTotalValue, &discountTotal, &tax, &totalPrice);
  printRes  (&length, &width, &customerDiscount, &costPerSquareFoot, &area, &carpetCost, &laborCost, &installedPrice, &subTotalValue, &discountTotal, &tax, &totalPrice);
  return 0;
}

// Reads data from the user and uses addresses to place them in main function's variables
void getData (int* length, int* width, float* customerDiscount, float* costPerSquareFoot){
  printf ("Length of room (feet)? ");
  scanf  ("%d", length);
  printf ("\n");
  printf ("Width of room (feet)? ");
  scanf  ("%d", width);
  printf ("\n");
  printf ("Customer discount (percent)(xxx.xx)? ");
  scanf  ("%f", customerDiscount);
  printf ("\n");
  printf ("Cost per square foot (dollars)(xxx.xx)? ");
  scanf  ("%f", costPerSquareFoot);
  printf ("\n");
  return;
}

// Calculates the values to be printed out using three subfunctions: installPrice subTotal and total, they all use addresses to store the results
void calculate (int* length, int* width, float* customerDiscount, float* costPerSquareFoot, int* area, float* carpetCost, float* laborCost, float* installedPrice, float* subTotalValue, float* discountTotal, float* tax, float* totalPrice){
  void installPrice (int* length, int* width, float* costPerSquareFoot, int* area, float* carpetCost, float* laborCost, float* installedPrice);
  void subTotal     (float* subTotalValue, float* discountTotal, float* installedPrice, float* customerDiscount);
  void total        (float* tax, float* totalPrice, float* subTotalValue);
  installPrice (length, width, costPerSquareFoot, area, carpetCost, laborCost, installedPrice);
  subTotal     (subTotalValue, discountTotal, installedPrice, customerDiscount); 
  total        (tax, totalPrice, subTotalValue);
  return;
}

// Calculates area, carpet cost, labor cost, and installed price
void installPrice (int* length, int* width, float* costPerSquareFoot, int* area, float* carpetCost, float* laborCost, float* installedPrice){
  *area           = *length * *width;
  *carpetCost     = *area * *costPerSquareFoot;
  *laborCost      = *area * laborCostRate;
  *installedPrice = *carpetCost + *laborCost;
  return;
}

// Calculates the discount and subtotal
void subTotal (float* subTotalValue, float* discountTotal, float* installedPrice, float* customerDiscount){
  *discountTotal = *installedPrice * (*customerDiscount / 100);
  *subTotalValue = *installedPrice - *discountTotal;
  return;
}

// Calculates the tax and total price
void total (float* tax, float* totalPrice, float* subTotalValue){
  *tax        = *subTotalValue * taxRate;
  *totalPrice = *subTotalValue + *tax;
  return;
}

// Prints all user input and final measurements
void printRes (int* length, int* width, float* customerDiscount, float* costPerSquareFoot, int* area, float* carpetCost, float* laborCost, float* installedPrice, float* subTotalValue, float* discountTotal, float* tax, float* totalPrice){
  printf("               MEASUREMENT ");
  printf("\n");
  printf("Length                            %d ft \n", *length);
  printf("Width                             %d ft \n", *width);
  printf("Area                             %d square ft \n", *area);
  printf("\n");
  printf("                CHARGES \n");
  printf("\n");
  printf("DESCRIPTION         COST/SQ FT           CHARGE ");
  printf("\n");
  printf("----------------------------------------------- ");
  printf("\n");
  printf("Carpet               $%5.2f            $%7.2f \n", *costPerSquareFoot, *carpetCost);
  printf("Labor                 $%4.2f             $%6.2f \n", laborCostRate, *laborCost);
  printf("----------------------------------------------- \n");
  printf("Installed Price                        $%7.2f \n", *installedPrice);
  printf("Discount               %4.2f%%            $%6.2f \n", *customerDiscount, *discountTotal);
  printf("----------------------------------------------- \n");
  printf("Subtotal                               $%7.2f \n", *subTotalValue);
  printf("Tax                                     $%6.2f \n",*tax);
  printf("Total                                  $%7.2f \n", *totalPrice);
  return;
}