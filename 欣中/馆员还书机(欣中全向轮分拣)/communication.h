//---------------------------------------------------------------------
//   PROG : 
//   DATE : 2013.12
//   COMP : sh-rfid
//   DESP : all file list
//---------------------------------------------------------------------

#ifndef _RS232_H_
#define _RS232_H_

void initiate_RS232(void);

void send_char_com(unsigned char ch) ;

void send_string_com(unsigned char *str) ;
void send_string_err(unsigned char err_State);




extern	unsigned char RD_command_Hpara1 ; 
extern	unsigned char RD_command_Hpara2 ;
//extern	unsigned char RD_command_Lpara1 ; 
//extern	unsigned char RD_command_Lpara2 ; 

extern unsigned int CURRENT_FATHER_PROCESS ;	  
extern unsigned int CURRENT_SON_PROCESS ;	
extern unsigned int CURRENT_GRANDSON_PROCESS ;
extern unsigned char RevolEnable;
extern unsigned char prog_book_drop_Return;

extern unsigned char prog_book_drop_kind;

#define PROCESS_Command_reset 					0x10
#define PROCESS_Command_reset_Step0				0x10
#define PROCESS_Command_reset_Step1				0x11
#define PROCESS_Command_reset_Step2				0x12
#define PROCESS_Command_reset_Step3				0x13

#define PROCESS_Command_book_in   				0x30
#define PROCESS_Command_book_in_Step0			0x30
#define PROCESS_Command_book_in_Step1			0x31
#define PROCESS_Command_book_in_Step2			0x32
#define PROCESS_Command_book_in_Step3 			0x33
#define PROCESS_Command_book_in_Step4 			0x34
#define PROCESS_Command_book_in_Step5 			0x35
#define PROCESS_Command_book_in_Step6 			0x36
#define PROCESS_Command_book_in_Step7 			0x37

#define PROCESS_Command_book_drop  				0x40
#define PROCESS_Command_book_drop_Step0			0x40
#define PROCESS_Command_book_drop_Step1			0x41
#define PROCESS_Command_book_drop_Step2			0x42
#define PROCESS_Command_book_drop_Step3			0x43
#define PROCESS_Command_book_drop_Step4			0x44
#define PROCESS_Command_book_drop_Step5			0x45
#define PROCESS_Command_book_drop_Step6			0x46
#define PROCESS_Command_book_drop_Step7			0x47
#define PROCESS_Command_book_drop_Step8			0x48
#define PROCESS_Command_book_drop_Step9			0x49
#define PROCESS_Command_book_drop_StepA			0x4A
#define PROCESS_Command_book_drop_End			0x4B


#define PROCESS_Command_book_out   				0x50
#define PROCESS_Command_book_out_Step0   		0x50
#define PROCESS_Command_book_out_Step1   		0x51
#define PROCESS_Command_book_out_Step2   		0x52
#define PROCESS_Command_book_out_Step3   		0x53
#define PROCESS_Command_book_out_Step4   		0x54
#define PROCESS_Command_book_out_Step5   		0x55
#define PROCESS_Command_book_out_Step6   		0x56
#define PROCESS_Command_book_out_Step7   		0x57
#define PROCESS_Command_book_out_Step8   		0x58
#define PROCESS_Command_book_out_Step9   		0x59
#define PROCESS_Command_book_out_StepA   		0x5A
#define PROCESS_Command_book_out_StepB   		0x5C
#define PROCESS_Command_book_out_StepC   		0x5D
#define PROCESS_Command_book_out_End			0x5B
#define PROCESS_Command_book_out_StepF   		0x5F

#define PROCESS_Command_prog_direct   				0xB0			//2014.2	 传送带正转
#define PROCESS_Command_prog_direct_Step0   		0xB0			
#define PROCESS_Command_prog_direct_Step1   		0xB1			
#define PROCESS_Command_prog_direct_Step2   		0xB2			

#define PROCESS_Command_prog_reverse   				0xA0			//2014.2	 传送带反转
#define PROCESS_Command_prog_reverse_Step0   		0xA0			
#define PROCESS_Command_prog_reverse_Step1   		0xA1			
#define PROCESS_Command_prog_reverse_Step2   		0xA2

#define PROCESS_Command_prog_stop   				0xC0			//2014.2	 传送带停止
#define PROCESS_Command_prog_stop_Step0   		    0xC0

#define CURRENT_GRANDSON_PROCESS_step0		    0x00
#define CURRENT_GRANDSON_PROCESS_step1			0x01
#define CURRENT_GRANDSON_PROCESS_step2			0x02
#define CURRENT_GRANDSON_PROCESS_step3			0x03
#define CURRENT_GRANDSON_PROCESS_step4			0x04
#define CURRENT_GRANDSON_PROCESS_step5			0x05
#define CURRENT_GRANDSON_PROCESS_step6			0x06





#define PROCESS_Command_check_vison     		0x70
#define PROCESS_Command_check_vison_Step0     	0x70
#define PROCESS_Command_check_vison_Step1     	0x71
#define PROCESS_Command_check_vison_Step2     	0x72
#define PROCESS_Command_check_vison_Step3     	0x73

#define PROCESS_Command_cleck_state			    0x80
#define PROCESS_Command_cleck_state_Step0		0x80
#define PROCESS_Command_cleck_state_Step1		0x81
#define PROCESS_Command_cleck_state_Step2		0x82
#define PROCESS_Command_cleck_state_Step3		0x83

#define PROCESS_Command_Idle            		0x90


#define PROCESS_Command_End						0x60  //添加结束子指令
#define PROCESS_Command_End_Step0				0x61
#define PROCESS_Command_End_Step1				0x62
#define PROCESS_Command_End_Step2				0x63


#define Command_reset 						0x21	 

#define Command_book_action       			0x22

#define Command_check_vison     			0x40

#define Command_cleck_state					0x24

#define Command_Idle            			0x29


#define		RecvStateIdle					0x00
#define		RecvStateBuzzy					0x01
#define		RecvStateEnd					0x02
#define		CE_OK							0x00	 //通讯正常
#define		CE_CHECKERROR					0x01	 //校验错
#define		CE_BADCOMMAND					0x02	 //命令错	
#define		CE_BADPARAM						0x03	 //参数错误
#define		CE_EXECUTE						0x04	 //逻辑错误
#define		CE_UNKNOWN						0x05	 //未知错误
#define		CE_NOCOMM						0x06	 //通讯错误




extern unsigned char SerialInbuff[];
extern unsigned char InBuff[];
extern unsigned char RecvState;
extern unsigned char  crcbuf_Out[6],crcbuf_In[6];

unsigned int CRC3(unsigned char *ptr, unsigned char i_len);

#endif
