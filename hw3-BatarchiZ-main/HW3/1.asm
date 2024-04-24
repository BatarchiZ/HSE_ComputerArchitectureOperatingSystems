.text:
	# : ReadInput1()
	li a7, 5
	ecall
	mv t0, a0
	# : ReadInput2() 
	li a7, 5
	ecall
	mv t1, a0
	# : (x+5) - (y-7)
	addi t0, t0, 5
	addi t1, t1, -7
	sub a0, t0, t1
	# : Print()
	li a7, 1
	ecall
	
	
	
