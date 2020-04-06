/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DB_KeyboardEventRead.c 														*/
/*                                                            				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/* 			Description fonctionnelle:		 	                        	      */
/*                                                                      	   */
/*  "KeyboardEvent" read function		                                     	*/
/*          	                                                               */
/*                                                            				      */
/******************************************************************************/
/*%I 	Input Parameter : 			Id   		        			                  	*/
/*%IO Input/Output Parameter : 	None 	        			                  		*/
/*%O 	Output Parameter : 			None      	                 				  		*/
/******************************************************************************/

/******************************************************************************/
/*                              INCLUDE FILES		                           */
/******************************************************************************/

#include "typedef.h"
#include "DB_KeyboardEvent.h"

/******************************************************************************/
/*                       FUNCTION BODY               	                        */
/******************************************************************************/

UWORD16 DB_KeyboardEventRead(e_DB_KEYBOARD_EVENT_ID Id)
{
/*%C Read the parameter value in the keyboard event array, function of Id     */
   return (DB_KeyboardEvent[Id]);
}
