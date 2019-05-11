#include<stdio.h>
void InorderTraveler(Node *node){
if(node==NULL) {return;}
InorderTraveler(node->left);
InorderTraveler(node->data);
InorderTraveler(node->right);
}
