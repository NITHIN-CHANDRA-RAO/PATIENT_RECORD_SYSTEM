#include "patient.h"

/* Create a new BST node */
struct Patient* createNode(int id, char name[], int age, char disease[]) {
    struct Patient* newNode = (struct Patient*)malloc(sizeof(struct Patient));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->age = age;
    strcpy(newNode->disease, disease);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Insert a patient into BST */
struct Patient* insert(struct Patient* root, int id, char name[], int age, char disease[]) {
    if (root == NULL)
        return createNode(id, name, age, disease);

    if (id < root->id)
        root->left = insert(root->left, id, name, age, disease);
    else if (id > root->id)
        root->right = insert(root->right, id, name, age, disease);
    else
        printf("Patient with ID %d already exists!\n", id);

    return root;
}

/* Search patient by ID */
struct Patient* search(struct Patient* root, int id) {
    if (root == NULL || root->id == id)
        return root;

    if (id < root->id)
        return search(root->left, id);

    return search(root->right, id);
}

/* Display records in inorder */
void inorder(struct Patient* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("ID: %d | Name: %s | Age: %d | Disease: %s\n",
               root->id, root->name, root->age, root->disease);
        inorder(root->right);
    }
}

/* Update patient disease */
void update(struct Patient* root, int id) {
    struct Patient* patient = search(root, id);

    if (patient == NULL) {
        printf("Patient with ID %d not found!\n", id);
        return;
    }

    printf("Enter disease: ");
    scanf("%49s", patient->disease);
    printf("Patient record updated successfully!\n");
}

/* Find minimum value node */
struct Patient* findMin(struct Patient* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

/* Delete a patient record */
struct Patient* deleteNode(struct Patient* root, int id) {
    if (root == NULL)
        return NULL;

    if (id < root->id) {
        root->left = deleteNode(root->left, id);
    } else if (id > root->id) {
        root->right = deleteNode(root->right, id);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct Patient* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Patient* temp = root->left;
            free(root);
            return temp;
        }

        struct Patient* temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->name, temp->name);
        root->age = temp->age;
        strcpy(root->disease, temp->disease);
        root->right = deleteNode(root->right, temp->id);
    }

    return root;
}

/* Count total patients */
int countPatients(struct Patient* root) {
    if (root == NULL)
        return 0;

    return 1 + countPatients(root->left) + countPatients(root->right);
}
