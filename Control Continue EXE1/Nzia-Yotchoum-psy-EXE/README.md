# Gestion de Meute - Dog Sled Management System

## Overview

This project implements a comprehensive dog sled management system in C. The system manages sled dogs (`Chien`) and sleds (`Traineau`) with their associated mushers. It demonstrates important C programming concepts including dynamic memory management, data structures, and proper resource management.

## Project Structure

```
Nzia-Yotchoum-psy-EXE/
├── Chien.h          # Dog data structure and function declarations
├── Chien.c          # Dog management implementation
├── Traineau.h       # Sled data structure and function declarations  
├── Traineau.c       # Sled management implementation
├── GestionMucher.c  # Main program demonstrating the system
├── makefile         # Build configuration
└── README.md        # This documentation
```

## Data Structures and Relationships

### 1. Dog (`Chien`) Structure

The `Chien` structure represents a sled dog with the following attributes:

```c
typedef struct {
    char nom[TAILLE_MAX];    // Dog name (max 10 characters)
    TypeR race;              // Dog breed (enum)
    typeL type;              // Dog role in team (enum)
    float poids;             // Dog weight in kg
} Chien;
```

#### Dog Breeds (`TypeR`)
- `HUSKY` (1) - Siberian Husky
- `MALAMUTE` (2) - Alaskan Malamute  
- `GROENLANDAIS` (3) - Greenland Dog

#### Dog Roles (`typeL`)
- `LEADER` (1) - Lead dog, guides the team
- `SWING_LEADER` (2) - Secondary leader, helps with turns
- `TEAM_DOG` (3) - Main pulling power
- `WHEEL_DOG` (4) - Closest to sled, handles heavy loads

### 2. Sled (`traineau`) Structure

The `traineau` structure represents a dog sled team:

```c
typedef struct {
    char* nomMusher;                    // Musher's name (dynamic allocation)
    int nbrChien;                       // Number of dogs per side
    Chien * ListeGauche[NB_MEUTE_MAX]; // Left side dogs (pointers)
    Chien * ListeDroite[NB_MEUTE_MAX]; // Right side dogs (pointers)
} traineau;
```

### 3. Relationship Diagram

```
                    traineau
                       |
           ┌───────────┼───────────┐
           │           │           │
      nomMusher    nbrChien   Lists of Dogs
     (dynamic)    (integer)        │
                                   ├─ ListeGauche[0...n] → Chien*
                                   └─ ListeDroite[0...n] → Chien*
```

## Memory Management Concepts

### Dynamic Memory Allocation with `malloc()`

This project extensively uses dynamic memory allocation for creating flexible data structures:

#### When to use `malloc()`:
1. **Variable-sized data**: When the size isn't known at compile time
2. **Persistent data**: When data needs to survive function scope
3. **Large structures**: To avoid stack overflow with large objects

#### Example from `creerChien()`:
```c
int creerChien(Chien ** dChien, char *nom, TypeR race, typeL type, float poids){
    *dChien = (Chien*)malloc(sizeof(Chien));  // Allocate memory for one Chien
    if(*dChien == NULL){                      // Always check for allocation failure
        return -1;
    }
    // ... initialize the structure
    return 0;
}
```

#### Example from `creerTraineau()`:
```c
int creerTraineau(traineau ** T, char* nomMusher, int nbrChien, /*...*/) {
    *T = (traineau*)malloc(sizeof(traineau));                    // Allocate traineau struct
    if(*T == NULL) return -1;
    
    (*T)->nomMusher = (char*)malloc(sizeof(char)*(strlen(nomMusher)+1)); // Dynamic string
    if((*T)->nomMusher == NULL) return -1;                      // Check allocation
    
    strcpy((*T)->nomMusher, nomMusher);                         // Copy string content
    // ...
}
```

### Memory Deallocation with `free()`

Every `malloc()` must have a corresponding `free()` to prevent memory leaks:

#### Example from `detruireChien()`:
```c
void detruireChien(Chien **dChien){
    if(*dChien != NULL){        // Check pointer validity
        free(*dChien);          // Free the memory
    }
    *dChien = NULL;            // Prevent dangling pointer
}
```

#### Example from `detruireTraineau()`:
```c
void detruireTraineau(traineau ** T){
    if(*T != NULL){
        free((*T)->nomMusher);  // Free dynamic string first
        free(*T);               // Then free the structure
        *T = NULL;              // Prevent dangling pointer
    }
}
```

### Critical Memory Management Rules:
1. **Always check `malloc()` return value** - it can fail
2. **Free in reverse order** - free contained pointers before container
3. **Set pointers to NULL** after freeing to avoid dangling pointers
4. **Never free the same pointer twice**
5. **Don't free stack-allocated memory**

## Argument Passing Nuances

### Pass by Value vs Pass by Reference

Understanding how arguments are passed is crucial for effective C programming:

### 1. Pass by Value
When you pass a variable directly, C makes a copy:

```c
void afficherChien(Chien * dChien);  // Receives COPY of pointer value
```

The function receives a copy of the pointer value, but can still access the pointed-to data.

### 2. Pass by Reference (Simulation in C)
C doesn't have true pass-by-reference, but we simulate it using pointers:

```c
int creerChien(Chien ** dChien, /*...*/);    // Pointer to pointer
void detruireChien(Chien **dChien);          // Pointer to pointer
```

#### Why use double pointers (`**`)?

When we need to **modify the original pointer itself** (not just the data it points to):

```c
// BEFORE: dChien points to nothing (NULL)
// dChien: [NULL]

creerChien(&dChien, "Rex", HUSKY, LEADER, 25.0);

// AFTER: dChien points to allocated memory
// dChien: [address] → [Chien structure in memory]
```

#### Detailed Example:

