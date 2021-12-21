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

	ldr r1, =TIM2_DIER
	ldr r0, [r1]
	orr r0, r0, 0x01
	str r0, [r1]
	
	
		
		
		
		
	
		@ set timer2 prescaler register
	ldr r1, =TIM2_PSC
	ldr r0, =0x01  @0xFFFE@0x1F40
	str r0, [r1]
	@ set auto-reload value
	ldr r1, =TIM2_ARR
	ldr r0, =0xF9	@ 
	@регистр настройки содержитт биты определяющие режим работы таймера
	ldr r1, =TIM2_CR2
	ldr r0, = 0x10   @MMS 001 в качестве тригера CEN бит.
	str r0, [r1]
	

		
	ldr r1, =NVIC_ISER0
	ldr r0, [r1]
	
	orr r0, r0, 0x10000000
	
	str r0, [r1]
		
	ldr r1, =NVIC_IPR7
	ldr r0, =0x23000000								@ priority 35 as defined in manuals
	
	str r0, [r1]
	
	
	
	
	
	@ load value from TIM2_CR1 register
	@ set interrupt enable bit
	ldr r1, =TIM2_CR1
	ldr r0, [r1]
	orr r0, r0, 0x01
	str r0, [r1]
	
		
	str r0, [r1]
	pop {r0, r1}
	bx lr
	



	
