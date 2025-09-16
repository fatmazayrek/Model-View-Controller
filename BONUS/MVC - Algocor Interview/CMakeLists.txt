cmake_minimum_required(VERSION 3.16)

project(HOMEWORK VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Network Core Qml)

qt_standard_project_setup()

qt_add_executable(appHOMEWORK
    main.cpp
)

qt_add_qml_module(appHOMEWORK
    URI HOMEWORK
    VERSION 1.0
    QML_FILES
    Main.qml
    LeftMenu.qml
    OrderMenu.qml
    SOURCES
    maincontroller.h maincontroller.cpp
    haberlesme/tcpsoketlib.cpp haberlesme/tcpsoketlib.h
    haberlesme/tcpmanager.h haberlesme/tcpmanager.cpp
    model/mesajlar.h
    model/strategymodel.h model/strategymodel.cpp
    model/ordermodel.h model/ordermodel.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appHOMEWORK PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appHOMEWORK
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appHOMEWORK
    PRIVATE Qt6::Quick Qt6::Network Qt6::Core Qt6::Qml
)

include(GNUInstallDirs)
install(TARGETS appHOMEWORK
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
