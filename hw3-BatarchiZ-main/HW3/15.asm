# (x == (y + 3)) ? 0 : 1
.text :
# TakeInput () : x
	li a7, 5
	ecall
	mv t0, a0
# TakeInput() : y
	li a7, 5
	ecall
	mv t1, a0
# y = y + 3
	addi t1, t1, 3
# x == y 
	beq t0, t1, go_zero
	addi a0, zero, 1
	li a7, 1
	ecall
	j end
	
go_zero : 
	addi a0, zero, 0
	li a7, 1
	ecall
end :

	