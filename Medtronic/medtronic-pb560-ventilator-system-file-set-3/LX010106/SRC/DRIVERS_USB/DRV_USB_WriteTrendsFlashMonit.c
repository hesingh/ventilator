/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505																		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DRV_USB_WriteTrendsFlashMonit.c	 										*/
/*																										*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C         																						*/
/******************************************************************************/
/*%I Input Parameter :  NONE                                                  */
/*%IO Input/Output :    NONE	                                                */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/

#include "enum.h"
#include "define.h"
#include "typedef.h"
#include "Structure.h"
#include "Ventilation_Datas.h"
#include "Ventilation_Compute_data.h"
#include "Timer_Data.h"
#include "Driver_USB_Data.h"
#include "DB_Usb.h"
#include "DB_RTC.h"
#include "Flash_Monit_Data.h"
#include "DRV_USB_WriteTrendsFlashMonit.h"


/******************************************************************************/
/*                   			FUNCTION BODY                    					*/
/******************************************************************************/

void DRV_USB_WriteTrendsFlashMonit(void)
{

/******************************************************************************/
/*%C Variables 																					*/
/******************************************************************************/
							
	UWORD16 UsbTrendTransfert = DB_UsbRead(USB_TREND_TRANSFER_U16);

	static UWORD16 FlashReadyLoop = 0 ;

	static UWORD32 NbTrensdsBytesToWrite = 0 ;
	static UWORD32 LoopWriteTrends = 0 ;

/******************************************************************************/
/*%C Write the Flash monitoring on the key												*/
/******************************************************************************/
	switch(Step_UsbTransferApply)
	{																			  
		/*%C First step is create the monitoring file */
		case Usb_FirstStep :
		{
			if(DRV_TREND_Read_Request == ENDED)
			{	
				UsbFlashInUse = TRUE;
				/*%C Request Flash */
				DRV_TREND_Read_Request = REQUEST;
				/*%C Update files time and date for files name */
				USB_FileHour 	= (UBYTE)DB_RTCRead(DB_RTC_HOUR_U16) ;
				USB_FileMinute 	= (UBYTE)DB_RTCRead(DB_RTC_MINUTE_U16) ;
				USB_FileSecond 	= (UBYTE)DB_RTCRead(DB_RTC_SECOND_U16) ;
				USB_FileYear 	= (UBYTE)DB_RTCRead(DB_RTC_YEAR_U16) ;
				USB_FileMonth	= (UBYTE)DB_RTCRead(DB_RTC_MONTH_U16) ;
			 	USB_FileDay		= (UBYTE)DB_RTCRead(DB_RTC_DAY_U16) ;
				/*%C Create the file */
				DRV_USB_CreateFileName(TrendsTransferType);
				/*%C Build the frame */
				DRV_USB_CreateFile(CurrentUsbKey , Tab_FileName) ;
				/*%C Next Step */
				Step_UsbTransferApply = Usb_WriteSerialNumberAtEndOfFile ;
			}
			else
			{
				/*%C Nand Flash is use by the Rs 232 Communication */
				Step_UsbTransferApply = Usb_CloseFile ;
			}
			break ;
		}




		/*%C Next Step is Write at the end of File */
		case Usb_WriteSerialNumberAtEndOfFile :
		{
			/*%C Updates parameters */
			DRV_USB_Transmit_SerialNumber();
			/*%C Build the frame */
			DRV_USB_WriteAtTheEndOfFile(CurrentUsbKey,
										SerialNumber ,
										End_of_e_usb_frame_serialNumber) ;
			/*%C Next Step */
			Step_UsbTransferApply = Usb_WriteAtTheEndOfFile;
			/*%C Initialize Variable */
			NbBytesUsbWrittenFlashMonit = 0 ;
			break ;
		}




		/*%C Next Step is Write at the end of File */
		case Usb_WriteAtTheEndOfFile :
		{
			if (DRV_TREND_New_Data == TRUE)
			{
				/*%C To update Nand buffer state on end of Spi transmit */
				UsbFlashTrasnferRunning = USB_NAND_TREND_TRANSFER_RUNNING ;
				/*%C Build the frame */
			  	DRV_USB_WriteAtTheEndOfFile(CurrentUsbKey,
				 							DRV_TREND_UART_Buffer_Var,
									 		DRV_TREND_Received_Data);

				NbBytesUsbWrittenFlashMonit 
										=	NbBytesUsbWrittenFlashMonit
										+	(UWORD32)DRV_TREND_Received_Data ;
				
				/*%C Re Init recived datas */
				DRV_TREND_Received_Data = 0 ;


				if (NbBytesUsbWrittenFlashMonit > NbBytesMonitoringFlashTrendToWrite)
				{
					NbBytesUsbWrittenFlashMonit = 0;
					NbBytesMonitoringFlashTrendToWrite = 0 ;
					Step_UsbTransferApply = Usb_CloseFile ;
					DRV_TREND_Read_Request = ENDED ;
					UsbFlashTrasnferRunning = USB_NAND_TRANSFER_IDLE ;
				}
				else
				{
					/*%C No Function */
				}
				/*%C Flash is Ready, reset flag */
				FlashReadyLoop = 0 ;
			}
			else
			{
				/*%C Frame isn't ready to be Send */
				FrameReadyToSend = FALSE ;

				/*%C If the Flash isn't Ready to transfer after 10s, */
				/*%C Stop transfer */
				FlashReadyLoop = FlashReadyLoop + 1 ;
				if(FlashReadyLoop > 2000)
				{
					FlashReadyLoop = 0 ;
					NbBytesUsbWrittenFlashMonit = 0;
					NbBytesMonitoringFlashTrendToWrite = 0 ;
					Step_UsbTransferApply = Usb_CloseFile ;
					DRV_TREND_Read_Request = ENDED ;
					UsbFlashTrasnferRunning = USB_NAND_TRANSFER_IDLE ;
				}
			}
			break ;
		 }




		/*%C Next Step is close the File */
		case Usb_CloseFile :
		{
			/*%C Update USB DataBase */
			DB_UsbWrite(USB_TREND_TRANSFER_SELECT_U16 , FALSE);
			DB_UsbWrite(USB_EVENTS_TRANSFER_U16 , TRUE);
			DB_UsbWrite(USB_TREND_TRANSFER_U16 , FALSE);

			/*%C Re Init this flag to the next transfert */
			FirstRemaningTimeApproximation = TRUE ;
			/*%C Build the frame */
			DRV_USB_CloseFile(CurrentUsbKey) ;
			/*%C Re Init the step */
			Step_UsbTransferApply = Usb_FirstStep ;
			UsbFlashInUse = FALSE;
			break ;
		}


				

		default:
		{
			/*%C Frame isn't ready to be Send */ 
			FrameReadyToSend =	FALSE ;
			break ;
		}
	}
}