//---------------------------------------------------------------------
//   PROG : 
//   DATE : 2014.2
//   COMP : sh-rfid
//   DESP : all file list
//---------------------------------------------------------------------
#include "include.h"

#define  ReaderSignalON			0x02
#define	 ReaderSignalOFF		0x00
#define  BoxSignalON			0x01
#define	 BoxSignalOFF			0x00
//��λ�����
code char Re_reset[]	 	= {0x82,0x08,0x21,0x00,0x00,0x00,0x00,0x00,0xA6,0xE3,0x83};  
//��������� 
code char Re_book_in[]  	= {0x82,0x08,0x22,0x00,0x01,0x01,0x00,0x00,0xBC,0xA9,0x83}; 
//��������� 
code char Re_book_out[]  	= {0x82,0x08,0x22,0x00,0x01,0x02,0x00,0x00,0xD8,0x46,0x83};
//���������  
code char Re_book_drop[]  	= {0x82,0x08,0x22,0x00,0x02,0x01,0x00,0x00,0x71,0x8C,0x83};
//��������
code char Re_close_drop[]   = {0x82,0x08,0x22,0x00,0x02,0x02,0x00,0x00,0x15,0x63,0x83}; 
//�̼��汾��ѯ����
//code char Re_check_vison[]  = {0x82,0x08,0x40,0x00,version_H,version_L,0x00,0x00,0xDE,0xAB,0x83};// //1.1
//���ʹ���ת
code char Re_prog_direct[]  = {0x82,0x08,0x22,0x00,0x03,0x01,0x00,0x00,0x71,0x8C,0x83};
//���ʹ���ת
code char Re_prog_reverse[] = {0x82,0x08,0x22,0x00,0x03,0x02,0x00,0x00,0x71,0x8C,0x83};
//���ʹ�ֹͣ
code char Re_prog_stop[]  	= {0x82,0x08,0x22,0x00,0x03,0x03,0x00,0x00,0x71,0x8C,0x83};

//�����ϱ�����
code char init_report_s0[]		= {0x82,0x08,0x23,0x00,0x00,0x00,0x00,0x00,0x4B,0xf7,0x83};	  //ȫ�����
code char init_report_s1[]		= {0x82,0x08,0x23,0x00,0x01,0x00,0x00,0x00,0x4B,0xf7,0x83};	  //1�Ź�Ļ���ڵ�
code char init_report_s2[]		= {0x82,0x08,0x23,0x00,0x02,0x00,0x00,0x00,0x86,0xD2,0x83};	  //2�Ź�Ļ���ڵ�
code char init_report_s3[]		= {0x82,0x08,0x23,0x00,0x03,0x00,0x00,0x00,0x3D,0xCE,0x83};	  //3�Ź�Ļ���ڵ�
code char init_report_s4[]		= {0x82,0x08,0x23,0x00,0x04,0x00,0x00,0x00,0x1C,0x99,0x83};	  //4�Ź�Ļ���ڵ�
code char init_report_s5[]		= {0x82,0x08,0x23,0x00,0x05,0x00,0x00,0x00,0xA7,0x85,0x83};	  //1�Ź�Ļ�����
code char init_report_s6[]		= {0x82,0x08,0x23,0x00,0x06,0x00,0x00,0x00,0x6A,0xA0,0x83};	  //2�Ź�Ļ�����
code char init_report_s7[]		= {0x82,0x08,0x23,0x00,0x07,0x00,0x00,0x00,0xD1,0xBC,0x83};	  //3�Ź�Ļ�����
code char init_report_s8[]		= {0x82,0x08,0x23,0x00,0x08,0x00,0x00,0x00,0x28,0x0E,0x83};	  //4�Ź�Ļ�����
code char init_report_s9[]		= {0x82,0x08,0x23,0x00,0x09,0x00,0x00,0x00,0x93,0x12,0x83};	  //���ŵ�λ
code char init_report_s10[]		= {0x82,0x08,0x23,0x00,0x0a,0x00,0x00,0x00,0x5E,0x37,0x83};	  //���ų�ʱ
code char init_report_s11[]		= {0x82,0x08,0x23,0x00,0x0b,0x00,0x00,0x00,0xE5,0x2B,0x83};	  //���ŵ�λ
code char init_report_s12[]		= {0x82,0x08,0x23,0x00,0x0c,0x00,0x00,0x00,0xC4,0x7C,0x83};	  //���ų�ʱ
code char init_report_s13[]		= {0x82,0x08,0x23,0x00,0x0d,0x00,0x00,0x00,0xA3,0x3A,0x83};  
code char init_report_s14[]		= {0x82,0x08,0x23,0x00,0x0e,0x00,0x00,0x00,0x0A,0xF0,0x83};
code char init_report_s15[]		= {0x82,0x08,0x23,0x00,0x0f,0x00,0x00,0x00,0x09,0x59,0x83};
code char init_report_s17[]		= {0x82,0x08,0x23,0x00,0x11,0x01,0x00,0x00,0xA3,0x3A,0x83};  //���ʹ���ת
code char init_report_s18[]		= {0x82,0x08,0x23,0x00,0x11,0x02,0x00,0x00,0x0A,0xF0,0x83};	 //���ʹ���ת
code char init_report_s19[]		= {0x82,0x08,0x23,0x00,0x11,0x03,0x00,0x00,0x09,0x59,0x83};	 //���ʹ�ֹͣ
code char init_report_s20[]		= {0x82,0x08,0x23,0x00,0x12,0x00,0x00,0x00,0x00,0x00,0x83};	 //ͼ�鳬��
code char init_report_s21[]		= {0x82,0x08,0x23,0x00,0x13,0x00,0x00,0x00,0x00,0x00,0x83};	 //�����������
code char init_report_s30[]		= {0x82,0x08,0x23,0x00,0xee,0x00,0x00,0x00,0x00,0x00,0x83};	 //������״̬����

code char init_report_s121[]	= {0x82,0x08,0x23,0x00,0x0c,0x01,0x00,0x00,0xC4,0x7C,0x83};  //�������� 

