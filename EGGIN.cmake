# Engine
include_directories( ${EGGIN_ROOT}/src )
link_directories( ${EGGIN_ROOT}/build )
# Render [Irrlicht]
set( IRRLICHT_ROOT ${EGGIN_ROOT}/tparty/irrlicht )
include_directories( ${IRRLICHT_ROOT}/include )
link_directories( ${IRRLICHT_ROOT}/lib/Linux )
# Render [OpenGL]
find_package( OpenGL REQUIRED )
include_directories( ${OPENGL_INCLUDE_DIRS} )

find_package( X11 REQUIRED )
include_directories(${X11_INCLUDE_DIR})

function(eggin_include_libs target)
    target_link_libraries( ${target}
        EGGIN
        ${X11_LIBRARIES}
        Irrlicht
        ${OPENGL_gl_LIBRARY}
        -lX11
        -lXxf86vm
    )
endfunction(eggin_include_libs)
