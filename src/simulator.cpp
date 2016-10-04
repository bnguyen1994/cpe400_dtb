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
 * @version 1.0
 *          Brandon Thai Nguyen (03 October 2016)
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
 /**
 * @brief 
 *
 * @details 
 *          
 * @pre 
 *
 * @post 
 *
 * @par Algorithm 
 *      
 *      
 * @exception 
 *
 * @param 
 *
 * @return 
 *
 * @note 
 */
Simulator::Simulator()
{

}

Simulator::~Simulator()
{

}

 /**
 * @brief Initialize world
 *
 * @details Dynamically constructs the world with given parameters
 *          
 * @pre Assume initialized world object
 *
 * @post World initialized
 *
 * @par Algorithm 
 *      Call the world class initWorld function
 *      
 * @exception None
 *
 * @param [in] sizeX
 *             Max x-axis world size to be set
 *
 *        [in] sizeY
 *             Max y-axos world size to be set
 *
 * @return None
 *
 * @note None
 */
void Simulator::initWorld(int sizeX, int sizeY)
{
	world.initWorld(sizeX,sizeY);
}
// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_SIMULATOR_CPP