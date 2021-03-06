# Define target name and output directory
init_target (EC_DynamicComponent)

# Define source files
file (GLOB CPP_FILES *.cpp)
file (GLOB H_FILES *.h)
file (GLOB MOC_FILES EC_DynamicComponent.h)

# Qt4 Moc files to subgroup "CMake Moc"
MocFolder ()

set (SOURCE_FILES ${CPP_FILES} ${H_FILES})

# Qt4 Wrap
QT4_WRAP_CPP(MOC_SRCS ${MOC_FILES})

use_package (BOOST)
use_package (POCO)
use_package (OGRE)
use_package (QT4)
use_modules (Core Foundation Interfaces SceneManager RexCommon)

build_library (${TARGET_NAME} STATIC ${SOURCE_FILES} ${MOC_SRCS} )

link_package (BOOST)
link_package (POCO)
link_package (QT4)
link_ogre()
link_modules (Core Foundation Interfaces SceneManager RexCommon)

# SetupCompileFlagsWithPCH()

final_target ()
