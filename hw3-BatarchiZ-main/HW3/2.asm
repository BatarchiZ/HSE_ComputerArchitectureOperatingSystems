# (x >> 2) + ((y - 1) << 3)

.text :
	# TakeInput() : x
	li a7, 5
	ecall
	mv t0, a0
	# TakeInput() : y
	li a7, 5
	ecall
	mv t1, a0
	# y - 1 = y
	addi t1, t1, -1
	# y = y << 3
	slli t1, t1, 3
	# x = x >> 2
	srli t0, t0, 2
	# x + y = a0
	add a0, t0, t1
	li a7, 1
	ecall
	
	
