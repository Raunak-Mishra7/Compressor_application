int main() {
    std::string text = "huffman algorithm example";
    
    // 1. Count frequency of each character
    std::unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // 2. Create a min heap & push all leaf nodes
    std::priority_queue<Node*, std::vector<Node*>, Compare> minHeap;
    for (auto pair : freq) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // 3. Iterate until size of heap becomes 1
    while (minHeap.size() != 1) {
        // Pop the two nodes of highest priority (lowest frequency)
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();

        // Create a new internal node with a frequency equal to the sum of the two nodes.
        // '$' is just a placeholder for internal nodes that don't hold actual characters.
        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // The remaining node is the root of the Huffman Tree
    Node* root = minHeap.top();

    // 4. Traverse the tree and print the codes
    std::unordered_map<char, std::string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    std::cout << "Huffman Codes:\n" << std::endl;
    for (auto pair : huffmanCode) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    // Clean up memory
    delete root;
    return 0;
}
