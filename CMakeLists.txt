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

add_executable(Tutorial tutorial.cxx)
