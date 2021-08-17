//FlashSST25.c
#include "FlashSST25.h"
#include "stdint.h"
#include "main.h"



/*********************************************************************
 *
 *  SPI Flash Memory Driver
 * 
 *********************************************************************/
SPI_HandleTypeDef SpiHandle;
int32_t dwWriteAddr;
DeviceCaps deviceCaps;

void InitSPI2(void)
{
  /*##-1- Configure the SPI peripheral #######################################*/
  /* Set the SPI parameters */
  SpiHandle.Instance               = SPI2;
  SpiHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  SpiHandle.Init.Direction         = SPI_DIRECTION_2LINES;
  SpiHandle.Init.CLKPhase          = SPI_PHASE_2EDGE;
  SpiHandle.Init.CLKPolarity       = SPI_POLARITY_HIGH;
  SpiHandle.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLED;
  SpiHandle.Init.CRCPolynomial     = 7;
  SpiHandle.Init.DataSize          = SPI_DATASIZE_8BIT;
  SpiHandle.Init.FirstBit          = SPI_FIRSTBIT_MSB;
  SpiHandle.Init.NSS               = SPI_NSS_SOFT;
  SpiHandle.Init.TIMode            = SPI_TIMODE_DISABLED;


  SpiHandle.Init.Mode = SPI_MODE_MASTER;

  if(HAL_SPI_Init(&SpiHandle) != HAL_OK)
  {
    /* Initialization Error */
    //Error_Handler();
		//int err = 1;
  }
	
}	
//------------------------------------------------------------------------------------
unsigned char SPI_ReadWriteByte(unsigned char data_write) 
{ 
  unsigned char data_read = 0;
	
	unsigned char aTxSPIBuffer[2]; 
	unsigned char aRxSPIBuffer[2];
	
	
	aTxSPIBuffer[0] = data_write;
	switch(HAL_SPI_TransmitReceive(&SpiHandle, (uint8_t*)aTxSPIBuffer, (uint8_t *)aRxSPIBuffer, 1, 500))
  {
    case HAL_OK:
      break;

    case HAL_TIMEOUT:
      break;

    case HAL_ERROR:
      break;
    default:
      break;
  }

	data_read = aRxSPIBuffer[0];
  return (unsigned char)data_read; 
}

//------------------------------------------------------------------------------------
uint16_t SPI_ReadWriteWord(uint16_t data_write) 
{ 
  uint16_t data_read = 0;
	
	unsigned char aTxSPIBuffer[2]; 
//	unsigned char aRxSPIBuffer[2];
	
	
	aTxSPIBuffer[0] = data_write;
	switch(HAL_SPI_TransmitReceive(&SpiHandle, (uint8_t*)aTxSPIBuffer, (uint8_t *)&data_read, 1, 500))
  {
    case HAL_OK:
      break;

    case HAL_TIMEOUT:
      break;

    case HAL_ERROR:
      break;
    default:
      break;
  }

//	data_read = aRxSPIBuffer[0];
  return data_read; 
}
//------------------------------------------------------------------------------------

/*****************************************************************************
  Function:
    void SPIFlashInit(void)

  Description:
    Initializes SPI Flash module.

  Precondition:
    None

  Parameters:
    None

  Returns:
    None

  Remarks:
    This function is only called once during the lifetime of the application.

  Internal:
    This function sends WRDI to clear any pending write operation, and also
    clears the software write-protect on all memory locations.
  ***************************************************************************/
