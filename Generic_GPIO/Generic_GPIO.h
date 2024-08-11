/*
 * Generic_GPIO.h
 *
 *  Created on: 03.07.2023
 *      Author: Christian Roth
 */

#ifndef Generic_GPIO_Generic_GPIO_H_
#define Generic_GPIO_Generic_GPIO_H_

#include <stdint.h>



typedef struct Generic_GPIO_Base sGeneric_GPIO_t;
struct Generic_GPIO_Base
{
	uint32_t GPIO_Pin;
	uint32_t GPIO_Port;

	/**
	 * @brief: Sets the given GPIO to high.
	 * @param: The GPIO that should be set to high.
	 */
	void (*vSetGPIO)(sGeneric_GPIO_t* const psGPIO);

	/**
	 * @brief: Sets the given GPIO to low.
	 * @param: The GPIO that should be set to low.
	 */
	void (*vResetGPIO)(sGeneric_GPIO_t* const psGPIO);

};



#endif /* Generic_GPIO_Generic_GPIO_H_ */
