// Program Information ////////////////////////////////////////////////////////
/**
 * @file vehicle.cpp
 *
 * @author Brandon Thai Nguyen
 *
 * @brief Implementation file for vehicle classes
 *
 * @details Implements all member methods of the vehicle classes
 *
 * @version
 *          2.0
 *          Tyler Goffinet (24 October 2016)
 *          Implemented functions
 *
 *          1.0
 *          Brandon Thai Nguyen (03 October 2016)
 *          Original Code
 *
 * @note Requires vehicle.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_VEHICLE_CPP
#define CLASS_VEHICLE_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "vehicle.h"

// Class implementation ///////////////////////////////////////////////////////

/**
 * @brief Constructor for abstract Vehicle class
 *
 * @details Sets up class member variables. Destination set to given position.
 *          recommend calling setDestination() from derived class constructors.
 *
 * @pre None
 *
 * @post None
 *
 * @par Algorithm
 *      Sets destination to given position
 *
 * @exception
 *
 * @param [in] x
 *             X position of vehicle
 *
 *        [in] y
 *             Y position of vehicle
 *
 *        [in] rowMax
 *             Number of rows allowed
 *
 *        [in] colNum
 *             Number of columns allowed
 *
 *        [in] hasPkt
 *             Contains packet
 *
 * @note None
 */
Vehicle::Vehicle( int x, int y, int rowMax, int columnMax, bool hasPkt )
    : xPos( x ),
      yPos( y ),
      rowMax( rowMax ),
      colMax( columnMax ),
      hasPkt( hasPkt )
{
  xDest = xPos;
  yDest = yPos;

  xNextPos = xPos;
  yNextPos = yPos;

  vehicleDir = NaN;

  redirectCounter = 0;
}

/**
 * @brief Moves vehicle
 *
 * @details Sets current location to next location and recalcuates
 *          next location
 *
 * @pre None
 *
 * @post Current location, next location, and direction are updated
 *
 * @par Algorithm
 *      Set current location to next location
 *      If current location is destination, then change destination
 *      Calculate new next location and direction
 *
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note Warning: Does NOT know about other vehicles
 */
void Vehicle::move()
{
  xPos = xNextPos;
  yPos = yNextPos;

  redirectCounter = 0;

  // If destination reached, calculate new destination
  if( xPos == xDest && yPos == yDest ) calculateDestination();

  // DEBUG:
  int        xTemp = xNextPos, yTemp = yNextPos;
  VehicleDir dirTemp = vehicleDir;
  calcNextLocation();
  if( xNextPos < 0 || colMax <= xNextPos || yNextPos < 0 || rowMax <= yNextPos )
  {
    xNextPos = 0;
  }
  xNextPos   = xTemp;
  yNextPos   = yTemp;
  vehicleDir = dirTemp;

  // Recalculate next location
  calcNextLocation();
}

/**
 * @brief Redirects the vehicle
 *
 * @details Attempts to have the car to take an alternative route
 *
 * @pre None
 *
 * @post Vehicle direction and next position is modified
 *
 * @par Algorithm
 *      Stage 1: Find route alternative
 *      Stage 2: Attempt to wiggle your way out
 *      Stage 3: Give up all hope
 *
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note Calling multiple times while not calling move will invoke
 *       different behaviors
 */
void Vehicle::redirect()
{
  ++redirectCounter;

  if( redirectCounter == 1 )
  {
    calcAltDirection();
  }
  // Attempt to 'wiggle' your way out; if more than 3 trys, give up
  else if( redirectCounter == 2 )
  {
    // Invert direction
    switch( vehicleDir )
    {
      case NaN:
        vehicleDir = NaN;
        break;
      case UP:
        planDown();
        break;
      case DOWN:
        planUp();
        break;
      case LEFT:
        planRight();
        break;
      case RIGHT:
        planLeft();
        break;
    }
  }
  else if( redirectCounter == 3 )
  {
    // Try a different direction
    switch( vehicleDir )
    {
      case NaN:
        calcAltDirection();
        break;
      case UP:
        planLeft();
        break;
      case DOWN:
        planRight();
        break;
      case LEFT:
        planUp();
        break;
      case RIGHT:
        planDown();
        break;
    }
  }
  else if( redirectCounter == 4 )
  {
    // Try an even different direction
    switch( vehicleDir )
    {
      case NaN:
        calcAltDirection();
        break;
      case UP:
        planRight();
        break;
      case DOWN:
        planLeft();
        break;
      case LEFT:
        planDown();
        break;
      case RIGHT:
        planUp();
        break;
    }
  }

  if( redirectCounter == 1 )
  {
    // Do nothing
  }
  else if( 1 < redirectCounter && redirectCounter < 5 )
  {
    // Recalculate with new direction
    calcNextLocation();
  }
  else
  {
    // Give up :(
    vehicleDir = NaN;
  }
}

