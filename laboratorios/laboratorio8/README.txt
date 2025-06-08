
# ie0417 Laboratorio 8: Software testing

## Integrantes:

- Emmanuel Aviles Ramirez (C20883)
- Diego Acosta Obando (C00041)
- Josue  Zuñiga Jimenez (B98738) 

Para este laboratorio se estudian distintas formas del software testing:


Instrucciones para ejecutar ejemplos del Lab 8 (Software Testing):

1. test_buggy.cpp
   - Compilar: g++ test_buggy.cpp -lgtest -lgtest_main -pthread -o test_buggy
   - Ejecutar: ./test_buggy

2. leak_example.cpp
   - Compilar: g++ -g -o leak_example leak_example.cpp
   - Ejecutar: valgrind --leak-check=yes ./leak_example

3. asan_example.cpp
   - Compilar: g++ -fsanitize=address -g -o asan_example asan_example.cpp
   - Ejecutar: ./asan_example

4. bug_example.cpp
   - Compilar: g++ -g -o bug_example bug_example.cpp
   - Ejecutar: gdb ./bug_example
     Luego en GDB:
       (gdb) run
       (gdb) backtrace
