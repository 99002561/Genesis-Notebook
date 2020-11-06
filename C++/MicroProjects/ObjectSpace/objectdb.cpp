#include "objectdb.h"

void ObjectDb::addObject(int x,int y,int weight){
    l_objects.push_back(WObject(x,y,weight));
}

void ObjectDb::removeObject(int x,int y){
    list<WObject>::iterator iter;
    for(iter=l_objects.begin();iter!=l_objects.end();++iter){
        if(x == iter->getX() && y == iter->getY()){
            l_objects.erase(iter);
            return;
        }
    }
    return;
} //x,y

int ObjectDb::countAll(){
    return l_objects.size();
}

int ObjectDb::findMinWeight(){
    list<WObject>::iterator iter = l_objects.begin();
    int minWeight = iter->weight();

    for(iter=l_objects.begin();iter!=l_objects.end();++iter){
        if(iter->weight() < minWeight){
            minWeight = iter->weight();
        }
    }
    return minWeight;
}


int ObjectDb::findMaxDistanceFromOrigin(){
    list<WObject>::iterator iter = l_objects.begin();
    int maxDistance = iter->distanceFromOrigin();

    for(iter=l_objects.begin();iter!=l_objects.end();++iter){
        if(iter->distanceFromOrigin() > maxDistance){
            maxDistance = iter->distanceFromOrigin();
        }
    }
    return maxDistance;
}

int ObjectDb::countObjectsByQuadrant(quadrant qp){
    list<WObject>::iterator iter;
    int objCnt=0;

    for(iter=l_objects.begin();iter!=l_objects.end();++iter){
        if(iter->getQuadrant() == qp){
            objCnt++;
        }
    }
return objCnt;
}

int ObjectDb::countObjectsOnCircleBoundary(int radius){
    list<WObject>::iterator iter;
    int objCnt=0;

    for(iter=l_objects.begin();iter!=l_objects.end();++iter){
        if(iter->distanceFromOrigin() == radius){
            objCnt++;
        }
    }
return objCnt;
}