/**
 * @brief Calculates vehicles's next location
 *
 * @details Using current location, next location, and direction,
 *          recalculates the location the car should be next
 *
 * @pre None
 *
 * @post None
 *
 * @par Algorithm
 *      Based on the direction, move towards destination along x axis first
 *      If wanted direction is behind, then make alternate turn
 *      If direction set to NaN, then any turn is possible
 *
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note Does not allow immediate U-turns. If no other options are
 *       available two move() calls are required to complete a U-turn.
 *       If direction set to NaN, then any turn is possible
 */
void Vehicle::calcNextLocation()
{
  xNextPos = xPos;
  yNextPos = yPos;

  // Get front facing locations
  switch( vehicleDir )
  {
    case NaN:
      if( xPos != xDest )
      {
        ( xDest < xPos ) ? planLeft() : planRight();
      }
      else if( yPos != yDest )
      {
        ( yDest < yPos ) ? planUp() : planDown();
      }
      else /* xPos == xDest && yPos == yDest */
      {
        vehicleDir = NaN;
      }
      break;

    case UP:
      if( xPos != xDest )
      {
        ( xDest < xPos ) ? planLeft() : planRight();
      }
      else if( yPos != yDest )
      {
        ( yDest < yPos ) ? planUp() : calcAltDirection();
      }
      else /* xPos == xDest && yPos == yDest */
      {
        vehicleDir = NaN;
      }
      break;

    case DOWN:
      if( xPos != xDest )
      {
        ( xDest < xPos ) ? planLeft() : planRight();
      }
      else if( yPos != yDest )
      {
        ( yDest < yPos ) ? calcAltDirection() : planDown();
      }
      else /* xPos == xDest && yPos == yDest */
      {
        vehicleDir = NaN;
      }
      break;

    case LEFT:
      if( xPos != xDest )
      {
        ( xDest < xPos ) ? planLeft() : calcAltDirection();
      }
      else if( yPos != yDest )
      {
        ( yDest < yPos ) ? planUp() : planDown();
      }
      else /* xPos == xDest && yPos == yDest */
      {
        vehicleDir = NaN;
      }
      break;

    case RIGHT:
      if( xPos != xDest )
      {
        ( xDest < xPos ) ? calcAltDirection() : planRight();
      }
      else if( yPos != yDest )
      {
        ( yDest < yPos ) ? planUp() : planDown();
      }
      else /* xPos == xDest && yPos == yDest */
      {
        vehicleDir = NaN;
      }
      break;
  }
}

/**
 * @brief Calculates an alterative direction
 *
 * @details Determines an optimal alterative way to the destination ignoring the
 *          possiblity of going fowards or backward
 *
 * @pre None
 *
 * @post Vehicle direction not forward or backward; next position is modified
 *
 * @par Algorithm
 *      Find optimal 90 degree alternate direction
 *      If no other direction possible, then direction set to NaN
 *
 * @exception None
 *
 * @param None
 *
 * @return Whether vehicle is boxed in on its sides
 *
 * @note If vehicle is boxed in on both sides left/right or up/down, then
 *       stops vehicle
 */
bool Vehicle::calcAltDirection()
{
  bool canMove = false;

  // Reset next position
  xNextPos = xPos;
  yNextPos = yPos;

  // Want to go alternate direction, but can't make U-turn
  switch( vehicleDir )
  {
    case NaN:
      vehicleDir = NaN;
      break;

    case UP:
    case DOWN:
      canMove = ( xDest < xPos ) ? planLeft() : planRight();

      if( !canMove ) /* can't move; Go in other direction */
      {
        canMove = ( xDest < xPos ) ? planRight() : planLeft();

        if( !canMove ) stop(); /* boxed in */
      }
      break;

    case LEFT:
    case RIGHT:
      canMove = ( yDest < yPos ) ? planUp() : planDown();

      if( !canMove ) /* can't move; Go in other direction */
      {
        canMove = ( yDest < yPos ) ? planDown() : planUp();

        if( !canMove ) stop(); /* boxed in */
      }
      break;
  }

  return canMove;
}

