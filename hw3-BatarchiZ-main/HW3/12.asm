# set the y-th bit of x to 1
.text : 
# takeInput() : x
	li a7, 5
	ecall 
	mv t0, a0
# takeInput() : y
	li a7, 5
	ecall 
	mv t1, a0
# 1 << y - 1 = y
	addi t1, t1, -1
	addi t5, zero, 1
	sll t1, t5, t1
# x || y
	or a0, t0, t1
#std::cout
	li a7, 1
	ecall
