
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Ð?nh nghia m?t nút trong cây Huffman
struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// So sánh hai nút theo t?n s?
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// L?p bi?u di?n cây Huffman
class HuffmanTree {
private:
    HuffmanNode* root;
    unordered_map<char, string> codes;

    // Hàm gi?i phóng b? nh? c?a cây Huffman
    void deleteTree(HuffmanNode* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    HuffmanTree() {
        root = nullptr;
    }

    // Hàm xây d?ng cây Huffman s? d?ng hàng d?i uu tiên
    void buildTree(const string& text) {
        // Ð?m t?n s? xu?t hi?n c?a các ký t?
        unordered_map<char, int> frequencies;
        for (char c : text) {
            frequencies[c]++;
        }

        // T?o các nút lá ban d?u t? các ký t? và t?n s?
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
        for (auto pair : frequencies) {
            pq.push(new HuffmanNode(pair.first, pair.second));
        }

        // Xây d?ng cây Huffman t? các nút lá
        while (pq.size() > 1) {
            HuffmanNode* left = pq.top();
            pq.pop();
            HuffmanNode* right = pq.top();
            pq.pop();

            HuffmanNode* parent = new HuffmanNode('\0', left->frequency + right->frequency);
            parent->left = left;
            parent->right = right;
            pq.push(parent);
        }

        root = pq.top();
    }

    // Hàm duy?t cây và gán t? mã cho các ký t?
    void assignCodes(HuffmanNode* node, string code) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            codes[node->data] = code;
        }

        assignCodes(node->left, code + "0");
        assignCodes(node->right, code + "1");
    }

    // Hàm nén chu?i ký t? b?ng thu?t toán nén tinh
    string compress(const string& text) {
        string compressed_text = "";
        for (char c : text) {
            compressed_text += codes[c];
        }
        return compressed_text;
    }

    // Hàm gi?i nén chu?i ký t? dã du?c nén
    string decompress(const string& compressed_text) {
        string decompressed_text = "";
        HuffmanNode* current = root;
        for (char c : compressed_text) {
            if (c == '0') {
                current = current->left;
            }
            else if (c == '1') {
                current = current->right;
            }

            if (current->left == nullptr && current->right == nullptr) {
                decompressed_text += current->data;
                current = root;
            }
        }
        return decompressed_text;
    }

    // Hàm hu? d?i tu?ng và gi?i phóng b? nh?
    ~HuffmanTree() {
        deleteTree(root);
    }

    // Getter cho root
    HuffmanNode* getRoot() {
        return root;
    }
};
int main()
{
	// Chu?i ký t? ban d?u
    string text = "Hello, world!";

    // Kh?i t?o cây Huffman
    HuffmanTree huffmanTree;

    // Xây d?ng cây Huffman
    huffmanTree.buildTree(text);

    // Duy?t cây và gán t? mã cho các ký t?
    huffmanTree.assignCodes(huffmanTree.getRoot(), "");

    // Nén chu?i ký t?
    string compressed_text = huffmanTree.compress(text);
    cout << "Compressed text: " << compressed_text <<endl;
    return 0;
	
}


