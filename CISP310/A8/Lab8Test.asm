; Encryption program
; Israel Vasquez
; Algorithm: A = (A xor B) xor (B)

INCLUDE Irvine32.inc

KEY = 239		; a value between 1 and 255
BUFMAX = 128	; max buffer size

.data
buffer BYTE		BUFMAX+1	DUP(0)
bufSize DWORD	?
sPrompt BYTE	"Enter the plain text: ",0
sEncrypt BYTE	"Cipher text: ",0
sDecrypt BYTE	"Decrypted text: ",0

.code

main PROC
	call InputString		; input the plain text
	call TranslateBuffer	; encrypt the buffer
	
	mov edx,OFFSET sEncrypt
	call DisplayMessage		; display the encrypted message

	call TranslateBuffer	; decrypt the buffer
	mov edx,OFFSET sDecrypt
	call DisplayMessage		; display the decrypted message

	exit
main ENDP

InputString PROC
	; Prompt the user for a plain text string
	; Save the string in a buffer and the size of the string into a bufSize
	; Receives: nothing
	; Returns: nothing

	pushad					; save all 32-bit register

	mov edx,OFFSET sPrompt	; display the prompt
	call DisplayMessage

	mov ecx,BUFMAX			; maximum character count
	mov edx,OFFSET buffer	; pointer to the buffer
	call ReadString

	mov bufSize,eax		; save length of the string read
	call Crlf

	popad
	ret

InputString ENDP

DisplayMessage PROC
	; Display the message from the caller, and display the buffer
	; Receives: EDX points to the message
	; Return: nothing

	pushad

	call WriteString		; display the message from the caller
	
	mov edx,OFFSET buffer
	call WriteString		; display the buffer
	call Crlf

	popad
	ret

DisplayMessage ENDP

TranslateBuffer PROC
	; Translate the string by XORing each byte
	; with the encryption key
	; Receives: nothing
	; Return: nothing

	pushad

	mov ecx,bufSize			; loop counter
	mov esi,0
L1:
	xor buffer[esi],KEY		; translate a byte
	inc esi
	loop L1
	
	popad
	ret

TranslateBuffer ENDP


END main