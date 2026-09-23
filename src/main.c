#include "../library/datal.h"
#include <stdbool.h>
#include <stdio.h>


int main(void)
{
  
stockMarket stock;
int options;
char symbol = '\0';

do{

prints();
printf("Enter a number from the option: ");
scanf("%d", &options);
getchar();

switch(options)
{
  case 1:
  puts("");
  getStockInput(&stock);
  break;
  
  case 2:
  puts("");
  wroteStockToFile(&stock);
  break;
  
  case 3:
  puts("");
  readAndPrintStock(&stock);
  break;
  
  case 4:
  return 0;
  
  default:
  puts("Invalid option");
}

puts("");
printf("Would you like to continue? Y[es]/N[o]: ");
scanf(" %c", &symbol);
if(!(symbol == 'Y' || symbol == 'y'))
{
  break;
}
}
while(true);

return 0;
}
