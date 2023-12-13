
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// �?nh nghia m?t n�t trong c�y Huffman
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

// So s�nh hai n�t theo t?n s?
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// L?p bi?u di?n c�y Huffman
class HuffmanTree {
private:
    HuffmanNode* root;
    unordered_map<char, string> codes;

    // H�m gi?i ph�ng b? nh? c?a c�y Huffman
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

    // H�m x�y d?ng c�y Huffman s? d?ng h�ng d?i uu ti�n
    void buildTree(const string& text) {
        // �?m t?n s? xu?t hi?n c?a c�c k� t?
        unordered_map<char, int> frequencies;
        for (char c : text) {
            frequencies[c]++;
        }

        // T?o c�c n�t l� ban d?u t? c�c k� t? v� t?n s?
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
        for (auto pair : frequencies) {
            pq.push(new HuffmanNode(pair.first, pair.second));
        }

        // X�y d?ng c�y Huffman t? c�c n�t l�
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

    // H�m duy?t c�y v� g�n t? m� cho c�c k� t?
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

    // H�m n�n chu?i k� t? b?ng thu?t to�n n�n tinh
    string compress(const string& text) {
        string compressed_text = "";
        for (char c : text) {
            compressed_text += codes[c];
        }
        return compressed_text;
    }

    // H�m gi?i n�n chu?i k� t? d� du?c n�n
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

    // H�m hu? d?i tu?ng v� gi?i ph�ng b? nh?
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
	// Chu?i k� t? ban d?u
    string text = "Hello, world!";

    // Kh?i t?o c�y Huffman
    HuffmanTree huffmanTree;

    // X�y d?ng c�y Huffman
    huffmanTree.buildTree(text);

    // Duy?t c�y v� g�n t? m� cho c�c k� t?
    huffmanTree.assignCodes(huffmanTree.getRoot(), "");

    // N�n chu?i k� t?
    string compressed_text = huffmanTree.compress(text);
    cout << "Compressed text: " << compressed_text <<endl;
    return 0;
	
}


