#ifndef STOCKCONTROLLER_H
#define STOCKCONTROLLER_H

#include <string>
#include <pistache/router.h>
#include "pistache/endpoint.h"
#include "pistache/http.h"

using namespace std;
using namespace Pistache;

class StockController{
  public:
  	void getStockSymbol(const Rest::Request& request, Http::ResponseWriter response);
  	void helloMethod(const Rest::Request& request, Http::ResponseWriter response);
  
  private:
  	string id;
};

#endif