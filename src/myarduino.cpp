#include "myarduino.h"

#include "Parts/reset.h"
#include "Parts/myservo.h"
#include "Parts/igniter.h"

MyServo myServo;
Reset reset;
Igniter igniter;

MyArduino::MyArduino() {
    arr[0] = &reset;
    arr[1] = &myServo;
    arr[2] = &igniter;
}

void MyArduino::init() {
    for(int i = 0; i < size; ++i) 
        arr[i]->init();
}

int MyArduino::action(int part, char command) {
    return arr[part]->action(command);
}

void MyArduino::update() {
    for (int i = 0; i < size; ++i) {
        arr[i]->update();
    }
}