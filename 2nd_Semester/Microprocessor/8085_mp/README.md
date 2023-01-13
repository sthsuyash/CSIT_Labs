# 8085 Microprocessor

1. [Data Transfer and Instruction Set](Data_transfer_and_Instruction_set/)

   - [Load register with data](Data_transfer_and_Instruction_set/load_reg_with_data.asm)
   - [Load register with data and copy content of this memory location to register C](Data_transfer_and_Instruction_set/load_regD_copy_to_regC.asm)
   - [Load content of memory location to register](Data_transfer_and_Instruction_set/load_content_of_mem0000H_to_regB.asm)
   - [Store content of register to memory location](Data_transfer_and_Instruction_set/store_content%2Bof_regC_to_mem0000H.asm)
   - [Input data from port address and out through port address](Data_transfer_and_Instruction_set/input_data_from_port_address_01H_and_out_through_port_address_02H.asm)
   - [Display content of memory location into port address](Data_transfer_and_Instruction_set/display_content_of_mem4000H_into_port_01H.asm)
   - [Swap contents of register B and C](Data_transfer_and_Instruction_set/swap_contents_of_regB_C.asm)
   - [Swap contents of memory location](Data_transfer_and_Instruction_set/swap_contents_of_memory_location.asm)

2. [Arithmetic and Logical Instruction Set](Arithmetic_and_Logical_Instruction_set/)

   - [Add content of one register and another register and store the result in next register](Arithmetic_and_Logical_Instruction_set/add_content_of_registers_and_store_in_register.asm)
   - [Subtract content of memory location 5000H from 5001H and store result in 5002H](Arithmetic_and_Logical_Instruction_set/subtract_contents_of_memory_location_store_in_mem.asm)
   - [Add 16-bit data from register pair B and D and store result at HL pair](Arithmetic_and_Logical_Instruction_set/add_16bit_data_from_register_pair_store_in_HL_pair.asm)
   - [Load 00H into register B and 10H into register C. Increment content of register B and Decrement content of register C. Store result at memory locations 4000H and 4001H](Arithmetic_and_Logical_Instruction_set/load_regB_regC_with_data_increment_b_decrement_C_store.asm)
   - [Load 16-bit data of register pair from another register pair and store result](Arithmetic_and_Logical_Instruction_set/subtract_16_bit_data_from_register_pair_store_in_HL_pair.asm)

3. [Branching Instruction Set](Branching_Instruction_set/)

   - [WAP to add the content of 4004H and 4005H and store the result and carry in successive memory location](Branching_Instruction_set/add_contents_of_4004_4005_store_result_and_carry_in_successive_location.asm)
   - [WAP for addition of two 16 bit numbers with carry](Branching_Instruction_set/add_16bit_with_carry.asm)
   - [WAP to subtract the content of register C from register B and store the difference at register L and borrow at register H](Branching_Instruction_set/subtract.asm)
   - [Subtract with borrow](Branching_Instruction_set/subtraction_with_borrow.asm)
   - [WAP to create a continous loop using unconditional jump instruction](Branching_Instruction_set/continuous_loop.asm)
   - [WAP to test the Jump on Zero (JZ=1) condition on arithmetic operation](Branching_Instruction_set/test_JZ_on_arithmetic_op.asm)
   - [WAP to test the Jump on Zero (JPE=1) condition on logical operation](Branching_Instruction_set/test_jump_on_even_parity_on_logical.asm)
   - [WAP to test the jump on negative (S=1) condition on arithmetic operation](Branching_Instruction_set/test_on_negative_condition_on_arithmetic_op.asm)

4. [Rotate Instruction Set](Rotate_Instruction_set/)

   - [WAP to rotate left the data byte A1H two times](Rotate_Instruction_set/rotate_left.asm)
   - [WAP to rotate right the data byte F1H three times](Rotate_Instruction_set/rotate_right.asm)
   - [Rotate left with carry the result of addition (AAH+EEH) three times](Rotate_Instruction_set/rotate_left_with_carry.asm)
   - [Rotate right with carry the result of subtraction (DEH-FAH) two times](Rotate_Instruction_set/rotate_right_with_carry.asm)
   - [WAP to load two data stored in memory location 8000 and 8001 directly to HL register. Add them. If carry exists, rotate right with carry the accumulator result three times, otherwise terminate](Rotate_Instruction_set/load_two_data_stored_in_mem8000_and_8001_directly_to_HL_reg.asm)
   - [WAP to convert the total number of 1 in given bit number](Rotate_Instruction_set/convert_total_number_of_1_in_given_bit_number.asm)

5. [Multiply, Divide and Memory Block Operations](Multiply_Divide_and_Memory_block_operation/)

   - [Multiply](Multiply_Divide_and_Memory_block_operation/multiply.asm)
   - [Divide](Multiply_Divide_and_Memory_block_operation/divide.asm)
   - [Copy block of memory to another memory location](Multiply_Divide_and_Memory_block_operation/copy_memory_block.asm)
   - [Swap memory blocks](Multiply_Divide_and_Memory_block_operation/swap_memory_blocks.asm)
   - [Sort memory block in ascending order](Multiply_Divide_and_Memory_block_operation/sort_memory_block_in_ascending_order.asm)
   - [Sort memory block in descending order](Multiply_Divide_and_Memory_block_operation/sort_memory_block_in_descending_order.asm)

6. [Subroutine, Stack and BCD Conversion](Subroutine_Stack_BCD_Conversion/)

   - [Factorial of a number using subroutine](Subroutine_Stack_BCD_Conversion/factorial.asm)
   - [Sum of squares of the first n numbers](Subroutine_Stack_BCD_Conversion/sum_of_squares.asm)
   - [Convert binary to BCD](Subroutine_Stack_BCD_Conversion/binary_to_BCD.asm)
   - [Convert BCD to binary](Subroutine_Stack_BCD_Conversion/BCD_to_binary.asm)
   - [Stack implementation and add data directly](Subroutine_Stack_BCD_Conversion/stack_implementation.asm)
   - [Stack implementation and add data indirectly](Subroutine_Stack_BCD_Conversion/stack_implementation_indirect.asm)
   - [Use of stack to reverse the number stored in a memory stack and store in the same memory block](Subroutine_Stack_BCD_Conversion/reverse_stack.asm)
