#include <iostream>
#include"tree.h"
#include <cassert>
int main() {
    tree tr;
    tr.insert(50);
    tr.insert(21);
    tr.insert(76);
    tr.insert(4);
    std::cout << "Test Insert OK\n";
    std::cout << tr.inorder(tr.wurzel) << '\n';
    std::cout << tr.postorder(tr.wurzel) << '\n';
    std::cout << tr.preorder(tr.wurzel) << '\n';
    std::cout << "Test orders OK\n";
    assert(tr.countNodes(tr.wurzel) == 4);
    tr._delete(tr.wurzel, 21);
    assert(tr.countNodes(tr.wurzel) == 3);
    return 0;
}