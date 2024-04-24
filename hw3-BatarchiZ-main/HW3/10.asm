# x & (-1 << 5)
.text : 
#LoadInput() : x
	li a7, 5
	ecall 
	mv t0, a0
# -1 << 5 = y
	addi t2, zero, -1
	slli t2, t2, 5
# x & y = a0
	and a0, t0, t2
	li a7, 1
	ecall