void SPIFlashInit(void)
{
    uint8_t i;
    volatile uint8_t Dummy;
	  uint16_t manufacturer;
    uint16_t memory;
    uint16_t capacity;
 
		InitSPI1();

        // Read Device ID code to determine supported device capabilities/instructions
        
					SET_CE;


            // Activate chip select
						SET_HOLD;
						CLR_CE;
        
            // Send instruction
            Dummy = SPI_ReadWriteByte(JEDEC_ID);
                
            manufacturer = SPI_ReadWriteByte(0);
            memory = SPI_ReadWriteByte(0);
            capacity = SPI_ReadWriteByte(0);

            // Deactivate chip select
            SET_CE;

                // Decode Device Capabilities Flags from Device ID
                deviceCaps.v = 0x00;
								if (manufacturer == SST26_MANUFACTURER && memory == SST26_MEMORY_TYPE)
								{
									/* Okay.. is it a FLASH capacity that we understand? */

//									if (capacity == SST26_SST26VF064_CAPACITY)
//										{
//											 /* Save the FLASH geometry */

////											 priv->sectorshift = SST26_SST26VF064_SECTOR_SHIFT;
////											 priv->nsectors    = SST26_SST26VF064_NSECTORS;
////											 priv->pageshift   = SST26_SST26VF064_PAGE_SHIFT;
////											 priv->npages      = SST26_SST26VF064_NPAGES;
//											 deviceCaps.bits.bPageProgram = 1;
//										}
//									else 
										if (capacity == SST26_SST26VF032_CAPACITY)
										{
											 /* Save the FLASH geometry */

//											 priv->sectorshift = SST26_SST26VF032_SECTOR_SHIFT;
//											 priv->nsectors    = SST26_SST26VF032_NSECTORS;
//											 priv->pageshift   = SST26_SST26VF032_PAGE_SHIFT;
//											 priv->npages      = SST26_SST26VF032_NPAGES;
											 deviceCaps.bits.bPageProgram = 1;
										}
								}

		sst26_globalunlock();

    // Clear any pre-existing AAI write mode
    // This may occur if the PIC is reset during a write, but the Flash is
    // not tied to the same hardware reset.
//    _SendCmd(WRDI);

    // Execute Enable-Write-Status-Register (EWSR) instruction
//    _SendCmd(EWSR);

    // Clear Write-Protect on all memory locations
//		CLR_CE;

		// Send instruction
//		Dummy = SPI_ReadWriteByte(WRSR);
//		Dummy = SPI_ReadWriteByte(0);
    // Deactivate chip select
//    SET_CE;	
}

/*****************************************************************************
  Function:
    void SPIFlashReadArray(DWORD dwAddress, uint8_t *vData, WORD wLength)

  Description:
    Reads an array of bytes from the SPI Flash module.

  Precondition:
    SPIFlashInit has been called, and the chip is not busy (should be
    handled elsewhere automatically.)

  Parameters:
    dwAddress - Address from which to read
    vData - Where to store data that has been read
    wLength - Length of data to read

  Returns:
    None
  ***************************************************************************/
void SPIFlashReadArray(uint32_t dwAddress, uint8_t *vData, uint16_t wLength)
{
    volatile uint8_t Dummy = 0;
 
    // Ignore operations when the destination is NULL or nothing to read
    if(vData == NULL || wLength == 0)
        return;

    // Clear Write-Protect on all memory locations
		CLR_CE;

		// Send READ opcode
		Dummy = SPI_ReadWriteByte(READ);
		Dummy = SPI_ReadWriteByte(((uint8_t*)&dwAddress)[2]);
		Dummy = SPI_ReadWriteByte(((uint8_t*)&dwAddress)[1]);
		Dummy = SPI_ReadWriteByte(((uint8_t*)&dwAddress)[0]);
		

    // Read data
    while(wLength--)
    {
			*vData++ = SPI_ReadWriteByte(((uint8_t*)&dwAddress)[0]);
    }

 
 // Deactivate chip select
    SET_CE;		

}

/*****************************************************************************
  Function:
    void SPIFlashBeginWrite(DWORD dwAddr)

  Summary:
    Prepares the SPI Flash module for writing.

  Description:
    Prepares the SPI Flash module for writing.  Subsequent calls to
    SPIFlashWrite or SPIFlashWriteArray will begin at this location and
    continue sequentially.

    SPI Flash

  Precondition:
    SPIFlashInit has been called.

  Parameters:
    dwAddr - Address where the writing will begin

  Returns:
    None

  Remarks:
    Flash parts have large sector sizes, and can only erase entire sectors
    at once.  The SST parts for which this library was written have sectors
    that are 4kB in size.  Your application must ensure that writes begin on
    a sector boundary so that the SPIFlashWrite functions will erase the
    sector before attempting to write.  Entire sectors need not be written
    at once, so applications can begin writing to the front of a sector,
    perform other tasks, then later call SPIFlashBeginWrite and point to an
    address in this sector that has not yet been programmed.  However, care
    must taken to ensure that writes are not attempted on addresses that are
    not in the erased state.  The chip will provide no indication that the
    write has failed, and will silently ignore the command.
  ***************************************************************************/
