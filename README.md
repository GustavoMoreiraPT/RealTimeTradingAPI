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



