@ Все Cortex-M процессоры используют thumb инструкции, так что включаем thumb режим
.thumb

@ В связи с тем, что ARM ассемблер может выполнять 2 типа инструкций (arm и thumb), то компилятор поддерживает 2 синтаксиса для работы с ними 
@ (подробнее можно почитать тут:  https://sourceware.org/binutils/docs/as/ARM_002dInstruction_002dSet.html#ARM_002dInstruction_002dSet
.syntax unified

.equ STACKINIT, 0x20005000		@ Определяем адрес конца SRAM

@ Начало секции кода
.text

@ Начало вектора прерываний
.org 0x00000000
SP: .word STACKINIT +1					@ Первая запись в векторе прерываний — это адрес вершины стэка. Процессор в начале работы инициализирует SP регистр этим адресом
RESET: .word main +1					@ Reset вектор
@ Далее идут высоко приоритетные прерывания которые обязательно должны присутствовать в векторе прерываний. Подробнее о них можно почитать сдесь:
@ http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0553a/BABBGBEC.html
NMI_HANDLER: .word nmi_fault	+1	
HARD_FAULT: .word hard_fault	+1	
MEMORY_FAULT: .word memory_fault +1
BUS_FAULT: .word bus_fault +1
@ Так как thumb и arm наборы инструкции имеют разный сдвиг адреса, чтобы обеспечить корректную работу всех thumb инструкций 
@ прибавляем к последнему адресу вектора прерываний 1. Подробнее про thumb и arm наборы инструкций можно почитать сдесь:
@ http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0473j/dom1359731139853.html
USAGE_FAULT: .word usage_fault +1
.org 0x000000B0
 TIMER2_INTERRUPT: .word timer2_interupt + 1	

@ Включаем код из led.inc в main.s, если он не был включен раньше
.ifndef LED_DEF
.include "led.inc"
.endif
.ifndef TIMER_DEF
.include "timer.inc"
.endif

main:
	push {lr}					@ Сохраняем Link Register в стэк
	bl led_init
	bl timer2_init					@ Вызываем функцию led_init
	pop {lr}					@ Восстанавливаем Link Register из стэка
	

_main_loop:	
	push {lr}
	  LDR   R1, =TIM2_CNT
	pop {lr}
	b _main_loop				@ branch to _main_loop and not load return address to link register (LR)
	@ return from function
	bx lr						@ indirect branch to link register address

@ Функция активного ожидания

timer2_interupt:	
	push {lr}
	bl led_flash	
	pop {lr}
	bx lr
	
nmi_fault:
	@ breakpoint
	bkpt
	bx lr
	
hard_fault:
	@ breakpoint
	bkpt
	bx lr

memory_fault:
	@ breakpoint
	bkpt
	bx lr

bus_fault:
	@ breakpoint
	bkpt
	bx lr

usage_fault:
	@ breakpoint
	bkpt
	bx lr
	bx lr	
	
.end