void SPIFlashBeginWrite(uint32_t dwAddr)
{
    dwWriteAddr = dwAddr;
}

/*****************************************************************************
  Function:
    void SPIFlashWrite(uint8_t vData)

  Summary:
    Writes a byte to the SPI Flash part.

  Description:
    This function writes a byte to the SPI Flash part.  If the current
    address pointer indicates the beginning of a 4kB sector, the entire
    sector will first be erased to allow writes to proceed.  If the current
    address pointer indicates elsewhere, it will be assumed that the sector
    has already been erased.  If this is not true, the chip will silently
    ignore the write command.

  Precondition:
    SPIFlashInit and SPIFlashBeginWrite have been called, and the current
    address is either the front of a 4kB sector or has already been erased.

  Parameters:
    vData - The byte to write to the next memory location.

  Returns:
    None

  Remarks:
    See Remarks in SPIFlashBeginWrite for important information about Flash
    memory parts.
  ***************************************************************************/
void SPIFlashWrite(uint8_t vData)
{
    volatile uint8_t Dummy = 0;

    // If address is a boundary, erase a sector first
    if((dwWriteAddr & SPI_FLASH_SECTOR_MASK) == 0u)
        SPIFlashEraseSector(dwWriteAddr);

    // Enable writing
    _SendCmd(WREN);

    // Activate the chip select
    CLR_CE;

    // Issue WRITE command with address
		Dummy = SPI_ReadWriteByte(WRITE);
		Dummy = SPI_ReadWriteByte(((uint8_t*)&dwWriteAddr)[2]);
		Dummy = SPI_ReadWriteByte(((uint8_t*)&dwWriteAddr)[1]);
		Dummy = SPI_ReadWriteByte(((uint8_t*)&dwWriteAddr)[0]);

    // Write the byte
		Dummy = SPI_ReadWriteByte(vData);
    dwWriteAddr++;

    // Deactivate chip select and wait for write to complete
		SET_CE;
    _WaitWhileBusy();

    // Restore SPI state
//     SPI_ON_BIT = 0;
//     SPIFLASH_SPICON1 = SPICON1Save;
//     SPI_ON_BIT = vSPIONSave;
}

/*****************************************************************************
  Function:
    void SPIFlashWriteArray(uint8_t* vData, WORD wLen)

  Summary:
    Writes an array of bytes to the SPI Flash part.

  Description:
    This function writes an array of bytes to the SPI Flash part.  When the
    address pointer crosses a sector boundary (and has more data to write),
    the next sector will automatically be erased.  If the current address
    pointer indicates an address that is not a sector boundary and is not
    already erased, the chip will silently ignore the write command until the
    next sector boundary is crossed.

  Precondition:
    SPIFlashInit and SPIFlashBeginWrite have been called, and the current
    address is either the front of a sector or has already been erased.

  Parameters:
    vData - The array to write to the next memory location
    wLen - The length of the data to be written

  Returns:
    None

  Remarks:
    See Remarks in SPIFlashBeginWrite for important information about Flash
    memory parts.
  ***************************************************************************/
