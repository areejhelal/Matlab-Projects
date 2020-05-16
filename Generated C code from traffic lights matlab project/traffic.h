/*
 * File: traffic.h
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

#ifndef RTW_HEADER_traffic_h_
#define RTW_HEADER_traffic_h_
#include <stddef.h>
#include <string.h>
#ifndef traffic_COMMON_INCLUDES_
# define traffic_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* traffic_COMMON_INCLUDES_ */

#include "traffic_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T green;                        /* '<Root>/Chart' */
  real_T red;                          /* '<Root>/Chart' */
  real_T yellow;                       /* '<Root>/Chart' */
} B_traffic_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T ctr;                          /* '<Root>/Chart' */
  uint8_T is_active_c3_traffic;        /* '<Root>/Chart' */
  uint8_T is_c3_traffic;               /* '<Root>/Chart' */
  uint8_T is_Init;                     /* '<Root>/Chart' */
  uint8_T is_Traffic;                  /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
  uint8_T temporalCounter_i2;          /* '<Root>/Chart' */
} DW_traffic_T;

/* Parameters (auto storage) */
struct P_traffic_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S2>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_b;  /* Mask Parameter: DigitalOutput_pinNumber_b
                                        * Referenced by: '<S3>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNumber_c;  /* Mask Parameter: DigitalOutput_pinNumber_c
                                        * Referenced by: '<S4>/Digital Output'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_traffic_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_traffic_T traffic_P;

/* Block signals (auto storage) */
extern B_traffic_T traffic_B;

/* Block states (auto storage) */
extern DW_traffic_T traffic_DW;

/* Model entry point functions */
extern void traffic_initialize(void);
extern void traffic_step(void);
extern void traffic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_traffic_T *const traffic_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'traffic'
 * '<S1>'   : 'traffic/Chart'
 * '<S2>'   : 'traffic/Digital Output'
 * '<S3>'   : 'traffic/Digital Output1'
 * '<S4>'   : 'traffic/Digital Output2'
 */
#endif                                 /* RTW_HEADER_traffic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
