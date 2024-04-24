# x | (-1 >> 27)

.text : 
# loadnput() : x
	li a7 , 5
	ecall
	mv t0, a0
# - 1 >> 27 = y
	addi t2, zero, -1
	srli t2, t2, 27
# x | y
	or a0, t0, t2
# output()
	li a7 , 1
	ecall
