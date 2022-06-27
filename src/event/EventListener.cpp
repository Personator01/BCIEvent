#include "EventListener.hpp"

using namespace BCIEvent;


EventListener::EventListener(std::shared_ptr<Event> listeningEvent){
    _listeningEvent = listeningEvent;
    _listeningEvent->addListener(this);
}

EventListener::~EventListener(){
    delete _next;
}