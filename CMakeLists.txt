# CMakeLists.txt

cmake_minimum_required(VERSION "3.17")

project(leetcode-cpp)

set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/code/cpp)
set(CMAKE_CXX_STANDARD 17)

# 配置gtest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

enable_testing()

# 定义获取子目录的宏
macro(SUBDIRLIST result curdir)
  file(
    GLOB children
    RELATIVE ${curdir}
    ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()

# 获取子目录
subdirlist(SUBDIRS ${SRC_ROOT})

foreach(d ${SUBDIRS})

  #如果存在测试文件，则生成测试target
  if(EXISTS ${SRC_ROOT}/${d}/${d}Test.cpp)
    add_executable(${d}Test ${SRC_ROOT}/${d}/${d}Test.cpp
                            ${SRC_ROOT}/${d}/${d}.cpp)

    target_link_libraries(${d}Test gtest_main)

    gtest_discover_tests(${d}Test)
  endif()

endforeach()
