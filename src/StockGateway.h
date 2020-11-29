#ifndef STOCKGATEWAY_H
#define STOCKGATEWAY_H

#include <string>
using namespace std;

class StockGateway{
  
  public:
    StockGateway(){}
	~StockGateway(){}
  	StockGateway(int calls){
      apiCalls = calls;
    }
  	StockGateway(const StockGateway& sg){
    	apiCalls = sg.apiCalls;
    }
  	StockGateway(StockGateway &&sg){
      apiCalls = sg.apiCalls;
      sg.apiCalls = 0;
    }
  
    StockGateway &operator=(const StockGateway &sg){
		if(this == &sg){
        	return *this;
        }
      
      	apiCalls = sg.apiCalls;
      	
      	return *this;
    }
  
  	StockGateway &operator=(StockGateway &&sg){
    	if(this == &sg){
        	return *this;
        }
      
      	apiCalls = sg.apiCalls;
      	sg.apiCalls = 0;
    }

    string fetchRealTimeStockValueBySymbol(string& symbol);
  
  	string fetchRealTimeStockValueBySymbol(string& symbol, string& timeOfDay);
  
  	int getApiCalls();
  	void incrementApiCalls();
  
  private:
  	int apiCalls;
};

#endif
