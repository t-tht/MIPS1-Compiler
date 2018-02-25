#ifndef node_hpp
#define node_hpp

class Node;

class Node{
	private:
	public:
		Node(Node* left_in, Node* right_in);
		~Node();
		virtual void print(std::ostream &dst) const =0;
};

#endif
