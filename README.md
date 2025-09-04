# Resilient Pattern Mining

## Pre-install:

To set up the environment, install [sdsl](https://github.com/simongog/sdsl-lite) by running:

```bash pre-install.sh```


## Execute RPM-ESA:

Compile:

```g++ -O3 -DNDEBUG -I ./libsdsl/include/ -L ./libsdsl/lib/ runs.hpp intervaltree.hpp main_ESA.cpp -o esa -lsdsl -ldivsufsort -ldivsufsort64```

Execute:

```./esa <text_file> <\tau> <\k>```

**Parameters:**

- `<text_file>`: Path to the input text file containing the string `S`.  
- `<tau>`:  The minimum frequency threshold for a substring `s` of `S` to be considered as *resilient*.  
- `<k>`: The maximum number of letter substitutions allowed in the string `S`.


## Execute RPM-ST:

Compile:

```make all```

Execute:

```./main <text_file> <\tau> <\k>``` 

**Parameters:**

- `<text_file>`: Path to the input text file containing the string `S`.  
- `<tau>`:  The minimum frequency threshold for a substring `s` of `S` to be considered as *resilient*.  
- `<k>`: The maximum number of letter substitutions allowed in the string `S`.

