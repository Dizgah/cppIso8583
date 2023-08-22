cmake_minimum_required( VERSION 3.5)

project( cppIso8583 LANGUAGES C CXX)

set( CMAKE_CXX_STANDARD 17)
set( CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    lib/dl_c_common_v0_0_2/
    lib/dl_c_iso8583_v0_0_3/
)

set(libIso8583_src
    lib/dl_c_common_v0_0_2/dl_mem.c
    lib/dl_c_common_v0_0_2/dl_output.c
    lib/dl_c_common_v0_0_2/dl_str.c
    lib/dl_c_common_v0_0_2/dl_time.c
    lib/dl_c_common_v0_0_2/dl_timer.c
    lib/dl_c_iso8583_v0_0_3/dl_iso8583.c
    lib/dl_c_iso8583_v0_0_3/dl_iso8583_common.c
    lib/dl_c_iso8583_v0_0_3/dl_iso8583_defs_1987.c
    lib/dl_c_iso8583_v0_0_3/dl_iso8583_defs_1993.c
    lib/dl_c_iso8583_v0_0_3/dl_iso8583_fields.c)

add_library(cppIso8583 ${libIso8583_src} cppiso8583.cpp)
