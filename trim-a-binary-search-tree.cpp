/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL) return root;
        if (!juger(root->val, low, high)) {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                // return NULL;
                return trimBST(NULL, low, high);
            }
            if (root->left != NULL && root->right == NULL) {
                // auto temp = root->left;
                TreeNode* temp = new TreeNode; 
                temp = root->left;
                delete root;
                // return temp;
                return trimBST(temp, low, high);
            }
            if (root->left == NULL && root->right != NULL) {
                // auto temp = root->right;
                TreeNode* temp = new TreeNode;
                temp = root->right;
                delete root;
                // return temp;
                return trimBST(temp, low, high);
            }
            if (root->left != NULL && root->right != NULL) {
                // auto temp = root->left;
                // auto node = root->right;
                // auto node1 = root->right;
                TreeNode* temp = new TreeNode;
                TreeNode* node = new TreeNode;
                TreeNode* node1 = new TreeNode;
                temp = root->left;
                node = root->right;
                node1 = root->right;

                while (node->left != NULL) node = node->left;
                node->left = temp;
                delete root;
                // return node1;
                return trimBST(node1, low, high);
            }
        } else {
            // root->left = trimBST(root->left, low, high);
            if (root->left) root->left = trimBST(root->left, low, high);
            // root->right = trimBST(root->right, low, high);
            if (root->right) root->right = trimBST(root->right, low, high);
        }   
        return root;  
    }

    bool juger(int num, int low, int high) {
        if (num > high) return false;
        if (num < low)  return false;
        return true;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int low = stringToInteger(line);
        getline(cin, line);
        int high = stringToInteger(line);
        
        TreeNode* ret = Solution().trimBST(root, low, high);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}