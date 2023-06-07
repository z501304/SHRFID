//------------------------------------------------------------
//描述：24小时自助还书机控制板程序-改为馆员还书口
//修改时间：2018年6月
//
//------------------------------------------------------------
#include "include.h"
void QuerySysDeviceState(void);
unsigned char SysDeviceState = 0;
unsigned char SysModle = SystermIdle;

void main()
{
	SysModle = SystermBussy;
  system_initiate();			/* 端口初始化 */
	SysModle  = SystermIdle;  
	RecvState = RecvStateIdle;
	REN 	  = 1; 	
	while(1)
	{		
		if(system_waiting_250times==0)   //2014.8.12
		{
			system_waiting_250times=4*60;
			if(BoxSensor_on_times>=250)					 //2014.12.29 防抖处理
			{
			  sys_timeout_flag=1;
//				conveyor_run = 1;
				CURRENT_FATHER_PROCESS 	=  PROCESS_Command_book_out;
			  CURRENT_SON_PROCESS	=  PROCESS_Command_book_out_StepF;
			}
		}  
		ReceiveDateProcess();  		//通讯数据解析
		SystermProcess();			//系统命令多线程（时间片处理）处理
	    if(SysModle == SystermIdle)	//空闲状态下，系统传感器状态主动上报
		{  
		    QuerySysDeviceState();	//查询系统状态
		}

	}
}
////////////////////////////////////////////////////////////////////////
//名称：Timer0Interrupt(void) interrupt 1 using 1
//功能：定时器0 1ms中断
//入口参数：无
//出口参数：无
//系统影响：TL0 ，TH0						     定时器计数初始值
////////////////////////////////////////////////////////////////////////
void Timer0Interrupt(void) interrupt 1 using 1
{
	TL0  = 0xCC;                               	//重用赋初值
	TH0 = 0xF8;                               	//(2^16-0XF8CC)*12/22.1184MHz=1MS

/*	if(OpenStopDoorRun == 0)					   //门到位停止9.22
	{
		 Stop_Door_run();
	}	*/

	if(EntrySensor == signal_on)
	{
		if(EntrySensor_on_times <=250)	 
			EntrySensor_on_times++;
	}
	else
		EntrySensor_on_times = 0;	

	if(ReadSensor == signal_on)
	{
		if(ReadSensor_on_times <=250)	 
			ReadSensor_on_times++;
	}
	else
		ReadSensor_on_times = 0;
	if(BoxSensor == signal_on)
	{
		if(BoxSensor_on_times <=250)	 
			BoxSensor_on_times++;
	}
	else
		BoxSensor_on_times = 0;
 
	TCounter250++;	                           			//250ms 计数器                  

	if(TCounter250>=250)		  						  //250ms 计数器
    {													        //250ms 定时到
		Time250ms_flag = 1;
		TCounter250 = 0;
		if(prog_reset_250times)							 //复位时间
			prog_reset_250times--;						 
		if(book_in_Running_250times)					 //入书时间
			book_in_Running_250times--;
		if(book_out_Running_250times)					 //退书时间
			book_out_Running_250times--;
		if(book_drop_Running_250times)					 //入箱时间
			book_drop_Running_250times--;
//		if(book_stop_running_250tims)					  //停止滚动时间
//			book_stop_running_250tims--;
		if(book_drop_Running_250times)					   //？？？
			book_drop_Running_250times--;
		if(ReadSensor_on_timeout_250times)				  //设置等待退书后等待读者取书时间为60秒
			ReadSensor_on_timeout_250times--;
		if(door_running_250times)
			door_running_250times--;
		if(door_NErunning_250times)
			door_NErunning_250times--;
		if(system_waiting_250times)
			system_waiting_250times--;
	}	
}