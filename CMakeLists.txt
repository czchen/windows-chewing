cmake_minimum_required(VERSION 2.8.8)
project(windows-chewing)

if (!${MSVC})
        message(FATAL_ERROR "Visual Studio only")
endif()

add_definitions(/DHAVE_CONFIG_H=1)
add_definitions(/D_CRT_SECURE_NO_WARNINGS=1)
add_definitions(/D_CRT_NONSTDC_NO_DEPRECATE=1)
add_definitions(/D_CRT_NON_CONFORMING_SWPRINTFS=1)

set(libchewing_src ${PROJECT_SOURCE_DIR}/libchewing)
add_subdirectory(${libchewing_src})

configure_file(
        ${PROJECT_SOURCE_DIR}/cmake/config.h.in
        ${PROJECT_BINARY_DIR}/Include/config.h
)

include(CheckIncludeFiles)
check_include_files(stdint.h HAVE_STDINT_H)

include_directories(
        ${PROJECT_BINARY_DIR}/Include
        ${PROJECT_SOURCE_DIR}/Include
        ${PROJECT_SOURCE_DIR}/ChewingIME
        ${libchewing_src}/include
        ${libchewing_src}/include/internal
)

add_executable(big52utf8 WIN32
        ${PROJECT_SOURCE_DIR}/big52utf8/big52utf8.cpp
)

add_library(ChewingIME
        ${PROJECT_SOURCE_DIR}/ChewingIME/Window.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/ChewingIME.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/StatusWnd.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/ChewingClient.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/Tooltip.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/IMEChildWnd.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/IMEUI.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/CompWnd.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/CompStr.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/DrawUtil.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/IMEUILock.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/CandWnd.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/IMCLock.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/CandList.cpp
        ${PROJECT_SOURCE_DIR}/ChewingIME/XPToolbar.cpp
)
target_link_libraries(ChewingIME ${chewing_static} imm32.lib comctl32.lib user32.lib)
set_target_properties(ChewingIME PROPERTIES
        OUTPUT_NAME ChewingIME.ime
)

add_executable(ChewingServer WIN32
        ${PROJECT_SOURCE_DIR}/ChewingServer/ChewingServer.cpp
        ${PROJECT_SOURCE_DIR}/ChewingServer/main.cpp
        ${PROJECT_SOURCE_DIR}/ChewingServer/chewing.cpp
)
target_link_libraries(ChewingServer ${chewing_static})

#add_executable(HashEd
#        ${PROJECT_SOURCE_DIR}/HashEd-UTF8/CHashContext.cpp
#        ${PROJECT_SOURCE_DIR}/HashEd-UTF8/Pho2Chewing.cpp
#        ${PROJECT_SOURCE_DIR}/HashEd-UTF8/StdAfx.cpp
#        ${PROJECT_SOURCE_DIR}/HashEd-UTF8/PhraseList.cpp
#        ${PROJECT_SOURCE_DIR}/HashEd-UTF8/HashEd.cpp
#        ${PROJECT_SOURCE_DIR}/HashEd-UTF8/HashEdDlg.cpp
#)

add_executable(Installer WIN32
        ${PROJECT_SOURCE_DIR}/Installer/Installer.cpp
)
target_link_libraries(Installer ${chewing_static} imm32.lib)

add_executable(OnlineUpdate WIN32
        ${PROJECT_SOURCE_DIR}/OnlineUpdate/OnlineUpdate.cpp
)
target_link_libraries(OnlineUpdate wininet.lib)
