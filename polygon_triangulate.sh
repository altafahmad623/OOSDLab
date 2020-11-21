#! /bin/bash
#
cp polygon_triangulate.hpp /$HOME/include
#
g++ -c -Wall -I/include polygon_triangulate_online.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polygon_triangulate.o ~/libcpp/polygon_triangulate.o
#
echo "Normal end of execution."
