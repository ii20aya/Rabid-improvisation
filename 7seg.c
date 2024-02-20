/*
 * _7seg.c
 *
 * Created: 10/13/2023 11:20:22 AM
 *  Author: HD STORE
 */ 

#include "DIO.h"
//#define cc
//#define highnibble
#include "macro.h"
void seven_seg_inti(char port){
	DIO_setportdir(port, 0xff);
}
////////////////////////////
void seven_seg_write_commka(char port , char val){  //common cathode
	//#if define cc
	unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};  /*,0x77,0x7c,0x39,0x5e,0x79,0x71*/
		
	//#else
	//unsigned char arr[]={ ~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x47,~0x7f,~ 0x6f/*,0x77,0x7c,0x39,0x5e,0x79,0x71*/};
	
	//#endif
	DIO_writeport(port,arr[val]);
}
///////////////////////////////////
          void seven_seg_bcd_inti(char port ){
	          //#if define highnibble
	          DIO_SET_BINDIR(port,4,1);
	          DIO_SET_BINDIR(port,5,1);
	          DIO_SET_BINDIR(port,6,1);
	          DIO_SET_BINDIR(port,7,1);
			  //#else
			  //DIO_SET_BINDIR(port,0,1);
			  //DIO_SET_BINDIR(port,1,1);
			  //DIO_SET_BINDIR(port,2,1);
			  //DIO_SET_BINDIR(port,3,1);
	          //#endif
          }
//////////////////////////////////////////////////
         void seven_segbcd_write(char port, char val){
	         
	           //#if define highnibble
	            DIO_write_highnibble(port, val);
				//#else
				 //DIO_write_lownibble(port, val);
	           //#endif
          }

///////////////////////////////////   

