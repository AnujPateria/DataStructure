class RangeModule {
public:


    struct Node {
        Node*left;
        Node*right;
        bool cover;
        int lazy;
        Node(){
            left = right = nullptr;
            cover = false;
            lazy = -1;
        }
    };
    Node* root;



    RangeModule() {
        root = new Node();
    }

    void pushDown(Node* node){
        if(!node->left) node->left = new Node();
        if(!node->right) node->right = new Node();

        if(node->lazy != -1){
            node->left->cover = node->right->cover = node ->lazy ;
            node->left->lazy = node->right->lazy = node->lazy;
            node->lazy = -1;
        }
    }
    void pushUp(Node* node) {
        node->cover = node->left->cover && node->right->cover;
    }

    bool query(Node* node, int l, int r, int ql , int qr){
        if(ql >= r || qr <= l) return true;

        if(ql<=l && r <= qr){
            return node -> cover;
        }
        pushDown(node);
        int mid = l + (r-l) / 2;
        return query(node->left, l, mid, ql, qr) && query(node->right, mid, r, ql, qr);
    }

    void update(Node* node, int l, int r, int ql, int qr, int val){
        if(ql >= r || qr <= l) return ;
        if(ql<=l && r <= qr){
            node->cover = val;
            node->lazy = val;
            return ;
        }
        pushDown(node);
        int mid = l + (r-l) /2;
        update(node->left, l, mid, ql, qr, val);
        update(node->right, mid, r, ql, qr, val);
        pushUp(node);
    }


    void addRange(int left, int right) {
        update(root, 0, 1e9, left, right, 1);
    }
    
    bool queryRange(int left, int right) {
        return query(root, 0, 1e9, left, right);
    }
    
    void removeRange(int left, int right) {
        update(root, 0, 1e9, left, right, 0);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */