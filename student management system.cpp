#include<iostream>
using namespace std;

class avl {
public:
    int d;//d is roll number of student
    string name;
    string department;
    string batch;
    avl* l;
    avl* r;
}*r;
class avl_tree {
public:
    int height(avl*);
    int difference(avl*);
    avl* rr_rotat(avl*);
    avl* ll_rotat(avl*);
    avl* lr_rotat(avl*);
    avl* rl_rotat(avl*);
    avl* balance(avl*);
    avl* insert(avl*, int);
    void show(avl*, int);
    void inorder(avl*);
    void preorder(avl*);
    void postorder(avl*);
    avl_tree() {
        r = NULL;
    }
};
int avl_tree::height(avl* t)
{
    int h = 0;
    if (t != NULL) {
        //calculating height of both, left and right subtree
        int l_height = height(t->l);
        int r_height = height(t->r);
        //max one will give the overall height of tree
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int avl_tree::difference(avl* t) {
    int l_height = height(t->l);
    int r_height = height(t->r);
    int b_factor = l_height - r_height;
    //for avl tree b_factor <=1
    return b_factor; 
}
avl* avl_tree::rr_rotat(avl* parent) {
    avl* t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;
    cout << "Right-Right Rotation";
    return t;
}
avl* avl_tree::ll_rotat(avl* parent) {
    avl* t;
    t = parent->l;
    parent->l = t->r;
    t->r = parent;
  
    return t;
}
avl* avl_tree::lr_rotat(avl* parent) {
    avl* t;
    t = parent->l;
    parent->l = rr_rotat(t);
    cout << "Left-Right Rotation";
    return ll_rotat(parent);
}
avl* avl_tree::rl_rotat(avl* parent) {
    avl* t;
    t = parent->r;
    parent->r = ll_rotat(t);
    cout << "Right-Left Rotation";
    return rr_rotat(parent);
}
avl* avl_tree::balance(avl* t) {
    int bal_factor = difference(t);
    if (bal_factor > 1) {
        if (difference(t->l) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    }
    else if (bal_factor < -1) {
        if (difference(t->r) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}
avl* avl_tree::insert(avl* r, int v) {
    if (r == NULL) {
        r = new avl;
        r->d = v;
        cout << "Enter name." << endl;
        cin >> r->name;
        cout << "Enter department." << endl;
        cin >> r->department;
        cout << "Enter batch." << endl;
        cin >> r->batch;
        r->l = NULL;
        r->r = NULL;
        return r;
    }
    else if (v < r->d) {
        r->l = insert(r->l, v);
        r = balance(r);
    }
    else if (v >= r->d) {
        r->r = insert(r->r, v);
        r = balance(r);
    } return r;
}
void avl_tree::show(avl* p, int l) {
    int i;
    if (p != NULL) {
        show(p->r, l + 1);
        cout << " ";
        if (p == r)
            cout << "Root -> ";
        for (i = 0; i < l && p != r; i++)
            cout << " ";
        cout << p->d;
        show(p->l, l + 1);
    }
}
void avl_tree::inorder(avl* t) {
    if (t == NULL)
        return;
    inorder(t->l);
    cout <<"CMS Id:  "<< t->d << " \n";
    cout << "Name:  " << t->name << "\n";
    cout << "Dept:  " << t->department << " ";
    cout << "Batch:  " << t->batch << " ";
    inorder(t->r);
}
void avl_tree::preorder(avl* t) {
    if (t == NULL)
        return;
    cout << "CMS Id:  " << t->d << " \n";
    cout << "Name:  " << t->name << "\n";
    cout << "Dept:  " << t->department << " ";
    cout << "Batch:  " << t->batch << " ";
    preorder(t->l);
    preorder(t->r);
}
void avl_tree::postorder(avl* t) {
    if (t == NULL)
        return;
    postorder(t->l);
    postorder(t->r);
    cout << "CMS Id:  " << t->d << " \n";
    cout << "Name:  " << t->name << "\n";
    cout << "Dept:  " << t->department << " ";
    cout << "Batch:  " << t->batch << " ";
}
int main() {
    int choice, val;
    avl_tree avl;
    cout << "Welcome to student management system.\n\n";
    while (1) {
        cout << "1.Enroll new student" << endl;
        cout << "3.Show all students InOrder traversal" << endl;
        cout << "4.Show all students PreOrder traversal" << endl;
        cout << "5.Show all students PostOrder traversal" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Register new student.Enter roll number. ";
            cin >> val;
            r = avl.insert(r, val);
            break;

        case 3:
            cout << "Inorder Traversal:" << endl;
            avl.inorder(r);
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal:" << endl;
            avl.preorder(r);
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal:" << endl;
            avl.postorder(r);
            cout << endl;
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}