#pragma once

//GC API 附带（GC 版本的）标准分配功能：
//
//GC_malloc（尺寸），GC_free（可选）和GC_realloc（ptr，大小）。
//与大多数 GC 实现一样，可以显式强制进行垃圾回收：
//GC_collect（）
//由于 GC 设计的简单性，我们可以高效地 （O（1）） 映射 GC 分配的指向分配大小的指针（以某些近似值）：
//GC_size（ptr）)
//同样，我们可以有效地映射 （O（1）） 到 GC 分配对象的基 （又名外部） 指针的内部指针：
//GC_base（ptr）)
//此操作是基本指针算术：基 = （（（ptr - base） / 大小 ）大小 = GC_size（ptr））和基是分配ptr的存储桶的基本地址。
