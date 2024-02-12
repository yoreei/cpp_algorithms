#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <stack>
#include <set>
#include <string>
#include "algo_utils.h"

using namespace std;

// Graph representation (Adjacency List)
using Graph = unordered_map<int, vector<int>>;

// Function signature for DFS
void dfsAlgorithm(const Graph& graph, int startNode, vector<int>& output);

// Test function
void testDfs(const Graph& graph, int startNode, const vector<int>& expectedOutput, int testNumber) {
    cout << "been here ";
    vector<int> output;
    dfsAlgorithm(graph, startNode, output);

    cout << "Test " << testNumber << ": " << "expected: " << toStr(expectedOutput) << "; output: " << toStr(output);
    if (output == expectedOutput) {
        cout << " Passed" << endl;
    }
    else {
        cout << " Failed" << endl;
    }
}

int dfs() {
    // Test Cases
    testDfs({ {1, {2, 3}}, {2, {4}}, {3, {}}, {4, {}} },
        1,
        { 1, 2, 4, 3 },
        1);
    testDfs({ {1, {2}}, {2, {3}}, {3, {1}} },
        1,
        { 1, 2, 3 },
        2);
    testDfs({ {1, {2, 3}}, {2, {1, 3}}, {3, {1, 2}} },
        1,
        { 1, 2, 3 },
        3);
    testDfs({ {1, {2}}, {2, {}}, {3, {4}}, {4, {}} }, 1, { 1, 2 }, 4);
    testDfs({ {1, {2, 3, 4}}, {2, {}}, {3, {}}, {4, {}} }, 1, { 1, 2, 3, 4 }, 5);
    testDfs({ {1, {2}}, {2, {3, 4}}, {3, {5}}, {4, {}}, {5, {}} }, 1, { 1, 2, 3, 5, 4 }, 6);
    testDfs({ {1, {2}}, {2, {1}} }, 1, { 1, 2 }, 7);
    testDfs({ {1, {2, 3}}, {2, {4}}, {3, {5}}, {4, {}}, {5, {}} }, 1, { 1, 2, 4, 3, 5 }, 8);
    testDfs({ {1, {2, 3}}, {2, {3}}, {3, {2}} }, 1, { 1, 2, 3 }, 9);
    testDfs({ {1, {2, 3}}, {2, {1, 3}}, {3, {2, 1}} }, 3, { 3, 2, 1 }, 10);
    testDfs({ {1, {2}}, {2, {3}}, {3, {}} }, 1, { 1, 2, 3 }, 11);
    testDfs({ {1, {2, 3}}, {2, {4}}, {3, {}}, {4, {}} }, 1, { 1, 2, 4, 3 }, 12);
    testDfs({ {1, {2, 3}}, {2, {4, 5}}, {3, {}}, {4, {}}, {5, {}} }, 1, { 1, 2, 4, 5, 3 }, 13);
    testDfs({ {1, {2, 3}}, {2, {4, 5}}, {3, {}}, {4, {6}}, {5, {}}, {6, {7}}, {7, {}} },
        1, { 1, 2, 4, 6, 7, 5, 3 }, 14);
    testDfs({ {1, {}} }, 1, { 1 }, 15);

    return 0;
}

void dfsAlgorithm(const Graph& graph, int startNode, vector<int>& output) {
    std::stack<int> stack;
    std::set<int> visited;

    stack.push(startNode);
    visited.insert(startNode);
    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        output.push_back(current);

        // Iterate over children in reverse order
        const auto& children = graph.at(current);
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            if (visited.find(*it) == visited.end()) {
                stack.push(*it);
                visited.insert(*it);
            }
        }
    }
}


