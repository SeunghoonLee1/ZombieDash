#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class Actor;
class Penelope;

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetPath);
    virtual ~StudentWorld(){
        cleanUp();
    }
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    bool doesIntersect(Actor* sameActor, double x, double y);
    bool doesOverlap(Actor* sameActor, double x, double y);
    void escapeHumans(double exitX, double exitY);
    bool doesOverlapWithPlayer(Actor* goodie, double x, double y);

    bool getFinishedLevel(){
        return m_finishedLevel;
    }
    void setFinishedLevel(bool status){
        m_finishedLevel = status;
    }

private:
    vector<Actor*> actorList;
    Penelope* playerPtr;
    bool m_finishedLevel;
};

#endif // STUDENTWORLD_H_
