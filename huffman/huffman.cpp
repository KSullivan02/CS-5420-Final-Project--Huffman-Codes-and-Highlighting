#include <opencv2/opencv.hpp>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace cv;
using namespace std;

// Struct for Huffman Tree nodes
struct HuffmanNode {
    uchar pixelValue; // Grayscale pixel value (0-255)
    float probability; // Probability of occurrence
    HuffmanNode* left; // Left child
    HuffmanNode* right; // Right child

    HuffmanNode(uchar val, float prob) : pixelValue(val), probability(prob), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue (min-heap)
struct CompareNode {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->probability > b->probability;
    }
};

// Generate Huffman Codes
void generateHuffmanCodes(HuffmanNode* root, string code, unordered_map<uchar, pair<int, string>>& huffmanCodes) {
    if (!root) return;

    if (!root->left && !root->right) { // Leaf node
        huffmanCodes[root->pixelValue] = {static_cast<int>(code.length()), code};
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Free memory for the Huffman Tree
void freeHuffmanTree(HuffmanNode* root) {
    if (!root) return;
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    delete root;
}

int main(int argc, char** argv) {
    // Command-line argument parsing
    const String keys =
        "{@image    |      | Path to the grayscale image file (required)}"
        "{help h    |      | Show help message}";

    CommandLineParser parser(argc, argv, keys);

    if (parser.has("help") || !parser.check()) {
        parser.printMessage();
        return 0;
    }

    String imagePath = parser.get<String>(0);
    if (imagePath.empty()) {
        cerr << "Error: No image path provided!" << endl;
        return -1;
    }

    // Load grayscale image
    Mat image = imread(imagePath, IMREAD_GRAYSCALE);
    if (image.empty()) {
        cerr << "Error: Could not open or find the image!" << endl;
        return -1;
    }

    // Compute histogram using OpenCV
    vector<int> histogram(256, 0);
    int totalPixels = image.rows * image.cols;

    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            uchar pixel = image.at<uchar>(i, j);
            histogram[pixel]++;
        }
    }

    // Compute probabilities
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNode> pq;
    for (int i = 0; i < 256; ++i) {
        if (histogram[i] > 0) {
            float probability = static_cast<float>(histogram[i]) / totalPixels;
            pq.push(new HuffmanNode(static_cast<uchar>(i), probability));
        }
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* combined = new HuffmanNode(0, left->probability + right->probability);
        combined->left = left;
        combined->right = right;
        pq.push(combined);
    }

    HuffmanNode* root = pq.top();

    // Generate Huffman Codes
    unordered_map<uchar, pair<int, string>> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Write codes to a file
    ofstream outputFile("huffman_codes.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open file for writing!" << endl;
        freeHuffmanTree(root);
        return -1;
    }

    outputFile << "Pixel Value | Code Length | Huffman Code\n";
    outputFile << "---------------------------------------\n";
    for (const auto& pair : huffmanCodes) {
        outputFile << setw(12) << static_cast<int>(pair.first)
                   << setw(13) << pair.second.first
                   << setw(15) << pair.second.second << "\n";
    }
    outputFile.close();
    cout << "Huffman codes have been written to 'huffman_codes.txt'.\n";

    // Compute entropy and average code length
    float entropy = 0.0;
    float avgCodeLength = 0.0;
    for (int i = 0; i < 256; ++i) {
        if (histogram[i] > 0) {
            float probability = static_cast<float>(histogram[i]) / totalPixels;
            entropy -= probability * log2(probability);

            if (huffmanCodes.find(static_cast<uchar>(i)) != huffmanCodes.end()) {
                avgCodeLength += probability * huffmanCodes[static_cast<uchar>(i)].first;
            }
        }
    }

    float compressionRatio = entropy / avgCodeLength;

    // Display results
    cout << fixed << setprecision(4);
    cout << "Entropy: " << entropy << " bits\n";
    cout << "Average Code Length: " << avgCodeLength << " bits\n";
    cout << "Compression Ratio: " << compressionRatio << "\n";

    // Free Huffman Tree memory
    freeHuffmanTree(root);

    return 0;
}
