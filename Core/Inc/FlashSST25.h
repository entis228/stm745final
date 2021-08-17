//FlashSST25.h
#ifndef 	FLASH_SST25_H
#define 	FLASH_SST25_H

#include "stdint.h"

/* Configuration ********************************************************************/
/* Per the data sheet, SST26 parts can be driven with either SPI mode 0 (CPOL=0 and
 * CPHA=0) or mode 3 (CPOL=1 and CPHA=1).  So you may need to specify
 * CONFIG_SST26_SPIMODE to select the best mode for your device.  If
 * CONFIG_SST26_SPIMODE is not defined, mode 0 will be used.
 */

#ifndef CONFIG_SST26_SPIMODE
#  define CONFIG_SST26_SPIMODE SPIDEV_MODE0
#endif

/* SPI Frequency.  May be up to 104 MHz. */

#ifndef CONFIG_SST26_SPIFREQUENCY
#  define CONFIG_SST26_SPIFREQUENCY 20000000
#endif

/* Various manufacturers may have produced the parts.  0xBF is the manufacturer ID
 * for the SST serial FLASH.
 */

#ifndef CONFIG_SST26_MANUFACTURER
#  define CONFIG_SST26_MANUFACTURER 0xBF
#endif

#ifndef CONFIG_SST26_MEMORY_TYPE
#  define CONFIG_SST26_MEMORY_TYPE  0x26
#endif

/* SST26 Registers *******************************************************************/
/* Indentification register values */

#define SST26_MANUFACTURER         CONFIG_SST26_MANUFACTURER
#define SST26_MEMORY_TYPE          CONFIG_SST26_MEMORY_TYPE

#define SST26_SST26VF016_CAPACITY    0x41 /* 16 M-bit */
#define SST26_SST26VF032_CAPACITY    0x42 /* 32 M-bit */
#define SST26_SST26VF064_CAPACITY    0x43 /* 64 M-bit */

/* SST26VF016 capacity is 2,097,152 bytes:
 * (512 sectors) * (4,096 bytes per sector)
 * (8192 pages) * (256 bytes per page)
 */

#define SST26_SST26VF016_SECTOR_SHIFT  12    /* Sector size 1 << 15 = 65,536 */
#define SST26_SST26VF016_NSECTORS      512
#define SST26_SST26VF016_PAGE_SHIFT    8     /* Page size 1 << 8 = 256 */
#define SST26_SST26VF016_NPAGES        8192

/* SST26VF032 capacity is 4,194,304 bytes:
 * (1,024 sectors) * (4,096 bytes per sector)
 * (16,384 pages) * (256 bytes per page)
 */

#define SST26_SST26VF032_SECTOR_SHIFT  12    /* Sector size 1 << 15 = 65,536 */
#define SST26_SST26VF032_NSECTORS      1024
#define SST26_SST26VF032_PAGE_SHIFT    8     /* Page size 1 << 8 = 256 */
#define SST26_SST26VF032_NPAGES        16384

/* SST26VF064 capacity is 8,388,608 bytes:
 * (2,048 sectors) * (4,096 bytes per sector)
 * (32,768 pages) * (256 bytes per page)
 */

#define SST26_SST26VF064_SECTOR_SHIFT  12    /* Sector size 1 << 15 = 65,536 */
#define SST26_SST26VF064_NSECTORS      2048
#define SST26_SST26VF064_PAGE_SHIFT    8     /* Page size 1 << 8 = 256 */
#define SST26_SST26VF064_NPAGES        32768

/* Instructions */
/*      Command         Value      NN Description                  Addr Dummy  Data */
#define SST26_NOP       0x00    /* 14 No Operation                    0   0   0     */
#define SST26_RSTEN     0x66    /* 14 Reset Enable                    0   0   0     */
#define SST26_RST       0x99    /* 14 Reset Memory                    0   0   0     */
#define SST26_EQIO      0x38    /* 1  Enable Quad I/O                 0   0   0     */
#define SST26_RSTQIO    0xFF    /*  4 Reset Quad I/O                  0   0   0     */
#define SST26_RDSR      0x05    /* 1  Read Status Register            0   0   >=1   */
                                /*  4 Read Status Register            0   1   >=1   */
#define SST26_WRSR      0x01    /* 14 Write Status Register           0   0   2     */
#define SST26_RDCR      0x35    /* 1  Read Config Register            0   0   >=1   */
                                /*  4 Read Config Register            0   1   >=1   */

