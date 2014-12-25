#pragma once
#include <string>
#include <fstream>
#include <iostream>

#include "json/json.h"


using std::string;
using std::cout;
using std::endl;


class Level{
   public:
        static bool toObject(const std::string& stringJson, Json::Value &  objectJson);
        static bool toString(std::string& stringJson, const Json::Value &  objectJson);
        bool output(const Json::Value & value);
        bool lool(){return true;}
};