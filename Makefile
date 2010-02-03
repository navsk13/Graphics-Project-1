#############################################################################
# Makefile for building: bin/project.app/Contents/MacOS/project
# Generated by qmake (2.01a) (Qt 4.6.1) on: Wed Feb 3 14:15:21 2010
# Project:  project.pro
# Template: app
# Command: /opt/local/bin/qmake-mac -macx -o Makefile project.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = /usr/bin/g++-4.0
DEFINES       = -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -gdwarf-2 -arch i386 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -gdwarf-2 -arch i386 -Wall -W $(DEFINES)
INCPATH       = -I/opt/local/libexec/qt4-mac/mkspecs/macx-g++ -I. -I/opt/local/libexec/qt4-mac/lib/QtCore.framework/Versions/4/Headers -I/opt/local/libexec/qt4-mac/include/QtCore -I/opt/local/libexec/qt4-mac/lib/QtGui.framework/Versions/4/Headers -I/opt/local/libexec/qt4-mac/include/QtGui -I/opt/local/libexec/qt4-mac/lib/QtOpenGL.framework/Versions/4/Headers -I/opt/local/libexec/qt4-mac/include/QtOpenGL -I/opt/local/libexec/qt4-mac/include -I. -Isrc/main -Isrc/re330 -I/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/System/Library/Frameworks/AGL.framework/Headers -Ibuild -F/opt/local/libexec/qt4-mac/lib
LINK          = /usr/bin/g++-4.0
LFLAGS        = -headerpad_max_install_names -arch i386
LIBS          = $(SUBLIBS) -F/opt/local/libexec/qt4-mac/lib -L/opt/local/libexec/qt4-mac/lib -lGLEW -framework OpenGL -framework AGL -framework QtOpenGL -L/opt/local/lib -L/opt/local/libexec/qt4-mac/lib -F/opt/local/libexec/qt4-mac/lib -framework QtGui -framework QtCore 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /opt/local/bin/qmake-mac
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.4

####### Output directory

OBJECTS_DIR   = build/

####### Files

SOURCES       = src/main/main.cpp \
		src/main/MainWidget.cpp \
		src/main/MainWindow.cpp \
		src/main/RenderWidget0.cpp \
		src/re330/BasicMath.cpp \
		src/re330/GLRenderContext.cpp \
		src/re330/GLWidget.cpp \
		src/re330/Matrix4.cpp \
		src/re330/RenderContext.cpp \
		src/re330/SceneManager.cpp \
		src/re330/VertexData.cpp \
		src/re330/VertexDeclaration.cpp build/moc_MainWindow.cpp \
		build/moc_GLWidget.cpp
OBJECTS       = build/main.o \
		build/MainWidget.o \
		build/MainWindow.o \
		build/RenderWidget0.o \
		build/BasicMath.o \
		build/GLRenderContext.o \
		build/GLWidget.o \
		build/Matrix4.o \
		build/RenderContext.o \
		build/SceneManager.o \
		build/VertexData.o \
		build/VertexDeclaration.o \
		build/moc_MainWindow.o \
		build/moc_GLWidget.o
DIST          = /opt/local/libexec/qt4-mac/mkspecs/common/unix.conf \
		/opt/local/libexec/qt4-mac/mkspecs/common/mac.conf \
		/opt/local/libexec/qt4-mac/mkspecs/common/mac-g++.conf \
		/opt/local/libexec/qt4-mac/mkspecs/qconfig.pri \
		/opt/local/libexec/qt4-mac/mkspecs/features/qt_functions.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/qt_config.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/exclusive_builds.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/default_pre.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/default_pre.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/dwarf2.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/debug.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/default_post.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/default_post.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/x86.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/objective_c.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/unix/opengl.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/warn_on.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/qt.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/unix/thread.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/moc.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/rez.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/sdk.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/resources.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/uic.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/yacc.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/lex.prf \
		project.pro
