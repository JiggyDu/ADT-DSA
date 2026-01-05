#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

void initVHeap(VHeap* vheap) {
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        vheap->H[i].next = i + 1;
    }
    vheap->H[MAX_SIZE - 1].next = -1;
    vheap->avail = 0;
}

int alloc(VHeap* vheap) {
    if (vheap->avail == -1) {
        return -1;
    }
    int index = vheap->avail;
    vheap->avail = vheap->H[index].next;
    return index;
}

void dealloc(VHeap* vheap, int index) {
    vheap->H[index].next = vheap->avail;
    vheap->avail = index;
}

int insertArticle(VHeap* vheap, int* L, Article article, int pos) {
    int index = alloc(vheap);
    if (index == -1) {
        printf("Error: Heap is full. Cannot insert new article.\n");
        return 0;
    }
    
    vheap->H[index].article = article;

    if (*L == -1) {
        *L = index;
        vheap->H[index].next = -1;
        return 1;
    }

    if (pos == 0) {
        vheap->H[index].next = *L;
        *L = index;
        return 1;
    }

    if (pos == -1) {
        int curr = *L;
        while (vheap->H[curr].next != -1) {
            curr = vheap->H[curr].next;
        }
        vheap->H[curr].next = index;
        vheap->H[index].next = -1;
        return 1;
    }

    int curr = *L;
    int prev = -1;
    int pos_count = 0;
    while (curr != -1 && pos_count < pos) {
        prev = curr;
        curr = vheap->H[curr].next;
        pos_count++;
    }
    
    if (prev == -1) {
        vheap->H[index].next = *L;
        *L = index;
    } else {
        vheap->H[prev].next = index;
        vheap->H[index].next = curr;
    }
    return 1;
}

void viewArticles(VHeap vheap, int L) {
    if (L == -1) {
        printf("The knowledge base is empty.\n");
        return;
    }

    printf("\n--- List of Articles ---\n");
    int curr = L;
    while (curr != -1) {
        printf("ID: %d | Title: %s\n", vheap.H[curr].article.id, vheap.H[curr].article.title);
        curr = vheap.H[curr].next;
    }
    printf("------------------------\n\n");
}

void searchArticle(VHeap vheap, int L, int id) {
    int curr = L;
    while (curr != -1) {
        if (vheap.H[curr].article.id == id) {
            printf("\n--- Article Found ---\n");
            printf("ID: %d\n", vheap.H[curr].article.id);
            printf("Title: %s\n", vheap.H[curr].article.title);
            printf("Content: %s\n", vheap.H[curr].article.content);
            printf("---------------------\n\n");
            return;
        }
        curr = vheap.H[curr].next;
    }
    printf("Article with ID %d not found.\n\n", id);
}

void deleteArticle(VHeap* vheap, int* L, int id) {
    if (*L == -1) {
        printf("No articles to delete.\n\n");
        return;
    }

    int curr = *L;
    int prev = -1;

    while (curr != -1) {
        if (vheap->H[curr].article.id == id) {
            if (prev == -1) {
                *L = vheap->H[curr].next;
            } else {
                vheap->H[prev].next = vheap->H[curr].next;
            }
            dealloc(vheap, curr);
            printf("Article with ID %d deleted successfully.\n\n", id);
            return;
        }
        prev = curr;
        curr = vheap->H[curr].next;
    }
    printf("Article with ID %d not found.\n\n", id);
}
