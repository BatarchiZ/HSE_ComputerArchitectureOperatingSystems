# (x + 5) / y + 10 / (y - 1)
.text :
# loadInput() : x
	li a7, 5
	ecall
	mv t0, a0
# loadInput() : y
	li a7, 5
	ecall
	mv t1, a0
# x = x + 5
	addi t0, t0, 5
# x = x/y
	div t0, t0, t1
# y = y - 1
	addi t1, t1, -1
# y = 10/y
	addi t3 , zero, 10
	div t1, t3, t1
# a0 = x + y
	add a0, t0, t1
	li a7, 1
	ecall

	