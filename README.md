# RealTimeTradingAPI
This is a repository for the Udacity C++ nanodegree Capstone project

## Scope of the project
This project is intended to be a very simple example on how to build a REST API using C++.
The concept created in the context of the Udacity Capstone project allows us to call endpoints that retrieve real stock information of a certain symbol.
For example, if you want to know the stock value of Tesla, you just do "PATH_TO_API"/stock/TSLA

## Instructions to build the project in the workspace
This project uses two different libraries, that require installation in order for the project to run sucessfully. These libraries are:

- **Pistache** - A REST Framework that allows easy declaration of endpoints and routing (https://github.com/pistacheio/pistache) 
- **Cpr** - An HTTP Client that easily allows to call external API's (https://github.com/whoshuu/cpr)

#### Install Pistache
To install Pistache, the following steps are required

From your terminal:

- git clone https://github.com/oktal/pistache.git
- git submodule update --init
- mkdir build
- cd build
- cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
- make
- sudo make install

#### Install Cpr
To install Cpr, the following steps are required

**Note for UDACITY Workspace:** the preinstalled version of CMAKE is 3.13. To build Cpr, CMAKE 3.15 or higher is required.
In order to successfully build Cpr, upgrading first CMAKE is necessary.
Steps to complete CMAKE upgrade:

- apt remove cmake
- pip install cmake --upgrade

From your terminal:

- git clone https://github.com/whoshuu/cpr.git
- cd cpr
- mkdir build && cd build
- cmake ..
- make
- make install

#### Troubleshooting of erros in the Udacity Workspace
When running the project from the Udactity Workspace, an error similar to the following happened every now and then:

https://github.com/CogChameleon/ChromaTag/issues/2

If this happens, run the following command in your terminal:

- sudo ldconfig -v

## Build, run and test the program
In order to run this project, the following steps are required

- clone this project (https://github.com/GustavoMoreiraPT/RealTimeTradingAPI.git)
- navigate to the "src" folder
- run: g++ -std=c++14 main.cpp -o main -lpistache -lpthread -lcpr
- execute: ./main
- curl 127.0.0.1/stock/TSLA

After executing these steps, you should see the result from the latest stock exchange of NASDAQ for the TSLA symbol. 
Please not that you can use any symbol that you like.

## Code explanation
At the current moment, this API is still very simple. The logic is divided into two main components:

- **main.cpp** - this class instantiate the Pistache routes for the endpoints, and handles the responsability of the requests by creating instances of StockGateway classes.
- **StockGateway.h and StockGateway.cpp** - Process the requests from the user by encapsulating the logic of calling an external API to retrieve stock values.

## Rubric Points Accessment
In this section it's discussed how to project accomplishes the 5 required rubric points from Udacity to pass the Capstone Project.

- 1 - In Object Oriented Programming, for the Criteria "The project uses Object Oriented Programming Techniques", the class definition and it's implementation of StockGateway, divided between files StockGateway.h and StockGateway.cpp, satisfy this criteria.
- 2 - In Object Oriented Programming, for the Criteria "Classes use appropriate access specifiers for class members", the criteria is also satisfied. In StockGateway.h, there is a clear separation between private and public members.
- 3 - In Object Oriented Programming, for the Criteria "Classes abstract implementation details from their interfaces" is also satisfied, since the method names are clean and do not pass details on hoe the "task" is being done. For example, in StockGateway.cpp, the method "fetchRealTimeStockValueBySymbol" provides a clear intention to the developer that decides to use the method, and it hides all the implementation details. For example, the method signature never says to the developer that is going to use Cpr library to call an external api. For what is worth, the method could have been fetching the stock value from a local database and the developer would never know.
- 4 - In Object Oriented Programming, for the Criteria "Classed encapsulate behavior" is also satisfied. In StockGateway.h there is a private variavle "apiCalls" that cannot be directly access through it's callers, only though member functions "getApiCalls()" to read the current value, or to increment the current value by one by using the function "incrementApiCalls".
- 5 - In Object Oriented Programming, for the Criteria "Overloaded functions allow the same function to operate on different parameters" is also satisfied. In StockGateway.h, there are two different method signatures for the same function "fetchRealTimeStockValueBySymbol" (lines 42 and 44). One of the signatures receives only one string, while the other one receives two strings.
- 6 - In Memory Management, for the Criteria "The project makes use of references in function declarations", both methods "fetchRealTimeStockValueBySymbol" receive a reference string instead of a value string.
- 7 - In Memory Management, for the Criteria "The project follows the Rule of 5", the class defined in StockGateway.h uses the rule of 5 by defining all possible constructors, copy constructors and move operators.




