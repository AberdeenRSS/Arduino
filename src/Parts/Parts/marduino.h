#include "Parts/AParts/apart.h"



class MArduno : public APart<MArduno> {
    enum States {};
public :
    MArduno();

    void update();


private:
    void(* resetFunc) (void) = 0;

    char resetArduino();
    char startPreparationPhase();
    char startIgnitionPhase();
    char startLiftoffPhase();
    char startRecoveryPhase();
};