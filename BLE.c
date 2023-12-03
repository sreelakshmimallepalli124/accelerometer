#include<stdio.h>
#include<stdlib.h>
typedef unsigned int u32;
typedef unsigned short int u16;
typedef unsigned char u8;
//packet
typedef struct beacon_ble
{
u8data_length;
u8 flag_data_type;
u8 flag_data;
u8 UUID_service;
u16 UUID_data;
u8 service_data;
u8 frame_type;
u8 version_number;
u8 battery_level;
u16 x_axis;
u16 y_axis;
u16 z_axis;
u8 *mac;
}ACCELEROMETER;
char **p;
int extract_beacon_packets(char **q);
char* extract_byte(int n);
int main()
{
char *q="0x0201060303E1FF1216E1FFA10364FFF4000FFF003772A33F23AC";
int temp=extract_beacon_packets(&q);
if(temp==0)
printf("beacon is moving\n");
else
printf("beacon is stationary\n");
}
int extract_beacon_packets(char **t)
{
p=t;
*p+=2;
ACCELEROMETER packet_1;
u32 i,j,k;
packet_1.data_length=*(extract _byte(1))-48;
packet_1.flag_data_type=*(extract_byte(1))-48;
packet_1.flag_data=*(extract_byte(1))-48;
packet_1.data_length=*(extract_byte(1))-48;
packet_1.UUID_service=*(extract_byte(1))-48;
packet_1.UUID_data=*(extract_byte(2))-48;
}
char* extract_byte(int n)
{
u8 *q=(u8*)malloc(sizeof(u8)*n);
int i;
printf("%s\n",*p);
if(n==1)
{
while(n--)
{
q[i]=(**p);
q[i]<<=4;
*p+=1;
}
*p+=1;
}
}
else if(n==2)
{
for(i=0;n--;i++)
{
q[i]=(**p);
q[i]<<=4;
*p+=1;
q[i]=q[i]|(**p);
*p+=1;
}
}
else
{
}
return p;
}
