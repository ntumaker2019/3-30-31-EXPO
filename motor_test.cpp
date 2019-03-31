#include "sMotor.h"
void motor_move()
{
    Motor motor1(PA_15, PA_8, PB_15, PB_14);
    sMotor motor2(PF_6, PF_7, PF_8, PF_9);
    motor1.step(128, 0, 4800);
    motor2.step(128, 1, 600);
}