code char init_report_s131[]	= {0x82,0x08,0x23,0x00,0x0d,0x01,0x00,0x00,0xA3,0x3A,0x83};  // ����ɹ�
code char init_report_s132[]	= {0x82,0x08,0x23,0x00,0x0d,0x02,0x00,0x00,0xC7,0xD5,0x83};  // ����ʧ��
code char init_report_s133[]	= {0x82,0x08,0x23,0x00,0x0d,0x03,0x00,0x00,0xC7,0xD5,0x83};  // ���鳬ʱ
code char init_report_s141[]	= {0x82,0x08,0x23,0x00,0x0e,0x01,0x00,0x00,0x6E,0x1F,0x83};	 // ����ɹ�
code char init_report_s142[]	= {0x82,0x08,0x23,0x00,0x0e,0x02,0x00,0x00,0x0A,0xF0,0x83};	 // ����ʧ��
code char init_report_s151[]	= {0x82,0x08,0x23,0x00,0x0f,0x01,0x00,0x00,0x09,0x59,0x83};	 //	����ɹ�
code char init_report_s152[]	= {0x82,0x08,0x23,0x00,0x0f,0x02,0x00,0x00,0x51,0x28,0x83};	 // ����ʧ��
code char init_report_s16[]		= {0X82,0X08,0X23,0X00,0X10,0X00,0X00,0X00,0x00,0x00,0X83};	 // ��λ�ɹ�
//״̬��ѯ����
code char Re_che_state[]		= {0x82,0x08,0x24,0x00,0x00,0x00,0x00,0x00,0x21,0xf7,0x83};
code char Re_state_ok[]			= {0x82,0x08,0x24,0x00,0x00,0x01,0x00,0x00,0x1f,0x66,0x83};
/*code char Re_s1_erro[]			= {0x82,0x08,0x24,0x00,0x01,0x00,0x00,0x00,0x9a,0xeb,0x83};
code char Re_s2_erro[]			= {0x82,0x08,0x24,0x00,0x02,0x00,0x00,0x00,0xb5,0x05,0x83};
code char Re_s3_erro[]			= {0x82,0x08,0x24,0x00,0x03,0x00,0x00,0x00,0x0e,0xe9,0x83};
code char Re_s4_erro[]			= {0x82,0x08,0x24,0x00,0x04,0x00,0x00,0x00,0x2f,0x4e,0x83};
code char Re_s5_erro[]			= {0x82,0x08,0x24,0x00,0x05,0x00,0x00,0x00,0x94,0x52,0x83};
code char Re_s6_erro[]			= {0x82,0x08,0x24,0x00,0x06,0x00,0x00,0x00,0x59,0x77,0x83};
code char Re_s7_erro[]			= {0x82,0x08,0x24,0x00,0x07,0x00,0x00,0x00,0xe2,0x6b,0x83};
code char Re_s8_erro[]			= {0x82,0x08,0x24,0x00,0x08,0x00,0x00,0x00,0x1b,0xd9,0x83};
code char Re_s9_erro[]			= {0x82,0x08,0x24,0x00,0x09,0x00,0x00,0x00,0xa0,0xc5,0x83};
code char Re_s10_erro[]			= {0x82,0x08,0x24,0x00,0x0a,0x00,0x00,0x00,0x6d,0xe0,0x83};
code char Re_s11_erro[]			= {0x82,0x08,0x24,0x00,0x0b,0x00,0x00,0x00,0xd6,0xfc,0x83};
code char Re_s12_erro[]			= {0x82,0x08,0x24,0x00,0x0c,0x00,0x00,0x00,0xf7,0xab,0x83};
code char Re_s13_erro[]			= {0x82,0x08,0x24,0x00,0x0d,0x00,0x00,0x00,0x4c,0xb7,0x83};
code char Re_s14_erro[]			= {0x82,0x08,0x24,0x00,0x0e,0x00,0x00,0x00,0x81,0x92,0x83};
code char Re_s15_erro[]			= {0x82,0x08,0x24,0x00,0x0f,0x00,0x00,0x00,0x3a,0x8e,0x83};
code char Re_s16_erro[]			= {0x82,0x08,0x24,0x00,0x10,0x00,0x00,0x00,0x62,0xff,0x83};	*/

unsigned char Re_data_erro[]		= {0x82,0x08,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83};

unsigned char bdata SystemFlag;
sbit SysState = SystemFlag^0;
sbit sys_timeout_flag = SystemFlag^1;
sbit SafeFlag = SystemFlag^2;

void prog_direct_running()    		//�����Ƥ����ת
{
	doorlock_c1 = control_off;
	doorlock_c2 = control_on;
}
void prog_Reverse_running()    		//�����Ƥ����ת
{
	doorlock_c1 = control_on;
	doorlock_c2 = control_off;
}
void prog_stop_running()    											     //ֹͣ
{	
	doorlock_c1 = control_off;
	doorlock_c2 = control_off;
	delay_1msx(100);
//	book_stop_running_250tims = 2;
//	while(book_stop_running_250tims) ;									   //ֹͣ����ͣ500ms��������ֵ������װ����֮ͣ���л������������˵��
}
/*void Light_red_on()													        //��ɫָʾ��������ɫָʾ����
{
	light_red     = control_on;
	light_green = control_off;
}

void Light_green_on()													//��ɫָʾ��������ɫָʾ����
{
	light_red     = control_off;
	light_green = control_on;
}

void Light_off()															//��ɫ��ɫָʾ�ƶ���
{
	light_red     = control_off;
	light_green = control_off;
}*/

void Positive_Door_run()			//����
{
//	  delay(800);									//2012.11.28
	  GND_1 = 0;
	  V12_1 = 0;
	  GND_2 = 1;
	  V12_2 = 1;

}

void Negative_Door_run()		   //����
{
	  GND_1 = 1;
	  V12_1 = 1;
 	  GND_2 = 0;
	  V12_2 = 0;
}

void Stop_Door_run()
{
	  GND_1 = 1;
	  V12_1 = 1;
 	  GND_2 = 1;
	  V12_2 = 1;
}
	
////////////////////////////////////////////////////////////////////////
//���ƣ�uint CRC3(unsigned char *ptr, uchar  i_len)
//���ܣ�����ָ������ѭ������У����
//��ڲ�����ptr     ָ�����ݿ��׵�ַ
//          i_len   ָ�����ݿ鳤��
//���ڲ�����crc     ָ�����ݵ�У����
//ϵͳӰ�죺��
///////////////////////////////////////////////////////////////////////
#pragma region CRCУ��
uint CRC3(unsigned char *ptr, uchar  i_len)
{
	uint CRC_POLYNOM = 0x8408;     										//polynome [��]����ʽ(��)
	uint CRC_PRESET  = 0xFFFF;
	uint crc = CRC_PRESET;
	uchar i,j;
	for(i=0;i< i_len;i++)
	{
		crc^=*ptr;            											        // ^ ������ crc = crc ^ (*ptr) = 0xFFFF ^(*ptr)
		ptr++;
		for(j=0;j< 8; j++)
		{
			if((crc&0x0001)>0)
				crc = (crc>>1)^CRC_POLYNOM;
			else
				crc = (crc>>1);
		}				    	
	}
	return (crc);
}
#pragma endregion											  							//����ʱ��Ƭ��ʽģ����̴߳���

#pragma region ���̴���			
															//�����ڱ���ִ��ʱ��ϳ���������ڼ���Ӧϵͳ������Ա�����λ������
