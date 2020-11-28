#ifndef STOCKGATEWAY_H
#define STOCKGATEWAY_H

#include <string>
using namespace std;

class StockGateway{
  
  public:
  StockGateway(){}
  
  string FetchRealTimeStockValueBySymbol(string symbol);
};

#endif
