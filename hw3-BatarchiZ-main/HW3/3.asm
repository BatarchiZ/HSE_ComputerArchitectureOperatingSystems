# (x << y) - 10
.text :
# TakeInput() : x
	li a7, 5
	ecall
	mv t0, a0
# TakeInput() : y
	li a7, 5
	ecall
	mv t1, a0
# y = x << y
	sll t1, t0, t1
# y - 10 = a0
	addi a0, t1, -10
	li a7, 1
	ecall


