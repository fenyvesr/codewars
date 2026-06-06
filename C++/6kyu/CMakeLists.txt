add_library(6kyu src/setTable.cpp
                 src/midiFiles.cpp
                 src/allocateRooms.cpp
                 src/restoreBrackets.cpp
                 src/ancestorVariations.cpp
)

target_include_directories(6kyu
    PUBLIC
        "${PROJECT_SOURCE_DIR}/6kyu/include"
)

if(TARGET range-v3)
    target_link_libraries(6kyu
        PUBLIC
            range-v3
    )
endif()
