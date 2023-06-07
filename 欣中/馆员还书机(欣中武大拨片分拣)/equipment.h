//---------------------------------------------------------------------
//   PROG : 
//   DATE : 2013.12
//   COMP : sh-rfid
//   DESP : all file list
//---------------------------------------------------------------------

#ifndef _SORTMOTOR_H_

#define _SORTMOTOR_H_

void state_testing_mode();

void ReceiveDateProcess(void);
void SystermProcess(void);
void host_command(unsigned char RD_command,unsigned char RD_command_Hpara1,unsigned char RD_command_Hpara2);


extern void prog_check_vison();

void prog_cleck_state();

void prog_direct_running();

void prog_Reverse_running();

void prog_stop_running();

void Light_red_on();

void Light_green_on();

void Light_off();

void Positive_Door_run();

void Negative_Door_run();

void Stop_Door_run();

void delay(unsigned int num);

code char Re_state_ok[];  				// 1.1ÐÞ¸´µÚ6Î»00 to 01

extern unsigned char Re_data_erro[];
extern unsigned char bdata SystemFlag;
extern bit SysState;
extern bit sys_timeout_flag;
extern bit SafeFlag;

extern void prog_check_state_report(unsigned char i_Senser); 
extern void prog_init_report(unsigned char i_Senser);
extern void QuerySysDeviceState(void);


#endif