void SPIFlashWriteArray(uint8_t* vData, uint16_t wLen)
{
    volatile uint8_t Dummy;
	  uint8_t isStarted;
    uint8_t vOpcode;
    uint8_t i;
	

        // Do nothing if no data to process
        if(wLen == 0u)
                return;

    // If starting at an odd address, write a single byte
    if((dwWriteAddr & 0x01) && wLen)
    {
        SPIFlashWrite(*vData);
        vData++;
        wLen--;
    }

        // Assume we are using AAI Word program mode unless changed later
        vOpcode = WRITE_WORD_STREAM;    

    isStarted = 0;

    // Loop over all remaining WORDs
    while(wLen > 1)
    {
        // Don't do anything until chip is ready
        _WaitWhileBusy();

        // If address is a sector boundary
        if((dwWriteAddr & SPI_FLASH_SECTOR_MASK) == 0)
            SPIFlashEraseSector(dwWriteAddr);

        // If not yet started, initiate AAI mode
        if(!isStarted)
        {
            // Enable writing
            _SendCmd(WREN);

                        // Select appropriate programming opcode.  The WRITE_WORD_STREAM 
                        // mode is the default if neither of these flags are set.
                if(deviceCaps.bits.bWriteByteStream)
                    vOpcode = WRITE_BYTE_STREAM;
                        else if(deviceCaps.bits.bPageProgram)
                        {
                                // Note: Writing one byte at a time is extremely slow (ex: ~667 
                                // bytes/second write speed on SST SST25VF064C).  You can 
                                // improve this by over a couple of orders of magnitude by 
                                // writing a function to write full pages of up to 256 bytes at 
                                // a time.  This is implemented this way only because I don't 
                                // have an SST25VF064C handy to test with right now. -HS
                                while(wLen--)
                                SPIFlashWrite(*vData++);
                                return;
                        }

            // Activate the chip select
					 // Clear Write-Protect on all memory locations
						CLR_CE;

						// Issue WRITE_xxx_STREAM command with address
						Dummy = SPI_ReadWriteByte(vOpcode);
						Dummy = SPI_ReadWriteByte(((uint8_t*)&dwWriteAddr)[2]);
						Dummy = SPI_ReadWriteByte(((uint8_t*)&dwWriteAddr)[1]);
						Dummy = SPI_ReadWriteByte(((uint8_t*)&dwWriteAddr)[0]);												

            isStarted = 1;
        }
        // Otherwise, just write the AAI command again
        else
        {
						CLR_CE;
					
						Dummy = SPI_ReadWriteByte(vOpcode);
        }

        // Write a byte or two
        for(i = 0; i <= deviceCaps.bits.bWriteWordStream; i++)
        {
								Dummy = SPI_ReadWriteByte(*vData++);
								dwWriteAddr++;
                wLen--;
                
        }

        // Release the chip select to begin the write
        SET_CE;

        // If a boundary was reached, end the write
        if((dwWriteAddr & SPI_FLASH_SECTOR_MASK) == 0)
        {
            _WaitWhileBusy();
            _SendCmd(WRDI);
            isStarted = 0;
        }
    }

    // Wait for write to complete, then exit AAI mode
    _WaitWhileBusy();
    _SendCmd(WRDI);

    // If a byte remains, write the odd address
    if(wLen)
        SPIFlashWrite(*vData);

}

/*****************************************************************************
  Function:
    void SPIFlashEraseSector(DWORD dwAddr)

  Summary:
    Erases a sector.

  Description:
    This function erases a sector in the Flash part.  It is called
    internally by the SPIFlashWrite functions whenever a write is attempted
    on the first byte in a sector.

  Precondition:
    SPIFlashInit has been called.

  Parameters:
    dwAddr - The address of the sector to be erased.

  Returns:
    None

  Remarks:
    See Remarks in SPIFlashBeginWrite for important information about Flash
    memory parts.
  ***************************************************************************/
void SPIFlashEraseSector(int32_t dwAddr)
{
    volatile uint8_t Dummy;

    // Enable writing
    _SendCmd(WREN);

    // Activate the chip select
		CLR_CE;
		// Issue ERASE command with address
		Dummy = SPI_ReadWriteByte(ERASE_4K);
    Dummy = SPI_ReadWriteByte(((uint8_t*)&dwAddr)[2]);
		Dummy = SPI_ReadWriteByte(((uint8_t*)&dwAddr)[1]);
		Dummy = SPI_ReadWriteByte(((uint8_t*)&dwAddr)[0]);		



    // Deactivate chip select to perform the erase
    SET_CE;

    // Wait for erase to complete
    _WaitWhileBusy();
}

/*****************************************************************************
  Function:
    void SPIFlashEraseSST25()

  Summary:
    Erases a sector.

  Description:
    This function erases a sector in the Flash part.  It is called
    internally by the SPIFlashWrite functions whenever a write is attempted
    on the first byte in a sector.

  Precondition:
    SPIFlashInit has been called.

  Parameters:
    dwAddr - The address of the sector to be erased.

  Returns:
    None

  Remarks:
    See Remarks in SPIFlashBeginWrite for important information about Flash
    memory parts.
  ***************************************************************************/
