; Project 1 shifting the Elements in an Array
; Israel Vasquez

.386
.model flat, stdcall
.stack 4096

ExitProcess proto, dwExitCode:dword

.data
    arr DWORD 10, 20, 30, 40       ; 32-bit integer array
    LEN = 4                        ; Number of elements in the array

.code
main PROC
    
    mov ecx, LEN                   
    dec ecx                        
    mov esi, OFFSET arr            
    add esi, (LEN - 1) * 4         
    mov eax, [esi]                 

rotate_loop:
    mov ebx, [esi - 4]             
    mov [esi], ebx                 
    sub esi, 4                     
    loop rotate_loop               

    mov [arr], eax                 

    INVOKE ExitProcess, 0
main ENDP
END main


