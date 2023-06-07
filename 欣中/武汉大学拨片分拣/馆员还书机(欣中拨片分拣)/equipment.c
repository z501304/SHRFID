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
//复位命令反馈
code char Re_reset[]	 	= {0x82,0x08,0x21,0x00,0x00,0x00,0x00,0x00,0xA6,0xE3,0x83};  
//入书命令反馈 
code char Re_book_in[]  	= {0x82,0x08,0x22,0x00,0x01,0x01,0x00,0x00,0xBC,0xA9,0x83}; 
//退书命令反馈 
code char Re_book_out[]  	= {0x82,0x08,0x22,0x00,0x01,0x02,0x00,0x00,0xD8,0x46,0x83};
//入箱命令反馈  
code char Re_book_drop[]  	= {0x82,0x08,0x22,0x00,0x02,0x01,0x00,0x00,0x71,0x8C,0x83};
//结束命令
code char Re_close_drop[]   = {0x82,0x08,0x22,0x00,0x02,0x02,0x00,0x00,0x15,0x63,0x83}; 
//固件版本查询返回
//code char Re_check_vison[]  = {0x82,0x08,0x40,0x00,version_H,version_L,0x00,0x00,0xDE,0xAB,0x83};// //1.1
//传送带张转
code char Re_prog_direct[]  = {0x82,0x08,0x22,0x00,0x03,0x01,0x00,0x00,0x71,0x8C,0x83};
//传送带反转
code char Re_prog_reverse[] = {0x82,0x08,0x22,0x00,0x03,0x02,0x00,0x00,0x71,0x8C,0x83};
//传送带停止
code char Re_prog_stop[]  	= {0x82,0x08,0x22,0x00,0x03,0x03,0x00,0x00,0x71,0x8C,0x83};

//主动上报返回
code char init_report_s0[]		= {0x82,0x08,0x23,0x00,0x00,0x00,0x00,0x00,0x4B,0xf7,0x83};	  //全部清除
code char init_report_s1[]		= {0x82,0x08,0x23,0x00,0x01,0x00,0x00,0x00,0x4B,0xf7,0x83};	  //1号光幕被遮挡
code char init_report_s2[]		= {0x82,0x08,0x23,0x00,0x02,0x00,0x00,0x00,0x86,0xD2,0x83};	  //2号光幕被遮挡
code char init_report_s3[]		= {0x82,0x08,0x23,0x00,0x03,0x00,0x00,0x00,0x3D,0xCE,0x83};	  //3号光幕被遮挡
code char init_report_s4[]		= {0x82,0x08,0x23,0x00,0x04,0x00,0x00,0x00,0x1C,0x99,0x83};	  //4号光幕被遮挡
code char init_report_s5[]		= {0x82,0x08,0x23,0x00,0x05,0x00,0x00,0x00,0xA7,0x85,0x83};	  //1号光幕被清除
code char init_report_s6[]		= {0x82,0x08,0x23,0x00,0x06,0x00,0x00,0x00,0x6A,0xA0,0x83};	  //2号光幕被清除
code char init_report_s7[]		= {0x82,0x08,0x23,0x00,0x07,0x00,0x00,0x00,0xD1,0xBC,0x83};	  //3号光幕被清除
code char init_report_s8[]		= {0x82,0x08,0x23,0x00,0x08,0x00,0x00,0x00,0x28,0x0E,0x83};	  //4号光幕被清除
code char init_report_s9[]		= {0x82,0x08,0x23,0x00,0x09,0x00,0x00,0x00,0x93,0x12,0x83};	  //开门到位
code char init_report_s10[]		= {0x82,0x08,0x23,0x00,0x0a,0x00,0x00,0x00,0x5E,0x37,0x83};	  //开门超时
code char init_report_s11[]		= {0x82,0x08,0x23,0x00,0x0b,0x00,0x00,0x00,0xE5,0x2B,0x83};	  //关门到位
code char init_report_s12[]		= {0x82,0x08,0x23,0x00,0x0c,0x00,0x00,0x00,0xC4,0x7C,0x83};	  //关门超时
code char init_report_s13[]		= {0x82,0x08,0x23,0x00,0x0d,0x00,0x00,0x00,0xA3,0x3A,0x83};  
code char init_report_s14[]		= {0x82,0x08,0x23,0x00,0x0e,0x00,0x00,0x00,0x0A,0xF0,0x83};
code char init_report_s15[]		= {0x82,0x08,0x23,0x00,0x0f,0x00,0x00,0x00,0x09,0x59,0x83};
code char init_report_s17[]		= {0x82,0x08,0x23,0x00,0x11,0x01,0x00,0x00,0xA3,0x3A,0x83};  //传送带正转
code char init_report_s18[]		= {0x82,0x08,0x23,0x00,0x11,0x02,0x00,0x00,0x0A,0xF0,0x83};	 //传送带反转
code char init_report_s19[]		= {0x82,0x08,0x23,0x00,0x11,0x03,0x00,0x00,0x09,0x59,0x83};	 //传送带停止
code char init_report_s20[]		= {0x82,0x08,0x23,0x00,0x12,0x00,0x00,0x00,0x00,0x00,0x83};	 //图书超长
code char init_report_s21[]		= {0x82,0x08,0x23,0x00,0x13,0x00,0x00,0x00,0x00,0x00,0x83};	 //还书口有异物
code char init_report_s30[]		= {0x82,0x08,0x23,0x00,0xee,0x00,0x00,0x00,0x00,0x00,0x83};	 //传感器状态不明

