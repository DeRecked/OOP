#include <cassert>
#include <iostream>
#include "unit.hpp"
#include "map.hpp"


/*****************************************/
/*  Unit class function implementations  */
/*****************************************/

bool Unit::random() {

}

bool Unit::sentry() {

}

bool Unit::fill() {

}

bool Unit::land() {

}

bool Unit::explore() {

}

bool Unit::army_load() {
    
}

bool Unit::army_attack() {

}

bool Unit::repair() {

}

bool Unit::wf_transport() {

}

bool Unit::move(const Direction d) {

}

int Unit::parse_action(const Command c) {
    // Parse command
    switch(c) {
        case NONE: break;
        case RANDOM: this->random();
            break;
        case SENTRY: this->sentry();
            break;
        case FILL: this->fill();
            break;        
        case LAND: this->land();
            break;        
        case EXPLORE: this->explore();
            break;       
        case ARMYLOAD: this->army_load();
            break;        
        case ARMYATTACK: this->army_attack();
            break;        
        case REPAIR: this->repair();
            break;        
        case WFTRANSPORT: this->wf_transport();
            break;        
        case MOVE_N: this->move(NORTH);
            break;        
        case MOVE_NE: this->move(NORTHEAST);
            break;        
        case MOVE_E: this->move(EAST);
            break;        
        case MOVE_SE: this->move(SOUTHEAST);
            break;        
        case MOVE_S: this->move(SOUTH);
            break;        
        case MOVE_SW: this->move(SOUTHWEST);
            break;               
        case MOVE_W: this->move(WEST);
            break;                
        case MOVE_NW: this->move(NORTHWEST);
            break;             
        default: break;
    };
}

/*********************************************/
/*  Derived struct function implementations  */
/*********************************************/

void Army::action(const Command c) { 
    assert(c != LAND and c != REPAIR);
    parse_action(c); 
}

void Fighter::action(const Command c) { 
    assert(c != FILL and c != ARMYLOAD and c != ARMYATTACK and c != WFTRANSPORT);    
    parse_action(c);
}

void Patrol::action(const Command c) { 
    assert(c != FILL and c != LAND and c != ARMYLOAD and c != ARMYATTACK and c != WFTRANSPORT);
    parse_action(c); 
}

void Destroyer::action(const Command c) { 
    assert(c != FILL and c != LAND and c != ARMYLOAD and c != ARMYATTACK and c != WFTRANSPORT);
    parse_action(c); 
}

void Submarine::action(const Command c) {
    assert(c != FILL and c != LAND and c != ARMYLOAD and c != ARMYATTACK and c != WFTRANSPORT); 
    parse_action(c); 
}

void Transport::action(const Command c) {
    assert(c != LAND and c != ARMYLOAD and c != ARMYATTACK and c != WFTRANSPORT); 
    parse_action(c); 
}

void Carrier::action(const Command c) {
    assert(c != FILL and c != LAND and c != ARMYLOAD and c != ARMYATTACK and c != WFTRANSPORT); 
    parse_action(c); 
}

void Battleship::action(const Command c) {
    assert(c != FILL and c != LAND and c != ARMYLOAD and c != ARMYATTACK and c != WFTRANSPORT); 
    parse_action(c); 
}

void Satellite::action(const Command c) {
    assert(c != FILL and c != LAND and c != ARMYLOAD and c != ARMYATTACK and c != REPAIR and c != WFTRANSPORT); 
    parse_action(c); 
}