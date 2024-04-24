# 2 * x * x - 3 * y + 4

.text : 
# ReadInput() : x
	li a7, 5
	ecall
	mv t0,a0
# ReadInput() : y
	li a7, 5
	ecall
	mv t1,a0
# x = 2*x*x
	addi t2, zero, 2
	mul  t0, t0, t0
	mul  t0, t2, t0
# y = 3 * y 
	addi t2, zero , 3
	mul t1, t2, t1
# a0 = x - y + 4
	sub t1, t0, t1
	addi a0, t1, 4
	li a7, 1
	ecall