/**
 * @brief Stop vehicle
 *
 * @details Sets next position equal to current position and sets direction
 *          to NaN
 *
 * @pre None
 *
 * @post Next location = current position; direction = NaN;
 *
 * @par Algorithm
 *      Set vehicle direction = NaN
 *      Set next position equal = current position
 *
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
void Vehicle::stop()
{
  vehicleDir = NaN;
  xNextPos   = xPos;
  yNextPos   = yPos;
}

/**
 * @brief Sets next location and direction to go up
 *
 * @details Increments X next position and sets direction up if
 *          within boundaries
 *
 * @pre None
 *
 * @post Next location and direction are modified
 *
 * @par Algorithm
 *      Checks if next position would be out of bounds
 *      Alters vehicle direction and next position
 *
 * @exception None
 *
 * @param None
 *
 * @return Returns true if turn is not out of bounds; false otherwise
 *
 * @note None
 */ bool
Vehicle::planUp()
{
  if( yNextPos - 1 >= 0 )
  {
    vehicleDir = UP;
    --yNextPos;

    return true;
  }

  return false;
}

/**
 * @brief Sets next location and direction to go down
 *
 * @details Increments X next position and sets direction down if
 *          within boundaries
 *
 * @pre None
 *
 * @post Next location and direction are modified
 *
 * @par Algorithm
 *      Checks if next position would be out of bounds
 *      Alters vehicle direction and next position
 *
 * @exception None
 *
 * @param None
 *
 * @return Returns true if turn is not out of bounds; false otherwise
 *
 * @note None
 */
bool Vehicle::planDown()
{
  if( yNextPos + 1 < rowMax )
  {
    vehicleDir = DOWN;
    ++yNextPos;

    return true;
  }

  return false;
}

/**
 * @brief Sets next location and direction to go left
 *
 * @details Decrements X next position and sets direction left if
 *          within boundaries
 *
 * @pre None
 *
 * @post Next location and direction are modified
 *
 * @par Algorithm
 *      Checks if next position would be out of bounds
 *      Alters vehicle direction and next position
 *
 * @exception None
 *
 * @param None
 *
 * @return Returns true if turn is not out of bounds; false otherwise
 *
 * @note None
 */
bool Vehicle::planLeft()
{
  if( xNextPos - 1 >= 0 )
  {
    vehicleDir = LEFT;
    --xNextPos;

    return true;
  }

  return false;
}

/**
 * @brief Sets next location and direction to go right
 *
 * @details Increments X next position and sets direction right if
 *          within boundaries
 *
 * @pre None
 *
 * @post Next location and direction are modified
 *
 * @par Algorithm
 *      Checks if next position would be out of bounds
 *      Alters vehicle direction and next position
 *
 * @exception None
 *
 * @param None
 *
 * @return Returns true if turn is not out of bounds; false otherwise
 *
 * @note None
 */
bool Vehicle::planRight()
{
  if( xNextPos + 1 < colMax )
  {
    vehicleDir = RIGHT;
    ++xNextPos;

    return true;
  }

  return false;
}

/**
 * @brief Searches for best vehicle to pass packet to in order to reach destination
 *
 * @details
 *
 *
 * @pre None
 *
 * @post throws packet to returned vehicle
 *
 * @par Algorithm
 *      Checks if next position would be out of bounds
 *      Alters vehicle direction and next position
 *
 * @exception None
 *
 * @param None
 *
 * @return Returns pointer to vehicle which should receive the packet
 *
 * @note None
 */
Vehicle *Vehicle::findPacketDest( ) {



  return nullptr;
}

/**
 * @brief Sets next location and direction to go right
 *
 * @details Increments X next position and sets direction right if
 *          within boundaries
 *
 * @pre None
 *
 * @post Next location and direction are modified
 *
 * @par Algorithm
 *      Checks if next position would be out of bounds
 *      Alters vehicle direction and next position
 *
 * @exception None
 *
 * @param None
 *
 * @return Returns true if turn is not out of bounds; false otherwise
 *
 * @note None
 */
void Vehicle::throwPacket(Vehicle *targetVehicle, Packet thrownPacket) {

  if(targetVehicle->packetCaught(thrownPacket))
  {

  }

}

