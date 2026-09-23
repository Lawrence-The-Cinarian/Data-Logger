#ifndef DATAL_H
#define DATAL_H

typedef struct
{
  char stockName[30];
  char stockSymbol[10];
  char date[40];
  char timeStamp[9];
  double price;
} stockMarket;

void prints();
int getStockInput(stockMarket *replace);
int wroteStockToFile(stockMarket *replace);
int readAndPrintStock(stockMarket *replace);

#endif