#pragma once


 gc_stacktop_asm(){
 movq %%rsp, %0
 =r stack_ptr
 "movq %%rsp, %0" : "=r"(stack_ptr)
}

//asm("movq %%rsp, %0" : "=r"(stack_ptr));