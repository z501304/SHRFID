#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#define    POWER            150    //原来值250
#define    BoardNum         0      //设备编号(从0开始)
#define    Time             1

#define    HAVE_BOOK        0
#define    NO_BOOK          1
#define    REACH            0

#define    IN_1        		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)
#define    IN_2       		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)
#define    IN_3        		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)
#define    IN_4        		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)
#define    IN_5        		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)
//#define    IN_6        		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)
//#define    IN_7        		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)
//#define    IN_8        		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)
//#define    IN_9        		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)
//#define    IN_10      		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)
//#define    IN_11      		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)
//#define    IN_12      		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)


#define    OUT1_OFF        GPIO_SetBits(GPIOC,GPIO_Pin_0)
#define    OUT1_ON          GPIO_ResetBits(GPIOC,GPIO_Pin_0)
#define    OUT2_OFF        GPIO_SetBits(GPIOC,GPIO_Pin_1)
#define    OUT2_ON          GPIO_ResetBits(GPIOC,GPIO_Pin_1)
#define    OUT3_OFF        GPIO_SetBits(GPIOC,GPIO_Pin_2)
#define    OUT3_ON          GPIO_ResetBits(GPIOC,GPIO_Pin_2)
#define    OUT4_OFF        GPIO_SetBits(GPIOC,GPIO_Pin_3)
#define    OUT4_ON          GPIO_ResetBits(GPIOC,GPIO_Pin_3)
#define    OUT5_OFF        GPIO_SetBits(GPIOC,GPIO_Pin_4)
#define    OUT5_ON          GPIO_ResetBits(GPIOC,GPIO_Pin_4)
#define    OUT6_OFF        GPIO_SetBits(GPIOC,GPIO_Pin_5)
#define    OUT6_ON          GPIO_ResetBits(GPIOC,GPIO_Pin_5)
#define    OUT7_OFF        GPIO_SetBits(GPIOC,GPIO_Pin_6)
#define    OUT7_ON          GPIO_ResetBits(GPIOC,GPIO_Pin_6)
#define    OUT8_OFF        GPIO_SetBits(GPIOC,GPIO_Pin_7)
#define    OUT8_ON          GPIO_ResetBits(GPIOC,GPIO_Pin_7)
#define    OUT9_OFF        GPIO_SetBits(GPIOC,GPIO_Pin_8)
#define    OUT9_ON          GPIO_ResetBits(GPIOC,GPIO_Pin_8)
#define    OUT10_OFF       GPIO_SetBits(GPIOC,GPIO_Pin_9)
#define    OUT10_ON         GPIO_ResetBits(GPIOC,GPIO_Pin_9)



