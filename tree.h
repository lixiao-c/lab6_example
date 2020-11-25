#ifndef TREE_H
#define TREE_H
enum
{
	STMT_NODE = 0,
	EXPR_NODE,
	DECL_NODE
};

enum
{
	WHILE_STMT = 0,
	PRINT_STMT,
	COMP_STMT
};

enum
{
	TYPE_EXPR = 0,
	OP_EXPR,
    CONST_EXPR,
	ID_EXPR
};

enum
{
	VAR_DECL = 0,
};

enum
{
	Notype = 0,
	Integer,
	Boolean,
};

#define MAX_CHILDREN 4


union NodeAttr {
	int op;
	int vali;
	char valc;
	int symtbl_seq;
	
	NodeAttr(void) { op = 0; }
	NodeAttr(int i)	{ op = i; }
	NodeAttr(char c) { valc = c; }
};

struct Label {
	string true_label;
	string false_label;
	string begin_label;
	string next_label;
};

struct Node
{
	struct Node *children[MAX_CHILDREN];
	struct Node *sibling;
	int lineno;
	int kind;
	int kind_kind;
	NodeAttr attr;
	int type;
	int seq;
	int temp_var;
	Label label;

	void output(void);
};

class tree
{
private:
	Node *root;
	int node_seq = 0;
	int temp_var_seq = 0;
	int label_seq = 0;

private:
	void type_check(Node *t);
	void get_temp_var(Node *t);
	string new_label(void);
	void recursive_get_label(Node *t);
	void stmt_get_label(Node *t);
	void expr_get_label(Node *t);
	void gen_header(ostream &out);
	void gen_decl(ostream &out, Node *t);
	void recursive_gen_code(ostream &out, Node *t);
	void stmt_gen_code(ostream &out, Node *t);
	void expr_gen_code(ostream &out, Node *t);

public:
	Node *NewRoot(int kind, int kind_kind, NodeAttr attr, int type,
		Node *child1 = NULL, Node *child2 = NULL, Node *child3 = NULL, Node *child4 = NULL);
	void get_label(void);
	void gen_code(ostream &out);
};
#endif