/**
 * @brief Sets next location and direction to go right
 *
 * @details Increments X next position and sets direction right if
 *          within boundaries
 *
 * @pre None
 *
 * @post Next location and direction are modified
 *
 * @par Algorithm
 *      Checks if next position would be out of bounds
 *      Alters vehicle direction and next position
 *
 * @exception None
 *
 * @param None
 *
 * @return Returns true if turn is not out of bounds; false otherwise
 *
 * @note None
 */
bool Vehicle::packetCaught(Packet thrownPacket) {
  bool inList = false;
  for(int i = 0; i < thrownPacket.ids.size(); i++)
  {
    if (thrownPacket.ids[i] == VehicleId)
    {
      inList = true;
      break;
    }
  }
  if(!inList)
  {
    newPacket = new Packet;
    newPacket-> destX = thrownPacket.destX;
    newPacket -> destY = thrownPacket.destY;
    newPacket -> srcX = thrownPacket.srcX;
    newPacket -> srcY = thrownPacket.srcY;
    newPacket -> message = thrownPacket.message;
    newPacket -> ids = thrownPacket.ids;
    newPacket -> ids.push_back(VehicleId);
    newPacket -> packetId = thrownPacket.packetId;
    newPacket -> thrown = false;

    packets.push_back(*newPacket);

    hasPkt = true;
  }

  return false;
}

/**
 * @brief Sets next location and direction to go right
 *
 * @details Increments X next position and sets direction right if
 *          within boundaries
 *
 * @pre None
 *
 * @post Next location and direction are modified
 *
 * @par Algorithm
 *      Checks if next position would be out of bounds
 *      Alters vehicle direction and next position
 *
 * @exception None
 *
 * @param None
 *
 * @return Returns true if turn is not out of bounds; false otherwise
 *
 * @note None
 */
void Vehicle::catchPacket(Packet thrownPacket) {

  bool inList = false;
  for(int i = 0; i < thrownPacket.ids.size(); i++)
  {
    if (thrownPacket.ids[i] == VehicleId)
    {
      inList = true;
      break;
    }
  }
  if(!inList)
  {

    newPacket = new Packet;
    newPacket-> destX = thrownPacket.destX;
    newPacket -> destY = thrownPacket.destY;
    newPacket -> srcX = thrownPacket.srcX;
    newPacket -> srcY = thrownPacket.srcY;
    newPacket -> message = thrownPacket.message;
    newPacket -> ids = thrownPacket.ids;
    newPacket -> packetId = thrownPacket.packetId;
    newPacket -> ids.push_back(VehicleId);

    packets.push_back(*newPacket);

    hasPkt = true;
  }

  return;
}


/**
 * @brief Constructor for Taxi class derived from abstrat Vehicle class
 *
 * @details Calculates destination and next location
 *
 * @pre None
 *
 * @post None
 *
 * @par Algorithm
 *      Calculates destination
 *      Calculates next location
 *
 * @exception None
 *
 * @param [in] x
 *             X position of vehicle
 *
 *        [in] y
 *             Y position of vehicle
 *
 *        [in] rowMax
 *             Number of rows allowed
 *
 *        [in] colNum
 *             Number of columns allowed
 *
 *        [in] hasPkt
 *             Contains packet
 *
 * @note None
 */
Taxi::Taxi( int x, int y, int rowMax, int colNum, bool hasPkt )
    : Vehicle( x, y, rowMax, colNum, hasPkt )
{
  calculateDestination();
  calcNextLocation();
}

/**
 * @brief Calculates Taxi's destination
 *
 * @details Randomly assigns destination within given row and column
 *          boundaries using rand() generator
 *
 * @pre number of columns > 0
 *      number of rows > 0
 *
 * @post New destination != old location
 *
 * @par Algorithm
 *      Generate random xy coordinates until coordinates != old destination
 *
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note Recommend setting current location coordinates = old destination
 *       before call
 */
void Taxi::calculateDestination()
{
  int xNewDest, yNewDest;

  do
  {
    xNewDest = rand() % ( colMax - 1 );
    yNewDest = rand() % ( rowMax - 1 );
  } while( xNewDest == xDest && yNewDest == yDest );

  xDest = xNewDest;
  yDest = yNewDest;
}

// Terminating precompiler directives  ////////////////////////////////////////

#endif  // #ifndef CLASS_VEHICLE_CPP
