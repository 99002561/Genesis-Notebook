#ifndef _wobject_h
#define _wobject_h

#include "iobject.h"

class WObject:public IObject{

    int o_weight;

    public:

    WObject();
    //x,y,weight
    WObject(int,int,int);


    int distanceFromOrigin();
    quadrant getQuadrant();

    int weight();


};




#endif