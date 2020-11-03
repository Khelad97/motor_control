/*
 * File:   application.c
 * Author: Khelad Mohamed
 *
 * Created on October 22, 2020, 8:09 PM
 */

#include "application.h"



motor_t robot_motor[4] = {
    {.relay_1.port_name = PORTC_INDEX, .relay_1.pin = PIN0, .relay_1.relay_stutus = MOTOR_OFF,
     .relay_2.port_name = PORTC_INDEX, .relay_2.pin = PIN1, .relay_2.relay_stutus = MOTOR_OFF},
    {.relay_1.port_name = PORTC_INDEX, .relay_1.pin = PIN2, .relay_1.relay_stutus = MOTOR_OFF,
     .relay_2.port_name = PORTC_INDEX, .relay_2.pin = PIN3, .relay_2.relay_stutus = MOTOR_OFF},
    {.relay_1.port_name = PORTC_INDEX, .relay_1.pin = PIN4, .relay_1.relay_stutus = MOTOR_OFF,
     .relay_2.port_name = PORTC_INDEX, .relay_2.pin = PIN5, .relay_2.relay_stutus = MOTOR_OFF},
    {.relay_1.port_name = PORTC_INDEX, .relay_1.pin = PIN6, .relay_1.relay_stutus = MOTOR_OFF,
     .relay_2.port_name = PORTC_INDEX, .relay_2.pin = PIN7, .relay_2.relay_stutus = MOTOR_OFF}
};
button_t move_btn[4] = {
    {.port_name = PORTD_INDEX, .pin = PIN0, .button_status = BUTTON_NOT_PRESSED},
    {.port_name = PORTD_INDEX, .pin = PIN1, .button_status = BUTTON_NOT_PRESSED},
    {.port_name = PORTD_INDEX, .pin = PIN2, .button_status = BUTTON_NOT_PRESSED},
    {.port_name = PORTD_INDEX, .pin = PIN3, .button_status = BUTTON_NOT_PRESSED}
};
void move_forward(void);
void move_backward(void);
void move_right(void);
void move_left(void);
void stop(void);
void robot_initalize(void);
uint8_t up = ZERO_INIT, back = ZERO_INIT, right = ZERO_INIT, left = ZERO_INIT;

int main() {
    robot_initalize();

    while (TRUE) {
        button_get_status(&move_btn[0], &up);
        button_get_status(&move_btn[1], &back);
        button_get_status(&move_btn[2], &right);
        button_get_status(&move_btn[3], &left);

        if (up == BUTTON_PRESSED) {
            move_forward();
        } else {
            stop();
        }

        if (back == BUTTON_PRESSED) {
            move_backward();
        } else {
            stop();
        }
        if (right == BUTTON_PRESSED) {
            move_right();
        } else {
            stop();
        }
        if (left == BUTTON_PRESSED) {
            move_left();
        } else {
            stop();
        }
    }
}

void robot_initalize(void) {
    motot_initialize(&robot_motor[0]);
    motot_initialize(&robot_motor[1]);
    motot_initialize(&robot_motor[2]);
    motot_initialize(&robot_motor[3]);
    button_initialize(&move_btn[0]);
    button_initialize(&move_btn[1]);
    button_initialize(&move_btn[2]);
    button_initialize(&move_btn[3]);

}

void move_forward(void) {
    motor_rotate_right(&robot_motor[0]);
    motor_rotate_right(&robot_motor[1]);
    motor_rotate_right(&robot_motor[2]);
    motor_rotate_right(&robot_motor[3]);

}

void move_backward(void) {
    motor_rotate_left(&robot_motor[0]);
    motor_rotate_left(&robot_motor[1]);
    motor_rotate_left(&robot_motor[2]);
    motor_rotate_left(&robot_motor[3]);

}

void move_right(void) {
    motor_rotate_right(&robot_motor[0]);
    motor_rotate_left(&robot_motor[1]);
    motor_rotate_right(&robot_motor[2]);
    motor_rotate_left(&robot_motor[3]);

}

void move_left(void) {
    motor_rotate_left(&robot_motor[0]);
    motor_rotate_right(&robot_motor[1]);
    motor_rotate_left(&robot_motor[2]);
    motor_rotate_right(&robot_motor[3]);

}

void stop(void) {
    motor_stop(&robot_motor[0]);
    motor_stop(&robot_motor[1]);
    motor_stop(&robot_motor[2]);
    motor_stop(&robot_motor[3]);

}