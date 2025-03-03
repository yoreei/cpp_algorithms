// https://cp-algorithms.com/data_structures/disjoint_set_union.html

#include <vector>
#include <iostream>

struct original {
    std::vector<int> parent{};
    std::vector<int> rank{};
    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                std::swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
}; // original

struct numSets {
    std::vector<int> parent{};
    std::vector<int> rank{};
    int num = 0;
    void make_set(int v) {
        ++num;
        parent[v] = v;
        rank[v] = 0;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                std::swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
            --num;
        }
    }
    void print_sets() {
        std::cout << "parent: \n";
        for (int i = 0; i < parent.size(); ++i){
            std::cout << i << ": " << parent[i] << "\trank: " << rank[i] << "\n";
        }
        std::cout << "\nnumSets: " << num << "\n\n";

    }
}; // numSets

int main() {
    numSets s{};
    s.parent.resize(10, -1);
    s.rank.resize(10, -1);
    s.make_set(1);
    s.make_set(2);
    s.make_set(3);
    s.make_set(4);
    s.union_sets(1, 2);
    s.union_sets(3, 4);

    s.print_sets();

    s = numSets{};
    s.parent.resize(10, -1);
    s.rank.resize(10, -1);
    s.make_set(1);
    s.make_set(2);
    s.make_set(3);
    s.make_set(4);
    s.make_set(5); // 5 sets
    s.union_sets(1, 2); // 4 sets
    s.union_sets(3, 4); // 3 sets
    s.union_sets(3, 5); // 2 sets
    s.union_sets(2, 4); // 1 set

    s.print_sets();
}
