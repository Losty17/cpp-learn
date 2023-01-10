set(HEADER_FILES
    vector2.h
    object.h
    player.h
)

add_executable(shooter 
    main.cpp
    player.cpp
    ${HEADER_FILES}
)

