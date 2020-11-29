#include <pistache/http.h>
#include <pistache/endpoint.h>
#include <pistache/router.h>

#include "Symbol.cpp"
//#include "StockController.cpp"
#include "StockGateway.cpp"

using namespace Pistache;
using namespace Rest;


namespace StockController{
  
  void getStockSymbol(const Rest::Request& request, Http::ResponseWriter response){
    auto collectedId = request.param(":name").as<string>();

    StockGateway gateway = StockGateway();
    cout << "Going to grab the value from the external API";
    auto result = gateway.FetchRealTimeStockValueBySymbol(collectedId);
    response.send(Http::Code::Ok, result);
  }

  void helloMethod(const Rest::Request& request, Http::ResponseWriter response){
      response.send(Http::Code::Ok, "Hello, World!");
  }
}

int main() {
  
  Symbol symbolToEvaluate("TSLA", "TESLA", "$", 500.60f);
  
  cout << symbolToEvaluate.getFullName();
  
  cout << "Listening on port 9082";
  
  Rest::Router router;
  
  Routes::Get(router, "/stock/:name", Routes::bind(&StockController::getStockSymbol));
  Routes::Get(router, "/hello", Routes::bind(&StockController::helloMethod));
  
  Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9085));

  auto opts = Http::Endpoint::options().threads(1);
  Http::Endpoint server(addr);
  server.init(opts);
  server.setHandler(router.handler());

  server.serve();
}