void SystermProcess(void)
{
    uchar flag = 0;
    switch(CURRENT_FATHER_PROCESS)
	{
	    #pragma region ��λ����
	  
		case PROCESS_Command_reset : 									
			switch(CURRENT_SON_PROCESS)
			{
				case  PROCESS_Command_reset_Step0:
					  send_string_com(Re_reset);						//�ϱ���λ������յ�
					  prog_direct_running();							//���ʹ���ת
					  
					  //Positive_Door_run();							//����  ���������ڴ��ӽ����������෴	��2013.5.7 �����
					  prog_reset_250times = 4*4;						//���ת��ʱ��5��
					  door_running_250times = 4*4;					//����ʱ�����3��
					  CURRENT_SON_PROCESS 	= PROCESS_Command_reset_Step1;
					  SysModle = SystermBussy;
					  //break;
				case  PROCESS_Command_reset_Step1:
									 
// 					  if((CloseStopDoorRun == 0)||(!door_running_250times))			//�ŵ�λֹͣ9.22
// 					  {
// 					  	 Stop_Door_run();
// 						// send_string_com(init_report_s9);		   //�ϱ����ŵ�λ
// 					  }

					  if(prog_reset_250times<8)  
					  {						
						  prog_Reverse_running();
						  if(prog_reset_250times==0)
						  {	
							  prog_stop_running();
							  prog_reset_250times = 4*3;	
							  door_NErunning_250times = 4*5;
							  //Negative_Door_run();
							  CURRENT_SON_PROCESS = PROCESS_Command_reset_Step2;
						  }	  							
					  }	
					  
					  break;
				case  PROCESS_Command_reset_Step2:
						//Negative_Door_run();																			                           //����ʱ�����5��
// 						while((OpenStopDoorRun == 0))//||(!door_NErunning_250times))				 //�ŵ�λֹͣ9.22
// 					  	{
// 					  		 Stop_Door_run();
// 							// send_string_com(init_report_s11);					     //�ϱ����ŵ�λ
// 							 send_string_com(init_report_s16);						 //�ϱ���λ��ϣ��豸���ڿ���״̬
// 							 CURRENT_SON_PROCESS = PROCESS_Command_reset_Step3;
// 							 SysModle = SystermIdle;
// 							 break;
// 					 	}
							send_string_com(init_report_s16);						 //�ϱ���λ��ϣ��豸���ڿ���״̬
							CURRENT_SON_PROCESS = PROCESS_Command_reset_Step3;
							SysModle = SystermIdle;
							 break;
// 						if((!EntrySensor )||(!SavftyEdag))	//����ڸô��ж����ڵ����ֻ����Ϣ��֪?						
// 						{
// 							Stop_Door_run();
// 							delay(50);
// 							while(CloseStopDoorRun!=0)
// 								{
// 								Positive_Door_run();
// 						    	}
// 							
// 							Stop_Door_run();
// 							delay(50);
// //                            Negative_Door_run();
// //							break;
// 				 		 }
// 						 else if(EntrySensor&&SavftyEdag)		  //��������ϰ�������
// 						 {
// 							Negative_Door_run();
// 						 } 
						
					break;
					
				default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;	//��λ��ϣ�����ϵͳΪ����״̬
						break;
			}
			break;
			#pragma endregion
	
		  
			#pragma region ���ʹ���ת
		case PROCESS_Command_prog_direct : 									
			switch(CURRENT_SON_PROCESS)
			{
				case  PROCESS_Command_prog_direct_Step0:
					  send_string_com(Re_prog_direct);					//�ϱ����ʹ���תָ���յ�
					  prog_direct_running();							//���ʹ���ת
					  send_string_com(init_report_s17);					//�ϱ����ʹ���ת
					  prog_reset_250times = 4*60;						//���ת��ʱ��60��
					  CURRENT_SON_PROCESS 	= PROCESS_Command_prog_direct_Step1;
					  SysModle = SystermBussy;
					  break;
				case  PROCESS_Command_prog_direct_Step1:									 
					  if(prog_reset_250times == 0)  //  || (!door_running_250times))		
					  {
					  	 prog_stop_running();
						 CURRENT_SON_PROCESS 	= PROCESS_Command_prog_direct_Step2;
						 break;
					  }
					  else
					     CURRENT_SON_PROCESS 	= PROCESS_Command_prog_direct_Step2;
					  break;
				case  PROCESS_Command_prog_direct_Step2:
				       SysModle = SystermIdle;	
				default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;	//����ϵͳΪ����״̬					
						break;
			}
			break;
			#pragma endregion
		
		  
			#pragma region ���ʹ���ת
			
		case PROCESS_Command_prog_reverse : 									
			switch(CURRENT_SON_PROCESS)
			{
				case  PROCESS_Command_prog_reverse_Step0:
					  send_string_com(Re_prog_reverse);					//�ϱ����ʹ���תָ���յ�
					  prog_Reverse_running();							//���ʹ���ת
					  send_string_com(init_report_s18);					//�ϱ����ʹ���ת
					  prog_reset_250times = 4*60;						//���ת��ʱ��60��
					  CURRENT_SON_PROCESS 	= PROCESS_Command_prog_reverse_Step1;
					  SysModle = SystermBussy;
					  break;
				case  PROCESS_Command_prog_reverse_Step1:									 
					  if(prog_reset_250times == 0)  //  || (!door_running_250times))		
					  {
					  	 prog_stop_running();
						 CURRENT_SON_PROCESS 	= PROCESS_Command_prog_reverse_Step2;
						 break;
					  }
					  else
					     CURRENT_SON_PROCESS 	= PROCESS_Command_prog_reverse_Step2;
					  break;
				case  PROCESS_Command_prog_reverse_Step2:
				       SysModle = SystermIdle;	
				default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;	//����ϵͳΪ����״̬					
						break;
			}
			break;
			#pragma endregion
			
			
			#pragma region ���ʹ�ֹͣ
		case PROCESS_Command_prog_stop : 									
			switch(CURRENT_SON_PROCESS)
			{
				case  PROCESS_Command_prog_stop_Step0:
					  send_string_com(Re_prog_stop);					//�ϱ����ʹ���תָ���յ�
					  SysModle = SystermBussy;
					  prog_stop_running();
					  send_string_com(init_report_s19);					//�ϱ����ʹ�ֹͣ
					  SysModle = SystermIdle;							//���ʹ���ת	
				default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;	//����ϵͳΪ����״̬					
						break;
			}
			break;
			#pragma endregion
		  
			
			#pragma region �������
		case PROCESS_Command_book_in:
			switch(CURRENT_SON_PROCESS)
			{  
				case  PROCESS_Command_book_in_Step0:
						send_string_com(Re_book_in);
						door_running_250times = 4*4;	        //���Ž���Ϊ3��	2013.5.7
				//		Positive_Door_run();
						BoxSensor_on_times = 0; 				//���䴫������ʼ��
            SysModle = SystermBussy;
//						conveyor_run = 0;						//���ʹ������ź�
						CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step1;
						break;

				case  PROCESS_Command_book_in_Step1:
					   door_NErunning_250times=4*60;
                       book_in_Running_250times = 4*10;				//���鴫�ʹ�����5s  ��Ϊ6s 
// 					   while(CloseStopDoorRun != 0)//||door_running_250times)		 //�ŵ�λֹͣ9.22
//                        {
//                            Positive_Door_run();
//                        }
                       Stop_Door_run();
                       send_string_com(init_report_s9);                     //�ϱ����ŵ�λ            
                       CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step2;
					   break;

				case  PROCESS_Command_book_in_Step2:
                       if((ReadSensor==0) && door_NErunning_250times )										//�����鵽��������� 
                       {                                           
                           //QuerySysDeviceState();
													 SysState=1;
													 door_NErunning_250times=4*60;
													 book_in_Running_250times = 4*8;
                           prog_direct_running();                                               //���ʹ���ת
                           CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step3;
                           break;
											 }
											 else if(door_NErunning_250times==0)
											 {                                               
																		 SysState=0;
														CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step6;
																		 break;
											 }
                       break;
				case  PROCESS_Command_book_in_Step3:
                       if(book_in_Running_250times) 
                       {
													 if((BoxSensor==1)&&(ReadSensor==1))  
													 {
											//	   CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step2;
											//	   Negative_Door_run();
															break;
													 }
													 else	if((BoxSensor==1)&&(ReadSensor==0))
													 {					
										//		   CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step5;
														 
														 
															break;
													 }
													 else	if((BoxSensor_on_times>5)&&(ReadSensor==1))		 //2014.12.29 ��������
													 {					
															 prog_stop_running();
															 CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step4;
															 //Negative_Door_run();
															 door_NErunning_250times=4*10;
															 break;
													 }
													 else if((BoxSensor==0)&&(ReadSensor==0))
													 {
															 prog_stop_running();
															 CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step5;
															 break;
													 }
													 break;
										 }
				
											else if(book_in_Running_250times==0)				//���鳬ʱ
										 {
												 SysState=0;
												 prog_stop_running();
												 if((BoxSensor==1)&&(ReadSensor==1))  
												 {
														 send_string_com(init_report_s133);		// 2014.8.11 �ϱ����鳬ʱ ˢ�½���
														 CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step2;
														 break;
												 }
												 else	if((BoxSensor==1)&&(ReadSensor==0))
												 {					
									//		   CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step5;
															break;
												 }
												 else	if((BoxSensor==0)&&(ReadSensor==1))
												 {					
														 CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step4;
														 Negative_Door_run();
														 door_NErunning_250times=4*10;
														 break;
												 }
												else if((BoxSensor==0)&&(ReadSensor==0))
												{
															CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step5;
															break;
												}
												break;
									 }
									 else
											break;                                   
                   break;
												
				 case  PROCESS_Command_book_in_Step4:	

// 				        if((OpenStopDoorRun==0))//||(!door_NErunning_250times))
// 						{
// 						    Stop_Door_run();
// 							send_string_com(init_report_s11);					 //�ϱ����ŵ�λ
// 						    CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step5;
// 							break;						
// 						}
// 						if(((EntrySensor==0 )||(SavftyEdag==0)||(ReadSensor==0))&& door_NErunning_250times)	  //������
// 						{
// 							Stop_Door_run();
// 							send_string_com(init_report_s21);		 //�ϱ������������
// 							delay(50);
// 							while(CloseStopDoorRun!=0)
// 							{
// 								Positive_Door_run();
// 						    }							
// 							Stop_Door_run();
// 							delay(50);
// 							break;
// 					    }
// 						else if(EntrySensor&&SavftyEdag&&ReadSensor&&door_NErunning_250times)		  //��������ϰ�������
// 						{
// 							Negative_Door_run();
// 							break;
// 						}
// 						else if(door_NErunning_250times==0)
// 						{
// 							Stop_Door_run();
// 							delay(10);
// 							CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step7;
// 							send_string_com(init_report_s12);			 //�ϱ�����ʧ��
// 							break;
// 						}	
						send_string_com(init_report_s11);					 //�ϱ����ŵ�λ
						    CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step5;
						break;
						
				  case  PROCESS_Command_book_in_Step5:				   
						if(ReadSensor==0)					//���ͼ���Ѿ����룬���Ƕ�����ǰ����⵽ͼ�飬��Ϊͼ�鳬������������
						{
							Stop_Door_run();
							BoxSensor_on_times = 0; 					//�趨Ϊ����ʧ��״̬
							CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step7;
							send_string_com(init_report_s20);		 //�����ϱ�ͼ�鳬��
							break;
						}
							
						else //if(BoxSensor_on_times > 0)									
						{
							
							
							RevolEnable = 0;
				    
				    
						
						
							send_string_com(init_report_s131);			//����ɹ�
							send_string_com(init_report_s131);
							CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step7;
							
							//prog_direct_running();
							
							//door_running_250times = 4*4;	
							
							break;
						}
// 						else
// 						{						    
// 							send_string_com(init_report_s132);						//2014.12.25   ����
// 							CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step7;
// 							break;
// 						}
					/*	else											//ԭ����ȡ���˳���ͼ���⣬�ϱ�����ʧ��
						{		
							send_string_com(init_report_s132);			//����ʧ��
						} */
				  case  PROCESS_Command_book_in_Step6:
// 						if((OpenStopDoorRun==0))//||(!door_NErunning_250times))
// 						{
// 						    Stop_Door_run();
// 							send_string_com(init_report_s11);					 //�ϱ����ŵ�λ
// 						    CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step7;
// 							break;						
// 						}
// 						if((EntrySensor==0 )||(SavftyEdag==0)||(ReadSensor==0))	  //������
// 						{
// 							Stop_Door_run();
// 							delay(50);
// 							while(CloseStopDoorRun!=0)
// 							{
// 								Positive_Door_run();
// 						    }							
// 							Stop_Door_run();
// 							delay(50);
// //                            Negative_Door_run();				  //������
// 							break;
// 					    }
// 						else if(EntrySensor&&SavftyEdag&&ReadSensor)		  //��������ϰ�������
// 						{
// 							Negative_Door_run();
// 							break;
// 						}	
						send_string_com(init_report_s11);					 //�ϱ����ŵ�λ
						    CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step7;
						break;

				  case  PROCESS_Command_book_in_Step7:
		
				    SysState=0;
					     
						SysModle = SystermIdle;
				  default:CURRENT_FATHER_PROCESS = PROCESS_Command_Idle;	//������ϣ�����ϵͳΪ����״̬
			   break;
			}
			break;
#pragma endregion 
	    
			
			#pragma region ��������
		case PROCESS_Command_End://����ָ��		
					switch(CURRENT_SON_PROCESS)
					{
        					case  PROCESS_Command_End_Step0:
                			        send_string_com(Re_close_drop);
                			        door_NErunning_250times = 4*4;
                				    book_out_Running_250times = 4*2;
                			  //      Negative_Door_run();
        	           //2014.8.1		prog_direct_running();
			                        CURRENT_SON_PROCESS = PROCESS_Command_End_Step1;
						            SysModle = SystermBussy;
//									conveyor_run = 1;						//���ʹ�ֹͣ�ź�
						          break;
								
        					case  PROCESS_Command_End_Step1:
//     						        if((OpenStopDoorRun == 0))// ||(!door_NErunning_250times))		
//     					  	      {
//     					  		        Stop_Door_run();
//     						//	        if(!door_NErunning_250times)			   //ȥ��ʱ���ж�
//     						//	        {
//     								        prog_stop_running();
// 														send_string_com(init_report_s11);				 //���ŵ�λ�ϱ�
//     								        CURRENT_SON_PROCESS = PROCESS_Command_End_Step2;
//     						//	        }
//     					 	        }
//     						        if((EntrySensor==0 )||(SavftyEdag==0)||(ReadSensor==0)||(door_NErunning_250times==0))		
//     						        {
// 														Stop_Door_run();
// 									//2014.8.1	        prog_stop_running();
// 														delay(50);
// 														while(CloseStopDoorRun!=0)
// 														{
// 															Positive_Door_run();
// 														}    							
// 														Stop_Door_run();
//     							     //   delay(50);
// 														delay_200msx(10);
// 														door_NErunning_250times=4*4;   							   								
//     						        }
// 												else if(EntrySensor && SavftyEdag && ReadSensor)
// 												{
// 														Negative_Door_run();
// 												}
												delay_200msx(5);
												prog_stop_running();
												send_string_com(init_report_s11);				 //���ŵ�λ�ϱ�
    								    CURRENT_SON_PROCESS = PROCESS_Command_End_Step2;
												break;

					        case PROCESS_Command_End_Step2:							
			                default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;	
						break;
								
					}
					break;
			#pragma endregion
			
			
			
			#pragma region �������
			
		case PROCESS_Command_book_out:
			switch(CURRENT_SON_PROCESS)
			{
				case  PROCESS_Command_book_out_Step0:
						send_string_com(Re_book_out);					//���������
				case  PROCESS_Command_book_out_StepF:		 
						book_out_Running_250times = 4*4;				//���鴫�ʹ�����5S
                       	door_NErunning_250times   = 4*4;					//����ʱ�����3��
				//	    Positive_Door_run();                 //����    2013.5.7	
										   
						prog_Reverse_running();
						ReadSensor_on_times = 0;
						CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step1;
						ReadSensor_on_timeout_250times = 4*60;			//���õȴ������ȴ�����ȡ��ʱ��Ϊ60��
						break;
				case  PROCESS_Command_book_out_Step1:
// 						if(CloseStopDoorRun == 0)//||!door_NErunning_250times)		 //�����볬ʱ�ж�
// 					  	{
// 					  		Stop_Door_run();
// 					 	}	
						if(book_out_Running_250times)
						{
							if(ReadSensor_on_times 	>= 10)				//������ǰ�����Ч�ź�10ms�˲�
							{
								CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step2;
							}
						}
						else
						{
							prog_stop_running();
							CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step2;	
						}
						break;
				case  PROCESS_Command_book_out_Step2:
				//		book_out_Running_250times_bake = book_out_Running_250times;
						if(book_out_Running_250times > 0)				//������˵�����ǰ�⣬�����1s��ʱ
							CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step9;			    //������ʱʱ��500����
						else
						{
						    send_string_com(init_report_s151);
							CURRENT_SON_PROCESS = PROCESS_Command_book_out_StepA;		   //���ػ�������
						    SysModle = SystermIdle;
						}	
						break;
				case  PROCESS_Command_book_out_Step3:
					    if(!book_out_Running_250times) 
					   	  CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step4;	
						break;
				case  PROCESS_Command_book_out_Step4:
					    prog_stop_running();		
					    QuerySysDeviceState();					   		//�ϱ����Ѿ������
					    ReadSensor_on_timeout_250times = 4*15;			//�˳��ĵ�һ����ȡ�߳�ʱʱ��
					    CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step5;	
					    break;
				case  PROCESS_Command_book_out_Step5:
					    if(ReadSensor_on_timeout_250times)			   //����ȴ�����ȡ�ߵ�һ����δ��ʱ�������ȴ�
					    {
						   if(ReadSensor == 1)				   //����ȡ�ߵ�һ���飬�����˵ڶ�����
								CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step6;	
					    }
					    else
					    {
						   CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step9;
						   door_NErunning_250times = 4*30;
					//	   ReadSensor_on_timeout_250times = 4*25;						
					    }
					    break;
				case  PROCESS_Command_book_out_Step6:
					    prog_Reverse_running();				//���ʹ���ת
					    ReadSensor_on_times = 0;
					    book_out_Running_250times = 4*3;    //book_out_Running_250times_bake;
					    CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step7;
					    break;
				case  PROCESS_Command_book_out_Step7:
					    if(book_out_Running_250times)  
					    {
						   if(ReadSensor_on_times 	>= 200)					//������ǰ�����Ч�ź�10ms�˲�
						   {
							  CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step8;
							  if(book_out_Running_250times > 0)			//������˵�����ǰ�⣬�����1s��ʱ
								book_out_Running_250times = 0;			//������ʱʱ��500����
						   }			
					    }
					    else
					    {
					  	   CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step8;
					    }					  
	 				    break;
				case  PROCESS_Command_book_out_Step8:
					  
					    if(!book_out_Running_250times)
					    {
						   CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step9;
						   ReadSensor_on_timeout_250times = 4*40;
						   door_NErunning_250times = 4*30;
						   prog_stop_running();						
					    }
					    break;
				case  PROCESS_Command_book_out_Step9:
						if(book_out_Running_250times==0)
						  prog_stop_running();
					    if((ReadSensor_on_times)&&(ReadSensor_on_timeout_250times))   
					  	//����ڶ������˵���ڻ��˳��ȴ�60��ȡ�鳬ʱ�����ɹ�
					    {
						   	break;
					    }
					    else if((ReadSensor_on_times)&&(ReadSensor_on_timeout_250times==0))
						{
							if(door_NErunning_250times)
							{
							    prog_Reverse_running();
							}
							else
							    prog_stop_running();
							break;
						}
						else if((ReadSensor_on_times==0)&&(ReadSensor_on_timeout_250times))
						{					  	
							prog_stop_running();
							send_string_com(init_report_s151);			//�ϱ�����ɹ�
						}
						else if((ReadSensor_on_times==0)&&(ReadSensor_on_timeout_250times==0))
						{
						    CURRENT_SON_PROCESS = PROCESS_Command_book_out_StepB;		 //����
							prog_stop_running();
							door_NErunning_250times = 4*4;
							break;
						}
						if(sys_timeout_flag)
						{
							sys_timeout_flag=0;
							CURRENT_SON_PROCESS = PROCESS_Command_book_out_StepB;
							break;
						}
						CURRENT_SON_PROCESS = PROCESS_Command_book_out_StepA;		   //���ػ�������
						SysModle = SystermIdle; 
						
				case  PROCESS_Command_book_out_StepA:				
			        	CURRENT_FATHER_PROCESS=PROCESS_Command_book_in;
			        	CURRENT_SON_PROCESS=PROCESS_Command_book_in_Step0;
						break;					
				//default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;	 //������ϣ�����ϵͳΪ����״̬
				case  PROCESS_Command_book_out_StepB:
// 						    if((OpenStopDoorRun==0))//||(!door_NErunning_250times))
// 						    {
// 						        Stop_Door_run();
// 						//		SysModle = SystermIdle;
// 								prog_stop_running();
// 							    send_string_com(init_report_s11);					 //�ϱ����ŵ�λ
// 								CURRENT_SON_PROCESS=PROCESS_Command_book_out_StepC;
// 						        break;						
// 						    }
// 						    if((EntrySensor==0 )||(SavftyEdag==0)||(ReadSensor==0)||(door_NErunning_250times==0))	  //������
// 						    {
// 							    Stop_Door_run();
// 							    delay(50);
// 							    while(CloseStopDoorRun!=0)
// 							    {
// 								    Positive_Door_run();
// 						        }							
// 							    Stop_Door_run();
// 							    delay_200msx(10);
// 								door_NErunning_250times = 4*4;
// 							    break;
// 					        }
// 						    else if(EntrySensor&&SavftyEdag&&ReadSensor)		  //��������ϰ�������
// 						    {
// 							    Negative_Door_run();
// 							    break;
// 						    }
					    if(ReadSensor_on_times >= 100)
							{							
									prog_stop_running();
									send_string_com(init_report_s11);					 //�ϱ����ŵ�λ
									CURRENT_SON_PROCESS=PROCESS_Command_book_out_StepC;
									break;
							}
						break;
				case  PROCESS_Command_book_out_StepC:
				        SysModle = SystermIdle;
				default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;
				      break;
			}
			break;
			#pragma endregion
			
			
			
			#pragma region �������
		case PROCESS_Command_book_drop:				
			switch(CURRENT_SON_PROCESS)
			{
				case    PROCESS_Command_book_drop_Step0:
//					while(HeigntSensor==0)
//					{
//					     ;
//					}

              
						V12_2=0;    //����Ƥ��
				       delay(1500);
					    V12_2=1;
						book_drop_Running_250times = 4*4;
						send_string_com(Re_book_drop);
						CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step1;
						
					  
						prog_book_drop_Return =  0x00;
						//conveyor_run = 0;       //������ˮ��
						break;
				case  	PROCESS_Command_book_drop_Step1:
						if((!prog_book_drop_Return)&&(book_drop_Running_250times))
						{
							if(CURRENT_GRANDSON_PROCESS == CURRENT_GRANDSON_PROCESS_step0)
							{
								prog_book_drop_kind = 0;
								if(BoxSensor_on_times != 0)
									prog_book_drop_kind |=BoxSignalON;
								if(ReadSensor_on_times != 0)
									prog_book_drop_kind |=ReaderSignalON;

							}		 
							switch(prog_book_drop_kind) 
							{		
								case ReaderSignalOFF|BoxSignalON:
									   switch(CURRENT_GRANDSON_PROCESS)
									   {
										   case CURRENT_GRANDSON_PROCESS_step0:
												  book_drop_Running_250times = 4*4;		//���鴫�ʹ�����4S
												  prog_direct_running();
												  CURRENT_GRANDSON_PROCESS = CURRENT_GRANDSON_PROCESS_step1;
												break;
										   case CURRENT_GRANDSON_PROCESS_step1:
												  if(book_drop_Running_250times)
												  {
													  if(BoxSensor_on_times == 0)
													  {
														  prog_book_drop_Return = 1;
														  CURRENT_GRANDSON_PROCESS = CURRENT_GRANDSON_PROCESS_step0;
													      CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step2;
														  break;
													  }
												  }
												  else
												  {
													  CURRENT_GRANDSON_PROCESS = CURRENT_GRANDSON_PROCESS_step0;	
												  }
												 break;
										   default: 
												  CURRENT_GRANDSON_PROCESS = CURRENT_GRANDSON_PROCESS_step0;	
												  break;
									   }
									   break;
								case ReaderSignalON|BoxSignalON:

											switch(CURRENT_GRANDSON_PROCESS)
											{
												  case CURRENT_GRANDSON_PROCESS_step0:
												  		book_drop_Running_250times = 4*4;		//���鴫�ʹ�����2S
														prog_direct_running();
														CURRENT_GRANDSON_PROCESS = CURRENT_GRANDSON_PROCESS_step1;
	
														break;
												  case CURRENT_GRANDSON_PROCESS_step1:
												  		if(book_drop_Running_250times)
														{
															if(BoxSensor_on_times == 0)
															{
																prog_book_drop_Return 	= 1;
																RevolEnable 			= 1;
															    CURRENT_GRANDSON_PROCESS = CURRENT_GRANDSON_PROCESS_step0;
																CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step2;

																break;
															}
														}
														else
														{
															CURRENT_GRANDSON_PROCESS = CURRENT_GRANDSON_PROCESS_step0;
	
														}
												  		break;
												  default: 
												  		CURRENT_GRANDSON_PROCESS = CURRENT_GRANDSON_PROCESS_step0;	
												  		break;
											}
											break;
								case ReaderSignalON|BoxSignalOFF:
								case ReaderSignalOFF|BoxSignalOFF:	

									 		prog_direct_running();										
								default:	CURRENT_GRANDSON_PROCESS = CURRENT_GRANDSON_PROCESS_step0;
	
											break;
							}
						}
						else
							CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step2;
						break;

				case  PROCESS_Command_book_drop_Step2:
						while(BoxSensor==0)
						{
							prog_direct_running();
						}
						delay(10);
		//2014.8.1				Positive_Door_run();
// 						while(BoxSensor==0)
// 						{
// 							prog_direct_running();
// 						}
						delay(200);								//����������ȥ���ͽ�ʱ��ӳ�
						delay(200);							//��ʱȡ����ʱ				
						delay(200);
						delay(200);
						delay(200);
						conveyor_run = 1;       //ֹͣ��ˮ��
						door_NErunning_250times = 4*4;
						prog_stop_running();
					//	delay_200msx(7);   //�ӳ�1.4�����ϱ�����ɹ�	 �����������ȥ��
			//			Positive_Door_run();
						send_string_com(init_report_s141); 		 //�ϱ�����ɹ�
						send_string_com(init_report_s141);
						send_string_com(init_report_s141);
			//			Positive_Door_run();	   //2014.8.1
// 						while(CloseStopDoorRun != 0)//&&(door_NErunning_250times))					   //2013.12.16 ||->&&
// 					  	{
// 					  		Positive_Door_run();	
// 					 	}
// 						Stop_Door_run();
//						send_string_com(init_report_s9);					 //�ϱ����ŵ�λ	   
						if(RevolEnable == 1)
						{
							CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step3;	//�ع��������������鴦��
						}
						else
						    CURRENT_FATHER_PROCESS=PROCESS_Command_book_in;
						CURRENT_SON_PROCESS=PROCESS_Command_book_in_Step0;

						//CURRENT_SON_PROCESS = PROCESS_Command_book_drop_End;
						break;
				/*����ع���*/
				case  PROCESS_Command_book_drop_Step3:
						book_drop_Running_250times = 4*5;							//���鴫�ʹ�����5S
						prog_Reverse_running();
						//Light_red_on();
						door_NErunning_250times = 4*2;
// 						Negative_Door_run();
// 						if(OpenStopDoorRun == 0)//||!door_NErunning_250times)					   //�ŵ�λֹͣ9.22
// 					  	{
// 					  	    Stop_Door_run();
// 							send_string_com(init_report_s11);                 //�ϱ����ŵ�λ
// 					 	}
// 						else if(door_NErunning_250times==0)
// 						{
// 							Stop_Door_run();
// 							send_string_com(init_report_s12);                 //�ϱ����ų�ʱ
// 						}
						send_string_com(init_report_s11);                 //�ϱ����ŵ�λ
						ReadSensor_on_times = 0;
						CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step4;	
						break;
				case  PROCESS_Command_book_drop_Step4:
						if(book_drop_Running_250times)  
						{
							if(ReadSensor_on_times 	>= 10)					      	//������ǰ�����Ч�ź�10ms�˲�
							{
								CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step5;	
							}			
						}
						else
							CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step5;	
					    break;
				case  PROCESS_Command_book_drop_Step5:
						book_drop_Running_250times_bake = book_drop_Running_250times;
						if(book_drop_Running_250times > 0)							//������˵�����ǰ�⣬�����1s��ʱ							book_drop_Running_250times = 2;							//������ʱʱ��500����
						    CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step6;
						break;
				case  PROCESS_Command_book_drop_Step6:
					    if(!book_drop_Running_250times)
					    {
							prog_stop_running();		
							QuerySysDeviceState();
							CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step7;
					    }
					   break;
				case  PROCESS_Command_book_drop_Step7:
					    if(!ReadSensor_on_times)
					    {
							prog_Reverse_running();
							//Light_red_on();
							door_NErunning_250times = 4*3;
							Negative_Door_run();
							if(OpenStopDoorRun == 0)//||!door_NErunning_250times)					   //door 9.22
					  		{
					  			 Stop_Door_run();
								 send_string_com(init_report_s11);			  //�ϱ����Ž���
					 		}
							else if(door_NErunning_250times==0)
							{
								 Stop_Door_run();
								 send_string_com(init_report_s12);			 //�ϱ����ų�ʱ
							}		
							ReadSensor_on_times = 0;
							book_drop_Running_250times = book_drop_Running_250times_bake;
							CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step8;
					    } 
					  break;
				case  PROCESS_Command_book_drop_Step8:
						if(book_drop_Running_250times)  
						{
							if(ReadSensor_on_times 	>= 10)							//������ǰ�����Ч�ź�10ms�˲�
							{
								CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step9;	
							}			
						}
						else
							CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step9;					
					  break;
				case  PROCESS_Command_book_drop_Step9:
					    if(book_drop_Running_250times > 0)							//������˵�����ǰ�⣬�����1s��ʱ
						    book_drop_Running_250times = 2;								//������ʱʱ��500����
					    CURRENT_SON_PROCESS = PROCESS_Command_book_drop_StepA;	
					    break;
				case  PROCESS_Command_book_drop_StepA:
					    if(book_drop_Running_250times)
					    {
						    break;
					    }
					    else
						    CURRENT_SON_PROCESS = PROCESS_Command_book_drop_End;					
					    prog_stop_running();
				case  PROCESS_Command_book_drop_End:
					    SysModle = SystermIdle;						  					
				default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle; 		//������ϣ�����ϵͳΪ����״̬
						door_NErunning_250times = 4*2;
// 				 	 	Negative_Door_run();
// 						if(OpenStopDoorRun == 0||!door_NErunning_250times)					   //door 9.22
// 					  	{
// 					  		Stop_Door_run();
// 					    }		
						break;
			}
			break;
			
			#pragma endregion
		
		case  PROCESS_Command_Idle:
		//		conveyor_run = 1;
// 				if(OpenStopDoorRun == 0)//||!door_NErunning_250times)					   //door 9.22
// 			    {
// 					Stop_Door_run();
// 		//			send_string_com(init_report_s11);
// 				}
// 				else if(door_NErunning_250times==0)
// 				{
// 					Stop_Door_run();
// 		//			send_string_com(init_report_s12);
// 				}
		default: break;
	}
}

