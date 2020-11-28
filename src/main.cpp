#include <pistache/endpoint.h>
#include "Symbol.cpp"

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
  
  Http::listenAndServe<HelloHandler>(Pistache::Address("*:9082"));
}