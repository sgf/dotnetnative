.CODE


gc_stacktop_asm PROC
 //void* stack_ptr
 movq %%rsp, %0
 ret //stack_ptr
gc_stacktop_asm ENDP

//asm("movq %%rsp, %0" : "=r"(stack_ptr));

END