#pragma endregion
#pragma region ���ڽ���
void ReceiveDateProcess(void)
{
	uchar   i,i_BSP = CE_OK;
	uint crcTemp1,crcTemp2;
	if(RecvState == RecvStateEnd)
	{
		system_waiting_250times=4*60;		 //2014.8.12 ϵͳ���еȴ�ʱ��
		for(i=0;i<0x0B;i++)                                      		//ת�����ݣ��������ݴ�������з���������ײ
		{                                                                    
			InBuff[i]=SerialInbuff[i];                              	//�����ջ�����������ת�Ʊ���   
			SerialInbuff[i]=0;                                      	//���ջ���������                                                               
		}
		RecvState=RecvStateIdle;									   	//���ݴ�����ϣ����Խ���������
		if((InBuff[10]!=0x03)||(InBuff[1]!=0x08))           		    //changed by zhanglei 03-26
		{                                                               //�ж����ݵĽ�β�ͳ���        												
			i_BSP =  CE_NOCOMM;                                         //ͨѶ���ݴ���ͷ,β,���ȴ�           
		}
		else
		{	
			crcbuf_In[0]=InBuff[2];         							//ȡ������
			crcbuf_In[1]=InBuff[3];    									//RSP
			crcbuf_In[2]=InBuff[4];    									//PARAMETER1 |
			crcbuf_In[3]=InBuff[5];    									//PARAMETER2 |   ����  
			crcbuf_In[4]=InBuff[6];    									//PARAMETER3 |
			crcbuf_In[5]=InBuff[7];    									//PARAMETER4 |
			EA=0;					   									//CRC��������У����ݽ�ֹ�жϲ���				  
			crcTemp1=CRC3(crcbuf_In, 6);           						//��У�������ݴ��� crcTemp1, crcbuf_In��Ϊcrcbuf_In[6]������׵�ַ������ &(crcbuf_In[6])
			crcTemp2=InBuff[8];                    						//crcУ����ĸ߰�λ    
			crcTemp2=crcTemp2<<8;										//��ȡcrcTemp2��8λ
			crcTemp2|=InBuff[9];                   						//��ȡcrcTemp2��8λ���ϲ���16λ
			EA=1;                      									//���ж� 
			if(crcTemp1!=crcTemp2)    	           						//��У�������ݺͽ��յ���У�������Ƚ�
			{                  											 
				i_BSP =  CE_CHECKERROR;                                 //У�����
			}
		}
		if(i_BSP == CE_OK)
		{
			//RD_command = InBuff[2];									//������
			//RD_command_Hpara1  = InBuff[4]; 						    //��ȡ����Я���Ĳ���HPARA_H	
			//RD_command_Hpara2  = InBuff[5] ;						    //��ȡ����Я���Ĳ���HPARA_L
			//RD_command_Lpara1  = InBuff[6] ; 						    //��ȡ����Я���Ĳ���LPARA_H
			//RD_command_Lpara2  = InBuff[7] ; 						    //��ȡ����Я���Ĳ���LPARA_L
			host_command(InBuff[2],InBuff[4],InBuff[5]);//�����,����������ȫ�ֱ����������βε���
		}
		else
		{
			send_string_err(i_BSP); 									//����ͨѶ������Ϣ
		}
	}	
//   RD_command = Command_Idle;											//�������Ĵ���
//	RD_command_Hpara1  = 0; 
//	RD_command_Hpara2  = 0 ;
//	RD_command_Lpara1  = 0 ; 
//	RD_command_Lpara2  = 0 ; 
	for(i=0;i<0x0B;i++)                                      			//ת�����ݣ��������ݴ���������µ�����
	{                                                                    
		InBuff[i]=0;                              						//�����ݱ������Ϊ0                                                                
	}
}	
#pragma endregion

