//---------------------------------------------------------------------
//   PROG : 
//   DATE : 2013.12
//   COMP : sh-rfid
//   DESP : all file list
//---------------------------------------------------------------------

#ifndef _INTERFACE_H_
#define _INTERFACE_H_



sbit serial_s1 	= P0^0;			//传感输入		
sbit serial_s2 	= P0^1;				
sbit serial_s3 	= P0^2;			//PLC启动信号
sbit serial_s4 	= P0^3;				
sbit serial_s5 	= P0^4;				
sbit serial_s6 	= P0^5;				
sbit serial_s7 	= P0^6;				
sbit serial_s8 	= P0^7;	
	
sbit serial_s9  = P2^7;				
sbit serial_s10	= P2^6;		
sbit serial_s11 = P2^5;				
sbit serial_s12	= P2^4;	
sbit serial_s13	= P2^3;				
sbit serial_s14 = P2^2;	
sbit serial_s15	= P2^1;				
sbit serial_s16 = P2^0;		

sbit doorlock_c1  = P1^0;		//电动滚筒控制端
sbit doorlock_c2  = P1^1;	

sbit conveyor_run    = P1^2;   //启动传送带
sbit GND_1      = P1^3;	   	   //还书门控制
sbit V12_2      = P1^4;	
sbit GND_2	    = P1^5;
sbit V12_1	    = P1^6;
	
#define  EntrySensor      serial_s1             //入口光幕防夹手	
#define  ReadSensor       serial_s2		        //读卡入口处 
#define  HeigntSensor     serial_s3		        //测高度
#define  BoxSensor        serial_s4        	    //书箱入口处
#define  OpenStopDoorRun	  serial_s5        	    //下门停止接近开关
#define  CloseStopDoorRun	  serial_s6        	    //上门停止接近开关
#define  SavftyEdag    		  serial_s7	         // 安全触边  


#define switch_on   0			//开关ON
#define switch_off  1			//开关OFF


#define signal_on   0			//光幕被遮挡，端口置0
#define signal_off  1			//光幕无遮挡，端口置1

#define control_on   0			//控制有效，端口置0
#define control_off  1			//控制停止，端口置1

#define led_on   0				//控制有效，端口置0
#define led_off  1				//控制停止，端口置1


extern unsigned char 	SysDeviceState;
extern unsigned char 	SysModle; 

#define EnterSensorFlag 0x01	   //入口光幕
#define ReadSensorFlag  0x02       //门禁光幕   
#define BoxSensorFlag   0x08	   //书箱入口处

#define SystermIdle 	0x00	   //系统忙碌
#define SystermBussy  	0x01       //系统空闲  



#endif
