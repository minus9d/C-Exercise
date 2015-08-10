add_library(MathFunctions mysqrt.cxx)

# make installしたときに/usr/bin, /usr/includeに配置されるべきファイルを指定
install (TARGETS MathFunctions DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)
