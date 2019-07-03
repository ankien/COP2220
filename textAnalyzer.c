#include <stdio.h>
#include <ctype.h>

/* Name/N#: Andrew Kien / N01367753
   Course/Section#: COP2220 / Faizan - 16294
   Project 5
   This program analyzes content from an input text file then prints the character statistics to an output file. These statistics include: letters, white spaces, digits, frequency of uppercase and lowercase letters, occurrences of each letter in the alphabet, and other characters.   
*/

int main(void) {
  FILE* input;
  FILE* output;

  input  = fopen("input.txt", "r");
  output = fopen("report.txt", "w");

  // Section for header and character summary table
  int charCount = 0;
  int spaceCount = 0;
  int digitCount = 0;
  int otherCount = 0;
  float max;
  int c;

  // Scans each character in the file, determines its class, and adds to a counter for the class
  while((c = fgetc(input)) != EOF) {
    if (isalpha(c)) {
      charCount++;
    }
    else if (isspace(c)) {
      spaceCount++;
    }
    else if (isdigit(c)) {
      digitCount++;
    }
    else {
      otherCount++;
    }
  }

  max += (charCount + spaceCount + digitCount + otherCount);

  fprintf(output, "Statistics for file: input.txt\n-------------------------------------------------\n\nTotal # of characters in file:%10d\n\nCategory                How many in file           %% of file\n----------------------------------------------------------------------\nLetters%33d%20.2f %%\nWhite space%29d%20.2f %%\nDigits%34d%20.2f %%\nOther characters%24d%20.2f %%\n\n", (int)max, charCount, 100 * (charCount / max), spaceCount, 100 * (spaceCount / max), digitCount, 100 * (digitCount / max), otherCount, 100 * (otherCount / max));

  fclose(input);

  // Section for letter statistics table
  char letterTemp;
  float letterMax;
  int upperCounter = 0;
  int lowerCounter = 0;
  char alphaChars[26];
  int charCounter[26] = {0};

  for (char c = 'a'; c <= 'z'; ++c) {
    alphaChars[c - 'a'] = c; 
  }

  // Determines the number of uppercase & lowercase characters and adds the count of each alphabetical character to another array
  for (int i = 0; i < 26; i++) {
    fopen("input.txt", "r");
    while ((letterTemp = fgetc(input)) != EOF) {
      if (alphaChars[i] == letterTemp) {
        lowerCounter++;
        charCounter[i]++;
      }
      else if (toupper(alphaChars[i]) == letterTemp) {
        upperCounter++;
        charCounter[i]++;
      }
    }
    fclose(input);
  }
  
  letterMax = lowerCounter + upperCounter;

  fprintf(output, "LETTER STATISTICS\n\nCategory                How many in file    %% of all letters\n----------------------------------------------------------------------\nUppercase%31d%20.2f %%\nLowercase%31d%20.2f %%\n", upperCounter, 100 * upperCounter / letterMax, lowerCounter, 100 * lowerCounter / letterMax);

  for (int i = 0; i < 26; i++) {
    fprintf(output, "%c%39d%20.2f %%\n", alphaChars[i], charCounter[i], 100 * charCounter[i] / letterMax);
  }

  // Section for number analysis
  fopen("input.txt", "r");
  int numCount = 0;
  int sum = 0;
  int integerRead;
  int temp;
  float average;

  // Scans each character in the file and checks if it's an integer, fscanf returns 1 if an integer is found
  do {
    temp = fscanf(input, "%d", &integerRead);
    if (temp == 1) {
      sum += integerRead;
      numCount++;
    }
    else {
      fgetc(input);
    }
  } while (temp != EOF); 

  average = (float)sum / numCount;

  fprintf(output, "\n\nNUMBER ANALYSIS\n\nNumber of integers in the file:%5d\nTheir sum:%28d\nTheir average:%26.2f", numCount, sum, average);

  fclose(output);
  fclose(input);
  return 0;
}