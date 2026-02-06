#ifndef PATIENT_H
#define PATIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
    struct Patient *left, *right;
};

/* Function declarations */
struct Patient* createNode(int id, char name[], int age, char disease[]);
struct Patient* insert(struct Patient* root, int id, char name[], int age, char disease[]);
struct Patient* search(struct Patient* root, int id);
void inorder(struct Patient* root);
void update(struct Patient* root, int id);
struct Patient* deleteNode(struct Patient* root, int id);
int countPatients(struct Patient* root);

#endif
