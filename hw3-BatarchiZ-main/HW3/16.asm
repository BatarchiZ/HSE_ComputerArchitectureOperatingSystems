# x < -5 & y > 10
.text : 
# TakeInput() : x
	li a7, 5
	ecall
	mv t0, a0
# TakeInput() : y
	li a7, 5
	ecall
	mv t1, a0
# x < -5
	addi t5, zero, -5
	blt t0, t5, go_second
	addi a0, zero, 0
	li a7, 1
	ecall
	j done

go_second :
	addi t5, zero, 10
	bgt t1, t5, go_one
	addi a0, zero, 0
	li a7, 1
	ecall
	j done
	
go_one :
	addi a0, zero, 1
	li a7, 1
	ecall
	j done
done: 