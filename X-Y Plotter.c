#include<reg52.h>  
#include<math.h>  
#define uint unsigned int
#define ulong unsigned long
sbit xpu=P1^0;
sbit xdr=P1^1;
sbit ypu=P2^3;
sbit ydr=P2^4;
sbit kxz=P1^4;
sbit kxf=P1^5;
sbit kyz=P1^6;
sbit kyf=P1^7;
sbit kzd=P3^2;
sbit kqd=P3^3;
sbit RS=P2^0;    
sbit RW=P2^1;    
sbit E=P2^2;     
sbit BF=P0^7;   
void delay(unsigned int t);
void delay1(uint a);
void delay2(uint k);
void Write_com (unsigned char com);
void WriteAddress(unsigned char x);
void WriteData(unsigned int m);
void LcdInt(void);
bit BusyTest(void);
void line(float x,float y,char n);
void cicle(float x0,float y0,float x,float y,char n,char r);
void zd_scan();
void main(void)
{
  TCON=0x00;
  IE=0x81;
  while(kqd)
    {
      if(kxz==0)
        {
          xdr=1;
          while(!kxz)
          {
            xpu=1;
            delay1(2);
            xpu=0;
            delay1(2);
          }  
        }
      if(kxf==0)
        {
          xdr=0;
          while(!kxf)
          {
            xpu=1;
            delay1(2);
            xpu=0;
            delay1(2);
          }  
        }
      if(kyz==0)
        {
          ydr=0;
          while(!kyz)
          {
            ypu=1;
            delay1(4);
            ypu=0;
            delay1(4);
          }  
        }
      if(kyf==0)
        {
          ydr=1;
          while(!kyf)
          {
            ypu=1;
            delay1(5);
            ypu=0;
            delay1(5);
          }  
        } 
      if(kqd==0) 
        goto ht; 
    }
      ht:
  line(19,28.5,1);
  line(87.5,3.5,1);
  line(10,30,4);
  line(64,0,4);
  line(5,5,1);
  line(15,0,1);
  cicle(161.2,28.5,163.7,0,2,'n');
  cicle(163.7,0,161.2,28.5,3,'n');
  line(16,0,3);
  line(12.5,18,2);
  line(26.5,0,2);
  cicle(104,0,66.45,80,4,'s');
  line(21.45,20,2);
  cicle(45,60,75,0,4,'n');
  line(35.12,0,2);
  cicle(0,10,10,0,2,'n');
  cicle(10,0,9.59,2.83,3,'n');
  line(9.21,31.7,4);
  line(5,5,3);
  line(19,0,3);
  line(3,32,2);
  line(4,4,2);
  line(30,15,3);
  line(9.5,0,3);
  line(7.5,35.5,2);
  line(37,0,2);
  line(3.5,3.5,3);
  line(18,0,2);
  line(3.5,7.5,2);
  line(31,0,2);
  line(0,1.5,3);
  line(18,0,3);
  line(0,13,1);
  line(18,0,1);
  line(0,1.5,4);
  line(34,0,4);
  line(0,16,1);
  line(3,0,1);
  line(0,13,1);
  line(4,0,2);
  line(0,16,2);
  line(11,0,1);
  line(0,14.5,3);
  line(10,20,4);
  line(36,0,1);
	  delay2(500);
	  line(11.5,2.5,1);
	  delay2(500);
  line(84.5,0,1);
  line(0,21,1);
  line(72.5,1.5,3);
  line(12,19.5,3);
	  delay2(500);
	  line(25,0,1);
	  delay2(500);
  line(0,8,1);
  cicle(0,8,8,0,1,'s');
	  delay2(500);
	  line(4,29,4);
	  delay2(500);
  line(0,14,4);
  line(29,7.5,3);
  line(0,21.5,1);
  line(17,0,1);
  line(0,13.96,4);
  cicle(17,13.96,22,0,4,'n');
  line(7,0,4);
    while(1);
}
void line(float x,float y,char n)
{
	unsigned short int a,b,c,d,e,q;
	unsigned long xe,ye,count;
	long f;
	xpu=0;
	ypu=0;
	xe=400*x;	 
	ye=400*y;
	count=xe+ye;
 	   f=0;
	   q=0; 
       a=(x/100);
	   b=(x-a*100)/10;
	   c=(x-a*100-b*10);
	   d=(x-a*100-b*10-c)*10;
	   e=(x*10-a*1000-b*100-c*10-d)*10;
  LcdInt();           
  delay(10);

			        Write_com(0x01);
					delay2(5);
					WriteAddress(0x00);
					delay2(5);
				    WriteData('X');
					delay2(5);
					WriteData(':');
					delay2(5);
					WriteData(' ');
					delay2(5);
					WriteData(a|0x30);
					delay2(5);
					WriteData(b|0x30);
					delay2(5);
					WriteData(c|0x30);
					delay2(5);
					WriteData('.');
					WriteData(d|0x30);
					delay2(5);
					WriteData(e|0x30);
					delay2(5);

				       x=y;
					   a=(x/100);
					   b=(x-a*100)/10;
					   c=(x-a*100-b*10);
					   d=(x-a*100-b*10-c)*10;
					   e=(x*10-a*1000-b*100-c*10-d)*10;					
					delay2(5);
					WriteAddress(0x40);
					delay2(5);
				    WriteData('Y');
					delay2(5);
					WriteData(':');
					delay2(5);
					WriteData(' ');
					delay2(5);
					WriteData(a|0x30);
					delay2(5);
					WriteData(b|0x30);
					delay2(5);
					WriteData(c|0x30);
					delay2(5);
					WriteData('.');
					WriteData(d|0x30);
					delay2(5);
					WriteData(e|0x30);
					delay2(5);
                    while(!q);
		  
	switch(n)	 
	{
		case 1:
		      xdr=1;
		      ydr=0; 
		      break;
		case 2:	
		      xdr=0;
		      ydr=0;
		      break;
		case 3:	
		      xdr=0;
		      ydr=1;
		      break;
		case 4:	
		      xdr=1;
		      ydr=1;
		      break;
	}
	while(count>0)
	{
	  if(f>=0)
		  {
		    xpu=1;
		    delay1(4);
		    xpu=0;
		    delay1(4);
		    f=f-ye;
		  }
	  else	
		{
		  ypu=1;
		  delay1(4);
		  ypu=0;
		  delay1(4);
		  f=f+xe;
		}
	  count=count-1;
		}
	q=1;
}
void cicle(float x0,float y0,float x,float y,char n,char r)
{
  unsigned short int a,b,c,d,e,q;
  ulong xm,ym,count;
  float g,h;
  long f;
  xm=400*x0;
  ym=400*y0;
  g=x-x0;
  if(g<0)
    {
      g=-g;
    }
  h=y-y0;
  if(h<0)
    {
      h=-h;
    }
  count=(g+h)*400; 
  f=0;			
  xpu=0;
  ypu=0;
  	   q=0; 
	   x=x0;
       a=(x/100);
	   b=(x-a*100)/10;
	   c=(x-a*100-b*10);
	   d=(x-a*100-b*10-c)*10;
	   e=(x*10-a*1000-b*100-c*10-d)*10;
  LcdInt();           
  delay(10);

			        Write_com(0x01);
					delay2(5);
					WriteAddress(0x00);
					delay2(5);
				    WriteData('X');
					delay2(5);
					WriteData('0');
					delay2(5);
					WriteData(':');
					delay2(5);
					WriteData(a|0x30);
					delay2(5);
					WriteData(b|0x30);
					delay2(5);
					WriteData(c|0x30);
					delay2(5);
					WriteData('.');
					WriteData(d|0x30);
					delay2(5);
				       x=y0;
					   a=(x/100);
					   b=(x-a*100)/10;
					   c=(x-a*100-b*10);
					   d=(x-a*100-b*10-c)*10;
					   e=(x*10-a*1000-b*100-c*10-d)*10;					
					delay2(5);
					WriteAddress(0x40);
					delay2(5);
				    WriteData('Y');
					delay2(5);
					WriteData('0');
					delay2(5);
					WriteData(':');
					delay2(5);
					WriteData(a|0x30);
					delay2(5);
					WriteData(b|0x30);
					delay2(5);
					WriteData(c|0x30);
					delay2(5);
					WriteData('.');
					WriteData(d|0x30);
					delay2(5);
	   x=x;
       a=(x/100);
	   b=(x-a*100)/10;
	   c=(x-a*100-b*10);
	   d=(x-a*100-b*10-c)*10;
	   e=(x*10-a*1000-b*100-c*10-d)*10;

					delay2(5);
					WriteAddress(0x09);
					delay2(5);
				    WriteData('X');
					delay2(5);
					WriteData(':');
					delay2(5);
					WriteData(a|0x30);
					delay2(5);
					WriteData(b|0x30);
					delay2(5);
					WriteData(c|0x30);
					delay2(5);
					WriteData('.');
					WriteData(d|0x30);
					delay2(5);
				       x=y;
					   a=(x/100);
					   b=(x-a*100)/10;
					   c=(x-a*100-b*10);
					   d=(x-a*100-b*10-c)*10;
					   e=(x*10-a*1000-b*100-c*10-d)*10;					
					delay2(5);
					WriteAddress(0x49);
					delay2(5);
				    WriteData('Y');
					delay2(5);
					WriteData(':');
					delay2(5);
					WriteData(a|0x30);
					delay2(5);
					WriteData(b|0x30);
					delay2(5);
					WriteData(c|0x30);
					delay2(5);
					WriteData('.');
					WriteData(d|0x30);
					delay2(5);
                    while(!q);
  if(((r=='s')&&((n==1)||(n==3)))||((r=='n')&&((n==2)||(n==4))))
    {
      switch(n)
         {
          case 1:
				    xdr=1;
				    ydr=1;
				    break;
          case 2:
			       xdr=0;
			       ydr=1;
			       break;
          case 3:
			       xdr=0;
			       ydr=0;
			       break;
	      case 4:
		          xdr=1;
			       ydr=0;
			       break;
        }
    while(count>0)
      {
          if(f>=0)
            {
              ypu=1;
              delay1(4);
              ypu=0;
              delay1(4);
              f=f-2*ym+1;
              ym=ym-1;
            }
          else
            {
             xpu=1;
             delay1(4);
             xpu=0;
             delay1(4);
             f=f+2*xm+1;
             xm=xm+1;
            }
          count=count-1;
        }
    }
  else
    {
     switch(n)
       {
         case 1:
           xdr=0;
           ydr=0;
           break;
         case 2:
           xdr=1;
           ydr=0;
           break;
         case 3:
           xdr=1;
           ydr=1;
           break;
         case 4:
           xdr=0;
           ydr=1;
           break;
      }
    while(count>0)
    {
  if(f>=0)
    {
      xpu=1;
      delay1(4);
      xpu=0;
      delay1(4);
      f=f-2*xm+1;
      xm=xm-1;
    }
  else
    {
      ypu=1;
      delay1(4);
      ypu=0;
      delay1(4);
      f=f+2*ym+1;
      ym=ym+1;
    }
      count=count-1;
    }
  }
  q=1;
}
 bit BusyTest(void)
  {
    	bit result;
		RS=0;      
    	RW=1;
    	E=1;       
         delay(10); 
    	result=BF; 
		E=0;
    	return result;
  }
