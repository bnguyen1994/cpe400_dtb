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
 * @version 1.0
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

Vehicle::Vehicle( int x, int y, int rowNum, int colNum, bool hasPkt )
    : xPos(x), yPos(y), rowNum(rowNum), columnNum(colNum), hasPkt(hasPkt)
{
  xDest = xPos;
  yDest = yPos;
  
  xNextPos = xPos;
  yNextPos = yPos;
  
  vehicleDir = NaN;
}

Vehicle::~Vehicle() {}

void Vehicle::move()
{
  xPos = xNextPos;
  yPos = yNextPos;
  
  // If destination reached, set new destination
  if( xPos == xDest && yPos == yDest ) setDestination();
  
  // Recalculate next location
  calculateNextLocation();
}

void Vehicle::getNextLocation( int& x, int& y )
{
  x = xNextPos;
  y = yNextPos;
}

void Vehicle::calculateNextLocation()
{
  // Get front facing locations
  switch( vehicleDir )
  {
    case NaN:
      if( xPos != xDest )
      {
        if( xPos < xDest )
        {
          vehicleDir = RIGHT;
          ++xNextPos;
        }
        else
        {
          vehicleDir = LEFT;
          --xNextPos;
        }
      }
      else if( yPos != yDest )
      {
        if( yPos < yDest )
        {
          vehicleDir = DOWN;
          ++yNextPos;
        }
        else
        {
          vehicleDir = UP;
          --yNextPos;
        }
      }
      else  /* xPos == xDest && yPos == yDest */
      {
        vehicleDir = NaN;
      }
      break;
      
    case UP:
      if( xPos != xDest )
      {
        if( xPos < xDest )
        {
          vehicleDir = RIGHT;
          ++xNextPos;
        }
        else
        {
          vehicleDir = LEFT;
          --xNextPos;
        }
      }
      else if( yPos != yDest )
      {
        if( yPos < yDest )
        {
          vehicleDir = DOWN;
          ++yNextPos;
        }
        else
        {
          // Want to go down, but can't make U-turn
          if( xPos < xDest && ( xPos + 1 ) < columnNum )
          {
            vehicleDir = RIGHT;
            ++xNextPos;
          }
          else if( xPos >= xDest && ( xPos - 1 ) >= 0 )
          {
            vehicleDir = LEFT;
            --xNextPos;
          }
          else  /* ( yPos + 1 ) > rowNum && ( yPos - 1 ) < 0 */
          {
            // Stop
            vehicleDir = NaN;
          }
        }
      }
      else  /* xPos == xDest && yPos == yDest */
      {
        vehicleDir = NaN;
      }
      break;
    
    case DOWN:
      if( xPos != xDest )
      {
        if( xPos < xDest )
        {
          vehicleDir = RIGHT;
          ++xNextPos;
        }
        else
        {
          vehicleDir = LEFT;
          --xNextPos;
        }
      }
      else if( yPos != yDest )
      {
        if( yPos < yDest )
        {
          vehicleDir = DOWN;
          ++yNextPos;
        }
        else
        {
          // Want to go up, but can't make U-turn
          if( xPos < xDest && ( xPos + 1 ) < columnNum )
          {
            vehicleDir = RIGHT;
            ++xNextPos;
          }
          else if( xPos >= xDest && ( xPos - 1 ) >= 0 )
          {
            vehicleDir = LEFT;
            --xNextPos;
          }
          else  /* ( yPos + 1 ) > rowNum && ( yPos - 1 ) < 0 */
          {
            // Stop
            vehicleDir = NaN;
          }
        }
      }
      else  /* xPos == xDest && yPos == yDest */
      {
        vehicleDir = NaN;
      }
      break;
      
    case LEFT:
      if( xPos != xDest )
      {
        if( xPos < xDest )
        {
          // Want to go right, but can't make U-turn
          if( yPos < yDest && ( yPos + 1 ) < rowNum )
          {
            vehicleDir = DOWN;
            ++yNextPos;
          }
          else if( yPos >= yDest && ( yPos - 1 ) >= 0 )
          {
            vehicleDir = UP;
            --yNextPos;
          }
          else  /* ( yPos + 1 ) > rowNum && ( yPos - 1 ) < 0 */
          {
            // Stop
            vehicleDir = NaN;
          }
        }
        else
        {
          vehicleDir = LEFT;
          --xNextPos;
        }
      }
      else if( yPos != yDest )
      {
        if( yPos < yDest )
        {
          vehicleDir = DOWN;
          ++yNextPos;
        }
        else
        {
          vehicleDir = UP;
          --xNextPos;
        }
      }
      else  /* xPos == xDest && yPos == yDest */
      {
        vehicleDir = NaN;
      }
      break;
      
    case RIGHT:
      if( xPos != xDest )
      {
        if( xPos < xDest )
        {
          vehicleDir = RIGHT;
          ++xNextPos;
        }
        else
        {
          // Want to go left, but can't make U-turn
          if( yPos < yDest && ( yPos + 1 ) < rowNum )
          {
            vehicleDir = UP;
            ++yNextPos;
          }
          else if( yPos >= yDest && ( yPos - 1 ) >= 0 )
          {
            vehicleDir = DOWN;
            ++yNextPos;
          }
          else  /* ( yPos + 1 ) > rowNum && ( yPos - 1 ) < 0 */
          {
            // Stop
            vehicleDir = NaN;
          }
        }
      }
      else if( yPos != yDest )
      {
        if( yPos < yDest )
        {
          vehicleDir = DOWN;
          ++yNextPos;
        }
        else
        {
          vehicleDir = UP;
          --xNextPos;
        }
      }
      else  /* xPos == xDest && yPos == yDest */
      {
        vehicleDir = NaN;
      }
      break;
  }
}

Taxi::Taxi( int x, int y, int rowNum, int colNum, bool hasPkt )
    : Vehicle( x, y, rowNum, colNum, hasPkt )
{
  setDestination();
}

void Taxi::setDestination()
{
  int xNewDest, yNewDest;
  
  srand( time( NULL ) );
  
  do
  {
    xNewDest = rand() % ( columnNum - 1);
    yNewDest = rand() % ( rowNum - 1);
  }
  while( !( yNewDest == yDest && xNewDest == xDest ) ); 
}

// Terminating precompiler directives  ////////////////////////////////////////

#endif  // #ifndef CLASS_VEHICLE_CPP
