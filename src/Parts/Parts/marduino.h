#include "Parts/AParts/apart.h"


class  MArduno : public APart<MArduno, 5> {
    enum States {};
public :
    MArduno();
    void update();

private:
    void(* resetFunc) (void) = 0;


    static const int timeout = 10000;
    unsigned long lastKeepAliveMillis = 0;
    bool timeoutTriggered = false;

    char resetArduino();
    char keepAlive();

    void onTimeout();
};