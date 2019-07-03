#include <stdio.h>

/*
Name/N#: Andrew Kien / 01367753
Course/Section#: COP2220 - Faizian / 16294
Project 1
This program calculates the amount and cost of water saved in a community by using low-flush toilets.
*/

int main(void) {
  //Declares price and liters of water per flush for the new toilets
  int toiletCost=150;
  int litersPerFlush=2;

  //Variable type declaration for community's population, persons per toilet, the liters per flush of their current toilets, and average amount of toilet flushes per day
  int population;
  int peoplePerToilet;
  float currentPerFlush;
  int flushAverage;

  printf("Welcome to FlushSave!!\n");
  printf("\n");

  // Prompts community manager a series of questions about the population count, users per toilet, water in liters per flush of existing toilets, and how much a toilet is flushed on average
  printf("What is the population of the community?  ");
  scanf("%d",&population);
  printf("How many persons will share a toilet?  ");
  scanf("%d",&peoplePerToilet);
  printf("How much water(liters) do the existing toilets use for each flush?   ");
  scanf("%f",&currentPerFlush);
  printf("How many times on average a toilet is flushed per day?  ");
  scanf("%d",&flushAverage);

  printf("\n");
  printf("-------------------------------------------------\n");
  printf("\n");

  //Prints population of community
  printf("There are %d people in your community\n",population);

  //Determines the amount of toilets needed for the community according to how many people use a single toilet
  float toiletAmount=population/peoplePerToilet;
  printf("You need %.2f toilets.\n",toiletAmount);

  //Determines community's current water usage according to manager's inputs
  float currentLiters=(population/peoplePerToilet)*(currentPerFlush*flushAverage);
  printf("Your community uses %.2f liters of water per day just for toilet!\n",currentLiters);

  //Subtracts water usage of new toilets from the current
  float savedLiters=currentLiters-((population/peoplePerToilet)*(litersPerFlush*flushAverage));
  printf("You can save %.2f liters of water per day just by switching to our toilets!\n",savedLiters);
  
  //Displays price of new toilets according to how many the community needs
  float newToiletPrice=toiletAmount*toiletCost; 
  printf("This will only cost you $%.2f",newToiletPrice);
  return 0;
}