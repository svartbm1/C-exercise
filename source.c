#include <stdio.h>
#include <string.h>
#include <stdlib.h>


  struct Country {
    char name[21];
    int gold;
    int silver;
    int bronze;
  };

  struct Country *countries;
  int count = 0;

  void add_country(){
    count++;
    countries = realloc(countries, count * sizeof(struct Country));
    if (countries == NULL) {
      printf("Memory allocation failed.\n");
      return;
    }
char name[21];
    scanf("%s", name);
    printf("Country %s added!\n", name);
    strcpy( countries[count-1].name, name);
    countries[count-1].gold = 0;
    countries[count-1].silver = 0;
    countries[count-1].bronze = 0;
    return;
  }

  void medals() {
    if (countries == NULL) {
      printf("Add a country first!\n");
      return;
    }
    char name[21];
    int gold;
    int silver;
    int bronze;
    scanf("%s %d %d %d", name, &gold, &silver, &bronze);
    int i = 0;
    while (i < count && strcmp(countries[i].name, name)!=0){
      i++;
    }
    if (i == count) {
      printf("That country has not been added.\n");
    } else {
      countries[i].gold += gold;
      countries[i].silver += silver;
      countries[i].bronze += bronze;
      printf("%s has %d gold medals, %d silver medals, and %d bronze medals.\n", countries[i].name, countries[i].gold, countries[i].silver, countries[i].bronze);
    }  
  }

  int main()
  {
    int end = 0;
    char command;
    printf("Give input in format M Country 1 2 3:\n");
    while (end == 0) {
	if (feof(stdin)) {
		break;    
}
      scanf("%c", &command);
      switch(command) {
        case 'A' :
          add_country();
          break;
        case 'M' :
          medals();
          break;
        case 'Q' :
	  printf("Freeing memory and ending program, bye bye!\n\n");
          end = 1;
          break;
         }
    }
  free(countries);
  return 0;

  }
