#include<8051.h>
void _mcs51_genRAMCLEAR(void)
{

}
typedef struct{
  unsigned char scan;
  unsigned char ascii;
  unsigned char disp;
}s_keymap;

s_keymap keymap[] = {
  /*scan ascii disp*/
  { 0xb7, '1', 0x06 }, /*0 1 1*/
  { 0xd7, '2', 0x5B }, /*1 0 1*/
  { 0xe7, '3', 0x4F }, /*1 1 0*/
  { 0xbb, '4', 0x66 },
  { 0xdb, '5', 0x6D },
  { 0xeb, '6', 0x7D },
  { 0xbd, '7', 0x07 },
  { 0xdd, '8', 0x7F },
  { 0xed, '9', 0x6F },
  { 0xbe, '*', 0x77 },
  { 0xde, '0', 0x3F },
  { 0xee, '#', 0x7C },
};

void main(void)
{
  unsigned char i;
  unsigned char m;
  unsigned char k=0;
  unsigned char a=0xff,b=0x00,c=0x00,d=0x00;
  while(1)
  { 
    
    while(k<=4)
    {
    for(i=0; i<sizeof(keymap)/sizeof(s_keymap); i++)
    {
      P0 = keymap[i].scan | 0xf0;
      if(P0 == keymap[i].scan)
      {
        
        if(k==0)
        {
          a = ~(keymap[i].disp);
          k=k+1;
        }
        else if(k==1)
        {
          b = ~(keymap[i].disp);
          k=k+1;
        }
        else if(k==2)
        {
          c = ~(keymap[i].disp);
          k=k+1;
        }
        else if(k==3)
        {
          d = ~(keymap[i].disp);
          k=k+1;
        }
        else
        {
          break;
        }
        
        for(m=0;m<100;m++);
      }
    }
    }
 
 P3=0x00;
 P1=a;
 for(m=0;m<100;m++);
 
 P3=0x08;
 P1=b;
 for(m=0;m<100;m++);

 P3=0x10;
 P1=c;
 for(m=0;m<100;m++);

 P3=0xff;
 P1=d;
 for(m=0;m<100;m++);
 }
  }
}


