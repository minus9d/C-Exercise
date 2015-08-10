cmake_minimum_required (VERSION 2.6)
project (Tutorial)

# バージョン番号
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# CMakeの設定をソースコードに渡すための
# ヘッダファイルの構成
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )

include_directories("${PROJECT_BINARY_DIR}")

option (USE_MYMATH
        "Use tutorial provided math implementation" ON)

# MathFunctions ライブラリを追加するか？
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# 実行ファイルを追加
add_executable (Tutorial tutorial.cxx)
target_link_libraries (Tutorial MathFunctions)

# make installしたときに/usr/bin, /usr/includeに配置されるべきファイルを指定
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
         DESTINATION include)


#######
# test
#######
add_test (TutorialRuns Tutorial 25)

add_test (TutorialComp25 Tutorial 25)

set_tests_properties (TutorialComp25
  PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")

add_test (TutorialNegative Tutorial -25)
set_tests_properties (TutorialNegative
  PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0")

add_test (TutorialSmall Tutorial 0.0001)
set_tests_properties (TutorialSmall
  PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")

add_test (TutorialUsage Tutorial)
set_tests_properties (TutorialUsage
  PROPERTIES
  PASS_REGULAR_EXPRESSION "Usage:.*number")
