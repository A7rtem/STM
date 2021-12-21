STM32F103C8T6_REGISTERS = 0 

.ifndef STM32F103C8T6_PORT_CODES
.include "memory_mapping.inc"
.endif


@ system registers
.equ SCR, 0xE000ED10				@ system control register

@ timer2 registers
.equ TIM2_CR1, TIM2 + 0x00			@ timer2 control register 1
.equ TIM2_CR2, TIM2 + 0x04			@ timer2 control register 2
.equ TIM2_SMCR, TIM2 + 0x08			@ timer2 slave mode control register
.equ TIM2_DIER, TIM2 + 0x0C			@ timer2 DMA (direct memory access)/Interrupt enable register
.equ TIM2_SR, TIM2 + 0x10			@ timer2 status register
.equ TIM2_EGR, TIM2 + 0x14			@ timer2 event generation register
.equ TIM2_CCMR1, TIM2 + 0x18		@ timer2 capture/compare mode register 1
.equ TIM2_CCMR2, TIM2 + 0x1C		@ timer2 capture/compare mode register 2
.equ TIM2_CCER, TIM2 + 0x20			@ timer2 capture/compare enable register
.equ TIM2_CNT, TIM2 + 0x24			@ timer2 counter register
.equ TIM2_PSC, TIM2 + 0x28			@ timer2 prescaler register
.equ TIM2_ARR, TIM2 + 0x2C			@ timer2 auto-reload register	
.equ TIM2_CCR1, TIM2 + 0x34			@ timer2 capture/compare register 1
.equ TIM2_CCR2, TIM2 + 0x38			@ timer2 capture/compare register 2
.equ TIM2_CCR3, TIM2 + 0x3C			@ timer2 capture/compare register 3
.equ TIM2_CCR4, TIM2 + 0x40			@ timer2 capture/compare register 4
.equ TIM2_DCR, TIM2 + 0x48			@ timer2 DMA (direct memory access) control register
.equ TIM2_DMAR, TIM2 + 0x4C			@ timer2 DMA (direct memory access) address for full transfer

@ reset and clock cotrol registers
.equ RCC_CR, RCC + 0x00				@ clock control register
.equ RCC_CFGR, RCC + 0x04			@ clock configuration register
.equ RCC_CIR, RCC + 0x08			@ clock interrupt register
.equ RCC_APB2RSTR, RCC + 0x0C		@ APB2 peripherial reset register (APB - advanced peripherial bus)
.equ RCC_APB1RSTR, RCC + 0x10		@ APB1 peripherial reset register
.equ RCC_AHBENR, RCC + 0x14			@ AHB peripherial clock enable register (AHB - advanced high performance bus)
.equ RCC_APB2ENR, RCC + 0x18		@ APB2 peripherial clock enable register
.equ RCC_APB1ENR, RCC + 0x1C		@ APB1 peripherial clock enable register
.equ RCC_BDCR, RCC + 0x20			@ backup domain control register	
.equ RCC_CSR, RCC + 0x24			@ control/status register

@cortexm3
.equ NVIC_IPR7, 0xE000E41C
.equ NVIC_ISER0, 0xE000E100	
.equ NVIC_ICER0, 0xE000E180
.equ NVIC_ICPR0, 0xE000E280

@ GPIO port C registers
.equ GPIOC_CRL, PORT_C				@ port C control register low
.equ GPIOC_CRH, PORT_C + 0x04		@ port C control register high
.equ GPIOC_IDR, PORT_C + 0x08		@ port C input data register
.equ GPIOC_ODR, PORT_C + 0x0C		@ port C output data register
.equ GPIOC_BSRR, PORT_C + 0x10		@ port C bit set/reset register
.equ GPIOC_BRR, PORT_C + 0x14		@ port C bit reset register (16 bit)
.equ GPIOC_LCKR, PORT_C + 0x18		@ port C configuration lock register
