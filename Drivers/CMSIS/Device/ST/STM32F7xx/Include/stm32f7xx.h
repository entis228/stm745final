





#ifndef __STM32F7xx_H
#define __STM32F7xx_H

#ifdef __cplusplus
 extern "C" {
#endif 




#if !defined  (STM32F7)
#define STM32F7
#endif 


#if !defined (STM32F756xx) && !defined (STM32F746xx) && !defined (STM32F745xx) && !defined (STM32F765xx) && \
    !defined (STM32F767xx) && !defined (STM32F769xx) && !defined (STM32F777xx) && !defined (STM32F779xx) && \
    !defined (STM32F722xx) && !defined (STM32F723xx) && !defined (STM32F732xx) && !defined (STM32F733xx) && \
    !defined (STM32F730xx) && !defined (STM32F750xx)

     
     
     
     
     
     
     
     
     
     
     
     
     
     
#endif



#if !defined  (USE_HAL_DRIVER)

  
#endif 


#define __STM32F7_CMSIS_VERSION_MAIN   (0x01) 
#define __STM32F7_CMSIS_VERSION_SUB1   (0x02) 
#define __STM32F7_CMSIS_VERSION_SUB2   (0x06) 
#define __STM32F7_CMSIS_VERSION_RC     (0x00) 
#define __STM32F7_CMSIS_VERSION        ((__STM32F7_CMSIS_VERSION_MAIN << 24)\
                                       |(__STM32F7_CMSIS_VERSION_SUB1 << 16)\
                                       |(__STM32F7_CMSIS_VERSION_SUB2 << 8 )\
                                       |(__STM32F7_CMSIS_VERSION_RC))



#if defined(STM32F722xx)
  #include "stm32f722xx.h"
#elif defined(STM32F723xx)
  #include "stm32f723xx.h"
#elif defined(STM32F732xx)
  #include "stm32f732xx.h"
#elif defined(STM32F733xx)
  #include "stm32f733xx.h"
#elif defined(STM32F756xx)
  #include "stm32f756xx.h"
#elif defined(STM32F746xx)
  #include "stm32f746xx.h"
#elif defined(STM32F745xx)
  #include "stm32f745xx.h"
#elif defined(STM32F765xx)
  #include "stm32f765xx.h"
#elif defined(STM32F767xx)
  #include "stm32f767xx.h"
#elif defined(STM32F769xx)
  #include "stm32f769xx.h"
#elif defined(STM32F777xx)
  #include "stm32f777xx.h"
#elif defined(STM32F779xx)
  #include "stm32f779xx.h"
#elif defined(STM32F730xx)
  #include "stm32f730xx.h"
#elif defined(STM32F750xx)
  #include "stm32f750xx.h"
#else
 #error "Please select first the target STM32F7xx device used in your application (in stm32f7xx.h file)"
#endif




typedef enum
{
  RESET = 0U,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0U,
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum
{
  SUCCESS = 0U,
  ERROR = !SUCCESS
} ErrorStatus;




#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))



#ifdef USE_HAL_DRIVER
 #include "stm32f7xx_hal.h"
#endif 

#ifdef __cplusplus
}
#endif 

#endif 