#pragma region ��������
void host_command(unsigned char RD_command,unsigned char RD_command_Hpara1,unsigned char RD_command_Hpara2)
{
	
	switch(RD_command)
	{
		case Command_reset:	
			{	
			//	if(CURRENT_FATHER_PROCESS !=  PROCESS_Command_Idle)
			//		send_string_err(CE_EXECUTE); 
			//	else
			//	{	
					CURRENT_FATHER_PROCESS 	= PROCESS_Command_reset ;	
					CURRENT_SON_PROCESS	= PROCESS_Command_reset_Step0;
					CURRENT_GRANDSON_PROCESS= CURRENT_GRANDSON_PROCESS_step0;
					TCounter250 					= 0;	//250���������
//					TCounter8 						= 0;	//8���������
//					Time8ms_flag 					= 0;	//8�����־
					Time250ms_flag					= 0;    //250��?					TCounter250						= 0;
//					TCounter8						= 0;
//					Time8ms_flag					= 0;
//					Time250ms_flag 					= 0;
					EntrySensor_on_times  			= 0;
					ReadSensor_on_times   			= 0;
					ReadSensor_on_timeout_250times  = 0;
					BoxSensor_on_times				= 0;
					prog_reset_250times 			= 0;
					book_in_Running_250times  		= 0;
					book_out_Running_250times 		= 0;
			//		book_out_Running_250times_bake 	= 0;
					book_drop_Running_250times		= 0;
					book_drop_Running_250times_bake	= 0;
			//		book_stop_running_250tims 		= 0;			
				}								
		//	}
			break;	
			
		case Command_book_action:													//���ʹ�����������ݲ����ֱ�����ϸ�ֶ���
		{	
			if((RD_command_Hpara1 == 0x02)&&(RD_command_Hpara2 == 0x02)) 	/* ���� */
			{
		  		if((BoxSensor==1)&&(SysState==0))
				{
				    CURRENT_FATHER_PROCESS 	=  PROCESS_Command_End;
				    CURRENT_SON_PROCESS	=  PROCESS_Command_End_Step0;
				}
				else
					send_string_err(CE_EXECUTE);       					
			}
			else if((CURRENT_FATHER_PROCESS != PROCESS_Command_Idle))
				send_string_err(CE_EXECUTE); 
			else
			{	
				if((RD_command_Hpara1 == 0x01)&&(RD_command_Hpara2 == 0x01))		/* ���� */				
				{	
					CURRENT_FATHER_PROCESS 	=   PROCESS_Command_book_in ;
					CURRENT_SON_PROCESS	=   PROCESS_Command_book_in_Step0;	 					
				}
				else if((RD_command_Hpara1 == 0x01)&&(RD_command_Hpara2 == 0x02))	/* ���� */
				{
					CURRENT_FATHER_PROCESS 	=  PROCESS_Command_book_out   ;
					CURRENT_SON_PROCESS	=  PROCESS_Command_book_out_Step0;									
				}
				else if((RD_command_Hpara1 == 0x02)&&(RD_command_Hpara2 == 0x01)) 	/* ���� */
				{
		  			CURRENT_FATHER_PROCESS 	=  PROCESS_Command_book_drop ;
					CURRENT_SON_PROCESS	=  PROCESS_Command_book_drop_Step0;	
					CURRENT_GRANDSON_PROCESS=  CURRENT_GRANDSON_PROCESS_step0;	 					
				}
				else if((RD_command_Hpara1 == 0x03)&&(RD_command_Hpara2 == 0x01)) 	/* ���ʹ���ת */
				{
		  			CURRENT_FATHER_PROCESS 	=  PROCESS_Command_prog_direct ;
					CURRENT_SON_PROCESS	=  PROCESS_Command_prog_direct_Step0;		 					
				}
				else if((RD_command_Hpara1 == 0x03)&&(RD_command_Hpara2 == 0x02)) 	/* ���ʹ���ת */
				{
		  			CURRENT_FATHER_PROCESS 	=  PROCESS_Command_prog_reverse ;
					CURRENT_SON_PROCESS	=  PROCESS_Command_prog_reverse_Step0;		 					
				}
				else if((RD_command_Hpara1 == 0x03)&&(RD_command_Hpara2 == 0x03)) 	/* ���ʹ�ֹͣ */
				{
		  			CURRENT_FATHER_PROCESS 	=  PROCESS_Command_prog_stop ;
					CURRENT_SON_PROCESS	=  PROCESS_Command_prog_stop_Step0;		 					
				}
				/*else if((RD_command_Hpara1 == 0x02)&&(RD_command_Hpara2 == 0x02)) 	/* ���� */
				/*{
		  			CURRENT_FATHER_PROCESS 	=  PROCESS_Command_End;
					CURRENT_SON_PROCESS		=  PROCESS_Command_End_Step0;					
				}*/
				else
					send_string_err(CE_BADPARAM);	   								//���������������
			}
			break;
		}
		//////////////////////////////////////////////////////////////////////
		case Command_cleck_state:		
				prog_cleck_state();			/* ����Ļ״̬�����͸�PC*/
				break;
		case Command_check_vison:		
				prog_check_vison();			/* ��ѯ�汾��*/
				break;
		default:   
				send_string_err(CE_BADCOMMAND);										//�����������
				break;
	}
}
#pragma endregion
// prog_check_vison--------------------------------------
void prog_cleck_state()
{
	char i_Senser,j_Senser;	
	send_string_com(Re_che_state);
																
	i_Senser = P0;							//ȡP0.0~P0.3��״̬
	i_Senser &= 0x0F;
	i_Senser = 0x0F - i_Senser;
	j_Senser = P2;							//ȡP2.4~P2.7��״̬
//	j_Senser = ~j_Senser;
	j_Senser &= 0xE0;
	if(j_Senser == 0xE0)
	{
		delay_1msx(80);							//���󱨴��� �����ڵ� �ټ��һ��  80mm��Ҫ100ms
		i_Senser = P0;							//ȡP0.0~P0.3��״̬
	    i_Senser &= 0x0F;
    	i_Senser = 0x0F - i_Senser;
	    j_Senser = P2;							//ȡP2.4~P2.7��״̬
//	    j_Senser = ~j_Senser;
	    j_Senser &= 0xE0;
	}
	j_Senser = 0xE0 - j_Senser;														//ͨѶ����������ʱ
	i_Senser = (j_Senser | i_Senser);
	prog_check_state_report(i_Senser);
		
}