#define SST26_READ      0x03    /* 1  Read Data Bytes                 3   0   >=1   */
#define SST26_FAST_READ 0x0b    /* 1  Higher speed read               3   1   >=1   */
                                /*  4 Higher speed read               3   3   >=1   */
#define SST26_SQOR      0x6b    /* 1  SQI Output Read                 3   1   >=1   */
#define SST26_SQIOR     0xeb    /* 1  SQI I/O Read                    3   3   >=1   */
#define SST26_SDOR      0x3b    /* 1  SDI Output Read                 3   1   >=1   */
#define SST26_SDIOR     0xbb    /* 1  SDI I/O Read                    3   1   >=1   */
#define SST26_SB        0xc0    /* 14 Set Burst Length                0   0   1     */
#define SST26_RBSQI     0x0c    /*  4 SQI Read Burst w/ Wrap          3   3   >=1   */
#define SST26_RBSPI     0xec    /* 1  SPI Read Burst w/ Wrap          3   3   >=1   */

#define SST26_RDID      0x9f    /* 1  Read Identification             0   0   >=3   */
#define SST26_QRDID     0xaf    /*  4 Quad Read Identification        0   1   >=3   */
#define SST26_SFDP      0x5a    /* 1  Serial Flash Discov. Par.       3   1   >=1   */

#define SST26_WREN      0x06    /* 14 Write Enable                    0   0   0     */
#define SST26_WRDI      0x04    /* 14 Write Disable                   0   0   0     */
#define SST26_SE        0x20    /* 14 Sector Erase                    3   0   0     */
#define SST26_BE        0xd8    /* 14 8/32/64K Block Erase            3   0   0     */
#define SST26_CE        0xc7    /* 14 Chip Erase                      0   0   0     */
#define SST26_PP        0x02    /* 1  Page Program                    3   0   1-256 */
#define SST26_QPP       0x32    /* 1  Quad Page Program               3   0   1-256 */
#define SST26_WRSU      0xb0    /* 14 Suspend Program/Erase           0   0   0     */
#define SST26_WRRE      0x30    /* 14 Resume Program/Erase            0   0   0     */

#define SST26_RBPR      0x72    /* 1  Read Block-Protection reg       0   0   1-18  */
                                /*  4 Read Block-Protection reg       0   1   1-18  */
#define SST26_WBPR      0x42    /* 14 Write Block-Protection reg      0   0   1-18  */
#define SST26_LBPR      0x8d    /* 14 Lock down Block-Prot. reg       0   0   0     */
#define SST26_NVWLDR    0xe8    /* 14 non-Volatile Write L-D reg      0   0   1-18  */
#define SST26_ULBPR     0x98    /* 14 Global Block Protection unlock  0   0   0     */
#define SST26_RSID      0x88    /* 14 Read Security ID                2   1   1-2048*/ 
                                /*  4 Read Security ID                2   3   1-2048*/
#define SST26_PSID      0xa5    /* 14 Program User Security ID area   2   0   1-256 */
#define SST26_LSID      0x85    /* 14 Lockout Security ID programming 0   0   0     */

/* NOTE 1: All parts.
 * NOTE 2: In SST26VF064 terminology, 0xd8 is block erase and 0x20
 *         is a sector erase.  Block erase provides a faster way to erase
 *         multiple 4K sectors at once.
 */

/* Status register bit definitions */

#define SST26_SR_WIP              (1 << 0)                /* Bit 0: Write in progress */
#define SST26_SR_WEL              (1 << 1)                /* Bit 1: Write enable latch */
#define SST26_SR_WSE              (1 << 2)                /* Bit 2: Write Suspend-Erase Status */
#define SST26_SR_WSP              (1 << 3)                /* Bit 3: Write Suspend-Program Status */
#define SST26_SR_WPLD             (1 << 4)                /* Bit 4: Write Protection Lock-Down Status */
#define SST26_SR_SEC              (1 << 5)                /* Bit 5: Security ID status */
#define SST26_SR_RES              (1 << 6)                /* Bit 6: RFU */
#define SST26_SR_WIP2             (1 << 7)                /* Bit 7: Write in progress */

#define SST26_DUMMY     0xa5

