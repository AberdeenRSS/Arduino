#include "myarduino.h"
#include <Arduino.h>
#include "Parts/AParts/interface.h"
#include "errors.h"

void MyArduino::registerPart(Interface* part) {
    array.registerPart(part);

    if(part->moreUpdate())
        addUpdateComponent(part->getUpdatesSpeed() + millis(), part);
}

void MyArduino::registerSensor(Interface* sensor){
    array.registerSensor(sensor);
}

void MyArduino::update() {
    if(!heap.empty()) {
        if(heap.top().getTime() <= millis()) {
            Interface* obj = heap.top().get_val();
            heap.pop();

            if(obj->moreUpdate())  {
                obj->update();

                if(obj->moreUpdate()) 
                    addUpdateComponent(obj->getUpdatesSpeed() + millis(), obj);
            }
        }
    }
}


char MyArduino::find(unsigned char part, char code) {
    Interface* ptr = array.find(part);

    if(!ptr)
        return Errors::WrongPartByte;

    return ptr->fun(code);
}

void MyArduino::read_data() {
    array.read_data();
}

void MyArduino::addUpdateComponent(unsigned long nextUpdate, Interface* component) {
    heap.insert(nextUpdate, component);
}

