#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include "algo_utils.h"

using namespace std;

// Graph representation (Adjacency List)
using Graph = unordered_map<int, vector<int>>;

struct NodeV2 {
    std::vector<NodeV2*> adjacent;
    int id;
};

// Function signature for DFS
void bfsAlgorithm(const Graph& graph, int startNode, vector<int>& output);
void bfsAlgorithmV2(const Graph& graph, int startNode, vector<int>& output);

// Test function
void testBfs(const Graph& graph, int startNode, const vector<int>& expectedOutput, int testNumber) {
    vector<int> output;
    //bfsAlgorithm(graph, startNode, output);
    bfsAlgorithmV2(graph, startNode, output);

    cout << "Test " << testNumber << ": " << "expected: " << toStr(expectedOutput) << "; output: " << toStr(output);
    if (output == expectedOutput) {
        cout << " Passed" << endl;
    }
    else {
        cout << " Failed" << endl;
    }
}

int bfs() {
    // Test Cases
    testBfs({ {1, {2, 3}}, {2, {4}}, {3, {}}, {4, {}} },
        1,
        { 1, 2, 3, 4 },
        1);
    testBfs({ {1, {2}}, {2, {3}}, {3, {1}} }, 1, { 1, 2, 3 }, 2);
    testBfs({ {1, {2, 3}}, {2, {1, 3}}, {3, {1, 2}} }, 1, { 1, 2, 3 }, 3);
    testBfs({ {1, {2}}, {2, {}}, {3, {4}}, {4, {}} }, 1, { 1, 2 }, 4);
    testBfs({ {1, {2, 3, 4}}, {2, {}}, {3, {}}, {4, {}} }, 1, { 1, 2, 3, 4 }, 5);
    testBfs({ {1, {2}}, {2, {3, 4}}, {3, {5}}, {4, {}}, {5, {}} }, 1, { 1, 2, 3, 4, 5 }, 6);
    testBfs({ {1, {2}}, {2, {1}} }, 1, { 1, 2 }, 7);
    testBfs({ {1, {2, 3}}, {2, {4}}, {3, {5}}, {4, {}}, {5, {}} }, 1, { 1, 2, 3, 4, 5 }, 8);
    testBfs({ {1, {2, 3}}, {2, {3}}, {3, {2}} }, 1, { 1, 2, 3 }, 9);
    testBfs({ {1, {2, 3}}, {2, {1, 3}}, {3, {2, 1}} },
        3,
        { 3, 2, 1 },
        10);

    return 0;
}

void bfsAlgorithm(const Graph& graph, int startNode, vector<int>& output) {
    std::queue<int> q{};
    std::set<int> visited{};
    q.push(startNode);
    visited.insert(startNode);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        output.push_back(current);
        for (auto child_it = graph.at(current).begin(); child_it != graph.at(current).end(); ++child_it)
        {
            if (visited.find(*child_it) == visited.end())
            {
                q.push(*child_it);
                visited.insert(*child_it);
            }
        }
    }
}

void bfsAlgorithmV2(const Graph& graph, int startValue, vector<int>& output)
{
    

    std::vector<std::unique_ptr<NodeV2>> m{};  //memory manager
    auto malloc = [&](auto&& newNode) {
        m.push_back(std::make_unique<NodeV2>(std::forward<decltype(newNode)>(newNode)));
        return m.back().get();
        };

    // construct graph
    NodeV2* root = malloc(NodeV2({}, startValue));
    {
        std::queue<NodeV2*> q{}; // make queue<int>
        std::map<int, NodeV2*> visited{};
        q.push(root);
        visited[startValue] = root;

        while (!q.empty())
        {
            NodeV2* current = q.front();
            q.pop();
            for (auto childIdIt = graph.at(current->id).begin(); childIdIt != graph.at(current->id).end(); ++childIdIt)
            {
                if (visited.find(*childIdIt) == visited.end())
                {
                    NodeV2* childNode = malloc(NodeV2(std::vector<NodeV2*>(), *childIdIt));
                    q.push(childNode);
                    visited[*childIdIt] = childNode;
                }
                current->adjacent.push_back(visited[*childIdIt]);
            }
        }
    }

    //print memory
    for (const auto& node : m)
    {
        cout << "{node.id: " << node->id << " }\n";
    }

    // walk the graph with bfs

    {
        std::queue<NodeV2*> q{}; // make queue<int>
        std::bitset<INT32_MAX> visited {};
        q.push(root);
        visited[startValue] = root;

        while (!q.empty())
        {
            NodeV2* current = q.front();
            q.pop();
            // TODO continue
            //output
            //for (const auto& child : current->adjacent)
            //{
            //    if (!visited[child->id])
            //    {
            //        q.push(child);
            //        visited[child->id] = true;
            //    }
            //}
        }
    }
}


