#include "StockController.h"
#include "StockGateway.cpp"

void StockController::getStockSymbol(const Rest::Request& request, Http::ResponseWriter response){
  auto collectedId = request.param(":id").as<string>();
  this->id = collectedId;
  
  StockGateway gateway = StockGateway();
  auto result = gateway.FetchRealTimeStockValueBySymbol(collectedId);
  response.send(Http::Code::Ok, result);
}

void Stock::Controller::helloMethod(const Rest::Request& request, Http::ResponseWriter response){
	response.send(Http::Code::Ok, "Hello, World!");
}