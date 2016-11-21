// Program Information ////////////////////////////////////////////////////////
/**
 * @file vehicle.h
 *
 * @brief Definition file for vehicle classes
 *
 * @author Brandon Thai Nguyen
 *
 * @details Specifies all member methods of the vehicle classes
 *
 * @version 2.00
 *          Tyler Michael Goffinet (24 October 2016)
 *          Added getId(), getLocation(), getDirection(), hasPacket(),
 *          getNextLocation(), move(), setPacket(), protected functions, and
 *          member variables
 *
 *          1.00
 *          Brandon Thai Nguyen (03 October 2016)
 *          Original Code
 *
 * @note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_VEHICLE_H
#define CLASS_VEHICLE_H

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>

// Class definition  //////////////////////////////////////////////////////////

enum VehicleDir
{
  NaN,
  UP,
  DOWN,
  LEFT,
  RIGHT
};

class Vehicle
{
 public:
  // Constructors
  Vehicle( int x, int y, int rowNum, int colNum, bool hasPkt = false );
  ~Vehicle() {}

  // Accessors
  virtual char getId() { return 'V'; }
  void getLocation( int& x, int& y )
  {
    x = xPos;
    y = yPos;
  }
  void getNextLocation( int& x, int& y )
  {
    x = xNextPos;
    y = yNextPos;
  }
  void getDestination( int& x, int& y )
  {
    x = xDest;
    y = yDest;
  }
  VehicleDir getDirection() { return vehicleDir; }
  bool       hasPacket() { return hasPkt; }

  // Modifiers
  void move();
  void redirect();
  void setPacket( bool holdsPacket ) { hasPkt = holdsPacket; }

 protected:
  // Member variables
  int  xPos, yPos;
  int  xDest, yDest;
  int  xNextPos, yNextPos;
  bool hasPkt;

  unsigned int redirectCounter;
  VehicleDir   vehicleDir;

  int rowMax, colMax;

  // Member functions
  void calcNextLocation();
  bool calcAltDirection();

  void stop();
  bool planUp();
  bool planDown();
  bool planLeft();
  bool planRight();

  // Pure virtual fuctions
  virtual void calculateDestination() = 0;
};

class Taxi : public Vehicle
{
 public:
  // Constructors
  Taxi( int x, int y, int rowMax, int colMax, bool hasPkt = false );

  // Accessors
  char getId() { return 'T'; }

  // Modifiers
  void calculateDestination();
};

// Terminating precompiler directives  ////////////////////////////////////////

#endif  // #ifndef CLASS_VEHICLE_H
