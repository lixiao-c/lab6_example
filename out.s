# your asm code header here

# define your veriables and temp veriables here
	.bss
_a:
	.zero	4
	.align	4
t0:
	.zero	4
	.align	4


# your asm code here
	.text
	.globl _start
_start:
	# your own code of AND operation here
	jl @1
	# your asm code of AND operation end
	movl $_a, %eax
	addl $1, %eax
	movl %eax, $t0
	jmp _start
@1:
	ret
