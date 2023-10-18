#include "myarduino.h"
#include <Arduino.h>
#include "Parts/AParts/interface.h"
#include "errors.h"

void MyArduino::reg(Interface* sensor, bool updates) {
    bt.insert(sensor->getCode(), sensor);

    if(sensor->moreUpdate())
        addUpdateComponent(sensor->getUpdatesSpeed() + millis(), sensor);
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

void MyArduino::show() {
    bt.show();
}

char MyArduino::find(unsigned char part, char code) {
    Interface* ptr = bt.find(part);
    
    if(!ptr)
        return Errors::WrongPartByte;

    return ptr->fun(code);
}

void MyArduino::read_data() {
    bt.in_order();
}

void MyArduino::addUpdateComponent(unsigned long nextUpdate, Interface* component) {
    heap.insert(nextUpdate, component);
}

