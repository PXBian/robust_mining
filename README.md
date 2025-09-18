# Resilient Pattern Mining

## Description

This repository contains the implementation of the algorithm proposed in our paper Resilient Pattern Mining (RPM). RPM introduces a time- and space-efficient algorithm for discovering `(τ,k)`-resilient substrings of a given text `S`. This repo provides two implementations: one based on the enhanced suffix array (RPM-ESA) and another based on the suffix tree (RPM-ST).

## Requirements

- A GNU/Linux system
- A modern C++17 ready compiler

## How to use

**INPUT**: A file containing the text `S`, an integer `τ`, and an integer `k`.

**OUTPUT**: A file containing the OUTPUT array, which corresponding to a compact representation of the set of `(τ,k)`-resilient substrings of `S`.


### Pre-install

To set up the environment, install [sdsl](https://github.com/simongog/sdsl-lite) by running:

```bash
cd robust_mining
./pre-install.sh
```

### Compile:

To compile the RPM-ESA algorithm, run:

```bash 
g++ -O3 -DNDEBUG -I ./libsdsl/include/ -L ./libsdsl/lib/ runs.hpp intervaltree.hpp main_ESA.cpp -o esa -lsdsl -ldivsufsort -ldivsufsort64
```

To compile the RPM-ST algorithm, run:

```bash 
make all
```


### Execute:

To execute the RPM-ESA algorithm, run:

```bash
./esa <text_file> <τ> <k>
```

To execute the RPM-ST algorithm, run:

```bash 
./main <text_file> <τ> <k>
``` 

**Parameters:**

- `<text_file>`: Path to the input text file containing the text `S`.  
- `<τ>`:  The minimum frequency threshold for a substring `s` of `S` to be considered as *resilient*.  
- `<k>`: The maximum number of letter substitutions allowed in `S`.


### Examples

To use RPM-ESA to find the `(τ,k)`-resilient substrings of `S` in `data/dna.200MB`, run as follows:

```bash 
./esa data/dna.200MB 10 100
```

To use RPM-ST to find the `(τ,k)`-resilient substrings of `S` in `data/dna.200MB`, run as follows:

```bash 
./main data/dna.200MB 10 100
```


## Citation
Pengxin Bian, Panagiotis Charalampopoulos, Lorraine A. K. Ayad, Manal Mohamed,
Solon P. Pissis, and Grigorios Loukides. 2025. Resilient Pattern Mining. ICDM'25

