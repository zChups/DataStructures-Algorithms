

#include "tree.h"

#include "tree.h"

Node* Insert(Node* root, const ElemType* value) {
    if (root == NULL) {
        return TreeCreateRoot(value, NULL, NULL);
    }

    if (ElemCompare(TreeGetRootValue(root), value) > 0) {
        root->left = Insert(root->left, value);
    }
    else if (ElemCompare(TreeGetRootValue(root), value) < 0) {
        root->right = Insert(root->right, value);
    }

    return root;
}

Node* Vector2Bst(const ElemType* v, size_t v_size) {
    Node* root = NULL;

    for (size_t i = 0; i < v_size; i++) {
        root = Insert(root, &v[i]);
    }

    return root;
}
