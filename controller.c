//
// Controller
//
// Very basic wrapper around the gyro code to abstrract the game model better from the HW
// A better implementation of the button controls we ended up using could in theory live
// in this class for a cleaner abstraction
//

#include "MPU6050.h"
#include "xil_printf.h"

MPU6050_t myController;

//#define I2C_WORKS

//Bellow calibration was never able to be done
#define MPU6050_ROTATION_TO_DEGREES 1

int controller_get_pitch()
{
#ifdef I2C_WORKS
    return (int)(MPU6050_getRotationX(myController) / MPU6050_ROTATION_TO_DEGREES);
#else
    return 0;
#endif
}

int controller_get_roll()
{
#ifdef I2C_WORKS
    return (int)(MPU6050_getRotationY(myController) / MPU6050_ROTATION_TO_DEGREES);
#else
    return 0;
#endif
}

void controller_init()
{
    MPU6050_initialize(&myController);
    if( ! MPU6050_testConnection(&myController) )
    {
        printf("ERROR INITIALIZING CONTROLLER\n");
    }
}
