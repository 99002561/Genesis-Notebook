#include "iobject.h"

IObject::IObject():
o_x(0),
o_y(0)
{}

IObject::IObject(int x,int y):
o_x(x),
o_y(y)
{}

int IObject::getX(){
return o_x;
}

int IObject::getY(){
return o_y;
}

