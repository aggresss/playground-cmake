# playground-cmake

Playground for CMake

## Reference

- [CMake Reference Documentation](https://cmake.org/cmake/help/latest/)

## MRU

```
cmake -S . -B build -Wno-dev
cmake -S . -B build -LH
cmake --open ./build
cmake --build ./build
cmake --install ./build --prefix /my/install/prefix
ccmake
ctest
```

## Command

```
CMake Error: cmake version 3.25.2
Usage: C:\Program Files\CMake\bin\cmake.exe -E <command> [arguments...]
Available commands:
  capabilities              - Report capabilities built into cmake in JSON format
  cat [--] <files>...       - concat the files and print them to the standard output
  chdir dir cmd [args...]   - run command in a given directory
  compare_files [--ignore-eol] file1 file2
                              - check if file1 is same as file2
  copy <file>... destination  - copy files to destination (either file or directory)
  copy_directory <dir>... destination   - copy content of <dir>... directories to 'destination' directory
  copy_if_different <file>... destination  - copy files if it has changed
  echo [<string>...]        - displays arguments as text
  echo_append [<string>...] - displays arguments as text but no new line
  env [--unset=NAME ...] [NAME=VALUE ...] [--] <command> [<arg>...]
                            - run command in a modified environment
  environment               - display the current environment
  make_directory <dir>...   - create parent and <dir> directories
  md5sum <file>...          - create MD5 checksum of files
  sha1sum <file>...         - create SHA1 checksum of files
  sha224sum <file>...       - create SHA224 checksum of files
  sha256sum <file>...       - create SHA256 checksum of files
  sha384sum <file>...       - create SHA384 checksum of files
  sha512sum <file>...       - create SHA512 checksum of files
  remove [-f] <file>...     - remove the file(s), use -f to force it (deprecated: use rm instead)
  remove_directory <dir>... - remove directories and their contents (deprecated: use rm instead)
  rename oldname newname    - rename a file or directory (on one volume)
  rm [-rRf] [--] <file/dir>... - remove files or directories, use -f to force it, r or R to remove directories and their contents recursively
  sleep <number>...         - sleep for given number of seconds
  tar [cxt][vf][zjJ] file.tar [file/dir1 file/dir2 ...]
                            - create or extract a tar or zip archive
  time command [args...]    - run command and display elapsed time
  touch <file>...           - touch a <file>.
  touch_nocreate <file>...  - touch a <file> but do not create it.
  create_symlink old new    - create a symbolic link new -> old
  create_hardlink old new   - create a hard link new -> old
  true                      - do nothing with an exit code of 0
  false                     - do nothing with an exit code of 1
Available on Windows only:
  delete_regv key           - delete registry value
  env_vs8_wince sdkname     - displays a batch file which sets the environment for the provided Windows CE SDK installed in VS2005
  env_vs9_wince sdkname     - displays a batch file which sets the environment for the provided Windows CE SDK installed in VS2008
  write_regv key value      - write registry value
```

## Usage

```
cmake --help
Usage

  cmake [options] <path-to-source>
  cmake [options] <path-to-existing-build>
  cmake [options] -S <path-to-source> -B <path-to-build>

Specify a source directory to (re-)generate a build system for it in the
current working directory.  Specify an existing build directory to
re-generate its build system.

Options
  -S <path-to-source>          = Explicitly specify a source directory.
  -B <path-to-build>           = Explicitly specify a build directory.
  -C <initial-cache>           = Pre-load a script to populate the cache.
  -D <var>[:<type>]=<value>    = Create or update a cmake cache entry.
  -U <globbing_expr>           = Remove matching entries from CMake cache.
  -G <generator-name>          = Specify a build system generator.
  -T <toolset-name>            = Specify toolset name if supported by
                                 generator.
  -A <platform-name>           = Specify platform name if supported by
                                 generator.
  --toolchain <file>           = Specify toolchain file
                                 [CMAKE_TOOLCHAIN_FILE].
  --install-prefix <directory> = Specify install directory
                                 [CMAKE_INSTALL_PREFIX].
  -Wdev                        = Enable developer warnings.
  -Wno-dev                     = Suppress developer warnings.
  -Werror=dev                  = Make developer warnings errors.
  -Wno-error=dev               = Make developer warnings not errors.
  -Wdeprecated                 = Enable deprecation warnings.
  -Wno-deprecated              = Suppress deprecation warnings.
  -Werror=deprecated           = Make deprecated macro and function warnings
                                 errors.
  -Wno-error=deprecated        = Make deprecated macro and function warnings
                                 not errors.
  --preset <preset>,--preset=<preset>
                               = Specify a configure preset.
  --list-presets[=<type>]      = List available presets.
  -E                           = CMake command mode.
  -L[A][H]                     = List non-advanced cached variables.
  --fresh                      = Configure a fresh build tree, removing any
                                 existing cache file.
  --build <dir>                = Build a CMake-generated project binary tree.
  --install <dir>              = Install a CMake-generated project binary
                                 tree.
  --open <dir>                 = Open generated project in the associated
                                 application.
  -N                           = View mode only.
  -P <file>                    = Process script mode.
  --find-package               = Legacy pkg-config like mode.  Do not use.
  --graphviz=<file>            = Generate graphviz of dependencies, see
                                 CMakeGraphVizOptions.cmake for more.
  --system-information [file]  = Dump information about this system.
  --log-level=<ERROR|WARNING|NOTICE|STATUS|VERBOSE|DEBUG|TRACE>
                               = Set the verbosity of messages from CMake
                                 files.  --loglevel is also accepted for
                                 backward compatibility reasons.
  --log-context                = Prepend log messages with context, if given
  --debug-trycompile           = Do not delete the try_compile build tree.
                                 Only useful on one try_compile at a time.
  --debug-output               = Put cmake in a debug mode.
  --debug-find                 = Put cmake find in a debug mode.
  --debug-find-pkg=<pkg-name>[,...]
                               = Limit cmake debug-find to the
                                 comma-separated list of packages
  --debug-find-var=<var-name>[,...]
                               = Limit cmake debug-find to the
                                 comma-separated list of result variables
  --trace                      = Put cmake in trace mode.
  --trace-expand               = Put cmake in trace mode with variable
                                 expansion.
  --trace-format=<human|json-v1>
                               = Set the output format of the trace.
  --trace-source=<file>        = Trace only this CMake file/module.  Multiple
                                 options allowed.
  --trace-redirect=<file>      = Redirect trace output to a file instead of
                                 stderr.
  --warn-uninitialized         = Warn about uninitialized values.
  --no-warn-unused-cli         = Don't warn about command line options.
  --check-system-vars          = Find problems with variable usage in system
                                 files.
  --compile-no-warning-as-error= Ignore COMPILE_WARNING_AS_ERROR property and
                                 CMAKE_COMPILE_WARNING_AS_ERROR variable.
  --profiling-format=<fmt>     = Output data for profiling CMake scripts.
                                 Supported formats: google-trace
  --profiling-output=<file>    = Select an output path for the profiling data
                                 enabled through --profiling-format.
  -h,-H,--help,-help,-usage,/? = Print usage information and exit.
  --version,-version,/V [<file>]
                               = Print version number and exit.
  --help-full [<file>]         = Print all help manuals and exit.
  --help-manual <man> [<file>] = Print one help manual and exit.
  --help-manual-list [<file>]  = List help manuals available and exit.
  --help-command <cmd> [<file>]= Print help for one command and exit.
  --help-command-list [<file>] = List commands with help available and exit.
  --help-commands [<file>]     = Print cmake-commands manual and exit.
  --help-module <mod> [<file>] = Print help for one module and exit.
  --help-module-list [<file>]  = List modules with help available and exit.
  --help-modules [<file>]      = Print cmake-modules manual and exit.
  --help-policy <cmp> [<file>] = Print help for one policy and exit.
  --help-policy-list [<file>]  = List policies with help available and exit.
  --help-policies [<file>]     = Print cmake-policies manual and exit.
  --help-property <prop> [<file>]
                               = Print help for one property and exit.
  --help-property-list [<file>]= List properties with help available and
                                 exit.
  --help-properties [<file>]   = Print cmake-properties manual and exit.
  --help-variable var [<file>] = Print help for one variable and exit.
  --help-variable-list [<file>]= List variables with help available and exit.
  --help-variables [<file>]    = Print cmake-variables manual and exit.
```

## Basic Concept

[cmake-language(7)](https://cmake.org/cmake/help/latest/manual/cmake-language.7.html)

- Generator // 生成 build system 的工程文件，例如 `Visual Studio 17 2022`
- Target  // 通过这些命令创建 `add_executable()` `add_library()` `add_custom_target()`
- Command // 包括 `internal command` `macro` `function`
- Variable // 包括 `normal variable` `cache variable` `environment variable`

---

## Version

https://cmake.org/files/

- v3.0.0   // Jun, 2014
- v3.10.0  // Nov, 2017
- v3.20.0  // Feb, 2021
