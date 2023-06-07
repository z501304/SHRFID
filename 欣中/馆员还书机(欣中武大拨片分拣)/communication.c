//---------------------------------------------------------------------
//   PROG : 
//   DATE : 2013.12
//   COMP : sh-rfid
//   FILE : rs232.c
//   DESP : all file list
//-----------------------------------------------------------------------------------
#include "include.h"

#define INBUF_LEN   0x0d	  //lenth of buffer	   

#define Revcom_head  0x02	  //the first data of the command. 
#define Revcom_tail  0x03  	  //the last data of the command.

unsigned int CURRENT_FATHER_PROCESS ;	  
unsigned int CURRENT_SON_PROCESS ;	
unsigned int CURRENT_GRANDSON_PROCESS ;	
unsigned char RD_command_Hpara1 ; 
unsigned char RD_command_Hpara2 ;
//unsigned char RD_command_Lpara1 ; 
//unsigned char RD_command_Lpara2 ; 


unsigned char prog_book_drop_kind = 0x00;
unsigned char RevolEnable = 0;
unsigned char prog_book_drop_Return =  0x00;



unsigned char SerialInbuff[INBUF_LEN];
unsigned char InBuff[INBUF_LEN];

unsigned char RecvIndex;
unsigned char RecvState;
uchar crcbuf_Out[6],crcbuf_In[6];

// intitiate serial port---------------------------------------------------------------
void initiate_RS232 (void)         
{
    ES = 0;                          // Against the serial port interrupt
    TMOD |= 0x20;                    // set the baud rate generator T1
    SCON = 0x50;                     // 0101,0000  8 data bits, no parity
    TH1 = 0xFD;                      // 22.1184MHz crystal oscillator, baud rate = 19200
    TL1 = 0xFD;
    RI = 0;							 //	Allow the serial port to receive
    TR1 = 1;						 
    EA = 1;                          //	Open the master switch of interrupt
    PCON = 0x80;                     //	Double Frequency, baud rate = 19200 * 2 = 38400
    ES = 1;                          //	Allow the serial port interrupt
}
//Serial port receive interrupt function-----------------------------------------------
void serial () interrupt 4 using 3
{
	if(RI)
	{
	    RI = 0;	
		if(RecvIndex > 0x0b)									//如果接收数据大于11，说明数据溢出，拒绝接收
		{
			RecvIndex =0;										//重新开始接收数据
			return ;
		}
		SerialInbuff[RecvIndex]  = SBUF;		
		if(SerialInbuff[0] == Revcom_head)						/*起始标志*/
		{
	 		RecvIndex = RecvIndex +1;	
			if(RecvIndex == 0x0b && RecvIndex <= INBUF_LEN)	 	/* 判断是否接收完成*/
			{	
				RecvIndex = 0;
				RecvState = RecvStateEnd;							  
			}
			else
				RecvState = RecvStateBuzzy;				
		}
		else
			 RecvIndex = 0;
	}
}

//Delay function-----------------------------------------------

//void delay_1msx(unsigned int msxnum)  
//{
//    unsigned char a,b,c;
//
//    for(c= msxnum;c>0;c--)
//  	  for(b=80;b>0;b--)
//        for(a=10;a>0;a--);
//}

//send one byte data to serial port-----------------------------------------------------

void send_char_com(unsigned char ch) 
{
	SBUF=ch;
	while(TI==0);
	TI=0;
}

//send one string data to serial port-----------------------------------------------------

void send_string_com(unsigned char *str) 
{
	unsigned char Str_Buff[0x0b] = {0};
	unsigned int crcTemp = 0; 
	unsigned int k;
	for(k=0;k<0x0b;k++)
		Str_Buff[k] = str[k];
	crcTemp=CRC3(&Str_Buff[2], 6);
	Str_Buff[9]= (unsigned char)crcTemp;
	Str_Buff[8]= (unsigned char)(crcTemp>>8); 
	k = 0;
	do
	{
		send_char_com(*(Str_Buff + k));
		k++;
	} while(k < 0x0b); 
}
 void send_string_err(unsigned char err_State) 
{
	unsigned char Err_Buff[0x0b] = {0},i;
	unsigned int crcTemp = 0; 
	for(i=0;i<0x0b;i++)
		Err_Buff[i] = InBuff[i];
	Err_Buff[0] = 0x82;
	Err_Buff[3] = err_State;	
	crcTemp=CRC3(&Err_Buff[2], 6);
	Err_Buff[9]= (unsigned char)crcTemp;
	Err_Buff[8]= (unsigned char)(crcTemp>>8);  
	Err_Buff[10]= 0x83;
	i = 0;
	do
	{
		send_char_com(*(Err_Buff + i));
		i++;
	} while(i < 0x0b); 
}
  