class Solution
{
    public:
    vector<int> serialize(Node *root) 
    {
        vector<int> nodes;
        recurSerialize(root, nodes);
        return nodes;
    }
    void recurSerialize(Node* root, vector<int>& nodes) {
        if (root == nullptr) {
            nodes.push_back(-1);
            return;
        }
        nodes.push_back(root->data);
        recurSerialize(root->left, nodes);
        recurSerialize(root->right, nodes);
        return;
    }
    
    Node * deSerialize(vector<int> &a)
    {
        Node* root = nullptr;
        root = recurDeserialize(root, a);
        return root;
    }
    Node* recurDeserialize(Node* root, vector<int>& a) {
        if (!a.size() || a.front() == -1) {
            a.erase(a.begin());
            return nullptr;
        }
        root = new Node(a.front());
        a.erase(a.begin());
        root->left = recurDeserialize(root->left, a);
        root->right = recurDeserialize(root->right, a);
        return root;
    }
};