void prog_check_state_report(unsigned char i_Senser)				  				//��ѯָ��ع�Ļ״̬
{
	unsigned char *i_str;
	if(i_Senser==0x00)
	{
		Re_data_erro[4] = i_Senser;
		Re_data_erro[5] = 0x01;
		i_str = Re_data_erro;
	}
	else
	{
	    Re_data_erro[4] = i_Senser;
		Re_data_erro[5] = 0x00;
	    i_str = Re_data_erro;
	}

	send_string_com(i_str);	
}
void prog_init_report(unsigned char i_Senser)						//�����ϱ���Ļ״̬
{
	unsigned char *i_str;
	switch(i_Senser&0x0F)
	{
		case  0x00:	i_str = init_report_s0   ;break;
		case  0x01:	i_str = init_report_s1	 ;break;
		case  0x02:	i_str = init_report_s2	 ;break;
		case  0x03:	i_str = init_report_s3	 ;break;
		case  0x04:	i_str = init_report_s4	 ;break;
		case  0x05:	i_str = init_report_s5	 ;break;
		case  0x06:	i_str = init_report_s6	 ;break;
		case  0x07:	i_str = init_report_s7	 ;break;
		case  0x08:	i_str = init_report_s8	 ;break;
//		case  0x09:	i_str = init_report_s9	 ;break;
//		case  0x0A:	i_str = init_report_s10  ;break;
//		case  0x0B:	i_str = init_report_s11  ;break;
//		case  0x0C:	i_str = init_report_s12  ;break;
//		case  0x0D:	i_str = init_report_s13  ;break;
//		case  0x0E:	i_str = init_report_s14  ;break;
//		case  0x0F:	i_str = init_report_s15  ;break;
		default :	i_str = init_report_s30  ;break;
	}
	send_string_com(i_str);	
}