u8  UHF[] = {0x5a,0x55,0x06,0x00,0x0d,0x06,0x00,0xc8,0x6a,0x69//获取SN操作指令
             ,0x5a,0x55,0x06,0x00,0x0d,0x03,0x00,0xc5,0x6a,0x69//中断操作指令
             ,0x5a,0x55,0x08,0x00,0x0d,0x03,0x50,0x01,0x02,0x1a,0x6a,0x69//寄存器读取指令
             ,0x5a,0x55,0x0c,0x00,0x0d,0x02,0x50,0x01,0x02,0x12,0x02,0x00,0x00,0x31,0x6a,0x69//寄存器写入指令//无反回值
             ,0x5a,0x55,0x08,0x00,0x0d,0x03,0x50,0x05,0x00,0x1c,0x6a,0x69//寄存器读取指令
             ,0x5a,0x55,0x08,0x00,0x0d,0x03,0x50,0x00,0x07,0x1e,0x6a,0x69//寄存器读取指令
             ,0x5a,0x55,0x07,0x00,0x0d,0x1b,0x00,0x00,0xde,0x6a,0x69//获取天线状态指令
             ,0x5a,0x55,0x07,0x00,0x0d,0x19,0x00,0x00,0xdc,0x6a,0x69//获取天线配置指令
             ,0x5a,0x55,0x0c,0x00,0x0d,0x1c,0x00,0x00,0x2c,0x01,0x00,0x00,0x00,0x11,0x6a,0x69//获取天线驻波比指令
             ,0x5a,0x55,0x07,0x00,0x0d,0x19,0x00,0x00,0xdc,0x6a,0x69//获取天线配置指令
             ,0x5a,0x55,0x08,0x00,0x0d,0x1a,0x00,0x00,0x01,0xdf,0x6a,0x69//设置天线状态指令
             ,0x5a,0x55,0x13,0x00,0x0d,0x18,0x00,0x00,0x2c,0x01,0x00,0x00,0xc8,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0xde,0x6a,0x69//设置天线配置指令


//,0x5a,0x55,0x08,0x00,0x0d,0x1a,0x00,0x01,0x01,0xe0,0x6a,0x69//设置天线状态指//2
//,0x5a,0x55,0x13,0x00,0x0d,0x18,0x00,0x01,0x2c,0x01,0x00,0x00,0xc8,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0xdf,0x6a,0x69//设置天线配置指令//2

//,0x5a,0x55,0x08,0x00,0x0d,0x1a,0x00,0x02,0x01,0xe1,0x6a,0x69//设置天线状态指//3
//,0x5a,0x55,0x13,0x00,0x0d,0x18,0x00,0x02,0x2c,0x01,0x00,0x00,0xc8,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0xe0,0x6a,0x69//设置天线配置指令//3

//,0x5a,0x55,0x08,0x00,0x0d,0x1a,0x00,0x03,0x01,0xe2,0x6a,0x69//设置天线状态指//4
//,0x5a,0x55,0x13,0x00,0x0d,0x18,0x00,0x03,0x2c,0x01,0x00,0x00,0xc8,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0xe1,0x6a,0x69//设置天线配置指令//4



             ,0x5A,0x55,0x0C,0x00,0x0D,0x02,0x50,0x00,0x07,0xFF,0xFF,0x00,0x00,0x1F,0x6A,0x69//寄存器读取指令
             ,0x5A,0x55,0x06,0x00,0x0D,0x20,0x00,0xE2,0x6A,0x69//获取会话信息指令
             ,0x5A,0x55,0x07,0x00,0x0D,0x1F,0x00,0x00,0xE2,0x6A,0x69//设置会话指令
             ,0x5A,0x55,0x0E,0x00,0x0D,0x21,0x00,0x01,0x04,0x00,0x01,0x03,0x00,0x0F,0x04,0x07,0x6A,0x69//设置单化标签算法指令
             ,0x5A,0x55,0x07,0x00,0x0D,0x1E,0x00,0x01,0xE2,0x6A,0x69//设置link profile配置信息指令
             ,0x5A,0x55,0x08,0x00,0x0D,0x03,0x50,0x00,0x00,0x17,0x6A,0x69//寄存器读取指令
             ,0x5A,0x55,0x07,0x00,0x0D,0x1B,0x00,0x00,0xDE,0x6A,0x69//获取天线状态指令
             ,0x5A,0x55,0x07,0x00,0x0D,0x19,0x00,0x00,0xDC,0x6A,0x69//获取天线配置指令
             ,0x5A,0x55,0x0C,0x00,0x0D,0x1C,0x00,0x00,0x2C,0x01,0x00,0x00,0x00,0x11,0x6A,0x69//获取天线驻波比指令
             ,0x5A,0x55,0x07,0x00,0x0D,0x1B,0x00,0x01,0xDF,0x6A,0x69//获取天线状态指令
             ,0x5A,0x55,0x07,0x00,0x0D,0x19,0x00,0x01,0xDD,0x6A,0x69//获取天线配置指令
             ,0x5A,0x55,0x0C,0x00,0x0D,0x1C,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0xE5,0x6A,0x69//获取天线驻波比指令
             ,0x5A,0x55,0x07,0x00,0x0D,0x1B,0x00,0x02,0xE0,0x6A,0x69//获取天线状态指令
             ,0x5A,0x55,0x07,0x00,0x0D,0x19,0x00,0x02,0xDE,0x6A,0x69//获取天线配置指令
             ,0x5A,0x55,0x0C,0x00,0x0D,0x1C,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0xE6,0x6A,0x69//获取天线驻波比指令
             ,0x5A,0x55,0x07,0x00,0x0D,0x1B,0x00,0x03,0xE1,0x6A,0x69//获取天线状态指令
             ,0x5A,0x55,0x07,0x00,0x0D,0x19,0x00,0x03,0xDF,0x6A,0x69//获取天线配置指令
             ,0x5A,0x55,0x0C,0x00,0x0D,0x1C,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0xE7,0x6A,0x69// 获取天线驻波比指令
             ,0x5A,0x55,0x06,0x00,0x0D,0x1D,0x00,0xDF,0x6A,0x69//获取linkprofile配置信息指令
             ,0x5A,0x55,0x08,0x00,0x0D,0x03,0x50,0x00,0x07,0x1E,0x6A,0x69//寄存器读取指令
             ,0x5A,0x55,0x06,0x00,0x0D,0x20,0x00,0xE2,0x6A,0x69//获取会话信息指令
             ,0x5A,0x55,0x06,0x00,0x0D,0x25,0x00,0xE7,0x6A,0x69// 获取mask设置指令
             ,0x5A,0x55,0x06,0x00,0x0D,0x22,0x00,0xE4,0x6A,0x69//获取单位化标签算法指令
             ,0x00
            };

