
# file structure
# 	demo 
#		-- src
#		-- inc
#		-- common
#		-- test
#		-- obj
#		my_demo
#		my_demo_test
#		make.base
#		makefile

INCLUDE +=  -I inc/ \
            -I common/inc

SRC_DIR  += common/src \
			./src \
			./ft

GMOCK_DIR= ../gmock-1.7.0

BIN_DIR = obj
TARGET := my_demo

CXX := gcc
CXXFLAGS += -fmessage-length=0

# common make pattern
include make.base

