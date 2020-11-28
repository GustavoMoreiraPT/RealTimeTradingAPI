#include <pistache/endpoint.h>
#include "Symbol.cpp"
#include "StockController.cpp"

using namespace Pistache;

struct HelloHandler : public Http::Handler {
  HTTP_PROTOTYPE(HelloHandler)
  void onRequest(const Http::Request&, Http::ResponseWriter writer) override{
    writer.send(Http::Code::Ok, "Hello, World!");
  }
};

int main() {
  
  Symbol symbolToEvaluate("TSLA", "TESLA", "$", 500.60f);
  
  cout << symbolToEvaluate.getFullName();
  
  cout << "Listening on port 9082";
  
  Http::Router router;
  
  Routes::Get(router, "/stock", Routes::bind(&StockController::getStockSymbol, this));
  Routes::Get(router, "/hello", Routes::bind(&StockController::helloMethod, this));
  
  Net::Address addr(Net::Ipv4::any(), Net::Port(9080));

  auto opts = Http::Endpoint::options().threads(1);
  Http::Endpoint server(addr);
  server.init(opts);
  server.setHandler(router.handler());
  
  //server.setHandler(std::make_shared<HelloHandler>());
  server.serve();
}