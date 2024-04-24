
.text :
	addi a7,zero, 0x005 #li a7, 5
	ecall 
	add t1, zero, a0  #mv t1, a0
	srli t0, a0, 31  #srli t0, a0, 31 # store sign of "b"
	ecall
	add t4, zero, a0 #mv t4, a0
	srli t3, a0, 31  # store sign of "b"
	beq t1, zero, label1 #if input1 == 1
	beq t4, zero, label1 #if input2 == 0
	beq t0, zero, label3 #if input 1 is positive
	xori t1, t1, -1 #flip all bits
	addi t1, t1, 1 #add one
label3:
	beq t3, zero, label4 #if input2 is positive
	xori t4, t4, -1 #flip all bits
	addi t4, t4, 0x001 #add one
label4:
	bge t1, t4, label5 #if t1 >= t4 -> label 5
	xor t4, t4, t1 #next three imstructions change places of input1 and input2
	xor t1, t4, t1	
	xor t4, t4, t1
	
label5:
	add t2, zero, zero # t2 = 0
label6:
	add t2, t2, t1 #t2 = t2 * count(input1)
	addi t4, t4, -1 #input1 - 1
	blt zero, t4, label6 #if 0 < input1 cycle until t4 = 0
	xor t6, t0, t3 #t3 combined sign
	beq t6, zero, label7 #if t6 is positive -> label
	xori t2, t2, -1  #from the result flip all bits
	addi t2, t2, 0x001 #add one
label7: #print t2
	addi a7, zero, 0x001
	add a0, zero, t2
	ecall
	addi a7, zero, 0x00a #exit
	ecall
label1: #print zero
	addi a7, zero, 0x001
	add a0, zero, zero
	ecall
	addi a7, zero, 0x00a
	ecall