//---------------------------------------------------------------------
//   PROG : 
//   DATE : 2013.12
//   COMP : sh-rfid
//   DESP : all file list
//---------------------------------------------------------------------

#ifndef _INTERFACE_H_
#define _INTERFACE_H_



sbit serial_s1 	= P0^0;			//��������		
sbit serial_s2 	= P0^1;				
sbit serial_s3 	= P0^2;			//PLC�����ź�
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

sbit doorlock_c1  = P1^0;		//�綯��Ͳ���ƶ�
sbit doorlock_c2  = P1^1;	

sbit conveyor_run    = P1^2;   //�������ʹ�
sbit GND_1      = P1^3;	   	   //�����ſ���
sbit V12_2      = P1^4;	
sbit GND_2	    = P1^5;
sbit V12_1	    = P1^6;
	
#define  EntrySensor      serial_s1             //��ڹ�Ļ������	
#define  ReadSensor       serial_s2		        //������ڴ� 
#define  HeigntSensor     serial_s3		        //��߶�
#define  BoxSensor        serial_s4        	    //������ڴ�
#define  OpenStopDoorRun	  serial_s5        	    //����ֹͣ�ӽ�����
#define  CloseStopDoorRun	  serial_s6        	    //����ֹͣ�ӽ�����
#define  SavftyEdag    		  serial_s7	         // ��ȫ����  


#define switch_on   0			//����ON
#define switch_off  1			//����OFF


#define signal_on   0			//��Ļ���ڵ����˿���0
#define signal_off  1			//��Ļ���ڵ����˿���1

#define control_on   0			//������Ч���˿���0
#define control_off  1			//����ֹͣ���˿���1

#define led_on   0				//������Ч���˿���0
#define led_off  1				//����ֹͣ���˿���1


extern unsigned char 	SysDeviceState;
extern unsigned char 	SysModle; 

#define EnterSensorFlag 0x01	   //��ڹ�Ļ
#define ReadSensorFlag  0x02       //�Ž���Ļ   
#define BoxSensorFlag   0x08	   //������ڴ�

#define SystermIdle 	0x00	   //ϵͳæµ
#define SystermBussy  	0x01       //ϵͳ����  



#endif