code char init_report_s121[]	= {0x82,0x08,0x23,0x00,0x0c,0x01,0x00,0x00,0xC4,0x7C,0x83};  //结束放书 

code char init_report_s131[]	= {0x82,0x08,0x23,0x00,0x0d,0x01,0x00,0x00,0xA3,0x3A,0x83};  // 入书成功
code char init_report_s132[]	= {0x82,0x08,0x23,0x00,0x0d,0x02,0x00,0x00,0xC7,0xD5,0x83};  // 入书失败
code char init_report_s133[]	= {0x82,0x08,0x23,0x00,0x0d,0x03,0x00,0x00,0xC7,0xD5,0x83};  // 入书超时
code char init_report_s141[]	= {0x82,0x08,0x23,0x00,0x0e,0x01,0x00,0x00,0x6E,0x1F,0x83};	 // 入箱成功
code char init_report_s142[]	= {0x82,0x08,0x23,0x00,0x0e,0x02,0x00,0x00,0x0A,0xF0,0x83};	 // 入箱失败
code char init_report_s151[]	= {0x82,0x08,0x23,0x00,0x0f,0x01,0x00,0x00,0x09,0x59,0x83};	 //	退书成功
code char init_report_s152[]	= {0x82,0x08,0x23,0x00,0x0f,0x02,0x00,0x00,0x51,0x28,0x83};	 // 退书失败
code char init_report_s16[]		= {0X82,0X08,0X23,0X00,0X10,0X00,0X00,0X00,0x00,0x00,0X83};	 // 复位成功
//状态查询返回
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

void prog_direct_running()    		//还书机皮带正转
{
	doorlock_c1 = control_off;
	doorlock_c2 = control_on;
}
void prog_Reverse_running()    		//还书机皮带反转
{
	doorlock_c1 = control_on;
	doorlock_c2 = control_off;
}
void prog_stop_running()    											     //停止
{	
	doorlock_c1 = control_off;
	doorlock_c2 = control_off;
	delay_1msx(100);
//	book_stop_running_250tims = 2;
//	while(book_stop_running_250tims) ;									   //停止后，暂停500ms，避免出现点击正反装，暂停之间切换过快问题损伤电机
}
/*void Light_red_on()													        //红色指示灯亮，绿色指示灯灭
{
	light_red     = control_on;
	light_green = control_off;
}

void Light_green_on()													//绿色指示灯亮，红色指示灯灭
{
	light_red     = control_off;
	light_green = control_on;
}

void Light_off()															//红色绿色指示灯都灭
{
	light_red     = control_off;
	light_green = control_off;
}*/

void Positive_Door_run()			//开门
{
//	  delay(800);									//2012.11.28
	  GND_1 = 0;
	  V12_1 = 0;
	  GND_2 = 1;
	  V12_2 = 1;

}

