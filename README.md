# CMake Project Creator 🛠️

A lightweight, modular CLI tool written in **C++20** to quickly bootstrap C++ projects with a professional directory structure and pre-configured `CMakeLists.txt`.

## 🚀 Features
- **Instant Scaffolding**: Creates `src/`, `include/`, and `CMakeLists.txt` in seconds.
- **Two Modes**:
  - **Interactive**: Guided setup through the terminal.
  - **Quick Start**: One-line command for power users.
- **Modern C++**: Built using C++20 features like `std::format` and `std::filesystem`.
- **Clean Architecture**: Decoupled logic with proper namespace encapsulation.

## 📂 Project Structure Created
When you create a project, it will look like this:
```text
your_project/
├── CMakeLists.txt
├── include/
└── src/
    └── main.cpp
```

## 🛠️ Requirements
- **Compiler**: GCC 10+, Clang 10+, or MSVC 2019+ (C++20 support required).
- **Build System**: CMake 3.20+.

## ⚙️ Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/youruser/cmake_creator.git
   cd cmake_creator
   ```
2. Build the project:
   ```bash
   cmake -B build
   cmake --build build
   ```
3. (Optional) Install globally:
   ```bash
   sudo cmake --install build
   ```

## 📖 Usage

### Interactive Mode
Simply run the executable without extra arguments to start the guide:
```bash
./cmake_creator new
```

### Quick Mode
Provide the name and (optional) path directly:
```bash
./cmake_creator new MyAwesomeProject /path/to/output
```

## 🧪 Development
The project includes a test suite. To run tests:
```bash
cd build
ctest
```
