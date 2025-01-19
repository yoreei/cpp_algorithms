#include <iostream>
#include <memory>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <mm_malloc.h>
#include <malloc.h>

/*
 *** input file format:
 *** children count of nodes at each tree height
 *** a node can have up to 9 children
 * m
 * n p q r (total count: m)
 * n1 n2 .. nn p1 p2 p3 .. pp q1 q2 .. qq (total count: n+p+q+r)
 */

const char *sample1 =
  "4 "
  "0 0 0 0";

const char *sample2 =
  "1 "
  "1 "
  "2 "
  "0 0";

const char *sample3 =
  "2 "
  "2 0 "
  "1 2 "
  "0 0 0";

const char *sample4 =
  "3 "
  "2 0 1 "
  "1 2 1 "
  "0 0 2 0 "
  "0 0";

const char *sample5 =
  "1 "
  "2 "
  "2 1 "
  "3 2 1 "
  "0 0 0 0 0 0";

struct Node {
	int value = 0;
	uint8_t numChildren = 0;
};

int main(int argc, char **argv) {

	std::cout << "Hello World2" << std::endl;
	const char *input = sample5;
	size_t len = std::strlen(input);
	if(len % 2 == 0) {
		std::cerr << "wrong input size\n";
		exit(-1);
	}
	size_t numNodes = (len + 1) / 2;
	void* mem = _mm_malloc(sizeof(Node) * numNodes, 64); ///> align with cache line size
	if (!mem) exit(-1);
	std::memset(mem, 0, sizeof(Node) * numNodes);
	Node* nodes = (Node*)mem;

	for(size_t i = 0; i < numNodes; ++i) {
		size_t inputCur = i * 2;
		nodes[i].numChildren = input[inputCur] - '0';
	}

	int nodesInLevel = 1;
	int levelCur = 0;
	int nextNodesInLevel = 0;
	for(size_t i = 0; i < numNodes; ++i) {
		if(levelCur >= nodesInLevel) {
			levelCur = 0;
			nodesInLevel = nextNodesInLevel;
			nextNodesInLevel = 0;
			std::cout << "\n";
		}

		std::cout << (int)nodes[i].numChildren << " ";
		nextNodesInLevel += nodes[i].numChildren;
		++levelCur;


	}
	std::cout << std::endl << std::flush;



	_mm_free(mem);
	return 0;
}
