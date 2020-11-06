#include "wobject.h"

WObject::WObject():
IObject(),
o_weight(0)
{}

WObject::WObject(int x,int y,int weight):
IObject(x,y),
o_weight(weight)
{}

int WObject::distanceFromOrigin(){
    return sqrt(pow(o_x,2) + pow(o_y,2));
}

quadrant WObject::getQuadrant(){
    
    if(o_x > 0 && o_y >0){
        return Q1;
    }
    else if(o_x < 0 && o_y >0){
        return Q2;
    }
    else if(o_x < 0 && o_y <0){
        return Q3;
    }
    else {
        return Q4;
    }

}

int WObject::weight(){
    return o_weight;
}