/*
 * MasterDeviceBase.h
 *
 *  Created on: 06.06.2023
 *      Author: Christian Roth
 */

#ifndef INC_Generic_SPI_MASTERMODE_MASTERDEVICEBASE_H_
#define INC_Generic_SPI_MASTERMODE_MASTERDEVICEBASE_H_

#include "../Generic_Error.h"
#include "../Generic_GPIO/Generic_GPIO.h"


typedef struct Generic_SPI_MasterDeviceBase sGeneric_SPI_MasterDeviceBase_t;
struct Generic_SPI_MasterDeviceBase
{
    sGeneric_GPIO_t nCS;
    
	/**
	 * @brief: Transmits data through the SPI bus. ! This is a pure virtual function.
	 *
	 * @param: _this : A pointer to this struct :: so e.g (sGeneric_SPI_MasterDeviceBase_t)a->eSendData(a, data, size).
	 *  				 This is used for inheritance and polymorphism.
	 *  			     Inheriting classes should input their own pointer.
	 * @param: pu8Data : The data array which should get send.
	 * @param: u8Size  : The length of the given data array.
	 *
	 * @return Generic_SUCCESS : Success.
	 * 		  Generic_FAIL    : _this has the wrong SPI DuplexMode selected.
	 * 		  Generic_ERROR   : An error occurred.
	 */
	eGeneric_Status(*eTransmitData)(sGeneric_SPI_MasterDeviceBase_t* const _this, uint8_t const* const pu8Data, uint16_t u8Size);

	/**
	 * @brief: Receives data through the SPI bus. ! This is a pure virtual function.
	 *
	 * @param: _this : A pointer to this struct :: so e.g (sGeneric_SPI_MasterDeviceBase_t)a->eReceiveData(a, data, size).
	 *  				 This is used for inheritance and polymorphism.
	 *  			     Inheriting classes should input their own pointer.
	 * @param: pu8Data : The array which should get filled with the received data.
	 * @param: u8Size  : The length of the given data array.
	 *
	 * @return Generic_SUCCESS : Success.
	 * 		  Generic_FAIL    : _this has the wrong SPI DuplexMode selected.
	 * 		  Generic_ERROR   : An error occurred.
	 */
	eGeneric_Status(*eReceiveData)(sGeneric_SPI_MasterDeviceBase_t* const _this, uint8_t* const pu8Data, uint16_t u8Size);

	/**
	 * @brief: Transmits and receives data through the SPI bus. ! This is a pure virtual function.
	 *
	 * @param: _this : A pointer to this struct :: so e.g (sGeneric_SPI_MasterDeviceBase_t)a->eSendReceiveData(a, data, size).
	 *  				 This is used for inheritance and polymorphism.
	 *  			     Inheriting classes should input their own pointer.
	 * @param: pu8TransmitData : The data array which should get send.
	 * @param: pu8ReceiveData  : The array which should get filled with the received data.
	 * @param: u8Size  		   : The length of the given arrays.
	 *
	 * @return Generic_SUCCESS : Success.
	 * 		  Generic_FAIL    : _this has the wrong SPI DuplexMode selected.
	 * 		  Generic_ERROR   : An error occurred.
	 */
	eGeneric_Status(*eTransmitReceiveData)(sGeneric_SPI_MasterDeviceBase_t* const _this, uint8_t const* const pu8TransmitData, uint8_t* const pu8ReceiveData, uint8_t u8Size);

};


#endif /* INC_Generic_I2C_MASTERMODE_MASTERDEVICEBASE_H_ */
