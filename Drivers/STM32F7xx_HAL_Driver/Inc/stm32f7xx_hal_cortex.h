 


#ifndef __STM32F7xx_HAL_CORTEX_H
#define __STM32F7xx_HAL_CORTEX_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f7xx_hal_def.h"



 



#if (__MPU_PRESENT == 1)

typedef struct
{
  uint8_t                Enable;                
  uint8_t                Number;                
  uint32_t               BaseAddress;           
  uint8_t                Size;                  
  uint8_t                SubRegionDisable;               
  uint8_t                TypeExtField;                           
  uint8_t                AccessPermission;      
  uint8_t                DisableExec;           
  uint8_t                IsShareable;           
  uint8_t                IsCacheable;           
  uint8_t                IsBufferable;          
}MPU_Region_InitTypeDef;

#endif 








#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007U) 
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006U) 
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005U) 
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004U) 
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003U) 



#define SYSTICK_CLKSOURCE_HCLK_DIV8    ((uint32_t)0x00000000U)
#define SYSTICK_CLKSOURCE_HCLK         ((uint32_t)0x00000004U)



#if (__MPU_PRESENT == 1)

#define  MPU_HFNMI_PRIVDEF_NONE      ((uint32_t)0x00000000U)  
#define  MPU_HARDFAULT_NMI           ((uint32_t)0x00000002U)
#define  MPU_PRIVILEGED_DEFAULT      ((uint32_t)0x00000004U)
#define  MPU_HFNMI_PRIVDEF           ((uint32_t)0x00000006U)



#define  MPU_REGION_ENABLE     ((uint8_t)0x01U)
#define  MPU_REGION_DISABLE    ((uint8_t)0x00U)



#define  MPU_INSTRUCTION_ACCESS_ENABLE      ((uint8_t)0x00U)
#define  MPU_INSTRUCTION_ACCESS_DISABLE     ((uint8_t)0x01U)



#define  MPU_ACCESS_SHAREABLE        ((uint8_t)0x01U)
#define  MPU_ACCESS_NOT_SHAREABLE    ((uint8_t)0x00U)



#define  MPU_ACCESS_CACHEABLE         ((uint8_t)0x01U)
#define  MPU_ACCESS_NOT_CACHEABLE     ((uint8_t)0x00U)



#define  MPU_ACCESS_BUFFERABLE         ((uint8_t)0x01U)
#define  MPU_ACCESS_NOT_BUFFERABLE     ((uint8_t)0x00U)



#define  MPU_TEX_LEVEL0    ((uint8_t)0x00U)
#define  MPU_TEX_LEVEL1    ((uint8_t)0x01U)
#define  MPU_TEX_LEVEL2    ((uint8_t)0x02U)



#define   MPU_REGION_SIZE_32B      ((uint8_t)0x04U)
#define   MPU_REGION_SIZE_64B      ((uint8_t)0x05U)
#define   MPU_REGION_SIZE_128B     ((uint8_t)0x06U) 
#define   MPU_REGION_SIZE_256B     ((uint8_t)0x07U) 
#define   MPU_REGION_SIZE_512B     ((uint8_t)0x08U) 
#define   MPU_REGION_SIZE_1KB      ((uint8_t)0x09U)  
#define   MPU_REGION_SIZE_2KB      ((uint8_t)0x0AU)
#define   MPU_REGION_SIZE_4KB      ((uint8_t)0x0BU) 
#define   MPU_REGION_SIZE_8KB      ((uint8_t)0x0CU) 
#define   MPU_REGION_SIZE_16KB     ((uint8_t)0x0DU) 
#define   MPU_REGION_SIZE_32KB     ((uint8_t)0x0EU) 
#define   MPU_REGION_SIZE_64KB     ((uint8_t)0x0FU) 
#define   MPU_REGION_SIZE_128KB    ((uint8_t)0x10U)
#define   MPU_REGION_SIZE_256KB    ((uint8_t)0x11U)
#define   MPU_REGION_SIZE_512KB    ((uint8_t)0x12U)
#define   MPU_REGION_SIZE_1MB      ((uint8_t)0x13U) 
#define   MPU_REGION_SIZE_2MB      ((uint8_t)0x14U) 
#define   MPU_REGION_SIZE_4MB      ((uint8_t)0x15U) 
#define   MPU_REGION_SIZE_8MB      ((uint8_t)0x16U) 
#define   MPU_REGION_SIZE_16MB     ((uint8_t)0x17U)
#define   MPU_REGION_SIZE_32MB     ((uint8_t)0x18U)
#define   MPU_REGION_SIZE_64MB     ((uint8_t)0x19U)
#define   MPU_REGION_SIZE_128MB    ((uint8_t)0x1AU)
#define   MPU_REGION_SIZE_256MB    ((uint8_t)0x1BU)
#define   MPU_REGION_SIZE_512MB    ((uint8_t)0x1CU)
#define   MPU_REGION_SIZE_1GB      ((uint8_t)0x1DU) 
#define   MPU_REGION_SIZE_2GB      ((uint8_t)0x1EU) 
#define   MPU_REGION_SIZE_4GB      ((uint8_t)0x1FU)

   

