TARGET = test-cfsm
QT = core widgets

HEADERS	+=						\
	../../src/customfilesystemmodel.h		\
	scenario-num.h					\
	run-scenario.h

SOURCES	+= test-cfsm.cpp				\
	../../src/customfilesystemmodel.cpp		\
	run-scenario.cpp

include(../tests-include.pro)
