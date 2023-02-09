
## add_custom_command

两个用途：

1. OUTPUT - 生成其他目标的依赖对象；
2. TARGET - 其他 TARGET 在  PRE_BUILD | PRE_LINK | POST_BUILD 过程中的自定义操作；

## add_custom_target

类比于 Makefile 中的 .PHONY 目标
