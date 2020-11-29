#include "StockGateway.h"

using namespace std;

#include <cpr/cpr.h>

string StockGateway::FetchRealTimeStockValueBySymbol(string symbol){
	cpr::Response r = cpr::Get(cpr::Url{"http://api.marketstack.com/v1/eod?access_key=52d803d632fff0ee40963c04bd5c5b21&symbols=" + symbol});
    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    r.text;   
  
  return r.text;
}
  
 