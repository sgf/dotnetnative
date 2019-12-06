.CODE

;函数原型//asm("movq %%rsp, %0" : "=r"(stack_ptr));
;gc_stacktop_asm PROC
; //void* stack_ptr
; movq %%rsp, %0
; ret //stack_ptr
;gc_stacktop_asm ENDP
;END





;声明
;	int64_t Div128x64(int64_t  loDividend,
;		int64_t  hiDividend,
;		int64_t  divisor,
;		int64_t* pRemainder);

;实现
; Windows 64-bit calling convention passes parameters as follows:
; RCX == first  64-bit integer parameter (low bits of dividend)
; RDX == second 64-bit integer parameter (high bits of dividend)
; R8  == third  64-bit integer parameter (divisor)
; R9  == fourth 64-bit integer parameter (pointer to remainder)
;Div128x64 PROC
;    mov  rax, rcx
;    idiv r8          ; 128-bit divide (RDX:RAX / R8)
;    mov  [r9], rdx   ; store remainder
;    ret              ; return, with quotient in RDX:RAX
;Div128x64 ENDP
