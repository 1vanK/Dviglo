# Добавляем все поддиректории
file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)
foreach(child ${children})
    if(NOT IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
        continue()
    endif()
    add_subdirectory(${child})
    #add_subdirectory(${child} EXCLUDE_FROM_ALL)
endforeach()
