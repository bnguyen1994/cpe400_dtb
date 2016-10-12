// Program Information ////////////////////////////////////////////////////////
/**
 * @file world.h
 *
 * @brief Definition file for world class
 * 
 * @author Brandon Thai Nguyen
 * 
 * @details Specifies all member methods of the world class
 *
 * @version 1.00
 *          Brandon Thai Nguyen (03 October 2016)
 *          Original Code
 *
 * @Note Requires world.h, vehicle.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_WORLD_H
#define CLASS_WORLD_H

// Header files ///////////////////////////////////////////////////////////////

#include <cstdlib>
#include <vector>
#include <time.h>

#include "vehicle.h"

// Class definition  //////////////////////////////////////////////////////////
template <class DataType>
class World
{
public:
    // Constructors
    World();
    ~World();

    // World control
    void initWorld(int sizeX, int sizeY);
    void displayWorld();
    bool populateWorld(int numObjects);

    // Accessors
    int getNumObjects();
    std::vector<DataType*> &getObjectList();

    bool isObjectPresent(int xCoor, int yCoor);
    bool insertObject(int xCoor, int yCoor, DataType *object);
    bool getObject(int xCoor, int yCoor, DataType *object);
    bool removeObject(int xCoor, int yCoor, DataType *object);
    bool deleteObject(int xCoor, int yCoor);



private:
    // Helper functions
    int findFromList(DataType *object);
    bool removeFromList(int index);
    // Class varibles
    int worldSizeX;
    int worldSizeY;
    int numObjects; /* number of objects present in world */
    std::vector<DataType*> objectList; /* list of objects present in world */ 
    DataType ***world; /* xCoors ptrs of yCoors ptrs of object ptrs. */
};
// Terminating precompiler directives  ////////////////////////////////////////

#endif      // #ifndef CLASS_WORLD_H
