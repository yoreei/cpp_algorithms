cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Algorithms VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(Algorithms main.cpp)

# Include directories
target_include_directories(Algorithms PUBLIC "${PROJECT_BINARY_DIR}")

# Add each .h file that is part of the project
set(HEADER_FILES
    adjacencylistmastrix.h
    main.h
    astart.h
    avltree.h
    bellman-ford.h
    bfs.h
    binsearch.h
    bintreetrav.h
    boyermoore.h
    bubblesort.h
    coinchange.h
    dfs.h
    dijkstra.h
    editdistance.h
    fibonacci.h
    floydwarshall.h
    heapsort.h
    insertionsort.h
    kadane.h
    knapsack.h
    kruskal.h
    longestcommonsubsequence.h
    maxminheap.h
    mergesort.h
    prim.h
    quicksort.h
    radixsort.h
    reblacktree.h
    selectionsort.h
    topologicalsort.h
    zalgorithm.h
    algo_utils.h
)

# Include the header files
target_sources(Algorithms PRIVATE ${HEADER_FILES})

if(MSVC)
  target_compile_options(Algorithms PUBLIC "/ZI")
  target_link_options(Algorithms PUBLIC "/INCREMENTAL")
endif()