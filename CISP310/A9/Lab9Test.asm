; Multiple Doubleword shift
; Israel Vasquez

INCLUDE Irvine32.inc

.data
ArraySize = 3
array DWORD ArraySize DUP(99999999h)   ; 1001 pattern

.code
main PROC
	call DisplayArray

	mov esi,0
	shr array[esi+8],1		; high dword
	rcr array[esi+4],1		; middle dword
	rcr array[esi],1		; low dword

	call DisplayArray
	exit
main ENDP

DisplayArray PROC			; display dword from highest to lowest
	pushad
	mov ecx,ArraySize
	mov esi,ArraySize-1
L1:
	mov eax,array[esi]
	mov ebx,4				; size = dword
	call WriteBinB
	mov al,' '
	call WriteChar
	sub esi,1
	Loop L1

	call Crlf
	popad
	ret
DisplayArray ENDP

END main