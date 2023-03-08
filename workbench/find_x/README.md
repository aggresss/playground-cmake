# cmake find_x

- find_package
- find_library
- find_program
- find_path
- find_file

## find_package

- https://cmake.org/cmake/help/latest/command/find_package.html
- https://cmake.org/cmake/help/latest/manual/cmake-developer.7.html#find-modules

find_package 用于查找包（通常是使用三方库），并通过后缀命名变量的方式返回关于包的细节（使用包所依赖的头文件、库文件、编译选项、链接选项等）

Standard Variable Names：

- Xxx_INCLUDE_DIRS
- Xxx_LIBRARIES
- Xxx_DEFINITIONS
- Xxx_EXECUTABLE
- Xxx_LIBRARY_DIRS
- Xxx_ROOT_DIR
- Xxx_VERSION_VV
- Xxx_WRAP_YY
- Xxx_FOUND
- Xxx_NOT_FOUND_MESSAGE
- Xxx_RUNTIME_LIBRARY_DIRS
- Xxx_VERSION
- Xxx_VERSION_MAJOR
- Xxx_VERSION_MINOR
- Xxx_VERSION_PATCH
- Xxx_LIBRARY
- Xxx_INCLUDE_DIR

与 find_libaray 直接在指定搜索目录下搜索库不同，find_package 命令可以获取更多的信息，那么它的搜索方式也是与 find_libaray 不一样，它有两种不同的搜索方式:

- 模块模式 (Module mode)
- 配置模式 (Config mode)

### 模块模式

在该模式下，Cmake会搜索一个名为 `Find<PackageName>.cmake` 的文件，其中 \<PackageName\> 为待搜索包的名称。
搜索路径的顺序依次是：

- 从变量 CMAKE_MODULE_PATH 指定的路径中进行查找
- 从 Cmake 安装路径中查找。Cmake 会在其安装路径下提供很多 .cmake 文件，例如 /XXX/cmake/Modules/ 目录下（不同的系统安装目录可能不一致）

如果找到文件 `Find<PackageName>.cmake`，Cmake 会读取并处理该文件，简而言之，它负责检查一些条件（如版本号是否满足等）是否满足，并在找到包后，返回给调用者一些变量，用以获取包的详细信息。
一般来说，`Find<PackageName>.cmake` 文件不是随包本身一起提供的，更多的是外部针对已有包的重新包装，例如操作系统、Cmake 程序、甚至是调用 find_package 命令的工程针对已有的包提供针对该包的 .cmake 文件。

### 配置模式

该模式下，CMake会搜索 `<lowercasePackageName>-config.cmake` 文件或 `<PackageName>Config.cmake` 文件。如果 find_package 命令中指定了具体的版本，也会搜索`<lowercasePackageName>-config-version.cmake` 或 `<PackageName>ConfigVersion.cmake` 文件，因此配置模式下通常会提供配置文件和版本文件（注意形式上要保持一致），并且作为包的一部分一起提供给使用者。

## find_library


## find_program


## find_path


## find_file


