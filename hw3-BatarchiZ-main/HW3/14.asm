# x > y ? 0 : 1
.text : 
# InputText : x
	li a7, 5
	ecall
	mv t0, a0
# InputText : y
	li a7, 5
	ecall
	mv t1, a0
# x > y 
	bgt t0, t1, go_zero
# std::cout << 1
	addi a0, zero, 1
	li a7, 1
	ecall
	j end
go_zero: 
	addi a0, zero, 0
	li a7, 1
	ecall
end:

	
	