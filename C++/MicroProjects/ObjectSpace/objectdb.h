#ifndef _object_db
#define _object_db

#include "wobject.h"
#include "list"

using std::list;

class ObjectDb{
    list<WObject> l_objects;

  public:

  void addObject(int,int,int); //x,y,weight
  void removeObject(int,int); //x,y

  int countAll();
  int findMinWeight();
  int findMaxDistanceFromOrigin();
  int countObjectsByQuadrant(quadrant);
  int countObjectsOnCircleBoundary(int);  //radius
};


#endif