void Write_com (unsigned char com)
{   
   while(BusyTest()==1);
	 RS=0;                 
	 RW=0; 
	 E=0;                 
       delay(2);  
	 P0=com;    
	   delay(4);                       
	 E=1;                  
       delay(4);             
	 E=0;                  
 }
 void WriteAddress(unsigned char x)
 {
     Write_com(x|0x80); 
 }
 void WriteData(unsigned int m)
 {     
	while(BusyTest()==1);
	  RS=1;           
	  RW=0;
	  E=0;           
        delay(4);
	  P0=m;           
        delay(4);     
	  E=1;          
	    delay(4);      
	  E=0;            
 }
void LcdInt(void)
{
   	delay2(5);            
   	Write_com(0x38);
	delay2(5);            
   	Write_com(0x38); 
	delay2(5);            
   	Write_com(0x38);   
	delay2(5);   
	Write_com(0x0F);  
	delay2(5);
	Write_com(0x06);  
	delay2(5);											  
	Write_com(0x01);  
	delay2(5);
 }
void delay(unsigned int t)
{
        unsigned int i,j;   	
	 	for(i=0;i<t;i++)
	  	for(j=0;j<10;j++);		 
}
void delay1(uint a)
{
  int i;
  for(i=a;i>0;i--);
}
void delay2(uint k)
{
  ulong i,j;
  for(i=0;i<k;i++)
    for(j=0;j<124;j++);
}
void zd_scan()interrupt 0
{
  if(kzd==0)
    {
      delay1(10);
      if(kzd==0)
        while(!kzd);
    }
}