#include "Symbol.h"


string Symbol::getName(){
	return this->name;
}

string Symbol::getFullName(){
	return this->fullName;
}

string Symbol::getDefaultCurrencySymbol(){
	return this->defaultCurrency;
}

float Symbol::getCurrentValue(){
	return this->currentValue;
}