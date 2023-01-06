#include "binary_trees.h"
#include <stdlib.h>

int heap_extract(heap_t **root) {
  if (root == NULL || *root == NULL) {
    return 0;
  }

  heap_t *heap = *root;
  int value = heap->value;

  if (heap->left == NULL && heap->right == NULL) {
    // heap has only one node
    free(heap);
    *root = NULL;
  } else {
    heap_t *last_node = get_last_node(heap);
    heap->value = last_node->value;
    if (last_node->parent->left == last_node) {
      last_node->parent->left = NULL;
    } else {
      last_node->parent->right = NULL;
    }
    free(last_node);

    heap_t *node = heap;
    while (node != NULL) {
      heap_t *max_child = get_max_child(node);
      if (max_child != NULL && max_child->value > node->value) {
        int temp = node->value;
        node->value = max_child->value;
        max_child->value = temp;
      } else {
        break;
      }
      node = max_child;
    }
  }

  return value;
}

// auxiliary function to get the last level-order node in the heap
heap_t *get_last_node(heap_t *heap) {
  if (heap->right != NULL) {
    return get_last_node(heap->right);
  } else if (heap->left != NULL) {
    return get_last_node(heap->left);
  } else {
    return heap;
  }
}

// auxiliary function to get the maximum value between a node's children
heap_t *get_max_child(heap_t *node) {
  if (node->left == NULL && node->right == NULL) {
    return NULL;
  } else if (node->right == NULL) {
    return node->left;
  } else if (node->left == NULL) {
    return node->right;
  } else {
    return node->left->value > node->right->value ? node->left : node->right;
  }
}
