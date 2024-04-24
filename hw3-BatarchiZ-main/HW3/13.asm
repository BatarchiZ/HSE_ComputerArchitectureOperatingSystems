#reset the y-th bit of x to 0
.text :
# takeInput() : x
	li a7, 5
	ecall
	mv t0, a0
# takeinput() ; y
	li a7,5 
	ecall 
	mv t1, a0
# 1 << y - 1 == 0000...0001000.000
	addi t1, t1, -1
	addi t5, zero, 1
	sll t5, t5, t1
# negate  == 1111...11101111...1111 = z
	#neg t5, t5
	not t5, t5
# x & z to turn of the y-th bit
	and a0, t5, t0
# std:: cout << 
	li a7, 1
	ecall
	
	
	
	

	