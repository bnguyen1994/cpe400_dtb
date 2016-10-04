// Program Information ////////////////////////////////////////////////////////
/**
 * @file simulator.h
 *
 * @brief Definition file for simulator class
 * 
 * @author Brandon Thai Nguyen
 * 
 * @details Specifies all member methods of the simulator class
 *
 * @version 1.0
 *          Brandon Thai Nguyen (03 October 2016)
 *          Original Code
 *
 * @Note Requires vehicle.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_SIMULATOR_H
#define CLASS_SIMULATOR_H

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include "vehicle.h"
#include "world.cpp"
using namespace std;

// Class definition  //////////////////////////////////////////////////////////
class Simulator
{
public:
	// Constructors
	Simulator();
	~Simulator();

	// World Control
	void initWorld(int sizeX, int sizeY);
	bool moveVehicle(int xCoorFrom, int yCoorFrom, int xCoorTo, int yCoorTo);
	void run(int ticks);
	void displayWorld();

private:
	World<Vehicle> world;
};
// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_SIMULATOR_H
