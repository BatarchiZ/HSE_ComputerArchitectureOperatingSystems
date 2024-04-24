.text 
main :
	li a7, 5
	ecall
	mv t0, a0
	ecall
	mv t1, a0
	mul a0, t1, t0
	li a7, 1
	ecall