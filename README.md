# Object-Oriented Memory Cache Simulation

This repository contains a memory cache simulation project designed for the *Computer Architecture* course at Universidad Javeriana Cali. This project implements cache memory concepts using Object-Oriented Programming (OOP) principles.

## Project Overview

The memory cache simulation models the behavior of a computer cache system, enabling an understanding of cache functionalities such as reading, writing, and hit/miss tracking. The program is developed with OOP to structure each cache component in a modular, extendable, and maintainable manner.

### Features

- **Cache Mapping Techniques**: Direct mapping, associative mapping, and set-associative mapping.
- **Replacement Policies**: Implements common cache replacement strategies such as LRU (Least Recently Used), FIFO (First-In-First-Out), and Random Replacement.
- **Hit and Miss Tracking**: Provides statistics on cache hits and misses for performance analysis.
- **Configurable Cache Parameters**: Customizable cache size, block size, and associativity.

## Getting Started

### Prerequisites

To run this simulation, you will need:
- C++ compiler supporting C++11 or higher
- A terminal or IDE for running and testing the program

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/username/object-oriented-memory-cache-simulation.git
   ```
2. Navigate to the project directory:
   ```bash
   cd object-oriented-memory-cache-simulation
   ```

3. Compile the source code:
   ```bash
   g++ -std=c++11 -o cache_simulation main.cpp
   ```

4. Run the simulation:
   ```bash
   ./cache_simulation
   ```

### Usage

The simulation provides options to set up cache parameters and specify memory addresses to access, helping analyze how different configurations impact cache performance.

## Project Structure

- `src/`: Contains the source code files implementing the cache simulation.
- `include/`: Header files with class definitions.
- `data/`: Contains test files for cache simulations.
- `README.md`: Project documentation.

## Authors

Developed by [Your Name] for the *Computer Architecture* course at Universidad Javeriana Cali.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.
