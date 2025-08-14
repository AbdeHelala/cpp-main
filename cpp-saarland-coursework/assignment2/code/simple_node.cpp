#include "simple_node.hpp"

// Constructor: creates a node with a value
SimpleNode::SimpleNode(double content)
    : content_(content), successor_(nullptr) {}

// Copy constructor: makes a deep copy (this copies the whole chain, not just the current node).
SimpleNode::SimpleNode(const SimpleNode& other_node)
    : content_(other_node.content_) {
    if (other_node.successor_) {
        successor_ = std::make_unique<SimpleNode>(*other_node.successor_);
    }
}

// Copy assignment: replaces this node's content and successor chain with a deep copy.
SimpleNode& SimpleNode::operator=(const SimpleNode& other_node) {
    if (this != &other_node) {
        content_ = other_node.content_;
        if (other_node.successor_) {
            successor_ = std::make_unique<SimpleNode>(*other_node.successor_);
        } else {
            successor_.reset();
        }
    }
    return *this;
}

// Insert function: inserts a copy of successor_node (and its chain) after this node.
void SimpleNode::insert(SimpleNode& successor_node) {
    // Create a deep copy of the incoming node (and its successors).
    std::unique_ptr<SimpleNode> new_node = std::make_unique<SimpleNode>(successor_node);

    // Walk to the end of the new node's chain.
    SimpleNode* tail = new_node.get();
    while (tail->successor_) {
        tail = tail->successor_.get();
    }

    // Attach the current successor chain after the new tail.
    tail->successor_ = std::move(successor_);

    // Set this node's successor to the new node.
    successor_ = std::move(new_node);
}

// Returns a reference to the next node (throws if there is none).
SimpleNode& SimpleNode::next() const {
    if (!successor_) {
        throw Invalid(); // or handle however you want; here we just throw.
    }
    return *successor_;
}

// Checks if this is the tail node (i.e., has no successor).
bool SimpleNode::is_tail() const {
    return !successor_;
}

// Counts the number of nodes in the chain, starting from this one.
std::size_t SimpleNode::length() const {
    std::size_t count = 1; // count this node
    const SimpleNode* current = successor_.get();
    while (current) {
        ++count;
        current = current->successor_.get();
    }
    return count;
}

// Accessor (non-const): allows modifying the node's content.
double& SimpleNode::operator()() {
    return content_;
}

// Accessor (const): allows reading the node's content.
double SimpleNode::operator()() const {
    return content_;
}
