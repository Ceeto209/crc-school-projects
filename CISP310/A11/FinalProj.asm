; Final Project: Count Matching Elements
; Israel Vasquez

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:DWORD

.data
    array1 DWORD 1, 2, 3, 4, 5
    array2 DWORD 1, 9, 3, 8, 5
    array3 DWORD 3, 1, 7, 9, 2
    array4 DWORD 3, 4, 5, 7, 2
    
    lengthArray DWORD 5       ; Length of the arrays
    result DWORD ?            

.code

CountMatches PROTO ptrArray1:PTR DWORD, ptrArray2:PTR DWORD, arrayLength:DWORD

main PROC
    ; Call CountMatches for the first pair of arrays
    INVOKE CountMatches, OFFSET array1, OFFSET array2, lengthArray          

    ; Call CountMatches for the second pair of arrays
    INVOKE CountMatches, OFFSET array3, OFFSET array4, lengthArray          
    
    INVOKE ExitProcess, 0
main ENDP


CountMatches PROC ptrArray1:PTR DWORD, ptrArray2:PTR DWORD, arrayLength:DWORD
    PUSHAD                    

    mov eax, 0                
    mov ecx, [ebp + 16]
    mov esi, [ebp +  12]       
    mov edi, [ebp + 8]

compare_loop:
    cmp ecx, 0                
    je done                   ; Exit loop if finished

    mov ebx, [esi]            ; Load current element of array1
    mov edx, [edi]            ; Load current element of array2
    cmp ebx, edx              ; Compare the elements
    jne no_match              ; Skip increment if not equal
    inc eax                   ; Increment counter if equal

no_match:
    add esi, 4                ; Move to the next element in array1
    add edi, 4                ; Move to the next element in array2
    dec ecx                   
    jmp compare_loop          

done:
    mov result, eax 
    POPAD                     
    ret                       
CountMatches ENDP

END main
