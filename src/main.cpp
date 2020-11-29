#include <pistache/http.h>
#include <pistache/endpoint.h>
#include <pistache/router.h>

#include "StockGateway.cpp"

using namespace Pistache;
using namespace Rest;


namespace StockController{
  
  void getStockSymbol(const Rest::Request& request, Http::ResponseWriter response){
    auto collectedId = request.param(":name").as<string>();

    StockGateway gateway = StockGateway();
    auto result = gateway.fetchRealTimeStockValueBySymbol(collectedId);
    gateway.incrementApiCalls();
    response.send(Http::Code::Ok, result);
  }
  
  void getStockSymbolByTimeOfDay(const Rest::Request& request, Http::ResponseWriter response){
  	auto collectedId = request.param(":name").as<string>();
    auto collectedTimeOfDay = request.param(":timeofday").as<string>();
    
    StockGateway gateway = StockGateway();
    auto result = gateway.fetchRealTimeStockValueBySymbol(collectedId, collectedTimeOfDay);
    response.send(Http::Code::Ok, result);
  }

  void helloMethod(const Rest::Request& request, Http::ResponseWriter response){
      response.send(Http::Code::Ok, "Hello, World!");
  }
}

int main() {
  
  cout << "Listening on port 9081";
  
  Rest::Router router;
  
  Routes::Get(router, "/stock/:name", Routes::bind(&StockController::getStockSymbol));
  Routes::Get(router, "/stock/:name/:timeofday", Routes::bind(&StockController::getStockSymbolByTimeOfDay));
  Routes::Get(router, "/hello", Routes::bind(&StockController::helloMethod));
  
  Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9081));

  auto opts = Http::Endpoint::options().threads(1);
  Http::Endpoint server(addr);
  server.init(opts);
  server.setHandler(router.handler());

  server.serve();
}