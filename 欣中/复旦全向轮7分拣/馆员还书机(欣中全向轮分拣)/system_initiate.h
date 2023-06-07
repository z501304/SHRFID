//---------------------------------------------------------------------
//   PROG : 
//   DATE : 2013.12
//   COMP : sh-rfid
//   DESP : all file list
//---------------------------------------------------------------------

#ifndef _SYSTEMINITIATE_H_
#define _SYSTEMINITIATE_H_

 #define EnterSensor_signal_on	 100
 #define ReadSensor_signal_on	 100
 #define BoxSensor_signal_on	 100

extern unsigned char TCounter250;
//extern unsigned char TCounter8;
//extern unsigned char Time8ms_flag;
extern unsigned char Time250ms_flag ;
void system_initiate();
void motor_initiate();
void delay_1msx(unsigned char msxnum);
void delay_200msx(unsigned char num);

extern unsigned char EntrySensor_on_times;
extern unsigned char ReadSensor_on_times;
extern unsigned char ReadSensor_on_timeout_250times;
extern unsigned char BoxSensor_on_times;
extern unsigned char prog_reset_250times;
extern unsigned char book_in_Running_250times;
extern unsigned char book_out_Running_250times;
//extern unsigned char book_out_Running_250times_bake;
extern unsigned char book_drop_Running_250times;
extern unsigned char book_drop_Running_250times_bake;
//extern unsigned char book_stop_running_250tims;
extern unsigned char door_running_250times;
extern unsigned char door_NErunning_250times;
extern unsigned char system_waiting_250times;
//extern unsigned char sys_timeout_flag;

extern unsigned char conveyor_on_timeout;
extern unsigned char safe_flag_timeout;

#endif