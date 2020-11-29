#include "StockGateway.h"
#include <cpr/cpr.h>
using namespace std;


string StockGateway::fetchRealTimeStockValueBySymbol(string& symbol){
	cpr::Response r = cpr::Get(cpr::Url{"http://api.marketstack.com/v1/eod/latest?access_key=52d803d632fff0ee40963c04bd5c5b21&symbols=" + symbol});
    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    r.text;   
  
  return r.text;
}

string StockGateway::fetchRealTimeStockValueBySymbol(string& symbol, string& timeOfDay){
	if(timeOfDay == "eod" || timeOfDay == "intraday"){
    cpr::Response r = cpr::Get(cpr::Url{"http://api.marketstack.com/v1/" + timeOfDay + "/latest?access_key=52d803d632fff0ee40963c04bd5c5b21&symbols=" + symbol});
    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    r.text;   
  
  	return r.text;
    }
  
  return "BAD REQUEST: time of day can only be set to eod or intraday";
}

int StockGateway::getApiCalls(){
	return this->apiCalls;
}

void StockGateway::incrementApiCalls(){
  	this->apiCalls++;
}
  
 