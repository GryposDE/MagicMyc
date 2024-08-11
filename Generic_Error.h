/*
 * Generic_Error.h
 *
 *  Created on: Apr 14, 2023
 *      Author: Christian Roth
 */

#ifndef Generic_ERROR_H
#define Generic_ERROR_H

#ifndef INC_Generic_ERROR_H_
#define INC_Generic_ERROR_H_

#include <stdint.h>

typedef enum
{
	Generic_SUCCESS = 0,
	Generic_FAIL 	= 1,
	Generic_ERROR	= 2

} eGeneric_Status;

#endif /* INC_Generic_ERROR_H_ */


#endif /* Generic_ERROR_H */