QMAKE_TARGET  = project
DESTDIR       = bin/
TARGET        = bin/project.app/Contents/MacOS/project

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-g \
		-gdwarf-2 \
		-arch \
		i386 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile bin/project.app/Contents/PkgInfo bin/project.app/Contents/Resources/empty.lproj bin/project.app/Contents/Info.plist $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/project.app/Contents/MacOS/ || $(MKDIR) bin/project.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: project.pro  /opt/local/libexec/qt4-mac/mkspecs/macx-g++/qmake.conf /opt/local/libexec/qt4-mac/mkspecs/common/unix.conf \
		/opt/local/libexec/qt4-mac/mkspecs/common/mac.conf \
		/opt/local/libexec/qt4-mac/mkspecs/common/mac-g++.conf \
		/opt/local/libexec/qt4-mac/mkspecs/qconfig.pri \
		/opt/local/libexec/qt4-mac/mkspecs/features/qt_functions.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/qt_config.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/exclusive_builds.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/default_pre.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/default_pre.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/dwarf2.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/debug.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/default_post.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/default_post.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/x86.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/objective_c.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/unix/opengl.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/warn_on.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/qt.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/unix/thread.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/moc.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/rez.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/mac/sdk.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/resources.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/uic.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/yacc.prf \
		/opt/local/libexec/qt4-mac/mkspecs/features/lex.prf \
		/opt/local/libexec/qt4-mac/lib/QtOpenGL.framework/QtOpenGL.prl \
		/opt/local/libexec/qt4-mac/lib/QtGui.framework/QtGui.prl \
		/opt/local/libexec/qt4-mac/lib/QtCore.framework/QtCore.prl
	$(QMAKE) -macx -o Makefile project.pro
/opt/local/libexec/qt4-mac/mkspecs/common/unix.conf:
/opt/local/libexec/qt4-mac/mkspecs/common/mac.conf:
/opt/local/libexec/qt4-mac/mkspecs/common/mac-g++.conf:
/opt/local/libexec/qt4-mac/mkspecs/qconfig.pri:
/opt/local/libexec/qt4-mac/mkspecs/features/qt_functions.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/qt_config.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/exclusive_builds.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/default_pre.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/mac/default_pre.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/mac/dwarf2.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/debug.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/default_post.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/mac/default_post.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/mac/x86.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/mac/objective_c.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/unix/opengl.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/warn_on.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/qt.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/unix/thread.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/moc.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/mac/rez.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/mac/sdk.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/resources.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/uic.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/yacc.prf:
/opt/local/libexec/qt4-mac/mkspecs/features/lex.prf:
/opt/local/libexec/qt4-mac/lib/QtOpenGL.framework/QtOpenGL.prl:
/opt/local/libexec/qt4-mac/lib/QtGui.framework/QtGui.prl:
/opt/local/libexec/qt4-mac/lib/QtCore.framework/QtCore.prl:
qmake:  FORCE
	@$(QMAKE) -macx -o Makefile project.pro

bin/project.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) bin/project.app/Contents || $(MKDIR) bin/project.app/Contents 
	@$(DEL_FILE) bin/project.app/Contents/PkgInfo
	@echo "APPL????" >bin/project.app/Contents/PkgInfo
bin/project.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) bin/project.app/Contents/Resources || $(MKDIR) bin/project.app/Contents/Resources 
	@touch bin/project.app/Contents/Resources/empty.lproj
	
