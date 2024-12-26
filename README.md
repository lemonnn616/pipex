# 🔗 pipex

**pipex** is a project that replicates the behavior of shell pipelines (`|`) by creating a program that chains command executions through input and output redirection. This project is part of the 42 School curriculum and demonstrates an understanding of process creation, inter-process communication (IPC), and file handling in Unix-based systems.

---

## 🛠️ Features

### **Mandatory Part**
- Recreates the behavior of the following shell command:  
  ```bash
  <file1 command1 | command2 >file2
  ```
- Implements:
  - Redirection of input and output using file descriptors.
  - Creation and management of child processes with `fork`.
  - Inter-process communication using Unix pipes.

### **Bonus Part**
- **Multiple Commands**:  
  Handles an arbitrary number of commands, replicating the behavior of:  
  ```bash
  <file1 command1 | command2 | command3 | ... | commandN >file2
  ```
- **Error Handling**:  
  Provides robust error messages for invalid files, commands, or arguments.
- **Support for Here-Documents**:  
  Implements the following functionality:  
  ```bash
  ./pipex here_doc LIMITER cmd1 cmd2 ... cmdN file
  ```
  The program reads from the standard input until the specified `LIMITER` is encountered and processes commands as a pipeline.
- **Efficient Memory Management**:  
  Ensures no memory leaks or unnecessary resource usage during execution.

---

## 🎯 Objectives

- Gain a deep understanding of file descriptors, pipes, and process creation.
- Implement robust error handling for edge cases.
- Learn to manage multiple commands and redirections efficiently.
- Understand and implement the concept of "here-documents."

---

## 🚀 Usage

### Mandatory Part
Run the program with the following syntax:
```bash
./pipex file1 cmd1 cmd2 file2
```
Equivalent to:
```bash
<file1 cmd1 | cmd2 >file2
```

### Bonus Part
1. **Multiple Commands**:  
   ```bash
   ./pipex file1 cmd1 cmd2 cmd3 ... cmdN file2
   ```
   Equivalent to:
   ```bash
   <file1 cmd1 | cmd2 | cmd3 | ... | cmdN >file2
   ```

2. **Here-Documents**:  
   ```bash
   ./pipex here_doc LIMITER cmd1 cmd2 ... cmdN file
   ```
   Equivalent to:
   ```bash
   <<LIMITER cmd1 | cmd2 | ... | cmdN >>file
   ```

---

## 📜 License

This project is part of the 42 School curriculum. All rights reserved.

