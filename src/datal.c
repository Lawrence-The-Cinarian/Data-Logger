#include "library/datal.h"
#include <stdio.h>

void prints()
{
  puts("");
  puts("Cinari's Data Logger");
  puts("(1) Add stock");
  puts("(2) Write stock to file");
  puts("(3) Read stock from file");
  puts("(4) Exit");
  puts("");
}
int getStockInput(stockMarket *replace)
{
  printf("Enter stock name: ");
  fgets(replace->stockName, sizeof(replace->stockName), stdin);
  printf("Enter stock symbol: ");
  scanf("%9s", replace->stockSymbol);
  printf("Enter date: ");
  fgets(replace->date, sizeof(replace->date), stdin);
  printf("Enter Time: ");
  scanf("%8s", replace->timeStamp);
  printf("Enter present price: ");
  scanf("%lf", &replace->price);
  return 0;
}

int wroteStockToFile(stockMarket *replace)
{
  FILE *inputinfo;
  inputinfo = fopen("datalog.txt", "a");
  if(inputinfo == NULL)
  {
    puts("Error opening file");
    return 1;
  }
  fprintf(inputinfo, "Stock name: %s\nStock symbol: %s\nDate: %s\nTime: %s\nPrice: %.2f\n\n");
  fclose(inputinfo);
  puts("Saved to datalog.txt");
  return 0;
}

int readAndPrintStock(stockMarket *replace)
{
  FILE *outputinfo;
  outputinfo = fopen("datalog.txt", "r");
  if(outputinfo == NULL)
  {
    puts("No such file exist");
    return 1;
  }
  
  while(fscanf(outputinfo, "%29s %9s %39s %8s %lf") == 5)
  {
  printf(inputinfo, "Stock name: %s\nStock symbol: %s\nDate: %s\nTime: %s\nPrice: %.2f\n\n");
  }
  fclose(inputinfo);
  return 0;
}