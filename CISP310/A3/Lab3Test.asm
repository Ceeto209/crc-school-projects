; Lab3Test -- Modified version of Adding two integers
; Israel Vasquez

.386
.model flat,stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

.data
sum dword ?

.code
main proc
	mov eax,11
	add eax,15
	mov sum,eax

	invoke ExitProcess,0

main endp
end main

