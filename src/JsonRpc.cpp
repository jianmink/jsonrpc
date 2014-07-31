#include "JsonRpc.h"

bool JsonRpc::parse(std::string str) {
    Json::Features features;
    Json::Reader reader(features);
    reader.parse(str, _root);

    Json::Value::Members members(_root.getMemberNames());
    std::sort(members.begin(), members.end());
    for (Json::Value::Members::iterator it = members.begin();
            it != members.end(); ++it) {
        const std::string &name = *it;
        std::cout << name;
        std::cout << _root[name];

        if ("method" == name) {
            _rpc = new DemoMethod();
        } else if ("params" == name) {
            _rpc->extractParams(_root[name]);
        }
    }

    return true;

}

bool DemoMethod::extractParams(Json::Value& params) {
    Json::Value::Members members(params.getMemberNames());
    std::sort(members.begin(), members.end());
    for (Json::Value::Members::iterator it = members.begin();
            it != members.end(); ++it) {
        const std::string &name = *it;
        std::cout << name;
        std::cout << params[name];

        if ("name" == name) {
            _params[name]=params[name].asString();
        }
    }

    return true;
}

void DemoMethod::invoke(){
    printf("my name is %s\n", _params["name"].c_str());
}

void JsonRpc::print() {

}

void JsonRpc::run(){

    _rpc->invoke();
}
