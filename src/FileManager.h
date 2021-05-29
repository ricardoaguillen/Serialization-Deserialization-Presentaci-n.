//
// Created by:
//  - Ricardo Guillen Porras .
//  - Royer Zuñiga Villarreal.
//  - Maria Angelica Robles.
//

#ifndef PRODUCTMANAGER_FILEMANAGER_H
#define PRODUCTMANAGER_FILEMANAGER_H

#include "../lib/nlohmann/json.hpp"

#include <string>
#include "ProductManager.h"

using namespace std;
using ::nlohmann::json;

class FileManager {
public:
    static void save(const string &jsonData, const std::string &filename);

    static string read(const std::string &filename);

    static string serialize(ProductManager &_productList);

    static ProductManager deserialize(const string &_data);
};

#endif //PRODUCTMANAGER_FILEMANAGER_H
