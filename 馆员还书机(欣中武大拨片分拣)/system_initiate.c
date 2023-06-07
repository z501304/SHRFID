//---------------------------------------------------------------------
//   PROG : 
//   DATE : 2013.12
//   COMP : sh-rfid
//   DESP : all file list
//---------------------------------------------------------------------

#include "include.h"




unsigned char TCounter250						= 0;
//unsigned char TCounter8							= 0;
//unsigned char Time8ms_flag						= 0;
unsigned char Time250ms_flag 					= 0;
unsigned char EntrySensor_on_times  			= 0;
unsigned char ReadSensor_on_times   			= 0;
unsigned char ReadSensor_on_timeout_250times   	= 0;
unsigned char BoxSensor_on_times				= 0;
unsigned char prog_reset_250times 				= 0;
unsigned char book_in_Running_250times  		= 0;
unsigned char book_out_Running_250times 		= 0;
//unsigned char book_out_Running_250times_bake 	= 0;
unsigned char book_drop_Running_250times		= 0;
unsigned char book_drop_Running_250times_bake	= 0;
//unsigned char book_stop_running_250tims 		= 0;
unsigned char door_running_250times				= 0;
unsigned char door_NErunning_250times		    = 0;
unsigned char system_waiting_250times 			= 240;
//unsigned char sys_timeout_flag 		         	= 0;

unsigned char conveyor_on_timeout				= 0;
unsigned char safe_flag_timeout					= 0;

void InitTimer(void)
{
	TMOD= 0X21; 	//TMOD = 0010 0001;  定时器0工作在16位计数模式，定时器1工作在8位自动装载模式，用作串口波特率发生器  
	TL0 = 0xCC;
	TH0 = 0xF8;    //0xFC;  //(65536-0XF8CC)*12/22.1184MHz=1MS
	TR0 = 1;       //打开定时器0
}
//Delay function-----------------------------------------------
void delay_1msx(unsigned char msxnum)  
{
    unsigned char a,b,c;

    for(c= msxnum;c>0;c--)
  	  for(b=141;b>0;b--)							 //
        for(a=5;a>0;a--);
}

void delay_200msx(unsigned char num)
{
     unsigned char t;
	 for(t=num;t>0;t--)
	 {
	    delay_1msx(200);
	 }
}
void system_initiate()
{
	CURRENT_FATHER_PROCESS 	= PROCESS_Command_Idle ;	  
	CURRENT_SON_PROCESS		= PROCESS_Command_Idle ;	

	TCounter250 	= 0;	//250毫秒计数器
//	TCounter8 		= 0;	//8毫秒计数器
//	Time8ms_flag 	= 0;	//8毫秒标志
	Time250ms_flag	= 0;    //250毫秒标志
 	InitTimer();
    initiate_RS232();
	IE=0X92;               //中断允许   IE =  1001 0010B;  EA = 1, ES = 1, ET0 = 1; 
}



