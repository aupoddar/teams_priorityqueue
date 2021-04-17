#include <iostream>
#include "json.hpp"
#include "priorityqueue.h"
#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>


int main(int argc,  char **argv) {
    //open file here
    std::ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObject;
    if(file.is_open()){
        //std::cout << "here" << std::endl;
        file >> jsonObject;
        //std::cout << jsonObject;
    }


    //read in values
    int max =jsonObject["metadata"]["maxHeapSize"];
    PriorityQueue Tree(max); //mazheapsizees
    Tree.numoperations = jsonObject["metadata"]["numOperations"];
    for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr) {

        std::string temp = itr.key(); //this loop goes through for each sample (key)

        if(temp != "metadata") { //if the sample isn't the metadata thingie, so this is to store all contents into an array

                if(jsonObject[temp]["operation"] == "insert"){
                    int val = jsonObject[temp]["key"];
                    Tree.insert(val);
                } else if(jsonObject[temp]["operation"] == "removeMin"){
                    Tree.removeMin();
                }

        }

    }

    //jsonObj.dump(2);
    //read each key

    //PriorityQueue Tree(num); //mazheapsizees

    std::cout << Tree.JSON().dump(2);




    return 0;


  //  std::cout << Tree.JSON().dump(1);
}