void Negative_Door_run()		   //关门
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
//名称：uint CRC3(unsigned char *ptr, uchar  i_len)
//功能：计算指定数据循环冗余校验码
//入口参数：ptr     指定数据块首地址
//          i_len   指定数据块长度
//出口参数：crc     指定数据的校验码
//系统影响：无
///////////////////////////////////////////////////////////////////////
#pragma region CRC校验
uint CRC3(unsigned char *ptr, uchar  i_len)
{
	uint CRC_POLYNOM = 0x8408;     										//polynome [数]多项式(的)
	uint CRC_PRESET  = 0xFFFF;
	uint crc = CRC_PRESET;
	uchar i,j;
	for(i=0;i< i_len;i++)
	{
		crc^=*ptr;            											        // ^ 异或操作 crc = crc ^ (*ptr) = 0xFFFF ^(*ptr)
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
#pragma endregion											  							//采用时间片方式模拟多线程处理，

#pragma region 进程处理			
															//可以在避免执行时间较长的命令动作期间相应系统命令，可以避免上位机呆机
void SystermProcess(void)
{
    uchar flag = 0;
    switch(CURRENT_FATHER_PROCESS)
	{
	    #pragma region 复位操作
	  
		case PROCESS_Command_reset : 									
			switch(CURRENT_SON_PROCESS)
			{
				case  PROCESS_Command_reset_Step0:
					  send_string_com(Re_reset);						//上报复位命令接收到
					  prog_direct_running();							//传送带正转
					  
					  //Positive_Door_run();							//开门  ，电机和入口处接近开关链接相反	，2013.5.7 ，杨海峰
					  prog_reset_250times = 4*4;						//电机转动时间5秒
					  door_running_250times = 4*4;					//关门时间界限3秒
					  CURRENT_SON_PROCESS 	= PROCESS_Command_reset_Step1;
					  SysModle = SystermBussy;
					  //break;
				case  PROCESS_Command_reset_Step1:
									 
// 					  if((CloseStopDoorRun == 0)||(!door_running_250times))			//门到位停止9.22
// 					  {
// 					  	 Stop_Door_run();
// 						// send_string_com(init_report_s9);		   //上报开门到位
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
						//Negative_Door_run();																			                           //开门时间界限5秒
// 						while((OpenStopDoorRun == 0))//||(!door_NErunning_250times))				 //门到位停止9.22
// 					  	{
// 					  		 Stop_Door_run();
// 							// send_string_com(init_report_s11);					     //上报关门到位
// 							 send_string_com(init_report_s16);						 //上报复位完毕，设备处于空闲状态
// 							 CURRENT_SON_PROCESS = PROCESS_Command_reset_Step3;
// 							 SysModle = SystermIdle;
// 							 break;
// 					 	}
							send_string_com(init_report_s16);						 //上报复位完毕，设备处于空闲状态
							CURRENT_SON_PROCESS = PROCESS_Command_reset_Step3;
							SysModle = SystermIdle;
							 break;
// 						if((!EntrySensor )||(!SavftyEdag))	//如果在该处判断有遮挡物就只发信息告知?						
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
// 						 else if(EntrySensor&&SavftyEdag)		  //入书口无障碍，关门
// 						 {
// 							Negative_Door_run();
// 						 } 
						
					break;
					
				default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;	//复位完毕，设置系统为空闲状态
						break;
			}
			break;
			#pragma endregion
	
		  
			#pragma region 传送带正转
		case PROCESS_Command_prog_direct : 									
			switch(CURRENT_SON_PROCESS)
			{
				case  PROCESS_Command_prog_direct_Step0:
					  send_string_com(Re_prog_direct);					//上报传送带正转指令收到
					  prog_direct_running();							//传送带正转
					  send_string_com(init_report_s17);					//上报传送带正转
					  prog_reset_250times = 4*60;						//电机转动时间60秒
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
				default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;	//设置系统为空闲状态					
						break;
			}
			break;
			#pragma endregion
		
		  
			#pragma region 传送带反转
			
		case PROCESS_Command_prog_reverse : 									
			switch(CURRENT_SON_PROCESS)
			{
				case  PROCESS_Command_prog_reverse_Step0:
					  send_string_com(Re_prog_reverse);					//上报传送带正转指令收到
					  prog_Reverse_running();							//传送带反转
					  send_string_com(init_report_s18);					//上报传送带反转
					  prog_reset_250times = 4*60;						//电机转动时间60秒
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
				default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;	//设置系统为空闲状态					
						break;
			}
			break;
			#pragma endregion
			
			
			#pragma region 传送带停止
		case PROCESS_Command_prog_stop : 									
			switch(CURRENT_SON_PROCESS)
			{
				case  PROCESS_Command_prog_stop_Step0:
					  send_string_com(Re_prog_stop);					//上报传送带正转指令收到
					  SysModle = SystermBussy;
					  prog_stop_running();
					  send_string_com(init_report_s19);					//上报传送带停止
					  SysModle = SystermIdle;							//传送带反转	
				default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;	//设置系统为空闲状态					
						break;
			}
			break;
			#pragma endregion
		  
			
			#pragma region 入书操作
		case PROCESS_Command_book_in:
			switch(CURRENT_SON_PROCESS)
			{  
				case  PROCESS_Command_book_in_Step0:
						send_string_com(Re_book_in);
						door_running_250times = 4*4;	        //关门界限为3秒	2013.5.7
				//		Positive_Door_run();
						BoxSensor_on_times = 0; 				//入箱传感器初始化
            SysModle = SystermBussy;
//						conveyor_run = 0;						//传送带启动信号
						CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step1;
						break;

				case  PROCESS_Command_book_in_Step1:
					   door_NErunning_250times=4*60;
                       book_in_Running_250times = 4*10;				//入书传送带正传5s  改为6s 
// 					   while(CloseStopDoorRun != 0)//||door_running_250times)		 //门到位停止9.22
//                        {
//                            Positive_Door_run();
//                        }
                       Stop_Door_run();
                       send_string_com(init_report_s9);                     //上报开门到位            
                       CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step2;
					   break;

				case  PROCESS_Command_book_in_Step2:
                       if((ReadSensor==0) && door_NErunning_250times )										//如果检查到有物体放入 
                       {                                           
                           //QuerySysDeviceState();
													 SysState=1;
													 door_NErunning_250times=4*60;
													 book_in_Running_250times = 4*8;
                           prog_direct_running();                                               //传送带正转
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
													 else	if((BoxSensor_on_times>5)&&(ReadSensor==1))		 //2014.12.29 防抖处理
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
				
											else if(book_in_Running_250times==0)				//入书超时
										 {
												 SysState=0;
												 prog_stop_running();
												 if((BoxSensor==1)&&(ReadSensor==1))  
												 {
														 send_string_com(init_report_s133);		// 2014.8.11 上报入书超时 刷新界面
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
// 							send_string_com(init_report_s11);					 //上报关门到位
// 						    CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step5;
// 							break;						
// 						}
// 						if(((EntrySensor==0 )||(SavftyEdag==0)||(ReadSensor==0))&& door_NErunning_250times)	  //防夹手
// 						{
// 							Stop_Door_run();
// 							send_string_com(init_report_s21);		 //上报还书口有异物
// 							delay(50);
// 							while(CloseStopDoorRun!=0)
// 							{
// 								Positive_Door_run();
// 						    }							
// 							Stop_Door_run();
// 							delay(50);
// 							break;
// 					    }
// 						else if(EntrySensor&&SavftyEdag&&ReadSensor&&door_NErunning_250times)		  //入书口无障碍，关门
// 						{
// 							Negative_Door_run();
// 							break;
// 						}
// 						else if(door_NErunning_250times==0)
// 						{
// 							Stop_Door_run();
// 							delay(10);
// 							CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step7;
// 							send_string_com(init_report_s12);			 //上报关门失败
// 							break;
// 						}	
						send_string_com(init_report_s11);					 //上报关门到位
						    CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step5;
						break;
						
				  case  PROCESS_Command_book_in_Step5:				   
						if(ReadSensor==0)					//如果图书已经进入，但是读卡器前光电检测到图书，认为图书超长或连续放书
						{
							Stop_Door_run();
							BoxSensor_on_times = 0; 					//设定为入书失败状态
							CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step7;
							send_string_com(init_report_s20);		 //主动上报图书超长
							break;
						}
							
						else //if(BoxSensor_on_times > 0)									
						{
							
							
							RevolEnable = 0;
				    
				    
						
						
							send_string_com(init_report_s131);			//入书成功
							send_string_com(init_report_s131);
							CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step7;
							
							//prog_direct_running();
							
							//door_running_250times = 4*4;	
							
							break;
						}
// 						else
// 						{						    
// 							send_string_com(init_report_s132);						//2014.12.25   增加
// 							CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step7;
// 							break;
// 						}
					/*	else											//原程序取消了超长图书检测，上报入书失败
						{		
							send_string_com(init_report_s132);			//入书失败
						} */
				  case  PROCESS_Command_book_in_Step6:
// 						if((OpenStopDoorRun==0))//||(!door_NErunning_250times))
// 						{
// 						    Stop_Door_run();
// 							send_string_com(init_report_s11);					 //上报关门到位
// 						    CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step7;
// 							break;						
// 						}
// 						if((EntrySensor==0 )||(SavftyEdag==0)||(ReadSensor==0))	  //防夹手
// 						{
// 							Stop_Door_run();
// 							delay(50);
// 							while(CloseStopDoorRun!=0)
// 							{
// 								Positive_Door_run();
// 						    }							
// 							Stop_Door_run();
// 							delay(50);
// //                            Negative_Door_run();				  //不关门
// 							break;
// 					    }
// 						else if(EntrySensor&&SavftyEdag&&ReadSensor)		  //入书口无障碍，关门
// 						{
// 							Negative_Door_run();
// 							break;
// 						}	
						send_string_com(init_report_s11);					 //上报关门到位
						    CURRENT_SON_PROCESS = PROCESS_Command_book_in_Step7;
						break;

				  case  PROCESS_Command_book_in_Step7:
		
				    SysState=0;
					     
						SysModle = SystermIdle;
				  default:CURRENT_FATHER_PROCESS = PROCESS_Command_Idle;	//入书完毕，设置系统为空闲状态
			   break;
			}
			break;
#pragma endregion 
	    
			
			#pragma region 结束命令
		case PROCESS_Command_End://结束指令		
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
//									conveyor_run = 1;						//传送带停止信号
						          break;
								
        					case  PROCESS_Command_End_Step1:
//     						        if((OpenStopDoorRun == 0))// ||(!door_NErunning_250times))		
//     					  	      {
//     					  		        Stop_Door_run();
//     						//	        if(!door_NErunning_250times)			   //去掉时限判断
//     						//	        {
//     								        prog_stop_running();
// 														send_string_com(init_report_s11);				 //关门到位上报
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
												send_string_com(init_report_s11);				 //关门到位上报
    								    CURRENT_SON_PROCESS = PROCESS_Command_End_Step2;
												break;

					        case PROCESS_Command_End_Step2:							
			                default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;	
						break;
								
					}
					break;
			#pragma endregion
			
			
			
			#pragma region 退书操作
			
		case PROCESS_Command_book_out:
			switch(CURRENT_SON_PROCESS)
			{
				case  PROCESS_Command_book_out_Step0:
						send_string_com(Re_book_out);					//退书命令反馈
				case  PROCESS_Command_book_out_StepF:		 
						book_out_Running_250times = 4*4;				//退书传送带正传5S
                       	door_NErunning_250times   = 4*4;					//开门时间界限3秒
				//	    Positive_Door_run();                 //开门    2013.5.7	
										   
						prog_Reverse_running();
						ReadSensor_on_times = 0;
						CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step1;
						ReadSensor_on_timeout_250times = 4*60;			//设置等待退书后等待读者取书时间为60秒
						break;
				case  PROCESS_Command_book_out_Step1:
// 						if(CloseStopDoorRun == 0)//||!door_NErunning_250times)		 //不加入超时判断
// 					  	{
// 					  		Stop_Door_run();
// 					 	}	
						if(book_out_Running_250times)
						{
							if(ReadSensor_on_times 	>= 10)				//检查读卡前光电有效信号10ms滤波
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
						if(book_out_Running_250times > 0)				//如果书退到读卡前光，则继续1s延时
							CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step9;			    //退书延时时间500毫秒
						else
						{
						    send_string_com(init_report_s151);
							CURRENT_SON_PROCESS = PROCESS_Command_book_out_StepA;		   //返回还书流程
						    SysModle = SystermIdle;
						}	
						break;
				case  PROCESS_Command_book_out_Step3:
					    if(!book_out_Running_250times) 
					   	  CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step4;	
						break;
				case  PROCESS_Command_book_out_Step4:
					    prog_stop_running();		
					    QuerySysDeviceState();					   		//上报书已经到入口
					    ReadSensor_on_timeout_250times = 4*15;			//退出的第一本书取走超时时限
					    CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step5;	
					    break;
				case  PROCESS_Command_book_out_Step5:
					    if(ReadSensor_on_timeout_250times)			   //如果等待读者取走第一本书未超时，继续等待
					    {
						   if(ReadSensor == 1)				   //读者取走第一本书，继续退第二本书
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
					    prog_Reverse_running();				//传送带反转
					    ReadSensor_on_times = 0;
					    book_out_Running_250times = 4*3;    //book_out_Running_250times_bake;
					    CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step7;
					    break;
				case  PROCESS_Command_book_out_Step7:
					    if(book_out_Running_250times)  
					    {
						   if(ReadSensor_on_times 	>= 200)					//检查读卡前光电有效信号10ms滤波
						   {
							  CURRENT_SON_PROCESS = PROCESS_Command_book_out_Step8;
							  if(book_out_Running_250times > 0)			//如果书退到读卡前光，则继续1s延时
								book_out_Running_250times = 0;			//退书延时时间500毫秒
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
					  	//如果第二本书退到入口或退出等待60秒取书超时，报成功
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
							send_string_com(init_report_s151);			//上报退书成功
						}
						else if((ReadSensor_on_times==0)&&(ReadSensor_on_timeout_250times==0))
						{
						    CURRENT_SON_PROCESS = PROCESS_Command_book_out_StepB;		 //关门
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
						CURRENT_SON_PROCESS = PROCESS_Command_book_out_StepA;		   //返回还书流程
						SysModle = SystermIdle; 
						
				case  PROCESS_Command_book_out_StepA:				
			        	CURRENT_FATHER_PROCESS=PROCESS_Command_book_in;
			        	CURRENT_SON_PROCESS=PROCESS_Command_book_in_Step0;
						break;					
				//default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle;	 //退书完毕，设置系统为空闲状态
				case  PROCESS_Command_book_out_StepB:
// 						    if((OpenStopDoorRun==0))//||(!door_NErunning_250times))
// 						    {
// 						        Stop_Door_run();
// 						//		SysModle = SystermIdle;
// 								prog_stop_running();
// 							    send_string_com(init_report_s11);					 //上报关门到位
// 								CURRENT_SON_PROCESS=PROCESS_Command_book_out_StepC;
// 						        break;						
// 						    }
// 						    if((EntrySensor==0 )||(SavftyEdag==0)||(ReadSensor==0)||(door_NErunning_250times==0))	  //防夹手
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
// 						    else if(EntrySensor&&SavftyEdag&&ReadSensor)		  //入书口无障碍，关门
// 						    {
// 							    Negative_Door_run();
// 							    break;
// 						    }
					    if(ReadSensor_on_times >= 100)
							{							
									prog_stop_running();
									send_string_com(init_report_s11);					 //上报关门到位
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
			
			
			
			#pragma region 入箱操作
		case PROCESS_Command_book_drop:				
			switch(CURRENT_SON_PROCESS)
			{
				case    PROCESS_Command_book_drop_Step0:
//					while(HeigntSensor==0)
//					{
//					     ;
//					}

              
						V12_2=0;    //启动皮带
				       delay(1500);
					    V12_2=1;
						book_drop_Running_250times = 4*4;
						send_string_com(Re_book_drop);
						CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step1;
						
					  
						prog_book_drop_Return =  0x00;
						//conveyor_run = 0;       //启动流水线
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
												  book_drop_Running_250times = 4*4;		//入书传送带正传4S
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
												  		book_drop_Running_250times = 4*4;		//入书传送带正传2S
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
						delay(200);								//如果书掉不下去，就将时间加长
						delay(200);							//暂时取消延时				
						delay(200);
						delay(200);
						delay(200);
						conveyor_run = 1;       //停止流水线
						door_NErunning_250times = 4*4;
						prog_stop_running();
					//	delay_200msx(7);   //延迟1.4秒再上报入箱成功	 如果不合适再去掉
			//			Positive_Door_run();
						send_string_com(init_report_s141); 		 //上报入箱成功
						send_string_com(init_report_s141);
						send_string_com(init_report_s141);
			//			Positive_Door_run();	   //2014.8.1
// 						while(CloseStopDoorRun != 0)//&&(door_NErunning_250times))					   //2013.12.16 ||->&&
// 					  	{
// 					  		Positive_Door_run();	
// 					 	}
// 						Stop_Door_run();
//						send_string_com(init_report_s9);					 //上报开门到位	   
						if(RevolEnable == 1)
						{
							CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step3;	//回滚处理，区别与退书处理
						}
						else
						    CURRENT_FATHER_PROCESS=PROCESS_Command_book_in;
						CURRENT_SON_PROCESS=PROCESS_Command_book_in_Step0;

						//CURRENT_SON_PROCESS = PROCESS_Command_book_drop_End;
						break;
				/*入书回滚处*/
				case  PROCESS_Command_book_drop_Step3:
						book_drop_Running_250times = 4*5;							//退书传送带正传5S
						prog_Reverse_running();
						//Light_red_on();
						door_NErunning_250times = 4*2;
// 						Negative_Door_run();
// 						if(OpenStopDoorRun == 0)//||!door_NErunning_250times)					   //门到位停止9.22
// 					  	{
// 					  	    Stop_Door_run();
// 							send_string_com(init_report_s11);                 //上报关门到位
// 					 	}
// 						else if(door_NErunning_250times==0)
// 						{
// 							Stop_Door_run();
// 							send_string_com(init_report_s12);                 //上报关门超时
// 						}
						send_string_com(init_report_s11);                 //上报关门到位
						ReadSensor_on_times = 0;
						CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step4;	
						break;
				case  PROCESS_Command_book_drop_Step4:
						if(book_drop_Running_250times)  
						{
							if(ReadSensor_on_times 	>= 10)					      	//检查读卡前光电有效信号10ms滤波
							{
								CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step5;	
							}			
						}
						else
							CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step5;	
					    break;
				case  PROCESS_Command_book_drop_Step5:
						book_drop_Running_250times_bake = book_drop_Running_250times;
						if(book_drop_Running_250times > 0)							//如果书退到读卡前光，则继续1s延时							book_drop_Running_250times = 2;							//退书延时时间500毫秒
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
								 send_string_com(init_report_s11);			  //上报关门结束
					 		}
							else if(door_NErunning_250times==0)
							{
								 Stop_Door_run();
								 send_string_com(init_report_s12);			 //上报关门超时
							}		
							ReadSensor_on_times = 0;
							book_drop_Running_250times = book_drop_Running_250times_bake;
							CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step8;
					    } 
					  break;
				case  PROCESS_Command_book_drop_Step8:
						if(book_drop_Running_250times)  
						{
							if(ReadSensor_on_times 	>= 10)							//检查读卡前光电有效信号10ms滤波
							{
								CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step9;	
							}			
						}
						else
							CURRENT_SON_PROCESS = PROCESS_Command_book_drop_Step9;					
					  break;
				case  PROCESS_Command_book_drop_Step9:
					    if(book_drop_Running_250times > 0)							//如果书退到读卡前光，则继续1s延时
						    book_drop_Running_250times = 2;								//退书延时时间500毫秒
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
				default:CURRENT_FATHER_PROCESS =  PROCESS_Command_Idle; 		//入箱完毕，设置系统为空闲状态
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
#pragma region 串口接收
void ReceiveDateProcess(void)
{
	uchar   i,i_BSP = CE_OK;
	uint crcTemp1,crcTemp2;
	if(RecvState == RecvStateEnd)
	{
		system_waiting_250times=4*60;		 //2014.8.12 系统空闲等待时间
		for(i=0;i<0x0B;i++)                                      		//转移数据，避免数据处理过程中发生数据碰撞
		{                                                                    
			InBuff[i]=SerialInbuff[i];                              	//将接收缓冲区的数据转移备份   
			SerialInbuff[i]=0;                                      	//接收缓冲区清零                                                               
		}
		RecvState=RecvStateIdle;									   	//数据处理完毕，可以接收新命令
		if((InBuff[10]!=0x03)||(InBuff[1]!=0x08))           		    //changed by zhanglei 03-26
		{                                                               //判断数据的结尾和长度        												
			i_BSP =  CE_NOCOMM;                                         //通讯数据错误（头,尾,长度错）           
		}
		else
		{	
			crcbuf_In[0]=InBuff[2];         							//取命令码
			crcbuf_In[1]=InBuff[3];    									//RSP
			crcbuf_In[2]=InBuff[4];    									//PARAMETER1 |
			crcbuf_In[3]=InBuff[5];    									//PARAMETER2 |   参数  
			crcbuf_In[4]=InBuff[6];    									//PARAMETER3 |
			crcbuf_In[5]=InBuff[7];    									//PARAMETER4 |
			EA=0;					   									//CRC计算过程中，短暂禁止中断产生				  
			crcTemp1=CRC3(crcbuf_In, 6);           						//将校验后的数据存入 crcTemp1, crcbuf_In作为crcbuf_In[6]数组的首地址，或用 &(crcbuf_In[6])
			crcTemp2=InBuff[8];                    						//crc校验码的高八位    
			crcTemp2=crcTemp2<<8;										//获取crcTemp2高8位
			crcTemp2|=InBuff[9];                   						//获取crcTemp2低8位，合并成16位
			EA=1;                      									//打开中断 
			if(crcTemp1!=crcTemp2)    	           						//将校验后的数据和接收到的校验码作比较
			{                  											 
				i_BSP =  CE_CHECKERROR;                                 //校验码错
			}
		}
		if(i_BSP == CE_OK)
		{
			//RD_command = InBuff[2];									//主命令
			//RD_command_Hpara1  = InBuff[4]; 						    //获取命令携带的参数HPARA_H	
			//RD_command_Hpara2  = InBuff[5] ;						    //获取命令携带的参数HPARA_L
			//RD_command_Lpara1  = InBuff[6] ; 						    //获取命令携带的参数LPARA_H
			//RD_command_Lpara2  = InBuff[7] ; 						    //获取命令携带的参数LPARA_L
			host_command(InBuff[2],InBuff[4],InBuff[5]);//命令处理,尽量避免用全局变量，采用形参导入
		}
		else
		{
			send_string_err(i_BSP); 									//发送通讯错误信息
		}
	}	
//   RD_command = Command_Idle;											//清空命令寄存器
//	RD_command_Hpara1  = 0; 
//	RD_command_Hpara2  = 0 ;
//	RD_command_Lpara1  = 0 ; 
//	RD_command_Lpara2  = 0 ; 
	for(i=0;i<0x0B;i++)                                      			//转移数据，避免数据处理过程中新的数据
	{                                                                    
		InBuff[i]=0;                              						//将数据备份清空为0                                                                
	}
}	
#pragma endregion

#pragma region 主机命令
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
					TCounter250 					= 0;	//250毫秒计数器
//					TCounter8 						= 0;	//8毫秒计数器
//					Time8ms_flag 					= 0;	//8毫秒标志
					Time250ms_flag					= 0;    //250岭?					TCounter250						= 0;
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
			
		case Command_book_action:													//传送带运行命令，根据参数分别具体的细分动作
		{	
			if((RD_command_Hpara1 == 0x02)&&(RD_command_Hpara2 == 0x02)) 	/* 结束 */
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
				if((RD_command_Hpara1 == 0x01)&&(RD_command_Hpara2 == 0x01))		/* 入书 */				
				{	
					CURRENT_FATHER_PROCESS 	=   PROCESS_Command_book_in ;
					CURRENT_SON_PROCESS	=   PROCESS_Command_book_in_Step0;	 					
				}
				else if((RD_command_Hpara1 == 0x01)&&(RD_command_Hpara2 == 0x02))	/* 退书 */
				{
					CURRENT_FATHER_PROCESS 	=  PROCESS_Command_book_out   ;
					CURRENT_SON_PROCESS	=  PROCESS_Command_book_out_Step0;									
				}
				else if((RD_command_Hpara1 == 0x02)&&(RD_command_Hpara2 == 0x01)) 	/* 入箱 */
				{
		  			CURRENT_FATHER_PROCESS 	=  PROCESS_Command_book_drop ;
					CURRENT_SON_PROCESS	=  PROCESS_Command_book_drop_Step0;	
					CURRENT_GRANDSON_PROCESS=  CURRENT_GRANDSON_PROCESS_step0;	 					
				}
				else if((RD_command_Hpara1 == 0x03)&&(RD_command_Hpara2 == 0x01)) 	/* 传送带正转 */
				{
		  			CURRENT_FATHER_PROCESS 	=  PROCESS_Command_prog_direct ;
					CURRENT_SON_PROCESS	=  PROCESS_Command_prog_direct_Step0;		 					
				}
				else if((RD_command_Hpara1 == 0x03)&&(RD_command_Hpara2 == 0x02)) 	/* 传送带反转 */
				{
		  			CURRENT_FATHER_PROCESS 	=  PROCESS_Command_prog_reverse ;
					CURRENT_SON_PROCESS	=  PROCESS_Command_prog_reverse_Step0;		 					
				}
				else if((RD_command_Hpara1 == 0x03)&&(RD_command_Hpara2 == 0x03)) 	/* 传送带停止 */
				{
		  			CURRENT_FATHER_PROCESS 	=  PROCESS_Command_prog_stop ;
					CURRENT_SON_PROCESS	=  PROCESS_Command_prog_stop_Step0;		 					
				}
				/*else if((RD_command_Hpara1 == 0x02)&&(RD_command_Hpara2 == 0x02)) 	/* 结束 */
				/*{
		  			CURRENT_FATHER_PROCESS 	=  PROCESS_Command_End;
					CURRENT_SON_PROCESS		=  PROCESS_Command_End_Step0;					
				}*/
				else
					send_string_err(CE_BADPARAM);	   								//发送命令参数错误
			}
			break;
		}
		//////////////////////////////////////////////////////////////////////
		case Command_cleck_state:		
				prog_cleck_state();			/* 检查光幕状态并发送给PC*/
				break;
		case Command_check_vison:		
				prog_check_vison();			/* 查询版本号*/
				break;
		default:   
				send_string_err(CE_BADCOMMAND);										//发送命令错误
				break;
	}
}
#pragma endregion
// prog_check_vison--------------------------------------
void prog_cleck_state()
{
	char i_Senser,j_Senser;	
	send_string_com(Re_che_state);
																
	i_Senser = P0;							//取P0.0~P0.3的状态
	i_Senser &= 0x0F;
	i_Senser = 0x0F - i_Senser;
	j_Senser = P2;							//取P2.4~P2.7的状态
//	j_Senser = ~j_Senser;
	j_Senser &= 0xE0;
	if(j_Senser == 0xE0)
	{
		delay_1msx(80);							//防误报处理 如无遮挡 再检测一次  80mm需要100ms
		i_Senser = P0;							//取P0.0~P0.3的状态
	    i_Senser &= 0x0F;
    	i_Senser = 0x0F - i_Senser;
	    j_Senser = P2;							//取P2.4~P2.7的状态
//	    j_Senser = ~j_Senser;
	    j_Senser &= 0xE0;
	}
	j_Senser = 0xE0 - j_Senser;														//通讯返回无需延时
	i_Senser = (j_Senser | i_Senser);
	prog_check_state_report(i_Senser);
		
}

void prog_check_state_report(unsigned char i_Senser)				  				//查询指令返回光幕状态
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
void prog_init_report(unsigned char i_Senser)						//主动上报光幕状态
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
#pragma region 设备状态
void QuerySysDeviceState(void)  						//设备自动查询设备状态并上报
{							
	uchar temp;     									//定义一个临时变量 
    
	temp  = SysDeviceState&0x0F;  				    	//备份上次传感器的状态到temp
	
	SysDeviceState=0X00;        						//当前状态清零，以便重新查询状态
	
	if(EntrySensor_on_times >= EnterSensor_signal_on)   //判断入口光幕有物体
	   SysDeviceState = SysDeviceState|EnterSensorFlag; //获取入口光幕状态
	
	if(ReadSensor_on_times 	>= ReadSensor_signal_on)    //判断读卡器前一道光幕
	   SysDeviceState = SysDeviceState|ReadSensorFlag; 	//获取读卡器前状态
	
	if(BoxSensor_on_times 	>= BoxSensor_signal_on)     //判断入箱光幕检测
	   SysDeviceState = SysDeviceState|BoxSensorFlag;	//获取入箱光幕状态

    if(temp != (SysDeviceState&0x0F))              		//最终比较当前光幕状态与上次光幕状态是否发生变化 
    {  
		prog_init_report(SysDeviceState&0x0F);   		//有变化，上报当前状态 
    }                            						//无变化，状态不上报	                                                    
} 
#pragma endregion
void delay(uint num)
{
 uchar i;
 while(num--)
 for(i=110;i>0;i--);
}
	