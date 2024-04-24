# (x / y) * y + x % y
.text : 
#TakeInput() : x
	li a7, 5
	ecall
	mv t0, a0
#TakeInput() : y
	li a7, 5
	ecall
	mv t1, a0
# z = x / y
	div t3, t0, t1
# z = z * y
	mul t3, t3, t1
# a = x % y
	rem t4, t0, t1
# a0 = z + a
	add a0, t3, t4
	li a7, 1
	ecall
	