#include <stdio.h>
#include <string.h>

int main(void) {
  int replaceFunc(char* str, char* word, char* replace);

  FILE* input;
  FILE* output;
  char str2[100];
  char str[100];
  char word[100];
  char replace[100];
  char buffer[1000];
  int counter = 0;

  printf("Please enter the input filename: ");
  scanf("%s", str);
  printf("Please enter the word to find: ");
  scanf("%s", word);
  printf("Please enter the word to replace with: ");
  scanf("%s", replace);

  strcpy(str2, str);
  strcat(str2, ".output");

  input  = fopen(str, "r");

  if (input == NULL) {
    printf("Can't open %s", str);
    return 0;
  }

  output = fopen(str2, "w");

  while(fgets(buffer, sizeof(buffer), input)) {
    counter += replaceFunc(buffer, word, replace);
    fputs(buffer, output);
  }

  printf("\n\nYou want to replace %s by %s in %s", word, replace, str);
  printf("\nThe output file name is %s", str2);
  printf("\n\n%d instances found and replaced.", counter);

  fclose(output);
  fclose(input);
  return 0;
}

int replaceFunc(char* str, char* word, char* replace) {
  char* pos;
  char tmp[1000];
  int length = strlen(word);
  int index = 0;
  int count = 0;

  while((pos = strstr(str, word)) != NULL) {
    count++;
    strcpy(tmp, str);
    index = pos - str;
    str[index] = '\0';
    strcat(str, replace);
    strcat(str, tmp + index + length);
  }
  return count;
}