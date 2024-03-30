# Compiler Design and Construction

**Lab 1:**

1. [Write a program to check whether the input is digit or not](./1_a_digit_or_not.l)
2. [Write a program to identify tokens](./1_b_identify_tokens.l)

**Lab 2:**

- Write a program in C to implement DFA that accepts string:
  - [baab](./2_a_baab.c)
  - [abba](./2_b_abba.c)

**Lab 3:**

1. [Write a program to check valid identifier](./3_a_valid_identifier.c)
2. [Write a program to check valid comment or not](./3_b_valid_comment.c)

**Lab 4:**

- [Write a program to count number of operators used in given input](./4_count_operators.c)

  `Input: a=b+c*d`

**Lab 5:**

1. [Write a program to find the first of given grammar](./5_a_first_of_grammar.c)

   ```c
   S->L+R
   S->R
   L->*R
   L->a
   R->L
   ```

2. [Write a program to find the follow of the given grammar](./5_b_follow_of_grammar.c)

   ```c
   R->aS
   R->(R)S
   S->+RS
   S->aRS
   s->as
   ```

**Lab 6:**

- [Write a program for constructing of LL(1) Parsing](./6_ll1_parsing.c)

**Lab 7:**

- [Write a program to implement Shift Reduce Parsing](./7_shift_reduce_parsing.c)

  ```c
  E->E+E
  E->E/E
  E->E*E
  E->a/b
  ```

  `Input symbol: a+b+a`

**Lab 8:**

- [Write a program to implement intermediate code generation](./8_intermediate_code_generation.c)

  `X=a+b-c*d/e`

**Lab 9:**

- [Write a program to implement machine code generation](./9_machine_code_generation.c)
