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
 * @brief Simulator Constructor
 *
 * @details Constructs the Simulator Class object
 *          
 * @pre None
 *
 * @post Simulator class object called
 *
 * @par Algorithm 
 *      None
 *      
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
Simulator::Simulator()
{
    // No data members to initialize
}

 /**
 * @brief Simulator Destructor
 *
 * @details Implicitly destructs all data structures
 *          
 * @pre Assume initialized class object
 *
 * @post None
 *
 * @par Algorithm 
 *      Simulator class data member destructors called implicitely upon deletion
 *      of the simulator class
 *      
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
Simulator::~Simulator()
{
    // 
}

 /**
 * @brief Run
 *
 * @details Runs the simulation 
 *          
 * @pre None
 *
 * @post Simulation ran
 *
 * @par Algorithm 
 *      Run the simulation in a loop executing commands from the user until the
 *      user terminates the program
 *      
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note Essentially the main driver
 */
void Simulator::run()
{
    // Varible Declaration
    char command;
    int worldSizeX = 0, worldSizeY = 0, ticks, numObjects;
    bool terminate = false, success;

    // Run simulator until termination
    while(!terminate)
    {
        // Display menu
        command = displayMenu();
        
        // Read command from user
        switch(command)
        {
            // Display world
            case 'd':
                world.displayWorld();
                break;

            // Initialize world
            case 'i':
                // Prompt world size from user
                std::cout << "Enter world size X: ";
                std::cin >> worldSizeX;
                std::cout << "Enter world size Y: ";   
                std::cin >> worldSizeY;
                std::cout << std::endl;

                // Init world
                success = world.initWorld(worldSizeX, worldSizeX);

                // Print status
                if(success)
                {
                    std::cout << worldSizeX << " by " << worldSizeY;
                    std::cout << " world created . . ." << std::endl;
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "ERROR: INVALID NUMBER ENTERED; WORLD NOT ";
                    std::cout << "INITIALIZED . . ." << std::endl << std::endl;
                }
                break;

            // Populate World
            case 'p':
                // Prompt for number of objects
                std::cout << "Enter number of vehicles to generate ";
                std::cout << "(Note: Must be less than ";
                std::cout << worldSizeX * worldSizeY << "): ";
                std::cin >> numObjects;
                std::cout << std::endl;

                // Populate world
                success = world.populateWorld(numObjects);

                // Print status
                if(success)
                {
                    std::cout << numObjects << " vehicles created . . .";
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "ERROR: INVALID NUMBER ENTERED; NO VEHICLES ";
                    std::cout << "CREATED . . ." << std::endl << std::endl;
                }
                break;

            // Run world a single tick
            case 'r':
                world.runWorld(1);
                break;

            // Run world n ticks
            case 'R':
                // Prompt for number of ticks
                std::cout << "Enter number of ticks: ";
                std::cin >> ticks;
                std::cout << std::endl;
                world.runWorld(ticks);
                break;

            // Terminate
            case 'q':
                std::cout << "Simulation Terminating . . . " << std::endl;
                std::cout << std::endl;
                terminate = true;
                break;

            // Unknown command
            default:
                std::cout << "ERROR: INVALID COMMAND . . ." << std::endl;
                std::cout << std::endl;
                break;
        }       
    }


}

 /**
 * @brief Display Menu
 *
 * @details Prints the list of available commands
 *          
 * @pre None
 *
 * @post Displays the menu 
 *
 * @par Algorithm 
 *      Standard I/O stream operations
 *      
 * @exception None
 *
 * @param None
 *
 * @return Char
 *
 * @note None
 */
char Simulator::displayMenu()
{
    // Varible Declaration
    char command;

    // Display list of commands
    std::cout << "Simulator Commands" << std::endl;
    std::cout << "  d - Display world" << std::endl;
    std::cout << "  i - Initialize world" << std::endl;
    std::cout << "  p - Populate world" << std::endl;
    std::cout << "  r - Run world one tick" << std::endl;
    std::cout << "  R - Run world n ticks" << std::endl;
    std::cout << "  q - Terminate Simulator" << std::endl;
    std::cout << "Command: ";
    std::cin >> command;
    std::cout << std::endl;

    // Return command entered
    return command;
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