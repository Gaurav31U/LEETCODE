class Skiplist {
public:
  struct Node{
    int val, count;
    Node * next;
    Node(int v, Node* n){val = v, count = 1, next = n;} 
  };
  vector<Node*> table;
    
  bool search(int target) {
    int id = target>>6;
    Node *p = table[id];
    
    while(p)
      if(p->val == target) return true;
      else p = p->next;
    
    return false;
  }
    
  void add(int num) {
    int id = num>>6;
    if(id >= table.size()) for(int i = table.size(); i <= id; i++) table.push_back(new Node(-1, NULL));
    Node* p = table[id];
    
    while(p->next)
      if(p->next->val == num) {p->next->count++; return;}
      else if(p->next->val < num) p = p->next;
            else{p->next = new Node(num, p->next); return;}
    
    p->next = new Node(num, NULL);
  }
    
  bool erase(int num) {
    int id = num>>6;
    Node* p = table[id];
   
    while(p->next)
      if(p->next->val == num){
        if(--p->next->count == 0) p->next = p->next->next;
        return true;
      }
      else if(p->next->val > num) return false;
           else p = p->next;
    
    return false;
  }
};	

