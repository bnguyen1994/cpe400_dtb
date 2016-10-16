// Program Information ////////////////////////////////////////////////////////
/**
 * @file Main.cpp
 *
 * @brief Driver program
 * 
 * @details
 *
 * @version 1.1
 *          Brandon Thai Nguyen (06 September 2016)
 *          Updated for use with simulator class
 *
 *          1.0
 *          Tyler Goffinet (28 September 2016)
 *          Original Code
 *
 * @Note 
 */
// Precompiler directives /////////////////////////////////////////////////////

    // none

// Header Files ///////////////////////////////////////////////////////////////

#include <iostream>
#include "simulator.h"

// Global Constant Definitioans  //////////////////////////////////////////////

// Function Prototypes ////////////////////////////////////////////////////////

// Main Function Implementation ///////////////////////////////////////////////

int main(int argc, char **argv)
{
    // Varible Declaration
    Simulator simulator;
    int worldSizeX, worldSizeY;
    bool successFlag;

    // Get world size from user
    cout << "Enter World Size X: ";
    cin >> worldSizeX;
    cout << "Enter World Size Y: ";   
    cin >> worldSizeY;

    // Init world
    simulator.initWorld(worldSizeX, worldSizeX);

    // Return
    return EXIT_SUCCESS;
}

// Function Implementation ////////////////////////////////////////////////////

    // None