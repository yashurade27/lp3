#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void printCode(Node *root, string code)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCode(root->left, code + "0");
    printCode(root->right, code + "1");
}

int main() {
    priority_queue<Node *, vector<Node *>, Compare> pq;

    int n;
    char ch;
    int freq;

    cout << "Enter number of characters: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter character and frequency: ";
        cin >> ch >> freq;

        pq.push(new Node(ch, freq));
    }

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *parent = new Node('-', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node *root = pq.top();

    cout << "\nHuffman Codes:" << endl;
    printCode(root, "");

    return 0;
}
