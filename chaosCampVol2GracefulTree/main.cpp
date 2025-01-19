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
  "1 2 0 0 "
  "0 0 0";

struct Node {
	int value = 0;
	std::vector<std::unique_ptr<Node>> children = {};
};

bool is1to9(char c) {
	return (c >= '1' && c <= '9');
}

int main(int argc, char **argv) {

	std::cout << "Hello World2" << std::endl;
	const char *input = sample1;
	size_t len = std::strlen(input);
	if(len % 2 == 0) {
		std::cerr << "wrong input size\n";
		exit(-1);
	}
	size_t numNodes = (len + 1) / 2;
	Node* mem = (Node*)_mm_malloc(sizeof(Node) * numNodes, 64); ///> align with cache line size
	if (!mem) exit(-1);
	std::memset(mem, 0, sizeof(Node) * numNodes);


	std::queue<Node*> nodeQueue {}; ///> a queue of nodes to be populated with children
	nodeQueue.push(currentNode);
    bool allNulls = false;
    int cur = 0; ///> cursor
	while(allNulls) {
		allNulls = true;
		if(input[cur] == '\n') { ++cur; continue; }
		else if(is1to9(input[cur])) {
			int numChildren = input[cur] - '0';
			currentNode = nodeQueue.front();
			currentNode->children.resize(numChildren);
			for(int i = 0; i < numChildren; ++i) {
				currentNode->children[i] = std::make_unique<Node>();
			}
		}
		else if(input[cur] == '0') {++cur; nodeQueue.pop(); continue;}
		else { std::cerr << "wrong input\n"; exit(-1);}
	}
	Node root = {};

	_mm_free(mem);
	return 0;
}
