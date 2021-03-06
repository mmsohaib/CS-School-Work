;; Paul Geromini Assignment 3
loop:	lodd counter:		; Load the counter of numbers to do
	jzer done:		; If its zero no more nums to do, goto done
	subd cons1:		; Take one away from count
	stod counter:		; Pass remianing numbers to do
one:	lodd daddr: 		; Load pointer to array of numbers to do
	pshi			; Push arg pointer onto stack
	addd cons1:		; Increment
	stod daddr:		; Store pointer for next fib number to do
	call fib:		; Call fib with arg on stack
	insp 1			; Clear stack on fib
two:	push			; Put return on stack
	lodd raddr:		; load pointer to result array
	popi			; Pop result off stack into result array
	addd cons1:		; Increment
	stod raddr:		; store pointer for next number to do
	jump loop:		; Start loop again
fib:	lodl 1			; Load arg from stack
	jzer fibz: 		; if 0 go to fibz
	subd cons1:		; decrement argument
	jzer fibo:		; if 0 go to fibo
	push			; else push arg - 1 for recursive call
	call fib:		; Recursive call
	push			; push result onto stack
	lodl 1 			; load arg - 1 from stack
	subd cons1: 		; accumulator now arg - 2
	push 			; push arg - 2 onto stack
	call fib: 		; call fib function recursively
clear:	insp 1			; Clear arg - 2 from stack
	addl 1 			; put result in accumulator
	insp 2
	retn			; Return
fibz: 	lodd cons0: 		; accumulator = 0
	retn 			; Return
fibo:	lodd cons1:		; accumulaotr = 1
	retn			; Return
done:	halt			; Halt program execution

	;; Data Structures
.LOC 100			; Locate data begining at 100
da:	3
	9
	18
	23
	25
ra:	0
	0
	0
	0
	0
daddr:	 da:
raddr:	 ra:
cons0:	 0 
cons1:	 1
counter: 5
