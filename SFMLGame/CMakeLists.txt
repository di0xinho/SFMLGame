cmake_minimum_required(VERSION 3.10)
project(SFMLGame)

# Ustawienia dla C++
set(CMAKE_CXX_STANDARD 17)

# Ustaw ścieżki do Raylib
set(SFML_DIR "$ENV{VCPKG_ROOT}/packages/sfml_x64-windows")  # Zaktualizuj tę ścieżkę

# Dodaj pliki źródłowe
file(GLOB SOURCES "src/*.cpp")

# Tworzenie pliku wykonywalnego
add_executable(SFMLGame ${SOURCES})

# Ustawienia dla linkowania
include_directories(${SFML_DIR}/include)
link_directories(${SFML_DIR}/lib)

# Podłączenie bibliotek SFML
target_link_libraries(SFMLGame sfml-graphics sfml-audio sfml-window sfml-system sfml-network)
