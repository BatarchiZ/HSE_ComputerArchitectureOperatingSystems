# ((x << 2) - y + 5) >> 1
.text :
# TakeInput() : x
	li a7,5
	ecall
	mv t0, a0
# TakeInput() : y
	li a7, 5
	ecall
	mv t1, a0
# multiply by minus -1 : -y = y * -1
	addi t3, zero, -1
	mul t1, t1, t3
# y = 5 - y
	addi t1, t1, 5
# x = x << 2
	slli t0, t0, 2
# y = y + x
	add t1, t0, t1
# y >> 1
	srai a0, t1, 1
# std::cout 
	li a7, 1
	ecall
	
