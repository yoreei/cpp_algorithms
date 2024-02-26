#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <stack>
#include <set>
#include <string>
#include "algo_utils.h"

namespace dfs {

    using namespace std;

    // Graph representation (Adjacency List)
    using Graph = unordered_map<int, vector<int>>;
    
    template <class T, class Alloc = allocator<T>>
    class InvVector : public vector<T, Alloc>  {
        auto begin() { return super>rbegin(); }
        auto end() { return super->rend(); }
        auto begin() const { return super->rbegin(); }
        auto end() const { return super->rend(); }
        auto rbegin() { return super->begin(); }
        auto rend() { return super->end(); }
        auto rbegin() const { return super->begin(); }
        auto rend() const { return super->end(); }
    };

    using InvGraph = unordered_map<int, InvVector<int>>;



    // Function signature for DFS
    void dfsAlgorithm(const Graph& graph, int startNode, vector<int>& output);

    // Test function
    template <bool check = true>
    void testDfs(const Graph& graph, int startNode, const vector<int>& expectedOutput, int testNumber) {
        cout << "been here ";
        vector<int> output;
        dfsAlgorithm(graph, startNode, output);

        cout << "Test " << testNumber << ": " << "expected: " << toStr(expectedOutput) << "; output: " << toStr(output) << endl;
        if constexpr (check) {
            if (output == expectedOutput) {
                cout << " Passed" << endl;
            }
            else {
                cout << " Failed" << endl;
            }
        }
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

    template<typename GraphT, typename T>
    void dfsAlgorithmNoRev(const GraphT& graph, int startNode, vector<T>& output) {

        std::stack<T> stack;
        std::set<T> visited;

        stack.push(startNode);
        visited.insert(startNode);
        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();

            output.push_back(current);

            // Iterate over children in reverse order
            const auto& children = graph.at(current);
            for (auto it = children.begin(); it != children.end(); ++it) {
                if (visited.find(*it) == visited.end()) {
                    stack.push(*it);
                    visited.insert(*it);
                }
            }
        }
    }

    void main() {
        const bool check = true;
        testDfs<check>({ {1, {2, 3}}, {2, {4}}, {3, {}}, {4, {}} },
            1,
            { 1, 2, 4, 3 },
            1);
        testDfs<check>({ {1, {2}}, {2, {3}}, {3, {1}} },
            1,
            { 1, 2, 3 },
            2);
        testDfs<check>({ {1, {2, 3}}, {2, {1, 3}}, {3, {1, 2}} },
            1,
            { 1, 2, 3 },
            3);
        testDfs<check>({ {1, {2}}, {2, {}}, {3, {4}}, {4, {}} }, 1, { 1, 2 }, 4);
        testDfs<check>({ {1, {2, 3, 4}}, {2, {}}, {3, {}}, {4, {}} }, 1, { 1, 2, 3, 4 }, 5);
        testDfs<check>({ {1, {2}}, {2, {3, 4}}, {3, {5}}, {4, {}}, {5, {}} }, 1, { 1, 2, 3, 5, 4 }, 6);
        testDfs<check>({ {1, {2}}, {2, {1}} }, 1, { 1, 2 }, 7);
        testDfs<check>({ {1, {2, 3}}, {2, {4}}, {3, {5}}, {4, {}}, {5, {}} }, 1, { 1, 2, 4, 3, 5 }, 8);
        testDfs<check>({ {1, {2, 3}}, {2, {3}}, {3, {2}} }, 1, { 1, 2, 3 }, 9);
        testDfs<check>({ {1, {2, 3}}, {2, {1, 3}}, {3, {2, 1}} }, 3, { 3, 2, 1 }, 10);
        testDfs<check>({ {1, {2}}, {2, {3}}, {3, {}} }, 1, { 1, 2, 3 }, 11);
        testDfs<check>({ {1, {2, 3}}, {2, {4}}, {3, {}}, {4, {}} }, 1, { 1, 2, 4, 3 }, 12);
        testDfs<check>({ {1, {2, 3}}, {2, {4, 5}}, {3, {}}, {4, {}}, {5, {}} }, 1, { 1, 2, 4, 5, 3 }, 13);
        testDfs<check>({ {1, {2, 3}}, {2, {4, 5}}, {3, {}}, {4, {6}}, {5, {}}, {6, {7}}, {7, {}} },
            1, { 1, 2, 4, 6, 7, 5, 3 }, 14);
        testDfs<check>({ {1, {}} }, 1, { 1 }, 15);
    }

} // namespace dfs



