# Microprocessor

_Assembly Level Language Programming_

Needed files for assembly programming:

- Either use online emulators like [sim8085](https://www.sim8085.com/), or
- Software links:
  - [8085 microprocessor emulator download link](https://sourceforge.net/projects/simulator8085/)
  - [8086 microprocessor emulator download link](https://emu8086-microprocessor-emulator.en.softonic.com/download)

## [8085 Microprocessor](8085_mp/)

1. [Data Transfer and Instruction Set](8085_mp/Data_transfer_and_Instruction_set/)

   - [Load register with data](8085_mp/Data_transfer_and_Instruction_set/load_reg_with_data.asm)
   - [Load register with data and copy content of this memory location to register C](8085_mp/Data_transfer_and_Instruction_set/load_regD_copy_to_regC.asm)
   - [Load content of memory location to register](8085_mp/Data_transfer_and_Instruction_set/load_content_of_mem0000H_to_regB.asm)
   - [Store content of register to memory location](8085_mp/Data_transfer_and_Instruction_set/store_content%2Bof_regC_to_mem0000H.asm)
   - [Input data from port address and out through port address](8085_mp/Data_transfer_and_Instruction_set/input_data_from_port_address_01H_and_out_through_port_address_02H.asm)
   - [Display content of memory location into port address](8085_mp/Data_transfer_and_Instruction_set/display_content_of_mem4000H_into_port_01H.asm)
   - [Swap contents of register B and C](8085_mp/Data_transfer_and_Instruction_set/swap_contents_of_regB_C.asm)
   - [Swap contents of memory location](8085_mp/Data_transfer_and_Instruction_set/swap_contents_of_memory_location.asm)

2. [Arithmetic and Logical Instruction Set](8085_mp/Arithmetic_and_Logical_Instruction_set/)

   - [Add content of one register and another register and store the result in next register](8085_mp/Arithmetic_and_Logical_Instruction_set/add_content_of_registers_and_store_in_register.asm)
   - [Subtract content of memory location 5000H from 5001H and store result in 5002H](8085_mp/Arithmetic_and_Logical_Instruction_set/subtract_contents_of_memory_location_store_in_mem.asm)
   - [Add 16-bit data from register pair B and D and store result at HL pair](8085_mp/Arithmetic_and_Logical_Instruction_set/add_16bit_data_from_register_pair_store_in_HL_pair.asm)
   - [Load 00H into register B and 10H into register C. Increment content of register B and Decrement content of register C. Store result at memory locations 4000H and 4001H](8085_mp/Arithmetic_and_Logical_Instruction_set/load_regB_regC_with_data_increment_b_decrement_C_store.asm)
   - [Load 16-bit data of register pair from another register pair and store result](8085_mp/Arithmetic_and_Logical_Instruction_set/subtract_16_bit_data_from_register_pair_store_in_HL_pair.asm)
   - [Perform AND, OR and XOR operation between 51H and A2H. Store the AND result at 9000H, OR at 9001H and XOR at 9002H](8085_mp/Arithmetic_and_Logical_Instruction_set/AND_OR_XOR.asm)
   - [Show masking of lower and higher nibbles of 8-bit number. Store the original number in 7007H, masked lower nibble in 7008H and masked upper nibble in 7009H](8085_mp/Arithmetic_and_Logical_Instruction_set/masking_of_lower_and_higher_nibbles_8bit_number.asm)
   - [SET the D6, D1 and D0 bits of 8 bits data A8H and store the result in memory location 1010H](8085_mp/Arithmetic_and_Logical_Instruction_set/set_d6_d1_d0_bits_of_8bit_data.asm)
   - [RESET the D4, D3, D2 and D0 bits of 8-bit data 3DH and store the result in register B](8085_mp/Arithmetic_and_Logical_Instruction_set/reset.asm)

3. [Branching Instruction Set](8085_mp/Branching_Instruction_set/)

   - [Add the content of 4004H and 4005H and store the result and carry in successive memory location](8085_mp/Branching_Instruction_set/add_contents_of_4004_4005_store_result_and_carry_in_successive_location.asm)
   - [Add two 16 bit numbers with carry](8085_mp/Branching_Instruction_set/add_16bit_with_carry.asm)
   - [Subtract the content of register C from register B and store the difference at register L and borrow at register H](8085_mp/Branching_Instruction_set/subtract.asm)
   - [Subtract with borrow](8085_mp/Branching_Instruction_set/subtraction_with_borrow.asm)
   - [Create a continous loop using unconditional jump instruction](8085_mp/Branching_Instruction_set/continuous_loop.asm)
   - [Test the Jump on Zero (JZ=1) condition on arithmetic operation](8085_mp/Branching_Instruction_set/test_JZ_on_arithmetic_op.asm)
   - [Test the Jump on Zero (JPE=1) condition on logical operation](8085_mp/Branching_Instruction_set/test_jump_on_even_parity_on_logical.asm)
   - [Test the jump on negative (S=1) condition on arithmetic operation](8085_mp/Branching_Instruction_set/test_on_negative_condition_on_arithmetic_op.asm)

4. [Rotate Instruction Set](8085_mp/Rotate_Instruction_set/)

   - [Rotate left the data byte A1H two times](8085_mp/Rotate_Instruction_set/rotate_left.asm)
   - [Rotate right the data byte F1H three times](8085_mp/Rotate_Instruction_set/rotate_right.asm)
   - [Rotate left with carry the result of addition (AAH+EEH) three times](8085_mp/Rotate_Instruction_set/rotate_left_with_carry.asm)
   - [Rotate right with carry the result of subtraction (DEH-FAH) two times](8085_mp/Rotate_Instruction_set/rotate_right_with_carry.asm)
   - [Load two data stored in memory location 8000 and 8001 directly to HL register. Add them. If carry exists, rotate right with carry the accumulator result three times, otherwise terminate](8085_mp/Rotate_Instruction_set/load_two_data_stored_in_mem8000_and_8001_directly_to_HL_reg.asm)
   - [Convert the total number of 1 in given bit number](8085_mp/Rotate_Instruction_set/convert_total_number_of_1_in_given_bit_number.asm)

5. [Multiply, Divide and Memory Block Operations](8085_mp/Multiply_Divide_and_Memory_block_operation/)

   - [Multiply](8085_mp/Multiply_Divide_and_Memory_block_operation/multiply.asm)
   - [Divide](8085_mp/Multiply_Divide_and_Memory_block_operation/divide.asm)
   - [Copy block of memory to another memory location](8085_mp/Multiply_Divide_and_Memory_block_operation/copy_memory_block.asm)
   - [Swap memory blocks](8085_mp/Multiply_Divide_and_Memory_block_operation/swap_memory_blocks.asm)
   - [Sort memory block in ascending order](8085_mp/Multiply_Divide_and_Memory_block_operation/sort_memory_block_in_ascending_order.asm)
   - [Sort memory block in descending order](8085_mp/Multiply_Divide_and_Memory_block_operation/sort_memory_block_in_descending_order.asm)

6. [Subroutine, Stack and BCD Conversion](8085_mp/Subroutine_Stack_BCD_Conversion/)

   - [Factorial of a number using subroutine](8085_mp/Subroutine_Stack_BCD_Conversion/factorial.asm)
   - [Sum of squares of the first n numbers](8085_mp/Subroutine_Stack_BCD_Conversion/sum_of_squares.asm)
   - [Convert binary to BCD](8085_mp/Subroutine_Stack_BCD_Conversion/binary_to_BCD.asm)
   - [Convert BCD to binary](8085_mp/Subroutine_Stack_BCD_Conversion/BCD_to_binary.asm)
   - [Stack implementation and add data directly](8085_mp/Subroutine_Stack_BCD_Conversion/stack_implementation.asm)
   - [Stack implementation and add data indirectly](8085_mp/Subroutine_Stack_BCD_Conversion/stack_implementation_indirect.asm)
   - [Use of stack to reverse the number stored in a memory stack and store in the same memory block](8085_mp/Subroutine_Stack_BCD_Conversion/reverse_stack.asm)

## [8086 Microprocessor](8086_mp/)

1. [Basic Arithmetic](8086_mp/Basic_Arithmetic/)

   - [Add two numbers, store the result at DX register and carry at CX register](8086_mp/Basic_Arithmetic/add_two_num_and_store_at_DXreg_carry_at_CXreg.asm)
   - [Add two numbers, store the result at DL register and carry at CL register.](8086_mp/Basic_Arithmetic/add_two_num_and_store_at_DLreg_carry_at_CLreg.asm)
   - [Subtract two numbers, store the result at DX register and borrow at CL register](8086_mp/Basic_Arithmetic/subtract_two_num_and_store_at_DXreg_borrow_at_CXreg.asm)
   - [Multiply](8086_mp/Basic_Arithmetic/multiply.asm)
   - [Divide](8086_mp/Basic_Arithmetic/divide.asm)
   - [Take single character input from keyboard and display it on screen](8086_mp/Basic_Arithmetic/take_single_char_input_from_keyboard_and_display_it_on_screen.asm)
   - [Print your name without using data variable](8086_mp/Basic_Arithmetic/print_your_name_without_using_data_variable.asm)
   - [Sort given numbers in ascending order](8086_mp/Basic_Arithmetic/sort_ascending_order.asm)
   - [Separate odd and even numbers](8086_mp/Basic_Arithmetic/odd_even.asm)

2. [String Processing](8086_mp/String_Processing/)

   - [Check Palindrome](8086_mp/String_Processing/check_palindrome.asm)
   - [Display list of strings](8086_mp/String_Processing/display_list_of_string.asm)
   - [Find position of character in string](8086_mp/String_Processing/find_position_of_character.asm)
   - [Reverse String](8086_mp/String_Processing/reverse_string.asm)

## [Practice Programs for 8085 Microprocessor](8086_mp/Practice/)

- [Ascending Sort](8085_ascendingSort.asm)
- [Descending Sort](8085_descendingSort.asm)
- [Count the total number of 1 in given number](8085_total_1_count.Xasm)
- [Reverse the number stored in one block and store in another](8085_reverse.asm)
- [BCD to Binary conversion](8085_BCDtoBinary.asm)

## [Practice Programs for 8086 Microprocessor](8086_mp/Practice/)

- [Add two 16 bit number](8086_mp/Practice/8086_add.asm)
- [Display string on the screen](8086_mp/Practice/8086_stringDisplay.asm)
- [Read the string and check whether they are same or not](8086_mp/Practice/8086_check_StringSame.asm)
- [Print data without Data variable](8086_mp/Practice/8086_print_withoutDataVar.asm)
