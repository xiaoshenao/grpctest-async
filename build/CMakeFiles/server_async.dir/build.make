# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/cmake-3.21.3/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.21.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login/build

# Include any dependencies generated for this target.
include CMakeFiles/server_async.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/server_async.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/server_async.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server_async.dir/flags.make

CMakeFiles/server_async.dir/server_async.cc.o: CMakeFiles/server_async.dir/flags.make
CMakeFiles/server_async.dir/server_async.cc.o: ../server_async.cc
CMakeFiles/server_async.dir/server_async.cc.o: CMakeFiles/server_async.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server_async.dir/server_async.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_async.dir/server_async.cc.o -MF CMakeFiles/server_async.dir/server_async.cc.o.d -o CMakeFiles/server_async.dir/server_async.cc.o -c /home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login/server_async.cc

CMakeFiles/server_async.dir/server_async.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_async.dir/server_async.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login/server_async.cc > CMakeFiles/server_async.dir/server_async.cc.i

CMakeFiles/server_async.dir/server_async.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_async.dir/server_async.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login/server_async.cc -o CMakeFiles/server_async.dir/server_async.cc.s

# Object files for target server_async
server_async_OBJECTS = \
"CMakeFiles/server_async.dir/server_async.cc.o"

# External object files for target server_async
server_async_EXTERNAL_OBJECTS =

server_async: CMakeFiles/server_async.dir/server_async.cc.o
server_async: CMakeFiles/server_async.dir/build.make
server_async: libim_grpc_proto.a
server_async: /usr/local/lib/libgrpc++_reflection.a
server_async: /usr/local/lib/libgrpc++.a
server_async: /usr/local/lib/libprotobuf.a
server_async: /usr/local/lib/libgrpc.a
server_async: /usr/local/lib/libz.a
server_async: /usr/local/lib/libcares.a
server_async: /usr/local/lib/libaddress_sorting.a
server_async: /usr/local/lib/libre2.a
server_async: /usr/local/lib/libabsl_raw_hash_set.a
server_async: /usr/local/lib/libabsl_hashtablez_sampler.a
server_async: /usr/local/lib/libabsl_hash.a
server_async: /usr/local/lib/libabsl_city.a
server_async: /usr/local/lib/libabsl_low_level_hash.a
server_async: /usr/local/lib/libabsl_statusor.a
server_async: /usr/local/lib/libabsl_bad_variant_access.a
server_async: /usr/local/lib/libgpr.a
server_async: /usr/local/lib/libupb.a
server_async: /usr/local/lib/libabsl_status.a
server_async: /usr/local/lib/libabsl_random_distributions.a
server_async: /usr/local/lib/libabsl_random_seed_sequences.a
server_async: /usr/local/lib/libabsl_random_internal_pool_urbg.a
server_async: /usr/local/lib/libabsl_random_internal_randen.a
server_async: /usr/local/lib/libabsl_random_internal_randen_hwaes.a
server_async: /usr/local/lib/libabsl_random_internal_randen_hwaes_impl.a
server_async: /usr/local/lib/libabsl_random_internal_randen_slow.a
server_async: /usr/local/lib/libabsl_random_internal_platform.a
server_async: /usr/local/lib/libabsl_random_internal_seed_material.a
server_async: /usr/local/lib/libabsl_random_seed_gen_exception.a
server_async: /usr/local/lib/libabsl_cord.a
server_async: /usr/local/lib/libabsl_bad_optional_access.a
server_async: /usr/local/lib/libabsl_cordz_info.a
server_async: /usr/local/lib/libabsl_cord_internal.a
server_async: /usr/local/lib/libabsl_cordz_functions.a
server_async: /usr/local/lib/libabsl_exponential_biased.a
server_async: /usr/local/lib/libabsl_cordz_handle.a
server_async: /usr/local/lib/libabsl_str_format_internal.a
server_async: /usr/local/lib/libabsl_synchronization.a
server_async: /usr/local/lib/libabsl_stacktrace.a
server_async: /usr/local/lib/libabsl_symbolize.a
server_async: /usr/local/lib/libabsl_debugging_internal.a
server_async: /usr/local/lib/libabsl_demangle_internal.a
server_async: /usr/local/lib/libabsl_graphcycles_internal.a
server_async: /usr/local/lib/libabsl_malloc_internal.a
server_async: /usr/local/lib/libabsl_time.a
server_async: /usr/local/lib/libabsl_strings.a
server_async: /usr/local/lib/libabsl_throw_delegate.a
server_async: /usr/local/lib/libabsl_int128.a
server_async: /usr/local/lib/libabsl_strings_internal.a
server_async: /usr/local/lib/libabsl_base.a
server_async: /usr/local/lib/libabsl_spinlock_wait.a
server_async: /usr/local/lib/libabsl_raw_logging_internal.a
server_async: /usr/local/lib/libabsl_log_severity.a
server_async: /usr/local/lib/libabsl_civil_time.a
server_async: /usr/local/lib/libabsl_time_zone.a
server_async: /usr/local/lib/libssl.a
server_async: /usr/local/lib/libcrypto.a
server_async: CMakeFiles/server_async.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable server_async"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server_async.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server_async.dir/build: server_async
.PHONY : CMakeFiles/server_async.dir/build

CMakeFiles/server_async.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server_async.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server_async.dir/clean

CMakeFiles/server_async.dir/depend:
	cd /home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login /home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login /home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login/build /home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login/build /home/king/share/study/zvoice/grpc-v1.45.2/examples/cpp/im_login/build/CMakeFiles/server_async.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server_async.dir/depend

