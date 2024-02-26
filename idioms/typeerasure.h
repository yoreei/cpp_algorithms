#include <iostream>
#include <memory>
#include <vector>

namespace type_erasure {
    class Node {
    public:
        // Constructor template that accepts any type T
        template <typename T>
        Node(T x) : self_(std::make_shared<Model<T>>(std::move(x))) {}

        // visit function that delegates to the contained object's visit function
        void visit() const {
            self_->visit_impl();
        }

    private:
        struct Concept {
            virtual ~Concept() = default;
            virtual void visit_impl() const = 0;
            //virtual vector[Concept] adj_impl() const = 0;
        };

        template <typename T>
        struct Model final : Concept {
            Model(T x) : data_(std::move(x)) {}
        
            void visit_impl() const override {
                data_.visit();
            }

            T data_;
        };

        std::shared_ptr<const Concept> self_;
    };

    // Example usage with different types

    class MyNode {
    public:
        void visit() const {
            std::cout << "MyNode visited" << std::endl;
        }
    };

    class AnotherNode {
    public:
        void visit() const {
            std::cout << "AnotherNode visited" << std::endl;
        }
    };

    void main() {
        std::vector<Node> nodes;
        nodes.emplace_back(MyNode{});
        nodes.emplace_back(AnotherNode{});

        for (const auto& node : nodes) {
            node.visit();
        }

    }

} // namespace type_erasure