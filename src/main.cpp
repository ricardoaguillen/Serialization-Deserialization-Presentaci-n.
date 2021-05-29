//
// Created by:
//  - Ricardo Guillen Porras .
//  - Royer Zuñiga Villarreal.
//  - Maria Angelica Robles.
//

#include <iostream>
#include "ProductManager.h"
#include "PhysicalProduct.h"
#include "DigitalProduct.h"
#include "FileManager.h"

int main() {

    ProductManager inventary;

    //Existing Physical Products
    PhysicalProduct rod("Physical", "Metal Rod #4", 3800, 6, "Metal");
    PhysicalProduct buildingLime("Physical", "Construction Building Lime 15 kg", 2400, 3, "Lime");
    PhysicalProduct snicker("Physical", "Snickers Chocolate Bar", 1200, 2, "Chocolate");
    PhysicalProduct cement("Physical", "Construction Cement 10 kg", 4000, 4, "Cement");

    //Digital Products
    DigitalProduct Videogame("Digital", "Dunkey Kong 89", 40000, 3, "30 mbps");
    DigitalProduct Videogame2("Digital", "Mario Kart 21", 30000, 1, "60 mbps");

    //Adding Products to the sale
    inventary.addPhysicalProduct(rod);
    inventary.addPhysicalProduct(buildingLime);
    inventary.addPhysicalProduct(snicker);
    inventary.addPhysicalProduct(cement);
    inventary.addDigitalProduct(Videogame);
    inventary.addDigitalProduct(Videogame2);

    std::cout << inventary.toString() << std::endl;


    std::cout << "Serialización del Json" << std::endl;
    std::cout << FileManager::serialize(inventary);
    // Save the data into Person.json
    FileManager::save(FileManager::serialize(inventary), "Inventary.json");


    ProductManager inventaryListFromJson;
    std::cout << "\n\nDeserialización del Json" << std::endl;
    string dataFromJSonFile;
    dataFromJSonFile = FileManager::read("Inventary.json");

    std::cout << "Info del json deserializado" << std::endl;
    std::cout << dataFromJSonFile << std::endl << std::endl;

    inventaryListFromJson = FileManager::deserialize(dataFromJSonFile);
    std::cout << "Lista deserializada" << std::endl << std::endl;
    std::cout << inventaryListFromJson.toString() << std::endl;

    return 0;
}
