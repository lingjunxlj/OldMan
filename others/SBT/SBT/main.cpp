template <typename T>
class SizeBalancedTree
{
public:
   SizeBalancedTree()
   {
        nil = new node;
        nil->size = 0;
        nil->lchild = nil;
        nil->rchild = nil;
        root = nil;
        deleted_node = nil;
   }
   ~SizeBalancedTree()
   {
        Clear();
        delete nil;
   }
   void Clear()
   {
        Clear(root);
   }
   void Delete(const T &key)
   {
        Delete(root, key);
   }
   void Insert(const T &key)
   {
        Insert(root, key);
   }
   const T &Select(size_t rank)
   {
        const node *p = root;
        for(;;)
        {
            if (rank < p->lchild->size)
                p = p->lchild;
            else if (p->lchild->size < rank)
                rank -= p->lchild->size+1, p = p->rchild;
            else break;
        }
        return p->key;
   }
private:
   struct node
   {
        T key;
        size_t size;
        node *lchild, *rchild;
        node() {}
        node(const T &key) : key(key), size(1) {}
   }*deleted_node, *nil, *root;
   void Clear(node *root);
   node *Delete(node *&root, const T &key);
   void Insert(node *&root, const T&key);
   void LeftRotate(node *&root)
   {
        node *p = root->rchild;
        root->rchild = p->lchild;
        p->lchild = root;
        p->size = root->size;
        root->size = root->lchild->size+root->rchild->size+1;
        root = p;
   }
   void Maintain(node *&root, bool flag);
   void RightRotate(node *&root)
   {
        node *p = root->lchild;
        root->lchild = p->rchild;
        p->rchild = root;
        p->size = root->size;
        root->size = root->lchild->size+root->rchild->size+1;
        root = p;
   }
};

template <typename T>
void SizeBalancedTree<T>::Clear(node *root)
{
   if (root != nil)
   {
        Clear(root->lchild);
        Clear(root->rchild);
        delete root;
   }
}

template <typename T>
typename SizeBalancedTree<T>::node *SizeBalancedTree<T>::Delete(node *&root, const T &key)
{
   if (root == nil) return nil;
   --root->size;
   if (key == root->key || root->lchild == nil && key < root->key || root->rchild == nil && root->key < key)
   {
        if (root->lchild != nil && root->rchild != nil)
        {
            node *p = Delete(root->rchild, key-1);
            root->key = p->key;
            return p;
        }
        else
        {
            node *p = root;
            root = root->lchild != nil ? root->lchild : root->rchild;
            return p;
        }
   }
   else return Delete(key < root->key ? root->lchild : root->rchild, key);
}

template <typename T>
void SizeBalancedTree<T>::Insert(node *&root, const T &key)
{
   if (root == nil)
   {
        root = new node(key);
        root->lchild = nil;
        root->rchild = nil;
        return;
   }
   ++root->size;
   bool flag = key < root->key;
   Insert(flag ? root->lchild : root->rchild, key);
   Maintain(root, flag);
}

template <typename T>
void SizeBalancedTree<T>::Maintain(node *&root, bool flag)
{
   if (root == nil) return;
   if (flag)
   {
        if (root->lchild->lchild->size > root->rchild->size)
            RightRotate(root);
        else if (root->lchild->rchild->size > root->rchild->size)
        {
            LeftRotate(root->lchild);
            RightRotate(root);
        }
        else return;
   }
   else
   {
        if (root->rchild->rchild->size > root->lchild->size)
            LeftRotate(root);
        else if (root->rchild->lchild->size > root->lchild->size)
        {
            RightRotate(root->rchild);
            LeftRotate(root);
        }
        else return;
   }
   Maintain(root->lchild, true);
   Maintain(root->rchild, false);
   Maintain(root, true);
   Maintain(root, false);
}
