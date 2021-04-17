#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <fstream>
#include <nlohmann/json.hpp>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

using json = nlohmann::json;
using CompanyOrOwnerName = std::string;
using UUID = std::string;

struct Company
{
    std::string company_name;
    std::string company_info;
};