volatile  unsigned char   RecvSucceed = 0;
volatile  unsigned char   RecvBuf[100];
volatile  unsigned char   MidBuf[100];
volatile  unsigned char   buf1[100];
volatile  unsigned char   buf2[100];
volatile  unsigned char   buf3[100];
volatile  unsigned char   buf4[100];
unsigned int     adder = 0;
unsigned int      UHFLen = 0;
unsigned char   SortNum = 0;
unsigned char   SortNum1 = 0;
unsigned char   HaveBookFlag = 0;
unsigned char   TimeSec  = 0;
unsigned char   TimeMin  = 0;
unsigned char   TimeFlag = 0;
unsigned char   TimeOver = 1;
u8 BookNum, k,FlagSame,BookN[12];
void USART1_SendData(uint8_t *ch,uint8_t Num)
{
    uint8_t i;
    for(i=0; i<Num; i++)
    {
        while(!USART_GetFlagStatus(USART1, USART_FLAG_TXE));
        USART_SendData(USART1, *ch);
        ch++;
    }
}
void UHFInit( void )
{
    u8 j,i;
    u32 k;
    while(1)
    {
        memset(RecvBuf,0,sizeof(RecvBuf));
        UHFLen =(UHF[adder+3]<<8)+UHF[adder+2]+4;
        memcpy(MidBuf,UHF+adder,UHFLen);
//---------------SET POWER--------------------
        if((MidBuf[2]==0x13)&&(MidBuf[3]==0x00)&&(MidBuf[4]==0x0d)&&(MidBuf[5]==0x18)&&(MidBuf[6]==0x00))
        {
            MidBuf[8] =  POWER%0x100;
            MidBuf[9] =  POWER/0x100;

            MidBuf[20]  = 0;
            for(i=0; i<20; i++)
            {
                MidBuf[20] +=MidBuf[i];
            }
        }
//---------------------------------------------
        USART1_SendData(MidBuf,UHFLen);
        if((MidBuf[5]==0x02)&&(MidBuf[6]==0x50))
        {
            ;
        }
        else
        {
            j = 0;
            for(k=0; k<2000; k++)
            {
                delay_ms(1);
                if(RecvSucceed == 0x01)
                {
                    j = 1;
                    RecvSucceed = 0x00;
                    break;
                }
            }
            if(j == 0)
            {
                OUT8_OFF;
                OUT9_ON;
            }
        }
        adder += UHFLen;
        if(UHF[adder] == 0x00)break;
    }
}

void  StartScan( void )
{
    u32 j;
    memset(RecvBuf,0,sizeof(RecvBuf));
    USART1_SendData("\x5A\x55\x08\x00\x0D\x11\x00\x00\x01\xD6\x6A\x69",12);
    /*
                   j = 0;
    	        for(j=0;j<2000;j++)
    	  	{
                             delay_ms(1);
    		        if(RecvSucceed == 0x01)
    		  	{
    		  	       j = 1;
    				RecvSucceed = 0x00;
    				break;
    		  	}
    	  	}
    		if(j == 0){OUT7_OFF;OUT8_ON;}
    */
}
void  StopScan( void )
{
    u32 j;
    memset(RecvBuf,0,sizeof(RecvBuf));
    USART1_SendData("\x5A\x55\x06\x00\x0D\x03\x00\xc5\x6A\x69",10);
    j = 0;
    for(j=0; j<2000; j++)
    {
        delay_ms(1);
        if(RecvSucceed == 0x01)
        {
            j = 1;
            RecvSucceed = 0x00;
            break;
        }
    }
    if(j == 0)
    {
        OUT8_OFF;
        OUT9_ON;
    }
}