#define  MPU_REGION_NO_ACCESS      ((uint8_t)0x00U)  
#define  MPU_REGION_PRIV_RW        ((uint8_t)0x01U) 
#define  MPU_REGION_PRIV_RW_URO    ((uint8_t)0x02U)  
#define  MPU_REGION_FULL_ACCESS    ((uint8_t)0x03U)  
#define  MPU_REGION_PRIV_RO        ((uint8_t)0x05U) 
#define  MPU_REGION_PRIV_RO_URO    ((uint8_t)0x06U)



#define  MPU_REGION_NUMBER0    ((uint8_t)0x00U)  
#define  MPU_REGION_NUMBER1    ((uint8_t)0x01U) 
#define  MPU_REGION_NUMBER2    ((uint8_t)0x02U)  
#define  MPU_REGION_NUMBER3    ((uint8_t)0x03U)  
#define  MPU_REGION_NUMBER4    ((uint8_t)0x04U) 
#define  MPU_REGION_NUMBER5    ((uint8_t)0x05U)
#define  MPU_REGION_NUMBER6    ((uint8_t)0x06U)
#define  MPU_REGION_NUMBER7    ((uint8_t)0x07U)

#endif 








  


void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup);
void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority);
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn);
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn);
void HAL_NVIC_SystemReset(void);
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb);




#if (__MPU_PRESENT == 1)
void HAL_MPU_Enable(uint32_t MPU_Control);
void HAL_MPU_Disable(void);
void HAL_MPU_ConfigRegion(MPU_Region_InitTypeDef *MPU_Init);
#endif 
uint32_t HAL_NVIC_GetPriorityGrouping(void);
void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority);
uint32_t HAL_NVIC_GetPendingIRQ(IRQn_Type IRQn);
void HAL_NVIC_SetPendingIRQ(IRQn_Type IRQn);
void HAL_NVIC_ClearPendingIRQ(IRQn_Type IRQn);
uint32_t HAL_NVIC_GetActive(IRQn_Type IRQn);
void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource);
void HAL_SYSTICK_IRQHandler(void);
void HAL_SYSTICK_Callback(void);




 




#define IS_NVIC_PRIORITY_GROUP(GROUP) (((GROUP) == NVIC_PRIORITYGROUP_0) || \
                                       ((GROUP) == NVIC_PRIORITYGROUP_1) || \
                                       ((GROUP) == NVIC_PRIORITYGROUP_2) || \
                                       ((GROUP) == NVIC_PRIORITYGROUP_3) || \
                                       ((GROUP) == NVIC_PRIORITYGROUP_4))

#define IS_NVIC_PREEMPTION_PRIORITY(PRIORITY)  ((PRIORITY) < 0x10U)

#define IS_NVIC_SUB_PRIORITY(PRIORITY)         ((PRIORITY) < 0x10U)

#define IS_NVIC_DEVICE_IRQ(IRQ)                ((IRQ) >= 0x00)

#define IS_SYSTICK_CLK_SOURCE(SOURCE) (((SOURCE) == SYSTICK_CLKSOURCE_HCLK) || \
                                       ((SOURCE) == SYSTICK_CLKSOURCE_HCLK_DIV8))

#if (__MPU_PRESENT == 1)
#define IS_MPU_REGION_ENABLE(STATE) (((STATE) == MPU_REGION_ENABLE) || \
                                     ((STATE) == MPU_REGION_DISABLE))

