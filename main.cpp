// algo.cpp : Defines the entry point for the application.
//

// all_includes.h

#ifndef ALL_INCLUDES_H
#define ALL_INCLUDES_H
#include "utils.h"
#include "idioms/typeerasure.h"
#include "textprocess/regex.h"
#include "textprocess/enum2string.h"
#include "challenges/thinkcell.h"
#include "stl/thinkcell.h"
#include "playground.h"
#include "templating/templating.h"
#include "algorithms/adjacencylistmastrix.h"
#include "algorithms/astart.h"
#include "algorithms/avltree.h"
#include "algorithms/bellman-ford.h"
#include "algorithms/bfs.h"
#include "algorithms/binsearch.h"
#include "algorithms/bintreetrav.h"
#include "algorithms/boyermoore.h"
#include "algorithms/bubblesort.h"
#include "algorithms/coinchange.h"
// #include "algorithms/dfs.h"
#include "algorithms/dijkstra.h"
#include "algorithms/editdistance.h"
#include "algorithms/fibonacci.h"
#include "algorithms/floydwarshall.h"
#include "algorithms/heapsort.h"
#include "algorithms/insertionsort.h"
#include "algorithms/kadane.h"
#include "algorithms/knapsack.h"
#include "algorithms/kruskal.h"
#include "algorithms/longestcommonsubsequence.h"
#include "algorithms/maxminheap.h"
#include "algorithms/mergesort.h"
#include "algorithms/prim.h"
#include "algorithms/quicksort.h"
#include "algorithms/radixsort.h"
#include "algorithms/reblacktree.h"
#include "algorithms/selectionsort.h"
#include "algorithms/topologicalsort.h"
#include "algorithms/zalgorithm.h"

#endif // ALL_INCLUDES_H

using namespace std;

int main()
{
	type_erasure::main();
	//non_type_template_parameters::main();
	return 0;
}
