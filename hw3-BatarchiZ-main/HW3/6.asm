.text :
# Takeinput() : x
	li a7, 5
	ecall
	mv t0, a0
# TakeInput() : y
	li a7, 5
	ecall 
	mv t1, a0
# x * 6 = x
	add t2, t0, zero
	slli t0, t0, 2
	add t0, t0, t2
	add t0, t0, t2
# y * 3 = y
	add t3, t1, zero
	slli t1, t1, 2
	sub t1, t1, t3
	
# std:: cout << x - y
	sub a0, t0, t1
	li a7, 1
	ecall
	
	
	
