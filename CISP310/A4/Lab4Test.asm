; Lab4 - Integer expression calculation
; Israel Vasquez

Comment #
A = (A + B) - (C + D). Assign integer values to the EAX, EBX, ECX, and EDX registers.
#

.386
.model flat,stdcall
.stack 4096

ExitProcess proto,dwExitCode:dword

.data
result WORD ?

.code
main PROC
	mov ax, 4000h
	mov bx, 3530h
	mov cx, 2900h
	mov dx, 32FBh

	add ax,bx
	add cx,dx

	sub ax,cx

	mov result,ax

	INVOKE ExitProcess,0
main ENDP
end main