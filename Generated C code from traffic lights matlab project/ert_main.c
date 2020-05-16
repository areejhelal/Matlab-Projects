/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'traffic'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Thu Jan 30 12:54:03 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "traffic.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  traffic_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
}

int main(void)
{
  volatile boolean_T runModel = 1;
  float modelBaseRate = 0.1;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(traffic_M, 0);
  traffic_initialize();
  configureArduinoAVRTimer();
  runModel =
    rtmGetErrorStatus(traffic_M) == (NULL);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei ();
  while (runModel) {
    runModel =
      rtmGetErrorStatus(traffic_M) == (NULL);
    runModel = runModel && MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  traffic_terminate();
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
