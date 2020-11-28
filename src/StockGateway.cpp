#include "StockGateway.h"

using namespace std;
using namespace boost::network;
using namespace boost::network::http;

string StockGateway::FetchRealTimeStockValueBySymbol(string symbol){
	client::request request_("http://api.marketstack.com/v1/eod?access_key=52d803d632fff0ee40963c04bd5c5b21&symbols=" + symbol);
    request_ << header("Connection", "close");
    client client_;
    client::response response_ = client_.get(request_);
    std::string body_ = body(response_);
}
  
 