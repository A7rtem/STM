TIMER_DEF = 0

@ initialize timer 2 for using
timer2_init:
	push {r0, r1}
	
	@ TIM2 timer clock enable
	@ load value from RCC_APB1ENR register
	@ RCC registers initialization should be before any other registers initialization
	ldr r1, =RCC_APB1ENR
	ldr r0, [r1]
	
	@ set bit 0 (TIM2 timer clock enable)
	orr r0, r0, 0x01
	
	@ store r0 to RCC_APB1ENR
	str r0, [r1]
	
	@ load value from TIM2_CR1 register
	ldr r1, =TIM2_CR1
	ldr r0, =0x00
	str r0, [r1]
	
	@ set timer2 prescaler register
	ldr r1, =TIM2_PSC
	ldr r0, =0x1F40
	str r0, [r1]
	
	@ set auto-reload value
	ldr r1, =TIM2_ARR
	ldr r0, =0x3E8		@ 1000
	str r0, [r1]
	
	@ re-initialize the counter and generate an update of the registers (I suppose that shadowed ARR and PSC)
	ldr r1, =TIM2_EGR
	ldr r0, =0x01
	str r0, [r1]
	
	push {lr}
	bl timer2_clear_pending
	pop {lr}
	
	@ set timer2 interrupt priority (each priority register contains priority for 4 interrrupts (each priority 8bit long))
	ldr r1, =NVIC_IPR7
	ldr r0, =0x23000000								@ priority 35 as defined in manuals
	
	str r0, [r1]
	
	push {lr}
	bl timer2_interrupt_set_enable
	pop {lr}
	
	pop {r0, r1}	
	bx lr
	
@ set 28th bit in NVIC_ISER0 register, this should enable TIM2 interrupt
@ function does not take, nor recieve parameters
timer2_interrupt_set_enable:
	push {r0, r1}
		
	ldr r1, =NVIC_ISER0
	ldr r0, [r1]
	
	orr r0, r0, 0x10000000
	
	str r0, [r1]
		
	pop {r0, r1}
	bx lr
	
@ set 28th bit in NVIC_ICER0 register, this should disable TIM2 interrupt
timer2_interrupt_clear_enable:
	push {r0, r1}
	
	ldr r1, =NVIC_ICER0
	ldr r0, [r1]
	
	orr r0, r0, 0x10000000
	
	str r0, [r1]
	
	pop {r0, r1}
	bx lr
	
@ clear pending state for TIM2 interrupt
@ function does not take, nor recieve parameters
timer2_clear_pending:
	push {r0, r1}
	
	ldr r1, =NVIC_ICPR0
	ldr r0, =0x10000000
	 
	str r0, [r1]
	
	pop {r0, r1}
	bx lr
	
@ sets Update interrupt enable bit in TIM2_DIER register
@ function does not take, nor recieve parameters
timer2_enable:
	push {r0, r1}
	
	ldr r1, =TIM2_DIER
	ldr r0, [r1]
	orr r0, r0, 0x01
	str r0, [r1]
	
	@ set interrupt enable bit
	ldr r1, =TIM2_CR1
	ldr r0, [r1]
	orr r0, r0, 0x01
	str r0, [r1]
	
	pop {r0, r1}
	bx lr
	
@ clears Update interrupt enable bit in TIM2_DIER register
@ function does not take, nor recieve parameters	
timer2_disable:
	push {r0, r1}
	
	ldr r1, =TIM2_DIER @ TODO: check does it clear TIM2_CR1 bit 0 (interrupt enable bit)
	ldr r0, [r1]
	and r0, r0, 0xFE
	str r0, [r1]
	
	pop {r0, r1}
	bx lr
	
