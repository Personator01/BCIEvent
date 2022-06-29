#include "Actor.hpp"
#include "Event.hpp"
#include "GlobalVariables.hpp"
#include "GraphDisplay.h"
#include "GraphObject.h"
#include "Variable.hpp"
#include "NumberVariable.hpp"
#include <stdexcept>
#include <type_traits>

using namespace BCIEvent;

    void Actor::update(){

	//Run and update blocks
	
	std::vector<Block*> toRemove;
	toRemove.reserve(_currentBlocks.size());
	for(auto i = _currentBlocks.begin(); i != _currentBlocks.end(); i++){
	    Block* currentBlock = *i;
	    Block* nextBlock = currentBlock->run(*this); //runs the block and gets a reference to the next block
	    if (nextBlock == nullptr){ //remove end blocks
		toRemove.push_back(currentBlock);
	    } else {
		_currentBlocks.erase(i);
		_currentBlocks.insert(i, nextBlock);
	    }
	}
	for (int i = 0; i < toRemove.size(); i++){ //remove end blocks
		    _currentBlocks.remove(toRemove[i]);
	}

	//Handle events
	
	for (auto &&listener : _eventListeners){
	    if (listener->isTriggered()){
		_currentBlocks.push_back(listener->getNext());
	    }
	}

    }

Actor::Actor(std::shared_ptr<GlobalVariables> globalVars, std::shared_ptr<States> states, GUI::GraphDisplay& display) : GUI::GraphObject(display, 0){
    _globalVars = globalVars;
    _states = states;
    SetAlignment(GUI::Alignment::Center);
    SetScalingMode(GUI::ScalingMode::AdjustBoth);

}

Actor::~Actor(){
    DestructorEntered();
}

template<typename ReqType>
ReqType Actor::getVariable(std::string name) const{
    static_assert(std::is_convertible<ReqType, bool>::value || std::is_floating_point<ReqType>::value || std::is_integral<ReqType>::value,
	    "Template argument for getVariable must be boolean, integral, or floating point");
    try {
        if(std::is_same<ReqType, bool>::value){
	    return _variables.at(name)->getAsBool();
	}
	else if (std::is_integral<ReqType>::value){
	    return static_cast<ReqType>(_variables.at(name)->getAsInt());
	}
	else{
	    return static_cast<ReqType>(_variables.at(name)->getAsDouble());
	}
    } catch (std::out_of_range e) {
	return _globalVars->getVariable<ReqType>(name);
    }
}
template <typename SetType>
void Actor::setVariable(std::string name, SetType value){
    static_assert(std::is_same<SetType, bool>::value || std::is_same<SetType, Variable>::value || std::is_floating_point<SetType>::value || std::is_integral<SetType>::value,
	    "Template argument for setVariable must be Variable, boolean, integral, or floating point");
    try {
	_variables.at(name) = value;
    } catch (std::out_of_range e) {
	_globalVars->setVariable(name, value);
    }
}

template <typename T> requires std::integral<T> || std::floating_point<T> || std::same_as<T, bool>
void Actor::setState(std::string name, T value){
    _states->getState(name).set(value);
}


template <typename T> requires std::integral<T> || std::same_as<T, bool>
T Actor::getState(std::string name) const{
    return static_cast<T>(_states->at(name).get());
}