```c
int main() {
    Chien* monChien = NULL;        // Pointer initially NULL
    
    // Pass the ADDRESS of monChien (&monChien)
    // So creerChien can modify what monChien points to
    creerChien(&monChien, "Rex", HUSKY, LEADER, 25.0);
    
    // Now monChien points to allocated memory
    afficherChien(monChien);       // Pass copy of pointer value
    
    // Pass ADDRESS of monChien so detruire can set it to NULL
    detruireChien(&monChien);      // monChien becomes NULL again
}
```

### 3. Array Parameters

Arrays are special in C - they're always passed as pointers:

```c
void afficheTousLesChiens(Chien * dChien[], int iNbChiens);
```

This is equivalent to:
```c
void afficheTousLesChiens(Chien ** dChien, int iNbChiens);
```

The array `dChien[]` is passed as a pointer to the first element.

### 4. String Parameters

Strings in C are character arrays, so they follow pointer rules:

```c
int creerTraineau(traineau ** T, char* nomMusher, /*...*/);
```

- `nomMusher` is a pointer to the first character
- Function receives a copy of the pointer value
- Can read/modify the string content (if not `const`)
- Cannot change where the original pointer points

## Build and Compilation

### Using the Makefile

```bash
# Compile the project
make

# Run the program
./gest

# Clean build artifacts (if clean target exists)
make clean
```

### Manual Compilation

```bash
# Compile object files
gcc -c Chien.c
gcc -c Traineau.c
gcc -c GestionMucher.c

# Link into executable
gcc Chien.o Traineau.o GestionMucher.o -o gest
```

### Compilation Dependencies

```
GestionMucher.c → depends on → Chien.h, Traineau.h
Traineau.c → depends on → Traineau.h, Chien.h
Chien.c → depends on → Chien.h
```

## Program Execution Flow

### 1. Individual Dog Management
```c
// Create array of dog pointers
Chien * dChien[NB_MEUTE_MAX];
int iNbChiens = 0;

// Create individual dogs
creerChien(&dChien[0], "Papiou", MALAMUTE, SWING_LEADER, 20.30);
creerChien(&dChien[1], "Wolfy", HUSKY, LEADER, 25.90);
// ... more dogs

// Display all dogs
afficheTousLesChiens(dChien, iNbChiens);

// Clean up memory
for (int i = 0; i < iNbChiens; i++) {
    detruireChien(&dChien[i]);
}
```

### 2. Sled Team Management
```c
// Create left and right side dog arrays
Chien * LeftChien[NB_MEUTE_MAX];
Chien * RightChien[NB_MEUTE_MAX];

// Create dogs for each side
creerChien(&LeftChien[0], "Papiou", MALAMUTE, SWING_LEADER, 20.30);
creerChien(&RightChien[0], "LolyPop", HUSKY, SWING_LEADER, 19.30);
// ... more dogs

// Create sled team
traineau * dTraineau[2];
creerTraineau(&dTraineau[0], "Nicholas", 3, LeftChien, RightChien);

// Display complete sled team
afficherTraineau(dTraineau[0]);

// Clean up
detruireTraineau(&dTraineau[0]);
```

## Key Programming Concepts Demonstrated

### 1. Encapsulation
- Data and related functions are grouped in modules
- Header files provide interface, implementation is hidden

### 2. Dynamic Memory Management
- Proper allocation/deallocation patterns
- Error checking for allocation failures
- Prevention of memory leaks and dangling pointers

### 3. Pointer Manipulation
- Single pointers for data access
- Double pointers for pointer modification
- Array-pointer relationships

### 4. Enumerated Types
- Type safety for categorical data
- Clear, readable code with meaningful constants

### 5. Modular Design
- Separation of concerns (Dog vs Sled management)
- Reusable components
- Clear interfaces between modules

## Sample Output

When running the program, you'll see:

```
 Nom: Papiou   Race: Malamute   Type: SWING_LEADER   Poids: 20.30 (kg)
 Nom: Wolfy    Race: Husky      Type: LEADER         Poids: 25.90 (kg)
 Nom: Karnik   Race: Groenlandais Type: TEAM_DOG     Poids: 21.40 (kg)
 Nom: Waazaa   Race: Malamute   Type: WHEEL_DOG      Poids: 30.70 (kg)

Traineau:
Musher: Nicholas
Nb de Chiens 3
Ligne : 0
 Nom: Papiou   Race: Malamute   Type: SWING_LEADER   Poids: 20.30 (kg)
 Nom: LolyPop  Race: Husky      Type: SWING_LEADER   Poids: 19.30 (kg)
Ligne : 1
 Nom: Wolfy    Race: Husky      Type: LEADER         Poids: 25.90 (kg)
 Nom: Betty    Race: Groenlandais Type: LEADER       Poids: 27.40 (kg)
Ligne : 2
 Nom: Bear     Race: Husky      Type: WHEEL_DOG      Poids: 31.80 (kg)
 Nom: Beaver   Race: Malamute   Type: WHEEL_DOG      Poids: 32.70 (kg)
```

## Common Pitfalls and Best Practices

### Memory Management
- ❌ **Don't**: `free(ptr); free(ptr);` // Double free
- ✅ **Do**: `free(ptr); ptr = NULL;` // Free and nullify

### Pointer Usage
- ❌ **Don't**: Use pointers after freeing
- ✅ **Do**: Check for NULL before dereferencing

### Function Design
- ❌ **Don't**: Return pointers to local variables
- ✅ **Do**: Use dynamic allocation for returned data

### Error Handling
- ❌ **Don't**: Ignore malloc failure
- ✅ **Do**: Always check and handle allocation failures

This project serves as an excellent introduction to advanced C programming concepts while maintaining a clear, practical context of managing a dog sled team.