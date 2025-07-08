; Lab 6: Using PUSH and POP to reverse a string
; Israel Vasquez

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data

source BYTE "ABCDEFGHIJ",0

.code
main proc
	mov ecx, LENGTHOF source - 1
	mov esi, OFFSET source
	mov eax,0
L1: mov al,BYTE PTR[esi]
	push eax
	inc esi
	loop L1
	
	mov ecx, LENGTHOF source - 1
	mov esi, OFFSET source
L2: pop eax
	mov [esi],al
	inc esi
	loop L2

	invoke ExitProcess,0
main endp
end main