#define IS_MPU_INSTRUCTION_ACCESS(STATE) (((STATE) == MPU_INSTRUCTION_ACCESS_ENABLE) || \
                                          ((STATE) == MPU_INSTRUCTION_ACCESS_DISABLE))

#define IS_MPU_ACCESS_SHAREABLE(STATE)   (((STATE) == MPU_ACCESS_SHAREABLE) || \
                                          ((STATE) == MPU_ACCESS_NOT_SHAREABLE))

#define IS_MPU_ACCESS_CACHEABLE(STATE)   (((STATE) == MPU_ACCESS_CACHEABLE) || \
                                          ((STATE) == MPU_ACCESS_NOT_CACHEABLE))

#define IS_MPU_ACCESS_BUFFERABLE(STATE)   (((STATE) == MPU_ACCESS_BUFFERABLE) || \
                                          ((STATE) == MPU_ACCESS_NOT_BUFFERABLE))

#define IS_MPU_TEX_LEVEL(TYPE) (((TYPE) == MPU_TEX_LEVEL0)  || \
                                ((TYPE) == MPU_TEX_LEVEL1)  || \
                                ((TYPE) == MPU_TEX_LEVEL2))

#define IS_MPU_REGION_PERMISSION_ATTRIBUTE(TYPE) (((TYPE) == MPU_REGION_NO_ACCESS)   || \
                                                  ((TYPE) == MPU_REGION_PRIV_RW)     || \
                                                  ((TYPE) == MPU_REGION_PRIV_RW_URO) || \
                                                  ((TYPE) == MPU_REGION_FULL_ACCESS) || \
                                                  ((TYPE) == MPU_REGION_PRIV_RO)     || \
                                                  ((TYPE) == MPU_REGION_PRIV_RO_URO))

#define IS_MPU_REGION_NUMBER(NUMBER)    (((NUMBER) == MPU_REGION_NUMBER0) || \
                                         ((NUMBER) == MPU_REGION_NUMBER1) || \
                                         ((NUMBER) == MPU_REGION_NUMBER2) || \
                                         ((NUMBER) == MPU_REGION_NUMBER3) || \
                                         ((NUMBER) == MPU_REGION_NUMBER4) || \
                                         ((NUMBER) == MPU_REGION_NUMBER5) || \
                                         ((NUMBER) == MPU_REGION_NUMBER6) || \
                                         ((NUMBER) == MPU_REGION_NUMBER7))

#define IS_MPU_REGION_SIZE(SIZE)    (((SIZE) == MPU_REGION_SIZE_32B)   || \
                                     ((SIZE) == MPU_REGION_SIZE_64B)   || \
                                     ((SIZE) == MPU_REGION_SIZE_128B)  || \
                                     ((SIZE) == MPU_REGION_SIZE_256B)  || \
                                     ((SIZE) == MPU_REGION_SIZE_512B)  || \
                                     ((SIZE) == MPU_REGION_SIZE_1KB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_2KB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_4KB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_8KB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_16KB)  || \
                                     ((SIZE) == MPU_REGION_SIZE_32KB)  || \
                                     ((SIZE) == MPU_REGION_SIZE_64KB)  || \
                                     ((SIZE) == MPU_REGION_SIZE_128KB) || \
                                     ((SIZE) == MPU_REGION_SIZE_256KB) || \
                                     ((SIZE) == MPU_REGION_SIZE_512KB) || \
                                     ((SIZE) == MPU_REGION_SIZE_1MB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_2MB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_4MB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_8MB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_16MB)  || \
                                     ((SIZE) == MPU_REGION_SIZE_32MB)  || \
                                     ((SIZE) == MPU_REGION_SIZE_64MB)  || \
                                     ((SIZE) == MPU_REGION_SIZE_128MB) || \
                                     ((SIZE) == MPU_REGION_SIZE_256MB) || \
                                     ((SIZE) == MPU_REGION_SIZE_512MB) || \
                                     ((SIZE) == MPU_REGION_SIZE_1GB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_2GB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_4GB))

#define IS_MPU_SUB_REGION_DISABLE(SUBREGION)  ((SUBREGION) < (uint16_t)0x00FFU)
#endif 

                                                                            

 


  
#ifdef __cplusplus
}
#endif

#endif 
 


