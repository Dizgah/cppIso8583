cmake_minimum_required( VERSION 3.5)

project( cppIso8583 LANGUAGES C CXX)

set( CMAKE_CXX_STANDARD 17)
set( CMAKE_CXX_STANDARD_REQUIRED ON)

set( PROJECT_DIR .)
set( INC ${PROJECT_DIR}/inc)
set( SRC ${PROJECT_DIR}/src)
set( LIB ${PROJECT_DIR}/lib)
set( WEBSOCKETPP ${LIB}/websocketpp)
set( RAPIDJSON ${LIB}/rapidjson)
set( DL_C_COMMON ${LIB}/iso8583/dl_c_common_v0_0_2)
set( DL_C_ISO ${LIB}/iso8583/dl_c_iso8583_v0_0_3)

find_package( OpenSSL REQUIRED)
find_package( Threads)

set( Boost_USE_STATIC_LIBS ON)
SET( Boost_USE_MULTITHREAD ON)
find_package( Boost REQUIRED system thread)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

include_directories( ${PROJECT_DIR}/)
include_directories( ${INC}/)
include_directories( ${LIB}/)
include_directories( ${WEBSOCKETPP}/)
include_directories( ${RAPIDJSON}/)
include_directories( ${DL_C_COMMON}/)
include_directories( ${DL_C_ISO}/)
include_directories( ${Boost_INCLUDE_DIR})
include_directories( ${OPENSSL_INCLUDE_DIR})

set(libIso8583_src
    "lib/iso8583/dl_c_common_v0_0_2/dl_mem.c"
    "lib/iso8583/dl_c_common_v0_0_2/dl_output.c"
    "lib/iso8583/dl_c_common_v0_0_2/dl_str.c"
    "lib/iso8583/dl_c_common_v0_0_2/dl_time.c"
    "lib/iso8583/dl_c_common_v0_0_2/dl_timer.c"
    "lib/iso8583/dl_c_iso8583_v0_0_3/dl_iso8583.c"
    "lib/iso8583/dl_c_iso8583_v0_0_3/dl_iso8583_common.c"
    "lib/iso8583/dl_c_iso8583_v0_0_3/dl_iso8583_defs_1987.c"
    "lib/iso8583/dl_c_iso8583_v0_0_3/dl_iso8583_defs_1993.c"
    "lib/iso8583/dl_c_iso8583_v0_0_3/dl_iso8583_fields.c"
)

add_library( cppIso8583 STATIC ${libIso8583_src})
target_include_directories( cppIso8583 PUBLIC ${libIso8583_src})

add_executable( cppIso8583Demo main.cpp)
target_link_libraries ( cppIso8583Demo ${PROJECT_LINK_LIBS} Threads::Threads ${Boost_LIBRARIES} OpenSSL::SSL OpenSSL::Crypto ${CURL_LIBRARIES} cppIso8583)