bin/project.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) bin/project.app/Contents || $(MKDIR) bin/project.app/Contents 
	@$(DEL_FILE) bin/project.app/Contents/Info.plist
	@sed -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,project,g" -e "s,@TYPEINFO@,????,g" /opt/local/libexec/qt4-mac/mkspecs/macx-g++/Info.plist.app >bin/project.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) build/project1.0.0 || $(MKDIR) build/project1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/project1.0.0/ && $(COPY_FILE) --parents src/main/MainWidget.h src/main/MainWindow.h src/main/RenderWidget0.h src/re330/BasicMath.h src/re330/Camera.h src/re330/Frustum.h src/re330/glew.h src/re330/GLRenderContext.h src/re330/GLRenderWidget.h src/re330/GLWidget.h src/re330/Matrix4.h src/re330/Node.h src/re330/Object.h src/re330/RE330_global.h src/re330/RenderContext.h src/re330/RenderWidget.h src/re330/SceneManager.h src/re330/Singleton.h src/re330/Vector3.h src/re330/Vector4.h src/re330/VertexData.h src/re330/VertexDeclaration.h src/re330/wglew.h build/project1.0.0/ && $(COPY_FILE) --parents src/main/main.cpp src/main/MainWidget.cpp src/main/MainWindow.cpp src/main/RenderWidget0.cpp src/re330/BasicMath.cpp src/re330/GLRenderContext.cpp src/re330/GLWidget.cpp src/re330/Matrix4.cpp src/re330/RenderContext.cpp src/re330/SceneManager.cpp src/re330/VertexData.cpp src/re330/VertexDeclaration.cpp build/project1.0.0/ && (cd `dirname build/project1.0.0` && $(TAR) project1.0.0.tar project1.0.0 && $(COMPRESS) project1.0.0.tar) && $(MOVE) `dirname build/project1.0.0`/project1.0.0.tar.gz . && $(DEL_FILE) -r build/project1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r bin/project.app
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: build/moc_MainWindow.cpp build/moc_GLWidget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_MainWindow.cpp build/moc_GLWidget.cpp
build/moc_MainWindow.cpp: src/main/RenderWidget0.h \
		src/re330/GLRenderWidget.h \
		src/re330/RE330_global.h \
		src/re330/RenderWidget.h \
		src/re330/GLWidget.h \
		src/re330/GLRenderContext.h \
		src/re330/glew.h \
		src/re330/RenderContext.h \
		src/re330/Singleton.h \
		src/re330/Camera.h \
		src/re330/Frustum.h \
		src/re330/Matrix4.h \
		src/re330/Vector4.h \
		src/re330/Vector3.h \
		src/re330/Object.h \
		src/re330/VertexData.h \
		src/re330/VertexDeclaration.h \
		src/re330/SceneManager.h \
		src/main/MainWindow.h
	/opt/local/libexec/qt4-mac/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/main/MainWindow.h -o build/moc_MainWindow.cpp

build/moc_GLWidget.cpp: src/re330/RE330_global.h \
		src/re330/GLRenderContext.h \
		src/re330/glew.h \
		src/re330/RenderContext.h \
		src/re330/Singleton.h \
		src/re330/Camera.h \
		src/re330/Frustum.h \
		src/re330/Matrix4.h \
		src/re330/Vector4.h \
		src/re330/Vector3.h \
		src/re330/Object.h \
		src/re330/VertexData.h \
		src/re330/VertexDeclaration.h \
		src/re330/GLWidget.h
	/opt/local/libexec/qt4-mac/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/re330/GLWidget.h -o build/moc_GLWidget.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

build/main.o: src/main/main.cpp src/main/MainWindow.h \
		src/main/RenderWidget0.h \
		src/re330/GLRenderWidget.h \
		src/re330/RE330_global.h \
		src/re330/RenderWidget.h \
		src/re330/GLWidget.h \
		src/re330/GLRenderContext.h \
		src/re330/glew.h \
		src/re330/RenderContext.h \
		src/re330/Singleton.h \
		src/re330/Camera.h \
		src/re330/Frustum.h \
		src/re330/Matrix4.h \
		src/re330/Vector4.h \
		src/re330/Vector3.h \
		src/re330/Object.h \
		src/re330/VertexData.h \
		src/re330/VertexDeclaration.h \
		src/re330/SceneManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o src/main/main.cpp

build/MainWidget.o: src/main/MainWidget.cpp src/main/MainWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/MainWidget.o src/main/MainWidget.cpp

build/MainWindow.o: src/main/MainWindow.cpp src/main/MainWindow.h \
		src/main/RenderWidget0.h \
		src/re330/GLRenderWidget.h \
		src/re330/RE330_global.h \
		src/re330/RenderWidget.h \
		src/re330/GLWidget.h \
		src/re330/GLRenderContext.h \
		src/re330/glew.h \
		src/re330/RenderContext.h \
		src/re330/Singleton.h \
		src/re330/Camera.h \
		src/re330/Frustum.h \
		src/re330/Matrix4.h \
		src/re330/Vector4.h \
		src/re330/Vector3.h \
		src/re330/Object.h \
		src/re330/VertexData.h \
		src/re330/VertexDeclaration.h \
		src/re330/SceneManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/MainWindow.o src/main/MainWindow.cpp

