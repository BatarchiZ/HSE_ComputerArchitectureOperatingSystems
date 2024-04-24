
.text :
	addi x17, x0, 0x005 #add a7, zero, 5
	ecall #Read Int
	add x6, x0, x10  #Put input to t1
	srli x5, x10, 31 
	ecall
	add x29, x0, x10
	srli x28, x10, 31
	beq x6,x0, label1 
	beq x29, x0, label1
	beq x5, x0, label3
	xori x6, x6, -1
	addi x6, x6, 1
label3:
	beq x28, x0, label4
	xori x29, x29, -1
	addi x29, x29, 0x001
label4:
	bge x6, x29, label5
	xor x29, x29, x6
	xor x6, x29, x6
	xor x29, x29, x6
label5:
	add x7, x0, x0
label6:
	add x7, x7, x6
	addi x29, x29, -1
	blt x0, x29, label6
	xor x31, x5, x28
	beq x31, x0, label7
	xori x7, x7, -1
	addi x7, x7, 0x001
label7:
	addi x17, x0, 0x001
	add x10, x0, x7
	ecall
	addi x17, x0, 0x00a
	ecall
label1:
	addi x17, x0, 0x001
	add x10, x0, x0
	ecall
	addi x17, x0, 0x00a
	ecall
