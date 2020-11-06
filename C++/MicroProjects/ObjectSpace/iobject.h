#ifndef _iobject_h
#define _iobject_h

#include "math.h"

enum quadrant {Q1,Q2,Q3,Q4};

class IObject
{
protected:
int o_x;
int o_y;

public:
    IObject();
    //x,y
    IObject(int,int);

    int getX();
    int getY();

    virtual int distanceFromOrigin()=0;
    virtual quadrant getQuadrant()=0;

};





#endif