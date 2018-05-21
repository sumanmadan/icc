
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)


set(qOasis_sources
	qCalculationChildMDIWindow.cxx
	qCalculationEditorForm.cxx
	qSpecificationChildMDIWindow.cxx
	qSpecificationEditorForm.cxx
	qOasis.cxx
	qOasisMainWindow.cxx
	)

set(qOasis_headers
	qCalculationChildMDIWindow.h
	qCalculationEditorForm.h
	qSpecificationChildMDIWindow.h
	qSpecificationEditorForm.cxx
	qOasisMainWindow.h
	)
  
qt5_wrap_ui(qOasis_ui
	MainWindow.ui
	CalculationEditorForm.ui
	DispositionEditorForm.ui
	EditorWindow.ui
	SpecificationEditorForm.ui
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(qOasis ${qOasis_sources} ${qOasis_headers} ${qOasis_ui} qOasis.qrc)
set_property(TARGET qOasis PROPERTY AUTORCC ON)

target_link_libraries(qOasis Qt5::Core Qt5::Widgets Qt5::Charts gfCore gfFileIO ${Boost_LIBRARIES})

set_target_properties(qOasis PROPERTIES FOLDER "Applications/qOasis") 
