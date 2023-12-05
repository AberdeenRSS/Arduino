#include "container.h"

#include "Parts/AParts/interface.h"

Container::Container() {
    for (int i = 0; i < Parts + Sensors; ++i)
        array[i] = nullptr;
}

void Container::registerPart(Interface *part) {
    for (int i = 0; i < Parts; ++i) {
        if (!array[i])  {
            array[i] = part;
            return;
        }
    }
}

void Container::registerSensor(Interface *sensor) {
    for (int i = Parts; i < Parts + Sensors; ++i) {
        if (!array[i]) {
            array[i] = sensor;
            return;
        }
    }
}

Interface *Container::find(char partID) const {
    for (int i = 0; i < Parts + Sensors; ++i)
        if (array[i]->getCode() == partID)
            return array[i];

    return nullptr;
}

void Container::read_data() {
    for (int i = Parts; i < Parts + Sensors; ++i)
        if (array[i])
            array[i]->fun(0x00);
}