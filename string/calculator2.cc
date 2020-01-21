#include<iostream>
#include<string>
#include <vector>

using namespace std;

enum class TokenType{
    NUMBER,
    MUL_OP,
    DIV_OP,
    ADD_OP,
    MINUS_OP,
};

struct Token{
    TokenType type;
    int32_t num;
    Token(TokenType t): type(t), num(0){}
    Token(TokenType t, int32_t n): type(t), num(n){}
};
void outputToken(Token* t){
    if(t == nullptr) {
        return;
    }
    if(t->type == TokenType::NUMBER) {
        std::cout << "num: " << t->num << std::endl;
    }else{
        std::cout << "type: " << static_cast<int>(t->type) << std::endl;
    }
}

struct BinaryNode{
    TokenType op;
    BinaryNode* left;
    BinaryNode* right;
    int32_t num;
    BinaryNode(int32_t n): op(TokenType::NUMBER), num(n), left(nullptr), right(nullptr){}
    BinaryNode(TokenType o, BinaryNode* l, BinaryNode* r): op(o), left(l), right(r){}
};

class Parser{
public:
    Parser(vector<Token> tok): offset_(0), tokens_(tok){}
    Token* get_next(){
        if(offset_ < tokens_.size()){
            auto& tok = tokens_[offset_];
            std::cout << "Return token " << static_cast<int>(tok.type) << std::endl;
            return &tokens_[offset_++];
        }
        return nullptr;
    }

    BinaryNode* parse_add(){
        BinaryNode* left = parse_mul();
        if(left == nullptr) { return nullptr; }
        Token* t = get_next();
        if(t == nullptr) {
            return left;
        }
        if(t->type == TokenType::ADD_OP || t->type == TokenType::MINUS_OP) {
            TokenType tk_type;
            tk_type = t->type;
            std::cout << "parse add minus" << std::endl;
            BinaryNode* right = parse_add();
            if(t == nullptr){
                std::cout << "parse add error" << std::endl;
                return nullptr;
            }
            return new BinaryNode(tk_type, left, right);
        }
        return nullptr;
    }
    BinaryNode* parse_mul(){
        BinaryNode* left = parse_val();
        Token* t = get_next();
        if(t == nullptr) {
            return left;
        }
        if(t->type == TokenType::MUL_OP || t->type == TokenType::DIV_OP) {
            TokenType tk_type = t->type;
            BinaryNode* right = parse_mul();
            std::cout << "parse mul div" << std::endl;
            if(t == nullptr){
                std::cout << "parse add error" << std::endl;
                return nullptr;
            }
            return new BinaryNode(tk_type, left, right);
        }
        offset_--;
        return left;
    }
    BinaryNode* parse_val() {
        Token* tok = get_next();
        if(tok == nullptr || tok->type != TokenType::NUMBER){
            return nullptr;
        }
        return new BinaryNode(tok->num);
    }
private:
    size_t offset_;
    vector<Token> tokens_;
};

void output(BinaryNode* node) {
    if(node == nullptr) {
        return;
    }
    if(node->op == TokenType::NUMBER) {
        std::cout << "number: " << node->num << std::endl;
    }else{
        std::cout << "op: " << static_cast<int>(node->op) << std::endl;
    }
    output(node->left);
    output(node->right);
}
int cal(BinaryNode* node) {
    if (node == nullptr)
    {
        return 0;
    }
    if (node->op == TokenType::NUMBER) {
        return node->num;
    }
    if (node->op == TokenType::ADD_OP) {
        return cal(node->left) + cal(node->right);
    }
    if (node->op == TokenType::MINUS_OP) {
        return cal(node->left) - cal(node->right);
    }
    if (node->op == TokenType::MUL_OP) {
        return cal(node->left) * cal(node->right);
    }
    if (node->op == TokenType::DIV_OP) {
        return cal(node->left) / cal(node->right);
    }
    return 0;
}

class Solution {
public:
    int calculate(string s) {
        vector<Token> tokens;
        int offset = 0;
        while(offset < s.length()) {
            char ch = s[offset];
            if(ch >= '0' && ch <= '9') {
                int32_t num = 0;
                while(offset < s.length() && ch >= '0' && ch <= '9') {
                    num = num * 10 + (ch - '0');
                    offset += 1;
                    ch = s[offset];
                };
                tokens.push_back(Token(TokenType::NUMBER, num));
            }
            else if(ch == '+') {
                tokens.push_back(Token(TokenType::ADD_OP));
                ++offset;
            }
            else if (ch == '-') {
                tokens.push_back(Token(TokenType::MINUS_OP));
                ++offset;
            }
            else if (ch == '*') {
                tokens.push_back(Token(TokenType::MUL_OP));
                ++offset;
            }
            else if (ch == '/') {
                tokens.push_back(Token(TokenType::DIV_OP));
                ++offset;
            }
            else{
                std::cout << "missing handle char " << ch << std::endl;
                ++offset;
            }
        }
        // for(auto t: tokens){
        //     if(t.type == TokenType::NUMBER) {
        //         std::cout << "num: " << t.num << std::endl;
        //     }else{
        //         std::cout << "type: " << static_cast<int>(t.type) << std::endl;
        //     }
        // }
        Parser parser(tokens);
        auto node = parser.parse_add();
        output(node);
        return cal(node);
    }
    
};

/*
expr := sub_expr + - sub_expr
sub_expr := sub_sub_expr *\/ sub_sub_expr
sub_sub_expr := num
*/
int main()
{
    Solution s = Solution();
    string str{"1-1+1"};
    std::cout << s.calculate(str);
    return 0;
}