void SPIFlashEraseSST25(void)
{
    volatile uint8_t Dummy;

    // Enable writing
    _SendCmd(WREN);

    // Activate the chip select
		CLR_CE;
		// Issue ERASE command with address
		Dummy = SPI_ReadWriteByte(SST26_CE);

    // Deactivate chip select to perform the erase
    SET_CE;

    // Wait for erase to complete
    _WaitWhileBusy();
}


/*****************************************************************************
  Function:
    static void _SendCmd(uint8_t cmd)

  Summary:
    Sends a single-byte command to the SPI Flash part.

  Description:
    This function sends a single-byte command to the SPI Flash part.  It is
    used for commands such as WREN, WRDI, and EWSR that must have the chip
    select activated, then deactivated immediately after the command is
    transmitted.

  Precondition:
    SPIFlashInit has been called.

  Parameters:
    cmd - The single-byte command code to send

  Returns:
    None
  ***************************************************************************/
void _SendCmd(uint8_t cmd)
{
    // Activate chip select
					SET_HOLD;
					CLR_CE;
        
          // Send instruction
          cmd = SPI_ReadWriteByte(cmd);
                
          // Deactivate chip select
          SET_CE;
}


/*****************************************************************************
  Function:
    static void _WaitWhileBusy(void)

  Summary:
    Waits for the SPI Flash part to indicate it is idle.

  Description:
    This function waits for the SPI Flash part to indicate it is idle.  It is
    used in the programming functions to wait for operations to complete.

  Precondition:
    SPIFlashInit has been called.

  Parameters:
    None

  Returns:
    None
  ***************************************************************************/
void _WaitWhileBusy(void)
{
    volatile uint8_t Dummy;

    // Activate chip select
		SET_HOLD;
		CLR_CE;

    // Send Read Status Register instruction
    Dummy = SPI_ReadWriteByte(RDSR);

    // Poll the BUSY bit
    do
    {
				Dummy = SPI_ReadWriteByte(0x00);
    } while(Dummy & BUSY);

    // Deactivate chip select
		SET_CE;
}

/*****************************************************************************
  Function:
    static void _GetStatus()

  Summary:
    Reads the status register of the part.

  Description:
    This function reads the status register of the part.  It was written
    for debugging purposes, and is not needed for normal operation.  Place
    a breakpoint at the last instruction and check the "status" variable to
    see the result.

  Precondition:
    SPIFlashInit has been called.

  Parameters:
    None

  Returns:
    None
  ***************************************************************************/
void _GetStatus()
{
 volatile uint8_t Dummy;
 static uint8_t statuses[16];
 static uint8_t *status = statuses;

  // Activate chip select
		SET_HOLD;
		CLR_CE;

  // Send Read Status Register instruction
		Dummy = SPI_ReadWriteByte(RDSR);
		*status = SPI_ReadWriteByte(0x00);

  status++;

  // Deactivate chip select
	SET_CE;

 if(status == &statuses[10])
     statuses[15] = 0;
}
//////////////////////////////////////////////////////////////////////
void sst26_pagewrite(uint8_t *buffer, uint16_t page)
{
  uint32_t offset = page << SST26_SST26VF064_PAGE_SHIFT;
	volatile uint8_t Dummy;
	uint16_t i = 0;
//  sstinfo("page: %08lx offset: %08lx\n", (long)page, (long)offset);

    // Enable writing
    _SendCmd(WREN);

    // Activate the chip select
		CLR_CE;
		// Issue ERASE command with address
		Dummy = SPI_ReadWriteByte(SST26_PP);
	
  SPI_ReadWriteByte( (offset >> 16) & 0xff);
  SPI_ReadWriteByte( (offset >> 8) & 0xff);
  SPI_ReadWriteByte( offset & 0xff);

  /* Then write the specified number of bytes */

          // Write a byte or two
        for(i = 0; i < 256; i++)
        {
								Dummy = SPI_ReadWriteByte(*buffer++);
								dwWriteAddr++;
        }

    // Deactivate chip select to perform the erase
    SET_CE;

    // Wait for erase to complete
    _WaitWhileBusy();
				
		_SendCmd(WRDI);		

}
///////////////////////////////////////////////////////////////////////////////////
void sst26_globalunlock(void)
{
	// Enable writing
		_SendCmd(WREN);
    _SendCmd(SST26_ULBPR);
	  _SendCmd(WRDI);
}

