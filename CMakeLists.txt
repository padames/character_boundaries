cmake_minimum_required(VERSION 3.28)

project(characterBoundaries)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always -std=c++17 -Wall -g -D_GLIBCXX_USE_CXX11_ABI=1")

set(CMAKE_POSITION_INDEPENDENT_CODE OFF)


# Boost setup
set(BOOST_ROOT "/usr/local/lib/boost")
find_package(Boost REQUIRED COMPONENTS locale system thread)


# ICU setup
set(ICU_ROOT "/usr/lib/x86_64-linux-gnu")
# set(ENV{PKG_CONFIG_PATH} "/lib/x86_64-linux-gnu/pkgconfig:$ENV{PKG_CONFIG_PATH}")
find_package(ICU REQUIRED COMPONENTS uc i18n data) 

# Define targets
add_executable(cbd main.cpp)
add_executable(cbd2 main_boost_locale.cpp)

# Link ICU to cbd
target_link_libraries(cbd 
    PRIVATE
    ICU::uc
    ICU::i18n
    ICU::data
)

# Link ICU and Boost.Locale to cbd2
target_link_libraries(cbd2 PRIVATE 
    Boost::locale 
    Boost::system   # System library is often needed with Boost
    Boost::thread   # Thread library if needed
    ICU::uc
    ICU::i18n
    ICU::data
)

# Optional: Add compile definitions for Boost with ICU (if needed)
target_compile_definitions(cbd2 PRIVATE 
    BOOST_LOCALE_WITH_ICU=1
    U_DISABLE_VERSION_SUFFIX  # Uncomment if needed
)

link_directories(/usr/lib/x86_64-linux-gnu)
# Optional: Add additional Boost settings (if necessary)
# set(Boost_USE_STATIC_LIBS OFF)
# set(Boost_USE_MULTITHREADED ON)
# set(Boost_USE_STATIC_RUNTIME OFF)

# Debugging: Uncomment to enable Boost debug output if needed
# set(Boost_DEBUG ON)