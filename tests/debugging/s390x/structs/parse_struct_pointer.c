struct dog{
	int name;
	int id;
	int roll;
};

void pass_struct_args(struct dog* d){
	d->id = d->name + 50;
	d->roll = 15;
}

void main(){
	struct dog d;
	d.name = 87;
	d.id = 227;
	d.roll = 12;
	pass_struct_args(&d);
}

**********************************************************************

Breakpoint 1, main () at parse_struct_pointer.c:14
14		d.name = 87;
(gdb) disas
Dump of assembler code for function main:
   0x0000000001000548 <+0>:		stmg	%r11,%r15,88(%r15)
   0x000000000100054e <+6>:		lay		%r15,-176(%r15)
   0x0000000001000554 <+12>:	lgr		%r11,%r15
=> 0x0000000001000558 <+16>:	mvhi	164(%r11),87
   0x000000000100055e <+22>:	mvhi	168(%r11),227
   0x0000000001000564 <+28>:	mvhi	172(%r11),12
   0x000000000100056a <+34>:	aghik	%r1,%r11,164
   0x0000000001000570 <+40>:	lgr		%r2,%r1
   0x0000000001000574 <+44>:	brasl	%r14,0x10004f8 <pass_struct_args>
   0x000000000100057a <+50>:	nopr
   0x000000000100057c <+52>:	lmg		%r11,%r15,264(%r11)
   0x0000000001000582 <+58>:	br		%r14
End of assembler dump.

**********************************************************************

(gdb) si
15		d.id = 227;
**********************************************************************

(gdb) si
16		d.roll = 12;
**********************************************************************

(gdb) disas
Dump of assembler code for function main:
   0x0000000001000548 <+0>:		stmg	%r11,%r15,88(%r15)
   0x000000000100054e <+6>:		lay		%r15,-176(%r15)
   0x0000000001000554 <+12>:	lgr		%r11,%r15
   0x0000000001000558 <+16>:	mvhi	164(%r11),87
   0x000000000100055e <+22>:	mvhi	168(%r11),227
=> 0x0000000001000564 <+28>:	mvhi	172(%r11),12
   0x000000000100056a <+34>:	aghik	%r1,%r11,164
   0x0000000001000570 <+40>:	lgr		%r2,%r1
   0x0000000001000574 <+44>:	brasl	%r14,0x10004f8 <pass_struct_args>
   0x000000000100057a <+50>:	nopr
   0x000000000100057c <+52>:	lmg		%r11,%r15,264(%r11)
   0x0000000001000582 <+58>:	br		%r14
End of assembler dump.
**********************************************************************

(gdb) si
17		pass_struct_args(&d);
(gdb) disas
Dump of assembler code for function main:
   0x0000000001000548 <+0>:		stmg	%r11,%r15,88(%r15)
   0x000000000100054e <+6>:		lay		%r15,-176(%r15)
   0x0000000001000554 <+12>:	lgr		%r11,%r15
   0x0000000001000558 <+16>:	mvhi	164(%r11),87
   0x000000000100055e <+22>:	mvhi	168(%r11),227
   0x0000000001000564 <+28>:	mvhi	172(%r11),12
=> 0x000000000100056a <+34>:	aghik	%r1,%r11,164
   0x0000000001000570 <+40>:	lgr		%r2,%r1
   0x0000000001000574 <+44>:	brasl	%r14,0x10004f8 <pass_struct_args>
   0x000000000100057a <+50>:	nopr
   0x000000000100057c <+52>:	lmg		%r11,%r15,264(%r11)
   0x0000000001000582 <+58>:	br		%r14
End of assembler dump.
**********************************************************************

(gdb) si
0x0000000001000570	17		pass_struct_args(&d);
(gdb) si
0x0000000001000574	17		pass_struct_args(&d);
(gdb) si
**********************************************************************

pass_struct_args (d=0x3fffdfa5f40) at parse_struct_pointer.c:7
7	void pass_struct_args(struct dog* d){
(gdb) disas
Dump of assembler code for function pass_struct_args:
=> 0x00000000010004f8 <+0>:		ldgr	%f2,%r11
   0x00000000010004fc <+4>:		ldgr	%f0,%r15
   0x0000000001000500 <+8>:		lay		%r15,-168(%r15)
   0x0000000001000506 <+14>:	lgr		%r11,%r15
   0x000000000100050a <+18>:	stg		%r2,160(%r11)
   0x0000000001000510 <+24>:	lg		%r1,160(%r11)
   0x0000000001000516 <+30>:	l		%r1,0(%r1)
   0x000000000100051a <+34>:	ahik	%r2,%r1,50
   0x0000000001000520 <+40>:	lg		%r1,160(%r11)
   0x0000000001000526 <+46>:	st		%r2,4(%r1)
   0x000000000100052a <+50>:	lg		%r1,160(%r11)
   0x0000000001000530 <+56>:	mvhi	8(%r1),15
   0x0000000001000536 <+62>:	nopr
   0x0000000001000538 <+64>:	lgdr	%r11,%f2
   0x000000000100053c <+68>:	lgdr	%r15,%f0
   0x0000000001000540 <+72>:	br		%r14
End of assembler dump.
