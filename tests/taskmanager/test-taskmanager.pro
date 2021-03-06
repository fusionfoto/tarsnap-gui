TARGET = test-taskmanager
QT = core sql network

VALGRIND = true

HEADERS  +=						\
	../../lib/core/ConsoleLog.h			\
	../../lib/core/TSettings.h			\
	../../src/backuptask.h				\
	../../src/persistentmodel/archive.h		\
	../../src/persistentmodel/job.h			\
	../../src/persistentmodel/persistentobject.h	\
	../../src/persistentmodel/persistentstore.h	\
	../../src/tarsnaptask.h				\
	../../src/taskmanager.h				\
	../../src/utils.h				\
	../qtest-platform.h

SOURCES += test-taskmanager.cpp				\
	../../lib/core/ConsoleLog.cpp			\
	../../lib/core/TSettings.cpp			\
	../../src/backuptask.cpp			\
	../../src/persistentmodel/archive.cpp		\
	../../src/persistentmodel/job.cpp		\
	../../src/persistentmodel/persistentobject.cpp	\
	../../src/persistentmodel/persistentstore.cpp	\
	../../src/tarsnaptask.cpp			\
	../../src/taskmanager.cpp			\
	../../src/utils.cpp

include(../tests-include.pro)
