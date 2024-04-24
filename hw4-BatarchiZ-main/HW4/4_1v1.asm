.text :
	lui x6 0x6c6c6
	addi x6, x6, 0x548
	lui x7, 0x41203
	addi x7, x7, -913
	lui x28, 0x00535
	addi x28, x28, -189
	lui x8, 0x10010
	addi x8, x8, 0
	sw x6, 0(x8)
	sw x7 4(x8)
	sw x28, 8(x8)
	addi x17, x0, 0x004
	add x10, x0, x8
	ecall 