cmake_minimum_required(VERSION 2.8.8)
project(windows-chewing)

add_definitions(/DHAVE_CONFIG_H=1 /D_CRT_SECURE_NO_WARNINGS)

configure_file(
        ${PROJECT_SOURCE_DIR}/Include/config.h.in
        ${PROJECT_BINARY_DIR}/Include/config.h
)

include(CheckTypeSize)
check_type_size(uint16_t UINT16_T)
message(${UINT16_T_CODE})

include_directories(
        ${PROJECT_BINARY_DIR}/Include
        ${PROJECT_SOURCE_DIR}/Include
        ${PROJECT_SOURCE_DIR}/Include/chewing/internal
)

add_executable(big52utf8 WIN32
        ${PROJECT_SOURCE_DIR}/big52utf8/big52utf8.cpp
)

add_executable(ChewingIME
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

add_executable(ChewingServer
        ${PROJECT_SOURCE_DIR}/ChewingServer/ChewingServer.cpp
        ${PROJECT_SOURCE_DIR}/ChewingServer/main.cpp
        ${PROJECT_SOURCE_DIR}/ChewingServer/chewing.cpp
)

add_executable(HashEd
        ${PROJECT_SOURCE_DIR}/HashEd-UTF8/CHashContext.cpp
        ${PROJECT_SOURCE_DIR}/HashEd-UTF8/Pho2Chewing.cpp
        ${PROJECT_SOURCE_DIR}/HashEd-UTF8/StdAfx.cpp
        ${PROJECT_SOURCE_DIR}/HashEd-UTF8/PhraseList.cpp
        ${PROJECT_SOURCE_DIR}/HashEd-UTF8/HashEd.cpp
        ${PROJECT_SOURCE_DIR}/HashEd-UTF8/HashEdDlg.cpp
)

add_executable(Installer
        ${PROJECT_SOURCE_DIR}/Installer/Installer.cpp
)

add_executable(OnlineUpdate
        ${PROJECT_SOURCE_DIR}/OnlineUpdate/OnlineUpdate.cpp
)