void  DelayScan( void  )
{
    u8 m;
    for(k=0; k<100; k++) /*  read 500ms */
    {
        if((RecvSucceed == 0x01)&&(FlagSame == 0x00))/* return data*/
        {
            if(RecvBuf[1] == 0x05)/*  receive tag data*/
            {
                if((RecvBuf[26]==0x6a)&&(RecvBuf[27]==0x69))
                {
                    FlagSame = 0;
                    for(m = 0; m<12; m++)
                    {
                        if(BookN[m] != RecvBuf[m+13])
                        {
                            memcpy(BookN,RecvBuf+13,12);
                            FlagSame = 0x01;
                            SortNum1 = RecvBuf[13] &0x1f;/* get numer*/
                            //HaveBookFlag = 0x01;
                            //break;
                        }
                    }
                }
            }
            RecvSucceed = 0x00;
        }
        delay_ms(5);
    }
}
//=======================Sort Motor=======================
void stop_right()
{
    OUT2_OFF;			//2号 off
    delay_ms(10);
    OUT3_ON;			//2号 on
}
void stop_left()
{
    OUT2_ON;			 //2号板 ON
    delay_ms(10);
    OUT3_OFF;			 //2号板 off
}
void sort_motor_stop()
{
    OUT2_OFF;
    OUT3_OFF;
}
void sort_right()
{
    OUT1_ON;
	delay_ms(3000);
//    stop_left();
//    while(IN_3)
//    {
//        ;
//    }
//    while(IN_3 == 0)
//    {
//        ;
//    }
    OUT1_OFF;
    
    stop_right();
}
void sort_left()
{
    OUT4_ON;
    stop_right();
    while(IN_3)
    {
        ;
    }
    while(IN_3 == 0)
    {
        ;
    }
    OUT4_OFF;
    delay_ms(80);
    stop_left();
}

void sort_one()
{
    OUT1_ON;		
    delay_ms(3000);
    OUT1_OFF;			
}
void sort_two()
{
    OUT2_ON;		
    delay_ms(3000);
    OUT2_OFF;			
}
void sort_three()
{
    OUT3_ON;		
    delay_ms(3000);
    OUT3_OFF;			
}
void sort_four()
{
    OUT4_ON;		
    delay_ms(3000);
    OUT4_OFF;			
}

void sort_five()
{
    OUT5_ON;		
    delay_ms(3000);
    OUT5_OFF;			
}
void sort_six()
{
    OUT6_ON;		
    delay_ms(3000);
    OUT6_OFF;			
}
void sort_seven()
{
    OUT7_ON;		
    delay_ms(3000);
    OUT7_OFF;			
}

