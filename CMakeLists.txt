cmake_minimum_required(VERSION 3.17)
project(NHF2Reversi)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(.vs)
include_directories(.vs/NHF2Reversi)
include_directories(.vs/NHF2Reversi/v17)
include_directories(.vs/NHF2Reversi/v17/ipch)
include_directories(.vs/NHF2Reversi/v17/ipch/AutoPCH)
include_directories(.vs/NHF2Reversi/v17/ipch/AutoPCH/64f307d7e5101cd5)
include_directories(.vs/NHF2Reversi/v17/ipch/AutoPCH/9d61f18eb28fa42)
include_directories(Debug)
include_directories(Debug/NHF2Reversi.tlog)

add_executable(NHF2Reversi
        .idea/.gitignore
        .idea/discord.xml
        .idea/workspace.xml
        .vs/NHF2Reversi/v17/Browse.VC.db
        .vs/ProjectSettings.json
        .vs/slnx.sqlite
        .vs/VSWorkspaceState.json
        Debug/NHF2Reversi.tlog/CL.command.1.tlog
        Debug/NHF2Reversi.tlog/CL.read.1.tlog
        Debug/NHF2Reversi.tlog/CL.write.1.tlog
        Debug/NHF2Reversi.tlog/link.command.1.tlog
        Debug/NHF2Reversi.tlog/link.read.1.tlog
        Debug/NHF2Reversi.tlog/link.write.1.tlog
        Debug/NHF2Reversi.tlog/NHF2Reversi.lastbuildstate
        Debug/NHF2Reversi.log
        Debug/vc141.idb
        Debug/vc141.pdb
        jatek.cpp
        jatek.h
        kimenet.h
        konzol.cpp
        konzol.h
        NHF2Reversi.cpp
        NHF2Reversi.vcxproj.filters
        NHF2Reversi.vcxproj.user
        NHF2Reversi.vcxproj.xml
        tabla.cpp
        tabla.h)
