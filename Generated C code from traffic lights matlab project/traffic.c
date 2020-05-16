/*
 * File: traffic.c
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
#include "traffic_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define traffic_IN_Green               ((uint8_T)1U)
#define traffic_IN_Init                ((uint8_T)1U)
#define traffic_IN_NO_ACTIVE_CHILD     ((uint8_T)0U)
#define traffic_IN_Red                 ((uint8_T)2U)
#define traffic_IN_Traffic             ((uint8_T)2U)
#define traffic_IN_Yellow              ((uint8_T)3U)
#define traffic_IN_init                ((uint8_T)1U)
#define traffic_IN_init_blink          ((uint8_T)2U)
#define traffic_IN_transition          ((uint8_T)3U)

/* Block signals (auto storage) */
B_traffic_T traffic_B;

/* Block states (auto storage) */
DW_traffic_T traffic_DW;

/* Real-time model */
RT_MODEL_traffic_T traffic_M_;
RT_MODEL_traffic_T *const traffic_M = &traffic_M_;

/* Model step function */
void traffic_step(void)
{
  uint8_T tmp;

  /* Chart: '<Root>/Chart' */
  if (traffic_DW.temporalCounter_i1 < 63U) {
    traffic_DW.temporalCounter_i1++;
  }

  if (traffic_DW.temporalCounter_i2 < 63U) {
    traffic_DW.temporalCounter_i2++;
  }

  /* Gateway: Chart */
  /* During: Chart */
  if (traffic_DW.is_active_c3_traffic == 0U) {
    /* Entry: Chart */
    traffic_DW.is_active_c3_traffic = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:2' */
    traffic_DW.is_c3_traffic = traffic_IN_Init;
    traffic_DW.temporalCounter_i1 = 0U;

    /* Entry Internal 'Init': '<S1>:1' */
    /* Transition: '<S1>:6' */
    traffic_DW.is_Init = traffic_IN_init;

    /* Entry 'init': '<S1>:5' */
    /* '<S1>:5:1' ctr =0; */
    traffic_DW.ctr = 0.0;
  } else if (traffic_DW.is_c3_traffic == traffic_IN_Init) {
    /* During 'Init': '<S1>:1' */
    /* '<S1>:4:1' sf_internal_predicateOutput = ... */
    /* '<S1>:4:1' after(5,sec)&&ctr==3; */
    if ((traffic_DW.temporalCounter_i1 >= 50U) && (traffic_DW.ctr == 3.0)) {
      /* Transition: '<S1>:4' */
      /* Exit Internal 'Init': '<S1>:1' */
      traffic_DW.is_Init = traffic_IN_NO_ACTIVE_CHILD;
      traffic_DW.is_c3_traffic = traffic_IN_Traffic;

      /* Entry Internal 'Traffic': '<S1>:3' */
      /* Transition: '<S1>:13' */
      traffic_DW.is_Traffic = traffic_IN_Red;
      traffic_DW.temporalCounter_i1 = 0U;

      /* Entry 'Red': '<S1>:12' */
      /* '<S1>:12:1' red =1; */
      traffic_B.red = 1.0;
    } else {
      switch (traffic_DW.is_Init) {
       case traffic_IN_init:
        /* During 'init': '<S1>:5' */
        /* Transition: '<S1>:9' */
        traffic_DW.is_Init = traffic_IN_init_blink;
        traffic_DW.temporalCounter_i2 = 0U;

        /* Entry 'init_blink': '<S1>:7' */
        /* '<S1>:7:1' red=1; */
        traffic_B.red = 1.0;

        /* '<S1>:7:1' yellow =1; */
        traffic_B.yellow = 1.0;

        /* '<S1>:7:1' green =1; */
        traffic_B.green = 1.0;

        /* '<S1>:7:2' ctr =ctr+1; */
        traffic_DW.ctr++;
        break;

       case traffic_IN_init_blink:
        /* During 'init_blink': '<S1>:7' */
        /* '<S1>:11:1' sf_internal_predicateOutput = ... */
        /* '<S1>:11:1' after(5,sec); */
        if (traffic_DW.temporalCounter_i2 >= 50U) {
          /* Transition: '<S1>:11' */
          traffic_DW.is_Init = traffic_IN_transition;
          traffic_DW.temporalCounter_i2 = 0U;

          /* Entry 'transition': '<S1>:8' */
          /* '<S1>:8:1' red=0; */
          traffic_B.red = 0.0;

          /* '<S1>:8:1' yellow =0; */
          traffic_B.yellow = 0.0;

          /* '<S1>:8:1' green =0; */
          traffic_B.green = 0.0;
        }
        break;

       default:
        /* During 'transition': '<S1>:8' */
        /* '<S1>:20:1' sf_internal_predicateOutput = ... */
        /* '<S1>:20:1' after(5,sec)&&ctr~=3; */
        if ((traffic_DW.temporalCounter_i2 >= 50U) && (traffic_DW.ctr != 3.0)) {
          /* Transition: '<S1>:20' */
          traffic_DW.is_Init = traffic_IN_init_blink;
          traffic_DW.temporalCounter_i2 = 0U;

          /* Entry 'init_blink': '<S1>:7' */
          /* '<S1>:7:1' red=1; */
          traffic_B.red = 1.0;

          /* '<S1>:7:1' yellow =1; */
          traffic_B.yellow = 1.0;

          /* '<S1>:7:1' green =1; */
          traffic_B.green = 1.0;

          /* '<S1>:7:2' ctr =ctr+1; */
          traffic_DW.ctr++;
        }
        break;
      }
    }
  } else {
    /* During 'Traffic': '<S1>:3' */
    switch (traffic_DW.is_Traffic) {
     case traffic_IN_Green:
      /* During 'Green': '<S1>:15' */
      /* '<S1>:19:1' sf_internal_predicateOutput = ... */
      /* '<S1>:19:1' after(5,sec); */
      if (traffic_DW.temporalCounter_i1 >= 50U) {
        /* Transition: '<S1>:19' */
        /* '<S1>:19:1' green=0 ; */
        traffic_B.green = 0.0;

        /* '<S1>:19:1' after(5,sec); */
        traffic_DW.is_Traffic = traffic_IN_Red;
        traffic_DW.temporalCounter_i1 = 0U;

        /* Entry 'Red': '<S1>:12' */
        /* '<S1>:12:1' red =1; */
        traffic_B.red = 1.0;
      }
      break;

     case traffic_IN_Red:
      /* During 'Red': '<S1>:12' */
      /* '<S1>:17:1' sf_internal_predicateOutput = ... */
      /* '<S1>:17:1' after(5,sec); */
      if (traffic_DW.temporalCounter_i1 >= 50U) {
        /* Transition: '<S1>:17' */
        /* '<S1>:17:1' red=0 ; */
        traffic_B.red = 0.0;

        /* '<S1>:17:1' after(5,sec); */
        traffic_DW.is_Traffic = traffic_IN_Yellow;
        traffic_DW.temporalCounter_i1 = 0U;

        /* Entry 'Yellow': '<S1>:14' */
        /* '<S1>:14:1' yellow = 1; */
        traffic_B.yellow = 1.0;
      }
      break;

     default:
      /* During 'Yellow': '<S1>:14' */
      /* '<S1>:18:1' sf_internal_predicateOutput = ... */
      /* '<S1>:18:1' after(5,sec); */
      if (traffic_DW.temporalCounter_i1 >= 50U) {
        /* Transition: '<S1>:18' */
        /* '<S1>:18:1' yellow=0 ; */
        traffic_B.yellow = 0.0;

        /* '<S1>:18:1' after(5,sec); */
        traffic_DW.is_Traffic = traffic_IN_Green;
        traffic_DW.temporalCounter_i1 = 0U;

        /* Entry 'Green': '<S1>:15' */
        /* '<S1>:15:1' green =1; */
        traffic_B.green = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (traffic_B.green < 256.0) {
    if (traffic_B.green >= 0.0) {
      tmp = (uint8_T)traffic_B.green;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_digitalWrite(traffic_P.DigitalOutput_pinNumber, tmp);

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  if (traffic_B.yellow < 256.0) {
    if (traffic_B.yellow >= 0.0) {
      tmp = (uint8_T)traffic_B.yellow;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S3>/Digital Output' */
  MW_digitalWrite(traffic_P.DigitalOutput_pinNumber_b, tmp);

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (traffic_B.red < 256.0) {
    if (traffic_B.red >= 0.0) {
      tmp = (uint8_T)traffic_B.red;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S4>/Digital Output' */
  MW_digitalWrite(traffic_P.DigitalOutput_pinNumber_c, tmp);
}

/* Model initialize function */
void traffic_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(traffic_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &traffic_B), 0,
                sizeof(B_traffic_T));

  /* states (dwork) */
  (void) memset((void *)&traffic_DW, 0,
                sizeof(DW_traffic_T));

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_pinModeOutput(traffic_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S3>/Digital Output' */
  MW_pinModeOutput(traffic_P.DigitalOutput_pinNumber_b);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S4>/Digital Output' */
  MW_pinModeOutput(traffic_P.DigitalOutput_pinNumber_c);

  /* SystemInitialize for Chart: '<Root>/Chart' */
  traffic_DW.is_Init = traffic_IN_NO_ACTIVE_CHILD;
  traffic_DW.temporalCounter_i2 = 0U;
  traffic_DW.is_Traffic = traffic_IN_NO_ACTIVE_CHILD;
  traffic_DW.temporalCounter_i1 = 0U;
  traffic_DW.is_active_c3_traffic = 0U;
  traffic_DW.is_c3_traffic = traffic_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void traffic_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
