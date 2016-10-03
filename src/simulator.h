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
 * @version 1.00
 *          Brandon Thai Nguyen (03 October 2016)
 *          Original Code
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_SIMULATOR_H
#define CLASS_SIMULATOR_H

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

// Class definition  //////////////////////////////////////////////////////////
class Simulator
{
public:
	// Constructors
	Simulator();
	~Simulator();

	// World Control
	initCity(int xCoor, int yCoor);
	moveVehicle(); // NEEDS PARAMS
private:
};
// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_SIMULATOR_H
