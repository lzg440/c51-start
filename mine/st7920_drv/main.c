/*=======================================================
<<<<<<<<<<<<<<<<<<< 爱普雷德技术团队 >>>>>>>>>>>>>>>>>>>>
<<<<<<<<<<<<<<<<<<< 我们一起追求卓越 >>>>>>>>>>>>>>>>>>>>
---------------------------------------------------------
旗舰网店: http://aplid.taobao.com/
官方邮箱: njaplid@163.com
 技术QQ1: 535676091
 技术QQ2: 1915624375
 技术QQ3: 154211813
---------------------------------------------------------
               All right reserved.2013.01
---------------------------------------------------------
 文件名: LCD_12864.c
 描述: 液晶12864显示图片,汉字
 作者:
=========================================================
-----------------------------------------------------------------------------------------------------------*/
#include <reg52.h>
#include <intrins.h>

/* 定义LCD12864接口对应的端口和引脚 */
#define LCD12864_DATA P0        //并行数据口
sbit LCD12864_RS = P2^7;        //数据/命令选择
sbit LCD12864_RW = P2^6;        //读/写选择
sbit LCD12864_EN = P2^5;        //使能信号
sbit LCD12864_PSB = P2^4;       //并/串接口选择, H并,L串
sbit LCD12864_RST = P2^2;       //复位, L有效

