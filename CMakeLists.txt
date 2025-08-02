cmake_minimum_required(VERSION 3.16)

project(test_task VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick QuickControls2)


qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(apptest_task
    main.cpp
    backend_core.cpp
    robot_controller.cpp
    robot.cpp
    dh_model.cpp
)

qt_add_qml_module(apptest_task
    URI test_task
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES components/OutputTextField.qml
        QML_FILES components/InputTextField.qml
        RESOURCES
        SOURCES
        SOURCES backend_core.h
        SOURCES backend_core.cpp
        SOURCES robot.h
        SOURCES robot_controller.h
        SOURCES robot_controller.cpp
        SOURCES
        SOURCES dh_model.h
        SOURCES robot.cpp
        SOURCES dh_model.cpp
        SOURCES test_robots.h
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(apptest_task PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.apptest_task
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(apptest_task
    PRIVATE Qt6::Quick
    Qt6::QuickControls2
)

include(GNUInstallDirs)
install(TARGETS apptest_task
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
