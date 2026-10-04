class Node {
public:
  vector<unique_ptr<Node>> children;
  bool isWord = false;

  Node() : children(26) {}
  virtual ~Node() = default;
};

class LetterNode : public Node {
public:
  char letter;
  LetterNode(char letter) : letter(letter) {}
  ~LetterNode() override = default;
};


class PrefixTree {
  unique_ptr<Node> root;

public:
  PrefixTree() {
    root = make_unique<Node>();
  }
    
  void insert(string word) {
    Node* curr = root.get();

    for (char ch : word) {
      int i = ch - 'a';

      if (!curr->children[i]) {
        curr->children[i] = make_unique<LetterNode>(ch);
      } 

      curr = curr->children[i].get();
    }

    curr->isWord = true;
  }
    
  bool search(string word) {
    Node* curr = root.get();

    for (char ch : word) {
      int i = ch - 'a';

      if (!curr->children[i]) {
        return false;
      }

      curr = curr->children[i].get();
    }

    return curr->isWord;
  }
    
  bool startsWith(string prefix) {
    Node* curr = root.get();

    for (char ch : prefix) {
      int i = ch - 'a';

      if (!curr->children[i]) {
        return false;
      }

      curr = curr->children[i].get();
    }

    return true;
  }

  ~PrefixTree() = default;
};