/* 定义Logo的位图数据 */
code unsigned char TDCAPLID[]={
/*------------------------------------------------------------------------------
  源文件 / 文字 : APLID二维码.bmp
  宽×高（像素）: 128×64
------------------------------------------------------------------------------*/
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x07,0xE7,0xE1,0xE0,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x07,0xE7,0xE1,0xE0,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x7F,0xE6,0x07,0xF8,0x67,0xFE,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x7F,0xE6,0x07,0xF8,0x67,0xFE,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x66,0x7F,0xE0,0x66,0x06,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x66,0x7F,0xE0,0x66,0x06,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x67,0x9E,0x61,0xE6,0x06,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x67,0x9E,0x61,0xE6,0x06,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x66,0x06,0x60,0x66,0x06,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x66,0x06,0x60,0x66,0x06,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x7F,0xE6,0x66,0x78,0x67,0xFE,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x7F,0xE6,0x66,0x78,0x67,0xFE,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x06,0x66,0x66,0x60,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x06,0x66,0x66,0x60,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x61,0xE7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x61,0xE7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x19,0xE1,0xF8,0x18,0x60,0x61,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x19,0xE1,0xF8,0x18,0x60,0x61,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xE7,0x9E,0x18,0x7E,0x07,0xFE,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xE7,0x9E,0x18,0x7E,0x07,0xFE,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0x98,0x61,0xF8,0x7E,0x18,0x78,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0x98,0x61,0xF8,0x7E,0x18,0x78,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x7E,0x19,0x80,0x01,0xF8,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x7E,0x19,0x80,0x01,0xF8,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x01,0xE1,0x9E,0x01,0x98,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x01,0xE1,0x9E,0x01,0x98,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x18,0x79,0xFF,0x81,0x86,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x18,0x79,0xFF,0x81,0x86,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x7F,0xE1,0xF9,0x9E,0x19,0xE6,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x7F,0xE1,0xF9,0x9E,0x19,0xE6,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0x9E,0x18,0x01,0x80,0x79,0x99,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0x9E,0x18,0x01,0x80,0x79,0x99,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x07,0x86,0x06,0x7E,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x07,0x86,0x06,0x7E,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x7E,0x66,0x7E,0x06,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x7E,0x66,0x7E,0x06,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x06,0x00,0x18,0x66,0x78,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x06,0x00,0x18,0x66,0x78,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x7F,0xE7,0x86,0x66,0x7E,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x7F,0xE7,0x86,0x66,0x7E,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x67,0x86,0x06,0x00,0x79,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x67,0x86,0x06,0x00,0x79,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x66,0x01,0xF8,0x78,0x67,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x66,0x01,0xF8,0x78,0x67,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x67,0xE7,0x98,0x7E,0x06,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x67,0xE7,0x98,0x7E,0x06,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x7F,0xE6,0x60,0x18,0x1F,0x9F,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x7F,0xE6,0x60,0x18,0x1F,0x9F,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x06,0x78,0x06,0x61,0xF8,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x06,0x78,0x06,0x61,0xF8,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

/* 定义Logo的位图数据 */
code unsigned char LogoAPLID[]={
/*------------------------------------------------------------------------------
  源文件 / 文字 : LogoAPLID黑白.bmp
  宽×高（像素）: 128×64
------------------------------------------------------------------------------*/
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0x80,0x7F,0xE0,0x07,0xFC,0x03,0xFC,0x03,0xC0,0x00,0x07,0xFF,0xFF,
0xFF,0xFF,0xFE,0x00,0x7F,0x00,0x01,0xFC,0x03,0xFC,0x03,0xC0,0x00,0x00,0xFF,0xFF,
0xFF,0xFF,0xFC,0x00,0x7E,0x00,0x00,0x7C,0x03,0xFC,0x03,0xC0,0x00,0x00,0x3F,0xFF,
0xFF,0xFF,0xFC,0x00,0x7C,0x00,0x00,0x3C,0x03,0xFC,0x03,0xC0,0x00,0x00,0x1F,0xFF,
0xFF,0xFF,0xF8,0x00,0x7C,0x03,0xC0,0x3C,0x03,0xFC,0x03,0xC0,0x00,0x00,0x0F,0xFF,
0xFF,0xFF,0xF0,0x00,0x78,0x03,0xC0,0x3C,0x03,0xFC,0x03,0xC0,0x1F,0x80,0x07,0xFF,
0xFF,0xFF,0xF0,0x00,0x78,0x07,0xC0,0x1C,0x03,0xFC,0x03,0xC0,0x3F,0xF0,0x03,0xFF,
0xFF,0xFF,0xE0,0x20,0x78,0x07,0xC0,0x1C,0x03,0xFC,0x03,0xC0,0x3F,0xF8,0x03,0xFF,
0xFF,0xFF,0xC0,0x20,0x78,0x07,0xC0,0x3C,0x03,0xFC,0x03,0xC0,0x3F,0xF8,0x01,0xFF,
0xFF,0xFF,0x80,0x60,0x78,0x07,0x80,0x3C,0x03,0xFC,0x03,0xC0,0x3F,0xFC,0x01,0xFF,
0xFF,0xFF,0x80,0x60,0x78,0x07,0x00,0x7C,0x03,0xFC,0x03,0xC0,0x3F,0xFC,0x01,0xFF,
0xFF,0xFF,0x00,0xC0,0x78,0x07,0x00,0xFC,0x03,0xFC,0x03,0xC0,0x3F,0xF8,0x03,0xFF,
0xFF,0xFE,0x00,0xC0,0x78,0x07,0xC3,0xFC,0x03,0xFC,0x03,0xC0,0x3F,0xF8,0x03,0xFF,
0xFF,0xFE,0x01,0xC0,0x78,0x07,0xFF,0xFC,0x03,0xFC,0x03,0xC0,0x3F,0xF0,0x03,0xFF,
0xFF,0xFC,0x01,0xC0,0x78,0x07,0xFF,0xFC,0x01,0xFC,0x03,0xC0,0x3F,0x80,0x07,0xFF,
0xFF,0xF8,0x03,0xC0,0x78,0x07,0xFF,0xFC,0x00,0x3C,0x03,0xC0,0x30,0x00,0x0F,0xFF,
0xFF,0xF8,0x03,0xC0,0x78,0x07,0xFF,0xFC,0x00,0x3C,0x03,0xC0,0x30,0x00,0x1F,0xFF,
0xFF,0xF0,0x07,0x80,0x78,0x07,0xFF,0xFE,0x00,0x3C,0x03,0xC0,0x30,0x00,0x3F,0xFF,
0xFF,0xE0,0x07,0x80,0x78,0x07,0xFF,0xFF,0x00,0x3C,0x03,0xC0,0x30,0x00,0xFF,0xFF,
0xFF,0xE0,0x0F,0x80,0x78,0x07,0xFF,0xFF,0xC0,0x3C,0x03,0xC0,0x30,0x03,0xFF,0xFF,
0xFF,0xC0,0x0F,0x80,0x78,0x07,0xFF,0xFF,0xF0,0x3C,0x03,0xC0,0x30,0x3F,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

/**********************************************
功能：
    延时函数
输入参数：
    n: 延时时长
输出参数：
    无
返回值：
**********************************************/
void Delay(unsigned int n)
{
    unsigned int i;
    while(n--)
    {
        i=200;
        while(i--);
    }
}

/**********************************************
功能：
    忙检测
输入参数：
    无
输出参数：
    无
返回值：
    1: 忙
    0: 空闲
**********************************************/
bit BusyCheck(void)
{
    bit BusyBit;
    
    LCD12864_DATA = 0xFF;
    LCD12864_RS = 0;
    LCD12864_RW = 1;
    LCD12864_EN = 1;
    _nop_();
    BusyBit = (bit)(LCD12864_DATA>>7);
    LCD12864_EN = 0;
    return BusyBit;
}

/**********************************************
功能：
    写命令到LCD12864
输入参数：
    CmdByte: 命令字节
输出参数：
    无
返回值：
**********************************************/
void CommandWrite12864(unsigned char CmdByte)
{
    while(BusyCheck());             //等待忙
    LCD12864_RS = 0;
    LCD12864_RW = 0;
    LCD12864_EN = 1;
    LCD12864_DATA = CmdByte;
    _nop_();
    LCD12864_EN = 0;
}

/**********************************************
功能：
    写数据到LCD12864
输入参数：
    DataByte: 数据字节
输出参数：
    无
返回值：
**********************************************/
void DataWrite12864(unsigned char DataByte)
{
    while(BusyCheck());             //等待忙
    LCD12864_RS = 1;
    LCD12864_RW = 0;
    LCD12864_EN = 1;
    LCD12864_DATA = DataByte;
    _nop_();
    LCD12864_EN = 0;
}

/**********************************************
功能：
    初始化LCD12864
输入参数：
    无
输出参数：
    无
返回值：
**********************************************/
void Reset12864(void)
{
	LCD12864_PSB = 1;               //选择并口传输
	CommandWrite12864(0x30);        //选择基本指令集
	CommandWrite12864(0x0c);        //开显示(无游标、不反白)
	CommandWrite12864(0x01);        //清除显示，并且设定地址指针为00H
	CommandWrite12864(0x06);        //指定在资料的读取及写入时，设定游标的移动方向及指定显示的移位
}

/**********************************************
功能：
    清屏
输入参数：
    无
输出参数：
    无
返回值：
**********************************************/
void ScreenClear12864(void)
{
    CommandWrite12864(0x01);
}

/**********************************************
功能：
    在指定坐标显示字符串
输入参数：
    x: 横坐标(0——15)
    y: 纵坐标(0——1)
    String: 字符串
输出参数：
    无
返回值：
**********************************************/
void StringDisplay12864(unsigned char x, unsigned char y, unsigned char *String)
{
    if((x<8)&&(y<4))
    {
        //指定数据地址
        switch(y)
        {
            case 0:
                CommandWrite12864(0x80|0x00|x);
                break;
            case 1:
                CommandWrite12864(0x80|0x10|x);
                break;
            case 2:
                CommandWrite12864(0x80|0x08|x);
                break;
            case 3:
                CommandWrite12864(0x80|0x18|x);
                break;
        }
        //显示字符串
        while(*String != '\0')
        {
            DataWrite12864(*String);
            Delay(50);
            String++;
        }
    }
}

/**********************************************
功能：
    显示一整个位图
输入参数：
    Picture: 指向位图的指针
输出参数：
    无
返回值：
**********************************************/
void PictureDisplay12864(unsigned char code *Picture)
{
    unsigned char i,j,k;
    
    /* 选择扩展指令集，并关闭绘图显示 */
	CommandWrite12864(0x34);
	CommandWrite12864(0x34);
    /* 将位图的所有字节写到液晶的位图RAM中 */
    for(i=0; i<2; i++)                      //GDRAM分上下两页
    {
        for(j=0; j<32; j++)
        {
            /* 写纵坐标y和横坐标x */
            CommandWrite12864(0x80+j);      //写GDRAM的坐标y，即第y行
            if(i==0)
            {
                CommandWrite12864(0x80);    //写GDRAM的坐标x（上页）
            }
            else
            {
                CommandWrite12864(0x88);    //写GDRAM的坐标x（下页）
            }
            /* 将16个字节写入GDRAM */
            for(k=0; k<16; k++)
            {
                DataWrite12864(*Picture++);
            }
        }
    }
    /* 打开绘图显示，并选择基本指令集 */
    CommandWrite12864(0x36);
    CommandWrite12864(0x30);
}

/*---------------------------------------------------------------------------------------------------------*/
/**********************************************
    主函数，实现LCD12864显示功能
**********************************************/
void main()
{
    Reset12864();                           //液晶12864初始化
    Delay(20);                              //延时,保证显示更稳定
    PictureDisplay12864(LogoAPLID);         //显示Logo图案
    Delay(1000);
    ScreenClear12864();
    
    while(1) //无限循环
    {
        StringDisplay12864(0,0,"爱普雷德电子科技");
        StringDisplay12864(0,1,"................");
        StringDisplay12864(0,2,"在实践中快乐学习");
        StringDisplay12864(0,3,"................");
        Delay(2000);
        ScreenClear12864();
        PictureDisplay12864(TDCAPLID);
        Delay(2000);
        ScreenClear12864();
    }
}