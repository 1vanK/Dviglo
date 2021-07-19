# Название цели
set(lib_name base)

# Создаём список файлов
file(GLOB_RECURSE h_files *.h)

# Создаём интерфейсную библиотеку. Интерфейсная библиотека не компилируется,
# так как состоит только из заголовочных файлов
add_library(${lib_name} INTERFACE ${h_files})

# Делаем заголовочные файлы доступными целям, которые используют эту библиотеку
target_include_directories(${lib_name} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Заставляем VS отображать дерево каталогов
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${h_files})

# Пока движок полностью не переделан на модули, устанавливаем заголовочные файлы
install_header_files(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${DEST_INCLUDE_DIR}/../dviglo FILES_MATCHING PATTERN *.h)
