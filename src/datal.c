#include "../library/datal.h"
#include <stdio.h>
#include <string.h>


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
  replace->stockName[strcspn(replace->stockName, "\n")] = '\0';
  
  printf("Enter stock symbol: ");
  fgets(replace->stockSymbol, sizeof(replace->stockSymbol), stdin);
  replace->stockSymbol[strcspn(replace->stockSymbol, "\n")] = '\0';
  
  printf("Enter date: ");
  fgets(replace->date, sizeof(replace->date), stdin);
  replace->date[strcspn(replace->date, "\n")] = '\0';
  
  printf("Enter time: ");
  fgets(replace->timeStamp, sizeof(replace->timeStamp), stdin);
  replace->timeStamp[strcspn(replace->timeStamp, "\n")] = '\0';
  
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
  fprintf(inputinfo, "Stock name: %s\nStock symbol: %s\nDate: %s\nTime: %s\nPrice: %.2f\n\n", replace->stockName, replace->stockSymbol, replace->date, replace->timeStamp, replace->price);
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
  
  while(fscanf(outputinfo, "Stock name: %29s\nStock symbol: %9s\nDate: %39s\nTime: %8s\nPrice: %lf\n\n", replace->stockName, replace->stockSymbol, replace->date, replace->timeStamp, &replace->price) == 5)
  {
  printf("Stock name: %s\nStock symbol: %s\nDate: %s\nTime: %s\nPrice: %.2f\n\n", replace->stockName, replace->stockSymbol, replace->date, replace->timeStamp, replace->price);
  }
  fclose(outputinfo);
  return 0;
}