build/RenderWidget0.o: src/main/RenderWidget0.cpp src/main/RenderWidget0.h \
		src/re330/GLRenderWidget.h \
		src/re330/RE330_global.h \
		src/re330/RenderWidget.h \
		src/re330/GLWidget.h \
		src/re330/GLRenderContext.h \
		src/re330/glew.h \
		src/re330/RenderContext.h \
		src/re330/Singleton.h \
		src/re330/Camera.h \
		src/re330/Frustum.h \
		src/re330/Matrix4.h \
		src/re330/Vector4.h \
		src/re330/Vector3.h \
		src/re330/Object.h \
		src/re330/VertexData.h \
		src/re330/VertexDeclaration.h \
		src/re330/SceneManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/RenderWidget0.o src/main/RenderWidget0.cpp

build/BasicMath.o: src/re330/BasicMath.cpp src/re330/BasicMath.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/BasicMath.o src/re330/BasicMath.cpp

build/GLRenderContext.o: src/re330/GLRenderContext.cpp src/re330/GLRenderContext.h \
		src/re330/glew.h \
		src/re330/RE330_global.h \
		src/re330/RenderContext.h \
		src/re330/Singleton.h \
		src/re330/Camera.h \
		src/re330/Frustum.h \
		src/re330/Matrix4.h \
		src/re330/Vector4.h \
		src/re330/Vector3.h \
		src/re330/Object.h \
		src/re330/VertexData.h \
		src/re330/VertexDeclaration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/GLRenderContext.o src/re330/GLRenderContext.cpp

build/GLWidget.o: src/re330/GLWidget.cpp src/re330/GLWidget.h \
		src/re330/RE330_global.h \
		src/re330/GLRenderContext.h \
		src/re330/glew.h \
		src/re330/RenderContext.h \
		src/re330/Singleton.h \
		src/re330/Camera.h \
		src/re330/Frustum.h \
		src/re330/Matrix4.h \
		src/re330/Vector4.h \
		src/re330/Vector3.h \
		src/re330/Object.h \
		src/re330/VertexData.h \
		src/re330/VertexDeclaration.h \
		src/re330/GLRenderWidget.h \
		src/re330/RenderWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/GLWidget.o src/re330/GLWidget.cpp

build/Matrix4.o: src/re330/Matrix4.cpp src/re330/Matrix4.h \
		src/re330/Vector4.h \
		src/re330/RE330_global.h \
		src/re330/Vector3.h \
		src/re330/BasicMath.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Matrix4.o src/re330/Matrix4.cpp

build/RenderContext.o: src/re330/RenderContext.cpp src/re330/RenderContext.h \
		src/re330/RE330_global.h \
		src/re330/Singleton.h \
		src/re330/Camera.h \
		src/re330/Frustum.h \
		src/re330/Matrix4.h \
		src/re330/Vector4.h \
		src/re330/Vector3.h \
		src/re330/Object.h \
		src/re330/VertexData.h \
		src/re330/VertexDeclaration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/RenderContext.o src/re330/RenderContext.cpp

build/SceneManager.o: src/re330/SceneManager.cpp src/re330/SceneManager.h \
		src/re330/RE330_global.h \
		src/re330/Camera.h \
		src/re330/Frustum.h \
		src/re330/Matrix4.h \
		src/re330/Vector4.h \
		src/re330/Vector3.h \
		src/re330/Object.h \
		src/re330/VertexData.h \
		src/re330/VertexDeclaration.h \
		src/re330/RenderContext.h \
		src/re330/Singleton.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/SceneManager.o src/re330/SceneManager.cpp

build/VertexData.o: src/re330/VertexData.cpp src/re330/VertexData.h \
		src/re330/RE330_global.h \
		src/re330/VertexDeclaration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/VertexData.o src/re330/VertexData.cpp

build/VertexDeclaration.o: src/re330/VertexDeclaration.cpp src/re330/VertexDeclaration.h \
		src/re330/RE330_global.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/VertexDeclaration.o src/re330/VertexDeclaration.cpp

build/moc_MainWindow.o: build/moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_MainWindow.o build/moc_MainWindow.cpp

build/moc_GLWidget.o: build/moc_GLWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_GLWidget.o build/moc_GLWidget.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

