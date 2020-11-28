#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
using namespace std;

class Symbol{
	public:
  		string getName();
  		string getFullName();
  		string getDefaultCurrencySymbol();
  		float getCurrentValue();
  		Symbol(string n, string fn, string current, float value){
          name = n;
          fullName = fn;
          defaultCurrency = current;
          currentValue = value;
        };
  
  	private: 
  		string name;
  		string fullName;
  		string defaultCurrency;
  		float currentValue;
};

#endif