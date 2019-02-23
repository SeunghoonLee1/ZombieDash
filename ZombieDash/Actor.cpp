#include "Actor.h"
#include "StudentWorld.h"
#include "GraphObject.h"
#include <iostream>
#include "GameWorld.h"
#include "GameConstants.h"
using namespace std;

class StudentWorld;
// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp

void Penelope::doSomething(){
    if(getIsAlive() == false){//check to see if she is still alive
        return;
    }
    
    if(getIsInfected()){
        setInfectionCount(getInfectionCount() + 1);
        if(getInfectionCount() == 500){
            setIsAlive(false);
            return;
            //            getWorld()->playSound(SOUND_PLAYER_DIE);
        }
    }
    int ch;
    if(getWorld()->getKey(ch)){
        //user hit a key during this tick!
        switch(ch){
            case KEY_PRESS_LEFT:
                Actor::setDirection(left);
                //move 4 pixels left only when it doesn't overlap(intersect) with wall
                if(!(getWorld()->doesIntersect(this, getX() - 4, getY())) ){
                    moveTo(getX() - 4, getY());
                }
                break;
            case KEY_PRESS_RIGHT:
                setDirection(right);
                if(!(getWorld()->doesIntersect(this, getX() + 4, getY()))){
                    moveTo(getX() + 4, getY());
                }
                break;
            case KEY_PRESS_UP:
                setDirection(up);
                if(!(getWorld()->doesIntersect(this, getX(), getY() + 4))){
                    moveTo(getX(), getY() + 4);
                }
                break;
            case KEY_PRESS_DOWN:
                setDirection(down);
                if(!(getWorld()->doesIntersect(this, getX(), getY() - 4))){
                    moveTo(getX(), getY() - 4);
                }
                break;
            case KEY_PRESS_ENTER:
                if(getNumVaccines() >= 1){
                    setIsInfected(false);
                    changeNumVaccines(-1);
                    setInfectionCount(0);
                }
                break;
            case KEY_PRESS_SPACE:
                if(getNumFlames() > 0){
                    changeNumFlames(-1);
                    getWorld()->playSound(SOUND_PLAYER_FIRE);
                    getWorld()->blastFlame();
                }
                break;
        }
    }
}

void Exit::doSomething(){
    getWorld()->escapeHumans(getX(), getY());
    
}

void VaccineGoodie::doSomething(){
    if(getIsAlive() == false){
        return;
    }
    if(getWorld()->doesOverlapWithPlayer(this)){
        getWorld()->increaseScore(50);
        setIsAlive(false);
        getWorld()->playSound(SOUND_GOT_GOODIE);
        //Inform the StudentWorld Object that Penelope is to receive one dose of vaccine.
        getWorld()->setGotVaccine(true);
    }
}

void GasCanGoodie::doSomething(){
    if(getIsAlive() == false){
        return;
    }
    if(getWorld()->doesOverlapWithPlayer(this)){
        getWorld()->increaseScore(50);
        setIsAlive(false);
        getWorld()->playSound(SOUND_GOT_GOODIE);
        //Inform the StudentWorld Object that Penelope is to receive 5 flames.
        getWorld()->setGotFlames(true);
    }
}

void Flame::doSomething(){
    if(getIsAlive() == false){
        return;
    }
    cout << "tick : " << getTicksPassed() << endl;
    if(getTicksPassed() == 2){
        setIsAlive(false);
        return;
    }
//    if(getDirection() == up){
//        for(int i = 0; i < 3; i++){
//            
//        }
//    }

    
    
    setTicksPassed(getTicksPassed() + 1);

    
}

