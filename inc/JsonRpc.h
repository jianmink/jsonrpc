
#ifndef JSONRPC_H_
#define JSONRPC_H_
#include "json/json.h"
#include <iostream>

class Method{
public:
    //todo
    Method(){}
    virtual ~Method(){};
    virtual void invoke()=0;


    virtual bool extractParams(Json::Value&)=0;

protected:
    std::string _method;
    std::map<std::string, std::string> _params;
};


class DemoMethod:public Method{
public:
    virtual ~DemoMethod(){}

    virtual void invoke();
    virtual bool extractParams(Json::Value&);
};

class JsonRpc{
public:
    bool parse(std::string);
    void run();
    void print();

private:
    Json::Value _root;
    Method* _rpc;
};




#endif /* JSONRPC_H_ */
