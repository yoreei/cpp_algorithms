cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Algorithms VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(Algorithms main.cpp "templating/templating.h" "utils.h" "playground.h")

# Include directories
target_include_directories(Algorithms PUBLIC "${PROJECT_BINARY_DIR}")

# Add each .h file that is part of the project
set(HEADER_FILES
    "idioms/typeerasure.h"
    "challenges/challenge.h"
    "algorithms/adjacencylistmastrix.h"
    main.h
    "algorithms/astart.h"
    "algorithms/avltree.h"
    "algorithms/bellman-ford.h"
    "algorithms/bfs.h"
    "algorithms/binsearch.h"
    "algorithms/bintreetrav.h"
    "algorithms/boyermoore.h"
    "algorithms/bubblesort.h"
    "algorithms/coinchange.h"
    "algorithms/dfs.h"
    "algorithms/dijkstra.h"
    "algorithms/editdistance.h"
    "algorithms/fibonacci.h"
    "algorithms/floydwarshall.h"
    "algorithms/heapsort.h"
    "algorithms/insertionsort.h"
    "algorithms/kadane.h"
    "algorithms/knapsack.h"
    "algorithms/kruskal.h"
    "algorithms/longestcommonsubsequence.h"
    "algorithms/maxminheap.h"
    "algorithms/mergesort.h"
    "algorithms/prim.h"
    "algorithms/quicksort.h"
    "algorithms/radixsort.h"
    "algorithms/reblacktree.h"
    "algorithms/selectionsort.h"
    "algorithms/topologicalsort.h"
    "algorithms/zalgorithm.h"
    "algorithms/algo_utils.h"
    "templating/templating.h"
    "playground.h"
    "stl/thinkcell.h"
    "syntax/syntax.h"
    "textprocess/regex.h"
    "textprocess/enum2string.h"
    "stl/function.h")

# Include the header files
target_sources(Algorithms PRIVATE ${HEADER_FILES})

if(MSVC)
  target_compile_options(Algorithms PUBLIC "/ZI")
  target_link_options(Algorithms PUBLIC "/INCREMENTAL")
endif()