// prog_check_vison--------------------------------------
void prog_check_vison()
{
	;//send_string_com(Re_check_vison);
}
// initiative_report--------------------------------------
#pragma region �豸״̬
void QuerySysDeviceState(void)  						//�豸�Զ���ѯ�豸״̬���ϱ�
{							
	uchar temp;     									//����һ����ʱ���� 
    
	temp  = SysDeviceState&0x0F;  				    	//�����ϴδ�������״̬��temp
	
	SysDeviceState=0X00;        						//��ǰ״̬���㣬�Ա����²�ѯ״̬
	
	if(EntrySensor_on_times >= EnterSensor_signal_on)   //�ж���ڹ�Ļ������
	   SysDeviceState = SysDeviceState|EnterSensorFlag; //��ȡ��ڹ�Ļ״̬
	
	if(ReadSensor_on_times 	>= ReadSensor_signal_on)    //�ж϶�����ǰһ����Ļ
	   SysDeviceState = SysDeviceState|ReadSensorFlag; 	//��ȡ������ǰ״̬
	
	if(BoxSensor_on_times 	>= BoxSensor_signal_on)     //�ж������Ļ���
	   SysDeviceState = SysDeviceState|BoxSensorFlag;	//��ȡ�����Ļ״̬

    if(temp != (SysDeviceState&0x0F))              		//���ձȽϵ�ǰ��Ļ״̬���ϴι�Ļ״̬�Ƿ����仯 
    {  
		prog_init_report(SysDeviceState&0x0F);   		//�б仯���ϱ���ǰ״̬ 
    }                            						//�ޱ仯��״̬���ϱ�	                                                    
} 
#pragma endregion
void delay(uint num)
{
 uchar i;
 while(num--)
 for(i=110;i>0;i--);
}
	