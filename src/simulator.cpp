// Program Information ////////////////////////////////////////////////////////
/**
 * @file simulator.cpp
 * 
 * @author Brandon Thai Nguyen
 *
 * @brief Implementation file for simulator class
 * 
 * @details Implements all member methods of the simulator class
 *
 * @version 1.00
 *          Michael Leverington (13 April 2016)
 *          Original Code
 *
 * @Note Requires simulator.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_SIMULATOR_CPP
#define CLASS_SIMULATOR_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "simulator.h"

// Class implementation ///////////////////////////////////////////////////////
Simulator::Simulator()
{

}

Simulator::~Simulator()
{
	// Varible Declaration
	Vehicle *temp;

	// Delete city
	for(int i = 0; i < citySizeX; i++)
	{
		temp = city[i];
		delete temp;
	}
	delete city;
	citySizeX = 0;
	citySizeY = 0;
}

void Simulator::initCity(int xCoor, int yCoor)
{
	// Set city size limits
	citySizeX = xCoor;
	citySizeY = yCoor;

	// Dynamically size city
	city = new Vehicle *[citySizeX];
	for(int i = 0, i < citySizeX, i++)
		city[i] = new Vehicle[yCoor];

}
// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_SIMULATOR_CPP