void DeviceInit( void )
{
    u8 i,j;
    u32  k;
    j = 0;
    OUT1_OFF;
    OUT2_OFF;
    OUT3_OFF;
    OUT4_OFF;
    OUT5_OFF;
    OUT6_OFF;
    OUT7_OFF;
    OUT8_OFF;
	OUT9_OFF;
	OUT10_OFF;
    delay_ms(200);
    delay_ms(200);
    delay_ms(200);
    delay_ms(200);
    delay_ms(200);
    delay_ms(200);
    delay_ms(200);
    delay_ms(200);
    delay_ms(200);
    delay_ms(200);
//    OUT1_ON;
//    delay_ms(200);
//    while(IN_4 == 0)
//    {
//        ;
//    }
//    OUT1_OFF;
//    delay_ms(200);
//    stop_left();
//    delay_ms(200);
}
//======================== main ==========================
int main(void)
{
    u8 i,j,m;
    u32 k;
    delay_init();	    	   /* delay interrupt */
    NVIC_Configuration(); /*  interrupt configuration */
    uart_init(115200);	   /* set uart band */
    GPIOS_Init(); /* Gpio set */
    DeviceInit();
    //USART1_SendData("\x5A\x55\x08\x00\x0D\x11\x00\x00\x01\xD6\x6A\x69",12);
    UHFInit();   /* UHF int */

    while(1)
    {
//================== step 1=========================
        if(IN_1 == HAVE_BOOK)/* fist in trigger*/
        {
            TimeOver = 0;
            TimeSec  = 0;
            TimeMin  = 0;
            TimeFlag = 0;
            OUT9_OFF; /* start transfer device*/
        }
//================== step 2=========================
        if(IN_2 == HAVE_BOOK)/* second in trigger*/
        {

            OUT9_ON;
            TimeOver = 0;
            TimeSec  = 0;
            TimeMin  = 0;
            TimeFlag = 0;
            StartScan(); /* start scan*/
            SortNum = 0x00;
            HaveBookFlag = 0x00;
            BookNum = 0;
            memset(BookN,0,12);
            k = 100;
//			for(k=0;k<100;k++)/*  read 1s */
            while((k>0)&&(HaveBookFlag==0))
            {
                k--;
                if(RecvSucceed == 0x01)/* return data*/
                {
                    if(RecvBuf[1] == 0x05)/*  receive tag data*/
                    {
                        if((RecvBuf[28]==0x6a)||(RecvBuf[29]==0x6a))
                        {
                            if((BookN[0]==0x00)&&(BookN[1]==0x00))
                            {
                                memcpy(BookN,RecvBuf+13,12);
                                
                                //========区别两种格式的标签
                                if(RecvBuf[13] == 0xC2)    	//远望谷格式
                                {
                                        SortNum = RecvBuf[23] &0xff;/* get number*/
                                        HaveBookFlag	 = 0x01;
                                }
                                else              //高校联盟标准格式
                                {
                                        SortNum = RecvBuf[13] &0x1f;/* get number*/
                                        HaveBookFlag	 = 0x01;
                                }

                            }
                            else
                            {
                                FlagSame = 0;
                                for(m = 0; m<12; m++)
                                {
                                    if(BookN[m] != RecvBuf[m+13])
                                    {
                                        //FlagSame = 0x01;
                                        HaveBookFlag = 0x00;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    RecvSucceed = 0x00;
                }
                delay_ms(10);

            }
        }
//================== step 3=========================
        if((HaveBookFlag == 0x01))/* third in trigger &&  have book*/
        {
            delay_ms(10);
            TimeOver = 0;
            TimeSec  = 0;
            TimeMin  = 0;
            TimeFlag = 0;
            HaveBookFlag	= 0x00;
            if( (BoardNum*2+1) == SortNum )
            {
                //OUT6_OFF;
                sort_one();
            }
            else if( (BoardNum*2+2) == SortNum )
            {
                //OUT6_OFF;
                sort_one();
            }
						else if( (BoardNum*2+3) == SortNum )
            {
                //OUT6_OFF;
                sort_one();
            }
						else if( (BoardNum*2+4) == SortNum )
            {
                //OUT6_OFF;
                sort_one();
            }
						else if( (BoardNum*2+5) == SortNum )
            {
                //OUT6_OFF;
                sort_one();
            }
						else if( (BoardNum*2+6) == SortNum )
            {
                //OUT6_OFF;
                sort_one();
            }
						else if( (BoardNum*2+7) == SortNum )
            {
                //OUT6_OFF;
                sort_two();
            }
						else if( (BoardNum*2+8) == SortNum )
            {
                //OUT6_OFF;
                sort_two();
            }
						else if( (BoardNum*2+9) == SortNum )
            {
                //OUT6_OFF;
                sort_two();
            }
						else if( (BoardNum*2+10) == SortNum )
            {
                //OUT6_OFF;
                sort_two();
            }
						else if( (BoardNum*2+11) == SortNum )
            {
                //OUT6_OFF;
                sort_two();
            }
						else if( (BoardNum*2+12) == SortNum )
            {
                //OUT6_OFF;
                sort_two();
            }
            else
            {
                //HaveBookFlag	= 0x00;
                sort_seven();
            }
        }
//===========================================
        delay_ms(10);
        if(TimeOver == 0)
        {
            if(++TimeSec>=100)
            {
                TimeSec = 0;
                if(++TimeMin>=60)
                {
                    TimeMin = 0;
                    if(++TimeFlag>=Time)
                    {
                        TimeSec  = 0;
                        TimeMin  = 0;
                        TimeFlag = 0;
                        TimeOver= 1;
                        //					    OUT1_OFF;
                        StopScan();   /*close reader*/
                    }
                }
            }
        }
    }
}
