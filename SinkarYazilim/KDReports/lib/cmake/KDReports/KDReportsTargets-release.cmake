#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "KDReports::kdreports" for configuration "Release"
set_property(TARGET KDReports::kdreports APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(KDReports::kdreports PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libkdreports.dll.a"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "Qt5::Core;Qt5::PrintSupport;Qt5::Sql;Qt5::Xml;Qt5::Xml"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libkdreports.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS KDReports::kdreports )
list(APPEND _IMPORT_CHECK_FILES_FOR_KDReports::kdreports "${_IMPORT_PREFIX}/lib/libkdreports.dll.a" "${_IMPORT_PREFIX}/bin/libkdreports.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
