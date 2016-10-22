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
 * @version 1.00
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
  ~Vehicle();
  
  // Accessors
  virtual char getId() { return 'V'; }
  void getLocation( int& x, int& y ) { x = xPos; y = yPos; }
  void getDestination( int& x, int& y ) { x = xDest; y = yDest; }
  VehicleDir getDirection() { return vehicleDir; }
  bool hasPacket() { return hasPkt; }
  void getNextLocation( int& x, int& y );
  
  // Modifiers
  void move();
  void setPacket( bool holdsPacket ) { hasPkt = holdsPacket; }

 protected:
  int xPos, yPos;
  int xDest, yDest;
  int xNextPos, yNextPos;
  VehicleDir vehicleDir;
  int rowNum, columnNum;
  bool hasPkt;
  
  void calculateNextLocation();
  virtual void setDestination() = 0;
};

class Taxi: public Vehicle
{
 public:
  // Constructors
  Taxi( int x, int y, int rowMax, int colMax, bool hasPkt = false );
  ~Taxi();
  
  // Accessors
  char getId() { return 'T'; }
  
  // Modifiers
  void setDestination();
};



// Terminating precompiler directives  ////////////////////////////////////////

#endif  // #ifndef CLASS_VEHICLE_H
