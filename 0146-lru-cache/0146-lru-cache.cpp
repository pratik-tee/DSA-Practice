class LRUCache {
public:
   struct ListNode{
      int key1,data;
       ListNode* next,*pre;
   ListNode(int key,int val){
       key1=key;
       data=val;
       pre=next=nullptr;
     }
   };
   ListNode *head,*tail;
   int cap;
   unordered_map<int,ListNode*>mp;
    void deletion(ListNode * temp){
      ListNode* t1=temp->pre;
      ListNode* t2=temp->next;
      t1->next=t2;
      t2->pre=t1;
   }
   void insertion(ListNode* temp){
    ListNode *t1=head->next;
      head->next=temp;
      temp->pre=head;
      temp->next=t1;
      t1->pre=temp;
   }
    LRUCache(int capacity) {
        cap=capacity;
       head=new ListNode(-1,-1);
       tail=new ListNode(-1,-1);
       head->next=tail;
       tail->pre=head;
       head->pre = nullptr;
       tail->next = nullptr;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        ListNode *node=mp[key];
        deletion(node);
        insertion(node);
        return node->data;
    }
    
    void put(int key, int value) {
        if (cap==0) return;
        if(mp.count(key)){
            ListNode* node=mp[key];
            node->data=value;
           deletion(node);
           insertion(node);
        }
        else{
            if(mp.size()==cap){
                 ListNode* node=tail->pre;
                 mp.erase(node->key1);
                 deletion(node);
                 delete node;
            }
            ListNode* temp=new ListNode(key,value);
            mp[key]=temp;
            insertion(temp);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */