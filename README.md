# Resilient Pattern Mining

## Description

This repository maintains a 

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

For compiling the RPM-ESA algorithm, run:

```g++ -O3 -DNDEBUG -I ./libsdsl/include/ -L ./libsdsl/lib/ runs.hpp intervaltree.hpp main_ESA.cpp -o esa -lsdsl -ldivsufsort -ldivsufsort64```

For compiling the RPM-ST algorithm, run:

```make all```


### Execute:

For executing the RPM-ESA algorithm, run:

```./esa <text_file> <τ> <k>```

For executing the RPM-ST algorithm, run:

```./main <text_file> <τ> <k>``` 

**Parameters:**

- `<text_file>`: Path to the input text file containing the text `S`.  
- `<τ>`:  The minimum frequency threshold for a substring `s` of `S` to be considered as *resilient*.  
- `<k>`: The maximum number of letter substitutions allowed in `S`.


### Examples

For using RPM-ESA to find the `(τ,k)`-resilient substrings of `S` in data/dna.200MB, run as follows:

```./esa data/dna.200MB 10 100```

For using RPM-ST to find the `(τ,k)`-resilient substrings of `S` in data/dna.200MB, run as follows:

```./main data/dna.200MB 10 100```


## Citation
Pengxin Bian, Panagiotis Charalampopoulos, Lorraine A. K. Ayad, Manal Mohamed,
Solon P. Pissis, and Grigorios Loukides. 2025. Resilient Pattern Mining. ICDM'25



