// #ifndef ast_constexpr_hpp
// #define ast_constexpr_hpp
//
// #include "ast.hpp"
//
// class ConstExpr;
//
// class ConstExpr : public Node{
// protected:
//     int val;
//     const NodePtr left;
//     const NodePtr right;
// public:
//     ConstExpr(const NodePtr _left, const NodePtr _right, int _val) : left(_left), right(_right), val(_val){};
//     ~ConstExpr(){};
//
//     void translate(std::ostream &dst)const override{
//         dst << val;
//     };
//
//     void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
//         if(left != NULL){
//             left->compile(dst, cntx, destloc);
//         }
//         if(right != NULL){
//             right->compile(dst, cntx, destloc);
//             cntx.constexprsum += val;
//         }
//         dst << "\t" <<"li\t$" << destloc << ", " << val << std::endl;
//     };
//
//     void evalhelper(InterpretContext &temp){
//
//     };
// };
//
// #endif
