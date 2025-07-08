; Call a procedure AddSum to sum elements of a 32-bit integer array
; Israel Vasquez

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
array DWORD 10h, 20h, 30h, 40h, 50h, 60h   ; sum = 150h
theSum DWORD ?

.code
main proc
	mov esi, 0
	mov ecx, LENGTHOF array
	mov eax, 0

	call AddSum

	mov theSum, eax

	invoke ExitProcess,0
main endp

AddSum proc
	; Inputs:	esi = index of the array or the address of the array
	;			ecx = number of elements in the array
	; Output:	eax = sum of the array

L1: add eax, array[esi]
	add esi, TYPE DWORD
	loop L1

	ret
AddSum endp

end main