#define READ                            0x03    // SPI Flash opcode: Read up up to 25MHz
#define READ_FAST                       0x0B    // SPI Flash opcode: Read up to 50MHz with 1 dummy byte
#define ERASE_4K                        0x20    // SPI Flash opcode: 4KByte sector erase
#define ERASE_32K                       0x52    // SPI Flash opcode: 32KByte block erase
#define ERASE_SECTOR            0xD8    // SPI Flash opcode: 64KByte block erase
#define ERASE_ALL                       0x60    // SPI Flash opcode: Entire chip erase
#define WRITE                           0x02    // SPI Flash opcode: Write one byte (or a page of up to 256 bytes, depending on device)
#define WRITE_WORD_STREAM       0xAD    // SPI Flash opcode: Write continuous stream of 16-bit words (AAI mode); available on SST25VF016B (but not on SST25VF010A)
#define WRITE_BYTE_STREAM       0xAF    // SPI Flash opcode: Write continuous stream of bytes (AAI mode); available on SST25VF010A (but not on SST25VF016B)
#define RDSR                            0x05    // SPI Flash opcode: Read Status Register
#define EWSR                            0x50    // SPI Flash opcode: Enable Write Status Register
#define WRSR                            0x01    // SPI Flash opcode: Write Status Register
#define WREN                            0x06    // SPI Flash opcode: Write Enable
#define WRDI                            0x04    // SPI Flash opcode: Write Disable / End AAI mode
#define RDID                            0x90    // SPI Flash opcode: Read ID
#define JEDEC_ID                        0x9F    // SPI Flash opcode: Read JEDEC ID
#define EBSY                            0x70    // SPI Flash opcode: Enable write BUSY status on SO pin
#define DBSY                            0x80    // SPI Flash opcode: Disable write BUSY status on SO pin

#define BUSY    0x01    // Mask for Status Register BUSY (Internal Write Operaiton in Progress status) bit
#define WEL     0x02    // Mask for Status Register WEL (Write Enable status) bit
#define BP0     0x04    // Mask for Status Register BP0 (Block Protect 0) bit
#define BP1     0x08    // Mask for Status Register BP1 (Block Protect 1) bit
#define BP2     0x10    // Mask for Status Register BP2 (Block Protect 2) bit
#define BP3     0x20    // Mask for Status Register BP3 (Block Protect 3) bit
#define AAI     0x40    // Mask for Status Register AAI (Auto Address Increment Programming status) bit
#define BPL     0x80    // Mask for Status Register BPL (BPx block protect bit read-only protect) bit

#define CE      GPIO_PIN_8    // Mask for Status Register BPL (BPx block protect bit read-only protect) bit
#define HOLD    GPIO_PIN_9    // Mask for Status Register BPL (BPx block protect bit read-only protect) bit
#define PORT_CE      GPIOD    // Mask for Status Register BPL (BPx block protect bit read-only protect) bit
#define PORT_HOLD    GPIOD    // Mask for Status Register BPL (BPx block protect bit read-only protect) bit

#define SET_CE PORT_CE->BSRR = CE
#define CLR_CE PORT_CE->BSRR = (CE<<16)
#define SET_HOLD PORT_HOLD->BSRR = HOLD
#define CLR_HOLD PORT_HOLD->BSRR = (HOLD << 16)

#define SPI_FLASH_SECTOR_MASK 0xFFF
#define WRITE_uint8_t_STREAM	WRITE_WORD_STREAM

#define SST25_CNT_BYTES 0x400000 //4194304

// SPI Flash device capabilities
typedef union
{
        unsigned char v;
        struct
        {
                unsigned char bWriteWordStream : 1;     // Supports AAI Word opcode (0xAD)
                unsigned char bWriteByteStream : 1;     // Supports AAI Byte opcode (0xAF)
                unsigned char bPageProgram : 1;         // Supports Byte program opcode with up to 256 bytes/page (0x02)
                unsigned char filler : 5;
        } bits;
} DeviceCaps;


void _SendCmd(uint8_t cmd);
void _WaitWhileBusy(void);
void _GetStatus(void);
void SPIFlashEraseSector(int32_t dwAddr);
void InitSPI2(void);
void SPIFlashInit(void);
void SPIFlashReadArray(uint32_t dwAddress, uint8_t *vData, uint16_t wLength);
void SPIFlashBeginWrite(uint32_t dwAddr);
void SPIFlashWrite(uint8_t vData);
void SPIFlashWriteArray(uint8_t* vData, uint16_t wLen);
void SPIFlashEraseSST25(void);
void sst26_pagewrite(uint8_t *buffer, uint16_t page);
void sst26_globalunlock(void);
unsigned char SPI_ReadWriteByte(unsigned char data_write);
uint16_t SPI_ReadWriteWord(uint16_t data_write); 

#endif
